#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

int main()
{
setlocale(LC_ALL, "Russian");
int balanceOpen=0;
int balanceClose = 0;
char fileName[255];
char buffer;
cout « "Введите имя файла" « endl;
cin » fileName;
ofstream fout("output.txt",ios_base::app);//запись в конец файла
ifstream fin(fileName);

if (!fin.is_open())
{
cout « "This file can not be opened!";
fout « "This file can not be opened!";
}
else
{
fin » buffer;
while (fin)
{


if (buffer == '{')
{
balanceOpen++;
}
else
if (buffer == '}')
{
balanceClose++;
}
fin » buffer;
}
fin.close();

if (balanceOpen < balanceClose)
{
cout « "Баланс скобок нарушен! Закрывающих скобок больше на " « balanceClose - balanceOpen « endl;
fout « "Баланс скобок нарушен! Закрывающих скобок больше на " « balanceClose - balanceOpen « endl;
}
else if (balanceOpen > balanceClose)
{
cout « "Баланс скобок нарушен! Открывающих скобок больше на " « balanceOpen - balanceClose « endl;
fout « "Баланс скобок нарушен! Открывающих скобок больше на " « balanceOpen - balanceClose « endl;
}
else if (balanceOpen == balanceClose && balanceOpen != 0)
{
cout « "Баланс не скобок нарушен!" « endl;
fout « "Баланс не скобок нарушен!" « endl;
}
else
{
cout « "В файле нет фигурных скобок" « endl;
fout « "В файле нет фигурных скобок" « endl;
}
}
fout.close();

_getch();
return 0;
}
