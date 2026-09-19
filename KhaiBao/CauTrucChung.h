#ifndef CAU_TRUC_CHUNG_H
#define CAU_TRUC_CHUNG_H

#include <string>
#include <vector>
using namespace std;
// Lưu thông tin của một địa chỉ giao hàng
struct DiaDiem {
    int id;
    string ten;
    string diaChi;
};
// Kết quả của thuật toán mới chạy xong
struct KetQuaToiUu {
    vector<int> loTrinh;
    double quangDuong;
    double thoiGian;
};

#endif
