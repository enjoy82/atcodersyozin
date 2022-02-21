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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    reverse(ALL(s));
    vector<int> ans;
    int now = 0;
    while(1){
        int next = 0;
        int f = 0;
        REP(i, 1, m+1){
            if(s[now + i] == '0'){
                if(now+i == n){
                    ans.pb(i);
                    f = 1;
                    break;
                }
                chmax(next, i);
            }
        }
        if(f){
            break;
        }
        if(next == 0){
            cout << -1 << endl;
            return 0;
        }else{
            ans.pb(next);
            now = now + next;
        }
    }
    REP(i, 0, ans.size()){
        cout << ans[ans.size()-i-1] << " ";
    }
    cout << endl;
}