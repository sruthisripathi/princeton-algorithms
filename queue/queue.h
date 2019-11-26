#include "../double-linked-list/double-linked-list.h"

class Queue {
    private:
        LinkedList q;
    public:
        Queue() {}

        void enqueue(int val) {
            q.insertAtStart(val);
        }

        int dequeue() {
            return q.removeFromEnd();
        }

        void printQueue() {
            q.printList();
        }

        int getSize() {
            return q.getSize();
        }
};
