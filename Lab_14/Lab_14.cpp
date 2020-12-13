/*
1. Дана строка, состоящая из слов, разделенных одним или несколькими пробелами. Посчитать количество слов в строке.
2. Удалить из строки все вхождения заданного символа.
3. Вставить в строку другую строку после первого вхождения заданного символа.
4. Дана строка, состоящая из слов, разделенных одним или несколькими пробелами. Заменить в строке каждое четное слово на заданное.
*/

#include <iostream>
#include <string>

using namespace std;

int count_words(string s)
{
	// Функция вычисления количества слов в строке <s>

	int count = 0;
	bool wrd = false;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == ' ' && wrd) {
			wrd = false;
			++count;
		}
		else if (s[i] != ' ' && !wrd)
			wrd = true;
	}
	if (wrd)
		return ++count;
	else
		return count;
}


void delete_char(string &str, string ch)
{
	// Функция удаляет из <str> все вхождения символа <ch>

	size_t pos;
	pos = str.find(ch);
	while (pos != string::npos) {
		str.erase(pos, 1);
		pos = str.find(ch);
	}

	return;
}


void insert_substr(string &str, string ch, string substr)
{
	// Функция вставляет в строку другую строку после первого вхождения заданного символа
	
	size_t pos;
	pos = str.find(ch);
	if (pos == string::npos) throw - 1;
	str.insert(pos + 1, substr);

	return;
}


void change_str(string& str, string substr)
{
	// Функция заменяет в строке каждое четное слово на заданное

	bool checkpoint{ false };
	int count = 0, beg, end;
	bool wrd = false;

	for (int i = 0; i < str.length() + 1; ++i) {
		if ((str[i] == ' ' || str[i] == '\0') && wrd) {

			if (checkpoint) {
				str.replace(beg, i - beg, substr);
				i += substr.length() - (i - beg);
				checkpoint = false;
				wrd = false;
				continue;
			}
			checkpoint = !checkpoint;
			wrd = false;
		}
		else if (str[i] != ' ' && !wrd) {
			wrd = true;
			beg = i;
		}
	}

	return;
}


int main()
{
	setlocale(LC_ALL, "RUS");

	string s;
	string ch;
	string subs;

	// # 1
	cout << "Введите строку: ";
	getline(cin, s);
	cout << s << '\n';
	cout << "Количесво слов — " << count_words(s) << '\n';

	// # 2
	cout << "Введите символ: ";
	getline(cin, ch);
	delete_char(s, ch);
	cout << s << '\n';

	// # 3
	cout << "Введите символ: ";
	getline(cin, ch);
	cout << "Введите подстроку — ";
	getline(cin, subs);
	try
	{
		insert_substr(s, ch, subs);
		cout << "Result: " << s << '\n';
	}
	catch (int)
	{
		cout << "Ошибка: символ отстутствует в строке\n";
	}
	
	// # 4
	s = "I couldn't find the English ones. ";
	cout << "Введите подстроку — ";
	getline(cin, subs);
	change_str(s, subs);
	cout << "Result: " << s << '\n';

	cout << "Программа успешно выполнена!";
	//system("pause");
	return 0;
}
