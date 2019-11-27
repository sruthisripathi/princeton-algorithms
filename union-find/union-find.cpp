#include "union-find.h";

int main() {
    int N;
    std::cout << "Enter the number of objects" << std::endl;
    std::cin >> N;
    UF uf(N);

    int i = 0;
    int p, q;
    std::cout << "Enter pairs of objects representing connections (Enter -1 when you are done)" << std::endl;
    std::cout << "Enter conection: ";
    while (std::cin >> p)
    {
        if (p == -1) {
            break;
        }
        std::cin >> q;
        if (!uf.isConnectedQuickUnion(p, q)) {
            uf.quickUnion(p, q);
            std::cout << "Formed connection: " << p << " <-> " << q << std::endl;
        }
        uf.printConnectedComponents();
        std::cout << "Enter conection: ";
    }

    uf.printConnectedComponents();

    return 0;
}
