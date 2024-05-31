#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <algorithm> // Include for remove_if
#include <cctype>    // Include for ispunct

// Function to split a string into words
std::vector<std::string> splitIntoWords(const std::string& text) {
    std::vector<std::string> words;
    std::stringstream ss(text);
    std::string word;
    while (ss >> word) {
        // Remove punctuation from the word
        word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
        words.push_back(word);
    }
    return words;
}

int main() {
    // Sample text input
    std::string text = "This is a sample text with some sample words. This text also contains a URL: http://example.com.";

    // Create an associative container to count word frequencies
    std::unordered_map<std::string, int> wordCount;

    // Split the text into words
    std::vector<std::string> words = splitIntoWords(text);

    // Count the frequency of each word
    for (const std::string& word : words) {
        ++wordCount[word];
    }

    // Print the word frequencies
    std::cout << "Word Frequency:\n";
    for (const auto& pair : wordCount) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    // Simple way to find URLs (for educational purposes)
    std::unordered_map<std::string, int> urlCount;
    std::size_t pos = 0;
    while ((pos = text.find("http://", pos)) != std::string::npos) {
        std::size_t end = text.find(' ', pos);
        std::string url = text.substr(pos, end - pos);
        ++urlCount[url];
        pos = end;
    }

    // Print the URL frequencies
    std::cout << "\nURL Frequency:\n";
    for (const auto& pair : urlCount) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    return 0;
}
