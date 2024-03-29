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
    string s; cin >> s;
    char key = s[0];
    int count = 1;
    REP(i, 1, s.size()){
        while(i < s.size() && s[i] == key){
            i++;
            count++;
        }
        cout << key << count;
        if(i == s.size()-1 && s.back() != s[s.size()-2]){
            cout << s.back() << 1 << endl;
            return 0;
        }
        count = 1;
        key = s[i];
    }
    cout << endl;
}