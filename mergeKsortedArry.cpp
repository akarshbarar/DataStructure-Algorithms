#include <bits/stdc++.h> 
class Node{
    public:
    int data;
    int i;
    int j;
    Node(int data, int row, int col){
        this->data = data;
        i=row;
        j=col;
    }
};

class cmp{
  public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<Node*, vector<Node*>, cmp>  pq;

    for(int i=0; i<k; i++){
        Node* temp = new Node(kArrays[i][0], i, 0);
        pq.push(temp);
    }

vector<int> ans;
    while(pq.size()>0){
        Node* tmp = pq.top();
        ans.push_back(tmp->data);
        pq.pop();

        int i = tmp->i;
        int j = tmp->j;

        if(j+1 < kArrays[i].size()){
            Node* nextNode = new Node(kArrays[i][j+1], i, j+1);
            pq.push(nextNode);
        }

    }
    return ans;

}
