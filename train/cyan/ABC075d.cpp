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
    int n, k; cin >> n >> k;
    vector<ll> column, row;
    vector<vector<ll>> lis(n, vector<ll>(2));
    REP(i, 0, n){
        cin >> lis[i][0] >> lis[i][1];
        lis[i][0] += 1e9;
        lis[i][1] += 1e9;
    }
    sort(ALL(lis), [](auto &x, auto &y){return x[0] < y[0];});
    map<ll, int> mp, mp1;
    REP(i, 0, n){
        if(mp[lis[i][0]] == 0){
            mp[lis[i][0]] = i;
            column.pb(lis[i][0]);
        }else{
            continue;
        }
    }
    sort(ALL(lis), [](auto &x, auto &y){return x[1] < y[1];});
    REP(i, 0, n){
        if(mp1[lis[i][1]] == 0){
            mp1[lis[i][1]] = i;
            row.pb(lis[i][1]);
        }else{
            continue;
        }
    }
    cout << endl;
    vector<vector<ll> > assyuku(column.size(), vector<ll>(row.size(), 0));
    REP(i, 0, n){
        int ci = mp[lis[i][0]], ri = mp1[lis[i][1]];
        assyuku[ci][ri]++;
    }
    /*REP(i, 0, column.size()){
        REP(l, 0, row.size()){
            cout << assyuku[i][l];
        }
        cout << endl;
    }*/
    ll ans = 5e18;
    REP(i, 0, column.size()){
        REP(l, 0, row.size()){
            REP(j, i, column.size()){
                REP(m, l, row.size()){
                    int count = 0;
                    REP(a, i, j+1){
                        REP(b, l, m+1){
                            count += assyuku[a][b];
                        }
                    }
                    if(count >= k){
                        ll c1 = column[i], c2 = column[j], r1 = row[l], r2 = row[m];
                        chmin(ans, (c1-c2)*(r1-r2));
                    }
                }
            }
        }
    }
    cout << ans << endl;
}