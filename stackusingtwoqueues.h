#include<climits>
#ifndef stackusingqueues_h
#define stackusingqueues_h
template <typename T>
class node
{
    public:
    T data;
    node<T>* next;
    node(T data)
    {
        this->data=data;
        next=NULL;
    }

};
template <typename Q>
class queue
{
    public:
    node<Q>* front;
    node<Q>* end;
    int totalelements;
    queue()
    {
        front=NULL;
        end=NULL;
        totalelements=0;
    }
    void enqueue(Q data)
    {
        totalelements++;
        node<Q>* newnode=new node<Q>(data);
        if(front==NULL)
        {
            front=newnode;
            end=newnode;
        }
        else
        {
            end->next=newnode;
            end=end->next;
        }
    }
    Q dequeue()
    {
        if(isempty())
        {
            return INT_MAX;
        }
        else
        {
            node<Q>* k=front;
            front=front->next;
            Q tobereturned=k->data;
            delete k;
            if(front==NULL)
            {
                end=NULL;
            }
            totalelements--;
            return tobereturned;
        }
    }
    bool isempty()
    {
        if(front==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};
template <typename S>
class stack
{
    queue<S> a;
    queue<S> b;
public:
    void push(S data)
    {
        if(!a.isempty())
        {
            a.enqueue(data);
        }
        else
        {
            b.enqueue(data);
        }
    }
    S pop()
    {
        if(!a.isempty())
        {
            while(a.totalelements!=1)
            {
                b.enqueue(a.dequeue());
            }
            return a.dequeue();

        }
        else
        {
            while(b.totalelements!=1)
            {
                a.enqueue(b.dequeue());
            }
            return b.dequeue();
        }
    }
    bool isempty()
    {
        if(a.isempty()==true&&b.isempty()==true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
#endif // stackusingqueues_h
