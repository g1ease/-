#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;
#include "Load1111.cpp"

int main()
{
	setlocale(LC_ALL, "rus");
	int meniu;
	//			system("cls");
				cout << "   МЕНЮ:\n";
				cout << "0 : Завершить работу\n";
				cout << "1 : Продать препарат\n";
				cout << "2 : Принять новый препарат\n";
				cout << "3 : Упорядочить по названию\n";
				cout << "4 : Загрузить данные\n";
				cout << "5 : Сохранить данные\n";
				cout << "6 : Вывести данные\n";
				cout << "7 : Вывести данные о сумме в кассе\n";
				cout << "8 : Очистить кассу\n";
				cout << ">";
cin >> meniu;
//cout << meniu;



	while (1)
	{
		if (0 <= meniu && meniu <= 8)
		{
			if (meniu == 1)
			{

Load testLoad;
testLoad.del();
}

			if (meniu == 2)
			{
Load testLoad;
testLoad.add();
}

			if (meniu == 4)
			{		
Load testLoad;
testLoad.load1();
}
			if (meniu == 5)
			{
Load testLoad;
testLoad.save();
}

			if (meniu == 6)
			{
Load testLoad;
testLoad.print();
}
                	if (meniu == 7)
{
Load testLoad;
testLoad.print1();
}
			if (meniu == 8)
			{

Load testLoad;
testLoad.del1();
}
			if (meniu == 0)
			{
				break;

			}
		}
		
                        if (meniu < 0 || meniu >8)
		{
			cout << "ERROR! \n\n";
		}
				cout << "   МЕНЮ:\n";
				cout << "0 : Завершить работу\n";
				cout << "1 : Продать препарат\n";
				cout << "2 : Принять новый препарат\n";
				cout << "3 : Упорядочить по названию\n";
				cout << "4 : Загрузить данные\n";
				cout << "5 : Сохранить данные\n";
				cout << "6 : Вывести данные\n";
				cout << "7 : Вывести данные о сумме в кассе\n";
				cout << "8 : Очистить кассу\n";
				cout << ">";
		cin >> meniu;
	}
	system("pause");
	return 0;
}; 
//};

