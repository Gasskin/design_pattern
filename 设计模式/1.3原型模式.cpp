#include<iostream>
using namespace std;

//����ԭ���࣬��Ҫ���ڶ���clone�ӿ�
class Prototype
{
public:
	Prototype(int val) :data(val) {}
	int data;
	virtual Prototype* clone() = 0;
};

//ʵ���࣬����ʵ�ֽӿ�
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

