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

const ld pi = 3.14159265359;

int main(){
    ld a, b, c; cin >> a >> b >> c;
    a = a * 1.0; b = b * 1.0; c = c * 1.0;
    ld r = 5000.0, l = 0.0;
    while(r - l >= 0.000000000001){
        ld mid = (r + l) / 2.0;
        ld k = a * mid + b * sin(c * mid * pi);
        if(k > 100.000000000000000){
            r = mid;
        }else{
            l = mid;
        }
    }
    //cout << std::fixed << std::setprecision(15) << a * r + b * sin(c * r * pi) << endl;
    cout << std::fixed << std::setprecision(20) << r << endl;
}