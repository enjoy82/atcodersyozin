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
    string s; cin >> s;
    vector<ll> solo(10, 0);
    REP(i, 0, s.size()){
        solo[s[i]-'0']++;
    }
    ll sum = 0;
    REP(i, 0, 10){
        chmax(sum, solo[i]);
    }
    vector<vector<ll> > doblis(10, vector<ll>(10, 0));
    vector<vector<ll> > countlis(10, vector<ll>(10, 0));
    REP(i, 0, s.size()){
        int key = s[i] - '0';
        REP(l, 0, 10){
            if(doblis[key][l] == 1){
                doblis[key][l] = 0;
                countlis[key][l] += 2;
            }
        }
        REP(l, 0, 10){
            doblis[l][key] = 1;
        }
    }
    REP(i, 0, 10){
        REP(l, 0, 10){
            if(i == l) continue;
            chmax(sum, countlis[i][l]);
        }
    }
    cout << s.size() - sum << endl;
} 

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}