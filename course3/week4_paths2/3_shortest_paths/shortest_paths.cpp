#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

void negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost, vector<int> prev, vector<long long> dist, vector<int> &reachable, vector<int> &shortest) {
  //write your code here
  int n = adj.size();
  
}

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &dist, vector<int> &reachable, vector<int> &shortest) {
  //write your code here
  int n = adj.size();
  vector<int> prev(n,-1);
  dist[s] = 0;
  for(int i=0; i<n-1; i++){
    for(int u=0; u<n; u++){
      vector<int> neighbours = adj[u];
      for(int j=0; j<neighbours.size(); j++){
        int v = neighbours[j];
        if(dist[u] < std::numeric_limits<long long>::max() && dist[u] + cost[u][j] < dist[v]){
          reachable[v] = 1;
          dist[v] = dist[u] + cost[u][j];
          prev[v] = u;
          //cout<<u+1<<":"<<v+1<<":"<<dist[v]<<endl;
        }
      }
    }
  }

  queue<int> negative_cycle;
  for(int u=0; u<n; u++){
    vector<int> neighbours = adj[u];
    for(int j=0; j<neighbours.size(); j++){
      int v = neighbours[j];
      if(dist[u] < std::numeric_limits<long long>::max() && dist[u] + cost[u][j] < dist[v]){
        negative_cycle.push(v);
        shortest[v] = 0;
        dist[v] = dist[u] + cost[u][j];
        prev[v] = u;
      }
    }
  }

  bool visited[n] = {false};

  while(!negative_cycle.empty()){
    int u = negative_cycle.front();
    negative_cycle.pop();
    visited[u] = true;
    vector<int> neighbours = adj[u];
    for(int v:neighbours){
      if(visited[v] == false){
        negative_cycle.push(v);
        shortest[v] = 0;
        visited[v] = true;
      }
    }
  }
  // for(int i=0; i<n; i++){
  //   cout<<i+1<<":"<<dist[i]<<":"<<reachable[i]<<":"<<shortest[i]<<"\t";
  // }
  // cout<<endl;
}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> dist(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  reachable[s] = 1;
  shortest[s] = 1;
  shortest_paths(adj, cost, s, dist, reachable, shortest);
  cout<<endl;
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << dist[i] << "\n";
    }
  }
}
