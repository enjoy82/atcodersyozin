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
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示

int main(){
    int n, a; cin >> n >> a;
    string k; cin >> k;
    a--;
    vector<int> lis(n), rlis(n, 0);
    REP(i, 0, n){
        cin >> lis[i];
        lis[i]--;
    }
    vector<int> flag(n, 0);
    int now = a;
    int count = 1;
    while(1){
        rlis[lis[now]] = now;
        if(flag[now] != 0)
            break;
        flag[now] = count;
        count++;
        now = lis[now];
    }
    ll loop = count - flag[now];
    ll start = flag[now] - 1;
    //cout << loop << start << endl;
    if(k.size() <= 6){
        ll mid = 0;
        REP(i, 0, k.size()){
            mid *= 10;
            mid += k[i] - '0';
        }
        REP(i, 0, mid){
            a = lis[a];
        }
        cout << a + 1 << endl;
        return 0;
    }
    else{
        vector<ll> modlis(k.size(), 0);
        modlis[0] = 1;
        REP(i, 1, k.size()){
            modlis[i] = (modlis[i-1] * 10) % loop;
        }
        ll mid = 0;
        REP(i, 0, k.size()){
            mid += (modlis[i] *  (k[k.size() - 1 - i] - '0'));
            mid %= loop;
        }
        REP(i, 0, mid){
            now = lis[now];
        }
        REP(i, 0, start){
            now = rlis[now];
        }
        cout << now + 1 << endl;
    }
}