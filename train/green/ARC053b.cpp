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
    vector<int> lis(26, 0);
    REP(i, 0, s.size()){
        lis[s[i]-'a']++;
    }
    int count1 = 0, count2 = 0;
    REP(i, 0, 26){
        if(lis[i] % 2 == 1){
            count1++;
            count2 += (lis[i]-1)/2;
        }else{
            count2 += lis[i]/2;
        }
    }
    if(count1 == 0){
        cout << s.size();
    }else{
        cout << (count2/count1)*2+1;
    }
}