#include <iostream>
#include <cmath>
#define PI 3.14159 
using namespace std;

class Diem2D{
    private:
        double x, y;
    public:
        Diem2D(double x = 0, double y = 0);
        int getX();
        int getY();
        void setX(int x);
        void setY(int y);
        void input();
        void output();
        double distance(Diem2D& u);
        //~Diem2D();
};

Diem2D::Diem2D(double x, double y){
    x = y = 0;
}

int Diem2D::getX(){
    return x;
}

int Diem2D::getY(){
    return y;
}

void Diem2D::setX(int x){
    this->x = x;
}

void Diem2D::setY(int y){
    this->y= y;
}

void Diem2D::input(){
    cout << "Enter x coordinates: ";      cin >> x;
    cout << "Enter y coordinates: ";      cin >> y;
}

void Diem2D::output(){
    cout << "(" << x << "," << y << ")" << endl;
}

double Diem2D::distance(Diem2D& u){
    return sqrt(pow(x - u.x, 2) + pow(y - u.y, 2));
}

class HinhTron{
    private:
        Diem2D tam;
        double banKinh;
    public:
        //HinhTron(Diem2D& tam, double banKinh);
        void input();
        void output();
        double circumference(HinhTron& u);
        double area(HinhTron& u);
        //~HinhTron();
};

void HinhTron::input(){
    cout << "Enter center of circle:\n";        tam.input();
    cout << "Enter radius:";                    cin >> banKinh;
}

void HinhTron::output(){
    cout << "Center of circle: "; tam.output();
    cout << "Radius: " << banKinh;
}

double HinhTron::circumference(HinhTron& u){
    return 2*PI*banKinh;
}

double HinhTron::area(HinhTron& u){
    return PI*banKinh;
}

class TamGiac{
private:
    Diem2D d1, d2, d3 ;
public:
    //TamGiac(Diem2D& d1, Diem2D& d2, Diem2D& d3);
    void input();
    void output(); 
    double circumfence();
    double area();
    //~ TamGiac();
};

void TamGiac::input(){
    cout << "Enter first coordinates: ";        
    d1.input();
    cout << "Enter second coordinates: ";       
    d2.input();
    cout << "Enter third coordinates: ";        
    d3.input();
}

void TamGiac::output(){
    cout << "First coordinates: ";      d1.output();
    cout << "Second coordinates: ";      d2.output();
    cout << "Third coordinates: ";      d3.output();
}
double TamGiac::circumfence(){
    return d1.distance(d2) + d2.distance(d3) + d3.distance(d1);
}

double TamGiac::area(){
    double p = circumfence() / 2;
    double t1 = d1.distance(d2);
    double t2 = d2.distance(d3);
    double t3 = d3.distance(d1);
    return sqrt(p * (p - t1) * (p - t2) * (p - t3));
}

int main(){
    HinhTron ht;
    ht.input();     ht.output();
    cout << "Circumference: " << ht.circumference(ht) << endl;
    cout << "Area: " << ht.area(ht) << endl;

    TamGiac tg;
    tg.input();     tg.output();
    cout << "Circumference: " << tg.circumfence() << endl;
    cout << "Area: " << tg.area() << endl;
    return 0;
}