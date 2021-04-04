/* 13 вариант :: Класс «Треугольник». Поля: длина одной из сторон и величины прилежащих к ней углов.
Методы: вычисление периметра, медианы, проведенной к заданной стороне, радиуса описанной
окружности, перегрузка операции сравнения на равенство «==» двух треугольников.*/



#include <iostream>
#include "triangle.cpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int menu;
    triangle Triangle;
    cout << "Введите длину стороны треугольника:";
    Triangle.set_side1(Triangle.write_side1());
    cout << "Введите величину первого угла:";
    Triangle.set_angle1(Triangle.write_angle1());
    cout << "Введите величину второго угла:";
    Triangle.set_angle2(Triangle.write_angle2());
    getchar();
    do {
        system("cls");
        cout << "1. Периметр треугольника" << endl;
        cout << "2. Найти медиану" << endl;
        cout << "3. Найти радиус описанной окружности" << endl;
        cout << "4. Сравнение треугольников" << endl;
        cout << "5. Напечатать треугольник" << endl;
        cout << "6. Создать треугольник с помощью конструктора" << endl;
        cout << "7. Проверить конструктор копирования" << endl;
        cout << "8. Установить новое значение углу 1" << endl;
        cout << "9. Установить новое значение стороне" << endl;
        cout << "10. Установить новое значение углу 2" << endl;
        cout << "11. Вывести значение 1 угла" << endl;
        cout << "12. Вывести значение стороны" << endl;
        cout << "13. Вывести значение 2 угла" << endl;
        cout << "14. Выход" << endl;
        cin >> menu;
        
        switch (menu)
        {
            case 1:
            {  system("cls");
               cout << "Периметр равен:" << Triangle.perimetr();
               getchar(); 
               break;
            }
            case 2:
            { 
               system("cls");
               cout << "Медиана равна:" << Triangle.mediana();
               getchar();
               break;
            }
            case 3:
            {
                system("cls");
                cout << "Радиус равен:" << Triangle.radius();
                getchar();
                break;
            }

            case 4:
            { 
               triangle Triangle2,Triangle3;
               system("cls");
               cout << "Введите длину стороны первого треугольника:";
               Triangle2.set_side1(Triangle.write_side1());
               cout << "Введите величину первого угла первого треугольника:";
               Triangle2.set_angle1(Triangle.write_angle1());
               cout << "Введите величину второго угла первого треугольника:";
               Triangle2.set_angle2(Triangle.write_angle1());
               system("cls");
               cout << "Введите длину стороны второго треугольника:";
               Triangle3.set_side1(Triangle.write_side1());
               cout << "Введите величину первого угла второго треугольника:";
               Triangle3.set_angle1(Triangle.write_angle1());
               cout << "Введите величину второго угла второго треугольника:";
               Triangle3.set_angle2(Triangle.write_angle2());
               system("cls");
               if (Triangle2 == Triangle3)
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
            case 5:
            {
                system("cls");
                Triangle.print_triangle();
                getchar();
                break;
            }
            case 6:
            {
                system("cls");
                double side1, angle1, angle2;
                cout << "Введите сторону треугольника:";
                cin >> side1;
                cout << "Введите первый угол:";
                cin >> angle1;
                cout << "Введите второй угол:";
                cin >> angle2;
                triangle Triangle(side1, angle1, angle2);
                Triangle.print_triangle();
                getchar();
                break;
            }
            case 7:
            {
                system("cls");
                double side1, angle1, angle2;
                cout << "Введите сторону треугольника:";
                cin >> side1;
                cout << "Введите первый угол:";
                cin >> angle1;
                cout << "Введите второй угол:";
                cin >> angle2;
                triangle Triangle(side1, angle1, angle2);
                triangle Triangle1 = Triangle;
                getchar();
                break;
            }
            case 8:
            {
                system("cls");
                cout << "Введите новое значение 1 угла:";
                Triangle.set_angle1(Triangle.write_angle1());
                break;
            }
            case 9:
            {
                system("cls");
                cout << "Введите новое значение стороны:";
                Triangle.set_side1(Triangle.write_side1());
                break;
            }
            case 10:
            {
                system("cls");
                cout << "Введите новое значение 2 угла:";
                Triangle.set_angle2(Triangle.write_angle2());
                break;
            }
            case 11:
            {
                system("cls");
                cout << "Значение 1 угла равно:" << Triangle.get_angle1();
                getchar();
                break;
            }
            case 12:
            {
                system("cls");
                cout << "Значение стороны равно:" << Triangle.get_side1();
                getchar();
                break;
            }
            case 13:
            {
                system("cls");
                cout << "Значение 2 угла равно:" << Triangle.get_angle2();
                getchar();
                break;
            }
        }
        getchar();
    } while (menu != 14);
}

