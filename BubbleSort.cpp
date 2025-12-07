
#include<iostream>
#include<conio.h>
#define MAX 50 
using namespace std;
void NhapMang(int a[], int& n) {
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
}
void InMang(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
	{
		cout << a[i] << "|";
	}
	if(n>0){//thiếu điều kiện này sai cả bài đmm
		cout << a[n - 1] << endl;
	}
}
void Swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++) 
		for (int j = n - 1; j > i; j--)
			if (a[j] < a[j - 1])
				Swap(a[j], a[j - 1]);
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
	BubbleSort(mang, spt);
	cout << "Mang sau khi sap xep: ";
	InMang(mang, spt);
	int t = _getch();
	return 0;
}