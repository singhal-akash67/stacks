#include<iostream>
using namespace std;
#include<climits>
#ifndef specialstack_h
#define specialstack_h

class node
{
    public:
    int data;
    node *next;
    node(int data)
    {
        this->data=data;
        next=NULL;

    }
};
class specialstack
{
    node *top;
    node *min;
    int total;
    public:
    specialstack()
    {
        top=NULL;
        min=NULL;
        total=0;
    }
    void push(int data)
    {
        total++;
        node *newnode=new node(data);
        if(top==NULL)
        {
            top=newnode;
            node *newmin=new node(data);
            min=newmin;
        }
        else
        {
            newnode->next=top;
            top=newnode;
            if(data<=min->data)
            {
                node *newmin=new node(data);
                newmin->next=min;
                min=newmin;
            }
        }
    }
    int pop()
    {
        if(top==NULL)
        {
            return INT_MIN;
        }
        total--;
        node *k=top;
        top=top->next;
        int tobereturned=k->data;
        delete k;
        if(tobereturned==min->data)
        {
            node *t=min;
            min=min->next;
            delete t;

        }
        return tobereturned;
    }
    int returnmin()
    {
        return min->data;
    }
    bool isempty()
    {
        if(top==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }



};
#endif // specialstack_h


