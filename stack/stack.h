#include "../double-linked-list/double-linked-list.h"

class Stack {
    private:
        LinkedList s;
    public:
        Stack() {}

        void push(int val) {
            s.insertAtEnd(val);
        }

        int pop() {
            return s.removeFromEnd();
        }

        void printQueue() {
            s.printList();
        }
        int getSize() {
            return s.getSize();
        }
};
