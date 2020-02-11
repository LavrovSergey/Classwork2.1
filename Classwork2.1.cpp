#define _CRT_SECURE_NO_WARNINGS
#include <direct.h>
#include <conio.h>
#include <fstream>
#include <stdio.h>
#include "windows.h"
#include <iostream>
using namespace std;
int menu();
struct word {
	char eng[50];
	char ukr[50];
};
void fill() {
	system("cls");
	word wordd;
	int count = 0;
	cout << "Сколько слов будет в вашем словаре" << endl;
	cin >> count;
	ofstream words("words.txt",ios::binary);
	while (count != 0) {
		cout << "Eng: ";
		cin.ignore(); cin.getline(wordd.eng, 50);
		cout << "Ukr: ";
		cin.ignore(0); cin.getline(wordd.ukr, 50); 
		words.write((char*)& wordd, sizeof(word));
		count--;
	}
	words.close();
	
}
void create() {
	system("cls");
	ifstream words("words.txt");
	word wordd;
    _mkdir("C:\\Users\\sereg\\OneDrive\\Рабочий стол\\Classwork2.1\\Dictionary");
	_chdir("C:\\Users\\sereg\\OneDrive\\Рабочий стол\\Classwork2.1\\Dictionary");
	while (words.read((char*)& wordd, sizeof(word))) {
		ofstream f(strcat(wordd.eng, ".txt"), ios::binary);
		f << wordd.ukr;
		f.close(); cout << "Хопа\n";
	}
	words.close();
}
void translate() {
	system("cls");
	word wordd;
	char slovo[50];
	char slovou[50] = {};
	 cin.getline(slovo, 50); 
	_chdir("C:\\Users\\sereg\\OneDrive\\Рабочий стол\\Classwork2.1\\Dictionary");
	ifstream f(strcat(slovo, ".txt"));
	f.read((char*)& slovou, strlen(slovo)-3);
	cout << slovou;
	f.close();
	
}
int menu()
{
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 4) % 4;
		if (key == 0) cout << "-> Заполнить словарь" << endl;
		else  cout << "   Заполнить словарь" << endl;
		if (key == 1) cout << "-> Создать словарь" << endl;
		else  cout << "   Создать словарь" << endl;
		if (key == 2) cout << "-> Проверить словарь" << endl;
		else  cout << "   Проверить словарь" << endl;
		if (key == 3) cout << "-> Exit" << endl;
		else  cout << "   Exit" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}
int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int answer = 0;
	answer = menu();
	switch (answer)
	{
	case 0:fill(); break;
	case 1:create(); break;
	case 2:translate(); break;
	case 3: system("cls"); cout << "Goodbye!\n__________________";
	}
	return 0;
}
