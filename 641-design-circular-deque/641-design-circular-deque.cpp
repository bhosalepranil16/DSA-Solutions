class MyCircularDeque {
public:
    int *arr;
    int front, rear, n;
    MyCircularDeque(int k) {
        arr = new int[k];
        n = k;
        front = rear = -1;
    }
    
    bool insertFront(int value) {
        if(isFull()) {
            return false;
        } else {
            if(isEmpty()) {
                front = rear = 0;
                arr[front] = value;
            } else {
                front = (front - 1 + n) % n;
                arr[front] = value;
            }
            return true;
        }
    }
    
    bool insertLast(int value) {
        if(isFull()) {
            return false;
        } else {
            if(front == -1 && rear == -1) {
                rear = front = 0;
                arr[rear] = value;
            } else {
                rear = (rear + 1) % n;
                arr[rear] = value;
            }
            return true;
        }
    }
    
    bool deleteFront() {
        if(isEmpty()) {
            return false;
        } else {
            if(front == rear) {
                front = rear = -1;
                return true;
            } else {
                front = (front + 1) % n;
                return true;
            }
        }
    }
    
    bool deleteLast() {
        if(isEmpty()) {
            return false;
        } else {
            if(front == rear) {
                front = rear = -1;
                return true;
            } else {
                rear = (rear - 1 + n) % n;
                return true;
            }
        }
    }
    
    int getFront() {
        if(isEmpty()) {
            return -1;
        } else {
            return arr[front];
        }
    }
    
    int getRear() {
        if(isEmpty()) {
            return -1;
        } else {
            return arr[rear];
        }
    }
    
    bool isEmpty() {
        if(front == -1 && rear == -1) {
            return true;
        } else {
            return false;
        }
    }
    
    bool isFull() {
        if((rear + 1) % n == front) {
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */