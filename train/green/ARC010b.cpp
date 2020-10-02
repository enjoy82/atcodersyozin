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
    vector<int> days(367, 0);
    REP(i, 1, 367){
        if(i % 7 == 1 || i % 7 == 0){
            days[i] = 1;
        }
    }
    int n; cin >> n;
    int m1[1] = {2};
    int m2[4] = {4, 6, 9, 11};
    int m3[7] = {1, 3, 5, 7, 8, 10, 12};
    map<int, int> mp;
    REP(i, 0, 1){
        mp[m1[i]] = 29;
    }
    REP(i, 0, 4){
        mp[m2[i]] = 30;
    }
    REP(i, 0, 7){
        mp[m3[i]] = 31;
    }
    REP(i, 0, n){
        string s; cin >> s;
        stringstream ss;
        ss << s;
        int month, date;
        ss >> month;
        ss.ignore();
        ss >> date;
        int k = 1;
        while(k != month){
            date += mp[k];
            k++;
        }
        days[date]++;
    }
    int count = 0;
    REP(i, 1, days.size()){
        if(days[i] == 2){
            count ++;
        }
        if(count >= 1 && days[i] == 0){
            days[i] = 1;
            count--;
        }
    }
    int ans = 0;
    int c = 0;
    REP(i, 1, days.size()){
        if(days[i] == 0){
            c = 0;
        }else{
            c++;
            chmax(ans, c);
        }
    }
    cout << ans << endl;
}