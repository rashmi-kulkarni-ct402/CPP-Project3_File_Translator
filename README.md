# CPP-Project3 (File Translator)

## Overview

CPP-Project3_Translator is a C++ project aimed at facilitating the conversion of 3D model data between different file formats. Specifically, the project supports conversions between `.obj`, `.stl`, and `.txt` formats. This utility is particularly useful for those working in 3D modeling, computer graphics, and related fields where different file formats are often encountered.

## Features

The project provides the following conversion capabilities:

- Conversion of `.obj` files to `.txt` format.
- Conversion of `.obj` files to `.stl` format.
- Conversion of `.stl` files to `.txt` format.
- Conversion of `.stl` files to `.obj` format.

## Classes

The project consists of several classes, each serving a specific purpose in the file conversion process:

1. **FileTypeChecker**: This class is responsible for verifying whether the input file type is `.obj` or `.stl`.
2. **Point3D**: This class represents a 3D point with three coordinate variables (x, y, z).
3. **Triangle**: This class represents a triangle with three vertices.
4. **Triangulation**: This class stores unique points and triangles extracted from an input file.
5. **ObjReader**: This class is responsible for reading data from a `.obj` file.
6. **ObjWriter**: This class writes data to a `.txt` file from a `.obj` file.
7. **ObjToStlWriter**: This class writes data to a `.stl` file from a `.obj` file.
8. **StlReader**: This class reads data from a `.stl` file.
9. **StlWriter**: This class writes data to a `.txt` file from a `.stl` file.
10. **StlToObjWriter**: This class writes data to a `.obj` file from a `.stl` file.

## Usage

To utilize this project, include the appropriate header files in your main program and instantiate the required classes.
