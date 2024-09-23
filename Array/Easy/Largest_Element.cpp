#include<bits/stdc++.h>
using namespace std;
//Brute
int LargestElement(vector<int>&arr,int n){
    int maxi=INT_MIN;
    for(auto i:arr){
        if(i>=maxi){
            maxi=i;
        }
    }
    return maxi;
} 
int main(){
    int n; 
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"enter element: ";
        cin>>arr[i];
    }
    int ans=LargestElement(arr,n);
    cout<<"largest element: "<<ans;

}