#include <iostream>
#define MAXSIZE 100

using namespace std;

class Queue {
private:
    int queue[MAXSIZE];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value);
    void dequeue();
    void display();
    int size();
    bool isEmpty();
    void clear();
};

void Queue::enqueue(int value) {
    if (rear == MAXSIZE - 1) {
        cout << "QUEUE IS FULL" << endl;
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        cout << value << " HAS BEEN ADDED TO THE QUEUE" << endl;
    }
}

void Queue::dequeue() {
    if (front == -1 || front > rear) {
        cout << "QUEUE IS EMPTY" << endl;
    } else {
        cout << "ELEMENT " << queue[front] << " DELETED FROM THE QUEUE" << endl;
        front++;
        if (front > rear) {
            front = rear = -1;  // Reset the queue if it becomes empty
        }
    }
}

void Queue::display() {
    if (front == -1) {
        cout << "QUEUE IS EMPTY" << endl;
    } else {
        cout << "THE QUEUE ELEMENTS ARE: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int Queue::size() {
    if (front == -1) {
        return 0;
    } else {
        return rear - front + 1;
    }
}

bool Queue::isEmpty() {
    return (front == -1);
}

void Queue::clear() {
    front = -1;
    rear = -1;
    cout << "QUEUE HAS BEEN CLEARED" << endl;
}

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\nQUEUE OPERATIONS";
        cout << "\n1. ENQUEUE";
        cout << "\n2. DEQUEUE";
        cout << "\n3. DISPLAY";
        cout << "\n4. SIZE OF QUEUE";
        cout << "\n5. CHECK IF QUEUE IS EMPTY";
        cout << "\n6. CLEAR QUEUE";
        cout << "\n7. EXIT";
        cout << "\nENTER YOUR CHOICE: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "ENTER THE VALUE TO ENQUEUE: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "QUEUE SIZE: " << q.size() << endl;
                break;
            case 5:
                if (q.isEmpty()) {
                    cout << "QUEUE IS EMPTY" << endl;
                } else {
                    cout << "QUEUE IS NOT EMPTY" << endl;
                }
                break;
            case 6:
                q.clear();
                break;
            case 7:
                cout << "EXITING..." << endl;
                break;
            default:
                cout << "PLEASE ENTER A VALID CHOICE (1-7)" << endl;
        }
    } while (choice != 7);

    return 0;
}
