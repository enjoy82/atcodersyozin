#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    vector<string> sortlist;
    for(int i = 0; i < n; i++){
        string a; cin >> a;
        sort(a.begin(), a.end());
        sortlist.push_back(a);
    }
    sort(sortlist.begin(), sortlist.end());
    long long int count = 1;
    long long int ans = 0;
    for(int i = 0; i < n-1; i++){
        if(sortlist[i] == sortlist[i+1]){
            count++;
        }else{
            ans += (count*(count-1))/2;
            count = 1;
        }
    }
    ans += (count*(count-1))/2;
    cout << ans << endl;
}  