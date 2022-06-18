#include <iostream>
#include <assert.h>
using namespace std;
class  arr{
    friend ostream& operator<<(ostream&, arr&);
    friend istream& operator>>(istream&, arr&);
    public:
    static int getc();
    arr( const arr&);
    arr(int=5);
    arr(int*, int);
    ~arr();
arr operator+(const arr&)const;
int operator*(const arr&)const;
arr operator*(int)const;
bool operator==(const arr&)const;
arr& operator=(arr&);
   private:
   int* a;
   int n;
   static int c;
};
int arr:: c=0;
int arr:: getc(){ return c;  }
istream&  operator>>(istream& in, arr& b){
    for(int i=0; i<b.n; i++)
    in>>b.a[i];
    return in;
}
ostream& operator<<(ostream& out, arr& b){
    for(int i=0; i<b.n; i++)
    out<<b.a[i]<<endl;
    return out;
}
arr:: arr(int k):n(k){
    a=new int [n];
    assert(a);
    for(int i=0; i<n; i++)
    a[i]=0;
    c++;
}
arr:: arr(const arr& b){
    if(this!=&b)
    delete [] a;
    n=b.n;
    a= new int [n];
    assert(a);
    for(int i=0; i<n; i++)
    a[i]=b.a[i];
    c++;
}
arr:: arr(int* b, int k){
   { assert(a);
    delete [] a;
   }
   n=k;
   a=new int [n];
   assert(a);
   for(int i=0; i<n; i++)
   a[i]=b[i];
   c++;
}
arr:: ~arr(){
 delete [] a;
 c--;
 cout<<"destructor"<<endl;
}
arr arr:: operator+(const arr& b)const{
    arr c;
    if(n>=b.n)
    for(int i=0; i<b.n; i++)
    c.a[i]=a[i]+b.a[i];
    else
    for(int i=0; i<n; i++)
    c.a[i]=a[i]+b.a[i];
    return c;
}
int arr:: operator*(const arr& b)const{
    int d;
    if(n<=b.n)
    for(int i=0; i<n; i++)
    d+=a[i]*b.a[i];
    else
    for(int i=0; i<b.n; i++)
    d+=a[i]*b.a[i];
    return d;
}
arr arr:: operator*(int c)const{
    arr b;
    b.n=n;
    for(int i=0; i<n; i++)
    b.a[i]=a[i]*c;
    return b;
}
bool arr:: operator==(const arr& b)const{
    assert(n==b.n);
    for(int i=0; i<n; i++)
     if(a[i]!=b.a[i])
     return false;
     return true;
}
arr& arr:: operator=(arr& b){
    if(this!=&b)
    delete [] a;
    n=b.n;
    a= new int [n];
    assert(a);
    for(int i=0; i<n; i++)
    a[i]=b.a[i];
    return *this;
}
int main(){
    int ar[10]={1, 14 ,4 , 36, 7, 9, 9, 0, 12, 4};
    arr a1(ar, 10), a2(6), a3(a1), a4;
    cin>>a4;
    cin>>a2;
    a2=a4;
    cout<<a2;
    //a4=a1+a3;
   // cout<<a4;
    if(a1==a3)
    cout<<"yes"<<endl;
    else
    cout<<"no"<<endl;
    return 0;
}
