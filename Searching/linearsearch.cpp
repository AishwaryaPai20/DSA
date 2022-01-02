#include<iostream>
using namespace std;
void linearSearch(int a[],int n)
{
    int temp=-1;
    for(int i=0;i<7;i++)
    {
        if(a[i]==n)
        {
            cout<<"Element fount at location "<<i+1<<endl;
            temp=0;
        }
    }
        if(temp==-1)
        {
            cout<<"Element not found"<<endl;
        }
}
int main()
{
    int arr[7];
    cout<<"Enter 7 elements in the array"<<endl;
    for(int i=0;i<7;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter an element to be searched"<<endl;
    int num=0;
    cin>>num;
    linearSearch(arr,num);
}