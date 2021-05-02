#include "Exp.h" 
#include "RIPEMD-160.h" 
#include <bitset>

string Exp::random_string()
{
    string charset =  "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string  str;
    

    for (int i = 0; i < 15; i++) {
       
        int num = rand() % 62;
        str.push_back(charset[num]);
    }
    return str;
}



void Exp::take_bits(string a, string b)
{
    b = a.substr(0, n - 1);
}

bool Exp::write_file()                                     //Запись в файл
{
   // ofstream out("count1.txt");                                                                 //Открываем или создаем файл
    //ofstream out("count2.txt");
   //ofstream out("count3.txt");
  // ofstream out("count4.txt");
    ofstream out("count5.txt", ios::app);

    if (out.fail())                                                                         //Вернуть 0
        return false;                                                                       //Если возникла ошибка

    for(int i=0; i<= count1; i++)
    out << y.at(i) << '\n';                                                                             //Записываем строку с результатом в файл


    out.close();

    return true;                                                                            //Возвращаем 1 в случае успеха
}

///нахождение среднего арифметического
int Exp::average(vector<int>a) {
    int res = 0;
    for (int i = 0; i < a.size(); i++)res = res + a.at(i);
    res = res / a.size();
    return res;
}

//поиск коллизий
int Exp::collis() {
    string s;
    kol = 0;
    bool flag = false;
    for (int i = 0; (i < y.size())&&(flag!=true); i++) {
        s = y.at(i);
        for (int j = i+1; (j < y.size())&&(flag != true); j++) {
            if (s == y.at(j)) flag = true;
            kol++;
        }
    }
    if (flag == false)kol = 0;
    y.clear();
    return kol;
}

void Exp::exp_finish()
{
    RIPEMD_160 x_mess;

    if (!x_mess.read_file("x_mess.txt"))cout << "Error!" << endl << endl;

    x.resize(x_mess.ripemd_160().size()); //меняем размер сообщения
    x = x_mess.ripemd_160(); //получили хеш сообщения x

    y0=x.substr(0,n);
    count1 = 0;
    
   
    int flag = 0;
        for (int i = 0; flag < 1; i++) {
            RIPEMD_160* hash3 = new RIPEMD_160();
            string a;
            (*hash3).message = random_string();
            a = (*hash3).ripemd_160().substr(0, n);//внутри а находиться первые n бит хеш
            y.push_back(a);
            if (y0 == a)flag++;
            else count1++;
            delete hash3;
           // a.clear();
        }
        s_dif.push_back(count1);
        count1 = 0;
        s_col.push_back(collis());
        y.clear();
}
