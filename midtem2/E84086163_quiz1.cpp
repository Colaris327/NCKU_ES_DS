#include <iostream>
#include <fstream>
using namespace std;

class Node
{
    public:
        int value;
        Node *left_child = nullptr;
        Node *right_child = nullptr;
        Node(int key) {this->value = key;}
};

class BSTree
{
    private:
        // for recursive insert node
        Node *Insert_node(Node *current, int key);
        Node *Delete_node(Node *current, int key);
    public:
        int sum = 0;
        Node *root = nullptr;
        // the fuction is used for calling Insert_node
        void Insert(int key);
        void Inorder(Node *current);
        void Sum(Node *current);
        void Delete(int key);
        void Create_greater(Node *current);
};

int main()
{
    BSTree T;
    ifstream f;
    f.open("P1.txt");
    int temp, key;
    while (f >> temp)
    {
        switch (temp)
        {
            case 1:
                f >> key;
                cout << "The instruction 1. Insert " << key << ". Successfully.\n";
                T.Insert(key);
                break;
            case 2:
                f >> key;
                cout << "The instruction 2. Delete " << key << ". Successfully.\n";
                T.Delete(key);
                break;
            case 4:
                cout << "The instruction 4. Inorder ";
                T.Inorder(T.root);
                cout << endl;
                break;
            case 3:
                T.Create_greater(T.root);
                cout << "The instruction 3. BST to greater sum tree. \n";
                break;
        }
    }
    // cout << T.sum;
    return 0;
}

void BSTree::Insert(int key)
{
    this->root = Insert_node(this->root, key);
}

Node *BSTree::Insert_node(Node *current, int key)
{
    if (current == nullptr)
        return new Node(key);
    if (key > current->value)
        current->right_child = Insert_node(current->right_child, key);
    else
        current->left_child = Insert_node(current->left_child, key);
    return current;
}

void BSTree::Inorder(Node *current)
{
    if (current == nullptr)
        return;
    Inorder(current->left_child);
    cout << current->value << ' ';
    Inorder(current->right_child);
}

void BSTree::Delete(int key)
{
    if (this->root == nullptr)
    {
        cout << "Empty Tree\n";
        return;
    }
    this->root = Delete_node(this->root, key);
}

Node *BSTree::Delete_node(Node *current, int key)
{
    if (current == nullptr)
    {
        cout << "Data:"<< key << " not found\n";
        return current;
    }
    if (current->value > key)
        current->left_child = Delete_node(current->left_child, key);
    else if (current->value < key)
        current->right_child = Delete_node(current->right_child, key);
    else
    {
        // deleted node has no child, just delete it
        if (current->left_child == nullptr && current->right_child == nullptr)
        {
            delete current;
            current = nullptr;
            // cout << "Data has been deleted\n";
        }
        // deleted node only has right child, contact its right child to parent
        else if (current->left_child == nullptr)
        {
            Node *temp = current->right_child;
            delete current;
            current = nullptr;
            return temp;
            // cout << "Data has been deleted\n";
        }
        // deleted node only has left child, contact its left child to parent
        else if (current->right_child == nullptr)
        {
            Node *temp = current->left_child;
            delete current;
            current = nullptr;
            return temp;
            // cout << "Data has been deleted\n";
        }
        // deleted node has both children
        else
        {
            // temp is the deleted node's right child's left most child
            Node *temp = current->right_child;
            while (temp->left_child)
                temp = temp->left_child;
            current->value = temp->value;
            current->right_child = Delete_node(current->right_child, temp->value);
            return current;
        }
    }
    return current;
}

void BSTree::Create_greater(Node *current)
{
    if (current == nullptr)
        return;
    Create_greater(current->right_child);
    int temp = current->value;
    current->value = this->sum;
    this->sum += temp;
    Create_greater(current->left_child);
}