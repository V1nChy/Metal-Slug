#ifndef _BUTTON_
#define _BUTTON_
#include "UI.h"
#include"GameFrame.h"
#include<string>
using namespace std;

class Button :
	public UI
{
public:
	bool mSoundSign;
	string m_InImg;
	string m_OutImg;
	Button(int X1,int Y1,int X2,int Y2,const string In,const string Out);
	~Button();

	void CursorInMove();
	void CursorOutMove();
	void SetSoundSign();
	void ButtonDown(const string ID);
	void Render();
};
#endif

