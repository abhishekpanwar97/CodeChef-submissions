#include <bits/stdc++.h>
using namespace std;

pair<long long int, vector<long long int>> k1(long long int n) {
    vector<long long int> temp(n);
    for(long long int i=0;i<n;i++){
        temp[i]=0;
    }

    pair<long long int,vector<long long int>> p;

    if (n == 1) {
        p.first=1;
        p.second=temp;
        return p;
    }else if (n == 2) {
        p.first=1;
        temp[0] = 1;
       p.second=temp;
        return p;
    }else if (n == 3) {
        p.first=0;
        temp[0] = 1;
        temp[1] = 1;
        p.second=temp;
        return p;
    }

    long long int sum = (n * (n + 1)) / 2;
    p.first=0;
    if (n % 4 == 0) {

        long long int turn = 1, s = 1, l = n;
        while (s < l) {
            if (!turn) {
                temp[s - 1] = temp[l - 1] = 1;
            }

            turn = 1-turn;
            s=s+1;
            l=l-1;
        }

        p.second=temp;
        return p;
    } 

    
        p.first= 1;
        long long int remaining_sum = sum / 2;
        for (long long int i = n; i >= 1; i--) {
            if (remaining_sum > i) {
                temp[i - 1] = 1;
                remaining_sum -= i;
            } else {
                temp[remaining_sum - 1] = 1;
                break;
            }
        }
        

    
    if (n % 4 == 3){
        p.first = 0;
    }

    p.second=temp;
    return p;
}


pair<long long int, vector<long long int>> k2(long long int n) {
    vector<long long int> temp(n);
    for(long long int i=0;i<n;i++){\
      temp[i]=0;
    }


  pair<long long int,vector<long long int>> p;

    p.first=0;
    long long int sum = n * (n + 1);
    sum=(sum * (2 * n + 1)) / 6;


    if (n == 1) {
        p.first=1;
        p.second=temp;
        return p;
    }else if (n/2==1 && n%2==0) {
        p.first = 3;
        temp[1] = 1;
        p.second=temp;
        return p;
    }else if (n/3==1 && n%3==0) {
        p.first = 4;
        temp[2] = 1;
        p.second=temp;
        return p;
    }else if (n/4==1 && n%4==0) {
        p.first = 2;
        temp[3] = 1;
        p.second=temp;
        return p;
    }else if (n == 5) {
        p.first = 3;
        temp[0] = 1;
        temp[2] = 1;
        temp[3] = 1;
        p.second=temp;
        return p;
    }else if (n % 4 == 2 && sum % 4 == 3) {
        temp[1] = 1;


        for (long long int i = 3; i < n - 3; i += 8) {
            temp[i] = 1;
            temp[i + 1] = 1;
            temp[i + 3] = 1;
            temp[i + 6] = 1;
        }


        temp[n - 3] = 1;
        temp[n - 2] = 1;
        p.first= 1;

    }else if (n % 4 == 3 && sum % 4 == 0) {
        bool step = true;

        for (long long int i = 0; i < n / 2;) {
            if (step) {
                i++;
                if (i < n / 2) {
                    i++;
                    step = !step;
                } else {
                    break;
                }
            } else {
                temp[i] = 1;
                i++;
                if (i < n / 2) {
                    temp[i] = 1;
                    i++;
                    step = !step;
                } else {
                    break;
                }

            }

        }

        step = false;
        for (long long int i = n / 2 + 1; i < n;) {
            if (step) {
                i++;
                if (i < n) {
                    i++;
                    step = !step;
                } else {
                    break;
                }
            } else {
                temp[i] = 1;
                i++;
                if (i < n) {
                    temp[i] = 1;
                    i++;
                    step = !step;
                } else {
                    break;
                }

            }
        }

    }else if (n % 4 == 3 && sum % 4 == 2) {
        temp[1] = 1;

        for (long long int i = 3; i < n / 2 - 2; i += 4) {
            temp[i + 1] = 1;
            temp[i + 2] = 1;
        }

        temp[n / 2] = 1;
        temp[n / 2 + 1] = 1;
        temp[n / 2 + 2] = 1;
        for (long long int i = n / 2 + 3; i < n - 3; i += 4) {
            temp[i + 2] = 1;
            temp[i + 3] = 1;
        }
        temp[n - 2] = 1;
    }else if (n % 4 == 0 && sum % 4 == 0) {
        for (long long int i = 0; i < n / 2; i += 4) {
            temp[i + 1] = 1;
            temp[i + 2] = 1;
        }

        for (long long int i = n / 2; i < n; i += 4) {
            temp[i] = 1;
            temp[i + 3] = 1;
        }

    }else if (n % 4 == 0 && sum % 4 == 2) {
        temp[1] = 1;
        temp[3] = 1;
        for (long long int i = 4; i < n / 2 - 2; i += 4) {
            temp[i] = 1;
            temp[i + 3] = 1;
        }

        temp[n / 2 - 2] = 1;
        temp[n / 2 - 1] = 1;

        for (long long int i = n / 2 + 2; i < n - 4; i += 4) {
            temp[i + 1] = 1;
            temp[i + 2] = 1;
        }

        temp[n - 3] = 1;
        temp[n - 1] = 1;

    }else if (n % 4 == 1 && sum % 4 == 1) {
        temp[2] = 1;
        temp[3] = 1;

        for (long long int i = 4; i < n / 2; i += 4) {
            temp[i + 2] = 1;
            temp[i + 3] = 1;
        }



        for (long long int i = n / 2 + 1; i < n - 4; i += 4) {
            temp[i] = 1;
            temp[i + 3] = 1;
        }

        temp[n - 4] = 1;
        temp[n - 1] = 1;
        p.first = 1;
    }else if (n % 4 == 1 && sum % 4 == 3) {
        temp[1] = 1;
        temp[3] = 1;

        for (long long int i = 4; i < n / 2 - 2; i += 4) {
            temp[i + 2] = 1;
            temp[i + 3] = 1;
        }

        temp[n / 2 + 1] = 1;
        temp[n / 2 + 2] = 1;

        for (long long int i = n / 2 + 3; i < n - 4; i += 4) {
            temp[i] = 1;
            temp[i + 3] = 1;
        }

        temp[n - 4] = 1;
        temp[n - 2] = 1;
        p.first = 1;
    }else if (n % 4 == 2 && sum % 4 == 1) {
        temp[0] = 1;
        temp[4] = 1;


        for (long long int i = 5; i < n - 5; i += 8) {
            temp[i] = 1;
            temp[i + 1] = 1;
            temp[i + 2] = 1;
            temp[i + 7] = 1;
        }


        temp[n - 5] = 1;
        temp[n - 4] = 1;
        temp[n - 2] = 1;
        p.first= 1;

    }
    

    p.second=temp;
    return p;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long int k;
    cin >> k;
    long long int testcases;
    cin>>testcases;
    
    while (testcases--) {
        long long int number;
        cin >> number;
        long long int value;
        vector<long long int> ans;

        if (k == 1) {
            pair<long long int,vector<long long int>> answer = k1(number);
            value = answer.first;
            ans = answer.second;
        } else {
            pair<long long int,vector<long long int>> answer = k2(number);
            value = answer.first;
            ans = answer.second;
        }

        cout << value << endl;
        for(auto itr=ans.begin();itr!=ans.end();++itr){
            cout<< *itr;
        }
        cout << endl;
    }

return 0;
}