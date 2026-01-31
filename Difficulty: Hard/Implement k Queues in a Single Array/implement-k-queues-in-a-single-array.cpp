class kQueues {
    int *arr;       // main array
    int *front;     // front of each queue
    int *rear;      // rear of each queue
    int *next;      // next index
    int freeSpot;   // first free index
    int n, k;

public:
    kQueues(int n, int k) {
        this->n = n;
        this->k = k;

        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];

        // Initialize all queues as empty
        for(int i = 0; i < k; i++) {
            front[i] = -1;
            rear[i] = -1;
        }

        // Initialize free list
        for(int i = 0; i < n - 1; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        freeSpot = 0;
    }

    // ENQUEUE
    void enqueue(int x, int qi) {
        if(isFull()) return;

        int index = freeSpot;
        freeSpot = next[index];

        if(front[qi] == -1) {
            front[qi] = index;
        } else {
            next[rear[qi]] = index;
        }

        next[index] = -1;
        rear[qi] = index;
        arr[index] = x;
    }

    // DEQUEUE
    int dequeue(int qi) {
        if(isEmpty(qi)) return -1;

        int index = front[qi];
        front[qi] = next[index];

        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

    // IS EMPTY
    bool isEmpty(int qi) {
        return front[qi] == -1;
    }

    // IS FULL
    bool isFull() {
        return freeSpot == -1;
    }
};
