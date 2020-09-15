#include<bits/stdc++.h>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
    unsigned long long int N;
      cin>>N;
      if(N%2==1){
          unsigned long long int anss=N/2;
          cout<<anss<<endl;
          continue;
      }else{
          //int count=0;
          while(N%2==0){
              N=N/2;
             // count++;
          }
       unsigned long long int anss=N/2;
       cout<<anss<<endl;
       continue;
          
      }
      
      
    }
    
    return 0;
}