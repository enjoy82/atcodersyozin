// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
//#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
//using namespace atcoder;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

template<class T>inline bool chmax(T &a, T b) {if(a < b) {a = b;return true;}return false;}
template<class T>inline bool chmin(T &a, T b) {if(a > b) {a = b;return true;}return false;}


char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int n; cin >> n;
    vector<int> lis(n);
    REP(i, 0, n){cin >> lis[i];}
    sort(ALL(lis));
    ll ans = 0;
    int left = lis[0], right = lis[0];
    int lidx = 1, ridx = n-1;
    ll sum = 0;
    REP(i, 0, n-1){
        if(max({abs(left-lis[lidx]), abs(left-lis[ridx]), abs(right-lis[lidx]), abs(right-lis[ridx])}) == abs(left-lis[lidx])){
            sum += abs(left-lis[lidx]);
            left = lis[lidx];
            lidx++;
        }else if(max({abs(left-lis[lidx]), abs(left-lis[ridx]), abs(right-lis[lidx]), abs(right-lis[ridx])}) == abs(left-lis[ridx])){
            sum += abs(left-lis[ridx]);
            left = lis[ridx];
            ridx--;
        }else if(max({abs(left-lis[lidx]), abs(left-lis[ridx]), abs(right-lis[lidx]), abs(right-lis[ridx])}) == abs(right-lis[lidx])){
            sum += abs(right-lis[lidx]);
            right = lis[lidx];
            lidx++;
        }else{
            sum += abs(right-lis[ridx]);
            right = lis[ridx];
            ridx--;
        }
        //cout << right << left << endl;
    }
    ans = sum;
    left = lis[n-1]; right = lis[n-1];
    lidx = 0; ridx = n-2;
    sum = 0;
    REP(i, 0, n-1){
        if(max({abs(left-lis[lidx]), abs(left-lis[ridx]), abs(right-lis[lidx]), abs(right-lis[ridx])}) == abs(left-lis[lidx])){
            sum += abs(left-lis[lidx]);
            left = lis[lidx];
            lidx++;
        }else if(max({abs(left-lis[lidx]), abs(left-lis[ridx]), abs(right-lis[lidx]), abs(right-lis[ridx])}) == abs(left-lis[ridx])){
            sum += abs(left-lis[ridx]);
            left = lis[ridx];
            ridx--;
        }else if(max({abs(left-lis[lidx]), abs(left-lis[ridx]), abs(right-lis[lidx]), abs(right-lis[ridx])}) == abs(right-lis[lidx])){
            sum += abs(right-lis[lidx]);
            right = lis[lidx];
            lidx++;
        }else{
            sum += abs(right-lis[ridx]);
            right = lis[ridx];
            ridx--;
        }
        //cout << right << left << endl;
    }
    chmax(ans, sum);
    cout << ans << endl;
}