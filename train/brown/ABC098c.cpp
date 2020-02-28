#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    string S; cin >> S;
    vector<vector<int> > lis(n, vector<int>(2, 0));
    int e = 0, w = 0;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == 'E'){
            e++;
        }else{
            w++;
        }
        lis[i][0] = e;
        lis[i][1] = w;
    }
    int ans = 1e7; 
    for(int i = 0; i < S.size(); i++){
        int mid = lis[i][1] + e - lis[i][0];
        if(S[i] == 'W'){
            mid--;
        }
        ans = min(ans, mid);
    }
    cout << ans << endl;
}