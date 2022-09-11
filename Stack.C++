#include <iostream>
#include <assert.h>
using namespace std;
template <typename T>
struct Listnode
{
    T m_value;
    Listnode* m_next;
    Listnode():m_value(0), m_next(nullptr){}
    Listnode(int val):m_value(val), m_next(nullptr){}
    Listnode(int val, Listnode* next):m_value(val), m_next(next){}
    ~Listnode(){}
};
template <typename U>
class Stack 
{
  public:
     Stack(){}
     virtual ~Stack(){}
     virtual void  push(U) = 0;
     virtual void  pop() = 0;
};
template <typename U>
class Datas: public Stack<U> 
{
  public:
     Datas();
     Datas(int);
     Datas(Datas&&);
     ~Datas();
  public:
     void push(U);
     void pop();
     Datas<U>& operator=(const Datas&);
     Datas<U> operator+(const Datas&)const;
     U operator[](int);
     int get_top();
     static int get_count();
  private:
     int m_size;
     U* m_arr;
     int m_top;
     static int m_count;
};
template <typename U>
U Datas<U>:: operator[](int i)
{
    return m_arr[i];
}
template <typename U>
int Datas<U>:: get_top()
{
    return m_top;
}
template <typename U>
int Datas<U>:: m_count = 0;
template <typename U>
int Datas<U>:: get_count()
{ 
    /*this function returns the count of created objects.*/
    return m_count; 
}
template <typename U>
Datas<U>:: Datas():m_size(1), m_top(-1)
{
    /*this is default constructor*/
    m_arr = new U [m_size];
    assert(m_arr);
    ++m_count;
}
template <typename U>
Datas<U>:: Datas(int size):m_size(size), m_top(-1)
{
    /*this is constructor with parametres*/
    m_arr = new U [m_size];
    assert(m_arr);
    ++m_count;
}
template <typename U>
Datas<U>:: Datas(Datas<U>&& obj)
{
    /*this is a move ctor.*/
    m_size = obj.m_size;
    m_top = obj.m_top;
    m_arr = obj.m_arr;
    obj.m_arr = nullptr;
    obj.m_top = 0;
    obj.m_size = 0;
}
template <typename U>
Datas<U>:: ~Datas()
{
    /*this is destructor*/
    delete [] m_arr;
    --m_count;
}
template <typename U>
void Datas<U>:: push(U elem)
{
    /*this member function(method) addes a element to the array to the top.*/
    if(m_top <= m_size - 1)
    {
        ++m_top;
        m_arr[m_top] = elem;
    }
    else
    {
        cout<<"the array is full."<<endl;
    }
}
template <typename U>
void Datas<U>:: pop()
{
    /*this method remove the top elemrny*/
    if(m_top >= 0)
    {
        delete &m_arr[m_top];
        --m_top;
    }
    else 
    {
        cout<<"there is no element to remove."<<endl;
    }
}
template <typename U>
Datas<U>& Datas<U>:: operator=(const Datas<U>& obj)
{
    /*this is a operator =.*/
    if(m_size == obj.m_size)
    { 
        for(int i = 0; i <= obj.m_top; ++i)
        {
            m_arr[i] = obj.m_arr[i];
        }
    }
    else
    {
        delete [] m_arr;
        m_arr = new U [obj.m_size];
        assert(m_arr);
        m_size = obj.m_size;
        m_top = obj.m_top;
        for(int i = 0; i <= m_top; ++i)
        {
            m_arr[i] = obj.m_arr[i];
        }
    }
    return *this;
}
template <typename U>
Datas<U> Datas<U>:: operator+(const Datas<U>& obj)const
{
    Datas<U> res(m_size + obj.m_size);
    int i;
    for(i = 0; i <= m_top; ++i)
    {
        res.m_arr[i] = m_arr[i];
    }
    for(int j = 0; j <= obj.m_top; ++j)
    {
        res.m_arr[i] = obj.m_arr[j];
        ++i;
    }
    res.m_top = i - 1; 
    return res;
}
template <typename U>
class NodeArray: public Stack<U>
{
  public:
     Listnode<U> m_top;
     NodeArray();
     NodeArray(U);
     NodeArray(NodeArray&&);
     ~NodeArray(){ --m_c; delete m_nodes; }
  public:
     void push(U);
     void pop();
     NodeArray<U>& operator=(const NodeArray&);
     NodeArray<U> operator+(const NodeArray)const;
     static int get_c();
     ostream&  operator<<(ostream&);
  private:
    static int m_c;
    Listnode <U>* m_nodes;
};
template <typename U>
int NodeArray<U>:: m_c = 0;
template <typename U>
int NodeArray<U>:: get_c()
{
    return m_c; // returns the count of created objects;
}
template <typename U>
NodeArray<U>:: NodeArray()
{
    /* this is a  default constructor */
    m_nodes = new Listnode<U>;
    assert(m_nodes);
    m_top = *m_nodes;
    ++m_c;
}
template <typename U>
NodeArray<U>:: NodeArray(U val)
{
    /*this is a constructor with parametres*/
    m_nodes = new Listnode<U>;
    assert(m_nodes);
    m_nodes->m_value = val;
    m_nodes->m_next = nullptr;
    m_top = *m_nodes;
    ++m_c;
}
template <typename U>
NodeArray<U>:: NodeArray(NodeArray<U>&& obj)
{
    /*this is a move ctor for NodeArray.*/
    m_top = obj.m_top;
    m_nodes = obj.m_nodes;
    obj.m_nodes = nullptr;
    obj.m_top = 0;
}
template <typename U>
void NodeArray<U>:: push(U val)
{
    /*this is a function that push element to the top*/
    Listnode<U>* tmp = new Listnode<U>;
    assert(tmp);
    tmp->m_value = val;
    tmp->m_next = &m_top;
    m_top = *tmp;
}
template <typename U>
void NodeArray<U>:: pop()
{
    /*this is a function that remvoe node frome the top.*/
    Listnode<U>* tmp = &m_top;
    m_top = *m_top.m_next;
    delete tmp;
}
template <typename U>
NodeArray<U>& NodeArray<U>:: operator=(const NodeArray<U>& oth)
{
    /*this is operator =.*/
    NodeArray<U> tmp(m_nodes->m_value);
    Listnode <U>* ptr = oth.m_top.m_next;
    tmp.push(oth.m_top.m_value);
    while(ptr->m_next != nullptr)
    {
        tmp.push(ptr->m_value);
        ptr = ptr->m_next;
    }
    NodeArray<U> rev(tmp.m_nodes->m_value);
    while(tmp.m_top.m_next != nullptr)
    {
        rev.push(tmp.m_top.m_value);
        tmp.m_top = *tmp.m_top.m_next;
    }
    NodeArray <U>* ptr2 = this;
    *this = rev;
    delete ptr2;
    return *this;
}
template <typename U>
NodeArray<U> NodeArray<U>:: operator+(const NodeArray<U> oth)const
{
    /*this is a operator + that creates the new NodeArray that consists of the nodes from two NodeArrays.*/
   NodeArray <U> tmp;
   tmp = oth;
   NodeArray <U> tmp2;
   tmp2 = *this;
   tmp2.m_nodes->m_next = &tmp.m_top;
   return tmp2;
}
template <typename U>
ostream& NodeArray<U>:: operator<<(ostream& out)
{
    Listnode<U>* ptr = &m_top;
    while(ptr->m_next != nullptr)
    {
        out<<ptr->m_value<<endl;
        ptr = ptr->m_next;
    }
    out<<ptr->m_value<<endl;
    return out;
}
int main()
{
    Datas <int> obj(4);
    obj.push(7);
    obj.push(8);
    obj.push(9);
    int c = obj.get_top();
    for(int i = 0; i <= c; ++i)
    {
        cout<<obj[i]<<" ";
    }
    NodeArray <int> n(12);
    n.push(67);
    cout<<n.m_top.m_value<<endl;
    return 0;
}
