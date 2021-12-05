//
// Created by Adrian on 12/1/2021.
//

#ifndef C___FILEREADER_H
#define C___FILEREADER_H

#include <fstream>
#include <vector>
#include <string>

#include <iostream>
namespace aoc {
    class fileReader {
    public:
        explicit fileReader(::std::ifstream &inputStream) {
            _inputStream = &inputStream;
        }

        template<class T>
        std::vector<T> readAs() {
            T tmp = 0;
            ::std::vector<T> result;
            while (*_inputStream >> tmp) {
                result.push_back(tmp);
            }
            return result;
        }

        std::vector<std::string> readLines() {
            std::string tmp;
            std::vector<std::string> result;
            while (getline(*_inputStream, tmp)) {
                result.push_back(tmp);
            }
            return result;
        }

        std::vector<int> readNumbers(std::string line, std::string separator) {
            std::string number = "";
            std::vector<int> result;
            for (auto letter:line) {
                if (separator.find(letter)==std::string::npos) {
                    //std::cout<<letter<<"\n";
                    number += letter;
                } else if (number != "") {
                    result.push_back(std::atoi(number.c_str()));
                    number = "";
                }
            }
            if (number != "") {
                result.push_back(std::atoi(number.c_str()));
            }
            return result;
        }

    private:
        std::ifstream *_inputStream;
    };
}


#endif //C___FILEREADER_H
