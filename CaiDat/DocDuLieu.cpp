#include "../KhaiBao/DocDuLieu.h"
#include <iostream>
#include <fstream>

using namespace std;
//Nôm na dễ hiểu là ban đầu sẽ mở file xong qua đọc số địa điểm n -> nó sẽ tạo ma trận n x n rồi đọc cái khoảng cách vào ma trận, đóng file và trả về true
// Hàm đọc ma trận khoảng cách từ file
bool docFileMaTran(string filePath, int &n, vector<vector<double>> &matrix)
{
    // Mở file dữ liệu
    ifstream file(filePath);

    // Nếu không mở được file
    if (!file.is_open())
    {
        cout << "Khong the mo file!" << endl;
        return false;
    }

    // Đọc số lượng địa điểm
    file >> n;

    // Kiểm tra số lượng địa điểm
    if (n <= 0)
    {
        cout << "So luong dia diem khong hop le!" << endl;
        return false;
    }

    // Tạo ma trận có kích thước n x n
    matrix.resize(n, vector<double>(n));

    // Đọc khoảng cách giữa các địa điểm
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            file >> matrix[i][j];
        }
    }

    // Đóng file
    file.close();

    return true;
}
