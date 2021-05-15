#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Classes.cpp"
#pragma warning(disable : 4703)
using namespace std;


int main() {
	setlocale(0, "Russian");
	char menu = 0;
	int n = 0, i = 0, k1 = 0, k2 = 0;
	Line** strings;
	do {
		system("CLS");
		cout << "1. Инициализация\n";
		cout << "2. Тестирование\n";
		cout << "3. Выход\n";
		cin >> menu;
		switch (menu) {
		case '1':
			system("CLS");
			menu = 0;
			cout << "1. Число элементов\n";
			cout << "2. Начальное значение\n";
			cin >> menu;
			switch (menu) {
			case '1':
				if (n == 0) {
					cout << "Введите число элементов\n";
					cin >> n;
					strings = new Line * [n];
				}
				else
					cout << "Число элементов уже введено\n";
				break;
			case '2':
				if (n == 0) {
					cout << "Число элементов ещё не введено, данный пункт меню недоступен\n";
					break;
				}
				i = 0;
				char* input = new char[100];
				while (i < n) {
					menu = 0;
					*input = NULL;
					cout << "Введите значение элемента №" << i + 1 << endl;
					getchar();
					gets_s(input, 100);
					cout << "Выберите тип элемента №" << i + 1 << endl;
					cout << "1. Строка\n";
					cout << "2. Строка-идентификатор\n";
					cout << "3. Шестнадцатеричная строка\n";
					cin >> menu;
					switch (menu) {
					case '1':
						strings[i] = new Line(input);
						break;
					case '2':
						strings[i] = new LineId(input);
						break;
					case '3':
						strings[i] = new Line16(input);
						
						break;
					default:
						strings[i] = new Line();
						break;
					}
					menu = 0;
					i++;
				}
				break;
			}
			menu = 0;
			getchar();
			break;
		case '2':
			system("CLS");
			menu = 0;
			if (n == 0) {
				cout << "Число элементов ещё не введено, данный пункт меню недоступен\n";
				break;
			}
			cout << "1. Строка\n";
			cout << "2. Строка-идентификатор\n";
			cout << "3. Шестнадцатеричная строка\n";
			cout << "4. Задать операнды\n";
			cin >> menu;
			switch (menu) {
			case '1':
				system("CLS");
				menu = 0;
				cout << "1. Вывод элемента типа Line\n";
				cout << "2. Вывод длины элемента типа Line\n";
				cin >> menu;
				switch (menu) {
				case '1':
					i = 0;
					cout << "Введите номер элемента типа Line\n";
					cin >> i;
					if ((i <= n) && (i > 0))
						*strings[i - 1] << cout;
					else
						cout << "Неверный номер элемента";
					break;
				case '2':
					i = 0;
					cout << "Введите номер элемента типа Line\n";
					cin >> i;
					if ((i <= n) && (i > 0))
						cout << strings[i - 1]->get_length();
					else
						cout << "Неверный номер элемента";
					break;
				}
				menu = 0;
				getchar();
				break;
			case '2':
				system("CLS");
				menu = 0;
				cout << "1. Вывод элемента типа LineId\n";
				cout << "2. Вывод длины элемента типа LineId\n";
				cin >> menu;
				switch (menu) {
				case '1':
					i = 0;
					cout << "Введите номер элемента типа LineId\n";
					cin >> i;
					if ((i <= n) && (i > 0))
						*strings[i - 1] << cout;
					else
						cout << "Неверный номер элемента";
					break;
				case '2':
					i = 0;
					cout << "Введите номер элемента типа LineId\n";
					cin >> i;
					if ((i <= n) && (i > 0))
						cout << strings[i - 1]->get_length();
					else
						cout << "Неверный номер элемента";
					break;
				}
				menu = 0;
				getchar();
				break;
			case '3':
				system("CLS");
				menu = 0;
				cout << "1. Вывод элемента типа Line16\n";
				cout << "2. Вывод длины элемента типа Line16\n";
				cin >> menu;
				switch (menu) {
				case '1':
					i = 0;
					cout << "Введите номер элемента типа Line16\n";
					cin >> i;
					if ((i <= n) && (i > 0))
						*strings[i - 1] << cout;
					else
						cout << "Неверный номер элемента";
					break;
				case '2':
					i = 0;
					cout << "Введите номер элемента типа Line16\n";
					cin >> i;
					if ((i <= n) && (i > 0))
						cout << strings[i - 1]->get_length();
					else
						cout << "Неверный номер элемента";
					break;
				}
				menu = 0;
				getchar();
				break;
			case '4':
				system("CLS");
				menu = 0;
				cout << "1. Слияние двух строк типа LineId\n";
				cout << "2. Сложение двух Шестнадцатеричных чисел\n";
				cout << "3. Проверка на представление Шестнадцатеричного числа как int\n";
				cout << "4. Присвоение строке типа Line значения другой строки типа Line\n";
				cout << "5. Присвоение строке типа LineId значения другой строки типа LineId\n";
				cout << "6. Присвоение строке типа Line16 значения другой строки типа Line16\n";
				cout << "7. Перевод всех символов строки(кроме цифр) в верхний регистр LineId\n";
				cin >> menu;
				switch (menu) {
				case '1':
					cout << "Введите номер первой строки\n";
					cin >> k1;
					cout << "Введите номер второй строки\n";
					cin >> k2;
					*(LineId*)strings[k1 - 1] + *(LineId*)strings[k2 - 1];
					break;
				case '2':
					cout << "Введите номер первой строки\n";
					cin >> k1;
					cout << "Введите номер второй строки\n";
					cin >> k2;
					*(Line16*)strings[k1 - 1] + *(Line16*)strings[k2 - 1];
					break;
				case '3':
					cout << "Введите номер строки\n";
					cin >> k1;
					(*(Line16*)strings[k1 - 1]).may_int();
					break;
				case '4':
					cout << "Введите номер первой строки\n";
					cin >> k1;
					cout << "Введите номер второй строки\n";
					cin >> k2;
					*strings[k1 - 1] = *(Line*)strings[k2 - 1];
					break;
				case '5':
					cout << "Введите номер первой строки\n";
					cin >> k1;
					cout << "Введите номер второй строки\n";
					cin >> k2;
					*strings[k1 - 1] = *(LineId*)strings[k2 - 1];
					break;
				case '6':
					cout << "Введите номер первой строки\n";
					cin >> k1;
					cout << "Введите номер второй строки\n";
					cin >> k2;
					*strings[k1 - 1] = *(Line16*)strings[k2 - 1];
					break;
				case '7':
					cout << "Введите номер строки\n";
					cin >> k1;
					(*(LineId*)strings[k1 - 1]).Up_Id();
					break;
				}
				menu = 0;
				getchar();
				break;
			}
			menu = 0;
			getchar();
			break;
		}
		getchar();
	} while (menu != '3');
}


