class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses+3];
    
    for(auto v: prerequisites){
        adj[v[1]].push_back(v[0]);
    }
    
    vector<int> deg(numCourses,0);
    
    for(int i=0; i<numCourses; i++){
        for(auto v: adj[i]){
            deg[v]++;
        }
    }
    
    queue<int> q;
        
    for(int i=0; i<numCourses; i++){
        if(deg[i] == 0)q.push(i);
    }
    
    while(q.size()){
        int node = q.front();
        q.pop();
        
        for(auto v: adj[node]){
            deg[v]--;
            if(deg[v] == 0)q.push(v);
        }
    }
    
    for(int i=0; i<numCourses; i++){
        if(deg[i])return false;
    }
    
    return true;
        
    }
};
