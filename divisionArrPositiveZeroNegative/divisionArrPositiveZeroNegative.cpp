//Завдання 3. Написати функцію, яка отримує покажчик  на статичний масив і його розмір.Функція розподіляє
//додатні, від’ємні та нульові елементи в окремі динамічні масиви
#include <iostream>
#include <Windows.h>// підключення заголовного файлу Windows.h, завдяки чому зможемо використовувати українську мову
#include <ctime>//використовуємо дану бібліотеку для рандомного заповнення масивів
using namespace std;
void inputArr(int* arr, int size);// створюємо функцію для заповнення масиву
void printArr(const int* arr, const int size);// створюємо функцію для виведення елементів масиву
void printArrNew(const int* arr, const int newsize);// створюємо функцію для виведення елементів масиву
void divisionArr(int* arr, int size, int* posArr, int& posCount, int* zeroArr, int& zeroCount, int* negArr, int& negCount);// створюємо функцію для розподілу елементів масиву на додатні, від’ємні та число 0
int main()
{
    srand(time(NULL));//завдяки даній функції, рандомні числа будуть постійно змінюватись 
    SetConsoleCP(1251); // встановлення кодування Windows-1251 в  потік введення
    SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в  потік виведення
    int size = 0;//оголошуємо розмірність масиву size
    int posCount = 0; //оголошуємо розмірність масиву 
    int zeroCount = 0; //оголошуємо розмірність масиву
    int negCount = 0; //оголошуємо розмірність масиву
    cout << "Введіть розмір   size  елементів  масиву" << endl;
    cin >> size;
    int* arr = new int[size];//оголошуємо вказівник  arr 
    int* posArr = new int[posCount]; // оголошуємо вказівник  posArr 
    int* zeroArr = new int[zeroCount]; // оголошуємо вказівник  zeroArr 
    int* negArr = new int[negCount]; // оголошуємо вказівник  negArr 
    inputArr(arr, size);//звертаємось до функції inputArr
    cout << "Елементи  масиву" << endl;
    printArr(arr, size);//звертаємось до функції printArr
    cout << endl;
    divisionArr(arr, size, posArr, posCount, zeroArr, zeroCount, negArr, negCount); // звертаємось до функції розподілу елементів масиву на додатні, від’ємні та число 0
    cout << "Позитивні елементи окремого масиву  " << endl;
    printArr(posArr, posCount);//звертаємось до функції printArr - для виведення позитивних елементи окремого масиву  
    cout << "Числа 0 окремого масиву  " << endl;
    printArr(zeroArr, zeroCount);//звертаємось до функції printArr - для виведення чисела 0 окремого масиву  
    cout << "Негативні елементи окремого масиву  " << endl;
    printArr(negArr, negCount);//звертаємось до функції printArr - для виведення негативних елементи окремого масиву  
    delete[]arr;//видаляємо вміст масиву
    delete[]posArr; //видаляємо вміст масиву
    delete[]zeroArr; //видаляємо вміст масиву
    delete[]negArr; //видаляємо вміст масиву
}
void inputArr(int* arr, int size) {//створюємо функцію для заповнення масиву
    for (int i = 0; i < size; i++)//використовуємо цикл для заповнення масиву
    {
        arr[i] = rand() % 50 - 20;//рандомно заповнюєм масив цілими числами
    }
}
void printArr(const int* arr, const int size) {// створюємо функцію для виведення елементів масиву
    for (int i = 0; i < size; i++)//використовуємо цикл для виведення елементів масиву
    {
        cout << "arr[" << i << "]=" << " " << arr[i] << endl;//виводимо елементи масиву
    }
}
void printArrNew(const int* arr, const int newsize) {//створюємо функцію для виведення елементів масиву
    for (int i = 0; i < newsize; i++)//використовуємо цикл для виведення елементів масиву
    {
        cout << "arr[" << i << "]=" << " " << arr[i] << endl;//виводимо елементи масиву
    }
}
void divisionArr(int* arr, int size, int* posArr, int& posCount, int* zeroArr, int& zeroCount, int* negArr, int& negCount) {//створюємо функцію для розподілу елементів масиву на додатні, від’ємні та число 0
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0) {//якщо елементи  масиву менші 0, то
            posArr[posCount] = arr[i]; //розподіляємо їх в інший масив
            posCount++;
        }

        if (arr[i] == 0) {//якщо елементи  масиву рівні 0, то
            zeroArr[zeroCount] = arr[i];//розподіляємо їх в інший масив
            zeroCount++;//підраховуємо кількість елементів
        }
        if (arr[i] < 0) {//якщо елементи  масиву менші 0, то
            negArr[negCount] = arr[i]; //розподіляємо їх в інший масив
            negCount++;//підраховуємо кількість елементів
        }
    }
}
