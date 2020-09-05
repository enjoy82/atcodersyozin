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
    int INF = 1e9;
    int n, k, l; cin >> n >> k >> l;
    vector<int> dlis(n);
    vector<int> plis;
    REP(i, 0, k+1){plis.pb(i);}
    for(int i = k-1; i >= 0; i--){plis.pb(i);}
    REP(i, 0, n){cin >> dlis[i];}
    REP(i, 0, 2 * k + 10){
        int t = i;
        int f = 1;
        REP(j, 0, n){
            int pret = t;
            while(dlis[j] + plis[(t+1) % (2*k)] > l){
                t++;
                if(t - pret > 250 || (j-1>= 0 && (dlis[j-1] + plis[t % (2*k)] > l))){
                    f = 0;
                    break;
                }
            }
            t++;
        }
        if(f == 1){
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}