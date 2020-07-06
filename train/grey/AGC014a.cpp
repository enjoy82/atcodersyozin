#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    ll a, b, c; cin >> a >> b >> c;
    if(a != 1 && a == b && b == c){
        cout << -1 << endl;
        return 0;
    }
    int count = 0;
    while(1){
        if(a % 2 == 0 && b % 2 == 0 && c % 2 == 0){
            count++;
            ll ha = a/2, hb = b/2, hc = c/2;
            a = hb+hc; b = ha+hc; c = ha+hb;
        }else{
            break;
        }
    }
    cout << count << endl;
}