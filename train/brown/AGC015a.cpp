#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll n, a, b; cin >> n >> a >> b;
    if(b < a){cout << 0 << endl; return 0;}
    if(n ==1 && a != b){cout << 0 << endl; return 0;}
    else if(n == 1){cout << 1 << endl; return 0;}
    cout << (n*b - (b-a)) - (n*a + (b-a)) + 1 << endl;
}