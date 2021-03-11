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

void chmax(string &a, string b){
    if(a.size() < b.size()){
        a = b;
    }else{
        if(a < b){
            a = b;
        }
    }
}


char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示

vector<int> flag(9, 0);

string MAX(string a, string b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int lis[9] = {2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){
    int n, m; cin >> n >> m;
    REP(i, 0, m){
        int a; cin >> a;
        flag[a-1] = 1;
    }
    vector<string> from(n+10, "");
    REP(i, 0, 9){
        if(flag[i] == 1){
            from[lis[i]] = to_string(i+1);
            //cout << from[lis[i]] << endl;        
        }
    }
    string ans = "";
    REP(i, 0, n+1){
        if(from[i] == ""){
            continue;
        }
        REP(l, 0, 9){
            if(flag[l] == 1){
                string key = to_string(l+1);
                int cost = lis[l];
                chmax(from[i+cost], (from[i]+key));
                //cout << from[i] << " "  <<  (from[i]+key)  << " " << from[i+cost] << endl;
            }else{
                continue;
            }
        }
    }
    cout << from[n] << endl;
}