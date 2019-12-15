#ifndef _GAME_INPUT_
#define _GAME_INPUT_

#include<windows.h>
#include<string>
using namespace std;

#define W 87
#define A 65
#define S 83
#define D 68
#define J 74
#define K 75
#define L 76

class GameInput
{
public:
	float mDeltaTime;
	float mJdeltaTime;
	float mLdeltaTime;
	string State;
	string LastDirect;
	float mXmove, mYmove;
	int mSpeed, mA;

	BOOL mJump;

	BOOL mUP;
	BOOL mDOWN;
	BOOL mLEFT;
	BOOL mRIGHT;
	BOOL mJ;
	BOOL mK;
	BOOL mL;
	BOOL mESC;
	BOOL mSPACE;
	BOOL mF5;

	GameInput();
	~GameInput();
	void Enter();
	void Run(float t);
	void ProcessMsg();
	void ProcessMove();
};

#endif