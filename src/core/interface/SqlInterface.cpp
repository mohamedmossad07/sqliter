/*
 * Sqlnterface.cpp
 *
 *  Created on: Jul 4, 2023
 *      Author: mohamed
 */
#include <core/interface/SqlInterface.h>

using namespace core::interface;

SqlInputBuffer *SqlInterface::acceptInput() {
    SqlInterface::printPrompt();
    std::string input;
    std::getline(std::cin, input);
    return new SqlInputBuffer(input);
}

void SqlInterface::printPrompt() {
    printf("db > ");
}
