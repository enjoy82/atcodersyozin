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
    ll n, k; cin >> n >> k;
    vector<ll> flag(n, 0), dist1(n, -1), dist2(n, -1);
    vector<vector<ll> > tree(n);
    REP(i, 0, n){
        ll a; cin >> a;
        a--;
        tree[i].pb(a);
    }
    ll now = 0;
    ll count = 0;
    flag[0] = 1;
    dist1[0] = 0;
    while(1){
        count++;
        ll next = tree[now][0];
        if(flag[next] == 0){
            dist1[next] = count;
        }else if(flag[next] == 1){
            dist2[next] = count;
        }else{
            break;
        }
        flag[next]++;
        now = next;
    }
    vector<ll> check(n, -1);
    ll kk;
    REP(i, 0, n){
        if(flag[i] == 2){
            kk = dist2[i] - dist1[i];
        }
    }
    REP(i, 0, n){
        if(flag[i] == 1){
            if( k   ==  dist1[i] ){
                cout << i+1 << endl;
                return 0;
            }
        }
    }
    REP(i, 0, n){
        if(flag[i] == 2){
            if( (k - dist1[i]) % kk   ==  0 ){
                cout << i+1 << endl;
                return 0;
            }
        }
    }
}