#include "iostream"
using namespace std;

//抽象产品
class Component
{
public:
	Component() {}
	virtual void operation() = 0;
};

//具体产品
class Phone :public Component
{
public:
	Phone() {}
	virtual void operation()override
	{
		cout << "打电话" << endl;
	}
};

//抽象装饰者
class Decorator :public Component
{
public:
	Decorator() {}
	virtual void operation()override
	{
		this->component->operation();
	}
	Component* getComponent()
	{
		return component;
	}
	void setComponent(Component* c)
	{
		this->component = c;
	}
private:
	Component* component;
};

//具体装饰者1
class Internet :public Decorator
{
public:
	Internet(Component* c)
	{
		this->setComponent(c);
	}
	void operation()
	{
		this->getComponent()->operation();
		newOperation();
	}
	void newOperation()
	{
		cout << "上网" << endl;
	}
};

//具体装饰者2
class Video :public Decorator
{
public:
	Video(Component* c)
	{
		this->setComponent(c);
	}
	void operation()
	{
		this->getComponent()->operation();
		newOperation();
	}
	void newOperation()
	{
		cout << "拍视频" << endl;
	}
};


int main()
{
	Component* c = new Phone();
	c->operation();
	cout << "---" << endl;
	Component* cplus = new Internet(c);
	cplus->operation();
	cout << "---" << endl;
	Component* cplusplus = new Video(cplus);
	cplusplus->operation();
	return 0;
}