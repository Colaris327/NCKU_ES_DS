#include <iostream>
using namespace std;

class STACK
{
    public:
        int array[5];
        int top = -1;
        int Topitem();
        bool IsFull() {return top == 4;}
        bool IsEmpty() {return top == -1;}
        void Push(int data);
        void Pop();
};

class QUEUE
{
    public:
        int array[5];
        int front = 0, rear = 0;
        bool IsFull() {return (rear - front) % 5 == 4;}
        bool IsEmpty() {return rear == front;}
        void Add(int data);
        void Delete();
        int Front_item();
};

int main()
{
    STACK st;
    st.Push(1);
    st.Push(2);
    st.Push(3);
    st.Push(7);
    st.Push(5);
    st.Push(10); // this stack can only store 5 items
    while (!st.IsEmpty())
    {
        cout << st.Topitem() << ' ';
        st.Pop();
    }
    st.Pop();

    QUEUE qu;
    qu.Add(1);
    qu.Add(2);
    qu.Add(3);
    qu.Add(7);
    qu.Add(5); // this queue can only store 4 items
    while (!qu.IsEmpty())
    {
        cout << qu.Front_item() << ' ';
        qu.Delete();
    }
    qu.Delete();
}

int STACK::Topitem()
{
    if (IsEmpty())
    {
        cout << "\nThe stack is empty\n";
        return INT32_MIN;
    }
    return array[top];
}

void STACK::Push(int data)
{
    if (IsFull())
    {
        cout << "\nThe stack is full, data:" << data << " can't be pushed into stack\n";
        return;
    }
    array[++top] = data;
}

void STACK::Pop()
{
    if (IsEmpty())
    {
        cout << "\nThe stack is empty\n";
        return;
    }
    top--;
}

void QUEUE::Add(int data)
{
    if (IsFull())
    {
        cout << "\nThe queue is full data:" << data << " can't be add into the queue\n";
        return;
    }
    rear = (rear + 1) % 5;
    array[rear] = data;
}

void QUEUE::Delete()
{
    if (IsEmpty())
    {
        cout << "\nThe queue is empty\n";
        return;
    }
    front = (front + 1) % 5;
}

int QUEUE::Front_item()
{
    if (IsEmpty())
    {
        cout << "\nThe queue is empty\n";
        return INT32_MIN;
    }
    return array[(front + 1) % 5];
}