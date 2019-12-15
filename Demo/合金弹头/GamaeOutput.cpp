#include"GameOutput.h"
#include <io.h>
#include <stdlib.h>
#pragma comment(lib, "Msimg32.lib")


GameOutput::GameOutput(HWND hwnd):
GO_hWnd(hwnd),
GO_hDC(0),
GO_hMemDC(0),
GO_ClientH(0),
GO_ClientW(0)
{
	RECT r;
	GetClientRect(GO_hWnd, &r);
	GO_ClientW = r.right - r.left;
	GO_ClientH = r.bottom - r.top;

	GO_hDC = GetDC(GO_hWnd);

	HBITMAP hbmp;
	GO_hMemDC = CreateCompatibleDC(GO_hDC);
	hbmp = CreateCompatibleBitmap(GO_hDC, GO_ClientW, GO_ClientH);
	DeleteObject(SelectObject(GO_hMemDC, hbmp));
	DeleteObject(hbmp);

	SetTextColor(GO_hMemDC,RGB(255,255,255));
	SetBkMode(GO_hMemDC, TRANSPARENT);
}
GameOutput::~GameOutput()
{
	/*map<string, CxImage*>::iterator i;
	for (i = GO_CxImage.begin(); i != GO_CxImage.end(); i++)
		delete (i->second);*/
	DeleteDC(GO_hMemDC);
	ReleaseDC(GO_hWnd, GO_hDC);
}
void GameOutput::BeginOutput()
{

	BitBlt(GO_hMemDC, 0, 0, GO_ClientW, GO_ClientH, 0, 0, 0, WHITENESS);
}
void GameOutput::EndOutput()
{
	BitBlt(GO_hDC, 0, 0, GO_ClientW, GO_ClientH, GO_hMemDC, 0, 0, SRCCOPY);
}

BOOL GameOutput::LoadCximg(const TCHAR* filename, const string ID, DWORD format)
{
	CxImage* image;
	if (GO_CxImage[ID])
		return FALSE;
	image = new CxImage(filename, format);
	GO_CxImage[ID] = image;
	return TRUE;
}

BOOL GameOutput::DrawCximage(int x,int y,const string ID)
{
	map<string, CxImage*>::iterator i = GO_CxImage.find(ID);
	if (i == GO_CxImage.end())
		return FALSE;
	i->second->Draw(GO_hMemDC,x-i->second->GetWidth()/2,y-i->second->GetHeight()/2);
	return TRUE;
}
BOOL GameOutput::SetJitte(const string ID, const int n)
{
	map<string, CxImage*>::iterator i = GO_CxImage.find(ID);
	if (i == GO_CxImage.end())
		return FALSE;
	i->second->Jitter(n);
	return TRUE;
}
BOOL GameOutput::SetNoise(const string ID, const int n)
{
	map<string, CxImage*>::iterator i = GO_CxImage.find(ID);
	if (i == GO_CxImage.end())
		return FALSE;
	i->second->Noise(n);
	return TRUE;
}
BOOL GameOutput::SetGrayScale(const string ID)
{
	map<string, CxImage*>::iterator i = GO_CxImage.find(ID);
	if (i == GO_CxImage.end())
		return FALSE;
	i->second->GrayScale();
	return TRUE;
}
BOOL GameOutput::SetLight(const string ID,int x,int y)
{
	map<string, CxImage*>::iterator i = GO_CxImage.find(ID);
	if (i == GO_CxImage.end())
		return FALSE;
	i->second->Light(x,y);
	return TRUE;
}
BOOL GameOutput::SetResampl(const string ID, int x,int y)
{
	map<string, CxImage*>::iterator i = GO_CxImage.find(ID);
	if (i == GO_CxImage.end())
		return FALSE;
	i->second->Resample(x, y,3);
	return TRUE;
}
BOOL GameOutput::DrawText(TCHAR* temp,int x,int y)
{
	TextOut(GO_hMemDC, x, y, temp, _tcslen(temp));
	return TRUE;
}
BOOL GameOutput::SetTitleText(TCHAR *title)
{
	return 0 != SetWindowText(GO_hWnd, title);
}

int GameOutput::LoadDirectory(const TCHAR* DirectName, DWORD format)
{
	char cname[260];
	TCHAR tname[260];
	wcstombs(cname, DirectName, wcslen(DirectName) + 1);

	char dir[260];
	strcpy_s(dir, 260, cname);
	strcat_s(dir, 260, "\\*");
	int r = 0;

	_finddata_t fd;
	intptr_t fr = _findfirst(dir, &fd);

	if (-1 != fr)
	{
		int go = 0;
		while (!go)
		{
			if ((fd.attrib & _A_SUBDIR))
			{
				if (strcmp(fd.name, ".") != 0 && strcmp(fd.name, "..") != 0)
				{
					strcpy_s(dir, 260, cname);
					strcat_s(dir, 260, "\\");
					strcat_s(dir, 260, fd.name);
					r += LoadDirectory((TCHAR*)dir, format);
				}
			}
			else
			{
				strcpy_s(dir, 260, cname);
				strcat_s(dir, 260, "\\");
				strcat_s(dir, 260, fd.name);

				mbstowcs(tname, dir, strlen(dir) + 1);

				r += LoadCximg(tname, fd.name, format) ? 1 : 0;
			}
			go = _findnext(fr, &fd);
		}
	}

	return r;
}