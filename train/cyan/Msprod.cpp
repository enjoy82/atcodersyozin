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
    int n; cin >> n;
    vector<int> clis(n);
    vector<int> anslis(n);
    vector<vector<int> > tree(n);
    vector<vector<int> > p(n-1, vector<int>(2, 0));
    REP(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--; b--;
        p[i][0] = a; p[i][1] = b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    ll sum = 0;
    REP(i, 0, n){cin >> clis[i];}
    sort(ALL(clis), greater<>());
    REP(i, 1, n){sum += clis[i];}
    cout << sum << endl;
    stack<ll> st;
    vector<int> used(n, -1);
    st.push(0);
    used[0] = 1;
    int ind = 0;
    while(!st.empty()){
        int k = st.top();
        st.pop();
        anslis[k] = clis[ind];
        ind++;
        REP(l, 0, tree[k].size()){
            if(used[tree[k][l]] == -1){
                used[tree[k][l]] = 1;
                st.push(tree[k][l]);
            }else{
                continue;
            }
        }
    }
    REP(i, 0, n){cout << anslis[i] << " ";}
}