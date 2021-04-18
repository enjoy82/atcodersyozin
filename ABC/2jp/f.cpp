// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
//#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
//using namespace atcoder;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

//ordered_set 重複不可
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// use set_function + find_by_order(select itr-num)

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

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示
class BIT {
public:
    //データの長さ
    ll n;
    //データの格納先
    vector<ll> a;
    //コンストラクタ
    BIT(ll n):n(n),a(n+1,0){}

    //a[i]にxを加算する
    void add(ll i,ll x){
        i++;
        if(i==0) return;
        for(ll k=i;k<=n;k+=(k & -k)){
            a[k]+=x;
        }
    }

    //a[i]+a[i+1]+…+a[j]を求める
    ll sum(ll i,ll j){
        return sum_sub(j)-sum_sub(i-1);
    }

    //a[0]+a[1]+…+a[i]を求める
    ll sum_sub(ll i){
        i++;
        ll s=0;
        if(i==0) return s;
        for(ll k=i;k>0;k-=(k & -k)){
            s+=a[k];
        }
        return s;
    }

    //a[0]+a[1]+…+a[i]>=xとなる最小のiを求める(任意のkでa[k]>=0が必要)
    ll lower_bound(ll x){
        if(x<=0){
            //xが0以下の場合は該当するものなし→0を返す
            return 0;
        }else{
            ll i=0;ll r=1;
            //最大としてありうる区間の長さを取得する
            //n以下の最小の二乗のべき(BITで管理する数列の区間で最大のもの)を求める
            while(r<n) r=r<<1;
            //区間の長さは調べるごとに半分になる
            for(int len=r;len>0;len=len>>1) {
                //その区間を採用する場合
                if(i+len<n && a[i+len]<x){
                    x-=a[i+len];
                    i+=len;
                }
            }
            return i;
        }
    }
};

int main(){
    ll n, m, q; cin >> n >> m >> q;
    vector<vector<ll> > lis(q, vector<ll>(3));
    map<ll, ll> mp;
    REP(i,0,q){
        cin >> lis[i][0] >> lis[i][1] >> lis[i][2];
        mp[lis[i][2]]++;
    }
    int idx = 1;
    for(auto &x: mp){
        x.second = idx;
        idx++;
    }
    BIT atree(idx + 10), btree(idx + 10); // count
    BIT atree2(idx + 10), btree2(idx + 10); // num
    vector<ll> alis(n,0), blis(m,0);
    ll ans = 0;
    //cout << "OK" << endl;
    atree.add(0, n);
    btree.add(0, m);
    //cout << "OK" << endl;
    //vector<ll> abase_sum(n, 0), bbase_sum(m, 0);
    REP(i,0,q){
        ll t, x, y;
        t = lis[i][0];
        x = lis[i][1];
        y = lis[i][2];
        //cout << t << " " << x << " " << y << endl;
        if(t == 1){
            ll cc = alis[x-1];
            ll tree_num = mp[cc];
            ll tree_num_y = mp[y];
            //cout << tree_num << " " << tree_num_y << endl;
            atree.add(tree_num, -1);
            atree.add(tree_num_y, 1);
            ll ff = btree.sum(0, tree_num) * cc + btree2.sum(tree_num+1, idx + 5);
            alis[x-1] = y;

            atree2.add(tree_num, -1*cc);
            atree2.add(tree_num_y, y);

            ll count = btree.sum(0, tree_num_y);
            ll kk = count * y + btree2.sum(tree_num_y+1, idx + 5);
            ans = ans + kk - ff;
        }else{
            ll cc = blis[x-1];
            ll tree_num = mp[cc];
            ll tree_num_y = mp[y];
            btree.add(tree_num, -1);
            btree.add(tree_num_y, 1);
            ll ff = atree.sum(0, tree_num) * cc + atree2.sum(tree_num+1, idx + 5);
            blis[x-1] = y;

            btree2.add(tree_num, -1*cc);
            btree2.add(tree_num_y, y);

            ll count = atree.sum(0, tree_num_y);
            ll kk = count * y + atree2.sum(tree_num_y+1, idx + 5);
            ans = ans + kk - ff;
        }
        cout << ans << endl;
    }
}