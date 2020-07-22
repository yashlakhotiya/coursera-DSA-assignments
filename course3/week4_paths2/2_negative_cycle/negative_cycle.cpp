#include <iostream>
#include <vector>
#define INT_MAX 99999

using std::vector;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here
  int n = adj.size();
  int dist[n], prev[n];
  for(int i=0; i<n; i++){
    prev[i] = -1;
    dist[i] = INT_MAX;
  }
  dist[0] = 0;
  for(int i=0; i<n-1; i++){
    for(int u=0; u<n; u++){
      vector<int> neighbours = adj[u];
      for(int i=0; i<neighbours.size(); i++){
        int v = neighbours[i];
        if(dist[u] + cost[u][i] < dist[v]){
          dist[v] = dist[u] + cost[u][i];
          prev[v] = u;
        }
      }
    }
  }
  for(int u=0; u<n; u++){
    vector<int> neighbours = adj[u];
    for(int i=0; i<neighbours.size(); i++){
      int v = neighbours[i];
      if(dist[u] + cost[u][i] < dist[v]){
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
