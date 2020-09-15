#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int ans=0;
	    int n=s.length();
	    for(int i=0;i<n;i++){
	        if(s[i]=='o'){
	            continue;
	        }if(s[i]=='x'){
	            if(i+1<n && s[i+1]=='y'){
	                s[i]='o';
	                s[i+1]='o';
	                ans++;
	            }
	        }else{
	            if(i+1<n && s[i+1]=='x'){
	                s[i]='o';
	                s[i+1]='o';
	                ans++;
	            }
	        }
	    }
	    
	    cout<<ans<<endl;
	}
	return 0;
}
