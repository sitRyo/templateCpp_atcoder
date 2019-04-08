#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
 
#define ALL(x) x.begin(), x.end()
using namespace std;
 
typedef vector<vector<int> > G;
const int inf = 1e9;
 
int n, m;
G graph;
vector<int> ans;
 
int visited[100100];
 
void dfs(int u){
    // cout << u << endl;
    ans.push_back(u);
    visited[u] = 1;
 
    for(int i=0; i<graph[u].size(); i++){
        int v = graph[u][i];
        if( !( visited[v] ) ){
            return dfs(v);
        }
    }
    // return;
}
 
int main(void){
    cin >> n >> m;
    graph = G(n+100);
    for(int i=0; i<m; i++){
 
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
 
    }
    
    dfs(1);
    reverse(ans.begin(), ans.end());
    ans.pop_back();
    dfs(1);
 
    cout << ans.size() << endl;
 
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
 
    cout << endl;
    return 0;
}