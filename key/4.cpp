#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int mi = 1000000;
int n; 
 
void bable(vector<vector<int> > after){
    sort(after.begin(), after.end(), [](auto& x, auto& y){return x[0] < y[0];});
    int k = 0;
    for(int i = 0; i < n; i++){
        if(abs(after[i][1] - i) % 2 == 1 && after[i][2] == 0 || (abs(after[i][1] - i) % 2 == 0 && after[i][2] == 1)){
            return;
        }
        k += abs(after[i][1] - i);//あやしい
    }
    mi = min(k/2, mi);
    return;
}
 
void solve(vector<vector<int> > &lis, vector<vector<int> > after, int num){
    if(num == n){
        bable(after);
        return;
    }
    after[num][1] = lis[num][2]; //preindex
    after[num][0] = lis[num][0];
    after[num][2] = 0;
    solve(lis, after, num+1);
    after[num][0] = lis[num][1];
    after[num][2] = 1;
    solve(lis, after, num+1);
    return;
}
 
int main(){
    cin >> n;
    vector<vector<int> > lis(n, vector<int>(3, 0));
    vector<vector<int> > after(n, vector<int>(3, 0)); //0->num 1->preindex 2->omote0ura1
    for(int i = 0; i < n; i++){
        cin >> lis[i][0];
    }
    for(int i = 0; i < n; i++){
        cin >> lis[i][1];
        lis[i][2] = i;
    }
    solve(lis, after, 0);
    if(mi == 1000000){
        cout << -1 << endl;
        return 0;
    }
    cout << mi << endl;
    return 0;
}