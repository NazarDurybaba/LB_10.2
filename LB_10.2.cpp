#include <fstream>
#include <string>
#include <iostream>
#include <Windows.h>

// ������� ��� ��������� ������ �� �������
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

// ������� ��� ��������� ����� � ���������� ������ � ������
void copyFileWithRemovedBrackets(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    std::string line;
    while (std::getline(inFile, line)) {
        outFile << removeTextInBrackets(line) << '\n';
    }
}

// ������� ��� ��������� ����� �����
void printFileContent(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::cout << line << '\n';
    }
}

int main() {

    SetConsoleOutputCP(1251);
    std::cout << "���� ����� t1 ����� ��������:\n";
    printFileContent("t1.txt");

    copyFileWithRemovedBrackets("t1.txt", "t2.txt");

    std::cout << "\n���� ����� t2 ���� �������:\n";
    printFileContent("t2.txt");

    return 0;
}
