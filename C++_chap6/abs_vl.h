#pragma once
#ifndef ABS_VL_H
#define ABS_VL_H
struct abs_vl
{
public:
	int abs_vl1(int k1)
	{
		int k;
		k = k1;
		if (k1 < 0)k = -k;
		
		return k;
	}
};
#endif