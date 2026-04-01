class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,int>> st;
        vector<vector<pair<int,int>>> adj(n);
        for(auto f: flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        st.push({0,src});
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        int cnt=0;
        while(!st.empty()){
             if(cnt==k) break;
             cnt++;
            int size=st.size();
          for(int i=0;i<size;i++) { 
            auto it=st.front();
            int node=it.second;
           // cout<<node<<endl;
            int  wt=it.first;
            st.pop();
            for(auto d:adj[node]){
                if(dist[d.first]>wt+d.second){
                //    cout<<d.first<<endl;
                //    cout<<wt;
                //     cout<<d.second;
                    dist[d.first]=wt+d.second;
                    st.push({dist[d.first],d.first});
                 cout<<d.first<<dist[d.first]<<endl;
                }
            }
            }
        }
        while(!st.empty()){
            auto it=st.front();
            int node=it.second;
           //cout<<node<<endl;
            int  wt=it.first;
            st.pop();
            for(auto d:adj[node]){
                if(dist[d.first]>wt+d.second){
                    // cout<<wt;
                    // cout<<d.second;
                    dist[d.first]=wt+d.second;
                cout<<d.first<<dist[d.first]<<endl;
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};