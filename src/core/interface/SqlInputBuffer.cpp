/*
 * SqlInputBuffer.cpp
 *
 *  Created on: Jul 4, 2023
 *      Author: mohamed
 */

#include <core/interface/SqlInputBuffer.h>

#include <utility>

using namespace core::interface;

SqlInputBuffer::SqlInputBuffer(std::string _input) : input(std::move(_input)) {}

SqlInputBuffer::~SqlInputBuffer() {}

void SqlInputBuffer::setInput(std::string inp) {
    this->input = std::move(inp);
}

std::string SqlInputBuffer::getInput() {
    return input;
}

