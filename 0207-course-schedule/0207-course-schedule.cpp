class Solution {
public:
    // fucniton to detect cycle
    bool detectCycle(int node,vector<vector<int>>&Graph,vector<int>&Vis,vector<int>&Path){
        Vis[node]++;
        Path[node]++;

        for(int neighbour : Graph[node])
        {
            if(Path[neighbour])
            {
                return true;
            }
            if(!Vis[neighbour])
            {
                if(detectCycle(neighbour,Graph,Vis,Path)) return true;
            }
        }

        Path[node]--;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>Graph(n);
        for(auto& pre : prerequisites)
        {
            Graph[pre[1]].push_back(pre[0]);
        }

        // Vis vector to capture which courses has been picked already
        // Path vector to capture the path arrived from a node
        vector<int>Vis(n,0);
        vector<int>path(n,0);
        for(int i=0;i<n;i++)
        {
            if(!Vis[i]){
                if(detectCycle(i,Graph,Vis,path)) return false;
            }
        }
        return true;
    }
};