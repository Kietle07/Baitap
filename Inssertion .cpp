#include<iostream>
#include<conio.h>
#define MAX 50
using namespace std;
void NhapMang(int a[], int& n) {
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void InMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i < n - 1) cout << "|";
    }
    if (n > 0) cout << endl;
}
void InsertionSort(int a[], int n)
{
    int x, j;
    for (int i = 1; i < n - 1; i++)
    {
        x = a[i];
        j = i - 1;
        while (j >= 0 && x < a[j])
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = x;
    }
}

int main() {
    int mang[MAX];
    int spt;
    cout << "Nhap so luong phan tu: ";
    cin >> spt;
    NhapMang(mang, spt);
    cout << "Mang truoc khi sap xep: ";
    InMang(mang, spt);
    InsertionSort(mang, spt);
    cout << "Mang sau khi sap xep: ";
    InMang(mang, spt);
    return 0;
}