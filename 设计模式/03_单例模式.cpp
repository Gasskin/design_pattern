#pragma once
#include "iostream"
using namespace std;

//����
//class Singleton
//{
//	Singleton() = default;
//public:
//	void Way()
//	{
//		cout << "һЩ����" << endl;
//	}
//	static Singleton* getInstance()
//	{
//		return instance;
//	}
//private:
//	static Singleton* instance;
//};
//
//Singleton* Singleton::instance = new Singleton();

//����
class Singleton
{
	Singleton() = delete;
	Singleton(const Singleton&) = delete;
public:
	void Way()
	{
		cout << "һЩ����" << endl;
	}
	static Singleton* getInstance()
	{
		static Singleton* instance;
		return instance;
	}
private:
};


int main()
{
	Singleton* s = Singleton::getInstance();
	s->Way();
	return 0;
}