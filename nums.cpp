#include <iostream>
#include <map>
#include <string>
#include <vector>

bool uptoCheck(std::vector<int> elements, int upto) {
    bool check = true;
    int offset = elements.size() - 1;
    for (int i = 0; i <= elements.size() - 1; ++i) {
        if (elements[i] > upto - offset) {
            return false;
        }
        --offset;
    }
    return check;
}

void addVectorToMap(std::vector<int>,
                    std::map<int, std::vector<std::vector<int>>>& addTo) {}

void addToVector(int upto, std::vector<int> elements,
                 std::map<std::string, std::vector<std::vector<int>>>& answers,
                 int requirement) {
    int sum = 0;
    int product = 0;
    for (int i = 0; i < elements.size(); ++i) {
        sum += elements[i];
        product = elements[i] * elements[i] + product;
    }

    std::string key = std::to_string(sum) + ":" + std::to_string(product);
    // std::cout << key << "\n";
    if (answers.find(key) != answers.end()) {
        answers[key].push_back(elements);
    } else {
        answers[key] = {elements};
    }

    for (int i = 0; i < elements.size(); ++i) {
        std::cout << elements[i] << " ";
    }
    std::cout << "\n";

    bool check = uptoCheck(elements, upto);
    if (check) {
        // std::cout << "req: " << requirement;
        int start = 1;
        int last_element = elements.size() - 1;
        for (int i = last_element; i >= 0; --i) {
            if (requirement < start) {
                if (i == last_element) {
                    std::vector<int> clone = elements;
                    ++clone[i];
                    if (clone[i] <= upto)
                        addToVector(upto, clone, answers,
                                    0);  // the if is ruining the algorithm
                } else if (elements[i] < elements[i + 1] - 1) {
                    std::vector<int> clone = elements;
                    ++clone[i];
                    addToVector(upto, clone, answers, start - 1);
                }
            }
            ++start;
        }
        // if (requirement == start) {
        //     // 1, 2, ... , upto (inclusive) will be shown as extra
        //     // i.e. upto = 6, set_size = 3 => 1,2,6
        //     std::vector<int> clone = elements;
        //     ++clone[elements.size() - 1];
        //     addToVector(upto, clone, answers, 0);
        // }
        // for (int i = elements.size() - 2; i >= 0; --i) {
        //     if (elements[i] < elements[i + 1] - 1) {
        //         // there has to be room for the lesser element to grow
        //         // i.e. 1,2,4 => 1,3,4 but not 1,3,4 => 1,4,4
        //         std::vector<int> clone = elements;
        //         clone[i] += 1;
        //         addToVector(upto, clone, answers, start - 1);
        //         break;
        //     }
        // }
    }
    // std::cout << i << " : " << j << " : " << k << "\n";
    // if (requirement < 1) addToVector(upto, i, j, k + 1, answers, 0);
    //
    // // in every case 1,2,3 => 1,2,4 & 1,2,4 => 1,2,5 etc.
    // if (j < k - 1 && requirement < 2) {
    //     // the below function should never  recursively call the original
    //     // function to increment k
    //     addToVector(upto, i, j + 1, k, answers, 1);
    // }
    // if (i < j - 1 && requirement < 3) {
    //     // the below function should never  recursively call the original
    //     // function to increment j || k
    //     addToVector(upto, i + 1, j, k, answers, 2);
    // }
    // std::cout << i << " : " << j << " : " << k << " base case \n";
}

int main() {
    while (true) {
        int set_size;
        std::cout << "how many numbers should be in each set: ";
        std::cin >> set_size;
        std::vector<int> set;
        int number;
        std::cout << "how high should the numbers go within this set: ";
        std::cin >> number;
        std::map<std::string, std::vector<std::vector<int>>> ans;
        for (int i = 1; i <= set_size; ++i) {
            set.push_back(i);
        }

        addToVector(number, set, ans, 0);
        int number_of_solutions = 1;
        // std::cout << "how many solutions should exist for the scenario "
        //              "(type -1 to restart): ";
        // std::cin >> number_of_solutions;
        // std::cout << "\n";
        // while (number_of_solutions != -1) {
        int results = 0;
        int unique_elements = 0;
        for (const auto& entry : ans) {
            if (entry.second.size() >= number_of_solutions) {
                // std::cout << "Key: " << entry.first << ", Values: ";
                for (const std::vector<int> vec : entry.second) {
                    std::cout << "[ ";
                    for (const int& number : vec) {
                        std::cout << number << " ";
                    }
                    std::cout << "] ";
                    ++unique_elements;
                }
                ++results;
                std::cout << "\n";
            }
        }
        std::cout << "returned " << results << " results, containing "
                  << unique_elements
                  << " unique elements and each element contains at least "
                  << number_of_solutions << " unique elements\n\n";
        // std::cout << "how many solutions should exist for the scenario "
        //              "(type -1 to restart): ";
        // std::cin >> number_of_solutions;
        // std::cout << "\n";
    }
    // }
}
