#include <iostream>
using namespace std;
class Vector{
    public:
       Vector();
       Vector(Vector &);
       ~Vector();
    public:
       void push_back(int);
       void push_front(int);
       int get_size();
       int get_capacity();
       int* get_addres();
       int static get_s();
    private:
       int m_capacity;
       int m_size;
       int* m_arr;
       static int s;
};
Vector:: Vector(){
    m_capacity = 5;
    m_size = 0;
    m_arr = new int [m_capacity];
    ++s;
}
Vector:: Vector(Vector & v){
    m_capacity = v.m_capacity;
    m_arr = new int [m_capacity];
    for(int i = 0; i < v.m_size; ++i){
            m_arr[i] = v.m_arr[i];
            ++m_size;
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
        m_capacity *= 2;
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
        m_capacity *= 2;
        int* ptr = new int[m_capacity];
        ptr[0] = element;
        for(int i = 1; i < m_size; ++i){
            ptr[i] = m_arr[i - 1];
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
int Vector:: s = 0;
int Vector:: get_s(){
    return s;
}
int main(){
    Vector v;
    cout<<v.get_size()<<endl;
    cout<<v.get_capacity()<<endl;
    cout<<v.get_addres()<<endl;
    int capacity = v.get_capacity();
    for(int i = 0; i < capacity; ++i){
        v.push_back(i);
    }
    v.push_back(10);
    cout<<v.get_size()<<endl;
    cout<<v.get_capacity()<<endl;
    cout<<v.get_addres()<<endl;
    return 0;
}
