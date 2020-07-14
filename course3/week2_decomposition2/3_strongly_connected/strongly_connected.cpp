#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using std::vector;
using std::pair;

void find_postorder(vector<vector<int> > &rev_adj,int i, vector<int> &postorder, int visited1[], int n){
  visited1[i] = 1;
  vector<int> neighbours = rev_adj[i];
  for(auto u = neighbours.begin(); u != neighbours.end(); u++){
    if(!visited1[*u]){
      find_postorder(rev_adj,*u,postorder,visited1,n);
    }
  }
  postorder.push_back(i);
  //cout<<i+1<<" ";
}

vector<int> postorder(vector<vector<int> > &rev_adj, int n){
  vector<int> postorder;
  int visited1[n] = {0};
  for(int i=0; i<n; i++){
    if(!visited1[i]){
      find_postorder(rev_adj,i,postorder,visited1,n);
    }
  }
  return postorder;
}

void dfs(vector<vector<int> > &adj, int i, int visited[],vector<int> &postorder/*,int *size*/){
  int n_neighbours = adj[i].size();
  int count = 0;
  visited[i] = 1;
  vector<int> neighbours = adj[i];
  for(auto u = neighbours.begin(); u != neighbours.end(); u++){
    if(!visited[*u]){
      dfs(adj,*u,visited,postorder/*,size*/);
    }
    count++;
  }
  //cout<<count<<":"<<n_neighbours<<endl;
  if(count == n_neighbours){
    //(*size)--;
    postorder.erase(find(postorder.begin(),postorder.end(),i));
  }
  //cout<<i+1<<":"<<count<<endl;
}

int number_of_strongly_connected_components(vector<vector<int> > &adj, vector<vector<int> > &rev_adj, int n) {
  int result = 0;
  //write your code here
  int visited[n] = {0};
  vector<int> porder = postorder(rev_adj,n);
  //cout<<endl;
  //int size = n;
  while(porder.size() != 0){
    //cout<<porder.size()<<endl;
    int vertice = porder.back();
    dfs(adj,vertice,visited,porder/*,&size*/);
    result++;
  }
  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > rev_adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    rev_adj[y - 1].push_back(x - 1);

  }
  std::cout << number_of_strongly_connected_components(adj,rev_adj,n);
}
