#include "percolation.h"
#include <time.h>
#include<cmath>

class PercolationStats {
    private:
        float m;
        float std;
        float clo;
        float chi;
        int n;
        int t;
        int *probs;

    public:
        PercolationStats(int N, int T) {
            m = std = clo = chi = 0;
            n = N;
            t = T;
            probs = (int*) calloc(sizeof(int), T);
            for(int i = 0; i<T; i++) {
                probs[i] = i;
            } 
        }

        ~PercolationStats() {
            delete [] probs;
        }

        void run() {
            srand(time(0));
            for(int i = 0; i < t; i++) {
                // std::cout<<"t: " << i <<std::endl;
                Percolation p = Percolation(n);
                while(!p.percolates()) {
                    int row = rand() % n;
                    int col = rand() % n;
                    // std::cout<<"row: " << row << "col: " << col <<std::endl;
                    p.open(row, col);
                }
                float percolation_prob = (float)p.numberOfOpenSites()/(n*n);
                probs[i] = percolation_prob;
                m = m + percolation_prob;
            }
            m /= t;
            for(int i=0; i<t; i++) {
                float temp = (probs[i] - m);
                std = temp*temp;
            }
            std = std / (float)(t-1);
            clo = m - ((1.96*std)/sqrt(t));
            chi = m + ((1.96*std)/sqrt(t));
        }

        double mean() {
            return m;
        }

        double stddev() {
            return std;
        }

        double confidenceLo() {
            return clo;
        }

        double ConfidenceHi() {
            return chi;
        }
};
