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
    int h, w, n; cin >> h >> w >> n;
    int x, y; cin >> x >> y;
    string s, t; cin >> s >> t;
    int f = 0;
    int ny = y;
    REP(i, 0, n){
        if(s[i] == 'L'){
            ny--;
        }
        if(ny <= 0){
            f = 1;
        }
        if(t[i] == 'R'){
            ny = min(ny+1, w);
        }
        if(ny <= 0){
            f = 1;
        }
    }
    ny = y;
    REP(i, 0, n){
        if(s[i] == 'R'){
            ny++;
        }
        if(ny > w){
            f = 1;
        }
        if(t[i] == 'L'){
            ny = max(ny-1, 1);
        }
        if(ny > w){
            f = 1;
        }
    }
    int nx = x;
    REP(i, 0, n){
        if(s[i] == 'U'){
            nx--;
        }
        if(nx <= 0){
            f = 1;
        }
        if(t[i] == 'D'){
            nx = min(nx+1, h);
        }
        if(nx <= 0){
            f = 1;
        }
    }
    nx = x;
    REP(i, 0, n){
        if(s[i] == 'D'){
            nx++;
        }
        if(nx > h){
            f = 1;
        }
        if(t[i] == 'U'){
            nx = max(nx-1, 1);
        }
        if(nx > h){
            f = 1;
        }
    }
    if(f == 1){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
}