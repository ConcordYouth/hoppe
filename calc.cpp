#include <iostream>
#include <string>

// int term(int i, int y, int& sum) {
//     if (i == y) {
//         return 1;
//     } else {
//         return term(i - 1, y, sum) + 1;
//     }
// }

int summation(int x, int y) {
    int velo = x;
    int acceleration = x;
    int sum = 1 + velo;
    for (int i = x + 1; i < y; ++i) {
        velo += acceleration;
        sum += velo;
        ++acceleration;
    }
    return sum;
}

int main() {
    while (true) {
        int set_size;
        std::cout << "how many numbers should be in each set: ";
        std::cin >> set_size;
        int number;
        std::cout << "how high should the numbers go within this set: ";
        std::cin >> number;
        int ans;
        if (number <= set_size) {
            if (number < set_size)
                ans = 0;
            else
                ans = 1;
        } else if (number - 1 == set_size) {
            ans = number;
        } else {
            ans = summation(set_size, number);
        }
        std::cout << "number of calculations: " << ans << "\n";
    }
}
