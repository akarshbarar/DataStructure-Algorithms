#include <bits/stdc++.h>
using namespace std;

class cmp {
public:

    bool operator()(Node* a, Node* b) {

        return a->data > b->data;
    }
};

Node* mergeKLists(vector<Node*> &arr) {

    priority_queue<
        Node*,
        vector<Node*>,
        cmp
    > pq;

    int k = arr.size();

    if(k == 0)
        return NULL;

    // Push first node of each list
    for(int i = 0; i < k; i++) {

        if(arr[i] != NULL) {

            pq.push(arr[i]);
        }
    }

    Node* head = NULL;
    Node* tail = NULL;

    while(!pq.empty()) {

        Node* tmp = pq.top();
        pq.pop();

        // Push next node
        if(tmp->next != NULL) {

            pq.push(tmp->next);
        }

        // First node
        if(head == NULL) {

            head = tmp;
            tail = tmp;
        }

        else {

            tail->next = tmp;
            tail = tmp;
        }
    }

    if(tail != NULL)
        tail->next = NULL;

    return head;
}