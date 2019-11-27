/*
Union-find with specific canonical element. Add a method find() to the union-find data type so that find(i) returns
the largest element in the connected component containing i. The operations, union(), connected(), and find() 
should all take logarithmic time or better.
For example, if one of the connected components is {1,2,6,9}, then the find() method should return 9 for each of 
the four elements in the connected components.
*/

#include "../union-find.h"
#include "../../queue/queue.h"

int main() {
    int N;
    std::cout << "Enter the number of objects" << std::endl;
    std::cin >> N;
    UF uf = UF(N);

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
        if (!uf.find(p, q)) {
            uf.quickUnion(p, q);
            std::cout << "Formed connection: " << p << " <-> " << q << std::endl;
        }
        uf.printConnectedComponents();
        std::cout << "Enter conection: ";
    }

    uf.printConnectedComponents();
    std::cout << "Finding MAX for 3..." << std::endl;
    int max = uf.findMax(3);
    std::cout << "Max: " << max << std::endl;
    std::cout << "Finding MAX for 5..." << std::endl;
    max = uf.findMax(5);
    std::cout << "Max: " << max << std::endl;
    
    return 0;
}
