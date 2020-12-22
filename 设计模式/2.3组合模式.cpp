#include<iostream>
#include <vector>
using namespace std;

//==============================================================================================
//抽象接口
class Component
{
public:
	Component(){}
	Component(string iName):name(iName){}
	virtual void add(Component*) = 0;
	virtual void remove(Component*) = 0;
	virtual void operation() = 0;
	string& getName()
	{
		return name;
	}
private:
	string name;
};

//==============================================================================================
//抽象叶子构件
class Office :public Component
{
public:
	Office() {}
	Office(string iName) :name(iName){}
	void add(Component*) override
	{
		cout << "to do..." << endl;
	}
	void remove(Component*) override
	{
		cout << "to do..." << endl;
	}
	void operation() override
	{
		cout << "to do..." << endl;
	}
private:
	string name;
};

//具体 行政办公室
class AdminOffice :public Office
{
public:
	AdminOffice(string iName):name(iName){}
	void operation() override
	{
		cout << name << " 行政办公室收到通知" << endl;
	}
private:
	string name;
};

//具体 教务办公室
class DeanOffice :public Office
{
public:
	DeanOffice(string iName) :name(iName) {}
	void operation() override
	{
		cout << name << " 教务办公室收到通知" << endl;
	}
private:
	string name;
};

//==============================================================================================
//抽象容器构件
class SubComponent :public Component
{
public:
	SubComponent(string iName):name(iName){}

	void add(Component* c) override
	{
		componentList.push_back(c);
	}
	void remove(Component* c) override
	{
		for (int i = 0; i < componentList.size(); i++)
		{
			if (componentList[i]->getName() == c->getName())
			{
				componentList.erase(componentList.begin() + i);
				break;
			}
		}
	}
	void operation()
	{
		cout << name << " 下发通知" << endl;
		for (int i = 0; i < componentList.size(); i++)
		{
			((Component*)componentList[i])->operation();
		}
	}
private:
	string name;

	//构件列表
	vector<Component*>componentList;
};

int main()
{
	Component* head = new SubComponent("总部");
	Component* branch1 = new SubComponent("江苏分部");
	Component* branch2 = new SubComponent("南京分部");

	Component* office1_1 = new AdminOffice("江苏");
	Component* office1_2 = new DeanOffice("江苏");

	Component* office2_1 = new AdminOffice("南京");
	Component* office2_2 = new DeanOffice("南京");

	head->add(branch1);
	head->add(branch2);

	branch1->add(office1_1);
	branch1->add(office1_2);

	branch2->add(office2_1);
	branch2->add(office2_2);

	head->operation();
	return 0;
}