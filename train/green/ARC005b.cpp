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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int x, y; cin >> x >>  y;
    x--; y--;
    string vec[8] = {"R", "L", "U", "D", "RU", "RD", "LU", "LD"};
    int xvec[8] = {1, -1, 0, 0, 1, 1, -1, -1};
    int yvec[8] = {0, 0, -1, 1, -1, 1, -1, 1};
    string s; cin >> s;
    int key;
    REP(i, 0, 8){
        if(s == vec[i]){
            key = i;
            break;
        }
    }
    int xv = xvec[key], yv = yvec[key];
    vector<string> lis(9);
    REP(i, 0, 9){cin >> lis[i];}
    string ans = "";
    REP(i, 0, 4){
        ans = ans + lis[y][x];
        if(x + xv < 0 || x + xv >= 9){
            xv *= -1;
        }
        if(y + yv < 0 || y + yv >= 9){
            yv *= -1;
        }
        x += xv;
        y += yv;
    }
    cout << ans << endl;
}