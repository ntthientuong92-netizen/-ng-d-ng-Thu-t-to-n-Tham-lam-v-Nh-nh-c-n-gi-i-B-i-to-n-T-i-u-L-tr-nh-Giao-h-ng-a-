#include <iostream>
#include <string>
#include "../KhaiBao/CauTrucChung.h"
#include "../KhaiBao/DocDuLieu.h"
#include "../KhaiBao/ThuatToanThamLam.h"
#include "../KhaiBao/ThuatToanNhanhCan.h"
#include "../KhaiBao/DoHieuNang.h"

using namespace std;
void hienThiMenu() {
    cout << "========================================================\n";
    cout << "    HE THONG TOI UU LO TRINH - TIEM BANH GOC BEP ME BAP   \n";
    cout << "========================================================\n";
    cout << "1. Chon bo du lieu (4 don, 8 don, 15 don)\n";
    cout << "2. Chay thuat toan Tham lam (Greedy)\n";
    cout << "3. Chay thuat toan Nhanh can (Branch & Bound)\n";
    cout << "4. Do hieu nang va xuat bao cao so sanh\n";
    cout << "0. Thoat chuong trinh\n";
    cout << "========================================================\n";
    cout << "Nhap lua chon cua ban: ";
}

int main() {
    int luaChon;
    string fileDuLieu = "../DungLieu/TapDuLieu_Nho_4Don.txt"; //Mặc định
    do {
        hienThiMenu();
        cin >> luaChon;
        
        switch(luaChon) {
            case 1:
                int chonFile;
                cout << "1. 4 Don | 2. 8 Don | 3. 15 Don => Chon: ";
                cin >> chonFile;
                if (chonFile == 1) fileDuLieu = "../DungLieu/TapDuLieu_Nho_4Don.txt";
                else if (chonFile == 2) fileDuLieu = "../DungLieu/TapDuLieu_Vua_8Don.txt";
                else if (chonFile == 3) fileDuLieu = "../DungLieu/TapDuLieu_Lon_15Don.txt";
                cout << "Da cap nhat du lieu dau vao!\n";
                break;
            case 2:
                cout << "\n--- KET QUA THUAT TOAN THAM LAM ---\n";
                break;
            case 3:
                cout << "\n--- KET QUA THUAT TOAN NHANH CAN ---\n";
                break;
            case 4:
                cout << "\n--- DANG DO HIEU NANG VA XUAT FILE CSV ---\n";
                cout << "Da xuat file tai KetQua/BaoCaoSoSanh.csv\n";
                break;
            case 0:
                cout << "Cam on ban da su dung phan mem.\n";
                break;
            default:
                cout << "Lua chon khong hop le, vui long nhap lai.\n";
        }
        cout << "\n";
    } while (luaChon != 0);

return 0;
}
