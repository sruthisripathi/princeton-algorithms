#include "double-linked-list.h"

int main() {
    LinkedList l = LinkedList();

    std::cout << "Inserting 1 at start" << std::endl;
    l.insertAtStart(1);
    std::cout << "Linked list: ";
    l.printList();

    std::cout << "Inserting 2 at start" << std::endl;
    l.insertAtStart(2);
    std::cout << "Linked list: ";
    l.printList();

    std::cout << "Inserting 3 at start" << std::endl;
    l.insertAtStart(3);
    std::cout << "Linked list: ";
    l.printList();

    std::cout << "Inserting 4 at start" << std::endl;
    l.insertAtStart(4);
    std::cout << "Linked list: ";
    l.printList();

    std::cout << "Inserting 5 at start" << std::endl;
    l.insertAtStart(5);
    std::cout << "Linked list: ";
    l.printList();

    std::cout << "Inserting 6 at end" << std::endl;
    l.insertAtEnd(6);
    std::cout << "Linked list: ";
    l.printList();

    std::cout << "Inserting 7 at end" << std::endl;
    l.insertAtEnd(7);
    std::cout << "Linked list: ";
    l.printList();

    std::cout << "Inserting 8 at end" << std::endl;
    l.insertAtEnd(8);
    std::cout << "Linked list: ";
    l.printList();

    std::cout << "Inserting 9 at end" << std::endl;
    l.insertAtEnd(9);
    std::cout << "Linked list: ";
    l.printList();

    std::cout << "Inserting 10 at end" << std::endl;
    l.insertAtEnd(10);
    std::cout << "Linked list: ";
    l.printList();

    std::cout << "Removing from start" << std::endl;
    l.removeFromStart();
    std::cout << "Linked list: ";
    l.printList();

    std::cout << "Removing from start" << std::endl;
    l.removeFromStart();
    std::cout << "Linked list: ";
    l.printList();

    std::cout << "Removing from end" << std::endl;
    l.removeFromEnd();
    std::cout << "Linked list: ";
    l.printList();

    std::cout << "Removing from end" << std::endl;
    l.removeFromEnd();
    std::cout << "Linked list: ";
    l.printList();

    return 0;
}
