#include<iostream>/*This uses stack class developed by me*/
#include"stack.h"
using namespace std;
bool balancedparenthesis(string temp)
{
    stack<char> a;
    int i=0;
    while(temp[i]!='\0')
    {
        if(temp[i]=='['||temp[i]=='{'||temp[i]=='(')
            {
                a.push(temp[i]);
            }
            else if(temp[i]==']')
            {
                char d=a.pop();
                if(d!='[')
                {

                    return false;
                }
            }
            else if(temp[i]=='}')
            {
                char d=a.pop();
                if(d!='{')
                    {
                        return false;
                    }
            }
            else if(temp[i]==')')
            {
                char d=a.pop();
                if(d!='(')
                {
                    return false;
                }
            }

               i++;
            }

    if(a.isempty()==true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

