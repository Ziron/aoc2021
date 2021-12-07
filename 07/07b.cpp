

#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

int main() {
    std::vector<int> positions;

    double sum = 0.0;
    int x;
    while (std::cin >> x) {
        positions.push_back(x);
        sum += x;
        std::cin.ignore(2, ',');
    }

    int avg = std::round(sum / positions.size());

    int target = avg; // Not correct!

    long long cost = std::transform_reduce(positions.begin(), positions.end(), 0.0, std::plus<>(), [target](const int& a) -> long long { 
        auto n = std::abs(a - target); 
        return (n + n*n) /2.0;
    });

    std::cout << "Move to " << target << std::endl;
    std::cout << "Cost: " << cost << std::endl;
}