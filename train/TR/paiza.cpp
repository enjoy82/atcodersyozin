#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
    int w, h; cin >> w >> h;
    int x, y, gx, gy;
    vector<vector <int> > a(h, vector<int>(w, 0));
    vector<vector <int> > dp(h, vector<int>(w, 1000000));
    for(int i = 0; i < h; i++){
        for(int l = 0; l < w; l++){
            char mid; cin >> mid;
            if(mid == '0'){
                a[i][l] = 0;
            }else if(mid == '1'){
                a[i][l] = 1;
            }else if(mid == 's'){
                a[i][l] = 0;
                x = i; y = l;
            }else{
                a[i][l] = 0;
                gx = i; gy = l;
            }
        }
    }
    dp[x][y] = 0;
    int v;
    int flag = 0;
    queue<int> xque, yque, vque;
    if(x-1 >= 0 && a[x-1][y] == 0 && dp[x-1][y] > dp[x][y]-2){xque.push(x-1); yque.push(y); vque.push(0);}
    if(y-1 >= 0 && a[x][y-1] == 0 && dp[x][y-1] > dp[x][y]-2){xque.push(x); yque.push(y-1); vque.push(0);}
    if(x+1 < h && a[x+1][y] == 0 && dp[x+1][y] > dp[x][y]-2){xque.push(x+1); yque.push(y); vque.push(0);}
    if(y+1 < w && a[x][y+1] == 0 && dp[x][y+1] > dp[x][y]-2){xque.push(x); yque.push(y+1); vque.push(0);}
    while(x != gx && y != gy || xque.empty() != true){
        x = xque.front();
        xque.pop();
        y = yque.front();
        yque.pop();
        v = vque.front();
        vque.pop();
        dp[x][y] = min(dp[x][y], v+1);
        if(x == gx && y == gy){
            flag = 1;
        }
        //cout << x << y << dp[x][y] << endl;
        if(x-1 >= 0 && a[x-1][y] == 0 && dp[x-1][y]-1 > dp[x][y]){xque.push(x-1); yque.push(y); vque.push(dp[x][y]);}
        if(y-1 >= 0 && a[x][y-1] == 0 && dp[x][y-1]-1 > dp[x][y]){xque.push(x); yque.push(y-1); vque.push(dp[x][y]);}
        if(x+1 < h && a[x+1][y] == 0 && dp[x+1][y]-1 > dp[x][y]){xque.push(x+1); yque.push(y); vque.push(dp[x][y]);}
        if(y+1 < w && a[x][y+1] == 0 && dp[x][y+1]-1 > dp[x][y]){xque.push(x); yque.push(y+1); vque.push(dp[x][y]);}
    }
    if(flag == 0){
        cout << "Fail" << endl;
    }else{
        cout << dp[gx][gy] << endl;
    }
    /*for(int i = 0; i < h; i++){
        for(int l = 0; l < w; l++){
            cout << a[i][l];
        }
        cout << endl;
    }*/
}