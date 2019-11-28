#include "percolation.h"

int main() {
    Percolation p = Percolation(3);
    std::cout << "Initiate..." << std::endl;
    p.printGrid();
    p.printUF();
    std::cout << std::endl;
 
    std::cout << "Open (0, 1):" << std::endl;
    p.open(0, 1);
    p.printGrid();
    p.printUF();
    std::cout << std::endl;

    std::cout << "Open (0, 2):" << std::endl;
    p.open(0, 2);
    p.printGrid();
    p.printUF();
    std::cout << std::endl;

    std::cout << "Open (1, 0):" << std::endl;
    p.open(1, 0);
    p.printGrid();
    p.printUF();
    std::cout << std::endl;

    std::cout << "Open (1, 1):" << std::endl;
    p.open(1, 1);
    p.printGrid();
    p.printUF();
    std::cout << std::endl;

    std::cout << "Open (2, 2):" << std::endl;
    p.open(2, 2);
    p.printGrid();
    p.printUF();
    std::cout << std::endl;

    std::cout << "Open (1, 2):" << std::endl;
    p.open(1, 2);
    p.printGrid();
    p.printUF();
    std::cout << std::endl;

    std::cout << "No of open sites: " << p.numberOfOpenSites() << std::endl;

    bool percolates = p.percolates();
    std::cout << "Percolates???" << "";
    if(percolates) {
        std::cout<<"YESSS!! :)";
    } else {
        std::cout<<"NO... :(";
    }
    return 0;
}
