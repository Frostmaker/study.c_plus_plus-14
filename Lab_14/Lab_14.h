#pragma once
#include <string>

/*
�� ������ ���������� ����� � ���������.
���� ��������� ��� ����� �������� ����� ������� � ������� �����.
*/

using namespace std;

int count_words(string s);
void delete_char(string& str, string ch);
void insert_substr(string& str, string ch, string substr);
void change_str(string& str, string substr);