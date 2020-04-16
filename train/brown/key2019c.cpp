#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    vector<ll> alis(n), blis(n), aplus;
    ll asum = 0, bsum = 0, bminus = 0, cnum = 0;
    for(int i = 0; i < n; i++){
        cin >> alis[i];
        asum += alis[i];
    }
    for(int i = 0; i < n; i++){
        cin >> blis[i];
        bsum += blis[i];
    }
    if(asum < bsum){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        ll c = alis[i] - blis[i];
        if(c >= 0){
            aplus.push_back(c);
        }else{
            bminus += -1 * c;
            cnum++;
        }
    }
    if(bminus == 0){
        cout << 0 << endl;
        return 0;
    }
    ll mid = 0;
    sort(aplus.begin(), aplus.end(), greater<>());
    for(int i = 0; i < aplus.size(); i++){
        mid += aplus[i];
        if(mid >= bminus){
            cout << i + 1 + cnum << endl;
            return 0;
        }
    }
}