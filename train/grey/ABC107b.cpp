#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int h, w; cin >> h >> w;
    vector<string> lis(h);
    REP(i, 0, h){cin >> lis[i];}
    REP(i, 0, h){
        int f = 1;
        REP(l, 0, w){
            if(lis[i][l] != '.'){
                //cout << i << l << endl;
                f = 0;
                break;
            }
        }
        if(f == 1){
            REP(l, 0, w){
                lis[i][l] = 'A';
            }
        }
    }
    REP(i, 0, w){
        int f = 1;
        REP(l, 0, h){
            if(lis[l][i] == '#'){
                //cout << i << l << endl;
                f = 0;
                break;
            }
        }
        if(f == 1){
            REP(l, 0, h){
                lis[l][i] = 'A';
            }
        }
    }
    REP(i, 0, h){
        int f = 0;
        REP(l, 0, w){
            if(lis[i][l] == 'A'){
                continue;
            }else{
                f = 1;
                cout << lis[i][l];
            }
        }
        if(f == 1)
            cout << endl;
    }
}