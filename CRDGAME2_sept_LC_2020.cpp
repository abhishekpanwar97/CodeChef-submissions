#include<bits/stdc++.h>
using namespace std;


//inline void addition(int &x, int y){x+=y;if(x>=modulus) x-=modulus;if(x<0) x+=modulus;}
// void addition(int number2,int &number1,int modulus){
//     number1=number1+number2;
//     if(number1>=modulus){
//          number1=number1-modulus;
//     }

//     if(number1<0){
//         number1=number1+modulus;
//     }
     
// }

// int multiply(int x, int y){ 
//     long long int temp=x;
//     temp=temp*y;
//     return temp%modulus;
// }

int gcd(int number1, int number2){ 
    if(number2!=0){
     return gcd(number2,number1%number2);
    }else{
      return number1;
    }
}


int power(int number ,int power,int modulus){
    int ans = 1; 
    while(power){
        if(power&1==1){
            long long int temp=ans;
            temp=temp*number;
            temp=temp%modulus;
            ans=temp;
        }
        
        long long int temp=number;
        temp=temp*number;
        number=temp%modulus;
        power=power/2;
      }

        return ans;
}





// int modulo_inverse(int number) { 
//     // as number and modulo are relatively prime
//     return power(number, modulus-2);
// }


// int division(int  num1, int  num2){ 
//     int temp=power(num2,modulus-2);
//     long long int temp2=num1;
//     temp2=temp2*temp;
//     temp2=temp2%modulus;
//     return temp2;
// }




int  solution(int  a, int  b,int modulus)
{
    int  ans=1,k,temp;
    if(a<(a-b)){
        k=a;
    }else{
        k=a-b;
    }

    for(int i=0;i<k;i++)
    {   long long int temp2=ans;
        temp2=temp2*(a-i);
        temp=temp2%modulus;
        //cout<<"ansmul: "<<temp<<endl;
        temp2=power(i+1,modulus-2,modulus);
        temp2=temp2*temp;
        ans=temp2%modulus;
       // cout<<"div1: "<<ans<<endl;
    }
    
    int finalans= ans%modulus;
    return finalans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int modulus = 1000000007;

    int test_cases;
    cin>>test_cases;
    for(int t=0;t<test_cases;t++)
    {
        int numbers;
        cin>>numbers;
        vector<int >array;
        int  max_element=0;
        int  max_element_value=0;

        for(int i=0;i<numbers;i++){
            int temp;
            cin>>temp;
            array.push_back(temp);
            }

        for(int i=0;i<numbers;i++){
                max_element=max(array[i],max_element);
            }

        for(int i=0;i<numbers;i++)
        {
            if(array[i]==max_element){
                max_element_value=max_element_value+1;
            }
        }

        int finalans=0;
        if(numbers==1)
        {
            printf("2\n");
            continue;
        }else if(max_element_value%2==1)
        {
            finalans=power(2,numbers,modulus);
        }else
        {
            finalans=power(2,numbers,modulus);
            int a=max_element_value;
            int b=max_element_value/2;
            int temp1=solution(a,b,modulus);
            int temp2=power(2,numbers-a,modulus);
            //cout<<"power: "<<temp2<<" , solution: "<<temp1<<endl;
            long long int temp=temp1;
            temp=temp*temp2;
            temp=temp%modulus;
            int mul_ans=temp;
            //cout<<"ans "<<finalans<<" , muli "<<mul_ans<<endl;
            finalans=finalans-mul_ans;
        }

        if(finalans<0){
            finalans=(finalans+modulus)%modulus;
        }
            
        int final_ans=finalans%modulus;

        printf("%d\n",final_ans);



    }
}