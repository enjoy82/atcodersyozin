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

vector<int> divisor(int n) {
    vector<int> ret;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    //sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

int main(){
    int n; cin >> n;
    vector<int> lis(n);
    map<int, int> mp;
    int ans = 0;
    REP(i, 0, n){cin >> lis[i]; mp[lis[i]]++;}
    if(mp[1] == 1){
        cout << 1 << endl;
        return 0;
    }else if(mp[1] > 1){
        cout << 0 << endl;
        return 0;
    }
    REP(i, 0, n){
        vector<int> r = divisor(lis[i]);
        int f = 1;
        if(mp[lis[i]] != 1){
            f = 0;
            continue;
        }
        REP(l, 0, r.size()){
            if(r[l] == lis[i]){
                continue;
            }
            if(mp[r[l]] >= 1){
                f = 0;
                break;
            }
        }
        ans += f;
    }
    cout << ans << endl;
}