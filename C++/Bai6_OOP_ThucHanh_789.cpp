#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

class Shape{
    public:

        virtual double getArea() const{
            return getArea();
        }

        virtual double getPerimeter() const{
            return getPerimeter();
        }

        virtual void input(){}

        virtual void print()const{}
        ~Shape(){}
};

class Circle:public Shape{
    private:
        double radius;
    public:
        Circle(){}
        Circle(const double radius){}
        ~Circle(){}
        double getPerimeter() const override{
            return pi * radius * 2;
        }

        double getArea() const override{
            return pi * radius * radius;
        }

        void input() override{
            cout << "Nhap ban kinh hinh tron: ";        cin >> radius;
        }

        void print() const override{
            cout << "Ban kinh hinh tron la: " << radius << endl;
        }
};

class Rectangle:public Shape{
    private:
        double height;
        double width;
    public:
        Rectangle(){}
        Rectangle(const double height, const double width){}
        ~Rectangle(){}
        double getPerimeter() const override{
            return (height + width) * 2;
        }  

        double getArea() const override{
            return height * width;
        }

        void input(){
            cout << "Chieu dai: ";      cin >> height;
            cout << "Chieu rong: ";     cin >> width; 
        }

        void print() const{
            cout << "Chieu dai: " << height << endl;
            cout << "Chieu rong: " << width << endl;
        }
};



int main(){
        Circle c[100];
        Rectangle r[100];
        int n;
        cout << "Nhap so luong hinh tron muon nhap: ";      cin >> n;
        for(int i = 0; i < n; i++){
            cout << "Nhap hinh tron thu " << i + 1 << endl; 
            c[i].input();
        }

        for(int i = 0; i < n; i++){
            cout << "\n=================================" << endl;
            cout << "Hinh tron thu " << i + 1 << endl;
            c[i].print();
            cout << "Chu vi hinh chu nhat: " << c[i].getPerimeter();
            cout << "\nDien tich hinh chu nhat: " << c[i].getArea();
        }

        int k;
        cout << "\nNhap so luong hinh chu nhat muon nhap: ";  cin >> k;
        for(int i = 0; i < k; i++){
            cout << "Nhap hinh chu nhat thu " << i + 1 << endl;
            r[i].input();
        }

        for(int i = 0; i < k; i++){
            cout << "\n=================================" << endl;
            cout << "Hinh chu nhat thu " << i + 1 << endl;
            r[i].print();
            cout << "Chu vi hinh chu nhat: " << r[i].getPerimeter();
            cout << "\nDien tich hinh chu nhat: " << r[i].getArea();

        }

    return 0;
}