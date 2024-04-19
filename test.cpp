#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class HocSinh {
private:
    std::string MaHS;
    std::string HoTenHS;
    std::string GioiTinhHS;
    std::string DiaChiHS;
    std::string DienThoaiHS;
    std::string EmailHS;
    float DiemTB1;
    float DiemTB2;
    float DiemTBNamHoc;
    std::string XepLoaiHS;

public:
    HocSinh() : MaHS(""), HoTenHS(""), GioiTinhHS(""), DiaChiHS(""), DienThoaiHS(""), EmailHS(""), DiemTB1(0.0), DiemTB2(0.0), DiemTBNamHoc(0.0), XepLoaiHS("") {}

    HocSinh(const std::string& ma, const std::string& ten, const std::string& gioiTinh, const std::string& diaChi, const std::string& dienThoai, const std::string& email, float diem1, float diem2)
        : MaHS(ma), HoTenHS(ten), GioiTinhHS(gioiTinh), DiaChiHS(diaChi), DienThoaiHS(dienThoai), EmailHS(email), DiemTB1(diem1), DiemTB2(diem2) {
        DiemTBNamHoc = (DiemTB1 + DiemTB2) / 2.0;
        XepLoaiHS = getXepLoai();
    }

    ~HocSinh() {}

    void nhapThongTin() {
        std::cout << "Nhap ma so hoc sinh: ";
        std::getline(std::cin, MaHS);
        std::cout << "Nhap ho ten hoc sinh: ";
        std::getline(std::cin, HoTenHS);
        // Tiếp tục với các thuộc tính còn lại
    }

    void xuatThongTin() const {
        std::cout << "Ma so hoc sinh: " << MaHS << std::endl;
        std::cout << "Ho ten hoc sinh: " << HoTenHS << std::endl;
        // Tiếp tục với các thuộc tính còn lại
    }

    std::string getXepLoai() {
        if (DiemTBNamHoc >= 9) return "Xuat sac";
        else if (DiemTBNamHoc >= 8) return "Gioi";
        // Tiếp tục với các điều kiện còn lại
        else return "Kem";
    }

    // Các phương thức truy xuất và cập nhật giá trị của các thuộc tính
    // Ví dụ:
    void setMaHS(const std::string& ma) { MaHS = ma; }
    std::string getMaHS() const { return MaHS; }
    // Tiếp tục với các thuộc tính còn lại
};

class LopHoc {
private:
    std::vector<HocSinh> danhSachHocSinh;
    int Siso;

public:
    LopHoc() : Siso(0) {}

    ~LopHoc() {}

    void nhapThongTinHocSinh() {
        char tiepTuc;
        do {
            HocSinh hs;
            hs.nhapThongTin();
            danhSachHocSinh.push_back(hs);
            Siso++;

            std::cout << "Nhap 'y' de tiep tuc, 'n' de ket thuc: ";
            std::cin >> tiepTuc;
            std::cin.ignore(); // Loại bỏ ký tự xuống dòng còn lại trong luồng đầu vào
        } while (tiepTuc == 'y');
    }

    void xuatThongTinHocSinh() const {
        for (const auto& hs : danhSachHocSinh) {
            hs.xuatThongTin();
        }
    }

    // Các phương thức khác
};

int main() {
    LopHoc lop;
    lop.nhapThongTinHocSinh();
    lop.xuatThongTinHocSinh();
    // Thực hiện các chức năng khác như tìm HS có điểm TB cao nhất, sắp xếp, ...
    return 0;
}