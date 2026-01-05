#include<iostream>
#include<conio.h>
#include<string>
#include<Windows.h>
#include<fstream>
#include<sstream>
#define MAX 5
using namespace std;
struct NhanVien
{
	char manv[6];
	char hoten[50];
	char phongban[40];
	float lcb, hsl, thuong, thuclanh;
};
int ReadData(string filename, NhanVien nv[], int& sl)
{
	fstream ifile(filename.c_str());
	if (!ifile.is_open())
	{
		cout << "Không có file hoặc bị lỗi";
		return 1;
	}
	string line; //đọc 1 dòng dữ liệu
	int i = 0;
	while (getline(ifile, line) && i < MAX) //đọc đủ số lượng
	{
		stringstream ss(line);
		ss.getline(nv[i].manv, 6, ','); //cin.getline(bien,cd): chuỗi
		ss.getline(nv[i].hoten, 50, ',');//cin>>số
		ss.getline(nv[i].phongban, 40, ',');
		ss >> nv[i].lcb;
		ss >> nv[i].hsl;
		ss >> nv[i].thuong;
		i++;
	}
	sl = i;
	return 0;
}
void InNV(NhanVien nv)
{
	cout << nv.manv << "\t";
	cout << nv.hoten << "\t";
	cout << nv.phongban << "\t";
	cout << nv.lcb << "  ";
	cout << nv.hsl << "  ";
	cout << nv.thuong << "  ";
	nv.thuclanh = nv.lcb * nv.hsl + nv.thuong;
	cout << nv.thuclanh;
}
void InDS(NhanVien ds[], int sl)
{
	system("cls"); //sử dụng gotoxy;
	cout << "MSNV \t Họ tên \t Phòng \t LCB HSL Thưởng Thực lãnh" << endl;
	for (int i = 0; i < sl; i++)
	{
		InNV(ds[i]);
		cout << "\n";
	}
}
int main()
{
	NhanVien danhsach[MAX];
	int sonv = 0;
	SetConsoleOutputCP(CP_UTF8);
	string filename = "Input.txt";
	if (!ReadData(filename, danhsach, sonv)) //nếu đọc dữ liệu ok
		InDS(danhsach, sonv);
	int t = _getch();
	return 0;
}