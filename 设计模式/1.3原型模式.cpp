#include<iostream>
using namespace std;

//抽象原型类，主要用于定义clone接口
class Prototype
{
public:
	Prototype(int val) :data(val) {}
	int data;
	virtual Prototype* clone() = 0;
};

//实现类，具体实现接口
class ConcretePro :public Prototype
{
public:
	ConcretePro(int val) :Prototype(val) {}
	Prototype* clone() override
	{
		ConcretePro* cloneData = new ConcretePro(data);
		return cloneData;
	}
};

