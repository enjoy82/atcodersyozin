#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int main(){
    int h, w; cin >> h >> w;
    vector<string> lis(h);
    REP(i, 0, h){cin >> lis[i];}
    REP(i, 0, h){
        REP(l, 0, w){
            if(lis[i][l] != '#'){
                int count = 0;
                REP(k, 0, 8){
                    int x = i + dx[k], y = l + dy[k];
                    if(x >= 0 && y >= 0 && x < h && y < w && lis[x][y] == '#'){
                        count++;
                    }
                }
                lis[i][l] = '0'+count;
            }
        }
    }
    REP(i, 0, h){
        cout << lis[i] << endl;
    }
}