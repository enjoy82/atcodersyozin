# include<iostream>
# include<vector>
#include<algorithm>
#include<cstdlib>
#include <math.h>
using namespace std;

int check(int a){
    for(int i =1; i <= a;i++){
        if(i*i == a){
            return 1;
        }
    }
    return 0;
}

int main(){
    int n, d;cin >> n >> d;
    vector<vector <int>> a(n, vector<int>(d, 0));
    for(int i=0; i<n ;i++){
        for(int l=0;l<d;l++){
            cin >> a[i][l];
        }
    }
    int ans =0;
    int res = 0;
    for(int i=0; i<n-1 ;i++){
        for(int k = i+1; k<n; k++){
            res = 0;
            for(int l=0;l<d;l++){
                res += pow((a[i][l]-a[k][l]),2.0);
            }
        if(check(res) == 1){ans++;}
        }
    }
    cout << ans << endl;
}