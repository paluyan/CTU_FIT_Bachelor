/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 6/5/20
*/

#pragma once


#include <cstring>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>
#include <cctype>


class IOManager {
public:
    static void Print(const std::string &text) {
        std::cout << text << std::endl;
    }

    static void ClearWindow() {
        for (int i = 0; i < 20; ++i) {
            std::cout << "\n" << std::endl;
        }
    }

    static void PressToContinue() {
        IOManager::Print("\n\n\n\n\n\npress z to continue...");
        int c;
        while ((c = getchar()) != 'z');

        IOManager::ClearWindow();
    }

    static std::string Read() {
        std::string vRes;

        std::cout << ">> ";
        while (!(std::cin >> vRes)) {
            std::cin.clear();
        }
        return vRes;
    }
};




