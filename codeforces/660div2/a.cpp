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

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve(){
    ll n; cin >> n;
    vector<int> lis{6, 10, 14, 15, 21}; 
    REP(i, 0, 3){
        REP(l, i+1, 4){
            REP(k, l+1, 5){
                ll c = n - (lis[i] + lis[l] + lis[k]);
                if(c >= 1 && !(c == lis[i] || c == lis[l] || c == lis[k])){
                    cout << "YES" << endl;
                    cout << lis[i] << " " << lis[l] << " " << lis[k] << " " << c << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
}

int main(){
    int t;cin >> t;
    REP(i, 0, t){solve();}
}