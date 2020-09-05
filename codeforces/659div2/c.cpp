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
    int n; cin >> n;
    string as, bs; cin >> as >> bs;
    vector<int> flag(26, 0);
    vector<vector<int> > allis(26, vector<int>(26, 0));
    REP(i, 0, n){
        if(as[i] - 'a' > bs[i]-'a'){
            cout << -1 << endl;
            return;
        }
    }
    REP(i, 0, n){
        flag[as[i]-'a']++;
        allis[as[i]-'a'][bs[i]-'a']++;
    }
    /*REP(i, 0, 25){
        REP(l, 0, 26){
            allis[i+1][l] = allis[i][l] + allis[i+1][l];
        }
    }*/
    int ans = 0;
    int count = 0;
    vector<int> al(26, 0);
    REP(i, 0, 25){
        int f = 0, idx = 0;
        int count = 0;
        REP(l, i+1, 26){
            if(allis[i][l] > 0){
                f = 1;
                idx = l;
                break;
            }
        }
        if(f == 1){
            ans++;
            REP(l, i+1, 26){
                allis[idx][l] += allis[i][l];
            }
        }
    }
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}