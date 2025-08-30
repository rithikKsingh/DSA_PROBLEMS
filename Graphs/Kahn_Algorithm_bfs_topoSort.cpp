/* 
link : https://www.geeksforgeeks.org/problems/topological-sort/1 

its also a topological sort but using bfs. It's also called :  Kahn's Algorithm

tc: O(E+V) sc: O(v)

approach : 

whats topo sort?
In topological sorting, node u will always appear before node v if there is a directed edge from node u towards node v(u -> v).

5 -> 0 <- 4
v         v
2 -> 3 -> 1

topo sort :  5 4 0 2 3 1 (there can be multiple answers)

BFS approach:

calculate indegree of each node -> push the nodes with 0 indegree into a queue -> traverse through the queue -> pop the front element-> push it into the answer array
-> traverse through the adjacent nodes -> decrease the indegree by 1-> if indegree becomes 0, push into the queue. repeat.

*/


class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int>ans;
        vector<int>adj[V];
        vector<int>indegree(V);
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto a:adj[node]){
                indegree[a]--;
                if(indegree[a]==0){
                    q.push(a);
                }
            }
        }     
        return ans;
    }
};
