#include<bits/stdc++.h>
using namespace std;

void Selectionsort(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        int mini=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[mini]){
                mini=j;
            }
        }
        swap(arr[i],arr[mini]);
    }
}

int main(){
    int n;
    cout<<"Enter Size : ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Enter element : ";
        cin>>arr[i];
        cout<<endl;
    }

    Selectionsort(arr,n);
    cout<<endl;
    cout<<"After sorting"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}