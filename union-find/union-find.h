#include<iostream>

class UF {
    protected:
        int N;
        int *connections;
        int *sz;

        int _getRoot(int p) {
            while(p != connections[p]) {
                // Path compression
                connections[p] = connections[connections[p]];
                p = connections[p];
            }
            return p;
        }

    public:
        // Parametrized constructor
        UF(int n) {
            N = n;
            connections = (int*) calloc(sizeof(int), n);
            for(int i = 0; i<n; i++) {
                connections[i] = i;
            }
            sz = (int*) calloc(sizeof(int), n);
            for(int i = 0; i<n; i++) {
                sz[i] = 1;
            }
        }

        bool isConnected(int p, int q) {
            return connections[p] == connections[q];
        }

        bool isConnectedQuickUnion(int p, int q) {
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
            int p_root = _getRoot(p); 
            int q_root = _getRoot(q);
            // Weighted quick union
            if(sz[p_root] < sz[q_root]) {
                connections[p_root] = q_root;
                sz[q_root] += sz[p_root];
            } else {
                connections[q_root] = p_root;
                sz[p_root] += sz[q_root];
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
