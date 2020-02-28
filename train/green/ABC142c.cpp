#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int toi(char a){
    return a - '0';
}

int main(){
    int n; cin >> n;
    int k; cin >> k;
    vector<int> flag(10, 0);
    for(int i = 0; i < k; i++){
        int a; cin >> a;
        flag[a] = 1;
    }
    int ans = 100000;
    for(int i = 100000; i >= n; i--){
        string s = to_string(i);
        int f = 0;
        for(int l = 0; l < s.size(); l++){
            if(flag[toi(s[l])] == 1){
                f = 1;
                break;
            }
        }
        if(f == 1){continue;}
        else{
            ans = i;
        }
    }
    cout << ans << endl;
}