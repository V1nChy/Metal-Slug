#include"Animation.h"
#include"GameFrame.h"
#include <io.h>
#include <stdlib.h>


Animation::Animation(int f,float t):
mFrame(f),
mTime(t),
mCount(0),
mDeltaTime(0)
{
	mImg = new CxImage*[f];
}
Animation::~Animation()
{
	
}
BOOL Animation::LoadImage(const TCHAR* filename, int n)
{
	mImg[n] = new CxImage(filename, CXIMAGE_FORMAT_PNG); 	
	return TRUE;
}
int Animation::LoadDirectory(const char* DirectName)
{
	TCHAR tname[260];
	char dir[260];
	strcpy_s(dir, 260, DirectName);
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
					strcpy_s(dir, 260, DirectName);
					strcat_s(dir, 260, "\\");
					strcat_s(dir, 260, fd.name);
					r += LoadDirectory(dir);
				}
			}
			else
			{
				strcpy_s(dir, 260, DirectName);
				strcat_s(dir, 260, "\\");
				strcat_s(dir, 260, fd.name);
				mbstowcs(tname, dir, strlen(dir) + 1);
				LoadImage(tname, r);
				r += 1;
			}
			go = _findnext(fr, &fd);
		}
	}

	return r;
}
void Animation::Init(const char* DirectName)
{}
void Animation::Enter()
{
	mCount = 0;
	mDeltaTime = 0;
}
void Animation::Render1(HDC hdc, float x, float y)
{
	mImg[mCount]->Draw(hdc, x - mImg[mCount]->GetWidth() / 2, y - mImg[mCount]->GetHeight()/2);
}
void Animation::Render2(HDC hdc, float x, float y)
{
	mImg[mCount]->Mirror();
	mImg[mCount]->Draw(hdc, x - mImg[mCount]->GetWidth() / 2, y - mImg[mCount]->GetHeight() / 2);
	mImg[mCount]->Mirror();
}
int Animation::GetWidth()
{
	return mImg[mCount]->GetWidth();
}
int Animation::GetHeight()
{
	return mImg[mCount]->GetHeight();
}
BOOL Animation::GetOneTime()
{
	return 0;
}
