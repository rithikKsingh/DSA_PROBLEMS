// link : https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
// tc:O(v+2e) : because undirected
// sc:O(V) for dist array + O(V) for ans


/*
Approach:
We want the shortest path in an unweighted graph (where every edge has equal weight = 1).
For this kind of problem, the best approach is Breadth First Search (BFS).
Why BFS?
BFS explores nodes level by level (first neighbors, then neighbors of neighbors, etc.).
That means the first time we reach a node, we’ve already found the shortest path to it.
Steps in the algorithm:
Initialize all distances as infinity (INT_MAX) → means “not reached yet.”
Distance of the source node = 0.
Use a queue to run BFS starting from the source.
Whenever we find a neighbor, check if we can update its distance with dist[current] + 1.
Keep repeating until no more nodes are left in the queue.
Finalization:
After BFS finishes, convert all unreachable nodes (INT_MAX) to -1.
Return the distance array as the result.
*/
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n=adj.size();
        vector<int>dist(n,INT_MAX);
        vector<int>ans(n,-1);
        
        queue<int>q;
        q.push(src);
        dist[src]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto a:adj[node]){
               if(dist[a]>1+dist[node]){
                   dist[a]=1+dist[node];
                   q.push(a);
               }
            }
        }
        for(int i=0;i<n;i++){
            if(dist[i]!=INT_MAX){
                ans[i]=dist[i];
            }
        }
        return ans;
        
    }
};
