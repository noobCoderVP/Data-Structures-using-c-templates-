// this is a dynamic array implementation
/* author: vaibhav patel
   created on: 12-06-2022 */

#include <iostream>
using namespace std;

template <typename T>
class Array
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

    /* function to get the capacity of the array */
    int capacity()
    {
        return MAX_SIZE;
    }

    /* function to get the element at index p */
    T get(int p)
    {
        if (p < size && p > -1) // valid range of positions
            return arr[p];
        cout << "Error, out of bound access, garbage value returned" << '\n';
        T a;
        return a; // garbage value when out of index access
    }

    /* find function to return the first occurence index, starting at position p */
    int find(T e, int p = 0)
    {
        for (int i = p; i < size; i++)
        {
            if (arr[i] == e)
                return i;
        }
        return -1; // in all invalid cases of p it returns -1
    }

    /* function that checks if the array is empty */
    bool isEmpty()
    {
        if (size == 0)
            return true;
        return false;
    }

    /* function that inserts a element at required position, default at end (if p ==-1)*/
    void insert(T e, int p = -1)
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
        if (p == -1)
        {
            arr[size] = e;
            size++;
        }
        else if (p > size or p < 0)
        {
            cout << "Error, please insert a correct index for insertion" << '\n';
        }
        else
        {
            for (int i = size - 1; i >= p; i--)
            {
                arr[i + 1] = arr[i];
            }
            arr[p] = e;
            size++;
        }
    }

    /* function to remove an element, default from end */
    void remove(int p = -1)
    {
        if (p == -1)
            p = size - 1;
        if (p >= size and p < 0)
            cout << "Error, please enter a correct index for removal" << '\n';
        else
        {
            for (int i = p; i < size; i++)
            {
                arr[i] = arr[i + 1];
            }
            size--;
        }
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
    }

    /* function to count number of occurence of an element, starting from position p */
    int count(T e, int p = 0)
    {
        if (p >= size and p < 0)
            return -1;
        else
        {
            int count = 0;
            for (int i = p; i < size; i++)
            {
                if (arr[i] == e)
                    count++;
            }
            return count;
        }
    }

    /* function to update the value at a given position, default at end */
    void update(T e, int p = -1)
    {
        if (p == -1)
            p = size - 1;
        if (p < 0 or p >= size)
            cout << "Error, please enter a correct index for update" << '\n';
        else
            arr[p] = e;
    }

    /* function to print whole array seperated by the seperator(char), default space */
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
    Array<int> arr;
    cout << arr.isEmpty() << '\n';
    for (int i = 0; i < 20; i++)
    {
        arr.insert(i);
    }
    arr.insert(2, 12);
    cout << arr.get(12) << '\n';
    arr.print('-');
    cout << arr.capacity() << '\n';
    arr.remove(4);
    arr.print();
    cout << arr.capacity() << '\n'; // capacity is reduced
    cout << arr.count(2) << '\n';

    Array <char> arr2;
    cout<<arr.isEmpty()<<'\n';
    for(int i=0; i<20; i++)
    {
        arr2.insert('a');
    }
    arr2.insert('b', 2);
    arr2.update('c', 1);
    arr2.print(',');
}
