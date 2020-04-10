#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
string name = "\0";
name = "beyonce.txt";
ifstream oldFile(name);
string str;
string str1;
string s;
int min=1000;

if (!oldFile)
exit(-1);

ofstream newFile("(11)" + name);

if (!newFile)
exit(-2);

//getline(oldFile, str);
//min=str.length();

//string();

//string str;
//string s;

while (!oldFile.eof()) {

getline(oldFile, str);
//cout << str << endl;

if (str.length()<min && str!="") {
min=str.length();
s = str;
//cout << s << endl;
//newFile << s << " - this is the shortest string" << endl;
}
                       }


cout << s << endl;
newFile << s << " - this is the shortest string" << endl; 

//while (!oldFile.eof()) {

//getline(oldFile, str1); 
//if (str1!=s) {
//newFile << str1 << endl;
//}
 //                     }


}

