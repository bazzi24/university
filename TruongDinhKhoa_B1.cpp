#include <iostream>
using namespace std;

class Person{
	private:
		char hoTen[100], gioiTinh[5];
		int ngay, thang, nam;
	public:
		void nhapp();
		void xuatt();
};
	void Person::nhapp(){
		fflush(stdin);
		cout << "Nhap ho ten:\t";	 	gets(hoTen);
		cout << "Gioi tinh:\t";		 	gets(gioiTinh);
		cout << "Nhap ngay sinh:\t"; 	cin >> ngay;
		cout << "Nhap thang:\t";		cin >> thang;
		cout << "Nhap nam:\t";			cin >> nam;	 
	}
	
	void Person::xuatt(){
		cout << "Ho ten:\t\t" << hoTen << endl;
		cout << "Gioi tinh:\t" << gioiTinh << endl;
		cout << "Ngay sinh:\t" << ngay << "/" << thang << "/" << nam << endl;
	}
	
	class Student:public Person{
		private:
			char lop[20];
			float diemThi;
		public:	
			float getDiemThi(){
				return diemThi;
			}
			void nhap(){
				Person::nhapp();
				fflush(stdin);
				cout << "Lop:\t\t";		gets(lop);
				cout << "Diem thi:\t";	cin >> diemThi;
			}
			void xuat(){
				Person::xuatt();
				cout << "Lop:\t\t" << lop << endl;
				cout << "Diem thi:\t" << diemThi << endl;
			}
	};
	

int main(){
	int n;
	Student ds[100];
	cout << "Nhap so luong sinh vien can in thong tin: ";		cin >> n;
	for(int i = 0; i < n; i++){
		cout << "Nhap thong tin cho sinh vien thu " << i + 1 << endl;
		ds[i].nhap();
	}
	cout << "=========================================================================================" << endl;
	cout << "THONG TIN SINH VIEN VUA NHAP" << endl;
	for(int i = 0; i < n; i++){
		ds[i].xuat();
	}
	cout <<"=========================================================================================" << endl;
	cout << "SAP XEP DANH SACH DIEM THI GIAM DAN" << endl;
	Student st;
	for(int i = 0; i < n; i++){
		for(int j =  i + 1; j < n; j++){
			if(ds[i].getDiemThi() < ds[j].getDiemThi()){
				st = ds[i];
				ds[i] = ds[j];
				ds[j] = st;
			}
		}
		
	}
	
	for(int i = 0; i < n; i++){
		ds[i].xuat();
	}
	
	return 0;
}
