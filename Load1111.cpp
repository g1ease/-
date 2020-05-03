#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;
//#include "Load1111.h"
class Load 
{
private: 
    int i; int l; int m; int z=6;
    char namefile[32];
int summa=100;
int Number=6;
int size=9;
int *Menkd = new int[6];
int *Menkl = new int[6];
char* *Mennm = new char*[6];
int *Ments = new int[6];

public: 




                         void load1() {  
cout <<"Введите имя файла: \n";
    cin >> namefile;
ifstream f(namefile); 


  f >> Number;
  for (i = 0; i < Number; i ++)
    f >> Menkd[i] >> Mennm[i] >> Menkl[i] >> Ments[i];

     f.close(); }



                           void print() {  
int i;

  cout << " N  Код                 Название            Количество             Цена (р.)\n";
  for (i = 0; i < Number; i ++)
    cout << i + 1 <<"   "<< Menkd[i] << "          "<< Mennm[i] << "          "<< Menkl[i] << "          "<< Ments[i] << "\n";
}


                           void del1() {  
 summa=0;
  cout << "Касса пуста.\n\n";
}

                           void print1() {  
cout << "В кассе: " << summa << " рублей.\n\n";
}



                           void save() {  
    cout <<"Введите имя файла: \n";
    cin >> namefile;
  fstream f; 
    f.open(namefile, ios::out);

  f << Number << "\n";
  for (i = 0; i < Number; i ++) {
    f << Menkd[i] << Mennm[i] << Menkl[i] << Ments[i] << "\n"; }

    f.close();
}


                           void add() {    
  int Check;
int i,l;
int e=0;
int v;

 
  cout << "Введите код добавляемого препарата > ";
  cin >> l;
  if (l % 1000 != 0 && l < 111)
  {
    cout <<  "Введите корректный код препарата.\n \n";
    return;
  }

  for (i= 0; i < Number ; i ++){
 if (Menkd[i] == l){
     Menkl[i] = Menkl[i] + 1;
     e=1;}}

if(e==0){
Number+=1;
z+=1;
Menkd = (int*)realloc(Menkd, Number * sizeof(int));
Menkl = (int*)realloc(Menkl, Number * sizeof(int));
Mennm = (char**)realloc(Mennm, Number * sizeof(int));
Ments = (int*)realloc(Ments, Number * sizeof(int)); 


Menkd[z]= l;
Menkl[z] =  1;
  cout << "Введите название препарата > ";
  cin >>  Mennm[z];
  cout << "Введите цену препарата > ";
  cin >> Ments[z];
}

cout << "Препарат добавлен.\n\n";
}



                           void del() {    
int i,m;

  cout << "Введите код продаваемого препарата > ";
  cin >> m;
  if (m % 1000 != 0 && m < 111)
  {
    cout << stderr, "Введите корректный код препарата.\n \n";
    return;
  

  for (i= 0; i < Number ; i ++){
 if (Menkd[i]== m){
     Menkl[i] = Menkl[i] - 1;
     summa+= Ments[i];
     cout << "Препарат продан.\n\n"; }}; }
}
};
     /*   int main(){
void del() ;
void add() ;
void save();
void print1() ;
void del1();
void print() ;
void load() ; } */

