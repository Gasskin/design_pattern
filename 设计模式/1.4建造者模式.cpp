#include <iostream>
using namespace std;

//目标产品
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
	string cpu;//必须
	string ram;//必须
	string display;//可选
	string keyboard;//可选
};

//抽象建造者接口
class AbstractBuilder
{
public:
	virtual void setDisplay() = 0;
	virtual void setKeyboard() = 0;
	virtual Computer* getComputer() = 0;
};

//具体建造者A，苹果
class AppleBuilder:public AbstractBuilder
{
public:
	AppleBuilder(string cpu, string ram)
	{
		computer = new Computer(cpu, ram);
	}
	void setDisplay() override
	{
		computer->setDisplay("苹果显示器");
	}
	void setKeyboard() override
	{
		computer->setKeyboard("苹果键盘");
	}
	Computer* getComputer() override
	{
		return computer;
	}
private:
	Computer* computer;
};

//具体建造者B，联想
class LenovoBuilder :public AbstractBuilder
{
public:
	LenovoBuilder(string cpu, string ram)
	{
		computer = new Computer(cpu, ram);
	}
	void setDisplay() override
	{
		computer->setDisplay("联想显示器");
	}
	void setKeyboard() override
	{
		computer->setKeyboard("联想键盘");
	}
	Computer* getComputer() override
	{
		return computer;
	}
private:
	Computer* computer;
};

//指导者
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
