#include<bits/stdc++.h>
using namespace std;
//Brute
int SecondLargestElement(vector<int>&arr,int n){
    int maxi=INT_MIN;
    int SecondMaxi=INT_MIN;
    for(auto i:arr){
        if(i>=maxi){
            SecondMaxi=maxi;
            maxi=i;
            
        }
        else if(i>=SecondMaxi && i!=maxi){
            SecondMaxi=i;
        }
    }
    return SecondMaxi;
} 


int main(){
    int n;
    cout<<"enter size of array";
    cin>>n;
    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cout<<"enter element: ";
        cin>>arr[i];
    }

    int ans=SecondLargestElement(arr,n);
    cout<<"Second largest element: "<<ans;

}