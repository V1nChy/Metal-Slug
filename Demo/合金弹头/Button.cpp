#include "Button.h"

Button::Button(int X1, int Y1, int X2, int Y2,const string In,const string Out) :
UI(X1,Y1,X2,Y2,FALSE),
m_InImg(In),
m_OutImg(Out),
mSoundSign(FALSE)
{}

void Button::CursorInMove()
{
	active = true;
}
void Button::CursorOutMove()
{
	active = false;
}
void Button::SetSoundSign()
{
	mSoundSign = true;
}
void Button::ButtonDown(const string ID)
{
	GameFrame::GetObject()->SetScene(SceneID);
}
void Button::Render()
{
	if (mSoundSign)
	{
		mSoundSign = false;
		Scene::sound.play(GAME_BUTTON);
	}

	if (active)
		GameFrame::GetObject()->GetGO()->DrawCximage((x2 + x1) / 2, (y2 + y1) / 2, m_InImg);
	else
		GameFrame::GetObject()->GetGO()->DrawCximage((x2 + x1) / 2, (y2 + y1) / 2, m_OutImg);
}

Button::~Button()
{
}
