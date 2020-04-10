#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
string name = "\0";
char fileName1[255];
char fileName2[255];
cout << "Введите имя файла для чтения:" << endl;
cin >> fileName1;
cout << "Введите имя файла для записи:" << endl;
cin >> fileName2;
ifstream oldFile(fileName1);
string str;
string str1;
string s;
int min=1000;

if (!oldFile)
exit(-1);

ofstream newFile(fileName2);

if (!newFile)
exit(-2);


while (!oldFile.eof()) {

getline(oldFile, str);

if (str.length()<min && str!="") {
min=str.length();
s = str;
}
                       }


cout << s << " - это самая короткая строка в файле" << endl;
newFile << s << " - это самая короткая строка в файле" << endl; 

}

