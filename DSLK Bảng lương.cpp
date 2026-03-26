#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#define MAX 50
using namespace std;
int xd = 2, yd = 1, ddx = 15;
void gotoxy(int x, int y) {
    COORD toado;
    toado.X = x;
    toado.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), toado);
}
// Tạo cấu trúc
struct Bangluong {
    char MSNV[6];
    int Thang;
    float Luong, TamUng, PhuCap;
};
// In tiêu đề bảng
void InTieuDe(int x, int& y) {
    gotoxy(x + 2.5 * ddx, y); cout << "THÔNG TIN BẢNG LƯƠNG";
    y++;
    gotoxy(x, y);     cout << "STT";
    gotoxy(x + 1 * ddx, y); cout << "MSNV";
    gotoxy(x + 2 * ddx, y); cout << "THÁNG";
    gotoxy(x + 3 * ddx, y); cout << "TIỀN LƯƠNG";
    gotoxy(x + 4 * ddx, y); cout << "TẠM ỨNG";
    gotoxy(x + 5 * ddx, y); cout << "PHỤ CẤP";
    y++;
}
// In một dòng dữ liệu
void InMotDong(int stt, Bangluong bl, int x, int y) {
    gotoxy(x, y);     cout << stt;
    gotoxy(x + 1 * ddx, y); cout << bl.MSNV;
    gotoxy(x + 2 * ddx, y); cout << bl.Thang;
    gotoxy(x + 3 * ddx, y); cout << bl.Luong;
    gotoxy(x + 4 * ddx, y); cout << bl.TamUng;
    gotoxy(x + 5 * ddx, y); cout << bl.PhuCap;
}

// Menu chính
string m1[] = {
    "\t\t\t\t\tCHƯƠNG TRÌNH QUẢN LÝ BẢNG LƯƠNG",
    "1. IN DANH SÁCH BẢNG LƯƠNG",
    "2. THÊM BẢNG LƯƠNG",
    "3. CẬP NHẬT THÔNG TIN BẢNG LƯƠNG",
    "4. XÓA BẢNG LƯƠNG",
    "5. TÌM KIẾM BẢNG LƯƠNG",
    "6. SẮP XẾP BẢNG LƯƠNG",
    "7. THỐNG KÊ BẢNG LƯƠNG",
    "8. THOÁT"
};
string mnthem[] = {
    "CHỌN CÁCH THÊM DANH SÁCH",
    "1. THÊM ĐẦU",
    "2. THÊM CUỐI",
    "3. THÊM BẤT KÌ",
    "4. THÊM TRƯỚC MÃ SỐ NHÂN VIÊN",
    "5. QUAY LẠI"
};
string mnxoa[] = {
    "CHỌN CÁCH XÓA DANH SÁCH",
    "1. XÓA ĐẦU",
    "2. XÓA CUỐI",
    "3. XÓA THEO MÃ SỐ NHÂN VIÊN",
    "4. XÓA SAU MÃ SỐ NHÂN VIÊN ĐÃ NHẶP",
    "5. XOA TOÀN BỘ DANH SÁCH",
    "6. QUAY LẠI."
};
string mn_sapxep[] = {
"THUẬT TOÁN SẮP XẾP CƠ BẢN",
"1. Thuật toán Bubble Sort",
"2. Thuật toán Selection Sort",
"3.Thuật toán Interchange Sort",
"4. Quay về."
};
string mn_sort[] = {
"CHỌN THÀNH PHẦN SẮP XẾP",
"1. Sắp xếp theo mã nhân viên",
"2. Sắp xếp theo tháng",
"3. Sắp xếp theo tiền lương",
"4. Sắp xếp theo tạm ứng",
"5. Sắp xếp theo phụ cấp",
"6. Quay lại"
};
string mn_huong[] = {
"CHỌN HƯỚNG SẮP XẾP",
"1. Tăng dần",
"2. Giảm dần",
"3. Quay lại"
};
void InMenu()
{
    system("cls");
    gotoxy(xd, yd);
    for (int i = 0; i < 9; i++) 
    {
        cout << m1[i] << endl;
    }
}
void InMenu(string menu[], int n)
{
    gotoxy(xd, yd);
    for (int i = 0; i < n; i++)
    {
        cout << menu[i] << endl;
    }
}
// Cấu trúc Node và DSLK
struct Node {
    Bangluong info;
    Node* next;
};
typedef Node* pNode;

struct LinkList {
    pNode Head;
    pNode Tail;
};
// Khởi tạo danh sách rỗng
void Initial(LinkList& l) {
    l.Head = nullptr;
    l.Tail = nullptr;
}

