#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(ll i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

const ll INF = 1e15;

int main(){
    ll n, l; cin >> n >> l;
    vector<ll> dp(l+10, INF);
    vector<ll> lis(l+10, 0);
    REP(i, 0, n){
        ll a; cin >> a;
        lis[a] = 1;
    }
    ll t1, t2, t3; cin >> t1 >> t2 >> t3;
    dp[0] = 0;
    REP(i, 1, l+10){
        //行動１
        ll pt1;
        if(lis[i] == 1){
            pt1 = t1 + t3;
        }else{
            pt1 = t1;
        }
        dp[i] = min(dp[i], dp[i-1] + pt1);

        //行動２
        ll pt2;
        if(i < 2){
            continue;
        }else{
            if(lis[i] == 1){
                pt2 = t1 + t2 + t3;
            }else{
                pt2 = t1 + t2;
            }
            dp[i] = min(dp[i], dp[i-2] + pt2);
        }

        //行動３
        ll pt3;
        if(i < 4){
            continue;
        }else{
            if(lis[i] == 1){
                pt3 = t1 + 3 * t2 + t3;
            }else{
                pt3 = t1 + 3 * t2;
            }
            dp[i] = min(dp[i], dp[i-4] + pt3);
        }
    }
    if(l-3 >= 0){
        dp[l] = min(dp[l], dp[l-3] + t1/2 + (t2/2)*5);
    }
    if(l-2 >= 0){
        dp[l] = min(dp[l], dp[l-2]+t1/2+(t2/2)*3);
    }
    dp[l] = min(dp[l], dp[l-1]+t1/2+t2/2);
    cout << dp[l] << endl;
    return 0;
}