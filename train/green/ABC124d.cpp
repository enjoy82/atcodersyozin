#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

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
    string s; cin >> s;
    int sum = 0;
    int r = 1;
    int ans = 0;
    if(s[0] == '0'){
        sum++;
    }
    REP(l, 0, n){
        while(sum < k+1){
            //cout << l << r << endl << sum << endl;
            if(r == n){
                break;
            }else{
                if(s[r-1] == '1' && s[r] == '0'){
                    sum++;
                }
                r++;
            }
        }
        if(r == n){
            if(s[n-1] == '0' && s[n-2] == '1'){
                ans = max(ans, r-l-1);
            }else{
                ans = max(ans, r-l);
            }
        }else{
            ans = max(ans, r-l-1);
        }
        if(l+1 < n && s[l] == '0' && s[l+1] == '1'){
            sum--;
        }
    }
    cout << ans << endl;
}