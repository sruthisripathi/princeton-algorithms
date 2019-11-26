#include "stack.h"

int main() {
    Stack s = Stack();

    std::cout << "Stacking 1" << std::endl;
    s.push(1);
    s.printQueue();

    std::cout << "Stacking 2" << std::endl;
    s.push(2);
    s.printQueue();

    std::cout << "Stacking 3" << std::endl;
    s.push(3);
    s.printQueue();

    std::cout << "Stacking 4" << std::endl;
    s.push(4);
    s.printQueue();

    std::cout << "Stacking 5" << std::endl;
    s.push(5);
    s.printQueue();

    std::cout << "Popping" << std::endl;
    s.pop();
    s.printQueue();

    std::cout << "Popping" << std::endl;
    s.pop();
    s.printQueue();
}
