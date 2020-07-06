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

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve(){
    int n; cin >> n;
    vector<int> lis(n);
    REP(i, 0, n){cin >> lis[i];}
    sort(ALL(lis));
    int c1 = 0, c0 = 0;
    REP(i, 0, n){
        if(lis[i] % 2 == 1){
            c1++;
        }else{
            c0++;
        }
    }
    c1 = c1 % 2;
    c0 = c0 % 2;
    int k = max(c1, c0);
    if(k == 0){
        cout << "YES" << endl;
        return;
    }else{
        REP(i, 0, n-1){
            if(abs(lis[i] - lis[i+1]) == 1){
                cout << "YES" << endl;
                return;
            }
        }
        cout << "NO" << endl;
        return;
    }
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}