#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int mod = 1000000007;

int main(){
    int n; cin >> n;
    ll ans = 1;
    vector<int> flag(n);
    for(int i = 0; i < n; i++){
        int mid; cin >> mid;
        flag[mid]++;
        if(flag[mid] > 2){
            cout << 0 << endl;
            return 0;
        }
    }
    if(n % 2 == 0 && flag[0] != 0){cout << 0 << endl; return 0;}
    for(int i = 0; i < n; i++){
        if(flag[i] == 2){
            ans = ans * 2 % mod;
        }else if(flag[i] == 1 && i != 0){
            cout << 0 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}