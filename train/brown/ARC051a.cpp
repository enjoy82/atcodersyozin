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
    int x1, y1, r; cin >> x1 >> y1 >> r;
    x1 += 250; y1 += 250;
    vector<vector<int> > grid(500, vector<int>(500, 0));
    REP(x, 0, 500){
        REP(y, 0, 500){
            if( ((x-x1)*(x-x1) + (y-y1)*(y-y1)) <= r*r ){
                grid[x][y] = 1;
            }
        }
    }
    int x2, x3, y2, y3; cin >> x2 >> y2 >> x3 >> y3;
    x2 += 250; x3 += 250; y2 += 250; y3 += 250;
    REP(i, x2, x3+1){
        REP(l, y2, y3+1){
            //cout << i << l << endl;
            if(grid[i][l] == 1){
                grid[i][l] = 3;
            }else{
                grid[i][l] = 2;
            }
        }
    }
    int bf = 0, rf = 0;
    REP(i, 0, 500){
        REP(l, 0, 500){
            if(grid[i][l] == 1){
                rf = 1;
            }else if(grid[i][l] == 2){
                bf = 1;
            }
        }
    }
    if(rf == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    if(bf == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}