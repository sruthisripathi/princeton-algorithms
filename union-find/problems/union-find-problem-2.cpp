/*
Union-find with specific canonical element. Add a method find() to the union-find data type so that find(i) returns
the largest element in the connected component containing i. The operations, union(), connected(), and find() 
should all take logarithmic time or better.
For example, if one of the connected components is {1,2,6,9}, then the find() method should return 9 for each of 
the four elements in the connected components.
*/

#include "../union-find.h"
#include "../../queue/queue.h"

class UFMaxFind : UF {
    public:
        UFMaxFind(int n):UF(n) {}

        int find(int i) {
            int root = UF::_getRoot(i);
            int max = root;
            Queue q = Queue();
            q.enqueue(root);
            while (q.getSize())
            {
                int node = q.dequeue();
                if(node > max) {
                    max = node;
                }
                for(int i=0; i < UF::N; i++) {
                    int currNode = UF::connections[i];
                    if(currNode == node) {
                        q.enqueue(currNode);
                    }
                }
            }
            
            return max;
        }
};
