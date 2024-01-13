#include <unistd.h>

#include <iostream>
#include <string>

using namespace std;

int main() {
    std::string nothing = "";
    for (int i = 0; i < 10; ++i) {
        int percent = i % 10;
        std::cout << "\r" << std::flush;
        std::cout << "[" << std::flush;
        for (int j = 0; j < 10; ++j) {
            if (j <= percent)
                std::cout << "#" << std::flush;
            else
                std::cout << "-" << std::flush;
        }
        std::cout << "]\r" << std::flush;
        sleep(1);
    }
    // std::cout << "test" << std::flush;
    // std::cout << "\rbest" << std::flush;
}
