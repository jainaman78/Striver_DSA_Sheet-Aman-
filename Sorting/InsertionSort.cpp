 #include<bits/stdc++.h>
using namespace std;

void Insertionsort(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
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

    Insertionsort(arr,n);
    cout<<endl;
    cout<<"After sorting"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}