#include <iostream>

class Stack
{
    char *arr;
    int capacity;
    int top;
    void resize()
    {
        int newCapacity = capacity * 2;
        char *newArr = new char[newCapacity];
        for (int i = 0; i <= top; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }
public:
    Stack(int size = 2)
    {
        arr = new char[size];
        capacity = size;
        top = -1;
    }

    void push(char value)
    {
        if (isFull())
        {
            resize();
        }
        arr[++top] = value;
    }

    char pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack Underflow" << std::endl;
            return '\0';
        }
        return arr[top--];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == capacity - 1;
    }

    void display()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty" << std::endl;
            return;
        }
        std::cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    void peek()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty" << std::endl;
        }
        else
        {
            std::cout << "Top element: " << arr[top] << std::endl;
        }
    }

    ~Stack()
    {
        delete[] arr;
    }
};

int main()
{
    Stack s;
    std::string str;

    std::cout << "Enter a string: ";
    std::getline(std::cin, str); 
    std::cout << "Original String : " << str << std::endl;
    for(int i=0;i<str.length();i++){
        s.push(str[i]);
    }
    std::string strreversed;
    for(int i=0;i<str.length();i++){
        strreversed.push_back(s.pop());
    }
    std::cout<<"Reversed string:"<<strreversed<<std::endl;
    return 0;
}
