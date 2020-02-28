#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

typedef pair<ll, ll> p;

int main(){
    map<p, int> mp;
    int n; cin >> n;
    vector<ll> x(n), y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < n; i++){
        for(int l = 0; l < n; l++){
            if(i == l)  continue;
            p z = {x[i] - x[l], y[i] - y[l]};
            mp[z]++;
        }
    }
    int max = 0;
    for(auto x:mp) {
        if(max < x.second){
            max = x.second;
        }
    }
    cout << n - max << endl;
}