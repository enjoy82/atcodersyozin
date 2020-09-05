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
    int n; cin >> n;
    ll ans = 0;
    vector<vector<vector<int>>> lis(21, vector<vector<int>>(21, vector<int>(11, 0)));
    REP(i, 0, n){
        string s; cin >> s;
        ll k = 0;
        int count = 0;
        REP(l, 0, s.size()){
            if(s[l] == '.'){
                count = s.size() - l - 1;
                continue;
            }
            k *= 10;
            k += (s[l] - '0');
        }
        //cout << count << endl;
        int c5 = 0, c2 = 0;
        while(k % 5 == 0){
            k /= 5;
            c5++;
        }
        while(k % 2 == 0){
            k /= 2;
            c2++;
        }
        REP(l, 0, 21){
            REP(k, 0, 21){
                REP(j, 0, 11){
                    int aa = c2 + l, bb = c5 + k;
                    int cc = min(aa, bb);
                    if(count + j <= cc){
                        ans += lis[l][k][j];
                    }
                }
            }
        }
        lis[min(c2, 20)][min(c5, 20)][count]++;
    }
    cout << ans << endl;
}