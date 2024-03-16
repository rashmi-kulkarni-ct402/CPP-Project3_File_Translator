# CPP-Project3_Translator

This Project's purpose is to convert data from one file type to another
1. .obj to .txt
2. .obj to .stl
3. .stl to .txt
4. .stl to .obj

Classes:
1. FileTypeChecker - This class declared 2 functions that check if the input file type is of .obj or .stl 
2. Point3D - This class decares 3 member variables that represent 3 coordinates for a 3D point
3. Triangle- This class declares 3 member variables that represent 3 vertices of a triangle
4. Triangulation - This class declares 2 vectors
   a. vector<Point3D> mUniquePoints; --> for storing unique points from an input file type
   b. vector<Triangle> mTriangles; --> for storing vertices of a triangle
5. ObjReader - This class declares a member function to read data from a .obj file
6. ObjWriter - This class declares a member function to write data (that was read from a .obj file) to a .txt file
7. ObjToStlWriter - This class declares a member function to write data (that was read from a .obj file) to a .stl file
8. StlReader - This class declares a member function to read data from a .stl file
9. StlWriter - This class declares a member function to write data (that was read from a .stl file) to a .txt file
10. StlToObjWriter - This class declares a member function to write data (that was read from a .stl file) to a .obj file
