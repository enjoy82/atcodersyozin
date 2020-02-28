#include<iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int memo[1000001] = {0};
int mod = pow(10, 9) + 7;

int saiki(int s){
    if(memo[s] != -1){return memo[s];}
    if(s == 0){return 1;}
    int ans = (saiki(s-1) + saiki(s-2))%mod;
    memo[s] = ans;
    return ans;
}
int main(){
    int n, m;
    cin >> n >> m;
    for(int l = 0; l <1000001; l++){
        memo[l] = -1;
    }
    for(int i=0;i<m;i++){
        int o;cin >> o;
        memo[o] = 0;
    }
    cout << saiki(n) << endl;
}