#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n, k;cin >> n >> k;
    stack<long long int > s;
    int j;
    vector<long long int> dp(200002);
    vector<long long int> lis(n);
    for(int i = 0; i<n; i++){
        cin >> lis[i];
    }
    if(k%2 == 1 && k != 1){
    for(int i = 0; i < 3; i++){
    for(int i = 1; i<n; i++){
        int a; a = lis[i];
        if(dp[a] == 0){
            s.push(a);
            dp[a] += 1;
        }else{
            while(dp[a] != 0){
                if(s.top() == a){
                    dp[s.top()] -= 1;
                    s.pop();
                    break;
                }
                dp[s.top()] -= 1;
                s.pop();
            }
        }
    }
    }
    }else if(k == 1){
    for(int i = 0; i<n; i++){
        int a; a = lis[i];
        if(dp[a] == 0){
            s.push(a);
            dp[a] += 1;
        }else{
            while(dp[a] != 0){
                if(s.top() == a){
                    dp[s.top()] -= 1;
                    s.pop();
                    break;
                }
                dp[s.top()] -= 1;
                s.pop();
            }
        }
    }
    }else{
    for(int i = 0; i < 2; i++){
    for(int i = 0; i<n; i++){
        int a; a = lis[i];
        if(dp[a] == 0){
            s.push(a);
            dp[a] += 1;
        }else{
            while(dp[a] != 0){
                if(s.top() == a){
                    dp[s.top()] -= 1;
                    s.pop();
                    break;
                }
                dp[s.top()] -= 1;
                s.pop();
            }
        }
    }
    }  
    }
    vector<long long int> ans;
    int count = 0;
    while(s.empty() != 1){
        ans.push_back(s.top());
        count++;
        s.pop();
    }
    for(int i = 0; i<count; i++){
        cout << ans[count - i - 1] << " ";
    }
    cout << endl;
}