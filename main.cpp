#include <iostream>
#include "./headers/Triangulation.h"
#include "./headers/Triangle.h"
#include "./headers/ObjReader.h"
#include "./headers/ObjWriter.h"
#include "./headers/ObjToStlWriter.h"
#include "./headers/StlReader.h"
#include "./headers/StlWriter.h"
#include "./headers/StlToObjWriter.h"
#include "./headers/FileTypeChecker.h"

int main()
{
    int choice;
    do
    {
        std::cout << std::endl;
        std::cout << "Select conversion type from below menu" << std::endl;
        std::cout << "1. .obj to .txt conversion" << std::endl;
        std::cout << "2. .obj to .stl conversion" << std::endl;
        std::cout << "3. .stl to .txt conversion" << std::endl;
        std::cout << "4. .stl to .obj conversion" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "***************************************************" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << std::endl;

        std::string inputFilePath;
        Shapes3D::FileTypeChecker checker;

        switch (choice)
        {
        case 1:
        {
            std::cout << ".obj to .txt conversion" << std::endl
                      << endl;
            std::cout << "Enter .obj filepath" << endl;
            std::cin >> inputFilePath;
            std::cout << endl;

            if (!checker.isObjFile(inputFilePath))
            {
                std::cout << "Error! Input file is not a .obj file." << std::endl;
                std::cout << "***************************************************" << std::endl;
                return 1;
            }

            Shapes3D::Triangulation triangulationObj;
            Shapes3D::ObjReader objReader;
            Shapes3D::ObjWriter objWriter;
            std::string txtOutputFilePath = "resources/outputFiles/cubeOutputTxtFromObj.txt";
            objReader.read(inputFilePath, triangulationObj);
            objWriter.write(txtOutputFilePath, triangulationObj);

            std::cout << "***************************************************" << std::endl;
        }
        break;

        case 2:
        {
            std::cout << ".obj to .stl conversion" << std::endl
                      << endl;
            std::cout << "Enter .obj filepath" << endl;
            std::cin >> inputFilePath;
            std::cout << endl;

            if (!checker.isObjFile(inputFilePath))
            {
                std::cout << "Error! Input file is not a .obj file." << std::endl;
                std::cout << "***************************************************" << std::endl;
                return 1;
            }

            Shapes3D::Triangulation triangulationObj;
            Shapes3D::ObjReader objReader;
            Shapes3D::ObjToStlWriter objToStlWriter;
            std::string stlOutputFilePath = "resources/outputFiles/cubeOutputStl.stl";
            objReader.read(inputFilePath, triangulationObj);
            objToStlWriter.write(stlOutputFilePath, triangulationObj);

            std::cout << "***************************************************" << std::endl;
        }
        break;

        case 3:
        {
            std::cout << ".stl to .txt conversion" << std::endl
                      << endl;
            std::cout << "Enter .stl filepath" << endl;
            std::cin >> inputFilePath;
            std::cout << endl;

            if (!checker.isStlFile(inputFilePath))
            {
                std::cout << "Error! Input file is not a .stl file." << std::endl;
                std::cout << "***************************************************" << std::endl;
                return 1;
            }

            Shapes3D::Triangulation triangulationObj;
            Shapes3D::StlReader stlReader;
            Shapes3D::StlWriter stlWriter;
            std::string txtOutputFilePath = "resources/outputFiles/cubeOutputTxtFromStl.txt";
            stlReader.read(inputFilePath, triangulationObj);
            stlWriter.write(txtOutputFilePath, triangulationObj);

            std::cout << "***************************************************" << std::endl;
        }
        break;

        case 4:
        {
            std::cout << ".stl to .txt conversion" << std::endl
                      << endl;
            std::cout << "Enter .stl filepath" << endl;
            std::cin >> inputFilePath;
            std::cout << endl;

            if (!checker.isStlFile(inputFilePath))
            {
                std::cout << "Error! Input file is not a .stl file." << std::endl;
                std::cout << "***************************************************" << std::endl;
                return 1;
            }

            Shapes3D::Triangulation triangulationObj;
            Shapes3D::StlReader stlReader;
            Shapes3D::StlToObjWriter stlToObjWriter;
            std::string objOutputFilePath = "resources/outputFiles/cubeOutputObj.obj";
            stlReader.read(inputFilePath, triangulationObj);
            stlToObjWriter.write(objOutputFilePath, triangulationObj);

            std::cout << "***************************************************" << std::endl;
        }
        break;

        case 0:
        {
            std::cout << "Existed...Thank you!" << std::endl;
            std::cout << "***************************************************" << std::endl;
        }
        break;

        default:
        {
            std::cout << "Invalid choice, please try again!" << std::endl;
            std::cout << "---------------------------------------------------" << std::endl;
        }

        break;
        }

    } while (choice != 0);

    return 0;
}
