#include <iostream>
#include <fstream>
#include <cstring> // For std::strcpy
#include <string>

// char* readFile(std::string filePath) {
//     // File name (can be changed to the actual file path)
//     // const char* fileName = "example.txt";

//     // Create an input file stream
//     std::ifstream fileStream(filePath, std::ios::in | std::ios::binary | std::ios::ate);

//     // Check if the file was successfully opened
//     if (!fileStream) {
//         std::cerr << "Unable to open file " << filePath << std::endl;
//         return NULL; // Exit with error code
//     }

//     // Determine the size of the file
//     std::streampos fileSize = fileStream.tellg();
//     fileStream.seekg(0, std::ios::beg);

//     // Allocate memory for the file contents
//     char* fileContents = new char[static_cast<std::size_t>(fileSize) + 1]; // +1 for the null terminator

//     // Read the file contents into the allocated memory
//     fileStream.read(fileContents, fileSize);

//     // Null-terminate the string
//     fileContents[fileSize] = '\0';

//     // Close the file stream
//     fileStream.close();

//     // Output the file contents (optional)
//     // std::cout << "File contents:\n" << fileContents << std::endl;

//     // Clean up: delete the allocated memory
//     return fileContents;
// }

char* readFile(const std::string& fileName) {
    // Create an input file stream
    std::ifstream fileStream(fileName, std::ios::in | std::ios::binary | std::ios::ate);

    // Check if the file was successfully opened
    if (!fileStream) {
        std::cerr << "Unable to open file " << fileName << std::endl;
        return nullptr; // Return null pointer on failure
    }

    // Determine the size of the file
    std::streampos fileSize = fileStream.tellg();
    fileStream.seekg(0, std::ios::beg);

    // Allocate memory for the file contents
    char* fileContents = new char[static_cast<std::size_t>(fileSize) + 1]; // +1 for the null terminator

    // Read the file contents into the allocated memory
    fileStream.read(fileContents, fileSize);

    // Null-terminate the string
    fileContents[fileSize] = '\0';

    // Close the file stream
    fileStream.close();

    return fileContents;
}

// int main()
// {
//     char* file = readFile("../bin/assets/shaders/shader.vert");
//     std::cout << file << std::endl;
//     return 0;
// }