bool IsEmpty(const LinkList& l) {
    return (l.Head == nullptr);
}

// Tạo node mới
pNode CreateNode(Bangluong bl) {
    pNode p = new Node;
    if (!p) return nullptr;
    p->info = bl;
    p->next = nullptr;
    return p;
}
// Tìm kiếm chung
pNode tkc(LinkList l, Bangluong bl)
{
    pNode p = l.Head;
    while (p != NULL && strcmp(p->info.MSNV, bl.MSNV) != 0)
        p = p->next;
    return p;
}
//Thêm vào đầu danh sách
void AddtoHead(LinkList& l, Bangluong bl)
{
    pNode p = CreateNode(bl);
    p->next = l.Head;
    l.Head = p;
    if (!l.Tail) l.Tail = p;
}
// Thêm vào cuối danh sách (dùng khi đọc file)
void AddtoTail(LinkList& l, Bangluong bl) {
    pNode p = CreateNode(bl);
    if (!p) return;

    if (IsEmpty(l)) {
        l.Head = l.Tail = p;
    }
    else {
        l.Tail->next = p;
        l.Tail = p;
    }
}

// Thêm vào vị trí bất kỳ 
void thembatki(LinkList& l, Bangluong bl) {
    int x;
    cout << "\nChọn vị trí muốn thêm vào: ";
    cin >> x;
    pNode p = CreateNode(bl);
    if (!p) return;

    if (x <= 1 || IsEmpty(l)) {
        p->next = l.Head;
        l.Head = p;
        if (!l.Tail) l.Tail = p;
        return;
    }

    pNode q = l.Head;
    int i = 1;
    while (q->next != nullptr && i < x - 1) {
        q = q->next;
        i++;
    }

    p->next = q->next;
    q->next = p;
    if (q == l.Tail) l.Tail = p;
}
//Thêm sau msnv được chọn

void themsaumsnv(LinkList& l, Bangluong bl)
{
   
    int stop;
    char msnvtim[6]; 
    cout << "\nChọn mã số nhân viên muốn thêm sau: ";
    
    cin.getline(msnvtim, 6);  

    if (IsEmpty(l))
    {
        AddtoHead(l, bl); 
        return;
    }

    pNode k = l.Head;
    while (k != NULL && strcmp(k->info.MSNV, msnvtim) != 0)  
        k = k->next;

    if (k == NULL)
    {
        cout << "\nKhông tìm thấy mã số nhân viên để thêm sau!";
        stop =_getch();
        return;
    }

    pNode p = CreateNode(bl);  
    p->next = k->next;
    k->next = p;

    if (k == l.Tail)           
        l.Tail = p;

    cout << "\nĐã thêm sau " << msnvtim << " thành công!";
}
//Thêm chung 
void themchung(LinkList& l, int sx)
{

    Bangluong bl;
    int chon=2, stop;
    if (sx == 0)
    {
        InMenu(mnthem, 6);
        cout << "Chọn chức năng thêm: ";
        cin >> chon;
        cin.ignore();
        if (chon == 5)return;
        system("cls");
    }
    do {
        system("cls");
        cout << "Nhập MSNV(tối đa 5 ký tự): ";
        cin.getline(bl.MSNV, 100);
        
        while (strlen(bl.MSNV) == 0 || strlen(bl.MSNV) > 5)
        {
            cin.clear();
            cout << "MSNV không hợp lệ, nhập lại (1-5): ";
            cin.getline(bl.MSNV, 6);
        }

        cout << "Nhập tháng (1-12): ";
        cin >> bl.Thang;
        while (bl.Thang < 1 || bl.Thang > 12) {
            cin.clear();       
            cin.ignore(1000, '\n');
            cout << "Tháng không hợp lệ, nhập lại (1-12):  ";
            cin >> bl.Thang;
       
        }
        cout << "Nhập tiền lương: ";
        cin >> bl.Luong;
        cout << "Nhập tạm ứng: ";
        cin >> bl.TamUng;
        cout << "Nhập phụ cấp: ";
        cin >> bl.PhuCap;
        if (tkc(l, bl) != nullptr)
            cout << "Mã số nhân viên bị trùng vui lòng nhập lại!\n";    
        cin.ignore();
        stop = _getch();
    } while (tkc(l, bl) != nullptr);

        switch (chon)
        {
        case 1: AddtoHead(l, bl); break;
        case 2: AddtoTail(l, bl); break;
        case 3: thembatki(l, bl); break;
        case 4: themsaumsnv(l, bl); break;
        }
    
    cout << "\nĐã thêm thành công\n";
}
// In toàn bộ danh sách
void PrintList(LinkList l) {
    if (IsEmpty(l)) {
        cout << "\nDanh sách trống!\n";
        return;
    }

    int stt = 1;
    int y = yd + 1;  
    InTieuDe(xd, y);

    for (pNode p = l.Head; p != nullptr; p = p->next) {
        InMotDong(stt++, p->info, xd, y++);
    }
}
// Tìm kiếm theo MSNV
void timkiem(LinkList l) {
    char msnv[6];
    
    cout << "\t\t\t\t\t\t=== TÌM KIẾM BẢNG LƯƠNG ===\n";
    cout << "Nhập số nhân viên cần tìm:  ";
    cin.getline(msnv, 6);

    pNode p = l.Head;
    while (p != nullptr && strcmp(p->info.MSNV, msnv) != 0) {
        p = p->next;
    }
    if (p != nullptr) {
        cout << endl;
        int y = yd+1;
        InTieuDe(xd, y);
        InMotDong(1, p->info, xd, y + 1);
    }
    else {
        cout << "\nKhông tìm thấy mã nhân viên!\n";
    }
}

