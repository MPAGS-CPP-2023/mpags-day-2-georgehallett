#ifndef MPAGSCIPHER_RUNCAESARCIPHER_HPP
#define MPAGSCIPHER_RUNCAESARCIPHER_HPP


#include <string>
std::string runCaesarCipher(const std::string& inputText, size_t& key,
                            const bool encrypt);

#endif