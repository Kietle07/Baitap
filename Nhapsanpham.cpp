#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// Cau truc cho san pham
struct SanPham {
    string maSP;     // Ma san pham (chuoi 4 ky tu)
    string tenSP;    // Ten san pham (chuoi 30 ky tu)
    string donVi;    // Don vi tinh (chuoi 10 ky tu)
    float giaBan;    // Gia ban (so thuc)
    int soLuong;     // So luong (so nguyen)
};
// Ham nhap so san pham n (n >= 3)
void NhapSoSanPham(int& n) {
    do {
        cout << "Nhap so san pham n (n >= 3): ";
        cin >> n;
        if (n < 3) {
            cout << "n phai >= 3! Nhap lai." << endl;
        }
    } while (n < 3);
}

// Ham nhap danh sach n san pham
void NhapDanhSach(SanPham ds[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap san pham " << i + 1 << ":" << endl;
        cout << "Ma SP: ";
        cin >> ds[i].maSP;
        cout << "Ten SP: ";
        cin >> ds[i].tenSP;
        cout << "Don vi: ";
        cin >> ds[i].donVi;
        cout << "Gia ban: ";
        cin >> ds[i].giaBan;
        cout << "So luong: ";
        cin >> ds[i].soLuong;
    }
}

// Ham xuat danh sach san pham
void XuatDanhSach(SanPham ds[], int n) {
    cout << "\nDanh sach san pham:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "San pham " << i + 1 << ": Ma: " << ds[i].maSP
            << " | Ten: " << ds[i].tenSP
            << " | Don vi: " << ds[i].donVi
            << " | Gia ban: " << ds[i].giaBan
            << " | So luong: " << ds[i].soLuong << endl;
    }
}
// Ham hoan doi hai san pham
void Swap(SanPham& a, SanPham& b) {
    SanPham temp = a;
    a = b;
    b = temp;
}

// Ham sap xep bubble sort theo gia ban (tang dan)
void SapXepTheoGia(SanPham ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ds[j].giaBan > ds[j + 1].giaBan) {
                Swap(ds[j], ds[j + 1]);
            }
        }
    }
}

// Ham sap xep bubble sort theo ten SP (de binary search)
void SapXepTheoTen(SanPham ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ds[j].tenSP > ds[j + 1].tenSP) {
                Swap(ds[j], ds[j + 1]);
            }
        }
    }
}

// Ham tim kiem binary search theo ten SP (tra ve vi tri neu tim thay, -1 neu khong)
int TimKiemBinary(SanPham ds[], int n, string tenTim) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (ds[mid].tenSP == tenTim) {
            return mid;
        }
        else if (ds[mid].tenSP < tenTim) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    SanPham ds[50];  // Mang luu danh sach (toi da 50)

    NhapSoSanPham(n);       // Nhap n
    NhapDanhSach(ds, n);    // Nhap danh sach
    XuatDanhSach(ds, n);    // Xuat danh sach ban dau

    // Sap xep theo gia va xuat lai
    SapXepTheoGia(ds, n);
    cout << "\nDanh sach sau khi sap xep theo gia ban:" << endl;
    XuatDanhSach(ds, n);

    // Sap xep theo ten de tim kiem binary
    SapXepTheoTen(ds, n);
    cout << "\nDanh sach sau khi sap xep theo ten (de tim kiem):" << endl;
    XuatDanhSach(ds, n);

    // Tim kiem theo ten
    string tenTim;
    cout << "\nNhap ten san pham can tim: ";
    cin >> tenTim;
    int viTri = TimKiemBinary(ds, n, tenTim);
    if (viTri != -1) {
        cout << "Tim thay san pham tai vi tri " << viTri + 1 << ": "
            << ds[viTri].tenSP << " - Gia: " << ds[viTri].giaBan << endl;
    }
    else {
        cout << "Khong tim thay san pham co ten " << tenTim << endl;
    }
    int t = _getch();
    return 0;
}