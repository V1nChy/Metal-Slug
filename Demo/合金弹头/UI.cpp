#include"UI.h"

UI::UI(int X1, int Y1, int X2, int Y2,BOOL Active):
x1(X1),
x2(X2),
y1(Y1),
y2(Y2),
active(Active),
BelongScene(0)
{}
void UI::SetUI(int X1, int Y1, int X2, int Y2)
{
	x1 = X1;
	y1 = Y1;
	x2 = X2;
	y2 = Y2;
}
void UI::SetActive(BOOL Active)
{
	active = Active;
}
void UI::CursorInMove(){}
void UI::CursorOutMove(){}
void UI::ButtonDown(const string ID){}
void UI::SetSoundSign(){}
void UI::Render(){}
void UI::Init(){}
void UI::End(){}