// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

class Solution{
    private:
    bool isSafe(int x, int y, int n,vector<vector<int>> vis, vector<vector<int>> &m ) {
        if ((x >= 0 && x < n) &&(y>= 0 && y < n) && vis[x][y] == 0 && m[x][y] == 1) {
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>> &m, int n,vector<string> &ans, string &path, int x, int y, vector<vector<int>> &vis) {
        if(x == n-1 && y == n-1) {
            ans.push_back(path);
            return;
        }
        vis[x][y] = 1;
        // Down
        int newx = x+1;
        int newy = y;
        if (isSafe(newx,newy, n, vis, m)) {
            path.push_back('D');
            solve(m,n, ans, path, newx,newy,vis);
            path.pop_back();
        }
        // LEft
        newx = x;
        newy = y-1;
        if (isSafe(newx,newy, n, vis, m)) {
            path.push_back('L');
            solve(m,n, ans, path, newx,newy,vis);
            path.pop_back();
        }
        // Right
        newx = x;
        newy = y+1;
        if (isSafe(newx,newy, n, vis, m)) {
            path.push_back('R');
            solve(m,n, ans, path, newx,newy,vis);
            path.pop_back();
        }
        // Up
        newx = x-1;
        newy = y;
        if (isSafe(newx,newy, n, vis, m)) {
            path.push_back('U');
            solve(m,n, ans, path, newx,newy,vis);
            path.pop_back();
        }
        
        vis[x][y] = 0;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        
        if(m[0][0] == 0) return ans;
            
            
        string path = "";
        int x=0,y=0;
        vector<vector<int>> vis=m;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                vis[i][j] = 0;
        
        
        solve(m,n, ans, path, x,y,vis);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

    