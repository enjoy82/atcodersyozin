#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

vector<ll> divisor(ll n) {
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

int main()
{
	vector<ll> r = divisor(10);
	for(auto i : r) cout << i << endl;
	return 0;
}