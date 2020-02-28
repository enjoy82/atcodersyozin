#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> lis(100000, 0);
    lis[0] = 1;
    for(int i = 0; i < n; i++){
        int mid; cin >> mid;
        for(int l = 10000; l >= mid; l--){
            if(lis[l-mid] == 1){
                lis[l] = 1;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 10000; i++){
        if(lis[i] == 1 && i % 10 != 0){
            ans = i;
        }
    }
    cout << ans << endl;
}