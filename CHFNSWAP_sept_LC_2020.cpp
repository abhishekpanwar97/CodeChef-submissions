#include<bits/stdc++.h>
using namespace std;

unsigned long long int nsum(long long int n){
    unsigned long long int sum=0;
    sum=n;
    sum=(sum*(sum+1))/2;
    return sum;
}

pair<long long int, long long int> point(long long int n){
    pair<long long int, long long int> ans;
    long int start=1,end=n,mid;
    unsigned long long int total,midsum,restsum,diff;
    total=nsum(n);
    bool check=false;
    while(start<=end){
        if(start==end){
            check=true;
        }
        mid=(start+end+1)/2;
        midsum=nsum(mid);
        restsum=total-midsum;
        if(midsum>restsum){
            end=mid-1;
        }else{
            start=mid;
        }
        
        if(check){
            break;
        }
        
    }
    
    ans.second=mid;
    start=1,end=n;
    check=false;
     while(start<=end){
        if(start==end){
            check=true;
        }
        mid=(start+end)/2;
        midsum=nsum(mid);
        restsum=total-midsum;
        if(midsum<restsum){
            diff=restsum-midsum;
            if(diff>2*(n-1)){
                start=mid+1;
            }else{
                end=mid;
            }
        }else{
            end=mid-1;
        }
        
        if(check){
            break;
        }
      }
      
      ans.first=mid;
      return ans;
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        if(n==3){
            cout<<2<<endl;
            continue;
        }
        
        unsigned long long int sum=nsum(n);
        if(sum%2==1){
            cout<<0<<endl;
            continue;
        }
        
        pair<long long int, long long int > ans=point(n);
        unsigned long long int countans=0;
        unsigned long long int sum1, sum2;
        for(long long int i=ans.first;i<=ans.second;i++){
            sum1=nsum(i);
            sum2=sum-sum1;
            if((sum2-sum1)<0){
                break;
            }else if(sum1==sum2){
                long long int l=((i-1)*i)/2;
                long long int r=n-i;
                r=((r-1)*r)/2;
                countans=countans+l+r;
            }else if((sum2-sum1)<=2*(n-1) && (sum2-sum1)%2==0){
                long long int d=sum2-sum1;
                d=d/2;
                long long int left=max(1LL,i-d);
              long long int right=0;
                if(left+d==i){
                    right=min(n,i+d);
                    right=right-i;
                }else{
                    right=max(0LL,(n-(left+d))+1);
                    right=min(d,right);
                }
                
                left=i-left+1;
                
              // cout<<"i "<<i<<" ,left "<<left<<"  ,right "<<right<<endl;
                countans=countans+min(left,right);
                
            }
        }
        
        cout<<countans<<endl;
        
    }
    return 0;
}