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

bool check(int mid, string &s, vector<pair<char, char> > &lis){
    REP(i,0,lis.size()){
        if(s[mid] == lis[i].first){
            if(lis[i].second == 'L'){
                mid--;
            }else{
                mid++;
            }
        }
        //cout << mid << endl;
        if(mid == 0 || mid == s.size() - 1){
            return true;
        }
    }
    return false;
}

int main(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    s = '#' + s + '#';
    vector<pair<char, char> > lis(q);
    REP(i,0,q){
        char a, b; cin >> a >> b;
        pair<char, char> p = {a, b};
        lis[i] = p;
    }
    int right = 0, left = n+1;
    while(left - right > 0){
        int mid = (right + left) / 2;
        if(mid == right || mid == left){
            break;
        }
        if(check(mid, s, lis)){ //ok
            right = mid;
        }else{
            left = mid;
        }
    }
    int r_idx = right;
    //cout << "%check" << endl;
    if(check(left, s, lis)){
        r_idx = left;
    }
    //cout << "%check" << endl;
    right = 0, left = n+1;
    while(left - right > 0){
        int mid = (right + left) / 2;
        if(mid == right || mid == left){
            break;
        }
        if(check(mid, s, lis)){ //ok
            left = mid;
        }else{
            right = mid;
        }
    }
    int l_idx = left;
    if(check(right, s, lis)){
        l_idx = right;
    }
    //cout << r_idx << " " << l_idx << endl;
    int k = r_idx + (n+1 - l_idx);
    cout << max(0, n - k) << endl;
}