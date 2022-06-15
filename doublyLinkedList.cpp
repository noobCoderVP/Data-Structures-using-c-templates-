/* author: vaibhav patel
   created on: 14-06-2021 */

#include <iostream>
using namespace std;

template <typename T>
class DoublyLinkedList
{
    struct Node
    {
        T elem;
        Node *next;
        Node *prev;
    };
    Node *Head = NULL;
    Node *Tail = NULL;

public:
    int size = 0;

    /* function which returns the size of doubly linked list */
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
            Head->prev = NULL;
            Tail = Head;
        }
        else
        {
            Node *temp = new Node;
            Head->prev = temp;
            temp->elem = e;
            temp->next = Head;
            temp->prev = NULL;
            Head = temp;
        }
        size++;
    }

    /* function which adds element at rear end */
    void pushback(T a)
    {
        if (size == 0)
            pushfront(a);
        else
        {
            Node *temp = new Node;
            temp->elem = a;
            temp->next = NULL;
            temp->prev = Tail;
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
            cout << "error, please enter a correct index" << '\n';
        }
        else
        {
            if (p < size / 2)
            {
                Node *temp = Head;
                for (int i = 0; i < p - 1; i++)
                {
                    temp = temp->next;
                }
                Node *temp2 = new Node;
                temp2->elem = a;
                temp2->next = temp->next;
                temp2->prev = temp;
                temp->next = temp2;
                temp2->next->prev = temp2;
            }
            else
            {
                Node *temp = Tail;
                for (int i = 0; i < (size - p); i++)
                {
                    temp = temp->prev;
                }
                Node *temp2 = new Node;
                temp2->elem = a;
                temp2->next = temp->next;
                temp2->prev = temp;
                temp->next = temp2;
                temp2->next->prev = temp2;
            }
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
                Node *temp = Head;
                temp = temp->next;
                temp->prev = NULL;
                Head = temp;
                delete temp;
                size--;
            }
            else if (p < 0 or p >= size)
            {
                cout << "Error, enter the correct index for removal" << '\n';
            }
            else if(p==size-1)
            {
                Node* temp = Tail;
                temp->prev->next = NULL;
                Tail = temp -> prev;
                delete temp;
                size--;
            }
            else
            {
                if (p < size / 2)
                {
                    Node *temp = Head;
                    for (int i = 0; i < p - 1; i++)
                    {
                        temp = temp->next;
                    }
                    Node *temp2 = temp->next;
                    temp -> next = temp2 -> next;
                    temp -> next -> prev = temp;
                    delete temp2;
                    size--;
                }
                else
                {
                    Node *temp = Tail;
                    for (int i = 0; i < (size - p); i++)
                    {
                        temp = temp->prev;
                    }
                    Node *temp2 = temp->next;
                    temp -> next = temp2 -> next;
                    temp -> next -> prev = temp;
                    delete temp2;
                    size--;
                }
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
            if (p < size / 2)
            {
                Node *temp = Head;
                for (int i = 0; i < p; i++)
                {
                    temp = temp->next;
                }
                temp -> elem = e;
            }
            else
            {
                Node *temp = Tail;
                for (int i = 0; i < (size - p -1); i++)
                {
                    temp = temp->prev;
                }
                temp -> elem = e;
            }
        }
    }

    /* function which returns true if the linked list is empty */
    bool isempty()
    {
        if (size == 0)
            return 1;
        return 0;
    }

    /* function which returns the number of occurence of a specific element */
    int count(T e)
    {
        Node *temp = Head;
        int count(0);
        while (temp != NULL)
        {
            if (temp->elem == e)
                count++;
            temp = temp->next;
        }
        return count;
    }

    /* function which prints the elements of list with seperator */
    void print(char sep = ' ')
    {
        Node *temp = Head;
        while (temp->next != NULL)
        {
            cout << temp->elem << sep;
            temp = temp->next;
        }
        cout << temp->elem << '\n';
    }

    void printRev(char sep = ' ')
    {
        Node *temp = Tail;
        while (temp->prev != NULL)
        {
            cout << temp->elem << sep;
            temp = temp->prev;
        }
        cout << temp->elem << '\n';
    }
};

int main()
{
    DoublyLinkedList <int> list;
    for(int i=0; i<10; i++)
    {
        list.pushback(i); // pushback check
    }
    cout<<"after pushback: "; list.print();

    list.pushfront(11); // pushfront check
    cout<<"after pushfront: "; list.print();

    cout<<"size of doubly linked list is now: "<<list.getsize()<<'\n'; // getsize() check

    list.insert(13,3); // insert starting from Head
    list.insert(15,8); // insert starting from tail
    cout<<"after insert: ";list.print(); // insert check

    list.update(17,10); // update starting from Head
    list.update(19,3); // update starting from tail
    cout<<"after update: "; list.print(); // update check

    cout<<"print in reverse: ";list.printRev(); // print in reverse

    cout<<"is list empty? "<<list.isempty()<<'\n'; // isempty check

    list.pushback(0);
    cout<<"number of occurence of 0: "<<list.count(0)<<'\n'; // count check

    list.remove(4); // remove starting from head
    list.remove(list.getsize()-4); // remove starting from Tail
    cout<<"after remove: ";list.print();

    cout<<"print using different seperator: ";
    list.print('-'); // print using seperators

    // similarly you can create a double linked list of any tyoe
}
