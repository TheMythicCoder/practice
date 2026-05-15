#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int value;
    string name;
};

struct Node {
    int index;
    int currentWeight;
    int currentValue;
    bool take;
    shared_ptr<Node> left;
    shared_ptr<Node> right;
    Node(int idx, int w, int v, bool t)
        : index(idx), currentWeight(w), currentValue(v), take(t) {}
};

int bestValue = 0;

void printTree(const shared_ptr<Node>& node, const string& prefix = "") {
    if (!node) return;
    cout << prefix
         << (node->index >= 0 ? "item[" + to_string(node->index) + "] " : "root ")
         << (node->take ? "[take] " : "[skip] ")
         << "w=" << node->currentWeight << " v=" << node->currentValue << "\n";
    printTree(node->left, prefix + "  ");
    printTree(node->right, prefix + "  ");
}

void buildKnapsackTree(const vector<Item>& items,
                       int capacity,
                       int index,
                       int currentWeight,
                       int currentValue,
                       const shared_ptr<Node>& parent,
                       bool take) {
    if (currentWeight > capacity) return;

    int nodeIndex = (index > 0 ? index - 1 : -1);
    auto node = make_shared<Node>(nodeIndex, currentWeight, currentValue, take);
    if (parent) {
        if (take) {
            parent->right = node;
        } else {
            parent->left = node;
        }
    }

    bestValue = max(bestValue, currentValue);

    if (index == items.size()) return;

    buildKnapsackTree(items, capacity, index + 1, currentWeight, currentValue, node, false);
    buildKnapsackTree(items,
                      capacity,
                      index + 1,
                      currentWeight + items[index].weight,
                      currentValue + items[index].value,
                      node,
                      true);
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    int n = 6;
    int capacity = 15;
    vector<Item> items;

    for (int i = 0; i < n; ++i) {
        int w = 1 + rand() % 10;
        int v = 1 + rand() % 20;
        items.push_back({w, v, "item" + to_string(i + 1)});
    }

    cout << "Capacity: " << capacity << "\n";
    for (int i = 0; i < n; ++i) {
        cout << items[i].name << ": w=" << items[i].weight << " v=" << items[i].value << "\n";
    }

    auto root = make_shared<Node>(-1, 0, 0, false);
    buildKnapsackTree(items, capacity, 0, 0, 0, root, false);

    cout << "\nBest value found: " << bestValue << "\n";
    cout << "Decision tree:\n";
    printTree(root);

    return 0;
}
