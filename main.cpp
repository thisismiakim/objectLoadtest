#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

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
        iss >> triangle.v1.x >> triangle.v1.y >> triangle.v1.z
            >> triangle.v2.x >> triangle.v2.y >> triangle.v2.z
            >> triangle.v3.x >> triangle.v3.y >> triangle.v3.z;
        
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