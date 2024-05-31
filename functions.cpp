#include "functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <regex>

// Function to clean text by removing punctuation and converting to lowercase
std::string cleanText(const std::string &text) {
    std::string cleaned;
    for (char ch : text) {
        if (std::isalnum(static_cast<unsigned char>(ch)) || std::isspace(static_cast<unsigned char>(ch))) {
            cleaned += std::tolower(static_cast<unsigned char>(ch));
        } else {
            cleaned += ' ';
        }
    }
    return cleaned;
}

// Function to count the frequency of words and record their occurrences by line
void function1(const std::string &input_file, const std::string &output_file_daznis, const std::string &output_file_eilutes_nr) {
    std::ifstream inputFile(input_file);
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open file " << input_file << std::endl;
        return;
    }

    std::map<std::string, int> wordCount;
    std::map<std::string, std::vector<int>> wordOccurrences;
    std::string line;
    int lineNumber = 0;

    while (std::getline(inputFile, line)) {
        lineNumber++;
        std::string cleanedLine = cleanText(line);
        std::istringstream iss(cleanedLine);
        std::string word;

        while (iss >> word) {
            if (!word.empty()) {
                wordCount[word]++;
                wordOccurrences[word].push_back(lineNumber);
            }
        }
    }

    inputFile.close();

    std::ofstream frequencyFile(output_file_daznis);
    if (!frequencyFile.is_open()) {
        std::cerr << "Unable to open file " << output_file_daznis << std::endl;
        return;
    }

    for (const auto &pair : wordCount) {
        if (pair.second > 1) {
            frequencyFile << pair.first << ": " << pair.second << std::endl;
        }
    }

    frequencyFile.close();

    std::ofstream occurrencesFile(output_file_eilutes_nr);
    if (!occurrencesFile.is_open()) {
        std::cerr << "Unable to open file " << output_file_eilutes_nr << std::endl;
        return;
    }

    for (const auto &pair : wordOccurrences) {
        if (pair.second.size() > 1) {
            occurrencesFile << pair.first << ": ";
            for (int line : pair.second) {
                occurrencesFile << line << " ";
            }
            occurrencesFile << std::endl;
        }
    }

    occurrencesFile.close();
}

// Function to find URLs in the text and output them to a file
void findURLs(const std::string &input_file, const std::string &output_file_url) {
    std::ifstream inputFile(input_file);
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open file " << input_file << std::endl;
        return;
    }

    std::string text((std::istreambuf_iterator<char>(inputFile)),
                     std::istreambuf_iterator<char>());
    inputFile.close();

    std::regex urlPattern(R"((https?://[^\s]+|www\.[^\s]+|\b\w+\.[a-z]{2,}\b))");
    std::sregex_iterator begin(text.begin(), text.end(), urlPattern), end;

    std::ofstream outputFile(output_file_url);
    if (!outputFile.is_open()) {
        std::cerr << "Unable to open file " << output_file_url << std::endl;
        return;
    }

    for (auto it = begin; it != end; ++it) {
        outputFile << it->str() << std::endl;
    }

    outputFile.close();
}
