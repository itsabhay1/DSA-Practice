class DisjointSet {
    public:
    vector<int>parent, size;

    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    
    int ultiParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = ultiParent(parent[node]);
    }

    void unionBySize(int x, int y){
        int ulpX = ultiParent(x);
        int ulpY = ultiParent(y);
        if(ulpX == ulpY) return;
        if(size[ulpX] < size[ulpY]){
            parent[ulpX] = ulpY;
            size[ulpY] += size[ulpX];
        }
        else{
            parent[ulpY] = ulpX;
            size[ulpX] += size[ulpY];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);

        int countEdge = 0, compo = 0;

        for(auto &it: connections){
            int u = it[0];
            int v = it[1];
            if(ds.ultiParent(u) == ds.ultiParent(v)) countEdge++;
            else ds.unionBySize(u,v);
        }

        for(int i=0; i<n; i++){
            if(ds.ultiParent(i) == i) compo++;
        }

        if(countEdge >= compo-1) return compo-1;
        return -1;
    }
};