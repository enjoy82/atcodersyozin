#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    string s1, s2, s3; cin >> s1 >> s2 >> s3;
    vector<int> allis1(26, 0), allis2(26, 0), allis3(26, 0);
    REP(i, 0, s1.size()){
        allis1[s1[i]-'A']++;
        allis2[s2[i]-'A']++;
        allis3[s3[i]-'A']++;
    }
    int c1 = 0, c2 = 0;
    int f = 1;
    REP(i, 0, 26){
        if(allis3[i] > 0){
            c1 += allis1[i];
            c2 += allis2[i];
        }
        if(allis1[i] > allis1[i] + allis2[i]){
            f = 0;
        }
    }
    if(f == 1 && c1 >= s1.size()/2 && c2 >= s1.size()/2){
        int mi = 0, ma = 0;
        REP(i, 0, 26){
            if(allis3[i] > 0){
                mi += max(0, allis3[i] - allis2[i]);
                ma += min(allis1[i], allis3[i]);
            }
        }
        if(mi <= s1.size()/2 && ma >= s1.size()/2){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }else{
        cout << "NO" << endl;
    }
}