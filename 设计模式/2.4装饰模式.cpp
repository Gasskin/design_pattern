#include "iostream"
using namespace std;

//�����Ʒ
class Component
{
public:
	Component() {}
	virtual void operation() = 0;
};

//�����Ʒ
class Phone :public Component
{
public:
	Phone() {}
	virtual void operation()override
	{
		cout << "��绰" << endl;
	}
};

//����װ����
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

//����װ����1
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
		cout << "����" << endl;
	}
};

//����װ����2
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
		cout << "����Ƶ" << endl;
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