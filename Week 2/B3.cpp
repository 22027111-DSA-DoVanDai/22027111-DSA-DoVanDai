#include <iostream>

//Bai 2: Cai dat double linked list kieu so nguyen
//Do phuc tap cua thuat toan F = o(time, memory)

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    DNode* head;
    DNode* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}   //Do phuc tap cua thuat toan F = o(1, 1)

    ~DoublyLinkedList() {
        DNode* current = head;
        while (current != nullptr) {
            DNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }   //Do phuc tap cua thuat toan F = o(n, 1)

    // Thêm ph?n t? vào d?u
    void push_front(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }   //Do phuc tap cua thuat toan F = o(1, 1)

    // Thêm ph?n t? vào cu?i
    void push_back(int val) {
        DNode* newNode = new DNode(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }   //Do phuc tap cua thuat toan F = o(1, 1)

    // Chèn t?i v? trí index b?t k?
    void insert(int index, int val) {
        if (index < 0 || index > size) return;
        if (index == 0) { push_front(val); return; }
        if (index == size) { push_back(val); return; }

        DNode* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        DNode* newNode = new DNode(val);
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
        size++;
        //Do phuc tap cua thuat toan F = o(1, 1) (truong hop tot nhat: chen vao dau hoac cuoi)
        //Do phuc tap cua thuat toan F = o(n, 1) (truong hop xau nhat: chen vao giua mang)
    }

    // Xóa ph?n t? t?i v? trí index
    void removeAt(int index) {
        if (index < 0 || index >= size || !head) return;

        DNode* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        if (current->prev) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }

        delete current;
        size--;
        //Do phuc tap cua thuat toan F = o(1, 1) (truong hop tot nhat: xoa o dau hoac cuoi)
        //Do phuc tap cua thuat toan F = o(n, 1) (truong hop xau nhat: xoa nut o giua danh sach)
    }

    // Tìm ki?m nút ch?a giá tr?
    DNode* search(int val) const {
        DNode* current = head;
        while (current != nullptr) {
            if (current->data == val) return current;
            current = current->next;
        }
        return nullptr;
        //Do phuc tap cua thuat toan F = o(1, 1) (truong hop tot nhat: gia tri nam o dau)
        //Do phuc tap cua thuat toan F = o(n, 1) (truong hop xau nhat: gia tri nam o cuoi hoac khong ton tai)
    }

    void printForward() const {
        DNode* current = head;
        while (current != nullptr) {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "NULL\n";
    }   //Do phuc tap cua thuat toan F = o(n, 1) (ham phai duyet qua tung phan tu)
};
