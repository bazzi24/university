#include <iostream>
using namespace std;

class Date{
	private:
		int ngay, thang, nam;
	public:
		void nhapp();
		void xuatt();	
};

void Date::nhapp(){
	cout << "Nhap ngay:\t"; 		cin >> ngay;
	cout << "Nhap thang:\t";		cin >> thang;
	cout << "Nhap nam:\t";			cin >> nam;	  
}

void Date::xuatt(){
	cout << "\nNgay: " << ngay << "/" << thang << "/" << nam << endl;
}

class PhieuNhap:public Date{
	private:
		char tenHang[100];
		int soLuong;
	public:
		void nhap();
		void xuat();
		int getSoLuong(){
			return soLuong;
		}
};

void PhieuNhap::nhap(){
	Date::nhapp();
	fflush(stdin);
	cout << "Nhap ten hang:\t"; 		gets(tenHang);
	cout << "Nhap so luong:\t"; 		cin >> soLuong;
}

void PhieuNhap::xuat(){
	Date::xuatt();
	cout << "Ten hang\t" << "So luong\t" << endl;
	cout << tenHang << "\t\t" << soLuong << endl;
}


int main(){
	int n;
	PhieuNhap p[100];
	cout << "Nhap so luong hang hoa can in thong tin: ";		cin >> n;
	for(int i = 0; i < n; i++){
		cout << "Nhap thong tin hang hoa thu " << i + 1 << endl;
		p[i].nhap();
	}
	cout << "============================================================================================================" << endl;
	cout << "THONG TIN HANG HOA VUA NHAP" << endl;
	for(int i = 0; i < n; i++){
		p[i].xuat();
	}
	
	cout << "\n============================================================================================================" << endl;
	cout << "HANG HOA CO SO LUONG TREN 100" << endl;
	for(int i = 0; i < n; i++){
		if(p[i].getSoLuong() >= 100){
			p[i].xuat();
		}
	}
	
	return 0;
}
