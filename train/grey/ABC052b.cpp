#include<bits/stdc++.h>
using namespace std;
#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
int main(){
    int n; string s; cin >> n >> s;
    vector<int> lis(n+1, 0);
    REP(i, 0, n){
        if(s[i] == 'I')
            lis[i+1] = lis[i] + 1;
        else
            lis[i+1] = lis[i] - 1;
    }
    sort(ALL(lis));
    cout << lis[n] << endl;
}