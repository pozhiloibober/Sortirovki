// Sortirovki.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <fstream>
#include <iostream>
#include <string>
#include<ctime>
#include <windows.h>
#define maxTime 10000

using namespace std;

void quickSort(int* mas, int size) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;
    //Центральный элемент массива
    int mid = mas[size / 2];
    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while (mas[i] < mid) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while (mas[j] > mid) {
            j--;
        }
        //Меняем элементы местами
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    //Рекурсивные вызовы, если осталось, что сортировать
    if (j > 0) {
        //"Левый кусок"
        quickSort(mas, j + 1);
    }
    if (i < size) {
        quickSort(&mas[i], size - i);  //"Првый кусок"
    }
}
        
void selectionSort(int* a, int size) //выбором
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_ind = i;
        for (int j = i; j < size; j++)
        {
            if (a[j] < a[min_ind])
            {
                min_ind = j;
            }

        }
        if (i != min_ind)
        {
            int temp = 0;
            temp = a[i];
            a[i] = a[min_ind];
            a[min_ind] = temp;
        }
    }
}

void insertSort(int* a, int size) // вставками
{
    for (int i = 1; i < size; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            a[j] = key;
            j--;
        }
    }
}
void merge(int[], int[], int, int[], int);
void mergeSort(int data[], int lenD) //слиянием
{
    if (lenD > 1) {
        int middle = lenD / 2;
        int rem = lenD - middle;
        int* L = new int[middle];
        int* R = new int[rem];
        for (int i = 0; i < lenD; i++) {
            if (i < middle) {
                L[i] = data[i];
            }
            else {
                R[i - middle] = data[i];
            }
        }
        mergeSort(L, middle);
        mergeSort(R, rem);
        merge(data, L, middle, R, rem);
    }
}
void merge(int merged[], int L[], int lenL, int R[], int lenR) {
    int i = 0;
    int j = 0;
    while (i < lenL || j < lenR) {
        if (i < lenL && j < lenR) {
            if (L[i] <= R[j]) {
                merged[i + j] = L[i];
                i++;
            }
            else {
                merged[i + j] = R[j];
                j++;
            }
        }
        else if (i < lenL) {
            merged[i + j] = L[i];
            i++;
        }
        else if (j < lenR) {
            merged[i + j] = R[j];
            j++;
        }
    }
}
void shakerSort(int* arr, int size)
{
    int leftMark = 1;
    int rightMark = size - 1;
    while (leftMark <= rightMark)
    {
        for (int i = rightMark; i >= leftMark; i--)
            if (arr[i - 1] > arr[i]) {
                int temp = 0;
                temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
        leftMark++;

        for (int i = leftMark; i <= rightMark; i++)
            if (arr[i - 1] > arr[i]) {
                int temp = 0;
                temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
        rightMark--;
    }
}
void bubbleSort(int data[], int lenD)//пузырьковая 
{
    int tmp = 0;
    for (int i = 0; i < lenD; i++)
    {
        for (int j = (lenD - 1); j >= (i + 1); j--)
        {
            if (data[j] < data[j - 1])
            {
                tmp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = tmp;
            }
        }
    }
}

void gnomeSort(int* A, int N) {
    int i = 0; int tmp = 0;
    while (i < N) {
        if (i == 0 || A[i - 1] <= A[i])
            ++i;
        else {
            tmp = A[i];
            A[i] = A[i - 1];
            A[i - 1] = tmp;
            --i;
        }
    }
}


void randomFill(int* a, int _size)
{
	for (int i = 0; i < _size; i++)
	{
		a[i] = rand();
	}
}

void durSortToFile(int time1, int time2, int time3, int time4, int time5, int time6, int time7, int _size) {
    ofstream fout;
    string path = "Sorttime.txt";
    fout.open(path, ofstream::app);
    
    fout << _size << "\t" << time1 << "\t" << time2 << "\t" << time3 << "\t" << time4 << "\t" << time5 << "\t" << time6 << "\t" << time7 << "\n";
    fout.close();
}
void nextSize(int& _size) {
    if (1000 <= _size && _size < 10000)
        _size += 1000;
    if (10000 <= _size && _size < 100000)
        _size += 10000;
    if (100000 <= _size && _size < 1000000)
        _size += 100000;
    if (1000000 <= _size)
        _size += 1000000;
}

int main()
{
    ofstream fout;
    fout.open("Sorttime.txt");
    
    int* my_array;
    int time = 0, time1 = 0, time2 = 0, time3 = 0, time4 = 0, time5 = 0, time6 = 0, time7 = 0;
    for (int size = 1000; size <= 10000000;) {
        my_array = new int[size];
        if (time1 < maxTime)
        {
            randomFill(my_array, size);
            time = GetTickCount();
            bubbleSort(my_array, size);
            time1 = GetTickCount() - time;
        }

        if (time2 < maxTime)
        {
            randomFill(my_array, size);
            time = GetTickCount();
            quickSort(my_array, size);
            time2 = GetTickCount() - time;
        }

        if (time3 < maxTime)
        {
            randomFill(my_array, size);
            time = GetTickCount();
            selectionSort(my_array, size);
            time3 = GetTickCount() - time;
        }

        if (time4 < maxTime)
        {
            randomFill(my_array, size);
            time = GetTickCount();
            insertSort(my_array, size);
            time4 = GetTickCount() - time;
        }

        if (time5 < maxTime)
        {
            randomFill(my_array, size);
            time = GetTickCount();
            mergeSort(my_array, size);
            time5 = GetTickCount() - time;
        }

        if (time6 < maxTime)
        {
            randomFill(my_array, size);
            time = GetTickCount();
            shakerSort(my_array, size);
            time6 = GetTickCount() - time;
        }

        if (time7 < maxTime)
        {
            randomFill(my_array, size);
            time = GetTickCount();
            gnomeSort(my_array, size);
            time7 = GetTickCount() - time;
        }

        durSortToFile(time1, time2, time3, time4, time5, time6, time7, size);
        nextSize(size);
        delete[] my_array;
    }
    return 0;

}
