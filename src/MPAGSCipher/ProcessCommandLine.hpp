#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP


#include <string>
#include <vector>


//Declaring transformChar function as compiler sees it called before function
bool processCommandLine(const std::vector<std::string>& cmdLineArgs,
        bool& helpRequested,
        bool& versionRequested,
        std::string& inputFileName,
        std::string& outputFileNameconst,
        size_t& key,
        bool& encrypt,
        bool& cipher_on);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP