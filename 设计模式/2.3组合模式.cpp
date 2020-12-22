#include<iostream>
#include <vector>
using namespace std;

//==============================================================================================
//����ӿ�
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
//����Ҷ�ӹ���
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

//���� �����칫��
class AdminOffice :public Office
{
public:
	AdminOffice(string iName):name(iName){}
	void operation() override
	{
		cout << name << " �����칫���յ�֪ͨ" << endl;
	}
private:
	string name;
};

//���� ����칫��
class DeanOffice :public Office
{
public:
	DeanOffice(string iName) :name(iName) {}
	void operation() override
	{
		cout << name << " ����칫���յ�֪ͨ" << endl;
	}
private:
	string name;
};

//==============================================================================================
//������������
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
		cout << name << " �·�֪ͨ" << endl;
		for (int i = 0; i < componentList.size(); i++)
		{
			((Component*)componentList[i])->operation();
		}
	}
private:
	string name;

	//�����б�
	vector<Component*>componentList;
};

int main()
{
	Component* head = new SubComponent("�ܲ�");
	Component* branch1 = new SubComponent("���շֲ�");
	Component* branch2 = new SubComponent("�Ͼ��ֲ�");

	Component* office1_1 = new AdminOffice("����");
	Component* office1_2 = new DeanOffice("����");

	Component* office2_1 = new AdminOffice("�Ͼ�");
	Component* office2_2 = new DeanOffice("�Ͼ�");

	head->add(branch1);
	head->add(branch2);

	branch1->add(office1_1);
	branch1->add(office1_2);

	branch2->add(office2_1);
	branch2->add(office2_2);

	head->operation();
	return 0;
}