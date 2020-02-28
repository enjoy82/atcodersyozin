#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int h, w, n;
int flag = 0;

void solve(vector<vector<int> >& ans, int count, int &posx, int &posy, int c){
    if(posx < 0){
        posy++;
        posx = 0;
        flag = 0;
    }else if(posx >= w){
        posy++;
        posx = w-1;
        flag = 1;
    }
    ans[posy][posx] = c;
    if(flag == 0){
        posx++;
    }else{
        posx--;
    }
    count--;
    if(count > 0){
        solve(ans, count , posx, posy, c);
    }
}

int main(){
    cin >> h >> w >> n;
    vector<vector<int> > ans(h, vector<int>(w, 0));
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int posx = 0, posy = 0;
    for(int i = 1; i <= n; i++){
        int count = a[i];
        solve(ans, count , posx, posy, i);

    }
    for(int i = 0; i < h; i++){
        for(int l = 0; l < w; l++){
            cout << ans[i][l] << " ";
        }
        cout << endl;
    }
}