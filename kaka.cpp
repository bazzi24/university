#include <iostream>
using namespace std;

class Diem{
	private:
		double x, y;
	public:
		//Diem(double x = 0, double y = 0);
		friend istream& operator >> (istream &is, Diem &u){
			cout << "Nhap: "; is >> u.x;
			cout << "Nhap: "; is >> u.y;
		}
		
		friend ostream& operator << (ostream &os, Diem &u){
			cout << u.x;
			cout << u.y;
		}
		
		
};

int main(){
	Diem p1, p2, p3;
	cin >> p1>>p2>>p3;
	cout << p1<<p2<<p3;
	
	return 0;
}