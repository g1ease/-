#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
string name = "\0";
name = "text6.txt";
ifstream oldFile(name);

if (!oldFile)
exit(-1);
ofstream newFile("(1)" + name);

if (!newFile)
exit(-2);
getline(oldFile, str);

int min=str.length();

while (!oldFile.eof()) {
string str;
string s;
getline(oldFile, str);
cout « str «endl;

if (str.length()<min) {
min=str.str.length();
s=str;}

}

cout « s « endl;
newFile « s «" - this is the shortest string"« endl; 
