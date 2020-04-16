#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main(){
    string s, t; cin >> s >> t;
    vector<int> alpha1(26, 0), alpha2(26, 0);
    REP(i, 0, s.size()){
        alpha1[s[i]-'a']++;
    }
    REP(i, 0, t.size()){
        alpha2[t[i]-'a']++;
    }
    string a = "";
    REP(i, 0, 26){
        REP(l, 0, alpha1[i]){
            a = a + alpha[i];
        }
    }
    string b = "";
    for(int i = 25; i >= 0; i--){
        REP(l, 0, alpha2[i]){
            b = b + alpha[i];
        }
    }
    if(a < b){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}