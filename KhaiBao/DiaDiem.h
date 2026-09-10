#ifndef DIADIEM_H
#define DIADIEM_H

#include <string>
#include <vector>

using namespace std;

/*
    Cấu trúc DiaDiem mô tả một điểm giao hàng của tiệm bánh "Góc Bếp Mẹ Bắp"
    - id     : mã số điểm (0 = cửa hàng / kho xuất phát, 1..n = khách hàng)
    - ten    : tên địa điểm / khu vực (ví dụ: Quận 1, Quận 3, Thủ Đức...)
    - x, y   : toạ độ quy đổi trên bản đồ (đơn vị: km), dùng để tính khoảng cách
*/
struct DiaDiem
{
    int id;
    string ten;
    double x;
    double y;
};

// Kiểu dữ liệu ma trận khoảng cách giữa các địa điểm
typedef vector<vector<double>> MaTranKhoangCach;

#endif // DIADIEM_H
