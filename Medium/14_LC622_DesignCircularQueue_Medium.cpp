class MyCircularQueue {
private:
    vector<int> queue;
    int frontIndex;
    int rearIndex;
    int capacity;
    int count;

public:
    MyCircularQueue(int k) {
        capacity = k;
        queue.resize(k);

        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        rearIndex = (rearIndex + 1) % capacity;
        queue[rearIndex] = value;
        count++;

        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        frontIndex = (frontIndex + 1) % capacity;
        count--;

        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return queue[frontIndex];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }

        return queue[rearIndex];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};
