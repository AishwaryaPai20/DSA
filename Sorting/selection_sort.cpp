#include<iostream>
using namespace std;
void selectionSort(int arr[],int n)
{
    int i,j,min;
    for(int i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            min=j;
        }
        if(min!=i) 
        {
            int temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
        }
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
    selectionSort(my_arr,n);
    cout<<"SORTED ARRAY :"<<endl;
    for(int i=0;i<n;i++) 
    {
        cout<<my_arr[i]<<" ";
    }
    return 0;

}