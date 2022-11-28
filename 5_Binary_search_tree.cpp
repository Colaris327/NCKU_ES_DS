#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
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
        Node *root = nullptr;
        // the fuction is used for calling Insert_node
        void Insert(int key);
        void Inorder(Node *current);
        void Delete(int key);
        void Preorder(Node *current);
        void Postorder(Node *current);
        void Levelorder(Node *current);
};

int main()
{
    BSTree T;
    // srand(time(nullptr));
    // for (int i = 0; i < 10; i++)
    //     T.Insert(rand() % 100);
    // cout << "Inorder: ";
    // T.Inorder(T.root);
    // cout << endl;
    // cout << "Preoder: ";
    // T.Preorder(T.root);
    // cout << endl;
    // cout << "Postorder: ";
    // T.Postorder(T.root);
    // cout << endl;
    // cout << "Levelorder: ";
    // T.Levelorder(T.root);
    // cout << endl;

    ifstream f;
    f.open("test1.txt");
    int temp, key;
    while (f >> temp)
    {
        switch (temp)
        {
            case 1:
                f >> key;
                T.Insert(key);
                break;
            case 2:
                f >> key;
                cout << "Delete " << key << endl;
                T.Delete(key);
                break;
            case 3:
                cout << "\nInorder: ";
                T.Inorder(T.root);
                cout << endl;
                break;
            case 4:
                cout << "\nPreorder: ";
                T.Preorder(T.root);
                cout << endl;
                break;
            case 5:
                cout << "\nPostorder: ";
                T.Postorder(T.root);
                cout << endl;
                break;
            case 6:
                cout << "\nLevelorder: ";
                T.Levelorder(T.root);
                cout << endl;
                break;
        }
    }
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

void BSTree::Preorder(Node *current)
{
    if (current == nullptr)
        return;
    cout << current->value << ' ';
    Preorder(current->left_child);
    Preorder(current->right_child);
}

void BSTree::Postorder(Node *current)
{
    if (current == nullptr)
        return;
    Postorder(current->left_child);
    Postorder(current->right_child);
    cout << current->value << ' ';
}

void BSTree::Levelorder(Node *current)
{
    if (current == nullptr)
    {
        cout << "Empty tree\n";
        return;
    }
    queue<Node *> q;
    q.push(current);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->value << ' ';
        if (temp->left_child)
            q.push(temp->left_child);
        if (temp->right_child)
            q.push(temp->right_child);
    }
}