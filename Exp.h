#include<stdlib.h.>
#include<time.h.>
#include <vector> 
#include <string>                                                                       //��� string
#include <iostream>                                                                     //��� cout
#include <sstream>                                                                      //��� ostringstream � ������� hex
#include <fstream>                                                                      //��� ������

using namespace std;                                                                    //��� cout, hex � ������

class Exp {
	string x; //��������� x
	//int n = 6; //���������� ������ � ������ ���, �������� ��� ���� ������ - ��� 4 ����
	string y0; //���� ������������������

	vector <string> y; //������ ������������������

	
	void take_bits(string a, string b); //���� ������ n ��� �� ������
	bool write_file();

	

public:	
	string random_string(); // ������ ��������� ������ ������ 15
	void exp_finish(); //
	int count1;//��������� ������� ���������
	int kol;
	int collis();
	int n=2; //���������� ������ � ������ ���, �������� ��� ���� ������ - ��� 8 ����
	int average(vector<int> a);
	bool f;
	int S_dif[5]; //������ ������� ���������� ��� ������ ���
	int S_col[5]; //������ ������� �������� ��� ������ ���
	vector <int> s_dif; //������ ��� ����������� ���� ����������
	vector <int> s_col; //������ ��� ���������� ���� �������� 
	int a;//���������� ��� ���������� �������� S_dif
	int b;//���������� ��� ���������� �������� S_col
};


