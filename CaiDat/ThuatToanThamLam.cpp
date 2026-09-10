#include "../KhaiBao/ThuatToanThamLam.h"
#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

// ---------------------------------------------------------------
// Tinh khoang cach Euclid giua 2 dia diem
// ---------------------------------------------------------------
double TinhKhoangCach(const DiaDiem &a, const DiaDiem &b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

// ---------------------------------------------------------------
// Xay dung ma tran khoang cach n x n tu danh sach dia diem
// ---------------------------------------------------------------
MaTranKhoangCach XayDungMaTranKhoangCach(const vector<DiaDiem> &dsDiaDiem)
{
    int n = (int)dsDiaDiem.size();
    MaTranKhoangCach maTran(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
                maTran[i][j] = TinhKhoangCach(dsDiaDiem[i], dsDiaDiem[j]);
        }
    }
    return maTran;
}

/*
    ------------------------------------------------------------------
    THUAT TOAN THAM LAM: CHON DINH GAN NHAT (NEAREST NEIGHBOR)
    ------------------------------------------------------------------
    Pseudocode (Muc 2.3):

    Function ThamLam_ChonDinhGanNhat(dsDiaDiem, dinhBatDau):
        n <- so luong dia diem
        daTham[0..n-1] <- false
        loTrinh <- []
        dinhHienTai <- dinhBatDau
        daTham[dinhHienTai] <- true
        Them dinhHienTai vao loTrinh

        Lap (n - 1) lan:
            dinhGanNhat <- -1
            khoangCachNhoNhat <- +vo cung
            Voi moi dinh j chua duoc tham:
                if khoangCach(dinhHienTai, j) < khoangCachNhoNhat:
                    khoangCachNhoNhat <- khoangCach(dinhHienTai, j)
                    dinhGanNhat <- j
            danh dau daTham[dinhGanNhat] <- true
            Them dinhGanNhat vao loTrinh
            dinhHienTai <- dinhGanNhat

        Them dinhBatDau vao cuoi loTrinh (quay ve diem xuat phat)
        return loTrinh
    ------------------------------------------------------------------
*/
vector<int> ThamLam_ChonDinhGanNhat(const vector<DiaDiem> &dsDiaDiem,
                                     int dinhBatDau)
{
    int n = (int)dsDiaDiem.size();
    vector<int> loTrinh;

    if (n == 0)
        return loTrinh;

    MaTranKhoangCach maTran = XayDungMaTranKhoangCach(dsDiaDiem);

    vector<bool> daTham(n, false);
    int dinhHienTai = dinhBatDau;
    daTham[dinhHienTai] = true;
    loTrinh.push_back(dinhHienTai);

    // Buoc lap: chon dinh gan nhat chua tham, lap (n - 1) lan
    for (int buoc = 1; buoc < n; buoc++)
    {
        int dinhGanNhat = -1;
        double khoangCachNhoNhat = numeric_limits<double>::max();

        for (int j = 0; j < n; j++)
        {
            if (!daTham[j])
            {
                double kc = maTran[dinhHienTai][j];
                if (kc < khoangCachNhoNhat)
                {
                    khoangCachNhoNhat = kc;
                    dinhGanNhat = j;
                }
            }
        }

        daTham[dinhGanNhat] = true;
        loTrinh.push_back(dinhGanNhat);
        dinhHienTai = dinhGanNhat;
    }

    // Quay ve diem xuat phat de hoan tat lo trinh khep kin
    loTrinh.push_back(dinhBatDau);

    return loTrinh;
}

// ---------------------------------------------------------------
// Tinh tong quang duong cua mot lo trinh
// ---------------------------------------------------------------
double TinhTongQuangDuong(const vector<int> &loTrinh,
                           const MaTranKhoangCach &maTran)
{
    double tong = 0.0;
    for (size_t i = 0; i + 1 < loTrinh.size(); i++)
        tong += maTran[loTrinh[i]][loTrinh[i + 1]];
    return tong;
}

// ---------------------------------------------------------------
// In lo trinh ra man hinh
// ---------------------------------------------------------------
void InLoTrinh(const vector<int> &loTrinh, const vector<DiaDiem> &dsDiaDiem)
{
    for (size_t i = 0; i < loTrinh.size(); i++)
    {
        cout << dsDiaDiem[loTrinh[i]].ten;
        if (i + 1 < loTrinh.size())
            cout << " -> ";
    }
    cout << endl;
}
