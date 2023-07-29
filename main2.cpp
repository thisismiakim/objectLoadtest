#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>


// this works
struct Vector3
{
    long double x, y, z;
};

struct Triangle
{
    Vector3 v1, v2, v3;
};

std::vector<Triangle> loadTriangles(const std::string& filename)
{
    std::vector<Triangle> triangles;
    std::ifstream file("object.txt");

    if (!file.is_open())
    {
        std::cout << "Failed to open the file." << std::endl;
        return triangles;
    }

    std::string line;
    while (std::getline(file, line))
    {

        std::istringstream iss(line);
        Triangle triangle;
        std::string value;


        // Read x, y, z for v1
        std::getline(iss, value, ',');
        triangle.v1.x = double(std::stold(value));
        
        std::getline(iss, value, ',');
        triangle.v1.y = std::stold(value);
        std::getline(iss, value, ',');
        triangle.v1.z = std::stold(value);

        // Read x, y, z for v2
        std::getline(iss, value, ',');
        triangle.v2.x = std::stold(value);
        std::getline(iss, value, ',');
        triangle.v2.y = std::stold(value);
        std::getline(iss, value, ',');
        triangle.v2.z = std::stold(value);

        // Read x, y, z for v3
        std::getline(iss, value, ',');
        triangle.v3.x = std::stold(value);
        std::getline(iss, value, ',');
        triangle.v3.y = std::stold(value);
        std::getline(iss, value);
        triangle.v3.z = std::stold(value);

        triangles.push_back(triangle);
    }

    return triangles;
}

int main()
{
    std::vector<Triangle> triangles = loadTriangles("triangles.txt");

    

    // Here you can manipulate the loaded data
    // For example, print the first triangle's first vertex
    if (!triangles.empty()) {
        std::cout << "First vertex of the first triangle: "
                  << triangles[0].v1.x << ", "
                  << triangles[0].v1.y << ", "
                  << triangles[0].v1.z << std::endl;
        std::cout << "Second vertex of the first triangle: "
                  << triangles[0].v2.x << ", "
                  << triangles[0].v2.y << ", "
                  << triangles[0].v2.z << std::endl;
    }


    return 0;
}