#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//Our project headers
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "RunCaesarCipher.hpp"

// Function to transform a character and return the result as a string
int main(int argc, char* argv[]){

    const std::vector<std::string> cmdLineArgs{argv, argv + argc};
    bool helpRequested{false};
    bool versionRequested{false};
    std::string inputFile{""};
    std::string outputFile{""};
    bool encrypt{true};
    size_t key{5};
    bool cipher_on{false};

    //Pass through processCommandLine function (/src/MPAGSCipher)
    bool process_successful { processCommandLine( cmdLineArgs, helpRequested, versionRequested, inputFile, outputFile, key, encrypt, cipher_on)};
    //Return error if false is returned
    if (process_successful != true){
        std::cerr << "Error - Unsuccessful Command Line" << std::endl;
        return 1;
    }

    // Handle help, if requested
    if (helpRequested) {
        // Line splitting for readability
        std::cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << "  -d Decryption    Decrypt input\n\n"
            << "  -e Encryption    Encrypt input\n\n"
            << "  -k Key           Supply chosen key default 5\n\n"
            << std::endl;
        // Help requires no further action, so return from main
        // with 0 used to indicate success
        return 0;
    }

    // Handle version, if requested
    if (versionRequested) {
        std::cout << "0.1.0" << std::endl;
        return 0;
    }

    // Initialise variables
    char inputChar{'x'};
    std::string inputText;
    std::string outputText;
    std::ifstream in_file;
    std::ofstream out_file;

    // Read in user input from stdin/file
    // Warn that input file option not yet implemented
    if (!inputFile.empty()) {
        in_file.open(inputFile);
        bool ok_to_read = in_file.good();
        if (!ok_to_read){
            std::cerr << "[Warning] input from file ('" << inputFile
                      << "') not implemented yet, remove -i and type letters in for command line interface.\n"
                      << std::endl;
            return 1;
        }
        // loop over each character from user input
        while (in_file >> inputChar) {
        inputText += transformChar(inputChar);
        }
        in_file.close();
    } else {
        while (std::cin >> inputChar){
            inputText += transformChar(inputChar);
        }
    }
    if (cipher_on == true){
    outputText = runCaesarCipher(inputText, key, encrypt);
    }
    else{
        outputText = inputText;
    }

    // Warn that output file option not yet implemented
    if (!outputFile.empty()) {
        out_file.open(outputFile);
        bool ok_to_write = out_file.good();
        if (!ok_to_write){
        std::cerr << "[Warning] output to file ('" << outputFile
                  << "') not implemented yet, remove -o and letters will print in command line interface.\n" << std::endl;
        return 1;
        }

    out_file << outputText << std::endl;
    out_file.close();
    } else {
        std::cout << outputText << std::endl;
    }

    return 0;
}