#pragma once
#include "iostream"
using namespace std;

//=============================================
//抽象水果
//=============================================
class Fruit
{
public:
	virtual void eat() = 0;
};
//具体苹果
class Apple :public Fruit
{
public:
	virtual void eat()override
	{
		cout << "吃苹果" << endl;
	}
};
//具体梨子
class Pear :public Fruit
{
public:
	virtual void eat()override
	{
		cout << "吃梨子" << endl;
	}
};
//=============================================
//抽象工厂
//=============================================
class Factory
{
public:
	virtual Fruit* GetFruit() = 0;
};
//苹果工厂
class AppleFactory :public Factory
{
public:
	virtual Fruit* GetFruit()override
	{
		return new Apple();
	}
};
//梨子工厂
class PearFactory :public Factory
{
public:
	virtual Fruit* GetFruit()override
	{
		return new Pear();
	}
};

