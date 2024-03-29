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
    if((n/2)%2 == 1){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        int a = 2;
        REP(i, 0, n/2){
            cout << a << " ";
            a+= 2;
        }
        a = 1;
        REP(i, 0, n/2-1){
            cout << a << " ";
            a += 2;
        }
        cout << a + n/2 << endl;
    }
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}