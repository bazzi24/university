#include <iostream>
#include <cmath>
using namespace std;

class Diem{
	private:
		double x, y;
	public:
		Diem(double x = 0, double y = 0);
		friend istream& operator >> (istream &is, Diem &u);
		friend ostream& operator << (ostream &os, Diem &u);
        double khoangCach(Diem u);
        double dienTich(Diem u, Diem v);
        double chuVi(Diem u, Diem v);
        //~Diem();
};

Diem::Diem(double x, double y){
    this->x = x;
    this->y = y;
}

istream& operator >> (istream &is, Diem &u){
    cout << "Nhap toa do x: "; is >> u.x;
    cout << "Nhap toa do y: "; is >> u.y;
    return is;
}

ostream&  operator<< (ostream &os, Diem &u){
    os << "(" << u.x << "," << u.y << ")" << endl;
    return os;
} 

double Diem::khoangCach(Diem u){
    return sqrt((x - u.x) * (x - u.x) + (y - u.y) * (y - u.y));
}

double Diem::chuVi(Diem a, Diem b){
    return khoangCach(a) + khoangCach(b) + a.khoangCach(b);
}

double Diem::dienTich(Diem a, Diem b){
    double p = chuVi(a,b) / 2;
    return sqrt(p * (p - khoangCach(a)) * (p - khoangCach(b)) * (p - a.khoangCach(b)));
}

int main(){
	Diem p1, p2, p3;
	cout << "Nhap toa do thu nhat " << endl;; cin >> p1;
    cout << "Nhap toa do thu hai " << endl; cin >> p2;
    cout << "Nhap toa do thu ba " << endl; cin >> p3;
    cout << "Chu vi cua ba diem tren la: " << p1.chuVi(p2,p3) << endl;
    cout << "Dien tich cua ba diem tren la: " << p1.dienTich(p2,p3) << endl;
    cout << "Chu vi + dien tich = " << p1.chuVi(p2,p3) + p1.dienTich(p2,p3) << endl;
	return 0;
}