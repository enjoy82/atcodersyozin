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

int check(string s){
    REP(i, 0, s.size()){
        if(s[i] == '.'){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n, r; cin >> n >> r;
    string s; cin >> s;
    int last = -1;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == '.'){
            last = i;
            break;
        }
    }
    if(last != -1 && last < r-1){
        cout << 1 << endl;
        return 0;
    }
    int f = 0;
    REP(i, 0, n){
        if(s[i] == '.'){
            f = 1;
        }
    }
    if(f){
        int ans = 0;
        REP(i, 0, n){
            //cout << s << endl;
            if(r + i - 1 == last){
                ans++;
                cout << ans << endl;
                return 0;
            }
            if(s[i] == '.'){
                REP(l, i, r+i){
                    s[l] = 'o';
                }
                ans++;
            }
            if(check(s)){
                cout << ans << endl;
                return 0;
            }
            ans++;
        }
        cout << ans << endl;
    }else{
        cout << 0 << endl;
    }
}