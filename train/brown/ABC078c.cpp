#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    cout << (1900 * m + 100*(n-m)) * (int)pow(2, m) << endl;
}