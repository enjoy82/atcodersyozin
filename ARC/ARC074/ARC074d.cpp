#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin >> n;
    vector<long long int> red(n+1);
    vector<long long int> blue(n+1);
    priority_queue<int, vector<int>, greater<int> > first;
    priority_queue<int> end;
    vector<int> mid(n);
    long long int max = 0;
    long long int min = 0;
    for(int i = 0; i<n;i++){
        int b;cin>>b;
        max += b;
        first.push(b);
    }
    red[0] = max;
    for(int l = 0; l<n;l++){
        int b; cin >> b;
        mid[l] = b;
        if(b > first.top()){
            max -= first.top();
            max += b;
            first.pop();
            first.push(b);
        }
        red[l+1] = max;
        //cout << max << endl;
    }
    for(int i = 0; i<n;i++){
        int b; cin>>b;
        min += b;
        end.push(b);
    }
    blue[n] = min;
    for(int l = 0; l<n;l++){
        int b = mid[n-1-l];
        if(b < end.top()){
            min -= end.top();
            min += b;
            end.pop();
            end.push(b);
        }
        blue[n-1-l] = min;
        //cout << min << endl;
    }
    long long int ans = red[0] - blue[0];
    for(int i = 1;i<=n; i++){
        if(ans < red[i]-blue[i]){
            ans = red[i]-blue[i];
        }
    }
    cout << ans << endl;
}