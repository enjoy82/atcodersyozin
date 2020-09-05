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
    int pre = 0;
    REP(l, 0, n){
        //cout << l << endl;
        pre = 0;
        int st = l;
        int f = 0;
        while(l < n && lis[l] > pre){
            pre = lis[l];
            l++;
            f++;
        }
        if(l == st){
            pre = lis[l];
            l++;
        }
        while(l < n && lis[l] < pre){
            pre = lis[l];
            l++;
            f++;
        }
        if(f == 2 || st == 0 && f == 1){
            chmax(ans, min(l, n-1)-st+1);
            l--;
        }
        if(f > 1)
            chmax(ans, min(l, n-1)-st+1);
    }
    cout << ans << endl;
}