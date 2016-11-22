#include<climits>
#include<iostream>
using namespace std;/*This uses linked list to form stack*/
#ifndef stack_h
#define stack_h
template <typename T>
class node /*This is the basic node class from which stack will be constructed*/
{
    public:
    T data; /*Type of data stack stores*/
    node<T> *next;/*Since we are using linked list, we have to store address of next node */
    node(T data)
    {
        this->data=data;
        next=NULL;
    }


};
template <typename P>
class stack
{
private:
    node<P> *top;/*This address points to top of stack*/
    int total;/*This denotes total number of elements in stack*/
public:
    stack()
    {
        top=NULL;/*This means stack is initially empty*/
        total=0;
    }
    void push(P data)
    {
        node<P> *newnode=new node<P>(data);/*We create an individual node in which we store the data entered by user*/
        total++;
        if(top==NULL)/*Now if top points to NULL or stack is empty, we will simply point top to new node*/
        {
            top=newnode;
            return;
        }
        else
        {
            newnode->next=top;/*Else we will append our new node in front of top*/
            top=newnode;
            return ;
        }
    }
    P pop()
    {
        if(top==NULL)/*Since top points to NULL at this condition, this means stack is empty and if someone tries to pop from empty stack, then int_min will be returned*/
        {
            cout<<"nothing in there in stack"<<endl;
            return INT_MIN;

        }
        else/*We just have to move onto next of top and delete the top because it has been created dynamically in heap. */

        {
            total--;
            node<P> *k=top;/*we will first store address of top, because moving directly to next of top will lead to loss of address of top. So we will store that in k*/
            top=top->next;/*Then move top onto next of top.*/
            P tobereturned=k->data;/*then before deleting top, we have to store its data */
            delete k;
            return tobereturned;
        }
    }
    bool isempty()/*This just returns boolean value whether stack is empty or not*/
    {
        if(total==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int returntotal()/*This returns the total number of elements present in stack*/
    {
        return total;
    }
    int returntop()/*This return data of top element in stack*/
    {
        return top->data;
    }

};
template <typename J>
void reversingrecursively(stack<J> &a)/*This is a function to reverse the stack recursively*/
{
    if(a.isempty()==true)
    {
        return;

    }
    J temp=a.pop();
    reversingrecursively(a);
    stack<J> auxilary;
    while(!a.isempty())
    {
        auxilary.push(a.pop());
    }
    a.push(temp);
    while(!auxilary.isempty())
    {
        a.push(auxilary.pop());
    }
    return;
}

#endif // STACK_H
