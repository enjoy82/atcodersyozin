#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};


vector<vector<int> > tree; //双方向木

//木の深さ調べる
////////////////////////
void Searchdepth(vector<int> &depth, int now, int cost){
    depth[now] = cost;
    REP(i, 0, tree[now].size()){
        int next = tree[now][i];
        if(depth[next] == -1){
            Searchdepth(depth, next, cost+1);
        }else{
            continue;
        }
    }
}

vector<int> searchdepth(int pos, int num){ //第1引数として頂点与える、第2引数で頂点の数
    vector<int> depth(num, -1);
    Searchdepth(depth, pos, 0);
    return depth;
}
///////////////////////


//木の子孫の数数える
////////////////////////////
int Searchleaf(vector<int> &leaf, vector<int> &used,int now){
    int count = 0;
    used[now] = 1;
    REP(i, 0, tree[now].size()){
        int next = tree[now][i];
        if(used[next] == -1){
            count += Searchleaf(leaf, used, next);
        }else{
            continue;
        }
    }
    leaf[now] = count;
    return count+1;
}

vector<int> searchleaf(int pos, int num){ //第1引数として頂点与える、第2引数で頂点の数
    vector<int> leaf(num, -1);
    vector<int> used(num, -1);
    Searchleaf(leaf, used, pos);
    return leaf;
}
///////////////////////////

/////hoe to use
int main(){
    int n, k; cin >> n >> k;
    tree = vector<vector<int>>(n);
    REP(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--; b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    vector<int> depth =  searchdepth(0, n);
    REP(i, 0, n){cout << depth[i];}
    cout << endl;
    vector<int> leaf = searchleaf(0, n);
    REP(i, 0, n){cout << leaf[i];}
    cout << endl;
}