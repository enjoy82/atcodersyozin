#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;

long long int kai(int a){
    long long int res = 1;
    for(int i = 2; i<= a; i++){
        res = res * i;
    }
    return res;
}

long long int cho(int a, int b){
    long long int c = kai(a);
    long long int d = kai(b);
    long long int e = kai(a-b);
    return c/(d*e);
}

int main(){
    long long int mod = 1000000007;
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= k; i++){
        long long int ans = (cho(n-k+1, i) * cho(k-1, i-1))%mod;
        cout << ans << endl;
    }
    return 0;
}