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

int main(){
    int q, x; cin >> q >> x;
    vector<ll> modlis(x, 0), modres(x, 0), flag(5e5, 0);
    int cc = x;
    REP(i, 0, x){
        modres[i] -= cc;
        cc--;
    }
    int ans = 0;
    REP(i, 0, q){
        int a; cin >> a;
        modlis[a % x]++;
        modres[a % x] += x;
        if(modres[a%x] < 5e5){
            //cout << "OK " << modres[a%x] << endl;
            flag[modres[a%x]] = 1;
        }
        while(flag[ans] == 1){
            ans++;
        }
        cout << ans << endl;
    }
}