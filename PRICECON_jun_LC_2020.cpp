#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int var;
	    int ans =0;
	    for(int i=0;i<n;i++){
	        cin>>var;
	        if(var>k){
	            ans+=var-k;
	        }
	    }
	    
	  cout<<ans<<endl;
	}
	return 0;
}
