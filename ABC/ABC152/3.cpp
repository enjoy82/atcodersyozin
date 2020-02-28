#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> lis(n);
    for(int i = 0; i < n; i++){
        cin >> lis[i];
    }
    int k = lis[0];
    int ans = 1;
    for(int i = 1; i < n; i++){
        if(k < lis[i]){
            continue;
        }
        ans++;
        k = lis[i];
    }
    cout << ans <<endl;
}