#include<iostream>
#include<map>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
        int n;
        cin>>n;
        long int arr[n];
        int i=0;
        while(i<n){
            cin>>arr[i];
            i++;
        }
        
        map<long int,int>mp;
        i=0;
        while(i<n){
            if(arr[i]!=0)
            mp[arr[i]]+=1;
            i++;
        }
        
        cout<<mp.size()<<endl;
        
        
        
    }
    
    return 0;
}