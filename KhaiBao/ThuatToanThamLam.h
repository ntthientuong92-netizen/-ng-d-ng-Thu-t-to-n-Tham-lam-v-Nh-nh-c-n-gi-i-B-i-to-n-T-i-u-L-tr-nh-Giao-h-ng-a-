#ifndef THUATTOANTHAMLAM_H
#define THUATTOANTHAMLAM_H

#include "DiaDiem.h"

/*
    CHUONG 2: THUAT TOAN THAM LAM (GREEDY)
    Muc 2.1: Y tuong thuat toan Chon dinh gan nhat (Nearest Neighbor)
    Muc 2.2: Chi tiet cac buoc thuc hien theo tung buoc lap
    Muc 2.3: Ma gia (Pseudocode) thuat toan Tham lam chuan khoa hoc

    Y tuong:
    Xuat phat tu tiem banh (dinh 0). Tai moi buoc, chon diem giao hang
    CHUA GHE QUA va co khoang cach GAN NHAT tinh tu diem hien tai de di
    den tiep theo. Lap lai cho den khi di het tat ca cac diem, sau do
    quay ve diem xuat phat (tiem banh) de hoan tat lo trinh khep kin.

    Day la thuat toan THAM LAM vi tai moi buoc no dua ra lua chon
    TOT NHAT CUC BO (gan nhat ngay luc do) ma khong xet toi anh huong
    ve sau, nen loi giai tim duoc la loi giai CHAP NHAN DUOC (heuristic)
    chu khong dam bao la loi giai TOI UU toan cuc.

    Do phuc tap: O(n^2) voi n la so diem giao hang (ke ca kho xuat phat).
*/

// Tinh khoang cach Euclid giua 2 dia diem a va b
double TinhKhoangCach(const DiaDiem &a, const DiaDiem &b);

// Xay dung ma tran khoang cach giua tat ca cac dia diem
MaTranKhoangCach XayDungMaTranKhoangCach(const vector<DiaDiem> &dsDiaDiem);

/*
    Thuat toan Tham lam - Chon dinh gan nhat (Nearest Neighbor)
    Input : dsDiaDiem   - danh sach cac dia diem (dinh 0 la tiem banh)
            dinhBatDau  - chi so dinh xuat phat (mac dinh = 0)
    Output: vector<int> chua thu tu cac dinh trong lo trinh
            (bat dau va ket thuc tai dinhBatDau)
*/
vector<int> ThamLam_ChonDinhGanNhat(const vector<DiaDiem> &dsDiaDiem,
                                     int dinhBatDau = 0);

// Tinh tong quang duong (chi phi) cua mot lo trinh da cho
double TinhTongQuangDuong(const vector<int> &loTrinh,
                           const MaTranKhoangCach &maTran);

// In lo trinh ra man hinh o dang de doc: Ten diem 1 -> Ten diem 2 -> ...
void InLoTrinh(const vector<int> &loTrinh, const vector<DiaDiem> &dsDiaDiem);

#endif // THUATTOANTHAMLAM_H
