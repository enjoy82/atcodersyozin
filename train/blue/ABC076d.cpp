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
    int n; cin >> n;
    vector<ld> tlis(n), vlis(n);
    REP(i, 0, n){
        cin >> tlis[i];
    }
    REP(i, 0, n){
        cin >> vlis[i];
    }
    vlis[n-1] = min(vlis[n-1], tlis[n-1]);
    for(int i = n-2; i >= 0; i--){
        if(vlis[i] > vlis[i+1] + tlis[i]){
            vlis[i] = vlis[i+1] + tlis[i];
        }
    }
    ld ans = 0.0;
    ld speed = 0.0;
    REP(i, 0, n){
        for(ld l = 0; l < tlis[i]; l += 0.5){
            ld speed_pre = speed;
            ld max_speed;
            if(i+1 < n){
                max_speed = min(vlis[i], vlis[i+1] + tlis[i]-l-0.5);
            }else{
                max_speed = min(vlis[i], tlis[i]-l-0.5);
            }
            if(speed < max_speed){
                speed += 0.5;
            }else if(speed == max_speed){

            }else{
                speed -= 0.5;
            }
            //cout << speed << endl;
            ans += (speed_pre + speed) * 0.5 / 2.0;
        }
    }
    cout << std::fixed << std::setprecision(15) << ans << endl;
}