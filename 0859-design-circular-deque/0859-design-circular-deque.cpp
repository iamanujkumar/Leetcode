class MyCircularDeque {
private:
    vector<int> deque;
    int front;
    int rear;
    int size;
    int capacity;

public:
    MyCircularDeque(int k) {
        capacity = k;
        deque.resize(k);
        front = 0;
        rear = k - 1;
        size = 0;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front + capacity - 1) % capacity;  // Move front pointer back in circular way
        deque[front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;  // Move rear pointer forward in circular way
        deque[rear] = value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;  // Move front pointer forward in circular way
        size--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear + capacity - 1) % capacity;  // Move rear pointer back in circular way
        size--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return deque[front];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return deque[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};
