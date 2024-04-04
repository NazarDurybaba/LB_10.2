#include <fstream>
#include <string>
#include <iostream>
#include <Windows.h>

// Функція для вилучення тексту між дужками
std::string removeTextInBrackets(const std::string& str) {
    std::string result;
    int openBrackets = 0;

    for (char c : str) {
        if (c == '(') {
            openBrackets++;
        }
        else if (c == ')') {
            if (openBrackets > 0) {
                openBrackets--;
            }
        }
        else if (openBrackets == 0) {
            result += c;
        }
    }

    return result;
}

// Функція для копіювання файлу з вилученням тексту в дужках
void copyFileWithRemovedBrackets(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    std::string line;
    while (std::getline(inFile, line)) {
        outFile << removeTextInBrackets(line) << '\n';
    }
}

// Функція для виведення вмісту файлу
void printFileContent(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::cout << line << '\n';
    }
}

int main() {

    SetConsoleOutputCP(1251);
    std::cout << "Вміст файлу t1 перед обробкою:\n";
    printFileContent("t1.txt");

    copyFileWithRemovedBrackets("t1.txt", "t2.txt");

    std::cout << "\nВміст файлу t2 після обробки:\n";
    printFileContent("t2.txt");

    return 0;
}
