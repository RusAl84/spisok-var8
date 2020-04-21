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
void input_item(char cc);              // функция ввода элемента списка
void print_spis();              // печать всего списка
void add_item(char, char);         // функация добавления элемента в список 1 аргумент
								// перед каким добавляем 2-ой что добавляем
Spis* find_item(char);    // поиск элемента списка по его значению возвращает адрес 
void del_item(char);             // функция удаления элемента списка по его значению
int main()
{
    
    //Найти символ число по символу, введенному с клавиатуры, и после него добавить новый символ в виде элемента в списке.
	SetConsoleCP(1251);      // подключаем русский язык 
	SetConsoleOutputCP(1251);// на вывод и ввод
	// счетчик элементов списка -1 элем-тов нет
input_item('f');
input_item('u');
input_item('s');
input_item('m');
print_spis();
cout << "----------------\n";
del_item('s');
print_spis();
}

void input_item(char cc)
{
	pCurrent = new Spis;
	//cout << endl << "введите значение элемента:";
	//cin >> pCurrent->c;
	pCurrent->c = cc;
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

void add_item(char value3, char value2)
{
	Spis* pAdd, * pFind;
	pFind = find_item(value3);//находим адрес искомого элемента
	std::cout << "----------------\n";
	std::cout << pFind;
	if (pFind == nullptr) return;//если искомого нет то вываливаемся
	pAdd = new Spis;  // создаем новый элемент списка
	
	pAdd->c = value2;
	count0 += 1;// увеличиваем счетчик элементов и получаем новый id
	pAdd->id = count0;
	// заполнение полей
	// берем у найденного элемента(pFind) из поля предыдущий элемент(previous_item)
	// его адрес, и по этому адресу вытаскиваем из поле следующего элемента(previous_item)
	// адрес и заносим его в  поле (next)следующего добавляемого элемента по адресу pAdd
	pAdd->next_item = pFind->previous_item->next_item;
	// меняем на адрес pAdd поле next_item в 
	//элементе pFind->previous_item
	pFind->previous_item->next_item = pAdd;
	// берем у найденного элемента(pFind) значение поля previous_item
	// и прописываем его в поле previous_item добавляемого элемента(pAdd)
	pAdd->previous_item = pFind->previous_item;
	// заменяем поле previous_item элемента pFind на значение pAdd
	pFind->previous_item = pAdd;
}

Spis* find_item(char value)
{
	int d=0;
	int flag = 0;
	pCurrent = pStart;
	for (int i = 0; i <= count0; i++)
	{
		if (pCurrent->c == value) // совпадают ли значения
		{
			flag = 1;
			//cout << pCurrent->previous_item << " : " << pCurrent->id << " : " <<
			//	pCurrent->c << " : " << pCurrent->next_item << endl;
			//cout << "искать далее?(1/0)"; cin >> d;
			if (d == 0) return pCurrent;//возвращаем указатель найденного элемента
			pCurrent = pCurrent->next_item; flag = 0;
		}
		else
			pCurrent = pCurrent->next_item;
	}
	if (!flag) {
		cout << "элемента с зачением=" << value << " нет в списке" << endl;
		return NULL;
	}
}

void del_item(char c) {
	int flag = 0;
	pCurrent = pStart;
	for (int i = 0; i <= count0; i++)
	{
		if (pCurrent->c == c)
		{
			flag = 1;
			// берем в найденном элементе адрес предыдущего и в поле следующего
			// предыдущего элемента записываем значение следующего из найденного
			pCurrent->previous_item->next_item = pCurrent->next_item;

			//берем в найденном элементе адрес последующего и в поле предыдущего
			// следущего элемента записываем значение предыдущего из найденного
			pCurrent->next_item->previous_item = pCurrent->previous_item;
			delete pCurrent;
			count0 -= 1;
			return;
		}
		else
			pCurrent = pCurrent->next_item;
	}
	if (!flag) cout << "элемента с id=" << c << " нет в списке" << endl;

}