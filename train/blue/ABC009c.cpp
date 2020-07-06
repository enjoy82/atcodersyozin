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
    int n, k; cin >> n >> k;
    string s, c; cin >> s;
    c = s;
    sort(ALL(c));
    string res;
    vector<int> count(26, 0);
    REP(i, 0, n){
        count[s[i]-'a']++;
    }
    vector<int> count2 = count;
    REP(i, 0, n){
        REP(l, 0, 26){
            if(count2[l] == 0){continue;}
            int mid = 0;
            count2[l]--;
            count[s[i]-'a']--;
            REP(k, 0, 26){
                mid += min(count[k], count2[k]);
            }
            int limit = k - ('a'+ l != s[i]);
            if(n-i-1-mid <= limit){
                res += 'a' + l;
                k -= res[i] != s[i];
                break;
            }
            count2[l]++;
            count[s[i]-'a']++;
        }
    }
    cout << res << endl;
}