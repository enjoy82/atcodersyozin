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
    ll n, k; cin >> n >> k;
    vector<vector<int> > lis(n, vector<int>(n, 0));
        vector<Pii> next;
        next.pb(Pii(n-1, n-1));
        int x = 0, y = 0;
        REP(i, 0, n-1){
            x++;
            next.pb(Pii(x, 0));
            next.pb(Pii(n-1-x, n-1));
        }
        ll count = 0;
        REP(i, 0, next.size()){
            Pii a = next[i];
            int nx = a.first, ny = a.second;
            //cout << nx << ny << endl;
            if(i % 2 == 1){
                while(count < k && nx < n && ny < n){
                    lis[nx][ny] = 1;
                    nx++; ny++;
                    count++;
                }
            }else{
                while(count < k && nx >= 0 && ny >= 0 ){
                    lis[nx][ny] = 1;
                    nx--; ny--;
                    count++;
                }
            }
        }
        int rmax = 0, rmin = 1e9, cmax = 0, cmin = 1e9;
        
        REP(i, 0, n){
            int mid = 0;
            REP(l, 0, n){
                mid += lis[i][l];
            }
            chmax(rmax, mid);
            chmin(rmin, mid);
        }
        REP(i, 0, n){
            int mid = 0;
            REP(l, 0, n){
                mid += lis[l][i];
            }
            chmax(cmax, mid);
            chmin(cmin, mid);
        }
        //cout << rmax << rmin << cmax << cmin  << endl;
        ll ans = (rmax - rmin) * (rmax - rmin) + (cmax - cmin) * (cmax - cmin);
        cout << ans << endl;
        REP(i, 0, n){
            REP(l, 0, n){
                cout << lis[i][l];
            }
            cout << endl;
        }
    
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}