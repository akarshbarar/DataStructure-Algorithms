class Solution {
public:
    int check(vector<int> box, vector<int> newBox) {
        if(newBox[0] <= box[0] && newBox[1] <= box[1] && newBox[2] <= box[2])
            return true;
        else 
            return false;
    }
    int solve(int n, vector<vector<int>> &arr){
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        for(int currIndex = n-1; currIndex >= 0; currIndex--) {
    
            for(int prevIndex = currIndex-1; prevIndex >= -1; prevIndex--) {
    
                int include = 0;
    
                if(prevIndex == -1 || check(arr[currIndex],arr[prevIndex])) {
                    include = arr[currIndex][2] + nextRow[currIndex+1];
                }
    
                int exclude = nextRow[prevIndex+1];
    
                currRow[prevIndex+1] = max(include, exclude);
            }
            nextRow = currRow;
        }
    
        return nextRow[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        // Step 1 sort each cubboid 
        for(auto &cube: cuboids){
            sort(cube.begin(), cube.end());
        }
        // Step 2 sort each cuboid based on width
        sort(cuboids.begin(), cuboids.end());

        // USE LIS logic
        return solve(cuboids.size(), cuboids);
    }
};