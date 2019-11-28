#include<iostream>
#include<time.h>

int main() {
    srand(time(0));
    for(int i=0;i<5;i++) {
        std::cout<< rand()%5 << " ";
    }
    std::cout << std::endl;
    return 0;
}