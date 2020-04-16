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

int main(){
    string s; cin >> s;
    string lis = "ddrrmffssllS", o = "WBWBWWBWBWBW";
    lis = lis + lis + lis + lis + lis;
    o = o + o + o + o + o;
    int i = 0;
    char ans;
    while(1){
        int f = 1;
        REP(l, 0, s.size()){
            if(s[l] == o[i+l]){
                continue;
            }else{
                f = -1;
                break;
            }
        }
        if(f == -1){
            i++;
            continue;
        }else{
            ans = lis[i];
            break;
        }
    }
    if(ans== 'd'){cout << "Do";}
    else if(ans == 'r'){cout << "Re";}
    else if(ans == 'm'){cout << "Mi";}
    else if(ans == 'f'){cout << "Fa";}
    else if(ans == 's'){cout << "So";}
    else if(ans == 'l'){cout << "La";}
    else if(ans == 'S'){cout << "Si";}
}