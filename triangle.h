/* 13 вариант :: Класс «Треугольник». Поля: длина одной из сторон и величины прилежащих к ней углов.
Методы: вычисление периметра, медианы, проведенной к заданной стороне, радиуса описанной
окружности, перегрузка операции сравнения на равенство «==» двух треугольников.*/

#include <cmath>

using namespace std;

#define PI 3.14159265


class triangle
{
public:
	double side1, angle1, angle2;
	double perimetr(class triangle Triangle)
	{
		double angle3, side2, side3;
		angle3 = 180 - Triangle.angle1 - Triangle.angle2;
		side2 = fabs(Triangle.side1 * sin(Triangle.angle1 * PI / 180) / sin(angle3 * PI / 180));
		side3 = fabs(Triangle.side1 * sin(Triangle.angle2 * PI / 180) / sin(angle3 * PI / 180));
		return (Triangle.side1 + side2 + side3);
	}
	double mediana(class triangle Triangle)
	{
		double side2, side3;
		double angle3 = 180 - Triangle.angle1 - Triangle.angle2;
		side2 = fabs(Triangle.side1 * sin(Triangle.angle1 * PI / 180) / sin(angle3 * PI / 180));
		side3 = fabs(Triangle.side1 * sin(Triangle.angle2 * PI / 180) / sin(angle3 * PI / 180));
		return 0.5 * sqrt(2 * side2 * side2 + 2 * side3 * side3 - Triangle.side1 * Triangle.side1);
	}
	double radius(class triangle Triangle)
	{
		double side2, side3;
		double angle3 = 180 - Triangle.angle1 - Triangle.angle2;
		side2 = fabs(Triangle.side1 * sin(Triangle.angle1 * PI / 180) / sin(angle3 * PI / 180));
		side3 = fabs(Triangle.side1 * sin(Triangle.angle2 * PI / 180) / sin(angle3 * PI / 180));
		double HalfPerimetr = 0.5 * (Triangle.side1 + side2 + side3);
		return (Triangle.side1 * side2 * side3) / ( 4 * sqrt(HalfPerimetr * (HalfPerimetr - Triangle.side1) * (HalfPerimetr - side2) * (HalfPerimetr - side3)));
	}
	bool operator== (triangle &Triangle)
	{
		return Triangle.angle1 == angle1 && Triangle.angle2 == angle2 && Triangle.side1 == side1;
	}
};


