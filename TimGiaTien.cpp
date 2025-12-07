#include<iostream>
#include<conio.h>
using namespace std;
int main() {
	int n, a, b, c, d, e, f;
	cout << "Nhap vao 1 so nguyen duong n>1000: ";
	cin >> n;
	if (n < 1000) {
		cout << "Khong hop le";
		do {
			cout << "Vui long nhap lai: ";
			cin >> n;
		} while (n < 1000);
	}
	else {
		cout << "Hop le.";
	}
	a = n / 150;
	b = (n % 150) / 100;
	c = (n % 150 % 100) / 50;
	d = (n % 150 % 100 % 50) / 10;
	e = (n % 150 % 100 % 50 % 10) / 5;
	f = (n % 150 % 100 % 50 % 10 % 5) / 1;
	cout << "\nSo nguyen ban vua nhap la: ";
	cout << "\nSo tien menh gia 150 la:" << a;
	cout << "\nSo tien menh gia 100 la: " << b;
	cout << "\nSo tien menh gia 50 la:" << c;
	cout << "\nSo tien menh gia 10 la:" << d;
	cout << "\nSo tien menh gia 5 la:" << e;
	cout << "\nSo tien menh gia 1 la:" << f;
	int t = _getch();
	return 0;
}