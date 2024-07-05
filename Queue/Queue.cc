#include <iostream>

class Queue {
private:
    int* arr;                // 배열 포인터
    int front;              // 큐의 맨 앞 인덱스
    int rear;               // 큐의 맨 뒤 인덱스
    int capacity;       // 큐의 최대 용량
    int size;               // 현재 큐의 크기

public:
    Queue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int item) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue." << std::endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = item;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return -1;
        }

        int item = arr[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    int getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return -1;
        }

        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return -1;
        }

        return arr[rear];
    }

    int getSize() {
        return size;
    }
};
