// Lab_7_2_1.cpp
// < прізвище, ім’я автора >
// Лабораторна робота № 7.2.1)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 0
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <time.h>

using namespace std;

//ІТЕРАЦІЙНИЙ СПОСІБ
void CreateMatrix(int** a, const int n, const int low, const int high);
void PrintMatrix(int** a, const int n);
int MaxMin(int** a, const int rowCount, const int colCount);

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n,
        low = -35, high = 45;

    cout << "Введіть розмір квадратної матриці: "; cin >> n;
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    cout << "ІТЕРАЦІЙНИЙ СПОСІБ" << endl;
    CreateMatrix(a, n, low, high); cout << endl;
    MaxMin(a, n, n); cout << endl;
    PrintMatrix(a, n); cout << endl;
    cout << "Максимальний елемент серед мінімальних елементів кожного рядка: " << MaxMin(a, n, n) << endl;


    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

//ІТЕРАЦІЙНИЙ СПОСІБ

void CreateMatrix(int** a, const int n, const int low, const int high)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = low + rand() % (high - low + 1);
}
void PrintMatrix(int** a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
}

int MaxMin(int** a, const int rowCount, const int colCount)
{
    int* min = new int[rowCount];
    for (int i = 0; i < rowCount; i++)
    {
        min[i] = a[i][0];
        for (int j = 1; j < colCount; j++)
            if (a[i][j] < min[i])
                min[i] = a[i][j];
    }
    int max = min[0];
    for (int i = 1; i < rowCount; i++)
        if (min[i] > max)
            max = min[i];
    delete[] min;
    return max;
}