#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll n, p; cin >> n >> p;
    string s; cin >> s;
    vector<int> lis(p+1, -1);
    for(int i = 0; i < s.size(); i++){
        lis[s[i]-'0'] = 1;
        if(i == 0){
            continue;
        }
        vector<int> lis2(p+1, -1);
        for(int l = 0; l < p; l++){
            if(lis[l] != -1){
                lis2[(l+(s[i]-'0'))%p] = lis[l] + 1;
                lis2[l] = 0;
            }
        }
        lis = lis2;
    }
    cout << lis[0] << endl;
}