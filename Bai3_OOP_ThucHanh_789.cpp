#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>


using namespace std;

class HocSinh{
    private:
        char maHS[20], hoTenHS[200], gioiTinhHS[10], diaChiHS[200], dienThoaiHS[10], emailHS[50], xepLoaiHS[20];
        float diemTB1, diemTB2, diemTBnamHoc; 
    public:
        //HocSinh(float diemTB1, float diemTB2);
        void input();
        void output();
        float getDiemTB1();
        float getDiemTB2();
        void setDiemTB1(float diemTB1);
        void setDiemTB2(float diemTB2);
        void rating();
        float getDiemTBCaNam()const;
        char getTen();
        //void tbmax();
        //~HocSinh(){}
};

char HocSinh::getTen(){
    cout << hoTenHS;
}
// HocSinh::HocSinh(float diemTB1, float diemTB2){
//     diemTB1 = diemTB2 = 0;
// }

// void HocSinh::tbmax(){
//     int max = 0;
//     for(int i = 0; i < ; i++){
//         if(getDiemTBCaNam(HocSinh* h) < max){
//             max = getDiemTBCaNam(HocSinh* h);
//         }
//     }
//     cout << max;
// }

void HocSinh::input(){
    fflush(stdin);
    cout << "Nhap ma hoc sinh: ";               gets(maHS);
    cout << "Nhap ho va ten hoc sinh: ";        gets(hoTenHS);
    cout << "Gioi tinh: ";                      gets(gioiTinhHS);
    cout << "Nhap dia chi: ";                   gets(diaChiHS);
    cout << "Nhap so dien thoai: ";             gets(dienThoaiHS);
    cout << "Nhap dia chi Email: ";             gets(emailHS);
    cout << "Nhap diem trung binh hoc ky 1: ";  cin >> diemTB1;
    cout << "Nhap diem trung binh hoc ky 2: ";  cin >> diemTB2;
}

void HocSinh::output(){
    cout << "Ma hoc sinh: " << maHS << endl;
    cout << "Ho va ten: " << hoTenHS << endl;
    cout << "Gioi tinh: " << gioiTinhHS << endl;
    cout << "Dia chi: " << diaChiHS << endl;
    cout << "Dia chi Email: " << emailHS << endl;
    cout << "Diem trung binh hoc ky 1: " << diemTB1 << endl;
    cout << "Diem trung binh hoc ki 2: " << diemTB2 << endl;
}

float HocSinh::getDiemTBCaNam() const{
    return (diemTB1 + diemTB2) / 2;
}

float HocSinh::getDiemTB1(){
    return diemTB1;
}

float HocSinh::getDiemTB2(){
    return diemTB2;
}

void HocSinh::setDiemTB1(float diemTB1){
    this->diemTB1 = diemTB1;
}

void HocSinh::setDiemTB2(float diemTB2){
    this->diemTB2 = diemTB2;
}

void HocSinh::rating(){
    diemTBnamHoc = (diemTB1 + diemTB2) / 2;
    cout << diemTBnamHoc << endl;
    if(diemTBnamHoc >= 0 && diemTBnamHoc <= 3.5){
        cout << "Hoc luc kem !";
    }
    else if (diemTBnamHoc < 5)
    {
        cout << "Hoc luc yeu !";
    }
    else if (diemTBnamHoc < 6)
    {
        cout << "Hoc luc trung binh !";
    }
    else if (diemTBnamHoc < 7)
    {
        cout << "Hoc luc trung binh kha !";
    }
else if (diemTBnamHoc < 8)
{
    cout << "Hoc luc kha !";
}
else if (diemTBnamHoc < 9)
{
    cout << "Hoc luc gioi !";
}
else{
    cout << "Hoc luc xuat sac !";
}
}

// CLASS LOP HOC //


class LopHoc:public HocSinh{
    private:
        vector<HocSinh> danhSachHocSinh;
        int siSo;
    public: 
        //~LopHoc(){}
        void inputLophoc();
        void outputLopHoc();
        void findMaxRating(const HocSinh* h);
};

void LopHoc::inputLophoc(){
    char tieptuc;
    do{
        HocSinh hs;
        hs.input();
        danhSachHocSinh.push_back(hs);
        siSo++;
        cout << "Ban co muon nhap them hoc sinh khong? (y/n): ";
        cin >> tieptuc;
        cin.ignore();
    }while(tieptuc == 'y');
}
                      
void LopHoc::outputLopHoc() {
    HocSinh hs;
    for(int i = 0; i < danhSachHocSinh.size(); i++){
        danhSachHocSinh[i].output();
        cout << "Diem trung binh ca nam: " << danhSachHocSinh[i].getDiemTBCaNam() << endl;
    }
}

void LopHoc::findMaxRating(const HocSinh* h){
    
    float max = 0;
    char hihi;
    for(int i = 0; i < danhSachHocSinh.size(); i++){
        if(max < danhSachHocSinh[i].getDiemTBCaNam()){
            max = danhSachHocSinh[i].getDiemTBCaNam();
            hihi = i;
        }
        
    }
    
    cout << "\nHoc sinh co so diem trung binh lon nhat la: "<< danhSachHocSinh[hihi].getTen() << endl;
    cout << "Voi so diem trung binh: " << max;
    
}

int main(){
    LopHoc l;
    
    l.inputLophoc();
    cout << "-----------------------------------------------" << endl;
    l.outputLopHoc();
    cout << "-----------------------------------------------" << endl;
    l.findMaxRating(&l);
    


    return 0;
}