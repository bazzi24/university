#include <bits/stdc++.h>
using namespace std;

class ThiSinh{
    private:
        string SoBaoDanh;
        string HoTen;
        string GioiTinh;
        int KhuVuc;
    public:
        ThiSinh(){}

        ThiSinh(const string SoBaoDanh, const string HoTen, const string GioiTinh, const int KhuVuc){}

        ThiSinh(const ThiSinh& t) : SoBaoDanh(t.SoBaoDanh), HoTen(t.HoTen), GioiTinh(t.GioiTinh), KhuVuc(t.KhuVuc){}

        ~ThiSinh(){}

        void input(){
            cout << "Nhap so bao danh: ";        getline(cin, SoBaoDanh);
            cout << "Nhap ho ten thi sinh: ";   getline(cin, HoTen);
            cout << "Nhap gioi tinh: ";         getline(cin, GioiTinh);
            cout << "Nhap khu vuc: ";           cin >> KhuVuc;
        }

        void print() const{
            cout << "So bao danh: " << SoBaoDanh << endl;
            cout << "Ho ten thi sinh: " << HoTen <<endl;
            cout << "Gioi tinh: " << GioiTinh << endl;
            cout << "Khu vuc: " << KhuVuc << endl;
        }

        friend istream& operator>>(istream& is, ThiSinh& t){
            t.input();
            return is;
        }

        friend ostream& operator<<(ostream& os, ThiSinh& t){
            t.print();
            return os;
        }

        virtual float tongDiem() const{
            return tongDiem();
        }

        virtual void check() const{}

        virtual void xetTuyen() const{}
};

class ThiSinhKhoiA:public ThiSinh{
    private:
        float diemMon1; // toan
        float diemMon2; // ly
        float diemMon3; // hoa
    public:
        ThiSinhKhoiA(){}

        ThiSinhKhoiA(const float diemMon1, const float diemMon2, const float diemMon3){}

        ThiSinhKhoiA(ThiSinhKhoiA& t) : diemMon1(t.diemMon1), diemMon2(t.diemMon2), diemMon3(t.diemMon3){}

        ~ThiSinhKhoiA(){}

        float getDiemMonToan(){
            return diemMon1;
        }

        float getDiemMonLy(){
            return diemMon2;
        }

        float getDiemMonHoa(){
            return diemMon3;
        }

        void setDiemMonToan(float diemMon1){
            this->diemMon1 = diemMon1;
        }

        void setDiemMonLy(float diemMon2){
            this->diemMon2 = diemMon2;
        }

        void setDiemMonHoa(float diemMon3){
            this->diemMon3 = diemMon3;
        }

        void input(){
            ThiSinh::input();
            cout << "Nhap diem mon Toan: ";         cin >> diemMon1;
            cout << "Nhap diem mon Ly: ";           cin >> diemMon2;
            cout << "Nhap diem mon Hoa: ";          cin >> diemMon3;
        }

        void print() const{
            ThiSinh::print();
            cout << "Diem Toan: " << diemMon1 << endl;
            cout << "Diem mon Ly: " << diemMon2 << endl;
            cout << "Diem mon Hoa: " << diemMon3 <<  endl;
        }

        friend istream& operator>>(istream& is, ThiSinhKhoiA& t){
            t.input();
            return is;
        }

        friend ostream& operator<<(ostream& os, ThiSinhKhoiA& t){
            t.print();
            return os;
        }

    float tongDiem() const override{
        return diemMon1 + diemMon2 + diemMon3;
    }

    void check()const override{
        if(diemMon1 == 0 || diemMon2 == 0 || diemMon3 == 0){
            cout << "Ban da bi diem liet ! " << endl;
        }
        else if(diemMon1 > 0 && diemMon2 > 0 && diemMon3 > 0){
            cout << "Ban da tren diem liet !" << endl;
        }
    }    

    void xetTuyen()const override{
        if(ThiSinhKhoiA::tongDiem() > 15 && (diemMon1 > 0 && diemMon2 > 0 && diemMon3)){
            cout << "Ban da dau ! Congratulations !" << endl;
        }
        else if(ThiSinhKhoiA::tongDiem() > 15 && (diemMon1 == 0 || diemMon2 == 0 || diemMon3 == 0)){
            cout << "Ban du diem dau nhung da bi diem liet !" <<endl;
        }
        else if(ThiSinhKhoiA::tongDiem() < 15){
            cout << "Ban khong du diem !";
        }
    }

};

