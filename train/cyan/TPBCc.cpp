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
    ll n; cin >> n;
    map<ll, ll>mp;
    REP(i, 2, 1e5){
        ll c = (i * (i-1))/2;
        mp[c] = i;
        if(c > 1e6){
            break;
        }
    }
    if(mp[n] > 0){
        cout << "Yes" << endl << mp[n] << endl;
        vector<vector<ll> > lis(mp[n], vector<ll>());
        int count = 1;
        REP(i, 0, mp[n]-1){
            REP(l, i+1, mp[n]){
                lis[i].pb(count);
                lis[l].pb(count);
                count++;
            }
        }
        REP(i, 0, mp[n]){
            cout << lis[i].size() << " ";
            REP(l, 0, lis[i].size()){
                cout << lis[i][l] << " ";
            }
            cout << endl;
        }
    }else{
        cout << "No" << endl;
    }
}