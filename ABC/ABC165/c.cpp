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

vector<vector<int> > lis;
int n, m, q;
ll ans = 0;

void solve(vector<int> ch, int num){
    if(num == n){
        ll mid = 0;
        REP(i, 0, q){
            int a = lis[i][0]-1, b = lis[i][1]-1;
            if(ch[b] - ch[a] == lis[i][2]){
                mid += lis[i][3];
            }
        }
        ans = max(ans, mid);
        return;
    }else{
        REP(i, 0, m){
            ch[num] = ch[num-1] + i;
            if(ch[num] > m){
                break;
            }
            solve(ch, num+1);
        }
        return;
    }
}

int main(){
    cin >> n >> m >> q;
    lis = vector<vector<int> >(q, vector<int>(4, 0));
    REP(i, 0, q){
        cin >> lis[i][0] >> lis[i][1] >> lis[i][2] >> lis[i][3];
    }
    vector<int> ch(n, 0);
    ch[0] = 1;
    solve(ch, 1);
    cout << ans << endl;
}