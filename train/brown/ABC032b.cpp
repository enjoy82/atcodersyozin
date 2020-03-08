#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    string s; cin >> s;
    int k; cin >> k;
    map<string, int> mp;
    for(int i = 0; i + k <= s.size(); i++){
        mp[s.substr(i, k)]++;
    }
    int ans = 0;
    for(auto &x: mp){
        ans++;
    }
    cout << ans << endl;
}