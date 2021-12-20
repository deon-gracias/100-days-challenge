#include<iostream>
#include<stdexcept>

class Stack {
protected:
    const static int MAX = 10;
    double stack[MAX] = {};
    int top = -1;

public:
    bool underflow(){
        return top == -1 ? true : false;
    }

    bool overflow() {
        return top == MAX - 1 ? true : false;
    }

    bool push(double x) {
        if (overflow()) throw std::overflow_error("Stack Overflow.");
        this->stack[++top] = x; return true;
    }

    double pop() {
        if (underflow()) throw std::underflow_error("Stack Underflow.");
        return this->stack[top--];
    }

    double display_top() {
        if (underflow()) throw std::underflow_error("Stack Underflow.");
        return this->stack[top];
    }

    void display() {
        if (underflow()) throw std::underflow_error("Stack Underflow.");
        std::cout << "Stack: ";
        for (int i = 0; i <= this->top; i++) std::cout << this->stack[i] << " ";
        std::cout << std::endl;
    }

    int menu() {

        char choice;

        do {

            std::cout << "\n=== MENU ===\n0. Quit\n1. Push\n2. Pop\n3. Top\n4. Display\nEnter choice: ";
            std::cin >> choice;

            switch(choice) {
                case '0':
                    break;

                case '1':
                    int val;
                    try {
                        std::cout << "Enter value to push: ";
                        std::cin >> val;
                        this->push(val);
                    } catch (std::overflow_error& e) {
                        std::cout << e.what() << std::endl;
                    }
                    break;

                case '2':
                    try {
                        std::cout << "Value popped: " << this->pop() << std::endl;
                    } catch (std::underflow_error& e) {
                        std::cout << e.what() << std::endl;
                    }
                    break;

                case '3':
                    try {
                        std::cout << "Top: " << this->display_top() << std::endl;
                    } catch (std::underflow_error& e) {
                        std::cout << e.what() << std::endl;
                    }
                    break;

                case '4':
                    try {
                        this->display();
                    } catch (std::underflow_error& e) {
                        std::cout << "Stack Underflow" << std::endl;
                    }
                    break;

                default:
                    std::cout << "Invalid choice" << std::endl;
                    break;
            }

        } while(choice != '0');

        return 0;
    }
};

int main() {

    Stack s = Stack();
    s.menu();

    return 0;

}
