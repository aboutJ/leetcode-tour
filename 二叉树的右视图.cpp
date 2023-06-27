#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 层次遍历
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) {
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);

        while(que.size() != 0) {
            int queSize = que.size();
            for(int i = 0;i < queSize;i++) {
                TreeNode* node = que.front();
                if(node->left) {
                    que.push(node->left);
                }
                if(node->right) {
                    que.push(node->right);
                }
                if(i == queSize-1) {
                    res.push_back(node->val);
                }
                que.pop();
            }
        }
        return res;
    }
};

int main() {

}