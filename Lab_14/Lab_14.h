#pragma once
#include <string>

/*
Не сделал отдельного файла с функциями.
Было интересно как тесты работают через функции в главном файле.
*/

using namespace std;

int count_words(string s);
void delete_char(string& str, string ch);
void insert_substr(string& str, string ch, string substr);
void change_str(string& str, string substr);