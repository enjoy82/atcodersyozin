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
    ll n, a, b, c; cin >> n >> a >> b >> c;
    ll ans = 1e9;
    vector<ll> lis(n);
    REP(i, 0, n){cin >> lis[i];}
    REP(i, 0, (1<<2*n)){
        ll mid = 0;
        ll aa = 0, bb = 0, cc = 0;
        ll at = 0, bt = 0, ct = 0;
        ll ch = i;
        int count = 0;
        while(ch != 0){
            int h = ch % 4;
            if(h == 0){
                //pass
            }else if(h == 1){
                aa += lis[count];
                at++;
            }else if(h == 2){
                bb += lis[count];
                bt++;
            }else if(h == 3){
                cc += lis[count];
                ct++;
            }
            ch = ch >> 2;
            count++;
        }
        if(aa == 0 || bb == 0 || cc == 0){
            continue;
        }
        //cout << aa << " " << bb << " " << cc << endl;
        mid = (at+bt+ct-3) * 10 + abs(a-aa) + abs(b-bb) + abs(c-cc);
        ans = min(mid, ans);
    } 
    cout << ans << endl;
}