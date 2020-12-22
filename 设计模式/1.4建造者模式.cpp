#include <iostream>
using namespace std;

//Ŀ���Ʒ
class Computer
{
	friend class AppleBuilder;
	friend class LenovoBuilder;
public:
	Computer(string iCpu, string iRam):cpu(iCpu),ram(iRam){}
	void show()
	{
		cout << cpu << " " << ram << " " << display << " " << keyboard << endl;
	}
private:
	void setDisplay(string dis)
	{
		this->display = dis;
	}
	void setKeyboard(string keyb)
	{
		this->keyboard = keyb;
	}
private:
	string cpu;//����
	string ram;//����
	string display;//��ѡ
	string keyboard;//��ѡ
};

//�������߽ӿ�
class AbstractBuilder
{
public:
	virtual void setDisplay() = 0;
	virtual void setKeyboard() = 0;
	virtual Computer* getComputer() = 0;
};

//���彨����A��ƻ��
class AppleBuilder:public AbstractBuilder
{
public:
	AppleBuilder(string cpu, string ram)
	{
		computer = new Computer(cpu, ram);
	}
	void setDisplay() override
	{
		computer->setDisplay("ƻ����ʾ��");
	}
	void setKeyboard() override
	{
		computer->setKeyboard("ƻ������");
	}
	Computer* getComputer() override
	{
		return computer;
	}
private:
	Computer* computer;
};

//���彨����B������
class LenovoBuilder :public AbstractBuilder
{
public:
	LenovoBuilder(string cpu, string ram)
	{
		computer = new Computer(cpu, ram);
	}
	void setDisplay() override
	{
		computer->setDisplay("������ʾ��");
	}
	void setKeyboard() override
	{
		computer->setKeyboard("�������");
	}
	Computer* getComputer() override
	{
		return computer;
	}
private:
	Computer* computer;
};

//ָ����
class Director
{
public:
	Director(){}
	void makeBuilder(AbstractBuilder* builder)
	{
		builder->setDisplay();
		builder->setKeyboard();
	}
};

int main()
{
	Director* comDirecor = new Director();
	AbstractBuilder* builder = new LenovoBuilder("I7", "16G");
	comDirecor->makeBuilder(builder);
	Computer* computer = builder->getComputer();
	computer->show();
	return 0;
}
