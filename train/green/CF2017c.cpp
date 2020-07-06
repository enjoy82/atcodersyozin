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
    string s, t = ""; cin >> s;
    REP(i, 0, s.size()){
        if(s[i] != 'x'){
            t = t + s[i];
        }
    }
    int en = t.size()-1;
    REP(i, 0, t.size()/2){
        if(t[i] != t[en-i]){
            cout << -1 << endl;
            return 0;
        }
    }
    vector<int> lis(t.size()+1, 0), lis2(t.size()+1, 0);
    int l = 0;
    REP(i, 0, (t.size()+1)/2){
        int count = 0;
        while(1){
            if(s[l] == t[i]){
                lis[i] = count;
                l++;
                break;
            }else{
                count++;
                l++;
            }
        }
    }
    reverse(ALL(s));
    reverse(ALL(t));
    l = 0;
    REP(i, 0, (t.size()+1)/2){
        int count = 0;
        while(1){
            if(s[l] == t[i]){
                lis2[i] = count;
                l++;
                break;
            }else{
                count++;
                l++;
            }
        }
    }
    ll ans = 0;
    REP(i, 0, lis.size()){
        ans += abs(lis[i] - lis2[i]);
    }
    cout << ans << endl;
}