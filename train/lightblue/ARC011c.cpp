// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
//#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
//using namespace atcoder;

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
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

map<int, string> mp;
vector<vector<int> > graph;

int main(){
    string first, end; cin >> first >> end;
    int n; cin >> n;
    mp[0] = first, mp[1] = end;
    graph = vector<vector<int> >(n+2);
    vector<string> lis;
    lis.pb(first);
    lis.pb(end);
    REP(i, 0, n){
        string s; cin >> s;
        mp[i+2] = s;
        lis.pb(s);
    }
    if(first == end){
        cout << 0 << endl;
        REP(i, 0, 2){
            cout << first << endl;
        }
        return 0;
    }
    REP(i, 0, lis.size()){
        REP(l, 0, lis.size()){
            if(i == l){
                continue;
            }
            int count = 0;
            REP(k, 0, lis[i].size()){
                if(lis[i][k] != lis[l][k]){
                    count++;
                }
            }
            if(count == 1){
                graph[i].pb(l);
                //cout << i << " " << l << endl;
            }else{
                continue;
            }
        }
    }
    queue<int> que;
    que.push(0);
    vector<int> flag(n+2, -1);
    flag[0] = 0;
    while(!que.empty()){
        int now = que.front();
        int pos = flag[now];
        que.pop();
        int kk = 0;
        REP(i, 0, graph[now].size()){
            int next = graph[now][i];
            if(flag[next] == -1){
                flag[next] = pos + 1;
                que.push(next);
                if(next == 1){
                    kk = 1;
                }
            }
        }
        if(kk){break;}
    }
    if(flag[1] == -1){
        cout << -1 << endl;
        return 0;
    }
    if(flag[1] == 1){
        cout << 0 << endl;
        cout << first << endl << end << endl;
        return 0;
    }
    cout << flag[1]-1 << endl;
    vector<int> anslis;
    anslis.pb(1);
    int key = flag[1] - 1;
    int next = 1;
    REP(i, 0, flag[1]){
        int ff = 1;
        REP(l, 0, flag.size()){
            if(flag[l] == key && ff == 1){
                REP(k, 0, graph[l].size()){
                    if(graph[l][k] == next){
                        anslis.pb(l);
                        ff = 0;
                        next = l;
                        k = 1e9;
                        l = 1e9;
                        key--;
                    }
                }
            }
        }
    }
    reverse(ALL(anslis));
    REP(i, 0, anslis.size()){
        cout << mp[anslis[i]] << endl;
    }
}