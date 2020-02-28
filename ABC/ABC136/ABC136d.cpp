#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    vector<long long int > ans(s.size(), 0);
    int j = 0;
    int ans1 = 0;
    int mid = 0;
    int start = 0;;
    int res;
    for(int i = 0; i < s.size(); i++){
        if(j == 0){
            if(s[i] == 'L'){
                j = 1;
                mid = i;
            }
        }else if(j == 1){
            if(s[i] == 'R'){
                j = 0;
               res = max((start - mid),(i - mid));
           float f = i - start;
            if(res % 2 == 1){
                ans[mid] = round(f/2);
                ans[mid-1] = f/2;
            }else{
                ans[mid-1] = round(f/2);
                ans[mid] = f/2;
            }
                ans1 = 0;
                start = i;
            }
        }
        ans1++;
        if(i == s.size()-1){
           res = max((start - mid),(i+1 - mid));
           float f = i+1 - start;
            if(res % 2 == 1){
                ans[mid] = round(f/2);
                ans[mid-1] = f/2;
            }else{
                ans[mid-1] = round(f/2);
                ans[mid] = f/2;
            }
        }
    }
    for(int i = 0; i < s.size(); i++){
        cout << ans[i] << " ";
    }
}