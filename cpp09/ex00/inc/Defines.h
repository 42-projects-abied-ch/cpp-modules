#ifndef CONSTANTS_H
# define CONSTANTS_H

# define MIN_SIZE_INPUT 14
# define MIN_SIZE_DB 11
# define COMMA_POS 10
# define MINUS_POS1 4
# define MINUS_POS2 7
# define SPACE_POS1 10
# define PIPE_POS 11
# define SPACE_POS2 12
# define INPUT_VAL_POS 13
# define DB_VAL_POS 11
# define APRIL 4
# define JUNE 6
# define SEPTEMBER 9
# define NOVEMBER 11

# ifndef DATABASE
#  define DATABASE "database/data.csv"
# endif

# define DB_EXPECTED_HEADER "date,exchange_rate"
# define INPUT_EXPECTED_HEADER "date | value"
# define INPUT_INVALID_HEADER "input file header is invalid"
# define INPUT_FILE_OPEN "could not open input file"
# define DB_INVALID_HEADER "database header is invalid"
# define DB_NO_HEADER "database header is missing"
# define DB_EMPTY "database is empty"
# define DB_FILE_OPEN "could not open database"
# define DATE_IN_FUTURE "date is in the future"
# define DATE_TOO_EARLY "date is earlier than first one in database"
# define DATE_FORMAT_INVALID "invalid date format (YYYY-MM-DD)"
# define DATE_INVALID_CHAR "invalid character in date"
# define DAY_NOT_VALID "is not a valid day"
# define MONTH_NOT_VALID "is not a valid month"
# define NUM_INVALID "is not a valid number"
# define NUM_TOO_HIGH "number too high (max 1000)"
# define NUM_NEGATIVE "negative numbers are not supported"
# define INVALID_FORMAT "is not a valid input format"

#endif