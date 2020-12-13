#pragma once
#include "iostream"
using namespace std;

//打折接口
class Discount
{
public:
	virtual float dis(float price) = 0;
};

//原价
class No :public Discount
{
public:
	//不打折，直接返回原价
	virtual float dis(float price)override
	{
		return price;
	}
};

//打八折
class Dis20:public Discount
{
public:
	virtual float dis(float price)override
	{
		return 0.8f * price;
	}
};

//sell类，可以根据不同的选择初始化不同的打折类
class Sell
{
public:
	Sell(Discount* dis)
	{
		discount = dis;
	}
	void doSell(float price)
	{
		cout << discount->dis(price);
	}
private:
	Discount* discount;
};
