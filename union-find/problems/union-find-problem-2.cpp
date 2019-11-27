/*
Union-find with specific canonical element. Add a method find() to the union-find data type so that find(i) returns
the largest element in the connected component containing i. The operations, union(), connected(), and find() 
should all take logarithmic time or better.
For example, if one of the connected components is {1,2,6,9}, then the find() method should return 9 for each of 
the four elements in the connected components.
*/

#include "../union-find.h"
#include "../../queue/queue.h"

class UFMaxFind : public UF {
    public:
        UFMaxFind(int n):UF(n) {}

        int find(int i) {
            int root = UF::_getRoot(i);
            std::cout << "Root of given node:" << root << std::endl;
            int max = root;
            Queue q = Queue();
            q.enqueue(root);
            std::cout << "Enque node" << std::endl;
            q.printQueue();
            while (q.getSize())
            {
                int node = q.dequeue();
                std::cout << "Deque node" << std::endl;
                q.printQueue();
                if(node > max) {
                    max = node;
                }
                for(int i=0; i < UF::N; i++) {
                    int currNode = UF::connections[i];
                    if(currNode == node && i != node) {
                        q.enqueue(i);
                        std::cout << "Enque node" << std::endl;
                        q.printQueue();
                    }
                }
            }
            
            return max;
        }
};

int main() {
    int N;
    std::cout << "Enter the number of objects" << std::endl;
    std::cin >> N;
    UFMaxFind uf = UFMaxFind(N);

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
    std::cout << "Finding MAX..." << std::endl;
    int max = uf.find(3);
    std::cout << "Max: " << max << std::endl;
    
    return 0;
}
