#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using std::vector;
using std::pair;

void dfs(vector<vector<int> > &adj,int i, vector<int> &used, int visited[]) {
  //write your code here
  visited[i] = 1;
  vector<int> neighbours = adj[i];
  for(auto u = neighbours.begin(); u != neighbours.end(); u++){
    if(!visited[*u]){
      dfs(adj,*u,used,visited);
    }
  }
  used.push_back(i);
}     

vector<int> toposort(vector<vector<int> > adj,int n) {
  vector<int> used;
  vector<int> order;
  //write your code here
  int visited[n] = {0};
  for(int i=0; i<n; i++){
    if(!visited[i]){
      dfs(adj,i,used,visited);
    }
  }
  for(auto i = used.end()-1; i != used.begin()-1; i--){
    order.push_back(*i);
  }
  return order;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<int> order = toposort(adj,n);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
