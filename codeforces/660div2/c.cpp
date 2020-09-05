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

ll n, m;
vector<ll> people, happy;
vector<vector<int> > tree;
vector<vector<ll> > lis;
vector<int> flag;
int fa = 1;

void saiki(int num){
    ll ch = -1 * people[num];
    REP(i, 0, tree[num].size()){
        int next = tree[num][i];
        if(flag[next] == 0){
            ch += happy[next];
            flag[next] = 1;
            saiki(next);
            REP(i, 0, 3){
                lis[num][i] += lis[next][i];
            }
        }
    }
    if(ch > happy[num]){
        //cout << num << endl;
        fa = 0;
    }
    ll c = lis[num][0] - lis[num][1];
    if(happy[num] >= c){
        if((happy[num] - c) % 2 == 1){
            fa = 0;
        }
        lis[num][0] += ((happy[num] - c) / 2);
        lis[num][1] -= ((happy[num] - c) / 2);
    }else{
        fa = 0;
    }
    if((lis[num][0] - lis[num][1]) != happy[num] ||lis[num][0] < 0 || lis[num][1] < 0 || lis[num][2] != (lis[num][0] + lis[num][1])){
        fa = 0;
    }
    cout << num << endl << lis[num][0] << " " << lis[num][1] << " " <<  lis[num][2]<< endl;
}

void solve(){
    cin >> n >> m;
    fa= 1;
    people = vector<ll>(n);
    happy = vector<ll>(n);
    tree = vector<vector<int> >(n);
    lis = vector<vector<ll> >(n, vector<ll>(3, 0));
    flag = vector<int>(n, 0);
    REP(i, 0, n){cin >> people[i];}
    REP(i, 0, n){cin >> happy[i];}
    REP(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--; b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    REP(i, 0, n){
        lis[i][1] = people[i];
        lis[i][2] = people[i];
    }
    flag[0] = 1;
    saiki(0);
    if(fa == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    people.clear();
    happy.clear();
    tree.clear();
    lis.clear();
    flag.clear();
}

int main(){
    int t;cin >> t;
    REP(i, 0, t){solve();}
}