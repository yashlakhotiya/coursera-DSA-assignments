#include <iostream>
#include <vector>

using std::vector;
using std::pair;


int reach(vector<vector<int> > &adj, int x, int y, int visited[]) {
  //write your code here
	visited[x] = 1;
 	vector<int> neighbours = adj[x];
	for(auto u =neighbours.begin(); u != neighbours.end(); u++){
		if(!visited[*u]){
			reach(adj,*u,y,visited);
		}
	}
	if(visited[y] == 1) return 1;
  	else return 0;
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
  int x, y;
  std::cin >> x >> y;
  int visited[n] = {0};
  std::cout << reach(adj, x - 1, y - 1, visited);
}
