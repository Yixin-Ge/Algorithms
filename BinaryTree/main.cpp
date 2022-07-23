#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template<typename T>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(T init_val) : val(init_val), left(nullptr), right(nullptr) {}
};

template<typename T>
TreeNode<T>* buildTree(vector<int> vec, int start, int end) {
    if(start > end) return nullptr;
    int middle = (start + end) / 2;

    TreeNode<T>* cur = new TreeNode<T>(vec[middle]);
    cur->left = buildTree<T>(vec, start, middle - 1);
    cur->right = buildTree<T>(vec, middle + 1, end);
    return cur;
}

template<typename T>
void printTree(TreeNode<T>* root) {
    if(root == nullptr) return;

    queue<TreeNode<T>*> queue;
    queue.push(root);

    cout << root->val << endl;

    while(!queue.empty()) {
        int size = queue.size();
        for(int i = 0; i < size; ++i) {
            TreeNode<T>* node= queue.front();
            queue.pop();
            if(node->left != nullptr) {
                queue.push(node->left);
                cout << node->left->val << " ";
            }
            else cout << "null ";
            if(node->right != nullptr) {
                queue.push(node->right);
                cout << node->right->val << " ";
            }
            else cout << "null ";
        }
        cout << endl;
    }

}

int main() {
    // Example: build a binary search tree from a vector
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    TreeNode<int>* root = buildTree<int>(vec, 0, vec.size() - 1);

    printTree(root);
    return 0;
}
