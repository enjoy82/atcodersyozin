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

const ll MOD = 1e9+7;

ll Pow(ll  x, ll n){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return Pow(x * x % MOD, n / 2);
  else
    return x * Pow(x, n - 1) % MOD;
}


vector<vector<ll> > graph;
vector<vector<ll> > uni;
vector<int> used;

void maketree(int now, int pos){
    REP(i, 0,  graph[now].size()){
        int next = graph[now][i];
        if(used[next] == 0){
            used[next] = 1;
            maketree(next, pos);
        }
    }
    uni[pos].pb(now);
}

int main(){
    int n; cin >> n;
    uni = vector<vector<ll> >(n);
    graph = vector<vector<ll> >(n);
    used = vector<int>(n, 0);
    vector<vector<ll> > s;
    int k = 0;
    map<int, int> mp;
    REP(i, 0, n){
        int a; cin >> a;
        if(a == -1){
            mp[i]++;
            k++;
            continue;
        }
        a--;
        graph[a].pb(i);
        graph[i].pb(a);
    }
    REP(i, 0, n){
        if(used[i] == 0){
            used[i] = 1;
            maketree(i, i);
        }
    }
    REP(i, 0, n){
        if(uni[i].size() == 0){
            continue;
        }else{
            int f = 0;
            REP(l, 0, uni[i].size()){
                int pos = uni[i][l];
                if(mp[pos] > 0){
                    f = 1;
                    break;
                }
            }
            vector<ll> aa(2);
            aa[0] = uni[i].size();
            aa[1] = f;
            s.pb(aa);
        }
    }
    ll ans = 0;
    ll key1 = Pow(n-1, k);
    ll key2 = Pow(n-1, k-1);
    REP(i, 0, s.size()){
        if(s[i][1] == 1){
            REP(l, 0, s.size()){
                if(s[l][1] == 0){
                    ans = (ans + (key2 * s[l][0]) % MOD) % MOD;
                }
            }
        }
    }
}