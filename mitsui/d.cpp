#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;
string s;
int toi(char c){
    return (int)c - '0';
}

int solve(int v){
    int a = v / 100;
    int i = 0;
    int f = 0;
    for(; i < n; i++){
        if(a == toi(s[i])){
            i++;
            f = 1;
            break;
        }
    }
    if(f == 0){
        return 0;
    }
    f = 0;
    a = (v / 10) % 10;
    for(; i < n; i++){
        if(a == toi(s[i])){
            i++;
            f = 1;
            break;
        }
    }
    if(f == 0){
        return 0;
    }
    f = 0;
    a = v % 10;
    for(; i < n; i++){
        if(a == toi(s[i])){
            f = 1;
            break;
        }
    }
    if(f == 0){
        return 0;
    }
    return 1;
}

int main(){
    cin >> n;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < 1000; i++){
        ans += solve(i);
    }
    cout << ans << endl;
}