
#include<iostream> // std::cout
#include<cstdint> // int64_t

#include"UserIO.h" // UserInput::Int(...)


// Function Prototypes (1) =============================================================================================

uint64_t Comb(unsigned int a_n, unsigned int a_r);


// Driver Code =========================================================================================================

int main()
{
    // Output description of program.
    std::cout << "This program calculates the mathematical formula nCr, which is the number of combinations, r, from n items.\n";
    std::cout << "\nTo quit the program, simply enter a negative number.\n\n";

    // Iterate until the user quits.
    while (true)
    {
        // Get n from user.
        int l_n = UserInput::Int("n: ", true);
        if (l_n < 0)
        { break; }
        
        // Get r from user.
        int l_r = UserInput::Int("r: ", true);
        if (l_r < 0)
        { break; }

        // Calculate nCr(l_n, l_r).
        uint64_t l_num_combs = Comb(l_n, l_r);

        // Output the result.
        std::cout << "nCr(" << l_n << ", " << l_r << ") = " << l_num_combs << "\n\n";
    }

}


// Auxiliaries (1) =====================================================================================================

/* Auxiliary of main
* This function returns the binomial coefficient associated with a_n and a_r: that is, it returns the number of
  combinations of a_r elements from a total of a_n elements.

* Parameters:
    > a_n: the total number of items.
    > a_r: the number of items which this program calculates the number of combinations of from a_n items.

* Notes:
    (a). This follows from the general equation of a combination, which can be seen at the following link:
         https://en.wikipedia.org/wiki/Combination#Number_of_k-combinations.
*/
uint64_t Comb(unsigned int a_n, unsigned int a_r)
{
    // Guard against a_k being greater than a_n (in which case there are 0 combs).
    if (a_r > a_n)
    { return 0; }

    // The number of combinations.
    uint64_t l_num_combs = 1;

    // Pick the lowest 'r' value (to make the program more efficient).
    unsigned int l_r = (a_r >= a_n - a_r) ? a_n - a_r : a_r;

    // (a). Calculate the number of combinations.
    for (unsigned int i = 1; i <= l_r; ++i)
    {
        l_num_combs *= a_n - l_r + i;
        l_num_combs /= i;
    }

    return l_num_combs;
}