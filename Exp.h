#include<stdlib.h.>
#include<time.h.>
#include <vector> 
#include <string>                                                                       //Для string
#include <iostream>                                                                     //Для cout
#include <sstream>                                                                      //Для ostringstream и функции hex
#include <fstream>                                                                      //Для файлов

using namespace std;                                                                    //Для cout, hex и файлов

class Exp {
	string x; //сообщение x
	//int n = 6; //количество взятых с начала бит, учитывая что один символ - это 4 бита
	string y0; //ноль последовательности

	vector <string> y; //вектор последовательности

	
	void take_bits(string a, string b); //берёт первые n бит из строки
	bool write_file();

	

public:	
	string random_string(); // создаёт рандомную строку длиной 15
	void exp_finish(); //
	int count1;//сложность второго прообраза
	int kol;
	int collis();
	int n=2; //количество взятых с начала бит, учитывая что один символ - это 8 бита
	int average(vector<int> a);
	bool f;
	int S_dif[5]; //массив средних сложностей для разных бит
	int S_col[5]; //массив средних коллизий для разных бит
	vector <int> s_dif; //вектор для нахождениея всех сложностей
	vector <int> s_col; //вектор ждя нахождения всех коллизий 
	int a;//переменная для временного хранения S_dif
	int b;//переменная для временного хранения S_col
};


