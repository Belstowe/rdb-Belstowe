#pragma once

#include "librdb/rdbtoken.hpp"
#include <initializer_list>
#include <string>
#include <variant>
#include <vector>

namespace rdb::parser {
    using Value = std::variant<long, double, std::string>;

    struct Operand {
        bool is_id;
        Value val;
    };

    typedef struct _column_def {
        std::string column_name;
        TokenType type_name;
    } ColumnDef;

    typedef struct _expression {
        Operand loperand;
        std::string operation;
        Operand roperand;
    } Expression;

    std::ostream& operator<<(std::ostream& os, const Expression& expression);

    class SqlStatement {
        public:
            virtual ~SqlStatement() = default;
            virtual void print(std::ostream& os) const = 0;
    };

    std::ostream& operator<<(std::ostream& os, const SqlStatement& statement);

    class CreateTableStatement : public SqlStatement {
        private:
            std::string _table_name;
            std::vector<ColumnDef> _column_def_seq;

        public:
            ~CreateTableStatement() = default;
            CreateTableStatement(std::string, std::vector<ColumnDef>);
            void print(std::ostream& os) const;
    };

    class InsertStatement : public SqlStatement {
        private:
            std::string _table_name;
            std::vector<std::string> _column_name_seq;
            std::vector<Value> _value_seq;

        public:
            ~InsertStatement() = default;
            InsertStatement(std::string, std::vector<std::string>, std::vector<Value>);
            void print(std::ostream& os) const;
    };

    class SelectStatement : public SqlStatement {
        private:
            std::string _table_name;
            std::vector<std::string> _column_name_seq;
            bool _has_expression_cond;
            Expression _expression;

        public:
            ~SelectStatement() = default;
            SelectStatement(std::string, std::vector<std::string>, Expression = Expression{0, "N", 0} );
            void print(std::ostream& os) const;
    };

    class DeleteFromStatement : public SqlStatement {
        private:
            std::string _table_name;
            bool _has_expression_cond;
            Expression _expression;

        public:
            ~DeleteFromStatement() = default;
            DeleteFromStatement(std::string, Expression = Expression{0, "N", 0} );
            void print(std::ostream& os) const;
    };

    class DropTableStatement : public SqlStatement {
        private:
            std::string _table_name;

        public:
            ~DropTableStatement() = default;
            DropTableStatement(std::string);
            void print(std::ostream& os) const;
    };
} // namespace rdb::parser