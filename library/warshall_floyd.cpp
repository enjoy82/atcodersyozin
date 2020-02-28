#define MAX_V 1000

int d[MAX_V][MAX_V];
int V; //頂点数

void warshall_floyd(){
    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int l = 0; l < V; l++){
                d[i][l] = min(d[i][l], d[i][k] + d[k][l]);
            }
        }
    }
}