#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<int> lis(n, 0);
    for(int i = 0; i < n-1; i++){
        if(s[i] == 'A' && s[i+1] == 'C'){
            lis[i+1]++;
        }
    }
    for(int i = 1; i < n; i++){
        lis[i] = lis[i] + lis[i-1];
    }
    for(int i = 0; i < q; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        cout << lis[b] - lis[a] << endl;
    }
    return 0;
}