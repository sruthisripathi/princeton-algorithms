#include "percolation.h"
#include <time.h>

class PercolationStats {
    private:
        int m;
        int std;
        int clo;
        int chi;
        int n;
        int t;

    public:
        PercolationStats(int N, int T) {
            m = std = clo = chi = 0;
            n = N;
            t = T;
        }

        void run() {
            srand(time(0));
            int percolation_prob = 0;
            for(int i = 0; i < t; i++) {
                // std::cout<<"t: " << i <<std::endl;
                Percolation p = Percolation(n);
                while(!p.percolates()) {
                    int row = rand() % n;
                    int col = rand() % n;
                    // std::cout<<"row: " << row << "col: " << col <<std::endl;
                    p.open(row, col);
                }
                m = m + (p.numberOfOpenSites()/(n*n));
            }
            m /= t;
        }

        double mean() {
            return m;
        }

        double stddev() {

        }

        double confidenceLo() {

        }

        double ConfidenceHi() {

        }
};
