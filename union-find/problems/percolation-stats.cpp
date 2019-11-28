#include "percolation-stats.h"

int main() {
    PercolationStats ps = PercolationStats(20, 100);
    ps.run();
    std::cout << "Mean percolation probability (20, 100): " << ps.mean() << std::endl;
    return 0;
}