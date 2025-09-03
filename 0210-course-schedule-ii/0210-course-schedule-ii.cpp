class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& visited, stack<int>& st, bool& hasCycle) {
        if (hasCycle) {
            return;
        }

        visited[node] = 1;

        for (int neighbor : graph[node]) {
            if (visited[neighbor] == 1) {
                hasCycle = true;
                return;
            }
            if (visited[neighbor] == 0) {
                dfs(neighbor, graph, visited, st, hasCycle);
                if (hasCycle) {
                    return;
                }
            }
        }
        
        visited[node] = 2;
        st.push(node);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        
        for (const auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
        }

        vector<int> visited(numCourses, 0);
        stack<int> st;
        bool hasCycle = false;

        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0) {
                dfs(i, graph, visited, st, hasCycle);
                if (hasCycle) {
                    return {};
                }
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};