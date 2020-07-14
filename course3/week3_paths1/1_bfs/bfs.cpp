#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using std::vector;
using std::queue;

void bfs(vector<vector<int> > &adj, int s, int *prev, int *dist){
	queue<int> q;
	q.push(s);
	//cout<<"abcd2"<<endl;
	//cout<<q.front()<<endl;
	while(!q.empty()){
		int first_node_of_queue = q.front();
		//cout<<first_node_of_queue<<endl;
		vector<int> neighbours = adj[first_node_of_queue];
		for(auto i = neighbours.begin(); i != neighbours.end(); i++){
			if(prev[*i] == -1){
				//cout<<"abcd3"<<endl;
				q.push(*i);
				prev[*i] = first_node_of_queue;
				dist[*i] = dist[first_node_of_queue]+1;
			}
		}
		q.pop();
	}
	//cout<<"end"<<endl;
}

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
	int n = adj.size();
	int prev[n];
	int dist[n] = {0};
	for(int i=0; i<n; i++){
		prev[i] = -1;
	}
	//cout<<"abcd1"<<endl;
	bfs(adj,s,prev,dist);
	//cout<<"after prev"<<endl;
	int d = 0;
	int q = t;
	while(q != s && prev[q] != -1){
		//cout<<q+1<<":"<<s+1<<" "<<prev[q]<<endl;
		d++;
		q = prev[q];
	}
	if(q == s) return d;
	else return -1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
