//
// Created by mohamed on 29/07/23.
//

#include <exceptions/ParserException.h>

namespace exceptions {
//    ParserException::ParserException(const Parser::location_type& loc,const std::string& msg)
//    {
//
//    }
    const char * ParserException::what() const noexcept{
        return msg.c_str();
    }

} // exceptions