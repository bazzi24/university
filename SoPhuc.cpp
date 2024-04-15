#include <iostream>
using namespace std;

class SoPhuc{
	private:
		double pThuc, pAo;
	public:

		void Nhap(){
			cout << "Nhap phan thuc: ";		cin >> pThuc;
			cout << "Nhap phan ao: ";		cin >> pAo;

		}
		void In(){
			cout << "(" << pThuc << " + i*" << pAo << ")";
		}
		SoPhuc Cong(SoPhuc);
		SoPhuc Tru(SoPhuc);
		SoPhuc Nhan(SoPhuc);
		SoPhuc Chia(SoPhuc);
};

SoPhuc SoPhuc::Cong(SoPhuc p){
	SoPhuc kq;
	kq.pThuc = pThuc + p.pThuc;
	kq.pAo = pAo + p.pAo;
	return kq;
}

SoPhuc SoPhuc::Tru(SoPhuc p){
	SoPhuc kq;
	kq.pThuc = pThuc - p.pThuc;
	kq.pAo = pAo - p.pAo;
	return kq;
}

SoPhuc SoPhuc::Nhan(SoPhuc p){
	SoPhuc kq;
	kq.pThuc = pThuc*p.pThuc - pAo*p.pAo;
	kq.pAo = pThuc*p.pAo + pAo*p.pThuc;
	return kq;
}

SoPhuc SoPhuc::Chia(SoPhuc p){
	SoPhuc kq;
	double mau = p.pThuc*p.pThuc + p.pAo*p.pAo;
	kq.pThuc = (pThuc*p.pThuc + pAo*p.pAo)/mau;
	kq.pAo = (pAo*p.pThuc - pThuc* p.pAo)/mau;
	return kq;
}

int main(){
	SoPhuc st1, st2;
	cout << "Nhap so phuc thu nhat: " << endl;
	st1.Nhap();		cout << "So phuc thu nhat la: ";	st1.In();
	cout << "\nNhap so phuc thu hai " << endl;
	st2.Nhap();		cout << "So phuc thu hai la: ";		st2.In();
	cout << "\nCong:\t ";		 st1.In();		 cout << " + "; 	st2.In(); 	cout << " = ";		st1.Cong(st2).In();
	cout << "\nTru:\t ";		 st1.In();		 cout << " - "; 	st2.In(); 	cout << " = ";		st1.Tru(st2).In();
	cout << "\nNhan:\t ";		 st1.In();		 cout << " * "; 	st2.In(); 	cout << " = ";		st1.Nhan(st2).In();
	cout << "\nChia:\t ";		 st1.In();		 cout << " / "; 	st2.In(); 	cout << " = ";		st1.Chia(st2).In();
	return 0;
}