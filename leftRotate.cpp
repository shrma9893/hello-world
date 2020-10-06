// rotation of array by juggling algorithm
#include<iostream>
using namespace std;
int gcd(int m,int n)
{
    if(m<n)
    {
        int t=m;
        m=n;
        n=t;
    }
    if(n==0)
        return m;
    else
        return gcd(n,m%n);
}
void leftRotation(int arr[],int d,int n)
{
    int i,j,k;
    for(i=0;i<gcd(n,d);i++)
    {
        int temp=arr[i];
        j=i;
        while(1)
        {
            k=j+d;
            if(k>=n)
                k-=n;
            if(k==i)
                break;
            arr[j]=arr[k];
            j=k;
        }
        arr[j]=temp;
    }
}
void rightRotation(int arr[],int d,int n)
{
    d=n-d;
    int i,j,k;
    for(i=0;i<gcd(n,d);i++)
    {
        int temp=arr[i];
        j=i;
        while(1)
        {
            k=j+d;
            if(k>=n)
                k-=n;
            if(k==i)
                break;
            arr[j]=arr[k];
            j=k;
        }
        arr[j]=temp;
    }
}
int main()
{
    int n,d,flag;
    cout<<"enter the size of array\n";
    cin>>n;
    cout<<"do you want to shift left or right , press 1 for left or 0 for right \n";
    cin>>flag;
    cout<<"enter no. of steps to shift";
    cin>>d;
    int arr[n];
    cout<<"enter "<<n<<" elements of array\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    if(flag)
        leftRotation(arr,d,n);
    else
        rightRotation(arr,d,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
