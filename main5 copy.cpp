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
    // add counter
    //count = 0; // Counter for the number of triangles


    while (std::getline(file, line), ' ' ) // Add the counter condition && count <10
    {

        std::istringstream iss(line);
        Triangle triangle;
        std::string value;

        for (int i=0; i<3; i++)
        {
            if (i==0){
                // Read x, y, z for v1
                std::getline(iss, value, ',');
                triangle.v1.x = std::stold(value);
                std::getline(iss, value, ',');
                triangle.v1.y = std::stold(value);
                std::getline(iss, value, ',');
                triangle.v1.z = std::stold(value);
                //i++;
            }
            else if (i == 1){

                // Read x, y, z for v2
                std::getline(iss, value, ',');
                triangle.v2.x = std::stold(value);
                std::getline(iss, value, ',');
                triangle.v2.y = std::stold(value);
                std::getline(iss, value, ',');
                triangle.v2.z = std::stold(value);
                //i++;
            }
            else{

                // Read x, y, z for v3
                std::getline(iss, value, ',');
                triangle.v3.x = std::stold(value);
                std::getline(iss, value, ',');
                triangle.v3.y = std::stold(value);
                std::getline(iss, value, ',');
                triangle.v3.z = std::stold(value);

                //std::getline(iss, value, '\n');
            }

            //std::getline(iss, value, ' ');
        }

        triangles.push_back(triangle);
        //count++;

    }

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