class ThiSinhKhoiB:public ThiSinh{
    private:
        float diemMon1; // toan
        float diemMon2; // sinh
        float diemMon3; // hoa
    public:
        ThiSinhKhoiB(){}

        ThiSinhKhoiB(const float diemMon1, const float diemMon2, const float diemMon3){}

        ThiSinhKhoiB(ThiSinhKhoiB& t) : diemMon1(t.diemMon1), diemMon2(t.diemMon2), diemMon3(t.diemMon3){}

        ~ThiSinhKhoiB(){}

        float getDiemMonToan(){
            return diemMon1;
        }
        
        float getDiemMonSinh(){
            return diemMon2;
        }

        float getDiemMonHoa(){
            return diemMon3;
        }

        void setDiemMonToan(float diemMon1){
            this->diemMon1 = diemMon1;
        }

        void setDiemMonSinh(float diemMon2){
            this->diemMon2 = diemMon2;
        }

        void setDiemMonHoa(float diemMon3){
            this->diemMon3 = diemMon3;
        }

        void input(){
            ThiSinh::input();
            cout << "Nhap diem mon Toan: ";             cin >> diemMon1;
            cout << "Nhap diem mon Sinh: ";             cin >> diemMon2;
            cout << "Nhap diem mon Hoa: ";              cin >> diemMon3;
        }

        void print()const{
            ThiSinh::print();
            cout << "Diem Toan: " << diemMon1 << endl;
            cout << "Diem Sinh: " << diemMon2 << endl;
            cout << "Diem Hoa: " << diemMon3 << endl;
        }

        friend istream& operator>>(istream& is, ThiSinhKhoiB& t){
            t.input();
            return is;
        }

        friend ostream& operator<<(ostream& os, ThiSinhKhoiB& t){
            t.print();
            return os;
        }

    float tongDiem() const override{
        return diemMon1 + diemMon2 + diemMon3;
    }

    void check()const override{
        if(diemMon1 == 0 || diemMon2 == 0 || diemMon3 == 0){
            cout << "Ban da bi diem liet ! " << endl;
        }
        else if(diemMon1 > 0 && diemMon2 > 0 && diemMon3 > 0){
            cout << "Ban da tren diem liet !" << endl;
        }
    }    

    void xetTuyen()const override{
        if(ThiSinhKhoiB::tongDiem() > 15 && (diemMon1 > 0 && diemMon2 > 0 && diemMon3)){
            cout << "Ban da dau ! Congratulations !" << endl;
        }
        else if(ThiSinhKhoiB::tongDiem() > 15 && (diemMon1 == 0 || diemMon2 == 0 || diemMon3 == 0)){
            cout << "Ban du diem dau nhung da bi diem liet !" <<endl;
        }
        else if(ThiSinhKhoiB::tongDiem() < 15){
            cout << "Ban khong du diem !";
        }
    }
};

class ThiSinhKhoiC:public ThiSinh{
    private:
        float diemMon1; //su
        float diemMon2; //van
        float diemMon3; //dia
    public:
        ThiSinhKhoiC(){}
        ThiSinhKhoiC(const float diemMon1, const float diemMon2, const float diemMon3){}
        ThiSinhKhoiC(ThiSinhKhoiC& t) : diemMon1(t.diemMon1), diemMon2(t.diemMon2), diemMon3(t.diemMon3){}
        ~ThiSinhKhoiC(){}
        float getDiemMonSu(){
            return diemMon1;
        }

        float getDiemMonVan(){
            return diemMon2;
        }

        float getDiemMonDia(){
            return diemMon3;
        }

        void setDiemMonSu(float diemMon1){
            this->diemMon1 = diemMon1;
        }

        void setDiemMonVan(float diemMon2){
            this->diemMon2 = diemMon2;
        }

        void setDiemMonDia(float diemMon3){
            this->diemMon3 = diemMon3;
        }

        void input(){
            ThiSinh::input();
            cout << "Nhap diem mon Su: ";           cin >> diemMon1;
            cout << "Nhap diem mon Van: ";          cin >> diemMon2;
            cout << "Nhap diem mon Dia: ";          cin >> diemMon3;
        }

        void print()const{
            ThiSinh::print();
            cout << "Diem Su: " << diemMon1 << endl;
            cout << "Diem mon Van: " << diemMon2 << endl;
            cout << "Diem mon Dia: " << diemMon3 << endl;
        }

        friend istream& operator>>(istream& is, ThiSinhKhoiC& t){
            t.input();
            return is;
        }

