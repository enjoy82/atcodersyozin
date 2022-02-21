#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

string s;
int n;

int solve(vector<char> &ans){
    for(int i = 1; i < n-1; i++){
        if(ans[i] == 'S'){
            if(s[i] == 'o'){
                if(ans[i-1] == 'S'){
                    ans[i+1] = 'S';
                }else{
                    ans[i+1] = 'W';
                }
            }else{
                if(ans[i-1] == 'S'){
                    ans[i+1] = 'W';
                }else{
                    ans[i+1] = 'S';
                }
            }
        }else{
            if(s[i] == 'o'){
                if(ans[i-1] == 'S'){
                    ans[i+1] = 'W';
                }else{
                    ans[i+1] = 'S';
                }
            }else{
                if(ans[i-1] == 'S'){
                    ans[i+1] = 'S';
                }else{ 
                    ans[i+1] = 'W';
                }
            }
        }
    }
    if(ans[n-1] == 'S'){
        if(s[n-1] == 'o'){
            if(ans[n-2] != ans[0]){
                return -1;
            }
        }else{
            if(ans[n-2] == ans[0]){
                return -1;
            }
        }
    }else{
        if(s[n-1] == 'x'){
            if(ans[n-2] != ans[0]){
                return -1;
            }
        }else{
            if(ans[n-2] == ans[0]){
                return -1;
            }
        }
    }
    if(ans[0] == 'S'){
        if(s[0] == 'o'){
            if(ans[1] != ans[n-1]){
                return -1;
            }
        }else{
            if(ans[1] == ans[n-1]){
                return -1;
            }
        }
    }else{
        if(s[0] == 'x'){
            if(ans[1] != ans[n-1]){
                return -1;
            }
        }else{
            if(ans[1] == ans[n-1]){
                return -1;
            }
        }
    }
    return 1;
}

int main(){
    cin >> n >> s;
    vector<char> ans1(n), ans2(n), ans3(n), ans4(n);
    ans1[0] = 'S';ans1[1] = 'S';
    ans2[0] = 'W';ans2[1] = 'W';
    ans3[0] = 'S';ans3[1] = 'W';
    ans4[0] = 'W';ans4[1] = 'S';
    if(solve(ans1) == 1){
        for(int i = 0; i < n; i++){
            cout << ans1[i];
        }
    }else if(solve(ans2) == 1){
        for(int i = 0; i < n; i++){
            cout << ans2[i]; 
        }
    }else if(solve(ans3) == 1){
        for(int i = 0; i < n; i++){
            cout << ans3[i];
        }
    }else if(solve(ans4) == 1){
        for(int i = 0; i < n; i++){
            cout << ans4[i];
        }
    }else{
        cout << -1;
    }
    return 0;
}