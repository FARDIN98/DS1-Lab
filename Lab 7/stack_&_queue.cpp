// Implement a singly linked list and use it to implement stack & queue. Write the code in C++
// Implement stack and queue using array
#include <iostream>
#include <stdexcept>

// Node structure for the singly linked list
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the end of the list
void insert(Node*& head, int val) {
    if (!head) {
        head = createNode(val);
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = createNode(val);
}

// Function to remove the first occurrence of a value from the list
void remove(Node*& head, int val) {
    if (!head)
        return;

    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next) {
        if (temp->next->data == val) {
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
            return;
        }
        temp = temp->next;
    }
}

// Function to display the list
void display(Node* head) {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Function to get the front element of the list for stack
int frontStack(Node* head) {
    if (head)
        return head->data;
    else
        throw std::runtime_error("Stack is empty.");
}

// Function to get the front element of the list for queue
int frontQueue(Node* head) {
    if (head)
        return head->data;
    else
        throw std::runtime_error("Queue is empty.");
}

// Function to check if the list is empty
bool isEmpty(Node* head) {
    return head == nullptr;
}

// Stack operations
void push(Node*& head, int val) {
    insert(head, val);
}

void pop(Node*& head) {
    if (!isEmpty(head))
        remove(head, frontStack(head));
    else
        throw std::runtime_error("Stack is empty.");
}

int top(Node* head) {
    return frontStack(head);
}

bool isStackEmpty(Node* head) {
    return isEmpty(head);
}

// Queue operations
void enqueue(Node*& head, int val) {
    insert(head, val);
}

void dequeue(Node*& head) {
    if (!isEmpty(head))
        remove(head, frontQueue(head));
    else
        throw std::runtime_error("Queue is empty.");
}

int front(Node* head) {
    return frontQueue(head);
}

bool isQueueEmpty(Node* head) {
    return isEmpty(head);
}

int main() {
    Node* stack = nullptr;
    Node* queue = nullptr;

    std::cout << "Enter elements for the stack (enter -1 to stop): ";
    int stackElement;
    while (std::cin >> stackElement && stackElement != -1) {
        push(stack, stackElement);
    }

    std::cout << "Enter elements for the queue (enter -1 to stop): ";
    int queueElement;
    while (std::cin >> queueElement && queueElement != -1) {
        enqueue(queue, queueElement);
    }

    std::cout << "Stack elements: ";
    while (!isStackEmpty(stack)) {
        std::cout << top(stack) << " ";
        pop(stack);
    }
    std::cout << std::endl;

    std::cout << "Queue elements: ";
    while (!isQueueEmpty(queue)) {
        std::cout << front(queue) << " ";
        dequeue(queue);
    }
    std::cout << std::endl;

    return 0;
}
