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
    string s1, s2, s3; cin >> s1 >> s2 >> s3;
    vector<int> flag(26, 0);
    REP(i,0,s1.size()){
        flag[s1[i]-'a'] = 1;
    }
    REP(i,0,s2.size()){
        flag[s2[i]-'a'] = 1;
    }
    REP(i,0,s3.size()){
        flag[s3[i]-'a'] = 1;
    }
    int count = 0;
    vector<int> clis;
    REP(i,0,26){
        if(flag[i]){
            clis.pb(i);
        }
    }
    if(clis.size() > 11){
        cout << "UNSOLVABLE" << endl;
        return 0;
    }
    vector<int> v(10);
    REP(i,0,10){
        v[i] = i;
    }
    do {
        ll ss1 = 0, ss2 = 0, ss3 = 0;
        //string ss1 = "", ss2 = "", ss3 = "";
        REP(i,0,s1.size()){
            int key = s1[i] - 'a';
            REP(l,0,clis.size()){
                if(key == clis[l]){
                    ss1 *= 10;
                    ss1 += v[l];
                }
            }
        }
        //cout << ss1 << " ";

        REP(i,0,s2.size()){
            int key = s2[i] - 'a';
            REP(l,0,clis.size()){
                if(key == clis[l]){
                    ss2 *= 10;
                    ss2 += v[l];
                }
            }
        }
        //cout << ss2 << " ";

        REP(i,0,s3.size()){
            int key = s3[i] - 'a';
            REP(l,0,clis.size()){
                if(key == clis[l]){
                    ss3 *= 10;
                    ss3 += v[l];
                }
            }
        }
        //cout << ss3 << endl;
        if(to_string(ss1).size() != s1.size() || to_string(ss2).size() != s2.size() ||to_string(ss3).size() != s3.size()){
            continue;
        }
        if(s1.size() == 1){
            if(ss1 == 0){
                continue;
            }
        }
        if(s2.size() == 1){
            if(ss2 == 0){
                continue;
            }
        }
        if(s3.size() == 1){
            if(ss3 == 0){
                continue;
            }
        }
        //ll is1 = stoi(ss1), is2 = stoi(ss2), is3 = stoi(ss3); 
        if(ss1 + ss2 == ss3){
            cout << ss1 << endl;
            cout << ss2 << endl;
            cout << ss3 << endl;
            return 0;
        }
    } while (std::next_permutation(v.begin(), v.end()));


    cout << "UNSOLVABLE" << endl;
    return 0;
}