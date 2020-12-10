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
		return 0.8 * price;
	}
};

//sell�࣬���Ը��ݲ�ͬ��ѡ���ʼ����ͬ�Ĵ�����
class Sell
{
public:
	Sell(int select = 1)
	{
		if (select == 1)
		{
			discount = new No();
		}
		else
		{
			discount = new Dis20();
		}
	}
	void doSell(float price)
	{
		cout << discount->dis(price);
	}
private:
	Discount* discount;
};

int main()
{
	Sell* s = new Sell(2);
	s->doSell(100);
	return 0;
}