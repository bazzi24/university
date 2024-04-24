#include <iostream>
#include <string>

using namespace std;

class NhanVien{
    private:
        string MaNV;
        string HoTenNV;
    public:
        // khoi tao khong tham so
        NhanVien() : MaNV(""), HoTenNV(""){}
        // khoi tao voi 2 tham so
        NhanVien(const string& MaNV, const string& HoTenNV){}
        // khoi tao sao chep
        NhanVien(const NhanVien& n) : MaNV(n.MaNV), HoTenNV(n.HoTenNV){}
        // ham ao dung virtual
        virtual ~NhanVien(){}

        virtual void nhap(){
            cout << "Nhap ma nhan vien: ";              getline(cin, MaNV);
            cout << "\nNhap ho ten nhan vien: ";          getline(cin, HoTenNV);
        }

        virtual void xuat() {
            cout << "Ma nhan vien: " << MaNV << endl;
            cout << "Ho ten nhan vien:" << HoTenNV << endl;
        }

        friend istream& operator>>(istream& is, NhanVien& n){
            n.nhap();
            return is;
        }

        friend  ostream& operator<<(ostream& os, NhanVien& n){
            n.xuat();
            return os;
        }

        virtual float tinhLuong() const{
            return tinhLuong();
        }

        void setMaNV(string MaNV){
            this->MaNV = MaNV;
        }

        void setHoTenNV(string HoTenNV){
            this->HoTenNV = HoTenNV;
        }

        string getMaNV(){
            return MaNV;
        }

        string getHoTenNV(){
            return HoTenNV;
        }
};


class NhanVienVanPhong:public NhanVien{
    private:
        float MucLuong;
        float HeSoLuong;
        float PhuCap;
    public:
        NhanVienVanPhong(){}
        NhanVienVanPhong(const float MucLuong, const float HeSoLuong,  const float PhuCap){}
        // khoi tao sao chep
        NhanVienVanPhong(const NhanVienVanPhong& n) : MucLuong(n.MucLuong), HeSoLuong(n.HeSoLuong), PhuCap(n.PhuCap){}
        ~NhanVienVanPhong(){}
        void nhap() override{
            NhanVien::nhap();
            cout << "Nhap muc luong: ";     cin >> MucLuong;
            cout << "Nhap he so luong: ";   cin >> HeSoLuong;
            cout << "Nhap phu cap: ";       cin >> PhuCap;
        }

        void xuat()  override{
            NhanVien::xuat();
            cout << "Muc luong: " << MucLuong << endl;
            cout << "He so luong:" << HeSoLuong << endl;
            cout << "Phu cap: " << PhuCap << endl;
        }

        friend istream& operator>>(istream& is, NhanVienVanPhong& np){
            np.nhap();
            return is;
        }

        friend ostream& operator<<(ostream& os, NhanVienVanPhong& np){
            np.xuat();
            return os;
        }

        float tinhLuong()const override{
            return (MucLuong * HeSoLuong) + PhuCap;
        }

        
};

class NhanVienSanXuat:public NhanVienVanPhong{
    private:
        int SoSanPham; // so san pham san xuat trong 1 thang
        float PhuCapDocHai; // so tien phu cap doc hai duoc cap them moi thang
    
    public:
        NhanVienSanXuat(){}
        NhanVienSanXuat(const int SoSanPham, const float PhuCapDocHai){}
        // khoi tao sao chep
        NhanVienSanXuat(NhanVienSanXuat& n) : SoSanPham(n.SoSanPham), PhuCapDocHai(n.PhuCapDocHai){}
        ~NhanVienSanXuat(){}
        void nhap() override{
            NhanVienVanPhong::nhap();
            cout << "Nhap so luong san pham san xuat duoc: ";       cin >> SoSanPham;
            cout << "Nhap so phu cap do hai: ";                     cin >> PhuCapDocHai;
        }

        void xuat()  override{
            NhanVienVanPhong::xuat();
            cout << "So luong san pham lam duoc trong 1 thang: " << SoSanPham << endl;
            cout << "So phu cap doc hai: " << PhuCapDocHai << endl;
        }

        friend istream& operator>>(istream& is, NhanVienSanXuat& np){
            np.nhap();
            return is;
        }

        friend ostream& operator<<(ostream& os, NhanVienSanXuat& np){
            np.xuat();
            return os;
        }

        float tinhLuong(){
            return NhanVienVanPhong::tinhLuong() + PhuCapDocHai;
        }
};

class NhanVienBanHang:public NhanVienVanPhong{
    private:
        int SoSanPham; // so san pham ban duoc trong 1 thang
        float HoaHong; // la so tien cong ty tra cho 1 san pham 
    public:
        NhanVienBanHang(){}
        NhanVienBanHang(const int SoSanPham, const float HoaHong){}
        //khoi tao sao chep
        NhanVienBanHang(NhanVienBanHang& n) : SoSanPham(n.SoSanPham), HoaHong(n.HoaHong){}
        ~NhanVienBanHang(){}
        void nhap() override{
            NhanVienVanPhong::nhap();
            cout << "So san pham ban duoc trong 1 thang: ";         cin >> SoSanPham;
            cout << "So tien hoa hong: ";                           cin >> HoaHong;
        }

        void xuat() override{
            NhanVienVanPhong::xuat();
            cout << "So san pham lam duoc trong 1 thang: " << SoSanPham << endl;
            cout << "So tien hoa hong: " << HoaHong << endl;
        }

        friend istream& operator>>(istream& is, NhanVienBanHang& np){
            np.nhap();
            return is;
        }

        friend ostream& operator<<(ostream& os, NhanVienBanHang& np){
            np.xuat();
            return os;
        }

        float tinhLuong(){
            return NhanVienVanPhong::tinhLuong() + HoaHong;
        }

};



int main(){
    NhanVienSanXuat sx[100];
    NhanVienVanPhong vp[100];
    NhanVienBanHang bh[100];

    int n;
    cout << "Nhap so luong nhan vien: ";        cin >> n;
    int k;
    cout << "Ban muon nhap cho nhan vien nao ?" << endl;
    menu: cout << "Vui long nhap: ";                  cin >> k;
    if(k == 1){
        for(int i = 0; i < n; i++){
            vp[i].nhap();
        }
        cout << "======================================" << endl;
        for(int i = 0; i < n; i++){
            vp[i].xuat();
            cout << "Luong: " << vp[i].tinhLuong() << endl;
        }
    }

    else if(k == 2){
        for(int i = 0; i < n; i++){
            sx[i].nhap();
        }
        cout << "======================================" << endl;
        for(int i = 0; i < n; i++){
            sx[i].xuat();
            cout << "Luong: " << sx[i].tinhLuong() << endl;
        }
    }

    else if(k == 3){
        for(int i = 0; i < n ; i++){
            bh[i].nhap();
        }
        cout << "======================================" << endl;
        for(int i = 0; i < n; i++){
            bh[i].xuat();
            cout << "Luong: " << bh[i].tinhLuong() << endl;
        }
    }

    else{
        cout << "Khong hop le ! " << endl;
        goto menu;
    }

    return 0;
}