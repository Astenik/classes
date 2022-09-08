#include <iostream>
#include <assert.h>
using namespace std;
struct Listnode
{
    int m_value;
    Listnode* m_next;
    Listnode():m_value(0), m_next(nullptr){}
    Listnode(int val):m_value(val), m_next(nullptr){}
    Listnode(int val, Listnode* next):m_value(val), m_next(next){}
    ~Listnode(){}
};
class Stack 
{
  public:
     Stack(){}
     virtual ~Stack(){}
     virtual void  push(int) = 0;
     virtual void  pop() = 0;
};
class Datas: public Stack 
{
  public:
     Datas();
     Datas(int);
     ~Datas();
  public:
     void push(int);
     void pop();
     Datas& operator=(const Datas&);
     Datas operator+(const Datas&)const;
     static int get_count();
  private:
     int m_size;
     int* m_arr;
     int m_top;
     static int m_count;
};
int Datas:: m_count = 0;
int Datas:: get_count()
{ 
    /*this function returns the count of created objects.*/
    return m_count; 
}
Datas:: Datas():m_size(1), m_top(-1)
{
    /*this is default constructor*/
    m_arr = new int [m_size];
    assert(m_arr);
    ++m_count;
}
Datas:: Datas(int size):m_size(size), m_top(-1)
{
    /*this is constructor with parametres*/
    m_arr = new int [m_size];
    assert(m_arr);
    ++m_count;
}
Datas:: ~Datas()
{
    /*this is destructor*/
    delete [] m_arr;
    --m_count;
}
void Datas:: push(int elem)
{
    /*this member function(method) addes a element to the array to the top.*/
    if(m_top <= m_size - 1)
    {
        ++m_top;
        m_arr[m_size] = elem;
    }
    else
    {
        cout<<"the array is full."<<endl;
    }
}
void Datas:: pop()
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
Datas& Datas:: operator=(const Datas& obj)
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
        m_arr = new int [obj.m_size];
        m_size = obj.m_size;
        m_top = obj.m_top;
        for(int i = 0; i <= m_top; ++i)
        {
            m_arr[i] = obj.m_arr[i];
        }
    }
    return *this;
}
Datas Datas:: operator+(const Datas& obj)const
{
    Datas res(m_size + obj.m_size);
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
class NodeArray: public Stack
{
  public:
     Listnode m_top;
     NodeArray();
     NodeArray(int);
     ~NodeArray(){ --m_c; delete m_nodes; }
  public:
     void push(int);
     void pop();
     NodeArray& operator=(const NodeArray&);
     NodeArray operator+(const NodeArray)const;
     static int get_c();
     friend ostream&  operator<<(ostream&, NodeArray&);
  private:
    static int m_c;
    Listnode* m_nodes;
};
int NodeArray:: m_c = 0;
int NodeArray:: get_c()
{
    return m_c; // returns the count of created objects;
}
NodeArray:: NodeArray()
{
    /* this is a  default constructor */
    m_nodes = new Listnode;
    assert(m_nodes);
    m_top = *m_nodes;
    ++m_c;
}
NodeArray:: NodeArray(int val)
{
    /*this is a constructor with parametres*/
    m_nodes = new Listnode;
    m_nodes->m_value = val;
    assert(m_nodes);
    m_top = *m_nodes;
    ++m_c;
}
void NodeArray:: push(int val)
{
    /*this is a function that push element to the top*/
    Listnode* tmp = new Listnode;
    assert(tmp);
    tmp->m_value = val;
    tmp->m_next = &m_top;
    m_top = *tmp;
}
void NodeArray:: pop()
{
    /*this is a function that remvoe node frome the top.*/
    Listnode* tmp = &m_top;
    m_top = *m_top.m_next;
    delete tmp;
}
NodeArray& NodeArray:: operator=(const NodeArray& oth)
{
    /*this is operator =.*/
    NodeArray tmp(m_nodes->m_value);
    Listnode* ptr = oth.m_top.m_next;
    tmp.push(oth.m_top.m_value);
    while(ptr->m_next != nullptr)
    {
        tmp.push(ptr->m_value);
        ptr = ptr->m_next;
    }
    NodeArray rev(tmp.m_nodes->m_value);
    while(tmp.m_top.m_next != nullptr)
    {
        rev.push(tmp.m_top.m_value);
        tmp.m_top = *tmp.m_top.m_next;
    }
    NodeArray* ptr2 = this;
    *this = rev;
    delete ptr2;
    return *this;
}
NodeArray NodeArray:: operator+(const NodeArray oth)const
{
    /*this is a operator + that creates the new NodeArray that consists of the nodes from two NodeArrays.*/
   NodeArray tmp;
   tmp = oth;
   NodeArray tmp2;
   tmp2 = *this;
   tmp2.m_nodes->m_next = &tmp.m_top;
   return tmp2;
}
ostream& operator<<(ostream& out, NodeArray obj)
{
    Listnode* ptr = &obj.m_top;
    while(ptr->m_next != nullptr)
    {
        out<<ptr->m_value<<endl;
        ptr = ptr->m_next;
    }
    out<<ptr->m_value<<endl;
    return out;
}
