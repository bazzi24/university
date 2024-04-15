#include <iostream>
using namespace std;

class Number{
	private:
		float x;
	public:
		friend istream& operator >> (istream &is, Number &u){
			cout << "nhap:";	is>>u.x;
			return is;
		}
		friend ostream& operator << (ostream &os, Number &u){
			os << u.x;
			return os;
		}
		Number operator+ (Number);
		Number operator- (Number);	
		Number operator* (Number);
		Number operator/ (Number);
		//~Number();
};

Number Number::operator+(Number n){
	Number t;
	t.x = x + n.x;
	return t;
}

Number Number::operator-(Number n){
	Number t;
	t.x = x - n.x;
	return t;
}
Number Number::operator*(Number n){
	Number t;
	t.x = x * n.x;
	return t;
}

Number Number::operator/(Number n){
	Number t;
	t.x = x / (float)n.x;
	return t;
}

int main(){
	Number n, m, cong, tru , nhan, chia;
	cin>>n>>m;
	cout << n << "," << m << endl;
	cong = n + m;
	cout << "Cong = " << cong << endl;
	tru = n - m;
	cout << "Tru =" << tru << endl;
	nhan = n * m;
	cout << "Nhan = " << nhan << endl;
	chia = n / m;
	cout << "Chia = " << chia << endl;
	return 0;
}