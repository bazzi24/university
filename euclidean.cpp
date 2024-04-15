#include <iostream>
#include <cmath> // Thư viện cho hàm sqrt và pow

// Khai báo cấu trúc Point để lưu trữ tọa độ x và y của một điểm
struct Point {
    double x;
    double y;
};

// Hàm để nhập tọa độ của điểm
void nhapDiem(Point &p) {
    std::cout << "Nhap x: ";
    std::cin >> p.x;
    std::cout << "Nhap y: ";
    std::cin >> p.y;
}

// Hàm tính khoảng cách Euclidean giữa hai điểm
double khoangCachEuclidean(const Point &p1, const Point &p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    Point diemA, diemB;
    std::cout << "Nhap toa do diem A:\n";
    nhapDiem(diemA);
    std::cout << "Nhap toa do diem B:\n";
    nhapDiem(diemB);

    double khoangCach = khoangCachEuclidean(diemA, diemB);
    std::cout << "Khoang cach giua hai diem la: " << khoangCach << std::endl;

    return 0;
}