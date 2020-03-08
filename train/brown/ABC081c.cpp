#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<int> lis(n+1, 0);
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        lis[k]++;
    }
    sort(lis.begin(), lis.end(), greater<>());
    int mid = 0;
    for(int i = 0; i < k; i++){
        mid += lis[i];
    }
    cout << n - mid << endl;
}