#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    vector<vector<int> > a(n);
    for(int i = 0; i < n; i++){
        for(int l = 0; l < n-1; l++){
            int mid; cin >> mid;
            a[i].push_back(mid);
        }
    }
    int b = n*(n-1) / 2;
    int j=0, ans=0, count=0, exit = 0;
    int dellis[1000];
    while(j != b){
        exit = 0;
        count = 0;
        for(int i = 0; i < n; i++){
            cout << i+1 << a[a[i][0]-1][0] << endl;
            if(i+1 == a[a[i][0]-1][0]){
                dellis[count] = i;dellis[count+1] = a[a[i][0]-1][0];
                exit = 1;
                j++;count += 2;
            }
        }
        for(int l = 0; l < count; l++){
            a[dellis[l]].erase(a[dellis[l]].begin());
        }
        ans++;
        if(exit == 0){cout << -1 << endl; break;}
    }
    cout << ans << endl;
}