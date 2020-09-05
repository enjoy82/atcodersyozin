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

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int> > flag(100, vector<int>(100, 0));
    vector<vector<int> > graph(100);
    vector<int> vflag(100, 0);
    REP(i, 0, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    int ans = 0;
    REP(i, 0, n){
        if(vflag[i] == 1){
            continue;
        }else{
            int f = 1;
            vflag[i] = 1;
            stack<int> st;
            st.push(i);
            while(!st.empty()){
                int now = st.top();
                st.pop();
                REP(l, 0, graph[now].size()){
                    int next = graph[now][l];
                    if(flag[now][next] == 0){
                        flag[now][next] = 1;
                        flag[next][now] = 1;
                        if(vflag[next] == 1){
                            f = 0;
                        }else{
                            vflag[next] = 1;
                            st.push(next);
                        }
                    }else{
                        continue;
                    }
                }
            }
            ans += f;
        }
    }
    cout << ans << endl;
}