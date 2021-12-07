

#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

int main() {
    std::vector<int> positions;

    double sum = 0.0;

    int x;
    while (std::cin >> x) {
        std::cout << x;
        
        
        positions.push_back(x);
        sum += x;
    }

    double average = sum / positions.size();

    int target = static_cast<int>(std::round(average));

    double cost = std::transform_reduce(positions.begin(), positions.end(), 0.0, std::plus<>(), [target](const int& a) -> double { return std::abs(a - target); });
    
    double cost = target;

    std::cout << cost << std::endl;
}