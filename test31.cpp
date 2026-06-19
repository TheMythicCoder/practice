#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Coordinate {
    int x;
    int y;
};

struct CoordinateCompare {
    bool operator()(Coordinate const &a, Coordinate const &b) const {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    }
};

std::ostream &operator<<(std::ostream &os, Coordinate const &coord) {
    return os << "(" << coord.x << ", " << coord.y << ")";
}

int main() {
    std::map<Coordinate, std::vector<std::string>, CoordinateCompare> orderedRoutes;

    orderedRoutes[{1, 2}] = {"alpha", "beta"};
    orderedRoutes[{0, 0}] = {"origin"};
    orderedRoutes[{1, 1}] = {"one-one", "start"};
    orderedRoutes[{2, 2}] = {"delta"};

    orderedRoutes[{1, 1}].push_back("extra");

    std::cout << "Ordered map contents:\n";
    for (auto const &entry : orderedRoutes) {
        std::cout << entry.first << ": ";
        for (auto const &label : entry.second) {
            std::cout << label << " ";
        }
        std::cout << '\n';
    }

    Coordinate query{1, 1};
    auto it = orderedRoutes.find(query);
    if (it != orderedRoutes.end()) {
        std::cout << "\nFound key " << it->first << " with values: ";
        for (auto const &value : it->second) {
            std::cout << value << " ";
        }
        std::cout << '\n';
    }

    std::cout << "\nKeys in sorted order: ";
    for (auto const &entry : orderedRoutes) {
        std::cout << entry.first << " ";
    }
    std::cout << '\n';

    return 0;
}
