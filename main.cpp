#include <iostream>
#include "functions.h"

int main() {
    const std::string input_file = "tekstas.txt";
    const std::string output_file_daznis = "zodziu_daznis.txt";
    const std::string output_file_eilutes_nr = "zodziu_eilutes.txt";
    const std::string output_file_url = "adresai.txt";

    function1(input_file, output_file_daznis, output_file_eilutes_nr);
    findURLs(input_file, output_file_url);

    std::cout << "Isvesties failai: " 
              << output_file_daznis << ", " 
              << output_file_eilutes_nr << ", and " 
              << output_file_url << std::endl;

    return 0;
}
