// ref: http://alrightchiu.github.io/SecondRound/linked-list-xin-zeng-zi-liao-shan-chu-zi-liao-fan-zhuan.html
#include <iostream>
using namespace std;

class LinkedList;

class Node
{
    private:
        int data;
        Node *next;
    public:
        Node(): data(0), next(nullptr) {};
        Node(int value): data(value), next(nullptr) {};
        int Node_data() {return this->data;}
    friend class LinkedList;
};

class LinkedList
{
    private:
        Node *first;
    public:
        LinkedList(): first(nullptr) {};
        void PrintList();
        // return nullptr for not found
        Node *Search_node(int value); 
        void Push_front(int value);
        void Push_back(int value);
        void Push_after(int prev, int value);
        void Delete_Node(int value);
        void Reverse();
};

int main()
{
    LinkedList list;
    list.Push_back(1);
    list.Push_back(2);
    list.Push_back(3);
    list.Push_front(10);
    list.Push_after(2, 7);
    list.Delete_Node(2);
    list.PrintList();
    Node *temp = list.Search_node(7);
    cout << endl << temp->Node_data() << endl;
    list.Reverse();
    list.PrintList();
    return 0;
}

void LinkedList::PrintList()
{
    if (first == nullptr)
    {
        cout << "List is empty\n";
        return;
    }
    Node *current = first;
    while (current != nullptr)
    {
        cout << current->data << ' ';
        current = current->next;
    }
}

Node *LinkedList::Search_node(int value)
{
    Node *current = first;
    while (current)
    {
        if (current->data == value)
            return current;
        current = current->next;
    }
    cout << "The node doesn't exist.\n";
    return nullptr;
}

void LinkedList::Push_front(int value)
{
    Node *newdata = new Node(value);
    // 不用管first是否為nullptr
    newdata->next = first;
    first = newdata;
}

void LinkedList::Push_back(int value)
{
    Node *newdata = new Node(value);
    if (first == nullptr)
    {
        first = newdata;
        return;
    }
    Node *current = first;
    while (current->next != nullptr)
        current = current->next;
    current->next = newdata;
}

void LinkedList::Push_after(int prev, int value)
{
    Node *current = Search_node(prev);
    if (current == nullptr)
        return;
    Node *newdata = new Node(value);
    newdata->next = current->next;
    current->next = newdata;
}

void LinkedList::Delete_Node(int value)
{
    Node *prev, *current = first;
    // Search_node()無法找到要刪除的current之前一個Node，所以不使用
    while (current != nullptr && current->data != value)
    {
        prev = current;
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "No such node exists.\n";
        return;
    }
    else if (current == first)
    {
        first = current->next;
        delete current;
        current = nullptr;
    }
    else
    {
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
}

void LinkedList::Reverse()
{
    // list為空或只有一個Node就不用做
    if (first == nullptr || first-> next == nullptr)
        return;
    // 三個pointer分別指向前一個、要反轉link的Node、下一個
    Node *prev = nullptr, *current = first, *right = first->next;
    while (right != nullptr)
    {
        current->next = prev;
        prev = current;
        current = right;
        right = right->next;
    }
    current->next = prev;
    first = current;
}