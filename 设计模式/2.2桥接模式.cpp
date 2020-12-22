#include<iostream>
using namespace std;

class Shape
{
public:
	Shape(){}
	virtual void operate() = 0;
};

class Circle :public Shape
{
public:
	Circle(){}
	void operate()override
	{
		cout << "Բ��" << endl;
	}
};

class Box :public Shape
{
public:
	Box() {}
	void operate()override
	{
		cout << "����" << endl;
	}
};


class Color
{
public:
	Color(Shape *s):shape(s){}
	virtual void operate() = 0;
	void shapeOperate()
	{
		shape->operate();
	}
private:
	Shape* shape;
};


class Red :public Color
{
public:
	Red(Shape* s):Color(s){}
	void operate()override
	{
		cout << "��ɫ" << endl;
		shapeOperate();
	}
};

class Blue :public Color
{
public:
	Blue(Shape* s):Color(s){}
	void operate()override
	{
		cout << "��ɫ" << endl;
		shapeOperate();
	}
};


