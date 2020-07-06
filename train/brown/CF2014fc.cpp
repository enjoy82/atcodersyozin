#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(ll i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

ll Pow(ll  x, ll n){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return Pow(x * x, n / 2);
  else
    return x * Pow(x, n - 1);
}


char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    ll a; cin >> a;
    REP(i, 10, 100000){
        ll sum = 0;
        ll k = i;
        int n = 0;
        while(1){
            ll c = k % 10;
            sum += Pow(i, n) * c;
            k /= 10;
            n++;
            if(k == 0){break;}
        }
        if(sum == a){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}