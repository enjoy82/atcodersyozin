#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int q; cin >> q;
    vector<vector<int> > lis(n, vector<int>(26, 0));
    for(int i = 0; i < n; i++){
        if(i != 0){
            lis[i] = lis[i-1];
        }
        lis[i][s[i] - 'a']++;
    }
    vector<vector<string> > lis2(n, vector<string>);
    for(int i = 0; i < q; i++){
        int a; cin >> a;
        if(a == 1){
            int k; cin >> k;
            k--;
            char c; cin >> c;
            s[k] = c;
            lis2[k].push_back(c - 'a');
        }else{

        }
    }
}