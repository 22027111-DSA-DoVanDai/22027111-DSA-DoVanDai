#include <iostream>

//Bai 2: Cai dat singly linked list kieu so nguyen
//Do phuc tap cua thuat toan F = o(time, memory)

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {}  //Do phuc tap cua thuat toan F = o(1, 1)

    ~SinglyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }   //Do phuc tap cua thuat toan F = o(n, 1)

    // Thêm ph?n t? vào d?u
    void push_front(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }   //Do phuc tap cua thuat toan F = o(1, 1)

    // Thêm ph?n t? vào cu?i
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }   //Do phuc tap cua thuat toan F = o(1, 1) (do co con tro tail)

    // Chèn t?i v? trí index b?t k? (0-indexed)
    void insert(int index, int val) {
        if (index < 0 || index > size) return;
        if (index == 0) { push_front(val); return; }
        if (index == size) { push_back(val); return; }

        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node* newNode = new Node(val);
        newNode->next = current->next;
        current->next = newNode;
        size++;
        //Do phuc tap cua thuat toan F = o(1, 1) (truong hop tot nhat: chen vao dau hoac cuoi)
        //Do phuc tap cua thuat toan F = o(n, 1) (truong hop xau nhat: chen vao gan cuoi)
    }   

    // Xóa ph?n t? t?i v? trí index
    void removeAt(int index) {
        if (index < 0 || index >= size || !head) return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            if (!head) tail = nullptr;
            delete temp;
            size--;
            return;
        }

        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        if (temp == tail) tail = current;
        delete temp;
        size--;
        //Do phuc tap cua thuat toan F = o(1, 1) (truong hop tot nhat: xoa o dau)
        //Do phuc tap cua thuat toan F = o(n, 1) (truong hop xau nhat: xoa o cuoi, do phai duyet den size - 2 de cap nhat con tro tail moi (tail = size-1))
    }

    // Tìm ki?m nút ch?a giá tr?
    Node* search(int val) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == val) return current;
            current = current->next;
        }
        return nullptr;
        //Do phuc tap cua thuat toan F = o(1, 1) (truong hop tot nhat: gia tri nam o dau)
        //Do phuc tap cua thuat toan F = o(n, 1) (truong hop xau nhat: gia tri nam o cuoi hoac khong co)
    }

    void print() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "NULL\n";
    }   //Do phuc tap cua thuat toan F = o(n, 1) (do phai duyet qua tung gia tri)
};
