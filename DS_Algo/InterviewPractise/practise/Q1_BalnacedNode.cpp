// MS OA
// A balanced node is a node which has count of all subtrees child as equal.

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    std::vector<Node*> subtrees;
    
    Node(int _val) {
      val = _val;
    }
};

int countNodes(Node* node) {
    if (!node) {
        return 0; // Base case: Empty tree has height 0
    }

    int count = 0;
    for (Node* child : node->subtrees) {
        count = 1 + countNodes(child);
    }
    return count;
}

bool isBalanced(Node* node) {
    if (!node) {
        return true; // Empty tree is considered balanced
    }
    if (node->subtrees.size() == 0 || node->subtrees.size()==1) { 
        return true;
    }
    int count = countNodes(node->subtrees[0]);
    for (size_t i = 1; i < node->subtrees.size(); ++i) {
        if (countNodes(node->subtrees[i]) != count) {
            return false; // Heights must be equal for all subtrees
        }
    }
    return true; // Balanced if all subtrees have equal heights
}

int countBalancedNodes(Node* root) {
    if (!root) {
        return 0; // Base case: Empty tree has no balanced nodes
    }

    int count = 0;
    if (isBalanced(root)) {
        count++; // Current node is balanced, so count it
    }

    for (Node* child : root->subtrees) {
        count += countBalancedNodes(child); // Recursively count in subtrees
    }

    return count;
}

Node* createTree() {
    Node* root = new Node(8);
    root->subtrees.push_back(new Node(3));
    root->subtrees.push_back(new Node(4));
    
    root->subtrees[0]->subtrees.push_back(new Node(1));
    root->subtrees[0]->subtrees.push_back(new Node(1));
    
    root->subtrees[1]->subtrees.push_back(new Node(1));
    root->subtrees[1]->subtrees.push_back(new Node(2));
    
    root->subtrees[1]->subtrees[1]->subtrees.push_back(new Node(1));
    
    return root;
}

void printInorder(Node* root) {
  if(root) {
    cout<< root->val <<" ";
    for(Node* x : root->subtrees)
      printInorder(x);
  }
}

int main() {
    // ... (Create your tree structure here)
    Node* tree = nullptr;
    tree = createTree();
    printInorder(tree);
    cout<<"\n";
    
    int balancedNodeCount = countBalancedNodes(tree);
    std::cout << "Number of balanced nodes: " << balancedNodeCount << std::endl;

    return 0;
}
