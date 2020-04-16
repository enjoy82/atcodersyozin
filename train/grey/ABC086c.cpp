#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb puah_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int n; cin >> n;
    vector<vector<int> > lis(n, vector<int>(3));
    REP(i, 0, n){cin >> lis[i][0] >> lis[i][1] >> lis[i][2];}
    int x = 0, y = 0;
    int t = 0;
    REP(i, 0, n){
        int dx = abs(lis[i][1] - x), dy = abs(lis[i][2] - y);
        int dt = lis[i][0] - t;
        if(dx + dy <= dt && (dt - (dx + dy)) % 2 == 0){
            x = lis[i][1];
            y = lis[i][2];
            t = lis[i][0];
            continue;
        }else{
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}