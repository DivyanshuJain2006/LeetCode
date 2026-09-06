/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    vector<Node*>nodeRegister;
    void dfs(Node* actual,Node* clone){
        for(auto neighbor : actual->neighbors){
            if(nodeRegister[neighbor->val]==NULL){
                Node* temp = new Node(neighbor->val);
                nodeRegister[temp->val] = temp;
                clone->neighbors.push_back(temp);
                dfs(neighbor,temp);
            }
            else clone->neighbors.push_back(nodeRegister[neighbor->val]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        nodeRegister.resize(110,NULL);

        Node* temp = new Node(node->val);
        nodeRegister[temp->val] = temp;
        dfs(node,temp);
        return temp;
    }
};