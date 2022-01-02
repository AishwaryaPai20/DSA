#include<iostream>
using namespace std;

int binarySearch(int arr[],int beg,int end,int x)
{
    while(beg<=end)
    {
        int mid=(beg+end)/2;
        if(arr[mid]==x) 
        {
            return mid;
        }
        else if(arr[mid]<x)
        {
            beg=mid+1;
        }
        else 
        {
            end=mid-1;
        }
    }
    return -1;
}
int main()
{
    int num,output;
    int arr[10];
    cout<<"Enter 10 elements of an array"<<endl;
    for(int i=0;i<10;i++)
    {
        cin >> arr[i];
    }
    cout<<"Enter the element you want to search"<<endl;
    cin>>num;
    output=binarySearch(arr,0,9,num);
    if(output==-1)
    {
        cout<<"No match found"<<endl;
    }
    else
    {
        cout<<"Match found at index position "<<output<<endl;
    }
    return 0;
}