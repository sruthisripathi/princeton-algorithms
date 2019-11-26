#include<iostream>
#include "../node.h"

class LinkedList {
    private:
        Node* start;
        Node* end;
        int sz;
    
    public:
        LinkedList(): start(nullptr), end(nullptr), sz(0) { }

        int getSize() {
            return sz;
        }
        void insertAtStart(int val) {
            Node* n = new Node(val);

            // If start and end are null
            if(start == nullptr && end == nullptr) {
                start = end = n;
            }
            // There is at least 1 node in the list
            else {
                n->next = start;
                start->prev = n;
                // There is only one node in the list
                if(start->next == nullptr) {
                    end->prev = n;
                }
                start = n;
            }
            sz += 1;
        }

        void insertAtEnd(int val) {
            Node* n = new Node(val);

            // If start and end are null
            if(start == nullptr && end == nullptr) {
                start = end = n;
            }
            // There is at least 1 node in the list
            else {
                n->prev = end;
                end->next = n;
                // There is only one node in the list
                if(end->prev == nullptr) {
                    start->next = n;
                }
                end = n;
            }
            sz += 1;
        }

        int removeFromStart() {
            if(start == nullptr) return 999;
            int val = start->val;
            if(start->next == nullptr) {
                start = end = nullptr;
            } else {
                start = start->next;
                start->prev = nullptr;
            }
            sz -= 1;
            return val;
        }

        int removeFromEnd() {
            if(end == nullptr) return 999;
            int val = end->val;
            if(end->prev == nullptr) {
                start = end = nullptr;
            } else {
                end = end->prev;
                end->next = nullptr;
            }
            sz -= 1;
            return val;
        }

        void printList() {
            Node *ptr = start;
            while(ptr != nullptr) {
                std::cout << ptr->val << " ";
                ptr = ptr->next;
            }
            std::cout << std::endl;
        }
};
