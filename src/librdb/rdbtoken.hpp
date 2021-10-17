#pragma once

#include <string_view>

namespace rdb::parser {
class Token {
public:
    typedef enum TokenType {
        KwCreate,
        KwSelect,
        KwInsert,
        KwDelete,
        KwDrop,
        KwValues,
        KwTable,
        KwInt,
        KwReal,
        KwText,
        KwWhere,
        KwFrom,
        KwInto,
        VarInt,
        VarReal,
        VarText,
        VarId,
        Operation,
        CurlyBracketOpening,
        CurlyBracketClosing,
        ParenthesisOpening,
        ParenthesisClosing,
        Comma,
        Semicolon,
        EndOfFile,
        Unknown
    } TokenType;

    explicit Token(const Token::TokenType& = Unknown, const std::string& = "");
    Token::TokenType type_get();
    int type_set(const Token::TokenType&);
    std::string_view lexeme_get();
    int lexeme_set(std::string);

private:
    TokenType type;
    std::string lexeme;
};
}