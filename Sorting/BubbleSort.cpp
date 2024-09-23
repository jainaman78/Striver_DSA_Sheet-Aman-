#include<bits/stdc++.h>
using namespace std;

void Bubblesort(vector<int>&arr,int n){
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
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

    Bubblesort(arr,n);
    cout<<endl;
    cout<<"After sorting"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}