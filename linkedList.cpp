/* author: vaibhav patel
   created on: 14-06-2021 */

#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
    struct Node
    {
        T elem;
        Node *next;
    };
    Node *Head = NULL;
    Node *Tail = NULL;

public:
    int size = 0;

    /* function which returns the size of linked list */
    int getsize()
    {
        return size;
    }

    /* function which adds element at front end */
    void pushfront(T e)
    {
        if (size == 0)
        {
            Head = new Node;
            Head->elem = e;
            Head->next = NULL;
            Tail = Head;
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

    /* function which adds element at rear end */
    void pushback(T a)
    {
        if(size==0)
            pushfront(a);
        else
        {
            Node *temp = new Node;
            temp->elem = a;
            temp->next = NULL;
            Tail->next = temp;
            Tail = temp;
            size++;
        }
    }

    /* function which inserts element at position p, default at beginning */
    void insert(T a, int p = 0)
    {
        if (p == 0)
            pushfront(a);
        else if (p < 0 or p >= size)
        {
            cout<<"error, please enter a correct index"<<'\n';
        }
        else
        {
            Node *temp = Head;
            for (int i = 0; i < p - 1; i++)
            {
                temp = temp->next;
            }
            Node *temp2 = new Node;
            temp2->elem = a;
            temp2->next = temp->next;
            temp->next = temp2;
            size++;
        }
    }

    /* function which removes element at position p */
    void remove(int p = 0)
    {
        if (size == 0)
        {
            cout << "List is already empty" << endl;
        }
        else
        {
            if (p == 0)
            {   
                Head = Head -> next;
                size--;
            }
            else if (p < 0 or p >= size)
            {
                cout << "Error, enter the correct index for removal" << '\n';
            }
            else
            {
                Node *temp = Head;
                for (int i = 0; i < p - 1; i++)
                {
                    temp = temp->next;
                }
                if(temp->next==Tail)
                {
                    Tail = temp;
                }
                Node *temp2 = temp -> next;
                temp -> next = temp2 -> next;
                delete temp2;
                size--;
            }
        }
    }

    /* function which updates element at position p */
    void update(T e, int p)
    {
        if (p >= size or p < 0)
            cout << "Please enter the correct index for updating" << '\n';
        else
        {
            Node *temp = Head;
            for (int i = 0; i < p; i++)
            {
                temp = temp->next;
            }
            temp->elem = e;
        }
    }

    /* function which returns true if the linked list is empty */
    bool isempty()
    {
        if(size==0) return 1;
        return 0;
    }

    /* function which returns the number of occurence of a specific element */
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

    /* function which prints the elements of list with seperator */
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
    LinkedList <int> arr;
    arr.pushback(1);
    arr.pushback(2);
    arr.pushfront(3);
    arr.insert(5);
    arr.insert(10,1);
    arr.insert(7,4);
    arr.insert(3);
    cout<<arr.isempty()<<'\n';
    cout<<arr.size<<'\n';
    cout<<arr.count(3)<<'\n';
    arr.print();
    arr.update(20,1);
    arr.pushfront(21);
    arr.print();
    arr.remove(4);
    arr.print('-');
}