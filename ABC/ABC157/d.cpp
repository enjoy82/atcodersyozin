#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    vector<vector<int> > lis(3, vector<int>(3, 0));
    for(int i = 0; i < 3; i++){
        for(int l = 0; l < 3; l++){
            cin >> lis[i][l];
        }
    }
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        for(int i = 0; i < 3; i++){
            for(int l = 0; l < 3; l++){
                if(k == lis[i][l]){
                    lis[i][l] = -1;
                }
            }
        }
    }
    int f = 0;
    for(int i = 0; i < 3; i++){
        if(lis[i][0] == lis[i][1] && lis[i][1] == lis[i][2]){
            f = 1;
        }
    }
    for(int l = 0; l < 3; l++){
        if(lis[0][l] == lis[1][l] && lis[1][l] == lis[2][l]){
            f = 1;
        }
    }
    if(lis[0][0] == lis[1][1] && lis[1][1] == lis[2][2]){
        f = 1;
    }
    if(lis[2][0] == lis[1][1] && lis[1][1] == lis[0][2]){
        f = 1;
    }
    if(f == 1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}