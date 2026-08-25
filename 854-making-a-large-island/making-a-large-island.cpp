class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:

    bool isValid(int row, int col, int n) {
        return row >= 0 && row < n &&
               col >= 0 && col < n;
    }

    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        DisjointSet ds(n * n);

        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, -1, 0, 1};

        // Step 1: Create components of existing 1s
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {

                if (grid[row][col] == 0)
                    continue;

                int nodeNo = row * n + col;

                for (int i = 0; i < 4; i++) {

                    int adjRow = row + dRow[i];
                    int adjCol = col + dCol[i];

                    if (isValid(adjRow, adjCol, n) &&
                        grid[adjRow][adjCol] == 1) {

                        int adjNodeNo = adjRow * n + adjCol;

                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        int mx = 0;

        // Step 2: Try converting every 0 to 1
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {

                if (grid[row][col] == 1)
                    continue;

                unordered_set<int> compo;

                for (int i = 0; i < 4; i++) {

                    int adjRow = row + dRow[i];
                    int adjCol = col + dCol[i];

                    if (isValid(adjRow, adjCol, n) &&
                        grid[adjRow][adjCol] == 1) {

                        int adjNodeNo = adjRow * n + adjCol;

                        int root = ds.findUPar(adjNodeNo);

                        compo.insert(root);
                    }
                }

                // Current 0 becomes 1
                int totalSize = 1;

                for (auto root : compo) {
                    totalSize += ds.size[root];
                }

                mx = max(mx, totalSize);
            }
        }

        // Step 3: Handle all-1 grid
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {

                if (grid[row][col] == 1) {

                    int nodeNo = row * n + col;

                    mx = max(mx,
                             ds.size[ds.findUPar(nodeNo)]);
                }
            }
        }

        return mx;
    }
};
