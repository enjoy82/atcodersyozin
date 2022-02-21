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
    int n; cin >> n;
    int ans = 0;
    vector<ll> xlis(n), ylis(n);
    REP(i, 0, n){cin >> xlis[i] >> ylis[i];}
    REP(i, 0, n-2){
        REP(l, i+1, n-1){
            REP(j, l+1, n){
                ll dx = xlis[l] - xlis[i], dy = ylis[l] - ylis[i],
                    dx1 = xlis[j] - xlis[i], dy1 = ylis[j] - ylis[i];
                if((dx * dy1) != (dy * dx1)){
                    if(abs(dx*dy1-dy*dx1) % 2 == 0){
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}