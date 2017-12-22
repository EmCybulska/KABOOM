#pragma once

class Point
{
public:
	Point();
	Point(int x, int y);
	virtual ~Point() = default;

	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	void add(int x, int y);

private:
	int _x;
	int _y;
};

