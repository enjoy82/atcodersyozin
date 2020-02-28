#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        if(s[i] == s[i+1]){
            ans++;
        }
    }
    ans += 2*k;
    if(ans > n-1){
        ans = n-1;
    }
    cout << ans << endl;
}