/* QUESTION: You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
 

Example 1:



Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to p
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(root==NULL)
        {
            return NULL;
        }
        vector<vector<Node*>> v;
        queue<Node*> q;
        Node* start = root;
        q.push(start);
        while(!q.empty())
        {
            int size = q.size();
            vector<Node*> t;
            while(size--)
            {
                Node* p = q.front();
                t.push_back(p);
                q.pop();
                if(p->left)
                {
                    q.push(p->left);
                }
                if(p->right)
                {
                    q.push(p->right);
                }
            }
            v.push_back(t);          
            
            
        }
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                if(j<v[i].size()-1)
                    v[i][j]->next = v[i][j+1];
                else
                    v[i][j]->next = NULL;
            }
        }
        return root;
        
    }
};
