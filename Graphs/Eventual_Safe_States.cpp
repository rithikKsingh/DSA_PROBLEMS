/*
A terminal node is a node without any outgoing edges(i.e outdegree = 0). Now a node is considered to be a safe node if all 
possible paths starting from it lead to a terminal node.



*/

/*
BFS Approach : using topological sort(kahns algo). If cycle exists in any nodes, they arent safe nodes because not every path leads to the terminal nodes.

What do you do?
You reverse the graph and apply kahns algo. That is you check the nodes which you can reach from terminal nodes. Also those nodes arent in a cycle.
then you add the nodes in the answer array which have 0 indegree. And those are dafe nodes.

tc: O(E+V) + O(NlogN) ->  V = no. of nodes and E = no. of edges.O(N*logN) for sorting the safeNodes array, 
where N is the number of safe nodes. 

Sc: O(N) -> adj list = O(E+V), O(N) ->indegree O(N) -> queue
*/
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>adjRev[graph.size()];
        vector<int>indegree(graph.size());
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adjRev[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }

        queue<int>q;
        for(int i=0;i<graph.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto a:adjRev[node]){
                indegree[a]--;
                if(indegree[a]==0){
                    q.push(a);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

/*
DFS approach
*/

class Solution {
public:
void dfs(vector<vector<int>>& graph,vector<int>&vis,int node){
    vis[node]=2;
    for(auto it:graph[node]){
        if(!vis[it]){
            dfs(graph,vis,it);
        }
        if(vis[it]==2) return;
    }
    vis[node]=1;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int nodes=graph.size();
        vector<int>vis(nodes,0),ans;
        for(int i=0;i<nodes;i++){
            if(!vis[i]){
                dfs(graph,vis,i);
            }
        }

        for(int i=0;i<nodes;i++){
            if(vis[i]==1) ans.push_back(i);
        }
        return ans;
    }
};
