#include <iostream>
#include <Windows.h>
#include "Set.h"

using namespace std;

Set makeSet()
{
	Set s;
	s.Init();
	return s;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "=== 1. Демонстрація базового класу BitString ===\n";
	BitString bs1, bs2; 
	bs1.Init(0, 15); // Молодшці 4 біти встановлені (1111)
	bs2.Init(0, 7); // Молодшці 3 біти встановлені (0111)


	cout << "bs1: "; bs1.Display();
	cout << "bs2: "; bs2.Display();

	BitString bsAnd = bs1.And(bs2);
	cout << "bs1 and bs2: "; bsAnd.Display();

	BitString bsShift = bs1.ShiftLeft(33);
	cout << "bs 1 ShiftLeft(33): "; bsShift.Display();
	 

	cout << "\n 2. Демонстрація класу-контейнера Set (композиція) === \n";
	Set A = makeSet();
	A.Include(1);
	A.Include(5);
	A.Include(10);
	A.Include(40);
	cout << "Множина А: "; A.Display();

	Set B = makeSet();
	B.Include(5);
	B.Include(10);
	B.Include(50);
	cout << "Множина В: "; B.Display();


	Set A_union_B = A.Union(B);
	cout << "Об'єднання (А U B): "; A_union_B.Display();

	Set A_intersect_B = A.Intersection(B);
	cout << "Перетин (А ∩ B): "; A_intersect_B.Display();

	Set A_diff_B = A.Difference(B);
	cout << "Різниця (A \\ B): "; A_diff_B.Display();

	cout << "\n== 3. Демонстація покажчика на об'єкт (->) ===\n";
	Set* ptrSet = new Set();
	ptrSet->Init();
	ptrSet->Include(2);
	ptrSet->Include(22);
	ptrSet->Include(62);
	cout << "Множина через покажчик: "; ptrSet->Display();
	ptrSet->Exclude(22);
	cout << "Після Exclude(22): "; ptrSet->Display();
	delete ptrSet;

	cout << "\n=== 4. Демонстрація динамічного масиву об'єктів ===\n";
	int n = 2;
	Set* arr = new Set[n];
	arr[0].Init();
	arr[0].Include(7);
	arr[1].Init();
	arr[1].Include(14);
	arr[1].Include(21);

	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "] = ";
		arr[i].Display();
	}
	delete[] arr;

	cout << "\n=== 5. Інтеркативне введення множини ===\n";
	Set userSet;
	userSet.Read();
	cout << "Введена множина: "; userSet.Display();

	return 0;
}