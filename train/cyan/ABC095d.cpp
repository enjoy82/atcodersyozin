#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

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
    ll n, c; cin >> n >> c;
    vector<vector<ll> > lis(n, vector<ll>(2, 0));
    REP(i, 0, n){
        cin >> lis[i][0] >> lis[i][1];
    }
    vector<vector<ll>> right(n+1, vector<ll>(2, 0)), left(n+1, vector<ll>(2, 0));
    REP(i, 0, n){
        right[i+1][1] = right[i][1] + lis[i][1];
        right[i+1][0] = lis[i][0];
    }
    REP(i, 0, n){
        ll a = right[i+1][1] - right[i+1][0];
        ll b = right[i][1] - right[i][0];
        if(b > a){
            right[i+1] = right[i];
        }
        //cout << right[i+1][0] << " " << right[i+1][1] << endl;
    }
    REP(i, 0, n){
        left[i+1][1] = left[i][1] + lis[n-i-1][1];
        left[i+1][0] = c - lis[n-i-1][0];
    }
    REP(i, 0, n){
        ll a = left[i+1][1] - left[i+1][0];
        ll b = left[i][1] - left[i][0];
        if(b > a){
            left[i+1] = left[i];
        }
        //cout << left[i+1][0] << " " << left[i+1][1] << endl;
    }
    ll ans = 0;
    REP(i, 0, n+1){
        ll a;
        if(left[n-i][1] - left[n-i][0] - right[i][0] > 0){
            a = (right[i][1] - right[i][0]) + (left[n-i][1] - left[n-i][0]) - right[i][0];
        }else{
            a = (right[i][1] - right[i][0]);
        }
        ans = max(ans, a);
    }
    REP(i, 0, n+1){
        ll a;
        if(right[n-i][1] - right[n-i][0] - left[i][0] > 0){
            a = (left[i][1] - left[i][0]) + (right[n-i][1] - right[n-i][0]) - left[i][0];
        }else{
            a = (left[i][1] - left[i][0]);
        }
        ans = max(ans, a);
    }
    cout << ans << endl;
}