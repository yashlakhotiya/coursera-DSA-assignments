#include <iostream>
#include <vector>

using namespace std;

using std::vector;
using std::pair;

int has_cycle(vector<vector<int> > &adj, int v, int visited[], int recursion_stack[]){
	visited[v] = 1;
	recursion_stack[v] = 1;
	vector<int> neighbours = adj[v];
	for(auto u =neighbours.begin(); u != neighbours.end(); u++){
		if(visited[*u] && recursion_stack[*u]){
			return 1;
		}
		if(!visited[*u] && has_cycle(adj,*u,visited,recursion_stack)){
			return 1;
		}
	}
	recursion_stack[v] = 0;
	return 0;
}

int acyclic(vector<vector<int> > &adj,int n) {
  //write your code here
	int recursion_stack[n]= {0};
	int visited[n] = {0};
	for(int v=0; v<n; v++){
		if(!visited[v]){
			if(has_cycle(adj,v,visited,recursion_stack)) return 1;
		}
	}
	return 0;
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
  std::cout << acyclic(adj,n);
}
