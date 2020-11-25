#pragma once
#include "iostream"
using namespace std;

//饿汉
//class Singleton
//{
//	Singleton() = default;
//public:
//	void Way()
//	{
//		cout << "一些方法" << endl;
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

//懒汉
class Singleton
{
	Singleton() = delete;
	Singleton(const Singleton&) = delete;
public:
	void Way()
	{
		cout << "一些方法" << endl;
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