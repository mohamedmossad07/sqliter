/*
 * Sqlnterface.h
 *
 *  Created on: Jul 4, 2023
 *      Author: mohamed
 */

#ifndef SRC_INCLUDE_CORE_INTERFACE_SQLNTERFACE_H_
#define SRC_INCLUDE_CORE_INTERFACE_SQLNTERFACE_H_

#include <core/interface/SqlInputBuffer.h>
#include <string>
#include <iostream>

namespace core::interface {
    class SqlInterface {
    public:
        SqlInterface() = delete;

        virtual ~SqlInterface() = delete;

        static SqlInputBuffer *acceptInput();

    private:
        static void printPrompt();
    };
}
#endif /* SRC_INCLUDE_CORE_SQLNTERFACE_H_ */
