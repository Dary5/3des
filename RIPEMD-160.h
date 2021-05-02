#include <string>                                                                       //��� string
#include <iostream>                                                                     //��� cout
#include <sstream>                                                                      //��� ostringstream � ������� hex
#include <fstream>                                                                      //��� ������

#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))                            //������� ����� �� n ���  

using namespace std;                                                                    //��� cout, hex � ������

class RIPEMD_160                                                                        //�����
{
                                                                         //�������� ���������

    unsigned long long bitlen;                                                          //�������� ����� ��������� (�� ���� 1) � �����

    unsigned int** X;                                                                   //������� ������ �� 64 �����(512 ���)

    unsigned int blocks;                                                                //���������� ������ ��� ���������

    unsigned int H0, H1, H2, H3, H4;                                                    //�������� RIPEMD ������

    unsigned int A1, B1, C1, D1, E1, A2, B2, C2, D2, E2, T;                             //���������� ��� ���������� �������� ��������� �� ����� ���������

    unsigned int F(unsigned int j, unsigned int x, unsigned int y, unsigned int z);     //����� ������� ������� � ����������� � ������� �����
    unsigned int K1(unsigned int j);                                                    //����� ��������� � ����������� � ������� ����� ��� ������� ������
    unsigned int K2(unsigned int j);                                                    //����� ��������� � ����������� � ������� ����� ��� ������� ������
    unsigned int inv(unsigned int value);                                               //����� ������� ��� (endians)
    unsigned int bytes_to_uint(char* bytes);                                            //������������� 4� ������ � unsigned int

    void extension();                                                                   //��� 1 - ���������� ���������
    void adding_length();                                                               //��� 2 - ���������� ����� ���������                                     
    void initialize_ripemd();                                                           //��� 3 - ������������� RIPEMD ������
    void message_processing();                                                          //��� 4 - ��������� ��������� � ������
    ostringstream result;                                                               //��� 5 - ��������� � ���� ���-���������
public:
    bool read_file(string fileName);                                                     //������ �� �����
    void get_new_mess(string s); //��� ������������
    bool write_file(char* fileName, string str);                                        //������ � ����

    string message;
    
    string ripemd_160();
    string random_string();
    string ripemd_160_exp(int flag);
    //�������� ��������������
    
};
