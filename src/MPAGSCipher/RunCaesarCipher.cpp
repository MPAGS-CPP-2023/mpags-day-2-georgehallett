#include <string>
#include <RunCaesarCipher.hpp>

std::string runCaesarCipher(const std::string& inputText, size_t& key, const bool encrypt) {
    // Create the alphabet container and empty string
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string outputText = "";

    for (char c : inputText) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            size_t pos = alphabet.find(c);
            if (pos != std::string::npos) {
                // Apply the shift (positive or negative depending on encrypt)
                int shift = encrypt ? key : -static_cast<int>(key);
                // Handle potential wrap-around
                pos = (pos + shift) % 26;
                // Determine the new character and add it to the output string
                outputText += base + pos;
            } else {
                outputText += c; // Character not in the alphabet, keep it unchanged
            }
        } else {
            outputText += c; // Non-alphabetic character, keep it unchanged
        }
    }

    return outputText;
}