#include<bits/stdc++.h>
using namespace std;
int main() {

    long long int value[21];
    for (int i = 0; i <= 20; i++) {
        value[i] = (1 << i);
    }
    
    
    int test_cases;
    cin >> test_cases;
    for(int z=0;z<test_cases;z++) {
        long long int given_value;
        cin>>given_value;
        int ans[40];
        long long int total_sum;
        cout<<"1"<<" "<<value[20]<<endl;
        cin>>total_sum;
        total_sum =total_sum - (given_value*value[20]);
        if(total_sum%2==0){
            ans[0]=0;
        }else{
            ans[0]=1;
        }

        for (int j=1; j<20; j++) {
            cout<<"1"<<" "<<value[j]<<endl;
            long long int ret_ans;
            cin >> ret_ans;
            long long int difference = (total_sum - ret_ans);
            difference=difference/value[j];
            
            long long int ones=(given_value + difference)/2;

            if(ones%2==0){
                ans[j]=0;
            }else{
                ans[j]=1;
            }
            
        }


        long long int final_ans = 0;
        for (int i = 0; i < 20; i++) {
            final_ans=final_ans+ans[i]*value[i];
        }

        
    cout<<"2"<<" "<<final_ans<<endl;
    int returned;
    cin>>returned;
    if (returned == -1) {
        exit(0);
    }

}


    return 0;
}