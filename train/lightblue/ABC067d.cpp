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

int n;
vector<vector<int> > tree;
vector<int> color;

int main(){
    cin >> n;
    tree = vector<vector<int> >(n);
    color = vector<int>(n, 0);
    vector<int> d(n, 1e9);
    REP(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--; b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    queue<int> q, rq;
    q.push(0);
    d[0] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        REP(i, 0, tree[now].size()){
            int next = tree[now][i];
            if(d[next] != 1e9){continue;}
            d[next] = d[now] + 1;
            q.push(next);
        }
    }
    int count = 0;
    rq.push(n-1);
    while(1){
        int now = rq.front();
        rq.pop();
        int f = 0;
        REP(i, 0, tree[now].size()){
            int next = tree[now][i];
            if(d[next] == d[now]-1){
                if(next == 0){f = 1;break;}
                rq.push(next);
                color[next] = -2;
                count++;
                break;
            }else{
                continue;
            }
        }
        if(f == 1){break;}
    }
    stack<int> s1, s2, ss1, ss2;
    int fc = 0, sc = 0;
    ss1.push(0);
    REP(i, 0, 1+(count+1)/2){
        int now = ss1.top();
        ss1.pop();
        fc++;
        color[now] = 1;
        s1.push(now);
        REP(i, 0, tree[now].size()){
            int next = tree[now][i];
            if(color[next] == -2){
                ss1.push(next);
            }
        }
    }
    ss2.push(n-1);
    count /= 2;
    REP(i, 0, 1+count){
        int now = ss2.top();
        ss2.pop();
        sc++;
        color[now] = -1;
        s2.push(now);
        REP(i, 0, tree[now].size()){
            int next = tree[now][i];
            if(color[next] == -2){
                ss2.push(next);
            }
        }
    }
    while(!s1.empty()){
        int now = s1.top();
        s1.pop();
        REP(i, 0, tree[now].size()){
            int next = tree[now][i];
            if(color[next] == 0){
                color[next] = 1;
                s1.push(next);
                fc++;
            }else{
                continue;
            }
        }
    }
    while(!s2.empty()){
        int now = s2.top();
        s2.pop();
        REP(i, 0, tree[now].size()){
            int next = tree[now][i];
            if(color[next] == 0){
                color[next] = -1;
                s2.push(next);
                sc++;
            }else{
                continue;
            }
        }
    }
    if(sc < fc){
        cout << "Fennec" << endl;
    }else{
        cout << "Snuke" << endl;
    }
}