#pragma once
#include "iostream"
using namespace std;


//电源类
class Battery
{
public:
	int High()//电源只能制造220V高压
	{
		return 220;
	}
};

//手机类
class Iphone
{
public:
	void get(int Low)//手机充电只能接受10V低压
	{
		if (Low == 10)
		{
			cout << "充电！" << endl;
		}
		else
		{
			cout << "电源类类型不匹配！" << endl;
		}
	}
};

//适配器类
class Adapter
{
public:
	Adapter()
	{
		batter = new Battery();
	}
	int adapt()
	{
		return batter->High() - 210;
	}
private:
	Battery* batter;
};

