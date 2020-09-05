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
    int n; cin >> n;
    string s, t; cin >> s >> t;
    vector<int> ans;
    int count = 0;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == t[i]) continue;
        if(s[0] == t[i]){
            ans.pb(1);
            if(s[i] == '1'){
                s[0] = '0';
            }else{
                s[0] = '1';
            }
        }
        string cs = s;
        REP(l, 0, i+1){
            if(s[l] == '1'){
                s[l] = '0';
            }else{
                s[l] = '1';
            }
        }
        ans.pb(i+1);
        REP(l, 0, i+1){
            cs[l] = s[i - l];
        }
        //cout << cs << endl;
        s = cs;
    }
    cout << ans.size() << " ";
    REP(i, 0, ans.size()){
        cout << ans[i] << " "; 
    }
    cout << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}