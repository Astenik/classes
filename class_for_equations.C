//This class is written with c++ and crated for equations.//
#include <iostream>  
#include <math.h>
using namespace std;
class equation{
    public:
    equation(){}
virtual   ~equation(){ cout<<"destructor"<<endl; }
virtual int   root_count()=0;
virtual double   roots()=0;
protected:
double b;
double c;
};
class linearEquation: public equation{
    public:
    linearEquation(double, double);
virtual   ~linearEquation(){ cout<<"linear destructor"<<endl; }
virtual  int root_count(){ return 1;  }
virtual double  roots(){  return ((-c)/b); }
};
 linearEquation:: linearEquation(double z, double j){ b=z; c=j;}
class quadraEquation: public linearEquation{
    public:
  quadraEquation(double , double , double );
virtual  ~quadraEquation(){ cout<<"quadra destructor"<<endl; }
virtual int root_count();
virtual double roots();
private:
double a;
};
  quadraEquation:: quadraEquation(double k, double g, double f):linearEquation(k, g){ a=f; }
int quadraEquation:: root_count(){
    if((b*b-4*a*c)==0) return 1;
    if( (b*b-4*a*c)>0) return 2;
    if((b*b-4*a*c)<0) return 0;
}
double quadraEquation:: roots(){
    if((b*b-4*a*c)==0 ) return ((-b)/2*a);
     if( (b*b-4*a*c)>0) return ((sqrt(b*b-4*a*c)-b)/2*a);
     if((b*b-4*a*c)<0) return -1;
}
int main(){
    equation* ptr[4];
    linearEquation l1(1, -3), l2(3, -9);
    quadraEquation q1(-3, -4, 1), q2(-1, -2, 1 );
    ptr[0]=&l1;
    ptr[1]=&q1;
    ptr[2]=&l2;
    ptr[3]=&q2;
    for(int i=0; i<4; i++){
      cout<<ptr[i]->roots()<<endl;
      cout<<ptr[i]->root_count()<<endl;
    }
    return 0;
}
