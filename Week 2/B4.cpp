#include <iostream>

// ==================== Interface ====================
struct ArrayList {
    int* data;
    int capacity;
    int size;

    ArrayList(int init_cap = 4) : capacity(init_cap), size(0) {
        data = new int[capacity];
    }
    ~ArrayList() { delete[] data; }

    void expand() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < size; ++i) newData[i] = data[i];
        delete[] data;
        data = newData;
    }

    void push_back(int val) {
        if (size == capacity) expand();
        data[size++] = val;
    }

    void removeAt(int index) {
        if (index < 0 || index >= size) return;
        for (int i = index; i < size - 1; ++i) data[i] = data[i + 1];
        size--;
    }
};

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

struct SinglyLinkedList {
    Node* head = nullptr;
    int size = 0;

    ~SinglyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void remove_front() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
};

// ==================== 1A. STACK BANG LIST (ARRAYLIST) ====================
class StackList {
private:
    ArrayList list;

public:
    void push(int val) {
        list.push_back(val); // Them vao cuoi mang O(1)
    }

    void pop() {
        if (isEmpty()) return;
        list.removeAt(list.size - 1); // Xoa phan tu o cuoi mang O(1)
    }

    int top() const {
        if (isEmpty()) return -1;
        return list.data[list.size - 1];
    }

    bool isEmpty() const { return list.size == 0; }
    int getSize() const { return list.size; }
};

// ==================== 1B. STACK BANG LINKEDLIST ====================
class StackLinkedList {
private:
    SinglyLinkedList list;

public:
    void push(int val) {
        list.push_front(val); // Them vao dau danh sach O(1)
    }

    void pop() {
        if (isEmpty()) return;
        list.remove_front(); // Xoa o dau danh sach O(1)
    }

    int top() const {
        if (isEmpty()) return -1;
        return list.head->data;
    }

    bool isEmpty() const { return list.size == 0; }
    int getSize() const { return list.size; }
};
