#ifndef SHAPES_H
#define SHAPES_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class Shape
{
public:
	Shape() {
		std::cout << "Constructing Shape.\n";
	}
	virtual ~Shape() {
		std::cout << "Destructing Shape.\n";
	}
	virtual double getPerimeter() const = 0;
	virtual double getSquare() const = 0;
	virtual void getInfo() const = 0;
};

//////////////////////////////////////////////////////////////////

class Ellipse : public Shape
{
private:
	double a, b;

public:
	Ellipse(double tmp1 = 0, double tmp2 = 0) : a(std::max(tmp1, tmp2)), b(std::min(tmp1, tmp2))
	{
		std::cout << "Constructing Ellipse.\n";
	}
	virtual ~Ellipse()
	{
		std::cout << "Destructing Ellipse.\n";
	}
	virtual double getPerimeter() const override;
	virtual double getSquare() const override;
	virtual void getInfo() const override;

public:
	double getLarge() const { return a; }
	double getSmall() const { return b; }
	void setLarge(double tmp) { a = tmp; }
	void setSmall(double tmp) { b = tmp; }
};

//////////////////////////////////////////////////////////////////

class Circle : public Ellipse
{
private:
	double r;

public:
	Circle(double tmp = 0) : r(tmp)
	{
		std::cout << "Constructing Circle.\n";
	}
	virtual ~Circle()
	{
		std::cout << "Destructing Circle.\n";
	}
	virtual double getPerimeter() const override final;
	virtual double getSquare() const override final;
	virtual void getInfo() const override final;

public:
	double getRadius() const { return r; }
	void setRadius(double tmp) { r = tmp; }

	double getLarge() const = delete;
	double getSmall() const = delete;
	void setLarge(double tmp) = delete;
	void setSmall(double tmp) = delete;
};

///////////////////////////////////////////////////////////////////////////

class Polygon : public Shape
{
private:
	int numOfAngles;
protected:
	std::vector<double> Lines;
	Polygon(int tmp = 3) : numOfAngles(tmp)
	{
		Lines.resize(numOfAngles);
		std::cout << "Constructing Polygon.\n";
	}
public:
	Polygon(int tmp, const std::vector<double>& tmp1) : numOfAngles(tmp)
	{
		if (tmp < 3)
		{
			std::cout << "Error: unable to create polygon.\n";
			return;
		}
		for (auto i = 0; i < numOfAngles; i++)
			Lines.push_back(tmp1[i]);
		std::cout << "Constructing Polygon.\n";
	}
	virtual ~Polygon()
	{
		Lines.clear();
		std::cout << "Destructing Polygon.\n";
	}
	virtual double getPerimeter() const = 0;
	virtual double getSquare() const = 0;
	virtual void getInfo() const = 0;

	double getNumOfAngles() const { return numOfAngles; }
	void setNumOfAngles(int tmp) { numOfAngles = tmp; }

	const std::vector<double>& getLines() const { return Lines; }
	void setLines(std::vector<double>& inputLines)
	{
		if (inputLines.size() != numOfAngles)
		{
			std::cout << "Error: unable to set polygon lines.\n";
			return;
		}

		for (int i = 0; i < numOfAngles; i++) Lines[i] = inputLines[i];
	}
};

//////////////////////////////////////////////////////////////////////////

class Triangle : public Polygon
{
private:
	bool check(double a, double b, double c);
public:
	Triangle() = delete;
	Triangle(const std::vector<double>& tmp) : Polygon(3, tmp)
	{
		if (!check(tmp[0], tmp[1], tmp[2]))
		{
			std::cout << "Error: unable to construct triangle.\n";
			return;
		}
		std::cout << "Constructing Triangle.\n";
	}
	Triangle(double a, double b, double c) : Polygon(3)
	{
		if (!check(a, b, c))
		{
			std::cout << "Error: unable to construct triangle.\n";
			return;
		}
		std::vector<double> tmp{ a, b, c };
		setLines(tmp);
		std::cout << "Constructing Triangle.\n";
	}
	virtual ~Triangle()
	{
		std::cout << "Destructing Triangle.\n";
	}

	virtual double getPerimeter() const override final;
	virtual double getSquare() const override final;
	virtual void getInfo() const override final;

	double getNumOfAngles() const = delete;
	void setNumOfAngles(int tmp) = delete;
};

////////////////////////////////////////////////////////////////////////

class Quadangle : public Polygon
{
protected:
	Quadangle() : Polygon(4)
	{
		std::cout << "Constructing Quadangle.\n";
	}

public:
	Quadangle(const std::vector<double>& tmp) : Polygon(4, tmp)
	{
		std::cout << "Constructing Quadangle.\n";
	}
	virtual ~Quadangle()
	{
		std::cout << "Destructing Quadangle.\n";
	}

	virtual double getPerimeter() const = 0;
	virtual double getSquare() const = 0;
	virtual void getInfo() const = 0;

	double getNumOfAngles() const = delete;
	void setNumOfAngles(int tmp) = delete;
};

/////////////////////////////////////////////////////////////////

class Rectangle : public Quadangle
{
private:
	double a, b;

public:
	Rectangle() = delete;
	Rectangle(double tmp1, double tmp2 = 0) : a(tmp1), b(tmp2)
	{
		std::cout << "Constructing Rectangle.\n";
	}
	virtual ~Rectangle()
	{
		std::cout << "Destructing Rectangle.\n";
	}

	virtual double getPerimeter() const override;
	virtual double getSquare() const override;
	virtual void getInfo() const override;
};

//////////////////////////////////////////////////////////////////////

class Square : public Rectangle
{
private:
	double a;

public:
	Square(double tmp) : a(tmp), Rectangle(tmp)
	{
		std::cout << "Constructing Square.\n";
	}
	virtual ~Square()
	{
		std::cout << "Destructing Square.\n";
	}

	virtual double getPerimeter() const override final;
	virtual double getSquare() const override final;
	virtual void getInfo() const override final;
};
#endif // !SHAPES_H
