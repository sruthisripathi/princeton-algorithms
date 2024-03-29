/*
Social network connectivity. Given a social network containing n members and a log file containing m timestamps 
at which times pairs of members formed friendships, design an algorithm to determine the earliest time at which 
all members are connected (i.e., every member is a friend of a friend of a friend ... of a friend). Assume that 
the log file is sorted by timestamp and that friendship is an equivalence relation. The running time of your 
algorithm should be mlogn or better and use extra space proportional to n.
*/

#include "../union-find.h"

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
        if(uf.isConnectedGraph()) {
            std::cout << "Earliest timem where full network is connected: " << i << std::endl;
            break;
        }
        i += 1;
        uf.printConnectedComponents();
        std::cout << "Enter conection: ";
    }

    uf.printConnectedComponents();
    
    return 0;
}
