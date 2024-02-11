#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <cstddef>
# pragma once

# include <string>
# include <iostream>

typedef enum    e_dataType
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    _NAN,
    INF,
    NO_TYPE_FOUND,
    UNDEFINED
}   t_dataType;

class ScalarConverter
{
    private:

        std::string     input;
        e_dataType      dataType;
        bool            decimal;

        void            setType();

        bool            checkFloat(const size_t i);
        bool            checkValidDecimal(const int i);
        bool            checkChar();
        bool            checkNaN();
        bool            checkInf();

        void            printChar() const;
        void            printInt() const;
        void            printDouble() const;
        void            printFloat() const;
        void            printNotANumber() const;
        void            printInf() const;
        void            printNonSense() const;



    public:

        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator = (const ScalarConverter &other);
        ~ScalarConverter();

        std::string     getInput() const;
        e_dataType      getDataType() const;
        void            setInput(const std::string input);
        
        void            printConverted();
};

#endif