#include <iostream>
#include <string>
#include <iomanip>
#include "../KhaiBao/DiaDiem.h"
#include "../KhaiBao/DocDuLieu.h"
#include "../KhaiBao/ThuatToanThamLam.h"
#include "../KhaiBao/ThuatToanNhanhCan.h"
#include "../KhaiBao/DoHieuNang.h"

using namespace std;

void hienThiMenu() {
    cout << "========================================================\n";
    cout << "    HE THONG TOI UU LO TRINH - TIEM BANH GOC BEP ME BAP   \n";
    cout << "========================================================\n";
    cout << "1. Chon bo du lieu (Bo 1: 8 diem, Bo 2: 10 diem, Bo 3: 12 diem)\n";
    cout << "2. Chay thuat toan Tham lam (Greedy)\n";
    cout << "3. Chay thuat toan Nhanh can (Branch & Bound)\n";
    cout << "4. Do hieu nang va xuat bao cao so sanh\n";
    cout << "0. Thoat chuong trinh\n";
    cout << "========================================================\n";
    cout << "Nhap lua chon cua ban: ";
}

int main() {
    int luaChon;
    int chonBoDuLieu = 1; // Mac dinh bo du lieu 1

    do {
        hienThiMenu();
        if (!(cin >> luaChon)) {
            break;
        }

        // Lay bo du lieu hien tai
        vector<DiaDiem> dsDiaDiem;
        string tenBoDuLieu;
        switch (chonBoDuLieu) {
            case 1: dsDiaDiem = TaoBoDuLieu1(); tenBoDuLieu = "Bo 1 (8 diem)"; break;
            case 2: dsDiaDiem = TaoBoDuLieu2(); tenBoDuLieu = "Bo 2 (10 diem)"; break;
            case 3: dsDiaDiem = TaoBoDuLieu3(); tenBoDuLieu = "Bo 3 (12 diem)"; break;
            default: dsDiaDiem = TaoBoDuLieu1(); tenBoDuLieu = "Bo 1 (8 diem)"; break;
        }

        switch(luaChon) {
            case 1: {
                cout << "1. Bo 1 (8 diem) | 2. Bo 2 (10 diem) | 3. Bo 3 (12 diem) => Chon: ";
                if (!(cin >> chonBoDuLieu)) {
                    cin.clear();
                    string temp;
                    cin >> temp;
                    chonBoDuLieu = 1;
                }
                if (chonBoDuLieu < 1 || chonBoDuLieu > 3) {
                    cout << "Lua chon khong hop le, mac dinh Bo 1.\n";
                    chonBoDuLieu = 1;
                }
                cout << "Da cap nhat du lieu dau vao!\n";
                break;
            }
            case 2: {
                cout << "\n--- KET QUA THUAT TOAN THAM LAM ---\n";
                cout << "Du lieu: " << tenBoDuLieu << "\n\n";

                MaTranKhoangCach maTran = XayDungMaTranKhoangCach(dsDiaDiem);
                auto [loTrinh, thoiGian] = DoHieuNang::Do(ThamLam_ChonDinhGanNhat, dsDiaDiem, 0);
                double tongQuangDuong = TinhTongQuangDuong(loTrinh, maTran);

                cout << "Lo trinh: ";
                InLoTrinh(loTrinh, dsDiaDiem);
                cout << fixed << setprecision(2);
                cout << "Tong quang duong: " << tongQuangDuong << " km\n";
                cout << "Thoi gian thuc thi: " << thoiGian << " micro giay\n";
                break;
            }
            case 3: {
                cout << "\n--- KET QUA THUAT TOAN NHANH CAN ---\n";
                cout << "Du lieu: " << tenBoDuLieu << "\n\n";

                MaTranKhoangCach maTran = XayDungMaTranKhoangCach(dsDiaDiem);
                int n = (int)dsDiaDiem.size();
                auto [ketQua, thoiGian] = DoHieuNang::Do(giaiNhanhCan, n, maTran);

                cout << "Lo trinh: ";
                for (size_t i = 0; i < ketQua.loTrinh.size(); i++) {
                    cout << dsDiaDiem[ketQua.loTrinh[i]].ten;
                    if (i + 1 < ketQua.loTrinh.size()) cout << " -> ";
                }
                cout << endl;
                cout << fixed << setprecision(2);
                cout << "Tong quang duong: " << ketQua.quangDuong << " km\n";
                cout << "Thoi gian thuc thi: " << thoiGian << " micro giay\n";
                break;
            }
            case 4: {
                cout << "\n--- DANG DO HIEU NANG VA XUAT FILE CSV ---\n";
                vector<KetQuaDo> danhSachKetQua;

                // Chay tren ca 3 bo du lieu
                vector<DiaDiem> ds1 = TaoBoDuLieu1();
                vector<DiaDiem> ds2 = TaoBoDuLieu2();
                vector<DiaDiem> ds3 = TaoBoDuLieu3();
                vector<pair<string, vector<DiaDiem>>> tatCaBoDuLieu = {
                    {"Bo 1", ds1}, {"Bo 2", ds2}, {"Bo 3", ds3}
                };

                for (auto& [tenBo, ds] : tatCaBoDuLieu) {
                    MaTranKhoangCach maTran = XayDungMaTranKhoangCach(ds);
                    int n = (int)ds.size();

                    // Tham lam
                    auto [ltTL, tgTL] = DoHieuNang::Do(ThamLam_ChonDinhGanNhat, ds, 0);
                    double qdTL = TinhTongQuangDuong(ltTL, maTran);
                    danhSachKetQua.push_back({tenBo, "Tham lam", n - 1, qdTL, tgTL});

                    // Nhanh can
                    auto [kqNC, tgNC] = DoHieuNang::Do(giaiNhanhCan, n, maTran);
                    danhSachKetQua.push_back({tenBo, "Nhanh can", n - 1, kqNC.quangDuong, tgNC});
                }

                DoHieuNang::XuatBaoCaoCSV(danhSachKetQua, "KetQua/BaoCaoSoSanh.csv");

                // In ket qua ra man hinh
                cout << "\n" << left << setw(10) << "BoDuLieu"
                     << setw(14) << "ThuatToan"
                     << setw(12) << "SoDiem"
                     << setw(16) << "QuangDuong(km)"
                     << "ThoiGian(us)\n";
                cout << string(64, '-') << "\n";
                for (auto& kq : danhSachKetQua) {
                    cout << left << setw(10) << kq.tenBoDuLieu
                         << setw(14) << kq.tenThuatToan
                         << setw(12) << kq.soDiemGiao
                         << fixed << setprecision(2)
                         << setw(16) << kq.quangDuong_km
                         << kq.thoiGian_micro << "\n";
                }
                cout << "\nDa xuat file tai KetQua/BaoCaoSoSanh.csv\n";
                break;
            }
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