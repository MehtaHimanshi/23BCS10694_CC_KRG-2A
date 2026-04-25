class Solution {
public:
    void dfs(int i,unordered_map<int,bool> &visited,
    unordered_map<int,list<int>> &adj){
        visited[i]=true;
        for(int aa:adj[i]){
            if(!visited[aa]){
                dfs(aa,visited,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,list<int>> adj;
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count=0;
        unordered_map<int,bool> visited;
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                dfs(i,visited,adj);
                count++;
            }
        }
        return count;
    }
};