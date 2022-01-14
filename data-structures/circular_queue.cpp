#include<iostream>
#include<stdexcept>

class CircularQueue {
protected:
    const static int MAX = 10;
    double queue[MAX] = {};
    int front = -1, rear = -1;

public:
    bool overflow(){
        return (this->rear + 1) % this->MAX == this->front ? true : false;
    }

    bool underflow() {
        return this->front == -1 ? true : false;
    }

    bool enqueue(double x) {
        if (overflow()) throw std::overflow_error("Queue Overflow");

        if (this->front == -1) this->front = this->rear = 0;
        else this->rear = (this->rear + 1) % this->MAX;

        this->queue[this->rear] = x;
        return true;
    }

    double dequeue() {
        if (underflow()) throw std::underflow_error("Queue Underflow");

        double data = this->queue[this->front];

        if (this->front == this->rear) this->front = this->rear = -1;
        else this->front = (this->front + 1) % this->MAX;

        return data;
    }

    double display_front() {
        if (underflow()) throw std:: underflow_error("Queue Underflow");
        return this->queue[front];
    }

    void display() {
        if (underflow()) throw std:: underflow_error("Queue Underflow");
        for (int i = front; i <= rear; i++) std::cout << this->queue[i] << " ";
        std::cout << std::endl;
    }

    void menu() {
        char choice;
        do {
            std::cout << "\n=== MENU ===\n0. Quit\n1. Insert\n2. Delete\n3. Front\n4. Display\nEnter choice: ";
            std::cin >> choice;

            switch(choice) {
                case '0':
                    break;

                case '1':
                    int val;
                    try {
                        std::cout << "Enter value to insert: ";
                        std::cin >> val;
                        this->enqueue(val);
                    } catch (std::overflow_error& e) {
                        std::cout << e.what() << std::endl;
                    }
                    break;

                case '2':
                    try {
                        std::cout << "Value Removed: " << this->dequeue() << std::endl;
                    } catch (std::underflow_error& e) {
                        std::cout << e.what() << std::endl;
                    }
                    break;

                case '3':
                    try {
                        std::cout << "Front: " << this->display_front() << std::endl;
                    } catch (std::underflow_error& e) {
                        std::cout << e.what() << std::endl;
                    }
                    break;

                case '4':
                    try {
                        this->display();
                    } catch (std::underflow_error& e) {
                        std::cout << e.what() << std::endl;
                    }
                    break;

                default:
                    std::cout << "Invalid choice" << std::endl;
                    break;
            }

        } while(choice != '0');

    }

};

int main() {
    CircularQueue q = CircularQueue();

    q.menu();

    return 0;
}
