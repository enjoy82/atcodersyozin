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

ld pi = 3.14159265359;

int main(){
    int n, q; cin >> n >> q;
    vector<vector<ld>> lis(n, vector<ld>(3));
    REP(i, 0, n){
        cin >> lis[i][0] >> lis[i][1] >> lis[i][2];
    }
    REP(i, 0, q){
        ld ans = 0;
        ld a, b; cin >> a >> b;
        REP(l, 0, n){  
            ld x = lis[l][0], r = lis[l][1], h = lis[l][2];
            if(b <= x || a >= x + h){
                continue;
            }else{
                if(a <= x){
                    if(b <= x + h){
                        ld R = (r * (x + h - b)) / h;
                        ans += ((r * r * h) - (R * R * (x+h-b)))/3;
                    }else{
                        ans += r * r * h / 3;
                    }
                }else{
                    if(b <= x + h){
                        ld R = (r * (x + h - a)) / h;
                        ld R1 = (r * (x + h - b)) / h;
                        ans += ((R * R * (x+h-a)) - (R1 * R1 * (x+h-b))) / 3;
                    }else{
                        ld R = (r * (x + h - a)) / h;
                        ans += R * R * (x+h-a) / 3;
                    }
                }
            }
        }
        cout << std::fixed << std::setprecision(15) << ans * pi << endl;
    }
}