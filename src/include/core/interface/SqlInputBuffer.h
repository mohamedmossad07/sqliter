/*
 * SqlInputBuffer.h
 *
 *  Created on: Jul 4, 2023
 *      Author: mohamed
 */

#ifndef SRC_INCLUDE_CORE_INTERFACE_SQLINPUTBUFFER_H_
#define SRC_INCLUDE_CORE_INTERFACE_SQLINPUTBUFFER_H_

#include <string>

namespace core::interface {
    class SqlInputBuffer {
    private:
        std::string input;

    public:
        explicit SqlInputBuffer(std::string input);

        virtual ~SqlInputBuffer();

        void setInput(std::string input);

        std::string getInput();
    };
}

#endif /* SRC_INCLUDE_CORE_INTERFACE_SQLINPUTBUFFER_H_ */
