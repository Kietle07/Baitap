#include<iostream>
#include<conio.h>
#include <algorithm>
#define MAX 50
using namespace std;

void NhapMang(int a[], int& n) {
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void InMang(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        cout << a[i] << "|";
    }
    if (n > 0) {  // Tránh lỗi nếu n=0
        cout << a[n - 1] << endl;
    }
}

void Swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;

}


void SelectionSort(int a[], int n)
{
    int min;
    for (int i = 0; i < n; i++)  
        for (int j = i; j < n; j++)
        {

        }
}
int main()
{
    int mang[MAX];
    int spt;
    cout << "Nhap so luong phan tu: ";
    cin >> spt;
    NhapMang(mang, spt);
    cout << "Mang truoc khi sap xep: ";
    InMang(mang, spt);
    ShakerSort(mang, spt);
    cout << "Mang sau khi sap xep: ";
    InMang(mang, spt);
    int t = _getch();
    return 0;
}

