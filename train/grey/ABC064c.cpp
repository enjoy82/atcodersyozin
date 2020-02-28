#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> lis(8, 0);
    int count = 0;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(a <= 399){
            lis[0]++;
        }else if(a <= 799){
            lis[1]++;
        }else if(a <= 1199){
            lis[2]++;
        }else if(a <= 1599){
            lis[3]++;
        }else if(a <= 1999){
            lis[4]++;
        }else if(a <= 2399){
            lis[5]++;
        }else if(a <= 2799){
            lis[6]++;
        }else if(a <= 3199){
            lis[7]++;
        }else{
            count++;
        }
    }
    int ans1 = 0;
    for(int i = 0; i < 8; i++){
        if(lis[i] > 0){
            ans1++;
        }
    }
    cout << max(ans1, 1) << " " << ans1 + count << endl;
}