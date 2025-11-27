#include <iostream>

class Stack
{
    int *arr;
    int capacity;
    int top;
    void resize()
    {
        int newCapacity = capacity * 2;
        int *newArr = new int[newCapacity];
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
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    void push(int value)
    {
        if (isFull())
        {
            resize();
        }
        arr[++top] = value;
        std::cout << value << " pushed to stack" << std::endl;
    }

    int pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack Underflow" << std::endl;
            return -1;
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
    int choice, value;

    do
    {
        std::cout << "\n1. Push";
        std::cout << "\n2. Pop";
        std::cout << "\n3. Peek";
        std::cout << "\n4. isEmpty";
        std::cout << "\n5. isFull";
        std::cout << "\n6. Display";
        std::cout << "\n7. Exit";
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter value to push: ";
            std::cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            if (s.isEmpty())
                std::cout << "Stack is empty" << std::endl;
            else
                std::cout << "Stack is not empty" << std::endl;
            break;

        case 5:
            if (s.isFull())
                std::cout << "Stack is full" << std::endl;
            else
                std::cout << "Stack is not full" << std::endl;
            break;

        case 6:
            s.display();
            break;

        case 7:
            std::cout << "Exiting program" << std::endl;
            break;

        default:
            std::cout << "Invalid choice" << std::endl;
        }
    } while (choice != 7);

    return 0;
}
