#include "queue.h"

int main() {
    Queue q = Queue();

    std::cout << "Enqueuing 1" << std::endl;
    q.enqueue(1);
    q.printQueue();

    std::cout << "Enqueuing 2" << std::endl;
    q.enqueue(2);
    q.printQueue();

    std::cout << "Enqueuing 3" << std::endl;
    q.enqueue(3);
    q.printQueue();

    std::cout << "Enqueuing 4" << std::endl;
    q.enqueue(4);
    q.printQueue();

    std::cout << "Enqueuing 5" << std::endl;
    q.enqueue(5);
    q.printQueue();

    std::cout << "Denqueuing" << std::endl;
    q.dequeue();
    q.printQueue();

    std::cout << "Denqueuing" << std::endl;
    q.dequeue();
    q.printQueue();
}