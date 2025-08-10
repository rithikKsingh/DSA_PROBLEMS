// link : https://leetcode.com/problems/number-of-provinces/

//METHOD_1 : DFS , by creating adjacency list
//TC: O(N2) + O(N+2E) = O(N2) . 2E because undirected. 1--2 ->[1]=2,[2]=1. Also in worst case where each component is connected to each node, E becomes N2.
//SC : O(n)+o(n2)+o(n). One due to vis array, one adjacency list(can turn to O(n2) in worst case. and one due to recursive call stack.
class Solution {
public:
    void dfs(vector<int>adj[],int node,vector<int>&vis){
        vis[node]=1;
        for(auto a:adj[node]){
            if(vis[a]==0){
                dfs(adj,a,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int>vis(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                dfs(adj,i,vis);
            }
        }
        return cnt;

    }
};

//method 2: avoiding adj list. 
class Solution {
public:
    void dfs(int node,vector<vector<int>>& isConnected,vector<int>&vis){
        vis[node]=1;
        for(int i=0;i<isConnected.size();i++){
            if(!vis[i]&&isConnected[node][i]){
                dfs(i,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int cnt=0;
        vector<int>vis(n);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,isConnected,vis);
            }
        }
        return cnt;
    }
};


//method 3: using bfs
//tc:O(n2), sc:O(n2)
class Solution {
public:
    void bfs(int node, vector<vector<int>>& isConnected, vector<bool>& visit) {
        queue<int> q;
        q.push(node);
        visit[node] = true;

        while (!q.empty()) {
            node = q.front();
            q.pop();
            visit[node] = true;
            for (int i = 0; i < isConnected.size(); i++) {
                if (isConnected[node][i] && !visit[i]) {
                    q.push(i);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int n = 0;
        vector<bool> visit(n);

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                numberOfComponents++;
                bfs(i, isConnected, visit);
            }
        }

        return n;
    }
};
