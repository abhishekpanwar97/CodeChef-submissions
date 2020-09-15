#include<bits/stdc++.h>
using namespace std;
int main(){
     int t;
     cin>>t;
     while(t--){
          int n,p;
          cin>>n>>p;
          int a[n][n]={0};
          bool check=true;
          for(int i=0;i<n;i++){
               for(int j=0;j<n;j++){
                    int x;
                    cout<<1<<" "<<i+1<<" "<<j+1<<" "<<i+1<<" "<<j+1<<endl;
                    cin>>x;
                    if(x!=-1){
                         a[i][j]=x;
                    }else{
                         break;
                         check=false;
                    }
               }
          }
          
          if(!check){
               break;
          }
          
          cout<<2<<endl;
          
          for(int i=0;i<n;i++){
               for(int j=0;j<n;j++){
                    cout<<a[i][j]<<" ";
               }
               cout<<endl;
          }
          
          int x;
          cin>>x;
          if(x==-1){
               break;
          }
     }
     
     return 0;
}