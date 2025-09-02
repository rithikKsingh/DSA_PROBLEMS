//link :https://www.geeksforgeeks.org/problems/alien-dictionary/1

// its better to read the description of the question because it gets difficult to understand as some restrictions come. 

/* do see these important test cases: 
1.[abc ab]   : here all characters of first and second string are same. However second string is smaller than first. Therefore it should have came before "abc". 
               So not possible to get an answer here.
2.[wrt wrtkj]  : here similar like above case. but here its possible. also since there is no difference in characters, so all are independent. 
3.["z", "z"] : both are same, so there should be atleast one node. as z can exist independently 
4.["abc"] :  single string, each character independent of each other.
  */

/* use of kahn's algo*/

/* my own written code was messier but it worked. the below code is a cleaner copy of my code. (credits :chat gpt) */
class Solution {
public:
    string findOrder(vector<string> &words) {
        vector<int> indegree(26, -1);      // indegree for each character
        vector<vector<int>> adj(26);       // adjacency list
        string ans = "";

        // Build graph
        for (int i = 0; i < words.size() - 1; i++) {
            int j = 0, k = 0;
            
            // Mark all matched characters as present
            while (j < words[i].size() && k < words[i+1].size() && words[i][j] == words[i+1][k]) {
                if (indegree[words[i][j] - 'a'] == -1) indegree[words[i][j] - 'a'] = 0;
                j++, k++;
            }

            // Case: first differing characters
            if (j < words[i].size() && k < words[i+1].size()) {
                int u = words[i][j] - 'a';
                int v = words[i+1][k] - 'a';
                if (indegree[u] == -1) indegree[u] = 0;
                if (indegree[v] == -1) indegree[v] = 0;
                adj[u].push_back(v);
                indegree[v]++;
            }
            else if (j < words[i].size() && k == words[i+1].size()) {
                // Invalid case: prefix issue
                return "";
            }

            // Mark remaining characters in both words
            for (; j < words[i].size(); j++) {
                if (indegree[words[i][j] - 'a'] == -1) indegree[words[i][j] - 'a'] = 0;
            }
            for (; k < words[i+1].size(); k++) {
                if (indegree[words[i+1][k] - 'a'] == -1) indegree[words[i+1][k] - 'a'] = 0;
            }
        }

        // Handle first word separately (ensure its chars are marked)
        for (char c : words[0]) {
            if (indegree[c - 'a'] == -1) indegree[c - 'a'] = 0;
        }

        // Topological Sort (Kahn’s Algorithm)
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front(); q.pop();
            ans += char('a' + node);
            for (int nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) q.push(nei);
            }
        }

        // Check for cycle (if any node still has indegree > 0)
        for (int i = 0; i < 26; i++) {
            if (indegree[i] > 0) return "";
        }

        return ans;
    }
};
