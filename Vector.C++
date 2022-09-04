// This class is for dynamic increacing vector. You can add element from the back calling push_back(), add element from the fron calling push_front()
// get the capacity, size and addrec as follow get_capacity/addres/size.// you also can get the count of borned objects using the get_s function.//
/* this file is:
"Vector.h"*/
#include <iostream>
using namespace std;
class Vector{
    public:
       Vector();
       Vector(const Vector &);
       ~Vector();
    public:
       void push_back(int);
       void push_front(int);
       int get_size();
       int get_capacity();
       int* get_addres();
       int static get_s();
       Vector& operator=(const Vector&);
       Vector operator+(const Vector&)const;
       Vector operator*(int)const;
       int operator[](int)const;
    private:
       int m_capacity;
       int m_size;
       int* m_arr;
       static int s;
};
Vector:: Vector(){
    m_capacity = 0;
    m_size = 0;
    m_arr = nullptr;
    ++s;
}
Vector:: Vector(const Vector & v){
    m_size = v.m_size;
    m_capacity = v.m_capacity;
    m_arr = new int [m_capacity];
    for(int i = 0; i < m_size; ++i){
            m_arr[i] = v.m_arr[i];
    }
    ++s;
}
Vector:: ~Vector(){
    --s;
    delete [] m_arr;
    cout<<"dectructor"<<endl;
}
void Vector:: push_back(int element){
     if(m_size == m_capacity){
        m_capacity = m_capacity ? m_capacity*2 : 1;
        int* ptr = new int[m_capacity];
        for(int i = 0; i < m_size; ++i){
            ptr[i] = m_arr[i];
        }
        delete [] m_arr;
        m_arr = ptr;
     }
    m_arr[m_size] = element; 
    ++m_size;
}
int Vector:: get_size(){
    return m_size;
}
int Vector:: get_capacity(){
    return m_capacity;
}
int* Vector:: get_addres(){
    return m_arr;
}
void Vector:: push_front(int element){
    if(m_size == m_capacity){
        m_capacity = m_capacity ? m_capacity*2 : 1;
        int* ptr = new int[m_capacity];
        ptr[0] = element;
        for(int i = 0; i < m_size; ++i){
            ptr[i + 1] = m_arr[i];
        }
        delete [] m_arr;
        m_arr = ptr;
     }
    else{
        for(int i = 1; i <= m_size; ++i){
             m_arr[i] = m_arr[i - 1];
        }
        m_arr[0] = element;
    }
    ++m_size;
}
Vector& Vector:: operator=(const Vector& v){
     if(this == &v){
         return *this;
     }
     delete [] m_arr;
     m_capacity = v.m_capacity;
     m_size = v.m_size;
     m_arr = new int [m_capacity];
     for(int i = 0; i < m_size; ++i){
         m_arr[i] = v.m_arr[i];
     }
     return *this;
}
Vector Vector:: operator+(const Vector& v)const{
     Vector res;
     res.m_capacity = m_capacity + v.m_capacity;
     res.m_size = m_size + v.m_size;
     res.m_arr = new int [res.m_capacity];
     for(int i = 0; i < m_size; ++i){
         res.m_arr[i] = m_arr[i];
     }
     int j = m_size;
     for(int i = 0; i < v.m_size; ++i){
         res.m_arr[j] = v.m_arr[i];
         ++j;
     }
     return res;
}
Vector Vector:: operator*(int c)const{
    Vector res;
    res.m_capacity = m_capacity;
    res.m_size = m_size;
    res.m_arr = new int [m_capacity];
    for(int i = 0; i < m_size; ++i){
        res.m_arr[i] = c*m_arr[i];
    }
    return res;
}
int Vector:: operator[](int i)const{
    if(0 <= i < m_size){
    return m_arr[i];
    }
    return -1;
}
int Vector:: s = 0;
int Vector:: get_s(){
    return s;
}
int main(){
    Vector v;
    v.push_back(1);
    v.push_front(0);
    Vector v2(v);
    v2.push_back(4);
    v2 = v2*2;
    Vector v3;
    v3 = v2;
    v3.push_back(8);
    cout<<"v size "<<v.get_size()<<endl;
    cout<<"v2 size "<<v2.get_size()<<endl;
    cout<<"v3 size "<<v3.get_size()<<endl;
    for(int i = 0; i < 4; ++i){
        cout<<v3[i]<<" ";
    }
    return 0;
}
