#include <vector>
#include <string>
#include <cctype>
#include <iostream>
#include <sstream>
#include "ProcessCommandLine.hpp"

//Reading from command line function
bool processCommandLine(
        const std::vector<std::string>& cmdLineArgs,
        bool& helpRequested,
        bool& versionRequested,
        std::string& inputFileName,
        std::string& outputFileName,
        size_t& key,
        bool& encrypt,
        bool& cipher_on)
        {
        
        const std::size_t nCmdLineArgs{cmdLineArgs.size()};

        for (std::size_t i{1}; i < nCmdLineArgs; ++i) {
            if (cmdLineArgs[i] == "-h" || cmdLineArgs[i] == "--help") {
                helpRequested = true;

            } else if (cmdLineArgs[i] == "--version") {
                versionRequested = true;

            } else if (cmdLineArgs[i] == "-d"){
                encrypt = false;
                cipher_on = true;
            } else if (cmdLineArgs[i] == "-e") {
                encrypt = true;
                cipher_on = true;
            }
             else if (cmdLineArgs[i] == "-k") {
                    if (i == nCmdLineArgs - 1) {
                    std::cerr << "[Error] -k requires a key argument" << std::endl;
                    // exit main with non-zero return to indicate failure
                return false;
                } else {
                // Got filename, so assign value and advance past it
                std::stringstream sstream(cmdLineArgs[i + 1]);
                sstream >> key;
                ++i;
            }
            }else if (cmdLineArgs[i] == "-i") {
            // Handle input file option
            // Next element is filename unless "-i" is the last argument
                if (i == nCmdLineArgs - 1) {
                    std::cerr << "[Error] -i requires a filename argument" << std::endl;
                    // exit main with non-zero return to indicate failure
                return false;
                } else {
                // Got filename, so assign value and advance past it
                inputFileName = cmdLineArgs[i + 1];
                ++i;
            }
            } else if (cmdLineArgs[i] == "-o") {
            // Handle output file option
            // Next element is filename unless "-o" is the last argument
                if (i == nCmdLineArgs - 1) {
                    std::cerr << "[Error] -o requires a filename argument" << std::endl;
                    // exit main with non-zero return to indicate failure
                return false;
                } else {
                // Got filename, so assign value and advance past it
                outputFileName = cmdLineArgs[i + 1];
                ++i;
            }
            } else {
                // Have an unknown flag to output error message and return non-zero
                // exit status to indicate failure
                std::cerr << "[Error] unknown argument '" << cmdLineArgs[i] << "'\n";
            return false;
        }
    }
    return true;
}