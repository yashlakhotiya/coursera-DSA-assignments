#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using std::vector;
using std::queue;

int bfs(vector<vector<int> > &adj, int s, int *prev, int *color){
  queue<int> q;
  q.push(s);
  //cout<<"abcd2"<<endl;
  //cout<<q.front()<<endl;
  //black 1 ;  white 0
  while(!q.empty()){
    int first_node_of_queue = q.front();
    //cout<<first_node_of_queue<<endl;
    vector<int> neighbours = adj[first_node_of_queue];
    for(auto i = neighbours.begin(); i != neighbours.end(); i++){
      if(prev[*i] == -1){
        //cout<<"abcd3"<<endl;
        q.push(*i);
        prev[*i] = first_node_of_queue;
        color[*i] = (color[first_node_of_queue]+1)%2;
      }
      else{
        if(color[*i] == color[first_node_of_queue]) return 0;
      }
    }
    q.pop();
  }
  return 1;
  //cout<<"end"<<endl;
}

int bipartite(vector<vector<int> > &adj) {
  //write your code here
  int n = adj.size();
  int prev[n];
  int color[n];
  for(int i=0; i<n; i++){
    prev[i] = -1;
    color[i] = -1;
  }
  color[0] = 1;//black
  //cout<<"abcd1"<<endl;
  int res = bfs(adj,0,prev,color);
  //cout<<"after prev"<<endl;
  return res;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
