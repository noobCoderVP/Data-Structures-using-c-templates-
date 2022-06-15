// this is a array implementation of stack
/* author: vaibhav patel
   created on: 15-06-2022 */

#include <iostream>
using namespace std;

template <typename T>
class Stack
{
    int MAX_SIZE = 10;  // keep track of maximum array size
    int size = 0;       // keep track of number of elements
    T *arr = new T[10]; // pointer to array of 10 elements

public:
    /* function to get the size of the array */
    int getsize()
    {
        return size;
    }

    /* function to get top element of stack */
    T top()
    {
        if(size==0)
        {
            cout<<"stack is already empty."<<'\n';
            T a; return a; // garbage value
        }
        return arr[size-1]; // garbage value when out of index access
    }

    /* function to check if an element is present */
    bool isPresent(T e)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == e)
                return true;
        }
        return false; // in all invalid cases of p it returns -1
    }

    /* function that checks if the array is empty */
    bool isEmpty()
    {
        if (size == 0)
            return true;
        return false;
    }

    /* function that inserts a element at required position, default at end (if p ==-1)*/
    void push(T e)
    {
        if (size == MAX_SIZE)
        {
            T *temp = new T[size * 2];
            for (int i = 0; i < size; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            MAX_SIZE = 2 * size;
        }
        arr[size] = e;
        size++;
    }

    /* function to remove an element, default from end */
    void pop()
    {
        if (MAX_SIZE == 2 * size)
        {
            T *temp = new T[size];
            for (int i = 0; i < size; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            MAX_SIZE = size;
        }
        size--;
    }

    /* function to count number of occurence of an element */
    int count(T e)
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == e)
                count++;
        }
        return count;
    }

    /* function to print whole stack seperated by the seperator(char), default space */
    void print(char sep = ' ')
    {
        for (int i = 0; i < size - 1; i++)
            cout << arr[i] << sep;
        cout << arr[size - 1] << '\n';
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
