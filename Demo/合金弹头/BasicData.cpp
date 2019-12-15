#include"BasicData.h"

float cPOINTF::GetDistance(cPOINTF & s)
{
	return sqrt((x - s.x)*(x - s.x) + (y - s.y)*(y - s.y));
}

float cPOINTF::GetAngle(cPOINTF & d)
{
	if (fabs(d.x - x)<1e-6)
	{
		if (d.y<y)
		{
			return 270;
		}
		else
		{
			return 90;
		}
	}
	float a = atan((d.y - y) / (d.x - x)) / 3.1415926 * 180;
	if (d.x<x)
	{
		a += 180;
	}
	return a;
}
BOOL RestrictInBoundary(RECT r)
{
	RECT ir;
	RECT boundary = {0,0,CLIENTWIDTH,CLIENTHEIGHT};
	return IntersectRect(&ir,&boundary,&r);
}