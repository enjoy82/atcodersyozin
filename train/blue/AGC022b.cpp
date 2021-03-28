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
    if(n == 3){
        cout << 2 << " " << 5 << " " << 63 << endl;
        return 0;
    }else if(n == 4){
        cout << 2 << " " << 5 << " " << 20 << " " << 63 << endl;
        return 0;
    }else if(n == 5){
        cout << 2 << " " << 5 << " " << 20 << " " << 30 << " " <<  63 << endl;
        return 0;
    }else{
        ll sum = 0;
        vector<int> anslis;
        int i = 1;
        while(anslis.size() != n){
            if(i % 6 == 2 || i % 6 == 3 || i % 6 == 4 || i % 6 == 0){
                anslis.pb(i);
                sum += i;
            }
            i++;
        }
        int ma6 = anslis.back() / 6, ma = anslis.back();
        if(sum % 6 == 2){
            for(int i = anslis.size()-1; i >= 0; i--){
                if(anslis[i] % 6 == 2){
                    anslis[i] = ma6 * 6 + 6;
                    break;
                }
            }
        }else if(sum % 6 == 3){
            for(int i = anslis.size()-1; i >= 0; i--){
                if(anslis[i] % 6 == 3){
                    anslis[i] = ma6 * 6 + 6;
                    break;
                }
            }
        }else if(sum % 6 == 5){
            for(int i = anslis.size()-1; i >= 0; i--){
                if(anslis[i] % 6 == 2){
                    anslis[i] = ma6 * 6 + 3;
                    if(anslis[i] <= ma){
                        anslis[i] = ma6 * 6 + 9;
                    }
                    break;
                }
            }
        }
        REP(i,0,n){
            cout << anslis[i] << " ";
        }
        cout << endl;
    }
}