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

int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int main(){
    ll h, w, n; cin >> h >> w >> n;
    vector<ll> anslis(10, 0);
    map<Pii, int> mp;
    anslis[0] = (h-2) * (w-2);
    REP(i, 0, n){
        int a, b; cin >> a >> b;
        a--; b--;
        mp[Pii(a, b)]++;
        REP(l, 0, 9){
            int na = a + dx[l], nb = b + dy[l]; 
            int count = 0, f = 1;
            REP(k, 0, 9){
                int nx = na + dx[k], ny = nb + dy[k];
                if(nx < 0 || ny < 0 || nx >= h || ny >= w){
                    f = 0;
                    break;
                }
                if(nx == a && ny == b){
                    continue;
                }else{
                    if(mp[Pii(nx, ny)] == 1){
                        count++;
                    }
                }
            }
            if(f){
                anslis[count]--;
                anslis[count+1]++;
            }
        }
    }
    REP(i, 0, 10){
        cout << anslis[i] << endl;
    }
}