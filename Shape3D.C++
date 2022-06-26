#include <iostream>
#include <math.h>
using namespace std;
class Shape3D{
    public:
     virtual double area() = 0;
     virtual double volume() = 0;
};
class Cylinder: public Shape3D, public Circle{
    public:
     Cylinder(double a = 0, double b = 0, double c = 1, double h = 1):Circle(a, b, c), high(h){ d++; }
     virtual ~Cylinder(){ d--; cout<<"Cylinder destructor"<<endl; }
     virtual double area(){ return (2*3.14*r*r + 2*3.14*r*high); }
     virtual double volume(){ return 3.14*r*r*high; }
     static int getd();
    private:
     double high;
     static int d;
};
int Cylinder:: d = 0;
int Cylinder:: getd(){ return d; }

class Cone: public Shape3D, public Circle{
    public:
     Cone(double a = 0, double b = 0, double c = 1, double k = 1):Circle(a, b, c), l(k){ f++; }
     virtual ~Cone(){ f--; cout<<"Cone destructor"<<endl; }
     virtual double area(){ return (3.14*r*r + 3.14*r*l); }
     virtual double volume(){ 
         double h = sqrt(l*l - r*r);
         return 3.14*r*r*h; }
     static int getf();
    private:
     double l;
     static int f;
};
int Cone:: f = 0;
int Cone:: getf(){ return f; }

class Rectangular: public Shape3D, public Rectangle{
    public:
     Rectangular(double a = 1, double b = 1, double h = 1):Rectangle(a, b), high(h){ y++; }
     virtual ~Rectangular(){ y--; cout<<"Rectangular destructor"<<endl; }
     virtual double area(){ return 2*length*width + 2*length*high + 2*width*high; }
     virtual double volume(){ return length*width*high; }
     static int gety();
    private:
     double high;
     static int y;
};
int Rectangular:: y = 0;
int Rectangular:: gety(){ return y; }
class prism: public Shape3D, public Triangle{
    public:
     prism(double a = 1, double b = 1, double c = 1, double d = 1):Triangle(a, b, c), prism_high(d){ x++; }
     virtual ~prism(){ x--; cout<<"prism destructor"<<endl; }
     virtual double area(){ return (Triangle:: area()*2 + prism_high*side1 + prism_high*side2 + prism_high*side3); }
     virtual double volume(){ return Triangle:: area()*prism_high; }
     static int getx();
    private:
     double prism_high;
     static int x;
};
int prism:: x = 0;
int prism:: getx(){ return x; }
int main(){
    Cylinder c;
    Rectangular R;
    prism p;
    Shape3D *ptr[3];
    ptr[0] = &c;
    ptr[1] = &R;
    ptr[2] = &p;
    for( int i=0; i<3; i++){
     cout<<ptr[i]->area()<<endl; 
     cout<<ptr[i]->volume()<<endl;
    }
    return 0;
    
}
