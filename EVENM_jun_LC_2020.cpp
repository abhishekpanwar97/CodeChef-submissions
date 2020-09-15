#include<bits/stdc++.h>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int N;
        cin>>N;
        int a[N][N]={0};
        int odd=1;
        int even=2;
        for(int i=0;i<N;i++){
          for(int j=0;j<N;j++){
              if((i+j)%2==0){
                  a[i][j]=odd;
                  odd+=2;
              }else{
                  a[i][j]=even;
                  even+=2;
              }
          }   
        }
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    return 0;
}