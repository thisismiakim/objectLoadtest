#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

struct Vector3D {
    double x, y, z;
};

int main() {
    std::fstream file("./object.txt"); // replace with your filename
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    std::vector<Vector3D> vectors;
    std::string line;
    while (std::getline(file, line, ' ')) {
        std::istringstream iss(line);
        Vector3D v;
        char comma; // to skip commas
        if (!(iss >> v.x >> comma >> v.y >> comma >> v.z)) {
            std::cerr << "Failed to parse a vector." << std::endl;
            return 1;
        }
        vectors.push_back(v);
    }

    file.close();

    // print out vectors
    for(const auto& v : vectors) {
        std::cout << "Vector: (" << v.x << ", " << v.y << ", " << v.z << ")\n";
    }

    return 0;
}