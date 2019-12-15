#ifndef _GONGXIANG_H_
#define _GONGXIANG_H_

#include <windows.h>
#include <math.h>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <io.h>
#include <stdlib.h>

using namespace std;

#define CLIENTWIDTH 800
#define CLIENTHEIGHT 600

#define RIGHT 1
#define LEFT -1
#define UP 1
#define DOWN -1


#define _YL_   0.5f //音量初始化

//敌人数量

#define     SOLDIER1MAX             3
#define     SOLDIER2MAX             1
#define     PLANEMAX               1
#define     TANKMAX                1

//	音效的编号
#define		GAME_MAIN			1
#define		GAME_HJDT			2
#define		GAME_SORT			3
#define		GAME_BACKGROUND		4
#define		GAME_OK		        5
#define		GAME_HELP			6
#define     GAME_BUTTON         7

#define		GUN0     		11
#define		GUN1     		12
#define		GUN2     		13
#define		GUN3     		14
#define		GUN4     		15

#define     BOOM1           16

#define     SOLDIERDIE1        17
#define     SOLDIERDIE2        18
#define     ROLEDIE            19



struct sEXIST
{
	BOOL Die;
	BOOL AnimationEnd;
};
struct sDirect
{
	int x;
	int y;
};


class cPOINTF
{
public:
	float x;
	float y;
	float angle;	// 度数一圈2PI

	float GetDistance(cPOINTF & s);
	float GetAngle(cPOINTF & d);
};
BOOL RestrictInBoundary(RECT r);
#endif