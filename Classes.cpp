#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Line // класс строка
{
private:
	int length;
	char* line;
protected:
	void set_length(int length)
	{
		this->length = length;
	}
	void set_line(char* line)
	{
		if (line == NULL)
		{
			cout << "Строка имеет NULL, создана пустая строка" << endl;
			line = new char;
			line[0] = '\0';
		}
		else this->line = line;
	}
	char* get_line()
	{
		return line;
	}
public:
	~Line()
	{
		delete line;
		cout << "Сработал деструктор класса Line\n";
	}
	Line()
	{
		set_length(0);
		line = new char;
		line[0] = '\0';
		cout << "Сработал конструктор без параметров класса Line\n";
	}
	Line(char* Line)
	{
		delete line;
		line = new char[strlen(Line) + 1];
		length = strlen(Line);
		strcpy_s(line, strlen(Line) + 1, Line);
		cout << "Сработал конструктор с параметрами класса Line 22\n";
	}
	Line(char Line)
	{
		length = 1;
		line = new char;
		line[0] = Line;
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
	Line& operator= (Line& line1)
	{
		delete line;
		line = new char[strlen(line1.line) + 1];
		strcpy_s(line, strlen(line1.line) + 1, line1.line);
		length = line1.length;
		return *this;
	}
	ostream& operator<<(ostream& out) {
		if (*line != '\0')
			if (length == 1)
				out << *line;
			else out << line;
		else
			cout << "Строка пуста";
		return out;
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
		string line = string(Line);
		string id_words[82] = { "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor", "bool", "break", "case", "catch",
"char", "char16_t", "char32_t", "class", "compl", "const", "constexpr", "const_cast", "continue", "decltypedefault", "delete", "do", "double", "dynamic_cast",
"else", "enum", "explicit", "export", "extern", "false", "float", "for", "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace", "new", "noexcept", "not", "not_eq", "nullptr",  "operator",
"or", "or_eq", "private", "protected", "public", "register", "reinterpret_cast", "return", "short", "signed", "sizeof", "static", "static_assert", "static_cast", "struct", "switch", "template",
"this", "thread_local", "throw", "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using", "virtual", "void", "volatile", "wchar_t", "whilexor", "xor_eq" };
		for (int j = 0; j < 82; j++)
		{
			if (line == id_words[j])
			{
				cout << "Строка является зарезервированным словом, создана пустая строка\n";
				return;
			}
		}
		if (isdigit(Line[i]) || strlen(Line) == 0 || !(isalpha(Line[i]) || Line[i] == '_'))
		{
			cout << "Создана пустая строка\n";
			return;
		}
		else i++;
		while (i < strlen(Line) && (isalpha(Line[i]) || isdigit(Line[i]) || Line[i] == '_'))
			i++;
		if (i != strlen(Line))
		{
			cout << "Создана пустая строка\n";
			return;
		}
		delete get_line();
		LineIden = new char[strlen(Line) + 1];
		strcpy_s(LineIden, strlen(Line) + 1, Line);
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
		delete get_line();
		LineIden = new char[strlen(Id.get_line()) + 1];
		strcpy_s(LineIden, strlen(Id.get_line()) + 1, Id.get_line());
		set_length(strlen(Id.get_line()));
		set_line(LineIden);
	}
	LineId& operator+ (LineId& Id)
	{
		char* lin;
		if (get_line()[0] == '\0')
		{
			if (Id.get_line()[0] != '\0')
			{
				delete get_line();
				lin = new char[strlen(Id.get_line()) + 1];
				strcpy_s(lin, strlen(Id.get_line()) + 1, Id.get_line());
				set_line(lin);
				return *this;
			}
			else {
				cout << "Обе строки пустые, сумма невозможна\n"; return *this;
			}

		}
		else if (Id.get_line()[0] == '\0')
		{
			cout << "Вторая строка пустая\n"; return *this;
		}
		lin = new char[strlen(this->get_line()) + strlen(Id.get_line()) + 1];
		strcpy_s(lin, strlen(this->get_line()) + 1, get_line());
		strcat_s(lin, strlen(this->get_line()) + strlen(Id.get_line()) + 1, Id.get_line());
		delete this->get_line();
		this->set_line(lin);
		this->set_length(strlen(get_line()));
		cout << endl << get_line() << endl;
		return *this;

	}
	void Up_Id()
	{
		char* LineIden = get_line();
		for (int i = 0; i < get_length(); i++)
		{
			if (LineIden[i] >= 'a' && LineIden[i] <= 'z')
			{
				LineIden[i] -= 32;
			}
		}
		cout << LineIden << endl;
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
		int j = 0;
		char* line16;
		if (!(l[0] == '-' || l[0] == '+' || l[0] >= '0' && l[0] <= '9' || l[0] >= 'a' && l[0] <= 'f' || l[0] >= 'A' && l[0] <= 'F'))
		{
			delete get_line();
			line16 = new char;
			line16[0] = '0';
			set_line(line16);
			set_length(1);
			cout << "Сработал конструктор с параметрами класса Line16 1\n";
			return;
		}
		else { j++; }
		for (int i = 1; i < strlen(l); i++)
		{
			if (l[i] >= '0' && l[i] <= '9' || l[i] >= 'a' && l[i] <= 'f' || l[i] >= 'A' && l[i] <= 'F')
			{
				j++;
			}
		}
		if (j == strlen(l))
		{
			delete get_line();
			line16 = new char[strlen(l) + 1];
			strcpy_s(line16, strlen(l) + 1, l);
			set_line(line16);
			set_length(j);
			cout << "Сработал конструктор с параметрами класса Line16 2\n";
		}
		else
		{
			line16 = new char;
			*line16 = '0';
			set_line(line16);
			set_length(1);
			cout << "Сработал конструктор с параметрами класса Line16 3\n";
			return;
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
	Line16& operator= (Line16& line)
	{
		char* Line;
		delete get_line();
		Line = new char[strlen(line.get_line()) + 1];
		strcpy_s(Line, strlen(line.get_line()) + 1, line.get_line());
		set_length(strlen(line.get_line()));
		set_line(Line);
	}
	bool may_int()
	{
		char* l = get_line();
		int len = get_length();
		if (l[0] == '+')
		{
			len -= 1;
			if (len > 8)  return false;
			if (len == 8 && l[1] > '7') return false;
			else return true;
		}
		else if (l[0] == '-')
		{
			len -= 1;
			if (len > 8)  return false;
			else if (len == 8 && l[1] > '7')
			{
				if (l[1] == '8')
				{
					bool flag;
					for (int i = 2; i < len + 1; i++)
					{
						if (l[i] == '0')
						{
							flag = 1;
						}
						else
						{
							flag = 0; break;
						}
					}
					if (flag == 0) 	return false;
					else return true;

				}
				else return false;
			}
			else return true;
		}
		else
		{
			if (len > 8) return false;
			else if (len == 8 && l[0] > '7') return false;
			else return true;
		}
	}
	Line16& operator+ (Line16& l)
	{
		int  i, j;
		bool flag=1;
		vector<int> n1, n2;
		char* line1 = get_line(), *line2 = l.get_line();
		char_to_int_vector(n1);
		l.char_to_int_vector(n2);
		if (((line1[0] == '+' || line1[0] != '-') && (line2[0]=='+' || line2[0]!='-')) || (line1[0] == '-' && line2[0]=='-'))
		{
			line1[0] == '-' ? flag=1 : flag=0;
			if (n1.size() >= n2.size())
			{
				for (i = n1.size()-1, j = n2.size()-1; j >= 0; j--, i--)
				{
					n1[i] += n2[j];
					if (n1[i] >= 16)
					{
						n1[i] -= 16;
						n1[i - 1] += 1;
					}
				}
				answer_output(n1, n1.size(),flag);
			}
			else
			{
				for (i = n1.size() - 1, j = n2.size() - 1; i >= 0; j--, i--)
				{
					n2[j] += n1[i];
					if (n2[j] >= 16)
					{
						n2[j] -= 16;
						n2[j - 1] += 1;
					}
				}
				l.answer_output(n2, n2.size(),flag);
			}
			return *this;
		}
		else
		{
			if (n1.size() > n2.size())
			{
				for (i = n1.size() - 1, j = n2.size() - 1; j >= 0; j--, i--)
				{
					n1[i] -= n2[j];
					if (n1[i] < 0)
					{
						n1[i] += 16;
						n1[i - 1] -= 1;
					}
				}
				line1[0] == '-' ? answer_output(n1, n1.size(), flag) : answer_output(n1, n1.size(), 0);
			}
			else if (n1.size() < n2.size())
			{
				for (i = n1.size() - 1, j = n2.size() - 1; i >= 0; j--, i--)
				{
					n2[j] -= n1[i];
					if (n2[j] < 0)
					{
						n2[j] += 16;
						n2[j - 1] -= 1;
					}
				}
				line2[0] == '-' ? l.answer_output(n2, n2.size(), flag) : l.answer_output(n2, n2.size(), 0);
			}
			else
			{
				if (n1 > n2)
				{
					for (i = n1.size()-1; i >= 0; i--)
					{
						n1[i] -= n2[i];
						if (n1[i] < 0)
						{
							n1[i] += 16;
							n1[i - 1] -= 1;
						}
				    }
				   line1[0] == '-' ? answer_output(n1, n1.size(), flag) : answer_output(n1, n1.size(), 0);
				}
				else if (n1 < n2)
				{
					for (i = n1.size()-1; i >= 0; i--)
					{
						n2[i] -= n1[i];
						if (n2[i] < 0)
						{
							n2[i] += 16;
							n2[i - 1] -= 1;
						}
					}
					line2[0] == '-' ? l.answer_output(n2, n2.size(), flag) : l.answer_output(n2, n2.size(), 0);
				}
				else cout << "Сумма равна нулю";
			}
			return *this;
		}
	}
	void char_to_int_vector(vector<int> &n2)
	{
		vector<int> n1;
		int i, j, len1 = get_length();
		char* line1 = get_line();
		if (line1[0] == '-' || line1[0] == '+')
		{
			len1 -= 1;
			n1.resize(len1);
			for (i = 1, j = 0; j < len1; i++, j++)
			{
				if (line1[i] >= '0' && line1[i] <= '9')  n1[j] = line1[i] - 48;
				else if (line1[i] >= 'A' && line1[i] <= 'F') n1[j] = line1[i] - 55;
				else n1[j] = line1[i] - 87;
			}
		}
		else
		{
			n1.resize(len1);
			for (j = 0; j < len1; j++)
			{
				if (line1[j] >= '0' && line1[j] <= '9') n1[j] = line1[j] - 48;
				else if (line1[j] >= 'A' && line1[j] <= 'F') n1[j] = line1[j] - 55;
				else n1[j] = line1[j] - 87;
			}
		}
		n2.swap(n1);
	}
	void answer_output(vector<int> n, int j,bool flag)
	{
		int k, i=0;
		flag == 1 ? cout << "Сумма равна: -" : cout << "Сумма равна: +";
		if (n[0] > 16)
		{
			cout << '1';
			n[0] -= 16;
		}
		else if (n[0] == 0) i++;
		for (; i < j; i++)
		{
			char k = 55;
			if (n[i] <= 9) cout << n[i];
			else
			{
				k += n[i];
				cout << k;
				k = 55;
			}
		}
	}
};
