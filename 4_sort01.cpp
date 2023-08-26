#include<iostream>
using namespace std;

void printarry(int arr[],int n){
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sortone(int arr[],int n){
    int left=0,right=n-1;

    while(left<right){
        while (arr[left]==0 && left<right)
        {
            /* code */
            left++;
        }
        while (arr[right]==1 && left<right)
        {
            /* code */
            right--;
        }
        if(left<right)
        {
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }
}

int main(){

    int arr[8]={1,1,0,0,0,0,1,0};

    sortone(arr,8);
    printarry(arr,8);
}