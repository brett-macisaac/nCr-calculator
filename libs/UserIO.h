#pragma once

#ifdef USERIO_DLL_EXPORTS
#define USERIO_DLL_API __declspec(dllexport)
#else
#define USERIO_DLL_API __declspec(dllimport)
#endif


//#include<iostream>
#include<string>
#include<sstream>
#include<vector>


namespace UserInput
{
    /*
    * This function returns a character entered by a user.
    * It only returns once the user has entered a character that is considered 'valid'.

    * Parameters:
        > a_valid_chars: a string containing all of the characters that are considered 'valid'. e.g. "12345" would be
                         the valid command if the user had to enter a number between 1 and 5.
    */
    USERIO_DLL_API char Char(const std::string& a_valid_chars, bool a_display_error_msgs = true, const std::string& a_prompt = "Enter a command: ");

    /*
    * This function returns a character entered by a user.
    * It only returns once the user has entered a character that is considered 'valid'.

    * Parameters:
        > a_valid_chars: a string containing all of the characters that are considered 'valid'. e.g. "12345" would be
                         the valid command if the user had to enter a number between 1 and 5.
    */
    USERIO_DLL_API char Char(const char* a_valid_chars, bool a_display_error_msgs = true, const std::string& a_prompt = "Enter a command: ");

    /*
    * This function returns a character entered by a user,

    * Parameters:
        > a_valid_chars: a string containing all of the characters that are considered 'valid'. e.g. "12345" would be
                         the valid command if the user had to enter a number between 1 and 5.
    */
    USERIO_DLL_API char Char(bool a_display_error_msgs = true, const std::string& a_prompt = "Enter a command: ");

    /*
    * This function returns an integer between given bounds entered by the user.

    * Parameters:
        > a_low: the lower bound (inclusive).
        > a_high: the upper bound (inclusive).
    */
    USERIO_DLL_API int Int(int a_low, int a_high, const std::string& a_prompt = "Enter an integer: ", bool a_display_error_msgs = true);

    /*
    * This function returns an integer entered by a user.
    */
    USERIO_DLL_API int Int(const std::string& a_prompt = "Enter an integer: ", bool a_display_error_msgs = true);

    /*
    * This function 'pauses' the program's execution until the user presses enter.
    * NOTE: this function assumes that the standard input buffer doesn't have a '\n' character in it prior to the
            function being called.
    */
    USERIO_DLL_API void PressEnterToContinue(bool l_prompt = true);
}


/*
* This namespace intends to help users create appealing and organised console UIs.

* Ideas:
    > Put the 'Indent' class in here (maybe just call it 'Indent').

* Composition:
    > Functions: 1
    > Classes: 0
*/
namespace UserOutput
{

    // Enumerations (1) ====================================================================================================

    enum class Alignment
    {
        Left,
        Centre,
        Right
    };


    // Functions (1) =======================================================================================================

        /*
        *

        * Parameters:
            > a_rows: the data that is to be outputted in tabular format. Each element contains the data of one row of the
                      table.
        */
    USERIO_DLL_API void TabulariseRows(std::ostream& a_ostream, const std::vector<std::vector<std::string>>& a_rows, int a_margin = 1,
        unsigned int a_length_pause_rows = 0, Alignment a_align_row = Alignment::Left,
        Alignment a_align_header = Alignment::Centre, char a_table_corner = '#', char a_table_row = '-',
        char a_table_column = '|', char a_table_fill = ' ');

    /*
    *

    * Parameters:
        > a_rows: the data that is to be outputted in tabular format. Each element contains the data of one column of
                  the table.
    */
    USERIO_DLL_API void TabulariseCols(std::ostream& a_ostream, const std::vector<std::vector<std::string>>& a_cols,
        int a_margin = 1, unsigned int a_length_pause_rows = 0,
        Alignment a_align_row = Alignment::Left, Alignment a_align_header = Alignment::Centre,
        char a_table_corner = '#', char a_table_row = '-', char a_table_column = '|',
        char a_table_fill = ' ');

    /*
    * This function pauses the program's execution for (at least) a_n_ms milliseconds.
    * It's particularly useful for pausing to let a user comfortably take in information, which is especially relevant
      for many text-based games.
    */
    USERIO_DLL_API void PauseFor(int a_n_ms);

