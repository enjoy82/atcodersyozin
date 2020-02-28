#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int an = 0;
int n;

struct inf{
    int x, y;
};

void solve(vector<vector<inf> > &lis, int num, int f, vector<int> flag, int ans, vector<int> truth){
    if(f == 0){
        truth[num] = 0;
        if(flag[num] == 1){
            return;
        }
        for(int i = 0; i < lis[num].size(); i++){
            int a = lis[num][i].x - 1;
            if(lis[num][i].y == 1){
                if(flag[a] == 1){
                    return;
                }
                flag[a] = 0;
                if(truth[a] == 1){
                    return;
                }
            }else{
                if(flag[a] == 0){
                    return;
                }
                flag[a] = 1;
                if(truth[a] == 0){
                    return;
                }
            }
        }
        ans++;
    }else{
        truth[num] = 1;
        if(flag[num] == 0){
            return;
        }
    }
    if(num == n-1){
        an = max(ans, an);
        return;
    }
    num++;
    solve(lis, num, 0, flag, ans, truth);
    solve(lis, num, 1, flag, ans, truth);
}

int main(){
    cin >> n;
    vector<vector<inf> > lis(n);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        for(int l = 0; l < a; l++){
            int x, y; cin >> x >> y;
            inf k = {x, y};
            lis[i].push_back(k);
        }
    }
    vector<int> flag(n, -1);
    vector<int> truth(n, -1);
    solve(lis, 0, 0, flag, 0, truth);
    solve(lis, 0, 1, flag, 0, truth);
    cout << an << endl;
}