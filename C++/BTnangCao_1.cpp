#include <bits/stdc++.h>
using namespace std;

class Vemaybay{
    private:
        string tenChuyen;
        int date, month, year;
        int giaVe;
    public:
        Vemaybay(){}
        Vemaybay(const string tenChuyen, const int ngayBay, const int giaVe){}
        ~Vemaybay(){}
        void input(){
            fflush(stdin);
            cout << "Nhap ten chuyen: ";        getline(cin, tenChuyen);
            cout << "Nhap ngay: ";              cin >> date;
            cout << "Nhap thang: ";             cin >> month;
            cout << "Nhap nam: ";               cin >> year;
            cout << "Nhap gia ve: ";            cin >> giaVe;
        }

        void print()const {
            cout << "Ten chuyen: " << tenChuyen << endl;
            cout << "Ngay khoi hanh: " << date << "/" << month << "/" << year << endl;
            cout << "Gia ve: " << giaVe << endl;
        }

        int getGiaVe(){
            return giaVe;
        }
};

class Nguoi{
    private:
        string hoTen;
        string gioiTinh;
        int tuoi;
    public:
        Nguoi(){}
        Nguoi(const string hoTen, const string gioiTinh, const int tuoi){}
        ~Nguoi(){}
        void input(){
            fflush(stdin);
            
            cout << "Nhap ho ten hanh khach: ";         getline(cin, hoTen);
            cout << "Nhap gioi tinh: ";                 getline(cin, gioiTinh);
            cout << "Nhap tuoi: ";                      cin >> tuoi;
        }

        void print()const{
            cout << "Ho ten hanh khach: " << hoTen << endl;
            cout << "Gioi tinh: " << gioiTinh << endl;
            cout << "Tuoi: " << tuoi << endl;
        }

};

class HanhKhach:public Nguoi{
    private:
        Vemaybay v[1000];
        int soLuong;
        int tongTien;
    public:
        HanhKhach(){}
        ~HanhKhach(){}
        void input(){
            Nguoi::input();
            cout << "Nhap so luong ve hanh khach da mua:";      cin >> soLuong;
            for(int i = 0; i < soLuong; i++){
                v[i].input();
                tongTien += v[i].getGiaVe();
            }
        }
        
        void print()const {
            cout << "THONG TIN KHACH HANG" << endl;
            Nguoi::print();
            cout << "THONG TIN CHUYEN BAY" << endl;
            for(int i = 0; i < soLuong; i++){
                v[i].print();
            }
            cout << "===> Tong tien: " << tongTien << endl;
        }

        
};

int main(){
    HanhKhach k[10];
    int p;
    cout << "Nhap so luong hanh khach: ";
    cin >> p;
    
    for(int i = 0; i < p; i++){
        k[i].input();
    }

    cout << "==================================" << endl;

    for(int i = 0; i < p; i++){
        k[i].print();
        cout << endl;
    }

    return 0;
}