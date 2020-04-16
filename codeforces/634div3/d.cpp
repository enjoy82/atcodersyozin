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

int change(char a){
    int k = (a - '0') + 1;
    if(k == 10){
        return 1;
    }else{
        return k;
    }
}

void solve(){
    vector<string> lis(9);
    REP(i, 0, 9){cin >> lis[i];}
    lis[0][0] = '0' + change(lis[0][0]);
    lis[1][3] = '0' + change(lis[1][3]);
    lis[2][6] = '0' + change(lis[2][6]);
    lis[3][1] = '0' + change(lis[3][1]);
    lis[4][4] = '0' + change(lis[4][4]);
    lis[5][7] = '0' + change(lis[5][7]);
    lis[6][2] = '0' + change(lis[6][2]);
    lis[7][5] = '0' + change(lis[7][5]);
    lis[8][8] = '0' + change(lis[8][8]);
    REP(i, 0, 9){cout << lis[i] << endl;}
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}