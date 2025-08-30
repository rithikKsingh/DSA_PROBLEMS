// link : https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// It's an application of Kahn's Algo. That is you use BFS top sort here. You just check elements with indgrees!=0 at the end when you are out of the queue.

// tc: O(E+V) sc: O(V)

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
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
            for(auto a:adj[node]){
                indegree[a]--;
                if(indegree[a]==0){
                    q.push(a);
                }
            }
        }
        
        for(auto a:indegree){
            if(a!=0) return true;
        }
   
        
        return false;
    }
};
