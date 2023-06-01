/* Represent a given graph using adjacency matrix/list to perform DFS and using adjacency 
list to perform BFS. Use the map of the area around the college as the graph. Identify 
the prominent land marks as nodes and perform DFS and BFS on that. 
*/

#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int>>& g, int start, vector<int>>& vis)
{
	vis[start] = 1;
	for(auto child: g[start])
{
	if(!vis[child])
	{
		dfs(g,child,vis);
		
	}
    }
}
 int main()
 {
 	int v; //vertex 
 	cin>>v;
 	vector<vector<int>> g;
 	
 	for(int i = 0; i< v; i++)
 	{
 		vector<int> temp;
 		g.push_back(temp);
	 }
	 
	 int E;
	 cin>>E;
	 for(int i=0;i<E;i++)
	 {
	 	inta,b;
	 	cin>>a>>b;
	 	g[a].push_back(b);
	 	g[b].push_back(a);
	 	
	 }
 	vector<int> vis(v,0);
 	dfs(g,0,vis);
 	
 }