// Xóa đầu danh sách
void XoaDau(LinkList& l) 
{
    pNode p = l.Head;
    //TH1: Ds rỗng
    if (IsEmpty(l))
    {
        cout << "\nDanh sách rỗng!";
        return;
    }
    //TH2: 
    else if (l.Head == l.Tail)
    {
        l.Head = nullptr;
        l.Tail = nullptr;
    }
    //TH3: Nhiều hơn 1 nút
    else
    {
        l.Head = l.Head->next;
        delete p;
    }
}

// Xóa cuối danh sách
void XoaCuoi(LinkList& l)
{
    pNode p = l.Tail, q = l.Head;
    if (IsEmpty(l))
    {
        cout << "\nDanh sách rỗng";
        return;
    }
    else if (l.Head == l.Tail)

        l.Head = l.Tail = nullptr;
    else
    {
        while (q->next != p)
            q = q->next;
        l.Tail = q;
        l.Tail->next = nullptr; 
        delete p;
    }
}
// Xóa bất kì 
void XoaCS(LinkList& l)
{
    Bangluong bl;
    pNode p, q = l.Head;
    if (IsEmpty(l))
    {
        cout << "\nDanh sách rỗng!";
        return;
    }
    else if (l.Head == l.Tail)
    {
        l.Head = l.Tail = nullptr;
        delete q;
    }
    else
    {
        cin.ignore();
        cout << "Chon MSNV muốn xóa: ";
        cin.getline(bl.MSNV, 6);
        while (strcmp(q->next->info.MSNV, bl.MSNV) != 0)
            q = q->next;
        p = q->next;
        q->next = q->next->next;
        delete p;
    }
}
// Xóa q sau p 
void XoaSau(LinkList& l)
{
    int i = 1;
    pNode p, q;
    Bangluong bl;
    cin.ignore();
    cout << "Chọn MSNV muốn xóa sau: ";
    cin.getline(bl.MSNV, 6);
    if (tkc(l, bl) == NULL)
        cout << "Không tìm thấy MSNV cần xóa!";
    else
    {
        p = tkc(l, bl);
        q = p->next;
        if (q == NULL)
            cout << "Không có phần tử nào sau MSNV đã chọn!";
        else
        {
            p->next = p->next->next;
            delete q;
            cout << "Đã xóa thành công!";
        }
    }
}
// Xóa hết
void XoaAll(LinkList& l)
{
    while (l.Head != nullptr)
        XoaDau(l);
}
// Cập nhật
void capnhat(LinkList l)
{
    pNode p;
    Bangluong bl;
    
    cout << "\t\t\t\t\t=== CẬP NHẬT THÔNG TIN BẢNG LƯƠNG BẢNG LƯƠNG ===\n";
    cout << "Nhập mã số nhân viên muốn cập nhật: ";
    cin.getline(bl.MSNV, 6);
    pNode k = tkc(l, bl);
    
    if (k == nullptr)
        cout << "Không tìm thấy mã số nhân viên cần cập nhật!";
    else
    {
        cout << "Mã nhân viên: ";
        cin.getline(k->info.MSNV, 6);
        cout << "Tháng: ";
        cin >> k->info.Thang;
        cout << "Lương: ";
        cin >> k->info.Luong;
        cout << "Tạm ứng: ";
        cin >> k->info.TamUng;
        cout << "Phụ cấp: ";
        cin >> k->info.PhuCap;
        cin.ignore();

        cout << "\nĐã cập nhật thành công!";
    }
}
// Tính tổng 
void Tinhtong(LinkList l)
{
    int stop;
    char msnv[6];
    char tieptuc;
    system("cls");
    int y = yd;
    gotoxy(xd, y); cout << "7. THỐNG KÊ BẢNG LƯƠNG";
    y++;
    InTieuDe(xd, y);
    int stt = 1;
    for (pNode p = l.Head; p != nullptr; p = p->next)
        InMotDong(stt++, p->info, xd, y++);
    
    do {
        gotoxy(xd, y + 1);
        cout << "Nhập mã nhân viên cần thống kê (tối đa 5 kí tự): ";
        cin.getline(msnv, 6);
        pNode p = l.Head;
        float tongluong = 0, tongtamung = 0, tongphucap = 0;
        bool found = false;

        while (p != nullptr)
        {
            if (strcmp(p->info.MSNV, msnv) == 0)
            {
                tongluong += p->info.Luong;
                tongtamung += p->info.TamUng;
                tongphucap += p->info.PhuCap;
                found = true;
            }
            p = p->next;
        }
        system("cls");
        if (!found)
        {
            cout << "Không tìm thấy MSNV: " << msnv;
        }
        else
        {
            float tongtien = tongluong + tongtamung + tongphucap;

            gotoxy(xd, yd);
            cout << "THỐNG KÊ BẢNG LƯƠNG - MSNV: " << msnv;

            gotoxy(xd, yd + 2); 
            cout << "Tổng tiền lương : " << tongluong;
            gotoxy(xd, yd + 3);
            cout << "Tổng tạm ứng    : " << tongtamung; 
            gotoxy(xd, yd + 4);
            cout << "Tổng phụ cấp    : " << tongphucap; 
            gotoxy(xd, yd + 5);
            cout << "Tổng tiền       : " << tongtien; 
        }
        gotoxy(xd, yd + 7);
        cout << "Tiếp tục thống kê nhân viên khác? (Y/N): "; 
        cin >> tieptuc;
        

    } while (tieptuc == 'Y' || tieptuc == 'y');
}
//Hàm so sánh chung
int sosanh(pNode a, pNode b, int chon1)
{
    switch (chon1)
    {
    case 1: return strcmp(a->info.MSNV, b->info.MSNV);
    case 2: return a->info.Thang- b->info.Thang;
    case 3: return a->info.Luong - b->info.Luong;
    case 4: return a->info.TamUng - b->info.TamUng;
    case 5: return a->info.PhuCap - b->info.PhuCap;
    }
}
//Hàm swap
void swap(pNode& a, pNode& b )
{
    Bangluong t = a->info;
    a->info = b->info;
    b->info = t;
}
// BubbleSort
void BubbleSort(LinkList& l, int sx, int chon1)
{
    int done;
    for (pNode p = l.Head; p != nullptr; p = p->next)
    {
        done = 1;
        for (pNode q = l.Head; q->next != nullptr; q = q->next)
        {
            int cmp = sosanh(q, q->next, chon1);
            if ((sx > 0 && cmp > 0) || (sx < 0 && cmp < 0))
            {
                swap(q, q->next);
                done = 0;
            }
        }
        if (done == 1) break;
    }
}
void SelectionSort(LinkList l, int sx, int chon1)
{
    pNode m;
    for (pNode p = l.Head; p->next != nullptr; p = p->next)
    {
        m = p;
        for (pNode x = p->next; x != nullptr; x = x->next)
        {
            int cmp = sosanh(x, m, chon1);
            if ((sx > 0 && cmp < 0) || (sx < 0 && cmp > 0))
                m = x;
        }
        swap(p, m);
    }
}
void InterchangeSort(LinkList l, int sx, int chon1)
{
    for (pNode p = l.Head; p != nullptr; p = p->next)
        for (pNode x = l.Head; x != nullptr; x = x->next)
        {
            int cmp = sosanh(p, x, chon1);
            if ((sx > 0 && cmp < 0) || (sx < 0 && cmp > 0))
                swap(p, x);
        }
}
void sapxeptong(LinkList& l, int& sx)
{
    int chon1, chon2, chon3;

    if (IsEmpty(l))
    {
        cout << "Danh sách rỗng";
        return;
    }
    if (l.Head == l.Tail)
    {
        cout << "Danh sách chỉ có 1 phần tử nên không cần sắp xếp";
        return;
    }
    do {
        system("cls");
        InMenu(mn_sapxep, 5);
        cout << "Mời chọn cách sắp xếp: ";
        cin >> chon3;
        if (chon3 == 4) return;

        system("cls");
        InMenu(mn_sort, 7);
        cout << "Mời chọn thành phần sắp xếp: ";
        cin >> chon1;
    } while (chon1 == 6);

    
    
        system("cls");
        InMenu(mn_huong, 4);
        cout << "Mời chọn hướng sắp xếp: ";
        cin >> chon2;
    
    if (chon2 == 3) return;

    sx = chon1;
    if (chon2 == 2) sx *= -1;

   
    switch (chon3)
    {
    case 1: BubbleSort(l, sx, chon1);    break;
    case 2: SelectionSort(l, sx, chon1); break;
    case 3: InterchangeSort(l, sx, chon1); break;
    }
}

