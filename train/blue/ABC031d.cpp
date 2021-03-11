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

vector<string> vlis;
vector<string> wlis;
vector<string> anslis;
int k, n;

void solve_ans(vector<int> lis){
    vector<string> midlis(26, "");
    REP(i, 0, n){
        int pos = 0;
        REP(l, 0, vlis[i].size()){
            string c = "";
            int size = lis[vlis[i][l] - '1'];
            REP(k, 0, size){
                if(pos + k >= wlis[i].size()){
                    return;
                }
                c = c + wlis[i][pos+k];
            }
            pos += size;
            if(midlis[vlis[i][l] - '1'] == ""){
                midlis[vlis[i][l] - '1'] = c;
            }else if(midlis[vlis[i][l] - '1'] == c){
                continue;
            }else{
                return;
            }
        }
        if(pos != wlis[i].size()){
            return;
        }
    }
    anslis = midlis;
}

void solve(int count, vector<int> lis){
    REP(i, 1, 4){
        lis[count] = i;
        if(count == k-1){
            solve_ans(lis);
        }else{
            solve(count+1, lis);
        }
    }
    
}

int main(){
    cin >> k >> n;
    anslis = vector<string>(k, "");
    vlis = vector<string>(n);
    wlis = vector<string>(n);
    REP(i,0,n){cin >> vlis[i] >> wlis[i];}
    vector<int> lis(k, 0);
    solve(0, lis);
    REP(i, 0, k){
        cout << anslis[i] << endl;
    }
}