    USERIO_DLL_API void OutputHeader(const std::string& a_title, char a_char_bottom = '=', unsigned int a_size_bottom = 120,
                                     char a_char_mid = '=', unsigned int a_size_mid = 2, char a_char_top = '=', 
                                     unsigned int a_size_top = 120, unsigned int a_spacing = 2);


    // Classes (1) =========================================================================================================

        /* Indentation Class
        * An object of this class can be used to conveniently add indentation to standard output.
        * This class is a Singleton because in practically every scenario a text-based program only requires a single
          object to handle indentation. The use of this design pattern means that Indent objects don't have to be
          passed around between objects; rather, every class that requires the indentation of output can simply be given a
          pointer to a single Indent object.

        * Class Composition:
            > Fields (6)
                - Static Fields (2)
            > Constructors (1)
            > Public Methods (5)
                - Accessors (1)
                - Mutators (4)
            > Operators (4)
        */
    class USERIO_DLL_API Indent
    {

    private:

    // Fields (6) ======================================================================================================

        /*
        * The size of the indentation.
        * A standard size is 4.
        */
        unsigned int f_indent_size;

        /*
        * The number of indents.
        */
        unsigned int f_num_indents;

        /*
         * The maximum number of indents.
        */
        unsigned int f_max_num_indents;

        /*
        * The indentation character.
        * This is typically a space (i.e. ' ').
        */
        char f_indent_character;

        /*
        * The number of new-lines to output when the f_newline flag is set.
        */
        unsigned int f_num_newlines;

        /*
        * The number of indents to change after the next indentation (see the () operator).
        */
        int f_num_change_post_output;


        // Static Fields (2) -----------------------------------------------------------------------------------------------

            /*
            * The maximum value of f_indent_size.
            */
        static const int S_MAX_INDENT_SIZE = 10;


        // Constructors (1) ================================================================================================

        Indent();

    public:

        // Public Methods (5) ==============================================================================================


        // Accessors (1) ---------------------------------------------------------------------------------------------------

            /* Accessor of s_instance
            * Returns the pointer s_instance, which points to the (only) Indent object.
            */
        static Indent* GetInstance();

        /* Accessor of f_num_indents
        */
        unsigned int GetIndentation() const;


        // Mutators (4) ----------------------------------------------------------------------------------------------------

            /* Mutator of f_indent_size
            */
        void SetIndentSize(unsigned int a_indent_size);

        /* Mutator of f_num_indents
        */
        void SetIndentation(unsigned int a_num_indents);

        /* Mutator of f_max_num_indents
        */
        void SetMaxNumIndents(unsigned int a_max_num_indents);

        /* Mutator of f_indent_character
        */
        void SetIndentChar(unsigned int a_indent_character);

        /* Mutator of f_newline, f_num_newlines
        */
        Indent& SetNewline(unsigned int a_num_newlines = 1);


        // Operators (4) ===================================================================================================

            /* ++ (prefix increment) operator
            * Increases the number of indents by one (if possible).
            */
        Indent& operator++();

        /* ++ (postfix increment) operator
        * Increases the number of indents by one (if possible). Unlike the prefix variant, this ensure that the
          increment to f_num_indents only occurs after the next indentation.
        */
        Indent& operator++(int);

        /* -- (prefix decrement) operator
        * Reduces the number of indents by one (if possible).
        */
        Indent& operator--();

        /* -- (postfix decrement) operator
        * Reduces the number of indents by one (if possible). Unlike the prefix variant, this ensure that the decrement
          to f_num_indents only occurs after the next indentation.
        */
        Indent& operator--(int);

        /* [] (indexer) operator
        * This operator changes the current number of indents (f_num_indents) by the amount of the given parameter.
        */
        Indent& operator[](int a_num_change);

        /* () (call) operator
        * This operator can be thought of as a 'post-fix' version of operator[]: i.e. it results in a change to
          f_num_indents according to the given parameter, but this change only occurs until after the next indent is
          outputted.
        * This could be useful if the last line of an output sequence is indented, but you want the indentation to be
          reduced once the sequence is complete.
        */
        Indent& operator()(int a_num_change);

        /* << (standard output) operator
        */
        __declspec(dllexport) friend std::ostream& operator<<(std::ostream& a_ostream, Indent& a_indent);

        // As this class is a singleton, it shouldn't be copyable or assignable.
        Indent(const Indent& a_instance) = delete;
        void operator=(const Indent& a_instance) = delete;
    };

}
