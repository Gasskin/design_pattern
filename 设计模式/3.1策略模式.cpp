#pragma once
#include "iostream"
using namespace std;

//���۽ӿ�
class Discount
{
public:
	virtual float dis(float price) = 0;
};

//ԭ��
class No :public Discount
{
public:
	//�����ۣ�ֱ�ӷ���ԭ��
	virtual float dis(float price)override
	{
		return price;
	}
};

//�����
class Dis20:public Discount
{
public:
	virtual float dis(float price)override
	{
		return 0.8f * price;
	}
};

//sell�࣬���Ը��ݲ�ͬ��ѡ���ʼ����ͬ�Ĵ�����
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
