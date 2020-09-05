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
    vector<string> clis(n);
    REP(i, 0, n){cin >> clis[i];}
    vector<vector<int> > ans(n, vector<int>(m, 0)), lis(n, vector<int>(m, 0));
    REP(i, 0, n){
        REP(l, 0, m){
            lis[i][l] = clis[i][l] - '0';
        }
    }
    REP(i, 1, n-1){
        REP(l, 1, m-1){
            if(lis[i-1][l] >= 1 && lis[i][l-1] >= 1 && lis[i][l+1] >= 1 && lis[i+1][l] >= 1){
                int k =  min({lis[i-1][l], lis[i][l-1], lis[i][l+1], lis[i+1][l]});
                ans[i][l] += k;
                REP(j, 0, 4){
                    lis[i+dx[j]][l+dy[j]] -= k;
                }
            }
        }
    }
    REP(i, 0, n){
        REP(l, 0, m){
            cout << ans[i][l];
        }
        cout << endl;
    }
}