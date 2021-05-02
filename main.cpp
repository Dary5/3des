#include "RIPEMD-160.h"
#include "Exp.h"

using namespace std;
int main(int argc, char** argv)
{
       RIPEMD_160 hash;

        if (!hash.read_file("in.txt")) cout << "Ошибка чтения файла!" << endl << endl;
        else if (!hash.write_file((char*)"out.txt", hash.ripemd_160()))
            cout << "Ошибка записи файла!" << endl << endl;
    
     

    ofstream out_preimage("preim.txt");
    ofstream out_collis("collis.txt");
    out_preimage << "0 0" << endl;
    out_collis << "0 0" << endl;
    unsigned seed = time(0);
    srand(seed);
        //провести эксперимент
       Exp e1;
      
       e1.n = 2;
       out_preimage << "8 ";
       out_collis << "8 ";
       ///нахождение среднего
       for (int i = 0; i < 1000; i++) {
           e1.exp_finish();
       }
       e1.S_dif[0] = e1.average(e1.s_dif);
       e1.S_col[0] = e1.average(e1.s_col);
       e1.s_dif.clear();
       e1.s_col.clear();
       cout << "1)complexity of the second preimage: " << e1.S_dif[0] << endl;
       cout << "1)complexity of collision: " << e1.S_col[0] << endl;
       out_preimage << e1.S_dif[0] << endl;
       out_collis << e1.S_col[0] << endl;

       e1.n = 3;
       out_preimage << "12 ";
       out_collis << "12 ";
       ///нахождение среднего
       for (int i = 0; i < 1000; i++) {
           e1.exp_finish();
       }
       e1.S_dif[1] = e1.average(e1.s_dif);
       e1.S_col[1] = e1.average(e1.s_col);
       e1.s_dif.clear();
       e1.s_col.clear();
       cout << "2)complexity of the second preimage: " << e1.S_dif[1] << endl;
       cout << "2)complexity of collision: " << e1.S_col[1] << endl;
       out_preimage << e1.S_dif[1] << endl;
       out_collis << e1.S_col[1] << endl;

       e1.n = 4;
       out_preimage << "16 ";
       out_collis << "16 ";
       ///нахождение среднего
       for (int i = 0; i < 1000; i++) {
           e1.exp_finish();
       }
       e1.S_dif[2] = e1.average(e1.s_dif);
       e1.S_col[2] = e1.average(e1.s_col);
       e1.s_dif.clear();
       e1.s_col.clear();
       cout << "3)complexity of the second preimage: " << e1.S_dif[2] << endl;
       cout << "3)complexity of collision: " << e1.S_col[2] << endl;
       out_preimage << e1.S_dif[2] << endl;
       out_collis << e1.S_col[2] << endl;


       e1.n = 5;
       ///нахождение среднего
       for (int i = 0; i < 500; i++) {
           e1.exp_finish();
       }
       e1.S_dif[3] = e1.average(e1.s_dif);
       e1.S_col[3] = e1.average(e1.s_col);
       e1.s_dif.clear();
       e1.s_col.clear();
       cout << "4)complexity of the second preimage: " << e1.S_dif[3] << endl;
       cout << "4)complexity of collision: " << e1.S_col[3] << endl;
       out_preimage << e1.S_dif[3] << endl;
       out_collis << e1.S_col[3] << endl;
        
     
    return 0;
}