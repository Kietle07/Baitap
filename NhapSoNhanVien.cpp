#include <iostream>
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
    for (int i = 0; i < n - 1; i++) {
        cout << a[i] << "|";
    }
    if (n > 0) {  // Tránh lỗi nếu n=0
        cout << a[n - 1] << endl;
    }
}

void Swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

void BubbleSort(int a[], int n) {  
    bool swapped;
    for (int i = 0; i < n - 1; i++) {  // Sửa vòng lặp ngoài thành n-1 để tối ưu
        swapped = false;
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                Swap(a[j], a[j - 1]);
                swapped = true;
            }
        }
        if (!swapped) break;  // Tối ưu: Dừng nếu không còn swap
    }
}

int main() {
    int mang[MAX], spt;
    cout << "Nhap so luong phan tu: ";
    cin >> spt;
    if (spt > MAX || spt <= 0) {
        cout << "So luong phan tu khong hop le (phai >0 va <= " << MAX << ")!" << endl;
        return 1;  // Thoát chương trình với lỗi
    }
    NhapMang(mang, spt);
    cout << "Mang truoc khi sap xep: ";
    InMang(mang, spt);
    BubbleSort(mang, spt);
    cout << "Mang sau khi sap xep: ";
    InMang(mang, spt);
    int t = _getch();
    return 0;
}