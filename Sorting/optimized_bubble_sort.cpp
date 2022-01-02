#include<iostream>
using namespace std;
void op_bubbleSort(int arr[],int n)
{
    int i,j;
    for(int i=0;i<n;i++)
    {
        int flag=false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int flag=true;
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        if(flag==false) break;   //no swapping happens in a round means it is already sorted
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
    op_bubbleSort(my_arr,n);
    cout<<"SORTED ARRAY :"<<endl;
    for(int i=0;i<n;i++) 
    {
        cout<<my_arr[i]<<" ";
    }
    return 0;

}