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
    int n; cin >> n;
    int ans = 0;
    vector<ll> lis(n);
    REP(i, 0, n){cin >> lis[i];}
    REP(i, 0, n-2){
        REP(l, i+1, n-1){
            REP(k, l+1, n){
                vector<int> mid(3, 0);
                mid[0] = lis[i];
                mid[1] = lis[l];
                mid[2] = lis[k];
                sort(ALL(mid));
                if(mid[0] + mid[1] > mid[2] && mid[0] != mid[1] && mid[1] != mid[2]){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}