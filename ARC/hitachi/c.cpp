#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<int> > tree;
vector<int> treecolor;
int red = 1;
int blue = 0;

void paint(int s, int color){
    for(int i = 0; i < tree[s].size(); i++){
        int to = tree[s][i];
        if(treecolor[to] != 0){
            continue;
        }else{
            if(color == 1){
                red++;
            }else{
                blue++;
            }
            treecolor[to] = color;
            paint(to, color * -1);
        }
    }
}

int main(){
    int n; cin >> n;
    tree = vector<vector<int> >(n+1);
    treecolor = vector<int>(n+1, 0);
    vector<int> anslis(n+1);
    treecolor[1] = 1;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    paint(1, -1);
    int maxred = (n + 2) / 3;
    int maxblue = (n + 1) / 3;
    int maxc = n / 3;
    int rc = 0, bc = 0, c = 0;
    if(red > n / 3 && blue > n/3){
        int i = 1;
        for(;rc < maxred && i <= n; i++){
            if(treecolor[i] == 1){
                anslis[i] = rc * 3 + 1;
                rc++;
            }
        }
        for(; i <= n; i++){
            if(treecolor[i] == 1){
                anslis[i] = c * 3 + 3;
                c++;
            }
        }
        i = 1;
        for(;bc < maxblue && i <= n; i++){
            if(treecolor[i] == -1){
                anslis[i] = bc * 3 + 2;
                bc++;
            }
        }
        for(; i <= n; i++){
            if(treecolor[i] == -1){
                anslis[i] = c * 3 + 3;
                c++;
            }
        }
    }else if(red <= n/3){
        int i = 1;
        for(;i <= n; i++){
            if(treecolor[i] == 1){
                anslis[i] = c * 3 + 3;
                c++;
            }
        }
        i = 1;
        for(; rc < maxred && i <= n; i++){
            if(treecolor[i] == -1){
                anslis[i] = rc * 3 + 1;
                rc++;
            }
        }
        for(; bc < maxblue && i <= n; i++){
            if(treecolor[i] == -1){
                anslis[i] = bc * 3 + 2;
                bc++;
            }
        }
        for(; c < maxc && i <= n; i++){
            if(treecolor[i] == -1){
                anslis[i] = c * 3 + 3;
                c++;
            }
        }
    }else{
        int i = 1;
        for(;i <= n; i++){
            if(treecolor[i] == -1){
                anslis[i] = c * 3 + 3;
                c++;
            }
        }
        i = 1;
        for(; rc < maxred && i <= n; i++){
            if(treecolor[i] == 1){
                anslis[i] = rc * 3 + 1;
                rc++;
            }
        }
        for(; bc < maxblue && i <= n; i++){
            if(treecolor[i] == 1){
                anslis[i] = bc * 3 + 2;
                bc++;
            }
        }
        for(; c < maxc && i <= n; i++){
            if(treecolor[i] == 1){
                anslis[i] = c * 3 + 3;
                c++;
            }
        }
    }
    for(int  i = 1; i <= n; i++){
        cout << anslis[i] << " ";
    }
}