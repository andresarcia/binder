#include <iostream>


class B 
{
	public:
	virtual void id() = 0;
};

class A 
{
public:
int a, b;
};

class C : public A, B
{

public:
long long z;

virtual void id()
{
	cout << "soy C";
}
};


class D : public A, B
{
public:
int z;

virtual void id()
{
  	cout << "soy D";
}
};


int main()
{
C c;
D d;

c.a = c.b = 1;

d.a = d.b = 2;

c.z = 3;

d.z = -1;

A * a = &d;

cout << a->a << a->b;

static_cast<C*>(a)->id();
}
