#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <ctime>  
#define MAX 30
using namespace std;

void Nhapmang(int a[], int& n) { 
    cout << "Nhap so phan tu cua mang:";
    cin >> n;
    for (int i = 0; i < n; i++)
        a[i] = rand() % 50;
}

void Xuatmang(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        cout << a[i] << "|";
    if (n > 0)  
        cout << a[n - 1];
}

int LinearSearch(int a[], int n, int x) {
    int i = 0;
    while (i < n) {
        if (a[i] == x)
            return i;
        i++;
    }
    return -1;
}

int main() {
    srand(time(NULL));
    int mang[MAX], spt, x;
    Nhapmang(mang, spt);
    cout << "Mang cua ban la:";
    Xuatmang(mang, spt);
    cout << "\nNhap gia tri can tim:";  
    cin >> x;
    int vt = LinearSearch(mang, spt, x);
    if (vt != -1)
        cout << "Co gia tri " << x << " Tai vi tri so " << vt;
    else
        cout << "Khong co gia tri " << x << " trong mang!";  
    int t = _getch();
    return 0;
}