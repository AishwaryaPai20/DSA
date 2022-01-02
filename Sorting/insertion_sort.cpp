#include<iostream>
using namespace std;
void insertionSort(int arr[],int n)
{
    int i,j,key;
    for(int i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of elements in an array ";
    cin>>n;
    int my_arr[n];
    cout<<"Enter "<<n<<" integers "<<endl;
    for(int i=0;i<n;i++) 
    {
        cin>>my_arr[i];
    }
    cout<<"UNSORTED ARRAY :"<<endl;
    for(int i=0;i<n;i++) 
    {
        cout<<my_arr[i]<<" ";
    }
    cout<<endl;
    insertionSort(my_arr,n);
    cout<<"SORTED ARRAY :"<<endl;
    for(int i=0;i<n;i++) 
    {
        cout<<my_arr[i]<<" ";
    }
    return 0;

}