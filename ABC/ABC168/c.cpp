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
    double pi = 3.14159265359;
    double a, b, h, m; cin >> a >> b >> h >> m;
    double sita1 = (60 * h + m) / 2;
    double sita2 = m * 6; 
    double ans = (a * a) + (b * b) - (2.0 * a * b * cos(pi * (sita1-sita2) / 180));
    cout << std::fixed << std::setprecision(20) << pow(ans, 0.5)  << endl;
}