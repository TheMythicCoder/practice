#include <iostream>
#include <string>
#include <random>
#include <vector>

using namespace std;

struct TreeNode {
    string value;
    vector<TreeNode*> children;
    
    TreeNode(string val) : value(val) {}
};

string generateRandomString(int length) {
    const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, chars.size() - 1);
    
    string result;
    for (int i = 0; i < length; ++i) {
        result += chars[dis(gen)];
    }
    return result;
}

TreeNode* buildRandomTree(int depth, int maxChildren) {
    if (depth == 0) return nullptr;
    
    TreeNode* root = new TreeNode(generateRandomString(5));
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, maxChildren);
    
    int numChildren = dis(gen);
    for (int i = 0; i < numChildren; ++i) {
        TreeNode* child = buildRandomTree(depth - 1, maxChildren);
        if (child) {
            root->children.push_back(child);
        }
    }
    
    return root;
}

void printTree(TreeNode* node, int indent = 0) {
    if (!node) return;
    
    for (int i = 0; i < indent; ++i) cout << "  ";
    cout << node->value << "\n";
    
    for (TreeNode* child : node->children) {
        printTree(child, indent + 1);
    }
}

int main() {
    TreeNode* tree = buildRandomTree(3, 3);
    cout << "Random Tree Structure:\n";
    printTree(tree);
    
    return 0;
}
