#include <iostream>
#include <math.h>
using namespace std;
class Shape2D{
    public:
      virtual double area() = 0;
      virtual double perimetre() = 0;
};
class Circle: public Shape2D{
    public:
     Circle(double a = 0, double b = 0, double c = 1):x(a), y(b), r(c){ k++; }
     Circle(const Circle& g):x(g.x), y(g.y), r(g.r){ k++; }
     virtual ~Circle(){  k--; cout<<"Circle destructor"<<endl; }
     virtual double area(){ return 3.14*r*r; }
     virtual double perimetre(){ return 2*3.14*r; }
     static int getk();
    protected:
     double x, y, r;
    private:
     static int k;
};
 int Circle:: k = 0;
 int Circle:: getk(){ return k; }

class Rectangle: public Shape2D{
    public:
     Rectangle(double a = 1, double b = 1):length(a), width(b){ l++; }
     Rectangle(const Rectangle& b):length(b.length), width(b.width){ l++; }
     virtual ~Rectangle(){  l--; cout<<"Rectangle destructor"<<endl; }
     virtual double area(){ return length*width; }
     virtual double perimetre(){ return 2*length + 2*width; }
     static int getl();
     Rectangle operator+(const Rectangle& b)const{
          Rectangle c;
          c.length = length + b.length;
          c.width = width + b.width;
          return c; }
     protected:
      double length, width;
     private:
      static int l;
};
int Rectangle:: l = 0;
int Rectangle:: getl(){ return l; }

class Triangle: public Shape2D{
    public:
     Triangle(double a = 1, double b = 1, double c = 1):side1(a), side2(b), side3(c){ h++; }
     Triangle(const Triangle& k):side1(k.side1), side2(k.side2), side3(k.side3){ h++; }
     virtual ~Triangle(){  h--; cout<<"triangle destructor"<<endl; }
     virtual double perimetre(){ return side1 + side2 + side3; }
     virtual double area(){ 
        double p = perimetre() / 2;
        double s = sqrt(p*(p - side1)*(p - side2)*(p - side3));
        return s; }
     static int geth(); 
    protected:
     double side1, side2, side3;
    private:
     static int h;
};
int Triangle:: h = 0;
int Triangle:: geth(){ return h; }

int main(){
    Circle c;
    Rectangle R;
    Triangle T;
    Shape2D *ptr[3];
    ptr[0] = &c;
    ptr[1] = &R;
    ptr[2] = &T;
    for( int i=0; i<3; i++){
     cout<<ptr[i]->area()<<endl; 
     cout<<ptr[i]->perimetre()<<endl;
    }
    return 0;
    
}