// Đọc dữ liệu từ file 
bool LoadData(string filename, LinkList& l) {
    ifstream finput(filename);
    if (!finput.is_open()) {
        return false;
    }
    string line;
    while (getline(finput, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string temp;
        Bangluong bl;
        getline(ss, temp, ','); strcpy_s(bl.MSNV, temp.c_str());
        getline(ss, temp, ','); bl.Thang = stoi(temp);
        getline(ss, temp, ','); bl.Luong = stof(temp);
        getline(ss, temp, ','); bl.PhuCap = stof(temp);
        getline(ss, temp, ','); bl.TamUng = stof(temp);
        AddtoTail(l, bl);
    }
    finput.close();
    return true;
}
int main() {
    SetConsoleOutputCP(65001);
    int stop;
    LinkList list;
    Initial(list);

    string filein = "input.txt";

    if (LoadData(filein, list)) {
        cout << "Đã đọc dữ liệu từ file " << filein << " thành công!\n";
    }
    else {
        cout << "Không mở được file " << filein << " hoặc file rỗng\n";
    }

    cout << "\nNhấn phím bất kì để tiếp tục";
    stop=_getch();

    int chon1,sx=0;
    do {
       
        InMenu();

        gotoxy(xd, yd + 12);
        cout << "Mời chọn chức năng(1-8): ";
        cin >> chon1;
        cin.ignore();
        system("cls");
        switch (chon1) {
        case 1:
            gotoxy(xd, yd);
            PrintList(list);
            cout << "\n\nNhấn phím bất kì để tiếp tục...";
            stop=_getch();
            break;
        case 2: {
            system("cls");
            cout << "\t\t\t\t\t\t=== THÊM BẢNG LƯƠNG MỚI ===\t" << endl;
            themchung(list,sx);       
            cout << "\nNhấn phím bất kì để tiếp tục...";
            stop=_getch();
            break;
        }
        case 3:
            system("cls");
       
           
            capnhat(list);
            cout << "\nNhấn phím bất kì để tiếp tục...";
            stop = _getch();
            break;
        case 4:
        {
            int chonxoa;
            system("cls");

            cout << "\t\t\t\t\t\t=== XÓA BẢNG LƯƠNG ===";
            InMenu(mnxoa, 7);

            cout << "\nMời chọn cách xóa: ";
            cin >> chonxoa;

            switch (chonxoa)
            {
            case 1:
                XoaDau(list);
                cout << "\nĐã xóa đầu danh sách!";
                break;

            case 2:
                XoaCuoi(list);
                cout << "\nĐã xóa cuối danh sách!";
                break;

            case 3:
                XoaCS(list);
                cout << "\nĐã xóa bất kì trong danh sách!";
                break;

            case 4:
                XoaSau(list);
                cout << "\nĐã xóa sau mã đã nhập!";
                break;
            case 5:
                XoaAll(list);
                cout << "Đã xóa toàn bộ danh sách!";
                break;
            case 6:
                
                break;

            default:
                cout << "\nLựa chọn không hợp lệ!";
            }
            cout << "\nNhấn phím bất kì để tiếp tục...";
            stop = _getch();
            break;
        }
        case 5:
            
            timkiem(list);
            cout << "\nNhấn phím bất kì để tiếp tục";
            stop=_getch();
            break;
        case 6:
        {
            int sx = 1;
            sapxeptong(list, sx);
            cout << "\nNhấn phím bất kì để tiếp tục";
            stop = _getch();
            break;
        }
        case 7: 
            Tinhtong(list);
            cout << "\nNhấn phím bất kì để tiếp tục!";
            stop = _getch();
            break;
        case 8:
            cout << "\nTạm biệt. Chương trình kết thúc!\n";
            break;

        default:
            cout << "Lựa chọn không hợp lệ!\n";
            stop=_getch();
            break;
        }
    } while (chon1 != 8);
    return 0;
}