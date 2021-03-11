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

int main(){
    int n, k; cin >> n >> k;
    vector<int> lis(n);
    REP(i, 0, n){cin >> lis[i];}
    set<int> st;
    REP(i, 0, k){
        st.insert(lis[i]);
    }
    int ans = 0;
    int pre = lis[0];
    REP(i, 1, k){
        if(pre < lis[i]){
            continue;
        }else{
            ans = 1;
        }
        pre = lis[i];
    } 
    int f = 0;
    vector<int> flag(n, 0);
    for(int i = 1; i < n; i++){
        flag[i] = flag[i-1] + (lis[i] > lis[i-1]);
    }
    if(ans == 0)
        //f = 1;
    ans = 1;
    for(int i = k; i < n; i++){
        int ma = *st.rbegin();
        int mi = *st.begin();
        int check = ((flag[i] - flag[i-k+1]) == (k-1));
        if(!(lis[i] > ma && mi == lis[i-k])){
            if(check){
                f = 1;
            }else{
                ans++;
            }
        }
        st.insert(lis[i]);
        st.erase(lis[i-k]);
    }
    if(flag[n-1] - flag[0] == n){
        cout <<  1 << endl;
    }
    cout << ans + f << endl;
    
}