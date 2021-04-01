/* 13 вариант :: Класс «Треугольник». Поля: длина одной из сторон и величины прилежащих к ней углов.
Методы: вычисление периметра, медианы, проведенной к заданной стороне, радиуса описанной
окружности, перегрузка операции сравнения на равенство «==» двух треугольников.*/

#include <cmath>
#include <iostream>
#include <cassert>

using namespace std;

#define PI 3.14159265

class triangle
{
private:
	double side1, angle1, angle2;
public:
	triangle(double Side1 = 10, double Angle1 = 60, double Angle2 = 60) //конструктор с параметрами
	{
		set_side1(Side1);
		set_angle1(Angle1);
		set_angle2(Angle2);
		cout << "Сработал конструктор с парамeтрами" << endl;
	}
	~triangle() //деструктор
	{
	}
	triangle(triangle& Triangle) 	//конструктор копирования
	{
		side1 = Triangle.side1; angle1 = Triangle.angle1; angle2 = Triangle.angle2;
		cout << "Сработал конструктор копирования" << endl;
	}
	double get_side1()
	{
		return side1;
	}
	double get_angle1()
	{
		return angle1;
	}
	double get_angle2()
	{
		return angle2;
	}
	void set_side1(double Side1)
	{
		assert(Side1 >= 0);
		side1 = Side1;

	}
	void set_angle1(double Angle1)
	{
		assert(Angle1 > 0 || Angle1 < 180);
		angle1 = Angle1;
	}
	void set_angle2(double Angle2)
	{
		assert(Angle2 > 0 || Angle2 < 180);
		angle2 = Angle2;
	}
	double write_side1()
	{
		double Side1;
		cin >> Side1;
		return Side1;
	}
	double write_angle1()
	{
		double Angle1;
		cin >> Angle1;
		return Angle1;
	}
	double write_angle2()
	{
		double Angle2;
		cin >> Angle2;
		return Angle2;
	}
	void print_triangle()
	{
		cout << "Сторона равна:" << side1 << endl;
		cout << "Угол 1 равен:" << angle1 << endl;
		cout << "Угол 2 равен:" << angle2 << endl;
	}
	double perimetr()
	{
		double angle3, side2, side3;
		angle3 = 180 - angle1 - angle2;
		side2 = fabs(side1 * sin(angle1 * PI / 180) / sin(angle3 * PI / 180));
		side3 = fabs(side1 * sin(angle2 * PI / 180) / sin(angle3 * PI / 180));
		return (side1 + side2 + side3);
	}
	double mediana()
	{
		double side2, side3;
		double angle3 = 180 - angle1 - angle2;
		side2 = fabs(side1 * sin(angle1 * PI / 180) / sin(angle3 * PI / 180));
		side3 = fabs(side1 * sin(angle2 * PI / 180) / sin(angle3 * PI / 180));
		return 0.5 * sqrt(2 * side2 * side2 + 2 * side3 * side3 - side1 * side1);
	}
	double radius()
	{
		double side2, side3;
		double angle3 = 180 - angle1 - angle2;
		side2 = fabs(side1 * sin(angle1 * PI / 180) / sin(angle3 * PI / 180));
		side3 = fabs(side1 * sin(angle2 * PI / 180) / sin(angle3 * PI / 180));
		double HalfPerimetr = 0.5 * (side1 + side2 + side3);
		return (side1 * side2 * side3) / (4 * sqrt(HalfPerimetr * (HalfPerimetr - side1) * (HalfPerimetr - side2) * (HalfPerimetr - side3)));
	}
	bool operator== (triangle& Triangle)
	{
		double angle3 = 180 - angle1 - angle2;
		double side2 = fabs(side1 * sin(angle1 * PI / 180) / sin(angle3 * PI / 180));
		double side3 = fabs(side1 * sin(angle2 * PI / 180) / sin(angle3 * PI / 180));
		double Triangle_angle3 = 180 - Triangle.angle1 - Triangle.angle2;
		double Triangle_side2 = fabs(Triangle.side1 * sin(Triangle.angle1 * PI / 180) / sin(Triangle_angle3 * PI / 180));
		double Triangle_side3 = fabs(Triangle.side1 * sin(Triangle.angle2 * PI / 180) / sin(Triangle_angle3 * PI / 180));
		if (side1 == Triangle.side1 && angle1 == Triangle.angle1 && angle2 == Triangle.angle2) return true;
		else if (angle1 == Triangle.angle1)
		{
			if (angle2 == Triangle_angle3 && side1 == Triangle_side3)
			{
				return true;
			}
			if (angle3 == Triangle.angle2 && side3 == Triangle.side1)
			{
				return true;
			}
		}
		else if (angle2 == Triangle.angle2)
		{
			if (angle1 == Triangle_angle3 && side1 == Triangle_side2)
			{
				return true;
			}
			if (angle3 == Triangle.angle1 && side2 == Triangle.side1)
			{
				return true;
			}
		}
		else if (angle3 == Triangle_angle3)
		{
			if (angle1 == Triangle.angle2 && side3 == Triangle_side2)
			{
				return true;
			}
			if (angle2 == Triangle.angle1 && side2 == Triangle_side3)
			{
				return true;
			}
		}
		else if (angle1 == Triangle.angle2)
		{
			if (angle3 == Triangle.angle1 && side3 == Triangle.side1)
			{
				return true;
			}
			if (angle2 == Triangle_angle3 && side1 == Triangle_side2)
			{
				return true;
			}
		}
		else if (angle2 == Triangle.angle1)
		{
			if (angle1 == Triangle.angle2 && side1 == Triangle.side1)
			{
				return true;
			}
			if (angle1 == Triangle_angle3 && side1 == Triangle_side3)
			{
				return true;
			}
		}
		else return false;
	}
};


