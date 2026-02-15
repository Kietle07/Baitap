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

void Swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y=temp;

}

void ShakerSort(int a[], int n)
{
    int left = 0;
    int right = n - 1;
    int k = right;
    while (left < right)
        for (int i=right;i>left;i--)
            if (a[i - 1] > a[i])
            {
                Swap(a[i - 1], a[i]);
                k = i;
            }
    left = k;
    for (int j = left; j < right - 1; j++)
        if (a[j] > a[j + 1])
        {
            Swap(a[j], a[j - 1]);
            k = j;  
        }
    right = k;
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





//#include <iostream>
//#include <algorithm>  // để dùng std::swap nếu muốn
//using namespace std;
//
//#define MAX 50
//
//void NhapMang(int a[], int& n) {
//    for (int i = 0; i < n; i++) {
//        cout << "a[" << i << "] = ";
//        cin >> a[i];
//    }
//}
//
//void InMang(int a[], int n) {
//    for (int i = 0; i < n; i++) {
//        cout << a[i];
//        if (i < n - 1) cout << "|";
//    }
//    if (n > 0) cout << endl;
//}
//
//void Swap(int& x, int& y) {
//    int temp = x;
//    x = y;
//    y = temp;
//}
//
//void ShakerSort(int a[], int n) {
//    int left = 0, right = n - 1, k = 0;
//    bool swapped = true;
//    while (swapped&& left < right) {
//        swapped = false;
//        for (int i = left; i < right; i++) {
//            if (a[i] > a[i + 1]) {
//                Swap(a[i], a[i + 1]);
//                swapped = true;
//                k = i;
//            }
//        }
//        right = k;
//        if (!swapped) break;
//        swapped = false;
//        for (int i = right; i > left; i--) {
//            if (a[i - 1] > a[i]) {
//                Swap(a[i - 1], a[i]);
//                swapped = true;
//                k = i;
//            }
//        }
//        left = k;
//    }
//}
//
//int main() {
//    int mang[MAX];
//    int spt;
//    cout << "Nhap so luong phan tu: ";
//    cin >> spt;
//    NhapMang(mang, spt);
//    cout << "Mang truoc khi sap xep: ";
//    InMang(mang, spt);
//    ShakerSort(mang, spt);
//    cout << "Mang sau khi sap xep: ";
//    InMang(mang, spt);
//    return 0;
//}