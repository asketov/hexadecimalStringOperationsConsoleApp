/* 13 вариант :: Класс «Треугольник». Поля: длина одной из сторон и величины прилежащих к ней углов.
Методы: вычисление периметра, медианы, проведенной к заданной стороне, радиуса описанной
окружности, перегрузка операции сравнения на равенство «==» двух треугольников.*/

#include <cmath>
#include <iostream>

using namespace std;

#define PI 3.14159265

class triangle
{
	double side1, angle1, angle2;
public:
	triangle(double Side1=0, double Angle1=0, double Angle2=0) //конструктор с параметрами
	{
		side1 = Side1; angle1 = Angle1; angle2 = Angle2;
	}
	~triangle() //деструктор
	{
	}
	triangle(triangle& Triangle) 	//конструктор копирования
	{
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
	void set_side1()
	{
		cin >> side1;
	}
	void set_angle1()
	{
		cin >> angle1;
	}
	void set_angle2()
	{
		cin >> angle2;
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
		return (side1 * side2 * side3) / ( 4 * sqrt(HalfPerimetr * (HalfPerimetr - side1) * (HalfPerimetr - side2) * (HalfPerimetr - side3)));
	}
	bool operator== (triangle &Triangle)
	{
		return Triangle.angle1 == angle1 && Triangle.angle2 == angle2 && Triangle.side1 == side1;
	}
	
};


