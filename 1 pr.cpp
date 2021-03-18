/* 13 вариант :: Класс «Треугольник». Поля: длина одной из сторон и величины прилежащих к ней углов.
Методы: вычисление периметра, медианы, проведенной к заданной стороне, радиуса описанной
окружности, перегрузка операции сравнения на равенство «==» двух треугольников.*/

#include <iostream>
#include "triangle.h"

using namespace std;



int main()
{
    setlocale(LC_ALL, "Russian");
    char menu;
    triangle Triangle;
    cout << "Введите длину стороны:";
    cin >> Triangle.side1;
    cout << "Введите величину первого угла:";
    cin >> Triangle.angle1;
    cout << "Введите величину второго угла:";
    cin >> Triangle.angle2;
    do {
        system("cls");
        cout << "1. Периметр треугольника" << endl;
        cout << "2. Найти медиану" << endl;
        cout << "3. Найти радиус описанной окружности" << endl;
        cout << "4. Сравнение треугольников" << endl;
        cout << "5. Выход" << endl;
        cin >> menu;
        switch (menu)
        {
            case '1':
            {  system("cls");
               cout << "Периметр равен:";
               cout << Triangle.perimetr(Triangle);
               getchar();
               break;
            }
            case '2':
            { 
               system("cls");
               cout << "Медиана равна:";
               cout << Triangle.mediana(Triangle);
               getchar();
               break;
            }
            case '3':
            {
                system("cls");
                cout << "Радиус равен:";
                cout << Triangle.radius(Triangle);
                getchar();
                break;
            }

            case '4':
            { 
               triangle Triangle2;
               system("cls");
               cout << "Введите длину стороны:";
               cin >> Triangle2.side1;
               cout << "Введите величину первого угла:";
               cin >> Triangle2.angle1;
               cout << "Введите величину второго угла:";
               cin >> Triangle2.angle2;
               system("cls");
               if (Triangle2 == Triangle)
               {
                   cout << "Треугольники равны";
               }
               else
               {
                   cout << "Треугольники не равны";
               }
               getchar();
               break;
            }
        }
        getchar();
    } while (menu != '5');
}

