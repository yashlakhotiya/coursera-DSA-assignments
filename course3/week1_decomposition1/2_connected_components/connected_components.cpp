#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void explore(vector<vector<int> > &adj, int v, int visited[]){
  visited[v] = 1;
  vector<int> neighbours = adj[v];
  for(auto u =neighbours.begin(); u != neighbours.end(); u++){
    if(!visited[*u]){
      explore(adj,*u,visited);
    }
  }
}

int number_of_components(vector<vector<int> > &adj, int visited[]) {
  int res = 0;
  for(int v=0; v<adj.size(); v++){
    if(!visited[v]){
      explore(adj,v,visited);
      res++;
    }
  }

  //write your code here
  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int visited[n] = {0};
  std::cout << number_of_components(adj,visited);
}
