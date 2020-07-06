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

int main(){
    int n, y; cin >> n >> y;
    for(int i = 0; i * 10000 <= y; i++){
        for(int l = 0; (i*10000 + l * 5000) <= y; l++){
            if( (y-10000*i - 5000*l) % 1000 == 0 && i + l + (y-10000*i - 5000*l) / 1000 == n){
                cout << i << " " << l << " " <<(y-10000*i - 5000*l) / 1000  << endl;
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << endl;
}