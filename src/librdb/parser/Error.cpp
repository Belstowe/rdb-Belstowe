#include "Error.hpp"

using rdb::parser::Error;
using rdb::parser::ErrorType;
using rdb::parser::Token;
using rdb::parser::TokenType;

Error::Error(Token token, ErrorType type, TokenType expected)
    : _token{token}, _type{type}, _expected{expected}
{
}

std::ostream& rdb::parser::operator<<(std::ostream& os, const Error& error) {
    os << "! " << error._token << ":\n";
    os << "  Error::" << error._type;
    if (error._expected != TokenType::Unknown) {
        os << " (expected " << error._expected << " )";
    }
    return os;
}

std::ostream& rdb::parser::operator<<(std::ostream& os, const ErrorType& error_type)
{
    switch (error_type) {
        case ErrorType::SyntaxError: os << "SyntaxError"; break;
        case ErrorType::VarSyntaxError: os << "VarSyntaxError"; break;
        case ErrorType::TypeSyntaxError: os << "TypeSyntaxError"; break;
        case ErrorType::IncorrectVarType: os << "IncorrectVarType"; break;
        case ErrorType::WrongColumnDefinition: os << "WrongColumnDefinition"; break;
        case ErrorType::NotStatement: os << "NotStatement"; break;
        case ErrorType::VarOutOfRange: os << "VarOutOfRange"; break;
        case ErrorType::UnknownType: os << "UnknownType"; break;
        case ErrorType::UnexpectedEOF: os << "UnexpectedEOF"; break;
        case ErrorType::Undefined: os << "Undefined"; break;
        default: os << static_cast<int>(error_type);
    }
    return os;
}