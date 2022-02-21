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
    int n; cin >> n;
    vector<vector<int> > tree(n);
    REP(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--; b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(0);
    vector<int> anslis;
    vector<int> flag(n, 0);
    flag[0]++;
    while(!pq.empty()){
        int now = pq.top();
        pq.pop();
        flag[now]++;
        anslis.pb(now+1);
        REP(i, 0, tree[now].size()){
            int next = tree[now][i];
            if(flag[next] == 0){
                pq.push(next);
                flag[next]++;
            }
        }
    }
    REP(i, 0, n-1){
        cout << anslis[i] << " ";
    }
    cout << anslis[n-1] << endl;
}