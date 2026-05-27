class Solution {
public:
    int solveByRec(vector<int>& arr,map<pair<int, int>,int> &maxi, int left, int right ) {
        if(left == right) return 0;
        int ans = INT_MAX;
        for(int k=left; k<right; k++){
            ans = min(ans, 
                        maxi[{left, k}]* maxi[{k+1, right}]
                        +
                        solveByRec(arr, maxi, left, k)
                        +
                        solveByRec(arr, maxi, k+1, right)
                    );
        }
        return ans;
    }

int solveByMemo(vector<int>& arr,map<pair<int, int>,int> &maxi, int left, int right, vector<vector<int>> &dp ) {
        if(left == right) return 0;
        int ans = INT_MAX;
        if(dp[left][right] != -1) return dp[left][right];
        for(int k=left; k<right; k++){
            ans = min(ans, 
                        maxi[{left, k}]* maxi[{k+1, right}]
                        + solveByMemo(arr, maxi, left, k, dp)
                        + solveByMemo(arr, maxi, k+1, right, dp)
                    );
        }
        return dp[left][right]=ans;
    }

    int solveByTab(vector<int> &arr, map<pair<int, int>,int> &maxi) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        for(int left = n-1; left>=0; left--) {
            for(int right = left+1; right< n; right++) {
                int ans = INT_MAX;
                for(int k=left; k<right; k++){
                    ans = min(ans, 
                                maxi[{left, k}]* maxi[{k+1, right}]
                                + dp[left][k]
                                + dp[k+1][right]
                            );
                }
                dp[left][right]=ans;
            }
        }
        return dp[0][n-1];
    }

    int solveOptimal(vector<int> &arr) {
        int ans = 0;
        stack<int> st;
        st.push(INT_MAX);
        for(auto &a: arr) {
            while(st.top() <=a) {
                int mid = st.top();
                st.pop();
                ans += mid* min(st.top(), a);
            }
            st.push(a);
        }
        while(st.size() > 2) {
            int x = st.top();
            st.pop();
            ans += x* st.top();
        }
        return ans;
    }

    int mctFromLeafValues(vector<int>& arr) {
        // map<pair<int, int>,int> maxi;
        // int n= arr.size();
        // for(int i=0; i<n; i++) {
        //     maxi[{i,i}]= arr[i];
        //     for(int j=i+1; j<n; j++){
        //         maxi[{i,j}] = max(arr[j], maxi[{i, j-1}]);
        //     }
        // }
        // return solveByRec(arr, maxi, 0, n-1);
        // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

        // return solveByMemo(arr, maxi, 0, n-1, dp);
        // return solveByTab(arr, maxi);
        return solveOptimal(arr);
    }
};