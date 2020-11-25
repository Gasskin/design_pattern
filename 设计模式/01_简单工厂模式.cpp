#pragma once
#include "iostream"
using namespace std;

class Fruit
{
public:
	virtual void eat() = 0;
};

class Apple :public Fruit
{
public:
	virtual void eat()override
	{
		cout << "吃苹果" << endl;
	}
};

class Pear :public Fruit
{
public:
	virtual void eat()override
	{
		cout << "吃梨子" << endl;
	}
};

class FruitFactory
{
public:
	Fruit* getFruit(int FruitID)
	{
		switch (FruitID)
		{
		case 0:
			return new Apple();
		case 1:
			return new Pear();
		default:
			cout << "不存在这种水果" << endl;
			break;
		}
	}
};

int main()
{
	FruitFactory* factory = new FruitFactory();
	Fruit* apple = factory->getFruit(0);
	apple->eat();
	return 0;
}