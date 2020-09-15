#include<bits/stdc++.h>
using namespace std;
int main(){
     int t;
     cin>>t;
     while(t--){
          int n;
          cin>>n;
          int arr[n];
          for(int i=0;i<n;i++){
               cin>>arr[i];
          }
          
          bool ans= true;
          int coins[3]={0};
          for(int i=0;i<n;i++){
               int recval=arr[i];
               int giveval=arr[i]-5;
               coins[(recval/5)-1]+=1;
               if(giveval==0){
                    continue;
               }else if(giveval==10){
                    if(coins[1]>=1){
                         coins[1]--;
                         continue;
                    }else if(coins[0]>=2){
                         coins[0]-=2;
                         continue;
                    }else{
                         ans=false;
                         break;
                    }
               }else{
                    if(coins[0]>=1){
                         coins[0]-=1;
                    }else{
                         ans=false;
                         break;
                    }
               }
          }
          
          if(ans){
               cout<<"YES"<<endl;
          }else{
               cout<<"NO"<<endl;
          }
          
     }
     
     return 0;
}