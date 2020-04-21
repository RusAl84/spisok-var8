// spisok-var8a.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;

struct Spis
{
	Spis* previous_item; //место для хранения адреса предыдущего элемента
	Spis* next_item;     // место для хранения адреса последующего элемента
	char c;               // значение элемента
	int id;              // идентификатор элемента списка создается автом начиная с 0
};

Spis* pStart,            // пер-ная. для хра-ния адреса начала списка 
* pEnd,              // пер-ная. для хра-ния адреса последнего эл-та 
* pCurrent,          // пер-ная. для хра-ния адреса текущего эл-та списка
* pTemp,             // пер-ная. для хра-ния промежуточного адреса эл-та списка
* pPrev;             // пер-ная. для хра-ния предыдущего адреса эл-та списка
int count0 = -1;
void input_item();              // функция ввода элемента списка
void print_spis();              // печать всего списка
int main()
{
    std::cout << "Hello World!\n";
    //Найти символ число по символу, введенному с клавиатуры, и после него добавить новый символ в виде элемента в списке.
	SetConsoleCP(1251);      // подключаем русский язык 
	SetConsoleOutputCP(1251);// на вывод и ввод
	// счетчик элементов списка -1 элем-тов нет
input_item();
}

void input_item()
{
	pCurrent = new Spis;
	cout << endl << "введите значение элемента:";
	cin >> pCurrent->c;
	if (count0 == -1) //не создавали ни одного элемента списка
	{
		count0 += 1;
		pCurrent->id = count0;
		pStart = pCurrent; // запомнили адрес начала списка
		pEnd = pCurrent;   // запомнили адрес последнего элемента списка
		pCurrent->previous_item = pCurrent;//  для 0-го элемента адрес предыдущего эл-та
		pCurrent->next_item = pCurrent;    // совпадает с адресом последующего эл-та
		pTemp = pCurrent;                  // запомнили тек. адрес, потребуется при вводе 
											// следующего эл-та		
	}
	else
	{
		count0 += 1;
		pCurrent->id = count0;
		pEnd = pCurrent;       // запомнили адрес последнего элемента списка
		pCurrent->previous_item = pTemp;// запомнили в текущем адрес предыдущего эл-та
		pCurrent->next_item = pTemp->next_item;// в поле след. текущего переписали
											   // след. из предыщего
		//cin >> pCurrent->d;
		pStart->previous_item = pEnd;
		pTemp->next_item = pCurrent;
		pTemp = pCurrent;            // запомнили тек. адрес, потребуется при вводе 
											// следующего эл-та
	}
}

void print_spis()
{
	if (count0 < 0) {
		cout << "элементов в списке нет" << endl;
		system("pause"); return;
	}
	pCurrent = pStart;
	cout << pStart << endl;
	for (int i = 0; i <= count0; i++)
	{
		cout << pCurrent->previous_item << " : " << pCurrent->id << " : " <<
			pCurrent->c << " : " << pCurrent->next_item << endl;
		pCurrent = pCurrent->next_item;
	}
	cout << pEnd << endl;
}