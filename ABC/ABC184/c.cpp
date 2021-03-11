// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
//#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
//using namespace atcoder;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(ll i=(l), i##_len=(n); i<i##_len; ++i)
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

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示

int main(){
    ll r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
    if(r1 == r2 && c1 == c2){
        cout << 0 << endl;
        return 0;
    }
    ll a = r2 - r1, b = c2 - c1;
    if(a == -1 * b || a == b){
        cout << 1 << endl;
        return 0;
    }
    int f = 0;
    REP(i, r1 - 5, r1 + 5){
        REP(l, c1 - 5, c1 + 5){
            if(abs(i - r1) + abs(l - c1) <= 3){
                ll a = r2 - i, b = c2 - l;
                if((r2 == i) && (c2 == l)){
                    cout << 1 << endl;
                    return 0;
                }
                if(a == -1 * b || a == b){
                    f = 1;
                }
            }else{
                continue;
            }
        }
    }
    if(f == 1){
        cout << 2 << endl;
        return 0;
    }
    if(((r1 + r2 - c1 + c2) % 2  == 0) || ((r1 + r2 + c1 - c2) % 2 == 0)){
        cout << 2 << endl;
        return 0;
    }
    REP(i, r1 - 10, r1 + 10){
        REP(l, c1 - 10, c1 + 10){
            if(abs(i - r1) + abs(l - c1) <= 6){
                if((r2 == i) && (c2 == l)){
                    cout << 2 << endl;
                    return 0;
                }
            }else{
                continue;
            }
        }
    }
    cout << 3 << endl;
}