#include <iostream>
#include <vector>
#include <algorithm>
#define INT_MAX 99999

using namespace std;

int find_min_element(bool in_queue[], int final_wt[], int n){
	int min = INT_MAX;
	int index = -1;
	for(int i=0; i<n; i++){
		if(in_queue[i] && final_wt[i] < min){
			min = final_wt[i];
			index = i;
		}
	}
	return index;
}
void dijkstras(vector<vector<int> > &adj, vector<vector<int> > &cost, int s,int final_wt[], int prev[]){
	//vector<int> neighbours = adj[0];
  //vector<int> cst = cost[0];
  
	vector<int> q;
	int n = adj.size();
	bool in_queue[n] = {false};
	q.push_back(s);
	final_wt[s] = 0;
	in_queue[s] = true;
	bool relaxed[n] = {false};
	while(!q.empty()){
		int node = find_min_element(in_queue,final_wt,n);
		int weight = final_wt[node];
		vector<int> neighbours = adj[node];
		vector<int> cst = cost[node];
		for(int i=0; i<neighbours.size(); i++){
			if(!relaxed[neighbours[i]]){
				if(final_wt[node] + cst[i] < final_wt[neighbours[i]]){
					final_wt[neighbours[i]] = final_wt[node] + cst[i];
					prev[neighbours[i]] = node;
				}
				if(!in_queue[neighbours[i]]){
					q.push_back(neighbours[i]);
					in_queue[neighbours[i]] = true;
				}
			}
		}
		q.erase(find(q.begin(),q.end(),node));
		in_queue[node] = false;
		relaxed[node] = true;
	}
}

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code here
	int n = adj.size();
	int final_wt[n];
	int prev[n];
	for(int i=0; i<n; i++){
		final_wt[i] = INT_MAX;
		prev[i] = -1;
	}
	dijkstras(adj,cost,s,final_wt,prev);
	if(final_wt[t] == INT_MAX) return -1;
	else return final_wt[t];
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
  
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
