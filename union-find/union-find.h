#include<iostream>

class UF {
    protected:
        int N;
        int *connections;
        int *sz;
        int *maxObj;
        int numComponents;

        int _getRoot(int p) {
            while(p != connections[p]) {
                // Path compression
                connections[p] = connections[connections[p]];
                p = connections[p];
            }
            return p;
        }

    public:
        UF() {}

        // Parametrized constructor
        UF(int n) {
            N = numComponents = n;
            connections = (int*) calloc(sizeof(int), n);
            maxObj = (int*) calloc(sizeof(int), n);
            sz = (int*) calloc(sizeof(int), n);
            for(int i = 0; i<n; i++) {
                connections[i] = i;
                sz[i] = 1;
                maxObj[i] = i;
            } 
        }

        int findMax(int i) {
            int root = _getRoot(i);
            return maxObj[root];
        }

        int isConnectedGraph() {
            std::cout << "No of components: " << numComponents << std::endl;
            return numComponents == 1;
        }

        bool isConnected(int p, int q) {
            return connections[p] == connections[q];
        }

        bool find(int p, int q) {
            return _getRoot(p) == _getRoot(q);
        }

        void quickFind(int p, int q) {
            // Eager algorithm
            int label_p = connections[p];
            int label_q = connections[q];
            for(int i=0; i<N; i++) {
                if(connections[i] == label_p || connections [i] == label_q) {
                    connections[i] = label_q;
                }
            }
        }

        void quickUnion(int p, int q) {
            // Lazy approach
            if(!isConnected(p, q)) {
                int p_root = _getRoot(p); 
                int q_root = _getRoot(q);
                int max = p_root > q_root ? p_root : q_root;
                // Weighted quick union
                if(sz[p_root] < sz[q_root]) {
                    connections[p_root] = q_root;
                    sz[q_root] += sz[p_root];
                    maxObj[q_root] = max;
                } else {
                    connections[q_root] = p_root;
                    sz[p_root] += sz[q_root];
                    maxObj[p_root] = max;
                }
                numComponents -= 1;
            }
        }

        void printConnectedComponents() {
            std::cout << "Indices:" << std::endl;
            for (int i = 0; i < N; i++) {
                std::cout << i << " ";
            }
            std::cout << std::endl;
            std::cout << "Connections:" << std::endl;
            for (int i = 0; i < N; i++) {
                std::cout << connections[i] << " ";
            }
            std::cout << std::endl;
            std::cout << "Sizes:" << std::endl;
            for (int i = 0; i < N; i++) {
                std::cout << sz[i] << " ";
            }
            std::cout << std::endl;
        }
};
