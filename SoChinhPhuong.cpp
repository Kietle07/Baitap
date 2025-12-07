#include<iostream>
#include<conio.h>
using namespace std;
int main() {
	int n;
	cout << "Nhap vao so co ba chu so:";
	cin >> n;
	if (n > 999 || n < 100) {
		cout << "So vua nhap khong hop le.";
		return -1;
	}
	int a, b, c, tong;
	a = n / 100;
	b = (n / 10) % 10;
	c = n % 10;
	tong = a + b + c;
	cout <<"Nhap vao so a: "<< a << endl;
	cout <<"Nhap vao so b: "<< b << endl;
	cout <<"Nhap vao so c: "<< c << endl;
	cout <<"Tong cac so a, b, c: "<< tong << endl;
	//vet can
	cout << "So chinh phuong: ";
	for (int i = 1; i <=3; i++) {
		if (i * i == a) cout<< a<<", ";
		if (i * i ==b) cout << b << ", ";
		if (i * i == c) cout << c;
	}
	//sqrt(n)*sqrt(n)=n
	int t = _getch();
	return 0;
}