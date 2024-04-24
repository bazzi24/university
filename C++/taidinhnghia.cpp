#include <iostream>
using namespace std;

class SoPhuc{
	private:
		double pThuc, pAo;
	public:
        SoPhuc(double pThuc = 0, double pAo = 0);
		friend istream& operator>> (istream& is, SoPhuc& p);
        friend ostream& operator<< (ostream& os, SoPhuc& p);
        void In(){
            cout << "(" << pThuc << " + i*" << pAo << ")";
        }
		SoPhuc Cong(SoPhuc);
		SoPhuc Tru(SoPhuc);
		SoPhuc Nhan(SoPhuc);
		SoPhuc Chia(SoPhuc);
        //~SoPhuc();
};

SoPhuc::SoPhuc(double pThuc, double pAo){
    this->pThuc = pThuc;
    this->pAo = pAo;
}

istream& operator>> (istream& is, SoPhuc& p){
    cout << "Nhap phan thuc: ";      is >> p.pThuc;
    cout << "Nhap phan ao: ";        is >> p.pAo;
    return is;
}

ostream& operator<< (ostream& os, SoPhuc& p){
    os << "(" << p.pThuc << " + i*" << p.pAo << ")";
    return os;
}



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
	SoPhuc st1, st2, cong, tru, nhan, chia;
	cout << "Nhap so phuc thu nhat " << endl;       cin >> st1;
	cout << "\nNhap so phuc thu hai " << endl;      cin >> st2;
    cong = st1.Cong(st2);
    tru = st1.Tru(st2);
    nhan = st1.Nhan(st2);
    chia = st1.Chia(st2);
    cout << "Cong:\t" << st1 << " + " << st2 << " = " << cong << endl;
    cout << "Tru:\t" << st1 << " - " << st2 << " = " << tru << endl;
    cout << "Nhan:\t" << st1 << " * " << st2 << " = " << nhan << endl;
    cout << "Chia:\t" << st1 << " / " << st2 << " = " << chia << endl;
    return 0;
}