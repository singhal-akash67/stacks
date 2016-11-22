#include<iostream>
using namespace std;
#include<climits>
#ifndef stack_h
#define stack_h
template <typename T>
class stack
{
    int top;
    T *array;
    int size;
public:
    stack(int size)/*This Constructor takes size from user*/
    {
        this->size=size;
        array=new T(size);
        top=0;
    }
    stack()/*This does not take size from user....it initializes size to 10*/
    {
        size=10;
        array=new T(size);
        top=0;
    }
    void push(T data)
    {
        if(isfull()==true)
        {
            cout<<"already full"<<endl;
            return;
        }
        else
        {
            array[top]=data;
            top++;
        }
    }
    T pop()
    {
        if(isempty()==true)
        {
            cout<<"already empty"<<endl;
            return INT_MIN;
        }
        else
        {
            top--;
            return array[top];
        }
    }
    bool isempty()
    {
        if(top==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isfull()
    {
        if(top==size)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    int currentsize()
    {
        return top;
    }
    ~stack()
    {
        delete array;
    }
};
#endif // stack_h
