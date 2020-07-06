#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

#define INF 2147483647 // 2^31-1
 
vector<Pii> value; // ノードの値を持つ配列
int N;             // 葉の数
 
void update(int i, int x) {
    // i 番目の葉の値を x に変える
    i += N - 1; // i 番目の葉のノード番号
    value[i].first = x;
    while (i > 0) {
        i = (i - 1) / 2; // ノード i の親ノードの番号に変える
        if(value[i*2+1] < value[i*2+2]){
            value[i] = value[i*2+1];
        }else{
            value[i] = value[i*2+2];
        }
    }
}

Pii mi(Pii a, Pii b){
    if(a.first < b.first){
        return a;
    }else{
        return b;
    }
}
 
/*Pii query(int a, int b, int k, int l, int r) {
    // [a, b) の区間に対するクエリについて
    // ノード k （区間 [l, r) 担当）が答える
    if (r <= a || b <= l) return INF; // 区間が被らない場合は INF を返す
    if (a <= l && r <= b)
        return value[k]; // ノード k の担当範囲がクエリ区間 [a, b)
                         // に完全に含まれる
    else {
        Pii c1 = query(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子に値を聞く
        Pii c2 = query(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子に値を聞く
        return mi(c1, c2); // 左右の子の値の min を取る
    }
}*/

vector<int> topic;
vector<vector<int> > graph;

int main(void) {
    int n, m;
    cin >> n >> m;
    N = 1;
    while (N < n) N *= 2; // 葉の数を計算（n以上の最小の2冪数）
    int c = n / 2;
 
    value = vector<Pii>(2 * N - 1);
    topic = vector<int>(n);
    graph = vector<vector<int> >(n);

    REP(i, 0, m){
        int a, b; cin >> a >> b;
        a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    REP(i, 0, n){cin >> topic[i];}
    for(int i = 0; i < n; i++){
        value[i+c].first = 0;
        value[i+c].second = topic[i];
    }
    


    return 0;
}