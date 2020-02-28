#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll n, k, s; cin >> n >> k >> s;
    int  i = 0;
    for(i =0; i < k; i++){
        cout << s << " ";
    }
    if(s == 1000000000){s -= 3;}
    for(; i < n ; i++){
        cout << s+1 << " ";
    }
}