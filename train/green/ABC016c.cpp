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

vector<vector<int> > tree;

int main(){
    int n, m; cin >> n >> m;
    tree = vector<vector<int>>(n);
    REP(i, 0, m){
        int a, b; cin >> a >> b;
        a--; b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    REP(i, 0, n){
        int ans = 0;
        map<int, int> mp;
        mp[i] = -1;
        REP(l, 0, tree[i].size()){
            mp[tree[i][l]] = -1;
        }
        REP(l, 0, tree[i].size()){
            int next = tree[i][l];
            REP(j, 0, tree[next].size()){  
                //cout << tree[next][j] << endl;     
                if(mp[tree[next][j]] != -1){
                    ans++;
                    mp[tree[next][j]] = -1;
                }
            }
        }
        cout << ans << endl;
    }
}