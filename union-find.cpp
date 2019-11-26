#include<iostream>
using namespace std;

class UF {
    private:
        int N;
        int *connections;

        int _getRoot(int p) {
            while(p != connections[p]) {
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
            connections[p_root] = q_root; 
        }

        void printConnectedComponents() {
            cout << "Connections:" << endl;
            for (int i = 0; i < N; i++) {
                cout << connections[i] << " ";
            }
            cout << endl;
            for (int i = 0; i < N; i++) {
                cout << i << " ";
            }
            cout << endl;
        }
};

int main() {
    int N;
    cout << "Enter the number of objects" << endl;
    cin >> N;
    UF uf(N);

    int i = 0;
    int p, q;
    cout << "Enter pairs of objects representing connections (Enter -1 when you are done)" << endl;
    while (cin >> p)
    {
        if (p == -1) {
            break;
        }
        cin >> q;
        if (!uf.isConnectedQuickUnion(p, q)) {
            uf.quickUnion(p, q);
            cout << "Formed connection: " << p << " <-> " << q << endl;
        }
    }

    uf.printConnectedComponents();

    return 0;
}
