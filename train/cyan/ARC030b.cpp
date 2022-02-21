#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

int n, x;
vector<int> hlis;
vector<vector<int> > tree;
vector<vector<int> > tree1;
vector<int> used;
vector<int> num;
int ans = 0;

void solve(int x, vector<int> nlis){
    nlis.pb(x);
    if(hlis[x] == 1){
        REP(i, 0, nlis.size()){
            num[nlis[i]] = 1;
        }
    }
    int f = 0;
    REP(i, 0, tree[x].size()){
        int next = tree[x][i];
        if(used[next] == 0){
            used[next]++;
            f = 1;
            solve(next, nlis);
        }
    }
    if(f == 0){
        return;
    }
}

void count(int x){
    REP(i, 0, tree[x].size()){
        int next = tree[x][i];
        if(num[next] == 1){
            num[next] = 0;
            ans += 2;
            count(next);
        }
    }
}

int main(){
    cin >> n >> x;
    x--;
    hlis = vector<int>(n);
    tree = vector<vector<int> >(n);
    tree1 = vector<vector<int> >(n);
    used = vector<int>(n, 0);
    num = vector<int>(n, 0);
    REP(i, 0, n){
        int a; cin >> a;
        hlis[i] = a;
    }
    REP(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--; b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    vector<int> nlis;
    used[x]++;
    solve(x, nlis);
    /*REP(i, 0, n){
        cout << num[i];
    }
    cout << endl;*/
    num[x] = 0;
    count(x);
    cout << ans << endl;
}