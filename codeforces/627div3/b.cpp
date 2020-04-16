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

void solve(){
    int n; cin >> n;
    vector<int> lis(n);
    vector<int> num(5010, 0);
    REP(i, 0, n){cin >> lis[i];}
    REP(i, 1, n-1){
        num = vector<int>(5010, 0);
        REP(l, 0, i){
            num[lis[l]]++;
        }
        REP(l, i+1, n){
            if(num[lis[l]] != 0){
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}