/* This class is for dynamic increacing vector. You can add element from the back calling push_back(), add element from the fron calling push_front()
 get the capacity, size and addrec as follow get_capacity/addres/size.// you also can get the count of borned objects using the get_s function.
 this file is:
"Vector.h"*/
#include <iostream>
#include <assert.h>
using namespace std;
template <typename T>
class Vector{
    public:
       Vector();
       Vector(const Vector &);
       Vector(Vector&&);
       ~Vector();
    public:
       void push_back(int);
       void push_front(int);
       int get_size();
       int get_capacity();
       T* get_addres();
       int static get_s();
       Vector& operator=(const Vector&);
       Vector operator+(const Vector&)const;
       Vector operator*(int)const;
       int operator[](int)const;
    private:
       int m_capacity;
       int m_size;
       T* m_arr;
       static int s;
};
template <typename T>
Vector<T>:: Vector(){
    /*this is the default ctor.*/
    m_capacity = 0;
    m_size = 0;
    m_arr = nullptr;
    ++s;
}
template <typename T>
Vector<T>:: Vector(const Vector & v){
    /*this is the copy ctor.*/
    m_size = v.m_size;
    m_capacity = v.m_capacity;
    m_arr = new T [m_capacity];
    assert(m_arr);
    for(int i = 0; i < m_size; ++i){
            m_arr[i] = v.m_arr[i];
    }
    ++s;
}
template <typename T>
Vector<T>:: Vector(Vector&& obj)
{
    /*this is the move ctor.*/
    m_size = obj.m_size;
    m_capacity = obj.m_capacity;
    m_arr = obj.m_arr;
    obj.m_arr = nullptr;
    obj.m_size = 0;
    obj.m_capacity =0;
}
template <typename T>
Vector<T>:: ~Vector()
{
    /*this is the dtor.*/
    --s;
    delete [] m_arr;
    cout<<"dectructor"<<endl;
}
template <typename T>
void Vector<T>:: push_back(int element)
{
    /*this is a function that addes element to the vector from the end.*/
     if(m_size == m_capacity){
        m_capacity = m_capacity ? m_capacity*2 : 1;
        T* ptr = new T[m_capacity];
        assert(ptr);
        for(int i = 0; i < m_size; ++i){
            ptr[i] = m_arr[i];
        }
        delete [] m_arr;
        m_arr = ptr;
     }
    m_arr[m_size] = element; 
    ++m_size;
}
template <typename T>
int Vector<T>:: get_size()
{
    /*this function returns the count of elements.*/
    return m_size;
}
template <typename T>
int Vector<T>:: get_capacity()
{
    /*this function returns the size of memory.*/
    return m_capacity;
}
template <typename T>
T* Vector<T>:: get_addres()
{
    return m_arr;
}
template <typename T>
void Vector<T>:: push_front(int element)
{
    /*this function addes element to the front.*/
    if(m_size == m_capacity){
        m_capacity = m_capacity ? m_capacity*2 : 1;
        T* ptr = new T[m_capacity];
        assert(ptr);
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
template <typename T>
Vector<T>& Vector<T>:: operator=(const Vector& v){
     if(this == &v)
     {
         return *this;
     }
     delete [] m_arr;
     m_capacity = v.m_capacity;
     m_size = v.m_size;
     m_arr = new T [m_capacity];
     assert(m_arr);
     for(int i = 0; i < m_size; ++i){
         m_arr[i] = v.m_arr[i];
     }
     return *this;
}
template <typename T>
Vector<T> Vector<T>:: operator+(const Vector& v)const{
     Vector res;
     res.m_capacity = m_capacity + v.m_capacity;
     res.m_size = m_size + v.m_size;
     res.m_arr = new T [res.m_capacity];
     assert(res.m_arr);
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
template <typename T>
Vector<T> Vector<T>:: operator*(int c)const{
    Vector res;
    res.m_capacity = m_capacity;
    res.m_size = m_size;
    res.m_arr = new T [m_capacity];
    assert(res.m_arr);
    for(int i = 0; i < m_size; ++i){
        res.m_arr[i] = c*m_arr[i];
    }
    return res;
}
template <typename T>
int Vector<T>:: operator[](int i)const{
    if(0 <= i < m_size){
    return m_arr[i];
    }
    return -1;
}
template <typename T>
int Vector<T>:: s = 0;
template <typename T>
int Vector<T>:: get_s()
{
    return s;
}
int main(){
    Vector <int> v;
    v.push_back(1);
    v.push_front(0);
    Vector <int> v2(v);
    v2.push_back(4);
    v2 = v2*2;
    Vector <int> v3;
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
