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

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<vector<int> > graph;

int main(){
    int n; cin >> n;
    graph = vector<vector<int> >(n);
    vector<vector<int> > lis(n-1, vector<int>(3, 0));
    map<int, int> mp;
    map<Pii, int> anslis;
    mp[0] = -1;
    REP(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
        lis[i][0] = a; lis[i][1] = b;
    }
    queue<int> q;
    int max = 1;
    vector<int> flag(n, 0);
    flag[0] = 1;
    q.push(0);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        int keycolor = mp[now];
        int color = 1;
        REP(i, 0, graph[now].size()){
            int next = graph[now][i];
            if(flag[next] == 0){
                int a, b;
                if(next > now){
                    a = now;
                    b = next;
                }else{
                    a = next;
                    b = now;
                }
                while(color == keycolor){
                    color++;
                }
                anslis[Pii(a, b)] = color;
                mp[next] = color;
                chmax(max, color);
                color++;
                q.push(next);
                flag[next] = 1;
            }
        }
    }
    cout << max << endl;
    REP(i, 0, n-1){
        cout << anslis[Pii(lis[i][0], lis[i][1])] << endl; 
    }
}