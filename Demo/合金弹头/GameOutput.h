#ifndef _GAME_OUTPUT_H_
#define _GAME_OUTPUT_H_

#include <windows.h>
#include <string>
#include <map>
#include <tchar.h>
#include"ximage.h"
using namespace std;
class GameOutput
{
protected:
	int GO_ClientW;
	int GO_ClientH;
	HWND GO_hWnd;
	HDC GO_hDC;
	HDC GO_hMemDC;
	map<string, CxImage*> GO_CxImage;
public:
	GameOutput(HWND hwnd);
	 ~GameOutput();

	void BeginOutput();
	void EndOutput();
	BOOL DrawText(TCHAR* temp, int x, int y);
	BOOL SetTitleText(TCHAR *title);

	BOOL LoadCximg(const TCHAR* filename,const string ID,DWORD format);
	BOOL DrawCximage(int x,int y,const string ID);
	BOOL SetJitte(const string ID,const int n);//�����������
	BOOL SetNoise(const string ID,const int n);//���
	BOOL SetGrayScale(const string ID);//�Ҷ�
	BOOL SetLight(const string ID,int x,int y);//���ȺͶԱȶ�
	BOOL SetResampl(const string ID, int x,int y);//������С


	int LoadDirectory(const TCHAR* DirectName, DWORD format);

	HDC GethMemDC(){ return GO_hMemDC; };
};
#endif