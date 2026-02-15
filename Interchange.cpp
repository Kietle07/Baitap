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
void Interchange(int a[], int n)
{
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
            }
        }
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
    Interchange(mang, spt);
    cout << "Mang sau khi sap xep: ";
    InMang(mang, spt);
    return 0;
}