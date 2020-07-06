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

#define INF 2147483647 // 2^31-1
 
vector<int> value; // ノードの値を持つ配列
int N;             // 葉の数
 
void update(int i, int x) {
    // i 番目の葉の値を x に変える
    i += N - 1; // i 番目の葉のノード番号
    value[i] = x;
    while (i > 0) {
        i = (i - 1) / 2; // ノード i の親ノードの番号に変える
        value[i] = min(value[i * 2 + 1],
                       value[i * 2 + 2]); // 左右の子の min を計算しなおす
    }
}
 
int query(int a, int b, int k, int l, int r) {
    // [a, b) の区間に対するクエリについて
    // ノード k （区間 [l, r) 担当）が答える
    if (r <= a || b <= l) return INF; // 区間が被らない場合は INF を返す
    if (a <= l && r <= b)
        return value[k]; // ノード k の担当範囲がクエリ区間 [a, b)
                         // に完全に含まれる
    else {
        int c1 = query(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子に値を聞く
        int c2 = query(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子に値を聞く
        return min(c1, c2); // 左右の子の値の min を取る
    }
}
 
int main(void) {
    int n1, q;
    cin >> n1 >> q;
    int n = 2e5+1;
    N = 1;
    while (N < n) N *= 2; // 葉の数を計算（n以上の最小の2冪数）
    map<int, int> mp1, mp2;
    value = vector<int>(2 * N - 1, INF);
    REP(i, 0, n1){
        int a, b; cin >> a >> b;
        update(a, b);
        mp1[i+1] = a;
        mp2[i+1] = b;
    }

    REP(i, 0, q){
        int c, d; cin >> c >> d;
        int k = mp[c];
        if(find())
    }
 
    for (int j = 0; j < q; j++) {
        int c;
        cin >> c;
        if (c == 0) {
            // update(i, x)
            int i, x;
            cin >> i >> x;
            update(i, x);
        } else {
            // find(s, t)
            int s, t;
            cin >> s >> t;
            cout << query(s, t + 1, 0, 0, N) << endl;
        }
    }
    return 0;
}