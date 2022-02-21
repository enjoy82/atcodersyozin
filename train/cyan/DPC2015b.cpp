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
    int n, m; cin >> n >> m;
    vector<int> alis(n), blis(m), clis(m);
    REP(i, 0, n){cin >> alis[i];}
    vector<vector<int> > Ilis(m);
    REP(i, 0, m){
        cin >> blis[i] >> clis[i];
        REP(l, 0, clis[i]){
            int a; cin >> a;
            Ilis[i].pb(a-1);
        }
        sort(ALL(Ilis[i]));
    }
    int ans = 0;
    REP(i, 0, (1 << n)){
        int c = i;
        int sum = 0;
        int ch = 0;
        string st = "";
        REP(l, 0, n){
            if(c & 1 == 1){
                ch++;
                sum += alis[l];
            }
            st = st + to_string(c & 1);
            c /= 2;
        }
        if(ch != 9){
            continue;
        }
        //cout << st << endl;
        REP(l, 0, m){
            int count = 0;
            REP(j, 0, Ilis[l].size()){
                if(st[Ilis[l][j]] == '1'){   
                    count++;
                }
            }
            if(count >= 3){
                sum += blis[l];
            }
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}