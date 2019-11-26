#include "union-find.h";

int main() {
    int N;
    cout << "Enter the number of objects" << endl;
    cin >> N;
    UF uf(N);

    int i = 0;
    int p, q;
    cout << "Enter pairs of objects representing connections (Enter -1 when you are done)" << endl;
    cout << "Enter conection: ";
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
        uf.printConnectedComponents();
        cout << "Enter conection: ";
    }

    uf.printConnectedComponents();

    return 0;
}
