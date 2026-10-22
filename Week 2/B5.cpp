#include <iostream>

// ==================== Interface (QUEUE LINKEDLIST) ====================
struct QueueNode {
    int data;
    QueueNode* next;
    QueueNode(int val) : data(val), next(nullptr) {}
};

struct QueueLinkedListStructure {
    QueueNode* head = nullptr;
    QueueNode* tail = nullptr;
    int size = 0;

    ~QueueLinkedListStructure() {
        while (head) {
            QueueNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_back(int val) {
        QueueNode* newNode = new QueueNode(val);
        if (!head) head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void remove_front() {
        if (!head) return;
        QueueNode* temp = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete temp;
        size--;
    }
};

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

// ==================== 2A. QUEUE BANG LIST (ARRAYLIST) ====================
class QueueList {
private:
    ArrayList list;

public:
    void push(int val) {
        list.push_back(val); // Them phan tu vao cuoi mang O(1)
    }

    void pop() {
        if (isEmpty()) return;
        list.removeAt(0); // xoa phan tu o dau mang (dich cac phan tu con lai sang trai)
    }

    int front() const {
        if (isEmpty()) return -1;
        return list.data[0];
    }

    bool isEmpty() const { return list.size == 0; }
    int getSize() const { return list.size; }
};

// ==================== 2B. QUEUE BANG LINKEDLIST ====================
class QueueLinkedList {
private:
    QueueLinkedListStructure list;

public:
    void push(int val) {
        list.push_back(val); // Them vao cuoi qua con tro tail O(1)
    }

    void pop() {
        if (isEmpty()) return;
        list.remove_front(); // Xoa o dau qua con tro head O(1)
    }

    int front() const {
        if (isEmpty()) return -1;
        return list.head->data;
    }

    bool isEmpty() const { return list.size == 0; }
    int getSize() const { return list.size; }
};
