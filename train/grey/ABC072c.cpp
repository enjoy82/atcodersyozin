#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> lis(1e5+10, 0);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        lis[a]++;
        lis[a+1]++;
        lis[a+2]++;
    }
    int ma = 0;
    for(int i = 0; i < 1e5+5 ;i++){
        ma = max(lis[i], ma);
    }
    cout << ma << endl;
}