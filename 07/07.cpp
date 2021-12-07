

#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

int main() {
    std::vector<int> positions;

    int x;
    while (std::cin >> x) {
        positions.push_back(x);
        std::cin.ignore(2, ',');
    }

    auto m = positions.begin() + positions.size()/2;
    std::nth_element(positions.begin(), m, positions.end());
    auto median = positions[positions.size()/2];

    int target = median;

    double cost = std::transform_reduce(positions.begin(), positions.end(), 0.0, std::plus<>(), [target](const int& a) -> double { return std::abs(a - target); });

    std::cout << "Move to " << target << std::endl;
    std::cout << "Cost: " << cost << std::endl;
}