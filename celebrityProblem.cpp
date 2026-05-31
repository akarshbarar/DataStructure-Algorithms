class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        stack<int> s;
        int n = mat.size();
        for(int i=0;i<n; i++){
            s.push(i);
        }
        
        while(s.size() >1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if(mat[a][b] == 1){
                s.push(b);
            }else {
                s.push(a);
            }
        }
        
        int x = s.top();
        // ROW
        int zeroCount = 0;
        int zeroFlag=false;
        for(int i=0; i< n; i++){
            if(mat[x][i] == 0)
                zeroCount++;
        }
        if(zeroCount == n-1){
            zeroFlag=true;
        }
        // Col
        int oneCount = 0;
        int oneFlag=false;
        for(int i=0; i< n; i++){
            if(mat[i][x] == 1)
                oneCount++;
        }
        if(oneCount == n){
            oneFlag=true;
        }
        if(zeroFlag==true && oneFlag==true)
            return x;
        else
            return -1;
    }
};