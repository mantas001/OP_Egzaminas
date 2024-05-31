#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <map>
#include <vector>

// Function to clean text by removing punctuation and converting to lowercase
std::string cleanText(const std::string &text);

// Function to count the frequency of words and record their occurrences by line
void function1(const std::string &input_file, const std::string &output_file_daznis, const std::string &output_file_eilutes_nr);

// Function to find URLs in the text and output them to a file
void findURLs(const std::string &input_file, const std::string &output_file_url);

#endif // FUNCTIONS_H
