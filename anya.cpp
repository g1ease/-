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
string s;
int min;
min=0;

if (!oldFile)
exit(-1);

ofstream newFile("(11)" + name);

if (!newFile)
exit(-2);

getline(oldFile, str);
min=str.length();

//string();

//string str;
//string s;
while (!oldFile.eof()) {

getline(oldFile, str);
//cout << str << endl;

if (str.length()<min) {
min=str.length();
s = str;
cout << s << endl;
newFile << s << " - this is the shortest string" << endl;
}
newFile << str << endl;

}


//cout << s << endl;
//newFile << s << " - this is the shortest string" << endl; 

}

