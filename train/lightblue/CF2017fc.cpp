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

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
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


int main(){
    int n; cin >> n;
    vector<int> flag(13, 0);
    flag[0]++;
    REP(i, 0, n){
        int a; cin >> a;
        flag[a]++;
    }
    int ans = 0;
    REP(i, 0, (1 << 12)){
        vector<int> used(25, 0);
        used[0] = flag[0];
        used[12] = flag[12];
        int s = 1e9;
        REP(l, 0, 13) {
            if(flag[0] == 0) continue;
            if(flag[l] == 2) {
                used[l] = used[24-l] = 1;
            }
            if(flag[l] == 1){
                if((i & (1 << (l-1))) == 1){
                    used[24-l] = 1;
                }else{
                    used[l] = 1;
                }
            }
            if(flag[l] >= 3){
                s = 0;
            }
        }
        REP(l, 0, 25){
            REP(k, 0, 25){
                if(l != k && used[l] == 1 && used[k] == 1){
                    int mid = min(abs(l-k) , 24 - abs(l-k));
                    chmin(s, mid);
                }
            }
        }
        //cout << s << endl;
        chmax(ans, s);
    }
    cout << ans << endl;
}