#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    map<ll, ll> m; 
    for(int i = 0; i < n; i++){
        ll a; cin >> a;
        m[a]++;
        if(m[a] == 2){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}