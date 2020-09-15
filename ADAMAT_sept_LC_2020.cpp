#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
        int n;
        cin>>n;
        int arr[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
        
        int count=0;
        for(int i=n-1;i>=0;i--){
            bool check=false;
            for(int j=0;j<n;j++){
                if(arr[j][i]!=(n*j+i+1)){
                    check=true;
                }
                
                if(arr[i][j]!=(n*i+j+1)){
                    check=true;
                }
                
            }
            
            if(check){
                count+=1;
                for(int l=0;l<=i;l++){
                    for(int m=l+1;m<=i;m++){
                        int temp=arr[l][m];
                        arr[l][m]=arr[m][l];
                        arr[m][l]=temp;
                    }
                }
            }
            
        
        }
        
        cout<<count<<endl;
    }
    
    return 0;
}