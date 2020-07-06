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

struct edge{
    int len;
    int r;
    int l;
};
bool operator>(const edge &a, const edge &b){
    if(a.len < b.len){
        return 1;
    }else if(a.len == b.len){
        if(a.r > b.r){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
};


void solve(){
    int n; cin >> n;
    vector<int> anslis(n, 0);
    edge e = {n, 0, n-1};
    priority_queue<edge, vector<edge>, greater<edge> > pq;
    pq.push(e);
    int i = 0;
    while(!pq.empty()){
        i++;
        edge e = pq.top();
        pq.pop();
        int R = e.r, L = e.l;
        anslis[(R+L)/2] = i;
        int m = (R+L)/2;
        if(R == L){
            continue;
        }else{
            if(R <= m-1){
                pq.push({m-1-R+1, R, m-1});
            }
            if(m+1 <= L){
                pq.push({L-m-1+1, m+1, L});
            }
        }
    }
    REP(i, 0, n){
        cout << anslis[i] << " ";
    }
    cout << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}