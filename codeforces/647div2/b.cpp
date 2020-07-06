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
    REP(i, 0, n){
        cin >> lis[i];
    }
    sort(ALL(lis));
    REP(i, 1, 2049){
        int f = 1;
        vector<int>  ne(n);
        REP(l, 0, n){
            int k = lis[l] ^ i;
            ne[l] = k;
        }
        sort(ALL(ne));
        REP(l, 0, n){
            if(lis[l] != ne[l]){
                f = 0;
                break;
            }
        }
        if(f == 1){
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}