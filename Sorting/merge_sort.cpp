#include<iostream>
using namespace std;
void bubbleSort(int arr[],int n)
{
    int i,j;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
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
    bubbleSort(my_arr,n);
    cout<<"SORTED ARRAY :"<<endl;
    for(int i=0;i<n;i++) 
    {
        cout<<my_arr[i]<<" ";
    }
    return 0;

}