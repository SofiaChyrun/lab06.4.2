// ChyrunSofialab6.4.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Lab_06_4.cpp
// < Чирун Софія >
// Лабораторна робота № 6.4.2
// Опрацювання та впорядкування одновимірних динамічних масивів   
// Варіант 18

#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

void Create(double* a, int size, const double Low, const double High, int i)
{
	a[i] = rand() % (int)pow(10, 2);
	a[i] = Low + (a[i] / pow(10, 2)) * (High - Low);
	if (i < size - 1)
	   Create(a, size, Low, High, i + 1);
}

double Sum(double* mas, int size) 
{
    if (size < 0)
	   return 0;
	else
	   return round((mas[size] + Sum(mas, size - 1)) * 100) / 100;
}

void SumCriteria(double* mas, int size, double k, int i, int l, double s)
{
	if (mas[size] >= 0) 
	{
	   size -= 1;
	   SumCriteria(mas, size, k, i, l, s);
	}
	else 
	{
	   i = size;
	   k = size + 1;
	   if (i < l)
		  for (int j = i + 1; j < l; j++)
			  s += trunc(mas[j]);
	   if (k == 0)
		  for (int j = 0; j < l; j++)
			  s += trunc(mas[i]);
	   cout << "SumCount=" << s << endl;
	}
}

int Count(double* mas, int size, int C, int s) 
{
	if (size < 0)
	   return s;
	else
	{
	   if (mas[size] < C) 	s++;
       Count(mas, size - 1, C, s);
	}
	return Count(mas, size - 1, C, s);
}

void Print(double* a, int size, int i)
{
	cout << setw(7) << a[i];
	if (i < size - 1)
	   Print(a, size, i + 1);
	else
	   cout << endl;
}

int Max(double* a, int size, int i, double max, int l)
{
	if (a[i] > max) 
	{
	   max = a[i];
	   l = i;
	}
	if (i < size - 1)
	   return Max(a, size, i + 1, max, l);
	else
	{
	   cout << "max = " << max << endl;
	   return l + 1;
	}
}

void Sort(double* a, int size, int  i, int j)
{
	double l;
	if (a[i]<(a[0] + a[0] * 0.2) && a[i] > (a[0] - a[0] * 0.2))
	{
	   l = a[i];
	   a[i] = a[j];
	   a[j] = l;
	   j++;
	}
	if (i < size - 2) Sort(a, size, i + 1, j);
}

int main()
{
	srand((unsigned)time(NULL)); 
	int n, C; 
	cout << "n="; cin >> n; cout << endl;
	double* a = new double[n]; 
	double Low = -99;
	double High = 99;
	int imax;
	Create(a, n, Low, High, 0);
	Print(a, n, 0);
    cout << endl << "Sall = " << Sum(a, n) << endl;
	cout << "C="; cin >> C; cout << endl;
	cout << "Count=" << Count(a, n - 1, C, 0) << endl;
	int h = n;
	SumCriteria(a, n - 1, 0, 0, h, 0);
	imax = Max(a, n, 1, a[0], 0);
	cout << "iMax=" << imax << endl;
	double l;
	l = a[imax - 1];
	a[imax - 1] = a[0];
	a[0] = l;
	Sort(a, n, 1, 1);
	Print(a, n, 0);
	return 0;
}
