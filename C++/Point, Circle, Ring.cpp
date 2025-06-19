#include <iostream>
using namespace std;

class Point
{
private:
	int xpos;
	int ypos;

public:
	Point(int x, int y) : xpos(x), ypos(y) {}
	void ShowPointInfo() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

class Circle
{
private:
	int rad;
	Point center;

public:
	Circle(int x, int y, int r) : center(x, y)
	{
		rad = r;
	}
	void ShowCircleInfo() const
	{
		cout << "radius: " << rad << endl;
		center.ShowPointInfo();
	}
};

class Ring
{
private:
	Circle incircle;
	Circle outcircle;

public:
	Ring(int inX, int inY, int inR, int outX, int outY, int outR) : incircle(inX, inY, inR), outcircle(outX, outY, outR) {}
	void ShowRingInfo() const
	{
		cout << "Inner Circle Info..." << endl;
		incircle.ShowCircleInfo();
		cout << "Outter Circle Info..." << endl;
		outcircle.ShowCircleInfo();
	}
};

int main()
{
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}