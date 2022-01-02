//Reversing a string using stack 

#include<iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
void Reverse(char *C,int n)
{
    stack<char>S;
    for(int i=0;i<n;i++)
    {
        S.push(C[i]);
    }
    for(int i=0;i<n;i++)
    {
        C[i]=S.top();
        S.pop();
    }
}
int main()
{
    char C[100];
    cout<<"Enter a string "<<endl;
    cin.getline(C,100);
    Reverse(C,strlen(C));
    cout<<"Reverse "<<C;
}

