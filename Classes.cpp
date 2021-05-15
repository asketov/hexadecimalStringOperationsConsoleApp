#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Line // класс строка
{
private:
	int length;
	char* line;
public:
	~Line()
	{
		delete line;
		cout << "Сработал деструктор класса Line\n";
	}
	Line()
	{
		set_length(0);
		set_line(NULL);
		cout << "Сработал конструктор без параметров класса Line\n";
	}
	Line(char* Line)
	{
		line = new char[strlen(Line) + 1];
		length = strlen(Line);
		strcpy_s(line, strlen(Line)+1, Line);
		cout << "Сработал конструктор с параметрами класса Line 22\n";
	}
	Line(char Line)
	{
		length = 1;
		line = &Line;
	}
	Line(Line& line1)
	{
		static int k = 0;
		length = line1.length;
		line = line1.line;
		k++;
		cout << "Сработал конструктор копирования класса Line " << k << " раз";
	}
	int get_length()
	{
		return length;
	}
	char* get_line()
	{
		return line;
	}
	void set_length(int length)
	{
		this->length = length;
	}
	void set_line(char* line)
	{
		this->line = line;
	}
	void operator= (Line& line1)
	{
		delete line;
		line = new char[strlen(line1.line) + 1];
		strcpy_s(line, strlen(line1.line)+1, line1.line);
		length = line1.length;
	}
	ostream& operator<<(ostream& out) {
		if (line != NULL)
			out << line;
		else
			cout << "Строка пуста";
		return out;
	}
	istream& operator>>(istream& in) {
		cout << "Введите строку\n";
		in >> line;
		return in;
	}
};

class LineId : public Line //класс Строка-идентификатор
{
public:
	LineId()
	{

		cout << "Сработал конструктор по умолчанию класса LineId\n";
	}
	~LineId()
	{
		cout << "Сработал деструктор класса LineId\n";
	}
	LineId(char* Line)
	{
		int i = 0;
		char* LineIden;
		if (isdigit(Line[i]))
		{
			return;
		}
		else i++;
		while (i < strlen(Line) && (isalpha(Line[i]) || isdigit(Line[i]) || Line[i] == '_'))
			i++;
		if (i != strlen(Line))
		{
			return;
		}

		LineIden = new char[strlen(Line) + 1];
		strcpy_s(LineIden, strlen(Line)+1, Line);
		set_length(strlen(Line));
		set_line(LineIden);
		cout << "Сработал конструктор с параметрами класса LineId\n";
	}
	LineId(LineId& line1)
	{
		static int k = 0;
		set_length(line1.get_length());
		set_line(line1.get_line());
		k++;
		cout << "Сработал конструктор копирования класса LineId " << k << " раз";
	}
	LineId& operator= (LineId& Id)
	{
		char* LineIden;
		LineIden = new char[strlen(Id.get_line()) + 1];
		strcpy_s(LineIden, strlen(Id.get_line())+1, Id.get_line());
		set_length(strlen(Id.get_line()));
		set_line(LineIden);
	}
	LineId& operator+ (LineId& Id)
	{
		char* lin;
		if (get_line() == NULL)
		{
			if (Id.get_line() != NULL)
			{
				lin = new char[strlen(Id.get_line()) + 1];
				strcpy_s(lin, strlen(Id.get_line()) + 1, Id.get_line());
				set_line(lin);
				return *this;
			}
			else {
				cout << "Обе строки пустые, сумма невозможна\n"; return *this;
			}

		}
		else if (Id.get_line() == NULL)
		{
			cout << "Вторая строка пустая\n"; return *this;
		}
		lin = new char[strlen(this->get_line()) + strlen(Id.get_line()) + 1];
		strcpy_s(lin, strlen(this->get_line()) + 1, get_line());
		strcat_s(lin , strlen(this->get_line()) + strlen(Id.get_line()) + 1, Id.get_line());
		delete this->get_line();
		this->set_line(lin);
		this->set_length(strlen(get_line()));
		cout << endl << get_line() << endl;
		return *this;
		
	}
	void Up_Id()
	{
		char* LineIden = get_line();
		for (int i = 0; i < get_length();i++)
		{
			if (LineIden[i] > 96 && LineIden[i] < 123)
			{
				LineIden[i] -= 32;
			}
		}
		cout << endl << LineIden << endl;
	}
};

