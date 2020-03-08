#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll n, a, b; cin >> n >> a >> b;
    ll k = a + b;
    ll c = n / k;
    n = n - c * k;
    if(n >= a){
        cout << c * a + a << endl;
    }else{
        cout << c * a + n << endl;
    }
}