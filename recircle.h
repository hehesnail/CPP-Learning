#ifndef __RECIRCLE__
#define __RECIRCLE__

#include <ctime>
#include <random>
#include <iostream>

const double PI = 3.14;

class Shape
{
private:
	int no;
public:
	Shape(int n = 0): no(n) {}
	int getNo() const {return no;}
	virtual int getArea() = 0;
	virtual void print() = 0;
};

class Point 
{
private:
	int x;
	int y;
public:
	Point(int xx = 0, int yy = 0): x(xx), y(yy) {}
	int getX() const {return x;}
	int getY() const {return y;}
};

class Rectangle: public Shape
{
private:
	int width;
	int height;
	Point leftUp;
public:
	Rectangle(int w = 0, int h = 0, int x = 0, int y = 0, int n = 0)
		:Shape(n), width(w), height(h), leftUp(Point(x,y)) {}
	int getArea() override {return width*height;}
	void print() override
	{
	std::cout << "Rectangle: " << this->getNo() << std::endl;
	std::cout << "width, height, x, y:" << width << ','
			  << height << ',' << leftUp.getX() << ',' << leftUp.getY() << std::endl; 
	std::cout << "Area:"<< this->getArea() << std::endl;
	}
};

class Circle: public Shape
{
private:
	Point center;
	int radius;
public:
	Circle(int r = 0, int x = 0, int y = 0, int n = 0)
		:Shape(n), radius(r), center(Point(x,y)){}
	int getArea() override {return static_cast<int>(PI*radius*radius);}
	void print() override
	{
	std::cout << "Circle: " << this->getNo() << std::endl;
	std::cout << "radius, x, y:" << radius << ','
			  << center.getX() << ',' << center.getY() << std::endl; 
	std::cout << "Area:"<< getArea() << std::endl;
	}
};

inline 
void CreateShapes(Shape* res[20])
{
	Shape* s[20];

	static std::default_random_engine e(time(0));
	static std::uniform_int_distribution<unsigned> g(1,11);

	for (int i = 0; i < 20; i++)
	{
		if (i < 10)
			s[i] = new Rectangle(g(e), g(e), g(e), g(e), i);
		else 
			s[i] = new Circle(g(e), g(e), g(e), i);
	}
	int j = 0;
	for (int i = 0; i < 20; i++)
	{
		if (s[i]->getArea() > 50)
		{
			res[j++] = s[i];
		}
		else 
		{
			delete s[i];
		}
	}

	return;
}

#endif