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
    string s; cin >> s;
    vector<vector<int>> lis(n+1, vector<int>(4, 0));
    REP(i, 0, n){
        lis[i+1] = lis[i];
        if(s[i] == 'A'){
            lis[i+1][0]++;
        }else if(s[i] == 'T'){
            lis[i+1][1]++;
        }else if(s[i] == 'G'){
            lis[i+1][2]++;
        }else{
            lis[i+1][3]++;
        }
    }
    int ans = 0;
    REP(i, 0, n){
        REP(l, i+1, n+1){
            int ca = lis[l][0] - lis[i][0], ct = lis[l][1] - lis[i][1], cg = lis[l][2] - lis[i][2], cc = lis[l][3] - lis[i][3];
            if(ca == ct && cg == cc){
                ans++;
            }
        }
    }
    cout << ans << endl;
}