#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    map<string, int> m;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        m[s]++;
    }
    int ans = 0;
    for(auto &x: m){
        ans = max(ans, x.second);
    }
    vector<string> lis;
    for(auto &x: m){
        if(x.second == ans){
            lis.push_back(x.first);
        }
    }
    sort(lis.begin(), lis.end());
    for(int i = 0; i < lis.size(); i++){
        cout << lis[i] << endl;
    }
    return 0;
}