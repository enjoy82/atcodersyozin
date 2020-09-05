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
    int n, m, k; cin >> n >> m >> k;
    vector<int> lis(n);
    REP(i,0,n){cin >> lis[i];}
    int free = max(m - k - 1, 0);
    if(k > m-1){
        k = m-1;
    }
    int left = k, right = 0;
    int ans = 0;
    //don't over
    REP(i, 0, k+1){
        //cout << left << right << endl;
        int mid = 1e9;
        REP(i, 0, free+1){ //あり得る
            int l1 = left + i, r1 = right + (free - i);
            int mid1 = max(lis[l1], lis[n-1-r1]);
            chmin(mid, mid1);
        }
        left--;
        right++;
        chmax(ans, mid);
    }
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}