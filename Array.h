#include <iostream>

using namespace std;

template <typename T>
class Array {
private:
    T* data;
    int size;
    int capacity;
    int grow;

public:
    Array() : data(nullptr), size(0), capacity(0), grow(1) {}

    ~Array() {
        if (data) {
            delete[] data;
        }
    }

    int GetSize() const {
        return capacity;
    }

    void SetSize(int newSize, int newGrow = 1) {
        grow = newGrow;
        if (newSize == capacity) return;

        T* newData = new T[newSize];

        int elementsToCopy = (size < newSize) ? size : newSize;
        for (int i = 0; i < elementsToCopy; i++) {
            newData[i] = data[i];
        }

        if (data) delete[] data;

        data = newData;
        capacity = newSize;

        if (size > capacity) {
            size = capacity;
        }
    }

    int GetUpperBound() const {
        return size - 1;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    void FreeExtra() {
        if (size < capacity) {
            SetSize(size, grow);
        }
    }

    void RemoveAll() {
        size = 0;
    }

    T GetAt(int index) const {
        if (index < 0 || index >= size) {
            cout << "Error: Index " << index << " is out of bounds (GetAt)." << endl;
            return T();
        }
        return data[index];
    }

    void SetAt(int index, const T& value) {
        if (index < 0 || index >= size) {
            cout << "Error: Index " << index << " is out of bounds (SetAt)." << endl;
            return;
        }
        data[index] = value;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            cout << "Error: Index " << index << " is out of bounds []." << endl;
            static T dummy;
            return dummy;
        }
        return data[index];
    }

    const T* GetData() const {
        return data;
    }

    void Add(const T& value) {
        if (size >= capacity) {
            int newCapacity = capacity + ((grow > 0) ? grow : 1);
            SetSize(newCapacity, grow);
        }
        data[size++] = value;
    }

    void Append(const Array<T>& other) {
        for (int i = 0; i < other.size; i++) {
            Add(other.data[i]);
        }
    }

    Array<T>& operator=(const Array<T>& other) {
        if (this == &other) return *this;

        if (data) delete[] data;

        size = other.size;
        capacity = other.capacity;
        grow = other.grow;

        data = new T[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }

        return *this;
    }

    Array(const Array<T>& other) : data(nullptr), size(0), capacity(0), grow(1) {
        *this = other;
    }

    void InsertAt(int index, const T& value) {
        if (index < 0 || index > size) {
            cout << "Error: Invalid index " << index << " for InsertAt." << endl;
            return;
        }

        if (size >= capacity) {
            int newCapacity = capacity + ((grow > 0) ? grow : 1);
            SetSize(newCapacity, grow);
        }

        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];
        }

        data[index] = value;
        size++;
    }

    void RemoveAt(int index) {
        if (index < 0 || index >= size) {
            cout << "Error: Invalid index " << index << " for RemoveAt." << endl;
            return;
        }

        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }

        size--;
    }

    void Print() const {
        cout << "[ ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << "] (Size: " << size << ", Capacity: " << capacity << ")" << endl;
    }
};