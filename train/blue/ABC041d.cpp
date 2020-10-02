// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
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

template<class T>inline bool chmax(T &a, T b) {if(a < b) {a = b;return true;}return false;}
template<class T>inline bool chmin(T &a, T b) {if(a > b) {a = b;return true;}return false;}


char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

typedef pair<ll,ll> P;

class tsort {
public:
	int V;
	vector<vector<int> > G;
	vector<int> deg,res;
    vector<vector<bool> > bad;
	tsort(int node_size) : V(node_size), G(V), deg(V, 0), bad(V, vector<bool>(V, false)){}
	void add_edge(int from,int to){
		G[from].push_back(to);
		deg[to]++;
        bad[from][to] = true;
	}
 	bool solve() { //sort TP
		queue<int> que;
		for(int i = 0; i < V; i++){
	        if(deg[i] == 0){
	            que.push(i);
	        }
	    }
		while(!que.empty()){
			int p = que.front();
	        que.pop();
			res.push_back(p);
			for(int v : G[p]){
	            if(--deg[v] == 0){
	                que.push(v);
	            }
	        }
		}
		return (*max_element(deg.begin(),deg.end()) != 0);
	}
    ll bitDP(){ //0-indexed
		vector<ll> dp(1 << V, 0);
        dp[0] = 1;
        REP(i, 0, 1 << V){
            REP(l, 0, V){
                if(!(i & (1 << l))){
                    bool ok = true;
                    REP(k, 0, V){
                        if(i&(1 << k) && bad[k][l]){
                            ok = false;    
                        }
                    }
                    if(ok){
                        dp[i + (1 << l)] += dp[i];
                    }
                }
            }
        }
        return dp[(1 << V) - 1];
    }
};

int main(){
    int n, m; cin >> n >> m;
	tsort t(n);
	REP(i, 0, m){
		int a, b; cin >> a >> b;
		a--; b--;
		t.add_edge(a, b);
	}
	cout << t.bitDP()<< endl;
}