class Line16 : public Line //класс шестнадцатеричная  строка
{
public:
	Line16()
	{
		cout << "Сработал конструктор по умолчанию класса Line16 \n";
	}
	Line16(char* l)
	{
		int j=0;
		char* line16;
		if (!(l[0] == 43 || l[0] == 45 || l[0] >= 48 && l[0] <= 57 || l[0] >= 65 && l[0] <= 70 || l[0] >= 97 && l[0] <= 102))
		{
			char* l = new char [1];
			l[0] = '0';
			set_line(l);
			set_length(1);
			cout << "Сработал конструктор с параметрами класса Line16 1\n";
			return;
		}
		else { j++; }
		for (int i = 1; i < strlen(l); i++)
		{
			if (l[i] >= 48 && l[i] <= 57 || l[i] >= 65 && l[i] <= 70 || l[i] >= 97 && l[i] <= 102)
			{
				j++;
			}
		}
		if (j == strlen(l))
		{
			line16 = new char[strlen(l) + 1];
			strcpy_s(line16, strlen(l)+1, l);
			set_line(line16);
			if (l[0] == 43 || l[0] == 45)
			{
				set_length(j - 1);
			}
			else set_length(j);
			cout << "Сработал конструктор с параметрами класса Line16 2\n";
		}
		else
		{
			char* l = new char;
			*l = '0';
			set_line(l);
			set_length(1);
			cout << "Сработал конструктор с параметрами класса Line16 2\n";
		}
	}
	~Line16()
	{
		cout << endl << "Сработал деструктор класса Line16\n";
	}
	Line16(Line16& line1)
	{
		static int k = 0;
		set_length(line1.get_length());
		set_line(line1.get_line());
		k++;
		cout << "Сработал конструктор копирования класса Line16 " << k << " раз";
	}
	void may_int()
	{
		int size = sizeof(int);
		char* l = get_line();
		int len = get_length();
		if (size == 2)
		{
			if (l[0] == 43)
			{
				len -= 1;
				if (len > 4)
				{
					cout << "Число не может быть представлено как int\n";
					return;
				}
				if (len == 4 && l[1] > 55)
				{
					cout << "Число не может быть представлено как int\n";
				}
				else
				{
					cout << "Число может быть представлено как int\n";
				}
			}
			else if (l[0] == 45)
			{
				len -= 1;
				if (len > 4)
				{
					cout << "Число не может быть представлено как int\n";
					return;
				}
				if (len == 4 && l[1] > 55)
				{
					if (l[1] == 56)
					{
						bool flag;
						for (int i = 2; i < len + 2; i++)
						{
							if (l[i] == 48)
							{
								flag = 1;
							}
							else 
							{
								flag = 0; break;
							}
						}
						if (flag == 0)
						{
							cout << "Число не может быть представлено как int\n";
							return;
						}
						else
						{
							cout << "Число может быть представлено как int\n";
							return;
						}
						
					}
					cout << "Число не может быть представлено как int\n";
				}
				else
				{
					cout << "Число может быть представлено как int\n";
				}
			}
			else
			{
				if (len > 4)
				{
					cout << "Число не может быть представлено как int\n";
				}
				if (len == 4 && l[0] > 55)
				{
					cout << "Число не может быть представлено как int\n";
				}
				else
				{
					cout << "Число может быть представлено как int\n";
				}
			}
		}
		else
		{
			if (l[0] == 43)
			{
				len -= 1;
				if (len > 8)
				{
					cout << "Число не может быть представлено как int\n";
					return;
				}
				if (len == 8 && l[1] > 55)
				{
					cout << "Число не может быть представлено как int\n";
					return;
				}
				else
				{
					cout << "Число может быть представлено как int\n";
					return;
				}
			}
			else if (l[0] == 45)
			{
				len -= 1;
				if (len > 8)
				{
					cout << "Число не может быть представлено как int\n";
					return;
				}
				else if (len == 8 && l[1] > 55)
				{
					if (l[1] == 56)
					{
						bool flag;
						for (int i = 2; i < len + 1; i++)
						{
							if (l[i] == 48)
							{
								flag = 1;
							}
							else
							{
								flag = 0; break;
							}
						}
						if (flag == 0)
						{
							cout << "Число не может быть представлено как int";
							return;
						}
						else
						{
							cout << "Число может быть представлено как int";
							return;
						}

					}
					cout << "Число не может быть представлено как int";
				}
				else
				{
					cout << "Число может быть представлено как int";
					return;
				}
			}
			else
			{
				if (len > 8)
				{
					cout << "Число не может быть представлено как int";
					return;
				}
				else if (len == 8 && l[0] > 55)
				{
					cout << "Число не может быть представлено как int";
					return;
				}
				else
				{
					cout << "Число может быть представлено как int";
					return;
				}
			}
		}
	}
	Line16& operator+ (Line16& l)
	{
		int* n1, * n2, i, j;
		char* line1 = get_line(), * line2 = l.get_line();
		n1 = new int[get_length()];
		n2 = new int[l.get_length()];
		if (line1[0] == 43 || line1[0] == 45)
		{
			for (i = 1, j = 0; i < get_length() + 1; i++, j++)
			{
				if (line1[i] >= 48 && line1[i] <= 57)
				{
					n1[j] = line1[i] - 48;
				}
				else if (line1[i] >= 65 && line1[i] <= 70)
				{
					n1[j] = line1[i] - 55;
				}
				else
				{
					n1[j] = line1[i] - 87;
				}
			}
		}
		else
		{
			for (j = 0; j < get_length() + 1; j++)
			{
				if (line1[j] >= 48 && line1[j] <= 57)
				{
					n1[j] = line1[j] - 48;
				}
				else if (line1[j] >= 65 && line1[j] <= 70)
				{
					n1[j] = line1[j] - 55;
				}
				else
				{
					n1[j] = line1[j] - 87;
				}
			}
		}
		if (line2[0] == 43 || line2[0] == 45)
		{
			for (i = 1, j = 0; i < l.get_length() + 1; i++, j++)
			{
				if (line2[i] >= 48 && line2[i] <= 57)
				{
					n2[j] = line2[i] - 48;
				}
				else if (line2[i] >= 65 && line2[i] <= 70)
				{
					n2[j] = line2[i] - 55;
				}
				else
				{
					n2[j] = line2[i] - 87;
				}
			}
		}
		else
		{
			for (j = 0; j < l.get_length() + 1; j++)
			{
				if (line2[j] >= 48 && line2[j] <= 57)
				{
					n2[j] = line2[j] - 48;
				}
				else if (line2[j] >= 65 && line2[j] <= 70)
				{
					n2[j] = line2[j] - 55;
				}
				else
				{
					n2[j] = line2[j] - 87;
				}
			}
		}
		if (line1[0] == 45)
		{
			if (line2[0] == 43 || line2[0]!=43 && line2[0]!=45)
			{
				if (get_length() < l.get_length())
				{
					for (i = get_length() - 1, j = l.get_length() - 1; i >= 0; i--, j--)
					{
						n2[j] -= n1[i];
						if (n2[j] < 0)
						{
							n2[j - 1] -= 1;
							n2[j] += 15;
						}
					}
					cout << "Сумма равна: +";
					for (i = 0; i < l.get_length(); i++)
					{
						char k = 55;
						if (n2[i] <= 9) cout << n2[i];
						else
						{
							k += n2[i];
							cout << k;
							k = 55;
						}
					}
					return *this;

				}
				else if (get_length() > l.get_length())
				{
					for (i = get_length() - 1, j = l.get_length() - 1; j >= 0; i--, j--)
					{
						n1[i] -= n2[j];
						if ( n1[i] < 0)
						{
							n1[i - 1] -= 1;
							n1[i] += 15;
						}
					}
					cout << "Сумма равна: -";
					for (i = 0; i < get_length(); i++)
					{
						char k = 55;
						if (n1[i] <= 9) cout << n1[i];
						else
						{
							k += n1[i];
							cout << k;
							k = 55;
						}
					}
					return *this;
				}
				else
				{
					int flag = 0;
					for (i = 0; i < get_length() + 1; i++)
					{
						if (n1[i] > n2[i])
						{
							break;
						}
						else if(n1[i] < n2[i])
						{
							flag = 1;
							break;
						}
					}
					if (i != get_length())
					{
						if (flag == 0)
						{
							cout << "Сумма равна: -";
							for (i = get_length() - 1; i >= 0; i--)
							{
								n1[i] -= n2[i];
								if (n1[i] < 0)
								{
									n1[i] += 15;
									n1[i - 1] -= 1;
								}
							}
							for (i = 0; i < get_length(); i++)
							{
								char k = 55;
								if (n1[i] <= 9) cout << n1[i];
								else
								{
									k += n1[i];
									cout << k;
									k = 55;
								}
							}
							return *this;
						}
						else
						{
							cout << "Сумма равна: +";
							for (i = get_length() - 1; i >= 0; i--)
							{
								n2[i] -= n1[i];
								if (n2[i] < 0)
								{
									n2[i] += 15;
									n2[i - 1] -= 1;
								}
							}
							for (i = 0; i < get_length(); i++)
							{
								char k = 55;
								if (n2[i] <= 9) cout << n2[i];
								else
								{
									k += n2[i];
									cout << k;
									k = 55;
								}
							}
							return *this;
						}
					}
					else cout << "Сумма равна: 0";

				}
			}
			else
			{
				if (get_length() < l.get_length())
				{
					for (i = get_length() - 1, j = l.get_length() - 1; i >= 0; i--,j--)
					{
						n2[j] += n1[i];
						if (n2[j] > 15)
						{
							n2[j] -= 15;
							n2[j - 1] += 1;
						}
					}
					cout << "Сумма равна: -";
					if (n2[0] > 15)
					{
						cout << "1";
						n2[0] -= 15;
					}
					for (i = 0; i < l.get_length(); i++)
					{
						char k = 55;
						if (n2[i] <= 9) cout << n2[i];
						else
						{
							k += n2[i];
							cout << k;
							k = 55;
						}
					}
					return *this;
				}
				else if (get_length() > l.get_length())
				{
					for (i = get_length() - 1, j = l.get_length() - 1; j >= 0; j--, i--)
					{
						n1[i] += n2[j];
						if (n1[i] > 15)
						{
							n1[i] -= 15;
							n1[i - 1] += 1;
						}
					}
					cout << "Сумма равна: -";
					if (n1[0] > 15)
					{
						cout << "1";
						n1[0] -= 15;
					}
					for (i = 0; i < get_length(); i++)
					{
						char k = 55;
						if (n1[i] <= 9) cout << n1[i];
						else
						{
							k += n1[i];
							cout << k;
							k = 55;
						}
					}
					return *this;
				}
				else
				{
					for (i = get_length() - 1; i >= 0; i--)
					{
						n1[i] += n2[i];
						if (n1[i] > 15 && i!=0)
						{
							n1[i] -= 15;
							n1[i - 1] += 1;
						}
					}
					cout << "Сумма равна: -";
					if (n1[0] > 15)
					{
						cout << "1";
						n1[0] -= 15;
					}
					for (i = 0; i < get_length(); i++)
					{
						char k = 55;
						if (n1[i] <= 9) cout << n1[i];
						else
						{
							k += n1[i];
							cout << k;
							k = 55;
						}
					}
					return *this;
				}
			}
		}
		else if (line1[0] == 43 || line1[0] != 43 && line1[0] != 45)
		{
		if (line2[0] == 43 || line2[0] != 43 && line2[0] != 45)
			{
			  if (get_length() < l.get_length())
			  {
				for (i = get_length() - 1, j = l.get_length() - 1; i >= 0; i--, j--)
				{
					n2[j] += n1[i];
					if (n2[j] > 15)
					{
						n2[j] -= 15;
						n2[j - 1] += 1;
					}
				}
				cout << "Сумма равна: +";
				if (n2[0] > 15)
				{
					cout << "1";
					n2[0] -= 15;
				}
				for (i = 0; i < l.get_length(); i++)
				{
					char k = 55;
					if (n2[i] <= 9) cout << n2[i];
					else
					{
						k += n2[i];
						cout << k;
						k = 55;
					}
				}
				return *this;
			  }
			  else if (get_length() > l.get_length())
			  {
				for (i = get_length() - 1, j = l.get_length() - 1; j >= 0; j--, i--)
				{
					n1[i] += n2[j];
					if (n1[i] > 15)
					{
						n1[i] -= 15;
						n1[i - 1] += 1;
					}
				}
				cout << "Сумма равна: +";
				if (n1[0] > 15)
				{
					cout << "1";
					n1[0] -= 15;
				}
				for (i = 0; i < get_length(); i++)
				{
					char k = 55;
					if (n1[i] <= 9) cout << n1[i];
					else
					{
						k += n1[i];
						cout << k;
						k = 55;
					}
				}
				return *this;
			  }
			  else
			  {
				for (i = get_length() - 1; i >= 0; i--)
				{
					n1[i] += n2[i];
					if (n1[i] > 15 && i != 0)
					{
						n1[i] -= 15;
						n1[i - 1] += 1;
					}
				}
				cout << "Сумма равна: +";
				if (n1[0] > 15)
				{
					cout << "1";
					n1[0] -= 15;
				}
				for (i = 0; i < get_length(); i++)
				{
					char k = 55;
					if (n1[i] <= 9) cout << n1[i];
					else
					{
						k += n1[i];
						cout << k;
						k = 55;
					}
				}
				return *this;
			  }
			}
			else 
			{
			if (get_length() < l.get_length())
			{
				for (i = get_length() - 1, j = l.get_length() - 1; i >= 0; i--, j--)
				{
					n2[j] -= n1[i];
					if (n2[j] < 0)
					{
						n2[j - 1] -= 1;
						n2[j] += 15;
					}
				}
				cout << "Сумма равна: -";
				for (i = 0; i < l.get_length(); i++)
				{
					char k = 55;
					if (n2[i] <= 9) cout << n2[i];
					else
					{
						k += n2[i];
						cout << k;
						k = 55;
					}
				}
				return *this;

			}
			else if (get_length() > l.get_length())
			{
				for (i = get_length() - 1, j = l.get_length() - 1; j >= 0; i--, j--)
				{
					n1[i] -= n2[j];
					if (n1[i] < 0)
					{
						n1[i - 1] -= 1;
						n1[i] += 15;
					}
				}
				cout << "Сумма равна: +";
				for (i = 0; i < get_length(); i++)
				{
					char k = 55;
					if (n1[i] <= 9) cout << n1[i];
					else
					{
						k += n1[i];
						cout << k;
						k = 55;
					}
				}
				return *this;
			}
			else
			{
				int flag = 0;
				for (i = 0; i < get_length() + 1; i++)
				{
					if (n1[i] > n2[i])
					{
						break;
					}
					else if (n1[i] < n2[i])
					{
						flag = 1;
						break;
					}
				}
				if (i != get_length())
				{
					if (flag == 0)
					{
						cout << "Сумма равна: +";
						for (i = get_length() - 1; i >= 0; i--)
						{
							n1[i] -= n2[i];
							if (n1[i] < 0)
							{
								n1[i] += 15;
								n1[i - 1] -= 1;
							}
						}
						for (i = 0; i < get_length(); i++)
						{
							char k = 55;
							if (n1[i] <= 9) cout << n1[i];
							else
							{
								k += n1[i];
								cout << k;
								k = 55;
							}
						}
						return *this;
					}
					else
					{
						cout << "Сумма равна: -";
						for (i = get_length() - 1; i >= 0; i--)
						{
							n2[i] -= n1[i];
							if (n2[i] < 0)
							{
								n2[i] += 15;
								n2[i - 1] -= 1;
							}
						}
						for (i = 0; i < get_length(); i++)
						{
							char k = 55;
							if (n2[i] <= 9) cout << n2[i];
							else
							{
								k += n2[i];
								cout << k;
								k = 55;
							}
						}
						return *this;
					}
				}
				else cout << "Сумма равна: 0";

			}
			}
		}
	}
};
