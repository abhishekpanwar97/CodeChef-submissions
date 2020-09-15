#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        vector<pair<float,pair<int,int>>>v;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                pair<int,int> temp;
                temp.first=i;
                temp.second=j;
                float speed;
                float ans;
                speed=arr[i]-arr[j];
                if(speed<=0){
                    ans=100.0;
                }else{
                    ans=j-i;
                    ans=ans/speed;
                }
                
                pair<float,pair<int,int>>p;
                p.first=ans;
                p.second=temp;
                v.push_back(p);
                
            }
        }
        
        sort(v.begin(),v.end());
        // for(auto itr=v.begin();itr!=v.end();++itr){
        //     pair<double,pair<int,int>>temp=*itr;
        //         pair<int,int>p=temp.second;
        // }
        int max_m=1;
        int min_m=n;
        for(int i=0;i<n;i++){
            int check[n]={0};
            check[i]=1;
            for(auto itr=v.begin();itr!=v.end();++itr){
                pair<double,pair<int,int>>temp=*itr;
                if(temp.first==100.0){
                    break;
                }
                pair<int,int>p=temp.second;
                if(check[p.first]==1){
                    check[p.second]=1;
                }
                
                if(check[p.second]==1){
                    check[p.first]=1;
                }
            }
            
            int count=0;
            for(int j=0;j<n;j++){
                if(check[j]==1){
                    count++;
                }
            }
            
            max_m=max(count,max_m);
            min_m=min(count,min_m);
        }
        
        cout<<min_m<<" "<<max_m<<endl;
        //cout<<endl;
       // cout<<"*******************"<<endl;
    }
    return 0;
}





