class MyCircularDeque {
public:
    vector<int> v;
    int front = 0, back = 0, sizee = 0, capacity;

    MyCircularDeque(int k) {
        v.resize(k);
        capacity = k;
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        v[front] = value;
        sizee++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        v[back] = value;
        back = (back + 1) % capacity;
        sizee++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        sizee--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        back = (back - 1 + capacity) % capacity;
        sizee--;
        return true;
    }

    int getFront() {
        return isEmpty() ? -1 : v[front];
    }

    int getRear() {
        return isEmpty() ? -1 : v[(back - 1 + capacity) % capacity];
    }

    bool isEmpty() { return sizee == 0; }
    bool isFull() { return sizee == capacity; }
};