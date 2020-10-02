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
    string s;
    map<int, string> mp;
    cout << 0 << endl;
    cin >> s;
    if(s == "Vacant"){
        return 0;
    }else{
        mp[0] = s;
    }
    cout << n-1 << endl;
    cin >> s;
    if(s == "Vacant"){
        return 0;
    }else{
        mp[n-1] = s;
    }
    int left = 0, right = n-1;
    REP(i, 0, 20){
        int mid = (left + right) / 2;
        int flag = 1;
        cout << mid << endl;
        cin >> s;
        if(s == "Vacant"){
            return 0;
        }else{
            mp[mid] = s;
        }
        if((mid - left) % 2 == 0){
            if(mp[mid] != mp[left]){
                flag = 0;
                right = mid;
            }
        }else{
            if(mp[mid] == mp[left]){
                flag = 0;
                right = mid;
            }
        }
        if(flag){
            if((right - mid) % 2 == 0){
                if(mp[mid] != mp[right]){
                    left = mid;
                }
            }else{
                if(mp[mid] == mp[right]){
                    left = mid;
                }
            }
        }
    }
}