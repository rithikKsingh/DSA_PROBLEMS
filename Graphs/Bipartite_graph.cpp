// link: https://leetcode.com/problems/is-graph-bipartite/description/
// tc: O(n+m) ~ O(n+2e) => you visit each nodes exactly once and if its not colored, only then you traverse through the edges. 
// SC: O(N)+O(N) = O(N) (col array and queue 


// Bipartite definition : If we are able to colour a graph with two colours such that no adjacent nodes have the same colour, it is called a bipartite graph.
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        // vector<int>adj[n];
        // for(int i=0;i<n;i++){
        //    for(int j=0;j<graph[i].size();j++){
        //         adj[i].push_back(graph[i][j]);
        //         adj[graph[i][j]].push_back(i);
        //    }
        // }

        vector<int>col(n,2);
        for(int i=0;i<n;i++){
            if(col[i]==2){
                col[i]=1;
                queue<int>q;
                q.push(i);
                while(!q.empty()){
                    int node=q.front();
                    int color=col[node];
                    q.pop();
                    for(auto a:graph[node]){
                        if(col[a]==2){
                            col[a]=!col[node];
                            q.push(a);
                        }else if(col[a]==col[node]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
