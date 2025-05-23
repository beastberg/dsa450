#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node {
public:
    Node* left;
    int data;
    Node* right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class Tree {
private:
    Node* root;
    void destroyTree(Node* p);

public:
    Tree();
    ~Tree();

    void CreateTree();

    void Preorder(Node* p);
    void PreOrder() { Preorder(root); }

    void Inorder(Node* p);
    void Inorder() { Inorder(root); }

    void Postorder(Node* p);
    void Postorder() { Postorder(root); }

    void Levelorder(Node* p);
    void Levelorder() { Levelorder(root); }

    int Height(Node* p);
    int Height() { return Height(root); }

    void iterativePreorder(Node* p);
    void iterativePreorder() { iterativePreorder(root); }

    void iterativeInorder(Node* p);
    void iterativeInorder() { iterativeInorder(root); }

    void iterativePostorder(Node* p);
    void iterativePostorder() { iterativePostorder(root); }
};

Tree::Tree() {
    root = nullptr;
}

Tree::~Tree() {
    destroyTree(root);
}

void Tree::destroyTree(Node* p) {
    if (p) {
        destroyTree(p->left);
        destroyTree(p->right);
        delete p;
    }
}

void Tree::CreateTree() {
    Node* p;
    Node* t;
    int x;
    queue<Node*> q;

    cout << "Enter root data: ";
    cin >> x;
    root = new Node(x);
    q.push(root);

    while (!q.empty()) {
        p = q.front();
        q.pop();

        cout << "Enter left child of " << p->data << " (-1 for NULL): ";
        cin >> x;
        if (x != -1) {
            t = new Node(x);
            p->left = t;
            q.push(t);
        }

        cout << "Enter right child of " << p->data << " (-1 for NULL): ";
        cin >> x;
        if (x != -1) {
            t = new Node(x);
            p->right = t;
            q.push(t);
        }
    }
}

void Tree::Preorder(Node* p) {
    if (p) {
        cout << p->data << ", ";
        Preorder(p->left);
        Preorder(p->right);
    }
}

void Tree::Inorder(Node* p) {
    if (p) {
        Inorder(p->left);
        cout << p->data << ", ";
        Inorder(p->right);
    }
}

void Tree::Postorder(Node* p) {
    if (p) {
        Postorder(p->left);
        Postorder(p->right);
        cout << p->data << ", ";
    }
}

void Tree::iterativePreorder(Node* p) {
    if (p == nullptr) return;
    stack<Node*> stk;
    while (p || !stk.empty()) {
        if (p) {
            cout << p->data << ", ";
            stk.push(p);
            p = p->left;
        } else {
            p = stk.top();
            stk.pop();
            p = p->right;
        }
    }
    cout << endl;
}

void Tree::iterativeInorder(Node* p) {
    stack<Node*> stk;
    while (p || !stk.empty()) {
        if (p) {
            stk.push(p);
            p = p->left;
        } else {
            p = stk.top();
            stk.pop();
            cout << p->data << ", ";
            p = p->right;
        }
    }
    cout << endl;
}

void Tree::iterativePostorder(Node* p) {
    if (!p) return;
    stack<pair<Node*, bool>> stk;
    stk.push({p, false});

    while (!stk.empty()) {
        auto [node, visited] = stk.top();
        stk.pop();

        if (!node) continue;

        if (visited) {
            cout << node->data << ", ";
        } else {
            stk.push({node, true});
            stk.push({node->right, false});
            stk.push({node->left, false});
        }
    }
    cout << endl;
}

void Tree::Levelorder(Node* p) {
    if (!p) return;
    queue<Node*> q;
    q.push(p);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << ", ";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    cout << endl;
}

int Tree::Height(Node* p) {
    if (!p) return -1;
    int leftHeight = Height(p->left);
    int rightHeight = Height(p->right);
    return 1 + max(leftHeight, rightHeight);
}

int main() {
    Tree t;
    int choice;

    while (true) {
        cout << "\n--- Binary Tree Operations Menu ---\n";
        cout << "1. Create Tree\n";
        cout << "2. Recursive Preorder\n";
        cout << "3. Recursive Inorder\n";
        cout << "4. Recursive Postorder\n";
        cout << "5. Iterative Preorder\n";
        cout << "6. Iterative Inorder\n";
        cout << "7. Iterative Postorder\n";
        cout << "8. Level Order\n";
        cout << "9. Height of Tree\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            t.CreateTree();
            break;
        case 2:
            cout << "Preorder: ";
            t.PreOrder();
            cout << endl;
            break;
        case 3:
            cout << "Inorder: ";
            t.Inorder();
            cout << endl;
            break;
        case 4:
            cout << "Postorder: ";
            t.Postorder();
            cout << endl;
            break;
        case 5:
            cout << "Iterative Preorder: ";
            t.iterativePreorder();
            break;
        case 6:
            cout << "Iterative Inorder: ";
            t.iterativeInorder();
            break;
        case 7:
            cout << "Iterative Postorder: ";
            t.iterativePostorder();
            break;
        case 8:
            cout << "Level Order: ";
            t.Levelorder();
            break;
        case 9:
            cout << "Height of Tree: " << t.Height() << endl;
            break;
        case 0:
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

