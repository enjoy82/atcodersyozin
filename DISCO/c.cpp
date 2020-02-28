#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int h, w, k; cin >> h >> w >> k;
    vector<vector<int> > lis(h, vector<int>(w, 0));
    vector<vector<int> > ans(h, vector<int>(w, 0));
    for(int i = 0; i < h; i++){
        string s; cin >> s;
        for(int l = 0; l < w; l++){
            if(s[l] == '#'){
                lis[i][l] = 1;
            }else{
                lis[i][l] = 0;
            }
        }
    }
    int m = 1;
    int first = 0;
    vector<int> flag(h, 0);
    for(int i = 0; i < h; i++){
        for(int l = 0; l < w; l++){
            ans[i][l] = m;
            if(lis[i][l] == 1){
                if(first != 0){
                    m++;
                }
                first = 1;
                ans[i][l] = m;
                flag[i] = 1;
            }
        }
        first = 0;
        m++;
        if(flag[i] == 0){
            for(int l = 0; l < w; l++){
                ans[i][l]--;
            }
            m--;
        }
    }
    for(int i = 0; i < h; i++){
        if(flag[i] == 0){
            int l = i + 1;
            while(1){
                if(l >= h){
                    break;
                }
                if(flag[l] == 1){
                    break;
                }
                l++;
            }
            if(l >= h){break;}
            for(int k = i; k < l; k++){
                for(int o = 0; o < w; o++){
                    ans[k][o] = ans[l][o];
                }
            }
        }
    }
    if(flag[h-1] == 0){
            int l = h-2;
            while(1){
                if(l < 0){
                    break;
                }
                if(flag[l] == 1){
                    break;
                }
                l--;
            }
            for(int k = h-1; k >l; k--){
                for(int o = 0; o < w; o++){
                    ans[k][o] = ans[l][o];
                }
            }
    }

    for(int i = 0; i < h; i++){
        for(int l = 0; l < w; l++){
            cout << ans[i][l] << " "; 
        }
        cout << endl;
    }
}