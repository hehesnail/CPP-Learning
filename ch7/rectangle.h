#ifndef __MYREC__
#define __MYREC__

class Shape
{
private:
	int no;
public:
	Shape(int i = 0):no(i) {}
	void operator = (const Shape& r)
	{
		no = r.no;
	}
	int getNo() const {return no;}
};

class Point
{
private:
	int x;
	int y;
public:
	Point(int xx = 0, int yy = 0)
		:x(xx), y(yy){}
	int getX() const {return x;}
	int getY() const {return y;}
};

class Rectangle:public Shape
{
private:
	int width;
	int height;
	Point* leftUp;

public:
	Rectangle (int w, int h, int x, int y, int n);
	Rectangle (const Rectangle& other);
	Rectangle& operator = (const Rectangle& other);
	~Rectangle();
	int getW() const {return width;}
	int getH() const {return height;}
	Point* getPoi() const {return leftUp;}
};

inline 
Rectangle::Rectangle(int w, int h, int x, int y, int n)
:Shape(n), width(w), height(h)
{
	leftUp = new Point(x, y);
}

inline 
Rectangle::Rectangle (const Rectangle& other):Shape(other),width(other.width), height(other.height)
{
	if (other.leftUp != nullptr)
	{
		leftUp = new Point(*(other.leftUp));
	}
	else
	{
		leftUp = nullptr;
	}
}

inline 
Rectangle& Rectangle::operator = (const Rectangle& other)
{
	if (this == &other)
	{
		return *this;
	}

	Shape::operator = (other);
	width = other.width;
	height = other.height;

	if (leftUp != nullptr)
	{
		if (other.leftUp != nullptr)
		{
			leftUp = new Point(*(other.leftUp));
		}
		else
		{
			delete leftUp;
			leftUp = nullptr;
		}
	}
	else
	{
		if (other.leftUp != nullptr)
		{
			leftUp = new Point(*(other.leftUp));
		}
	}

	return *this;
}

inline 
Rectangle::~Rectangle()
{
	delete leftUp;
}

#endif