#include <iostream>

//Bai 1: Cai dat list kieu so nguyen
//Do phuc tap cua thuat toan F = o(time, memory)

struct ArrayList {
    int* data;      // Con tro toi mang dong
    int capacity;   // suc chua cua mang
    int size;       // so luong phan tu thuc te dang co

    // khoi tao mang dong voi dung luong cho truoc (default = 4)
    ArrayList(int init_capacity = 4) {
        capacity = init_capacity;
        size = 0;
        data = new int[capacity];
    }   //Do phuc tap cua thuat toan F = o(1, capacity)

    // Giai phong bo nho dong khi dung xong
    ~ArrayList() {
        delete[] data;
    }   //Do phuc tap cua thuat toan F = o(1, 1)

    // tu dong gap doi suc chua cua mang khi mang bi day
    void expand() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data; // Xóa m?ng cu
        data = newData; // Tr? sang m?ng m?i
    }   //Do phuc tap cua thuat toan F = o(n, n)

    // 1. Them vao cuoi
    void push_back(int val) {
        if (size == capacity) expand();
        data[size++] = val;
        //Do phuc tap cua thuat toan F = o(1, 1) voi truong hop binh thuong
    }   // Neu mang bi day, ham phai goi them expand(), do phuc tap la F = o(n, n)

    // 2. Chen vao vi tri index
    void insert(int index, int val) {
        if (index < 0 || index > size) return;
        if (size == capacity) expand();

        for (int i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = val;
        size++;
        //Do phuc tap cua thuat toan F = o(1, 1) voi truong hop binh thuong
    }   // Neu mang bi day, ham phai goi them expand(), do phuc tap la F = o(n, n)

    // 3. xoa tai vi tri index
    void removeAt(int index) {
        if (index < 0 || index >= size) return;

        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1]; 
        }
        size--;
        //Do phuc tap cua thuat toan F = o(1, 1) voi truong hop binh thuong (xoa o cuoi mang)
    }   //Truong hop xau nhat la xoa o dau mang, do phuc tap la F = o(n, 1)

    // 4. Tim kiem gia tri tai vi tri val
    int search(int val) {
        for (int i = 0; i < size; ++i) {
            if (data[i] == val) return i;
        }
        return -1;
        //Do phuc tap cua thuat toan F = o(1, 1) voi truong hop binh thuong (gia tri tim nam o vi tri dau tien)
    }   //Truong hop xau nhat khi gia tri nam o cuoi hoac khong ton tai trong mang, do phuc tap la F = o(n, 1)

    // 5. In danh sach
    void print() {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }   //Do phuc tap cua thuat toan F = o(n, 1)
};

int main() {
    ArrayList list; // Khoi tao capacity = 4

    //Khoi tao 5 gia tri
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.push_back(50); // Ham expand() tu dong chay, capacity gap doi (8)

    list.print(); // Output: 10 20 30 40 50

    list.insert(2, 25); // Chen 25 vao vi tri 2
    list.print(); // Output: 10 20 25 30 40 50

    list.removeAt(0); // Xoa tai vi tri 0 (so 10)
    list.print(); // Output: 20 25 30 40 50

    return 0;
}
