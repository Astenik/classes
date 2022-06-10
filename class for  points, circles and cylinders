#include <iostream>
using namespace std;
class point1{
    public:
    point1(double=0, double=0);
   ~point1();
 void setpoint(double, double);
 double getx();
 double gety();
 void print();
 protected:
  double x;
  double y;
};
point1:: point1(double a, double b){
    setpoint(a,b);
}
point1:: ~point1(){
    cout<<"point destructor"<<endl;
}
void point1:: setpoint(double a, double b){
    x=a;
    y=b;
}
double point1:: getx(){
    return x;
}
double point1:: gety(){
    return y;
}
void point1:: print(){
    cout<<"("<<x<<";"<<y<<")"<<endl;
}
class circle: public point1{
    public:
    circle(double=0, double=0, double=1);
   ~circle();
   void setr(double);
   double getr();
   double area();
   double length();
   void print();
   protected:
   double r;
};
circle:: circle(double a, double b, double c):point1(a, b){
    r=c;
}
circle::~circle(){
    cout<<"circle destructor"<<endl;
}
void circle:: setr(double c){
    r=c;
}
double circle:: getr(){
    return r;
}
double circle:: area(){
    return 3.14*r*r;
}
double circle:: length(){
    return 2*3.14*r;
}
void circle:: print(){
    point1::print(); cout<<";"<<"sharavixy:"<<r<<"]"<<endl;
}
class glan: public circle{
    public:
    glan(double=0, double=0, double=1, double=2);
   ~glan();
   void seth(double);
   double geth();
   double area();
   double caval();
   void print();
   protected:
   double h;
};
glan:: glan(double a, double b, double c, double d):circle(a, b, c){
    h=d;
}
glan:: ~glan(){
    cout<<"glan destructor"<<endl;
}
void glan:: seth(double d){
    h=d;
}
double glan:: geth(){
    return h;
}
double glan:: area(){
    return (2*circle::area()+circle::length()*h);
}
double glan:: caval(){
    return circle::area()*h;
}
void glan:: print(){
    circle::print(); cout<<"high="<<h<<endl;
}
int main(){
    point1 p1, p2(2,1);
    circle s1, s2(1,2,3);
    glan g1, g2(1, 0, 4, 7);
    p1.print();
    p2.print();
    s1.print();
    s2.print();
    g1.print();
    g2.print();
    p1.setpoint(4,3);
    s1.setr(6);
    g1.seth(7);
    cout<<p1.getx()<<" "<<p2.getx()<<endl;
    cout<<s1.area()<<" "<<s2.area()<<endl;
    cout<<s1.length()<<" "<<s2.length()<<endl;
    cout<<g1.area()<<" "<<g2.area()<<endl;
    cout<<g1.caval()<<" "<<g2.caval()<<endl;
    return 0;
}