        friend ostream& operator<<(ostream& os, ThiSinhKhoiC& t){
            t.print();
            return os;
        }

    float tongDiem() const override{
        return diemMon1 + diemMon2 + diemMon3;
    }

    void check()const override{
        if(diemMon1 == 0 || diemMon2 == 0 || diemMon3 == 0){
            cout << "Ban da bi diem liet ! " << endl;
        }
        else if(diemMon1 > 0 && diemMon2 > 0 && diemMon3 > 0){
            cout << "Ban da tren diem liet !" << endl;
        }
    }    

    void xetTuyen()const override{
        if(ThiSinhKhoiC::tongDiem() > 15 && (diemMon1 > 0 && diemMon2 > 0 && diemMon3)){
            cout << "Ban da dau ! Congratulations !" << endl;
        }
        else if(ThiSinhKhoiC::tongDiem() > 15 && (diemMon1 == 0 || diemMon2 == 0 || diemMon3 == 0)){
            cout << "Ban du diem dau nhung da bi diem liet !" <<endl;
        }
        else if(ThiSinhKhoiC::tongDiem() < 15){
            cout << "Ban khong du diem !";
        }
    }
};



class ThiSinhKhoiD:public ThiSinh{
    private:
        float diemMon1; // toan
        float diemMon2; // van
        float diemMon3; // anh van
    public:
        ThiSinhKhoiD(){}

        ThiSinhKhoiD(const float diemMon1, const float diemMon2, const float diemMon3){}

        ThiSinhKhoiD(ThiSinhKhoiD& t) : diemMon1(t.diemMon1), diemMon2(t.diemMon2), diemMon3(t.diemMon3){}

        ~ThiSinhKhoiD(){}

        float getDiemMonToan(){
            return diemMon1;
        }

        float getDiemMonVan(){
            return diemMon2;
        }

        float getDiemMonAnhVan(){
            return diemMon3;
        }

        void setDiemMonToan(float diemMon1){
            this->diemMon1 = diemMon1;
        }

        void setDiemMonVan(float diemMon2){
            this->diemMon2 = diemMon2;
        }

        void setDiemMonAnhVan(float diemMon3){
            this->diemMon3 = diemMon3;
        }

        void input(){
            ThiSinh::input();
            cout << "Nhap diem mon Toan: ";         cin >> diemMon1;
            cout << "Nhap diem mon Van: ";          cin >> diemMon2;
            cout << "Nhap mon Anh Van: ";           cin >> diemMon3;
        }

        void print() const{
            ThiSinh::print();
            cout << "Diem mon Toan: " << diemMon1 << endl;
            cout << "Diem mon Van: " << diemMon2 << endl;
            cout << "Diem mon Anh Van: " << diemMon3 << endl;
        }

        friend istream& operator>>(istream& is, ThiSinhKhoiD& t){
            t.input();
            return is;
        }

        friend ostream& operator<<(ostream& os, ThiSinhKhoiD& t){
            t.print();
            return os;
        }

    float tongDiem() const override{
        return diemMon1 + diemMon2 + diemMon3;
    }

    void check()const override{
        if(diemMon1 == 0 || diemMon2 == 0 || diemMon3 == 0){
            cout << "Ban da bi diem liet ! " << endl;
        }
        else if(diemMon1 > 0 && diemMon2 > 0 && diemMon3 > 0){
            cout << "Ban da tren diem liet !" << endl;
        }
    }    

    void xetTuyen()const override{
        if(ThiSinhKhoiD::tongDiem() > 15 && (diemMon1 > 0 && diemMon2 > 0 && diemMon3)){
            cout << "Ban da dau ! Congratulations !" << endl;
        }
        else if(ThiSinhKhoiD::tongDiem() > 15 && (diemMon1 == 0 || diemMon2 == 0 || diemMon3 == 0)){
            cout << "Ban du diem dau nhung da bi diem liet !" <<endl;
        }
        else if(ThiSinhKhoiD::tongDiem() < 15){
            cout << "Ban khong du diem !";
        }
    }
};


int main(){
    ThiSinhKhoiD la;
    la.input();
    cout << "=====================================" << endl;
    la.print();
    cout << "=====================================" << endl;
    cout << "Tong diem: " << la.tongDiem() << endl;
    cout << "Ket qua diem liet: " ; la.check();
    cout << "Ket qua xet tuyen: "; la.xetTuyen();
    return 0;
}