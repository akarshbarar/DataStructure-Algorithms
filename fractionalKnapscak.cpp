class Solution {
  public:
    static bool cmp(pair<double, pair<int, int>> a, pair<double, pair<int, int>> b){
        return a.first > b.first;
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<double, pair<int, int>>> v;
        int n = val.size();
        for(int i=0; i<n; i++){
            double perUnitValue =(1.0)*val[i]/wt[i];
            pair<double,pair<int, int>> p = make_pair(perUnitValue, make_pair(val[i], wt[i]));
            v.push_back(p);
        }
        
        sort(v.begin(), v.end(), cmp);
        
        double totalValue = 0;
        
        for(int i=0; i<n; i++){
            if(v[i].second.second > capacity){
                totalValue += capacity*v[i].first;
                capacity = 0;
            }
            else {
                totalValue += v[i].second.first;
                capacity -= v[i].second.second;
            }
        }
        return totalValue;
        
    }
};
