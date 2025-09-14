//link : https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1


/*
Dijextra is not applicable to negative weight cycle because then distacen keep decreasing . 

you can implement using 1. Queue 2. Priority Queue(min) 3. Set

Set is faster because you can erase already existing paths. Priority  Queue wont do this.

Queue ve PQ. In PQ, you go through the minimal paths first and ultimately rach all minimals. 
In queue, you go on ll the paths and unnecessary iterations
TC : O(Elog(V)) SC: O(E+V) 

E = Number of edges, V = Number of Nodes.
  */
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<pair<int,int>> adj[V];  
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); 
        }
        
        set<pair<int,int>>s;
        vector<int>dist(V,1e9);
        s.insert({0,src});
        dist[src]=0;
        while(!s.empty()){
            auto it=*(s.begin());
            int len=it.first;
            int node=it.second;
            s.erase(it);
            
            for(auto a:adj[node]){
                int adjNode=a.first;
                int wt=a.second;
                
                if(len+wt<dist[adjNode]){
                    if(dist[adjNode]!=1e9){
                        s.erase({dist[adjNode],adjNode});
                    }
                    
                    dist[adjNode]=len+wt;
                    s.insert({dist[adjNode],adjNode});
                }
            }
        }
        
        return dist;
    }

};




/*

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int source)
    {
          priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  vector<int> dist(V, INT_MAX);

  pq.push({0, source});
  dist[source] = 0;

  while (!pq.empty()) {
    int node = pq.top().second;
    int dis = pq.top().first;
    pq.pop();
    for (auto it : adj[node]) {
      int adjNode = it[0];
      int weight = it[1];

      if (dis + weight < dist[adjNode]) {
        dist[adjNode] = dis + weight;
        pq.push({dist[adjNode], adjNode});
      }
    }
  }

  return dist;
    }
};

*/
