// this is stack implementation of linked list
/* author: vaibhav patel
   created on: 15-06-2021 */

#include <iostream>
using namespace std;

template <typename T>
class Stack
{
    struct Node
    {
        T elem;
        Node *next;
    };
    Node *Head = NULL;

public:
    int size = 0;

    /* function which returns the size of stack */
    int getsize()
    {
        return size;
    }

    /* push operation on stack */
    void push(T e)
    {
        if (size == 0)
        {
            Head = new Node;
            Head->elem = e;
            Head->next = NULL;
        }
        else
        {
            Node *temp = new Node;
            temp->elem = e;
            temp->next = Head;
            Head = temp;
        }
        size++;
    }

    /* pop operation on stack */
    void pop()
    {
        if (size == 0)
        {
            cout << "List is already empty" << '\n';
        }
        else
        {
            Node* temp = Head;
            Head = temp -> next;
            delete temp;
            size--;
        }
    }

    /* top element of stack */
    T top()
    {
        return Head->elem;
    }

    /* function which returns true if the stack is empty */
    bool isEmpty()
    {
        if(size==0) return 1;
        return 0;
    }

    /* function which returns the number of occurence of a specific element in stack */
    int count(T e)
    {
        Node* temp = Head;
        int count(0);
        while(temp != NULL)
        {
            if(temp -> elem == e)
                count++;
            temp = temp -> next;
        }
        return count;
    }

    /* function which prints the elements of stack with seperator */
    void print(char sep=' ')
    {
        Node* temp = Head;
        while(temp->next != NULL)
        {
            cout<<temp->elem<<sep;
            temp = temp->next;
        }
        cout<<temp->elem<<'\n';
    }
};

int main()
{
   // driver code for the program
    Stack <int> stc;

    for(int i=0; i<10; i++)
    {
        stc.push(i);
    }
    cout<<"after push: "; stc.print();

    stc.pop(); stc.pop();
    cout<<"after pop: "; stc.print();

    cout<<"top element of stack is: "<<stc.top()<<'\n';

    cout<<"size of the stack is: "<<stc.getsize()<<'\n';

    stc.push(1);
    cout<<"Number of occurence of 1 is: "<<stc.count(1)<<'\n';

    cout<<"is stack empty?: "<<stc.isEmpty()<<'\n';
}
