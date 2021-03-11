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
  ll x, y;
  map<ll, ll> mp;
  cin >> x >> y;
  if(y <= x){
    cout << x-y << endl;
    return 0;
  }
  mp[x] = abs(x-y);
  queue<ll> que;
  que.push(y);
  mp[y] = 0;
  while(!que.empty()){
    ll a = que.front();
    que.pop();
    if(mp[a] >= mp[x])
      continue;
    mp[x] = min(mp[x], mp[a] + abs(a-x));
    if(a <= x){
      continue;
    }
    if(a % 2 == 0){
      if(!mp.count(a/2) || mp[a/2] > mp[a]){
        que.push(a/2);
        mp[a/2] = mp[a] + 1;
      }
    }else{
      if(!mp.count((a-1)/2) || mp[(a-1)/2] > mp[a] + 1){
        que.push((a-1)/2);
        mp[(a-1)/2] = mp[a] + 2;
      }
      if(!mp.count((a+1)/2) || mp[(a+1)/2] > mp[a] + 1){
        que.push((a+1)/2);
        mp[(a+1)/2] = mp[a] + 2;
      } 
    }
  }
  cout << mp[x] << endl;
}