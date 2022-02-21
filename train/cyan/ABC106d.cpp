#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int a[510][510];
int main(){
    int n, m, q; cin >> n >> m>> q;    
    for(int i = 0; i < m; i++){
        int l, r; cin >> l >> r;
        a[l][r]++;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] += a[i][j-1];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] += a[i-1][j];
        }
    }
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        cout << a[l-1][l-1] +a[r][r] - a[r][l-1]- a[l-1][r]<< endl;
    }
}