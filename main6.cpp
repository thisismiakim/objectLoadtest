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
        int triangleCount = 0; 
        while (std::getline(file, line)) 
        {
            std::istringstream iss(line);
            Triangle triangle;
            char comma; // To discard the comma character

            // Read x, y, z for v1
            iss >> triangle.v1.x >> comma >> triangle.v1.y >> comma >> triangle.v1.z;
            
            // Read x, y, z for v2
            iss >> triangle.v2.x >> comma >> triangle.v2.y >> comma >> triangle.v2.z;
            
            // Read x, y, z for v3
            iss >> triangle.v3.x >> comma >> triangle.v3.y >> comma >> triangle.v3.z;

            triangles.push_back(triangle);
        }


    file.close();

    return triangles;
    
}

int main()
{
    int numTriangles = 10;
    std::vector<Triangle> triangles = loadTriangles("triangles.txt");


    // Here you can manipulate the loaded data
    // For example, print the first triangle's first vertex
    if (!triangles.empty()) {
        for (int i=0; i < numTriangles; i++){
                  std::cout << "First vertex of the " << i << " triangle: "
                  << triangles[i].v1.x << ", "
                  << triangles[i].v1.y << ", "
                  << triangles[i].v1.z << std::endl;
                  std::cout << "Second vertex of the " << i << " triangle: "
                  << triangles[i].v2.x << ", "
                  << triangles[i].v2.y << ", "
                  << triangles[i].v2.z << std::endl;
                  std::cout << "Third vertex of the " << i << " triangle: "
                  << triangles[i].v3.x << ", "
                  << triangles[i].v3.y << ", "
                  << triangles[i].v3.z << std::endl;
                  std::cout<<std::endl;
        }

    }


    return 0;
}