// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
//#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
//using namespace atcoder;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

template<class T>inline bool chmax(T &a, T b) {if(a < b) {a = b;return true;}return false;}
template<class T>inline bool chmin(T &a, T b) {if(a > b) {a = b;return true;}return false;}


char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};


int main(){
    int n; cin >> n;
    vector<int> D(13, 0);
    D[0]++;
    REP(i, 0, n){
        int a; cin >> a;
        D[a]++;
        if(D[a] >= 3){
            cout << 0 << endl;
            return 0;
        }
    }
    if(D[12] >= 2){
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    D[0]--;
    REP(i, 0, (1 << 13)){
        int s = 30;
        vector<int> time(25, 0);
        time[0]++;
        REP(l, 0, 13){
            if(D[l] == 1){
                if(i & (1 << l)){
                    time[24 - l]++;
                }else{
                    if(l == 0)
                        s = 0;
                    time[l]++;
                }
            }else if(D[l] == 2){
                time[l]++;
                time[24-l]++;
            }
        }
        REP(l, 0, 25){
            REP(k, l+1, 25){
                if(time[l] && time[k]){
                    chmin(s, min(k-l, 24-(k-l)));
                }
            }
        }
        chmax(ans, s);
    }
    cout << ans << endl;
}