#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<string>
#include<sstream> //tách chuỗi
#include<fstream>
#define MAX 50
using namespace std;
int xd = 10, yd = 1, ddx = 12;
void gotoxy(int x, int y)
{
    COORD toado;
    toado.X = x;
    toado.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), toado);
}
struct NhanVien
{
    char msnv[11];
    char hoten[50];
    char phongban[20];
    char namsinh[12];
    float lcb, hsl, thuong, thuclanh;
};
int ReadFile(string filename, NhanVien ds[], int& n)
{
    fstream ifile(filename.c_str());
    if (!ifile.is_open())
    {
        cout << "Không có file hoặc bị lỗi";
        return 1;
    }
    string line;
    n = 0;
    while (getline(ifile, line) && n < MAX)
    {
        stringstream ss(line);
        ss.getline(ds[n].msnv, sizeof(ds[n].msnv), ',');
        ss.getline(ds[n].hoten, sizeof(ds[n].hoten), ',');
        ss.getline(ds[n].phongban, sizeof(ds[n].phongban), ',');
        ss.getline(ds[n].namsinh, sizeof(ds[n].namsinh), ',');
        ss >> ds[n].lcb;
        ss >> ds[n].hsl;
        ss >> ds[n].thuong;
        n++;
    }
    ifile.close();
    return 0;
}
void InTieuDe(string title, int x, int& y)
{
    gotoxy(x + 2.5 * ddx, y); cout << "MSNV";
    gotoxy(x, y); cout << "HỌ TÊN";
    gotoxy(x + 2 * ddx, y); cout << "PHÒNG BAN";
    gotoxy(x + 3.5 * ddx, y); cout << "NGÀY SINH";
    gotoxy(x + 4.5 * ddx, y); cout << "LCB";
    gotoxy(x + 5.5 * ddx, y); cout << "HSL";
    gotoxy(x + 6 * ddx, y); cout << "THƯỞNG";
    gotoxy(x + 7 * ddx, y); cout << "THỰC LÃNH";
}
void InDS(NhanVien ds[], int sonv, int x, int y)
{
    InTieuDe("THÔNG TIN NHÂN VIÊN", x, y);
    y++;
    for (int i = 0; i < sonv; i++)
    {
        gotoxy(x + 2.5 * ddx, y); cout << ds[i].msnv;
        gotoxy(x, y); cout << ds[i].hoten;
        gotoxy(x + 2 * ddx, y); cout << ds[i].phongban;
        gotoxy(x + 3.5 * ddx, y); cout << ds[i].namsinh;
        gotoxy(x + 4.5 * ddx, y); cout << ds[i].lcb;
        gotoxy(x + 5.5 * ddx, y); cout << ds[i].hsl;
        gotoxy(x + 6 * ddx, y); cout << ds[i].thuong;
        float tl = ds[i].lcb * ds[i].hsl + ds[i].thuong;
        gotoxy(x + 7 * ddx, y); cout << tl;
        y++;
    }
}
string m1[] = { "CHƯƠNG TRÌNH QUẢN LÝ NHÂN VIÊN",
"1. IN DANH SÁCH NHÂN VIÊN",
"2. THÊM NHÂN VIÊN",
"3. CẬP NHẬT THÔNG TIN NHÂN VIÊN",
"4. XÓA NHÂN VIÊN",
"5. TÌM KIẾM NHÂN VIÊN",
"6. SẮP XẾP DANH SÁCH",
"7. THOÁT", };
string mn_timkiem[] = { "TÌM KIẾM NHÂN VIÊN",
"1. Tìm kiếm tuyến tính (Linear Search)",
"2. Tìm kiếm nhị phân (Binary Search",
"3. Quay về." };
string mn_sapxep[] = {
"THUẬT TOÁN SẮP XẾP CƠ BẢN",
"1. Thuật toán Bubble Sort",
"2. Thuật toán Shaker Sort",
"3. Thuật toán Selection Sort",
"4. Thuật toán Insertion Sort",
"5. Thuật toán Interchange Sort",
"6. Quay về."
};
void InMenu(string menu[], int len)
{
    system("cls");
    cout << menu[0];
    for (int i = 0; i < len; i++)
        cout << menu[i] << "\n";
}
int main()
{
    int stop;
    SetConsoleOutputCP(CP_UTF8);
    int chon1, chon2;
    NhanVien danhsach[MAX];
    int sonv = 0;
    string filein = "Input.txt";
    if (ReadFile(filein, danhsach, sonv))
        cout << "Lỗi đọc file";
    else
        InDS(danhsach, sonv, xd, yd);
    do
    {
        InMenu(m1, size(m1));
        cout << "\n Mời chọn chức năng (1-7): ";
        cin >> chon1;
        switch (chon1)
        {
        case 1:
            system("cls");
            cout << "In danh sách nhân viên" << endl;
            InDS(danhsach, sonv, xd, yd);
            stop = _getch();
            break;
        case 2:
            system("cls");
            cout << "2. THÊM NHÂN VIÊN" << endl;
            stop = _getch();
            break;
        case 3:
            system("cls");
            cout << "3. CẬP NHẬT THÔNG TIN NHÂN VIÊN" << endl;
            stop = _getch();
            break;
        case 4:
            system("cls");
            cout << "4. XÓA NHÂN VIÊN" << endl;
            stop = _getch();
            break;
        case 5:
            do
            {
                InMenu(mn_timkiem, size(mn_timkiem));
                cout << "Mời chọn chức năng: ";
                cin >> chon2;
                switch (chon2)
                {
                case 1:
                    system("cls");
                    cout << "Tìm kiếm tuyến tính" << endl;
                    stop = _getch();
                    break;
                case 2:
                    system("cls");
                    cout << "Tìm kiếm nhị phân" << endl;
                    stop = _getch();
                    break;
                case 3:
                    system("cls");
                    cout << "Nhấn phím bất kì để tiếp tục..." << endl;
                    stop = _getch();
                    break;
                }
            } while (chon2 != 3);
            break;
        case 6:
            do
            {
                InMenu(mn_sapxep, size(mn_sapxep));
                cout << "Mời chọn chức năng: ";
                cin >> chon2;
                switch (chon2)
                {
                case 1:
                    system("cls");
                    cout << "Thuật toán Bubble Sort" << endl;
                    stop = _getch();
                    break;
                case 2:
                    system("cls");
                    cout << "Thuật toán Shaker Sort" << endl;
                    stop = _getch();
                    break;
                case 3:
                    system("cls");
                    cout << "Thuật toán Selection Sort" << endl;
                    stop = _getch();
                    break;
                case 4:
                    system("cls");
                    cout << "Thuật toán Insertion Sort" << endl;
                    stop = _getch();
                    break;
                case 5:
                    system("cls");
                    cout << "Thuật toán Interchange Sort" << endl;
                    stop = _getch();
                    break;
                case 6:
                    system("cls");
                    cout << "Nhấn phím bất kì để tiếp tục..." << endl;
                    stop = _getch();
                }
            } while (chon2 != 6);
            break;
        case 7:
            cout << "\n NHẤN PHÍM BẤT KÌ ĐỂ KẾT THÚC....";
            stop = _getch();
        }
    } while (chon1 != 7);
    stop = _getch();
    return 0;
}