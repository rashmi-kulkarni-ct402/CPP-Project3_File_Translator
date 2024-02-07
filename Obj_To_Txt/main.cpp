#include <iostream>
#include "./headers/Triangulation.h"
#include "./headers/Triangle.h"
#include "./headers/ObjReader.h"
#include "./headers/ObjWriter.h"
#include "./headers/FileTypeChecker.h"

int main()
{
    std::string inputFilePath;
    std::cout << "Enter .obj filepath" << std::endl;
    std::cout << std::endl;
    std::cin >> inputFilePath;
    std::cout << std::endl;

    Shapes3D::FileTypeChecker checker;
    if (!checker.isObjFile(inputFilePath))
    {
        std::cout << "Error! Input file is not a .obj file." << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;
        return 1;
    }

    Shapes3D::Triangulation triangulationObj;
    Shapes3D::ObjReader objReader;
    Shapes3D::ObjWriter objWriter;
    std::string txtOutputFilePath = "resources/outputFiles/cube.txt";
    objReader.read(inputFilePath, triangulationObj);
    objWriter.write(txtOutputFilePath, triangulationObj);

    std::cout << "***************************************************" << std::endl;

    return 0;
}