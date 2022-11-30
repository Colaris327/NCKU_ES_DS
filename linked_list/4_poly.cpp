#include <iostream>
using namespace std;

class Node
{
    public:
        int coef;
        int exp;
        Node *next;
        Node(int a, int b): coef(a), exp(b), next(nullptr) {}
};

class Poly
{
    public:
        Node *first = nullptr;
        void Insert(int coef, int exp);
        void Print_result();
};

void Poly::Insert(int coef, int exp)
{
    if (this->first == nullptr)
    {
        this->first = new Node(coef, exp);
        return;
    }
    Node *current = this->first;
    while (current->next != nullptr)
        current = current->next;
    current->next = new Node(coef, exp);
}

void Poly::Print_result()
{
    Node *current = this->first;
    while (current)
    {
        cout << current->coef << ' ' << current->exp << endl;
        current = current->next;
    }
}

Poly Combine(Poly p1, Poly p2)
{
    Node *p1_pointer = p1.first;
    Node *p2_pointer = p2.first;
    Poly p3;
    while (p1_pointer != nullptr && p2_pointer != nullptr)
    {
        if (p1_pointer->exp == p2_pointer->exp)
        {
            p3.Insert(p1_pointer->coef + p2_pointer->coef, p1_pointer->exp);
            p1_pointer = p1_pointer->next;
            p2_pointer = p2_pointer->next;
        }
        else if (p1_pointer->exp > p2_pointer->exp)
        {
            p3.Insert(p1_pointer->coef, p1_pointer->exp);
            p1_pointer = p1_pointer->next;
        }
        else
        {
            p3.Insert(p2_pointer->coef, p2_pointer->exp);
            p2_pointer = p2_pointer->next;
        }
    }
    if (p1_pointer)
    {
        while (p1_pointer)
        {
            p3.Insert(p1_pointer->coef, p1_pointer->exp);
            p1_pointer = p1_pointer->next;
        }
    }
    else
    {
        while (p2_pointer)
        {
            p3.Insert(p2_pointer->coef, p2_pointer->exp);
            p2_pointer = p2_pointer->next;
        }
    }
    return p3;
}

int main()
{
    Poly p1, p2, p3;
    int p1_size, p2_size;
    cout << "p1 size: ";
    cin >> p1_size;
    int coef, exp;
    for (int i = 0; i < p1_size; i++)
    {
        cin >> coef >> exp;
        p1.Insert(coef, exp);
    }
    cout << "p2 size: ";
    cin >> p2_size;
    for (int i = 0; i < p2_size; i++)
    {
        cin >> coef >> exp;
        p2.Insert(coef, exp);
    }
    cout << endl << endl;
    p3 = Combine(p1, p2);
    p3.Print_result();
    return 0;
}