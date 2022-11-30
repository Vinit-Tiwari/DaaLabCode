#include<iostream>
using namespace std;

int Partition(int a[],int low,int high){
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(a[j]<pivot){
            i=i+1;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return (i+1);
}
void QuickSort(int a[],int low,int high) {
    if(low<high){
        int index = Partition(a,low,high);
        QuickSort(a,low,index-1);
        QuickSort(a,index+1,high);
    }
}
int main(){
    int n;
    cout<<"Size of array : ";
    cin>>n;
    int a[n];
    cout<<"\nTaking array an as input : ";
    for(int i=0;i<n;i++){
        cin>>a[i];                             
    }
    cout<<"\nGiven array is : ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }cout<<endl;
    int low=0;
    int high=n-1;
    QuickSort(a,low,high);
    cout<<"\nSorted Array is : ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}