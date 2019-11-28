#include "../union-find.h"

class Percolation {
    private:
        int **grid;
        int N;
        UF uf;
        int totalOpenSites;
        int site(int row, int col) {
            if(row == 0) {
                return 0;
            }
            if(row == N-1) {
                return (N*N)-(2*N)+1;
            }
            return ((row-1)*N)+col+1;
        }
    public:
        Percolation(int n) {
            N = n;
            grid = new int*[n];
            for (int i=0; i < n; i++) {
                grid[i] = new int[n];
                for(int j=0; j<n; j++) {
                    grid[i][j] = 0;               
                }
            }
            uf = UF((n*n)-(2*n)+2);
            totalOpenSites=0;
        }

        ~Percolation() {
            for (int i=0; i<N; i++) {
                delete [] grid[i];
            }
            delete [] grid;
        }

        void open(int row, int col) {
            if(!isOpen(row, col)) {
                int center = site(row, col);
                // std::cout << "Center site: " << center << std::endl;
                grid[row][col]=1;
                if(row-1 >= 0 && grid[row-1][col]) {
                    int north = site(row-1, col);
                    // std::cout << "North site: " << north << std::endl;
                    uf.quickUnion(center, north);
                }
                if(row+1 < N && grid[row+1][col]) {
                    int south = site(row+1, col);
                    // std::cout << "South site: " << south << std::endl;
                    uf.quickUnion(south, center);
                }
                if(col-1 >= 0 && grid[row][col-1]) {
                    int west = site(row, col-1);
                    // std::cout << "West site: " << west << std::endl;
                    uf.quickUnion(center, west);
                }
                if(col+1 < N &&grid[row][col+1]) {
                    int east = site(row, col+1);
                    // std::cout << "East site: " << east << std::endl;
                    uf.quickUnion(east, center);
                }
                totalOpenSites += 1;
            }
        }

        bool isOpen(int row, int col) {
            return grid[row][col] == 1;
        }

        bool isFull(int row, int col) {
            return uf.find(0, row*N+col);
        }

        int numberOfOpenSites() {
            return totalOpenSites;
        }

        bool percolates() {
            return uf.find(0, (N*N)-2*N+1);
        }

        void printGrid() {
            for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                    std::cout << grid[i][j] << " ";                
                }
                std::cout << std::endl;
            }
        }

        void printUF() {
            uf.printConnectedComponents();
        }
};
