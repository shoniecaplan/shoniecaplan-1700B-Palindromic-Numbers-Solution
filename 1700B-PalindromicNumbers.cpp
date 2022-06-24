/* ♥ ◦ ❀ ◦ ♥ ◦ ❀ |  shonie_caplan official  | ❀ ◦ ♥ ◦ ❀ ◦ ♥
♡ ◦ ❀ ◦ ♡ ◦ ❀ ◦ ♡   |  𝕾. 𝕮𝖆𝖕𝖑𝖆𝖓 .ᵒᶠᶠ  |   ♡ ◦ ❀ ◦ ♡ ◦ ❀ ◦ ♡
⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄
Codeforces Problem:
1700B Palindromic Numbers
⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄
Contact: shonie4caplan@gmail.com
Finished: 2022-06-24
⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄⑄
                                MAKING A PALINDROME EXPLAINED
  ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Making '99' with '63' takes two digits (36), but making '99' with '91' takes one digit (8).

**SO INPUT NUMBERS STARTING WITH A '9' MUST BE SEPARATED FROM OTHER INPUT NUMBERS**


ANY number that **DOESNT** start with a '9', is given a target number of all '9's. The length of the
target number is the same as the input number. This will guarantee that any input number that doesnt
start with a '9', can make a palindrome by adding a number with the same number of digits as the input.
ex:
(623) has 3 digits, so the target number is (999) <- has 3 digits ( 3 from input ).
┗━ (999 - 623) = 376  ->  376 has 3 digits, the same as the input (623), so this is correct.

(12)  has 2 digits, so the target number is (99)  <- has 2 digits ( 2 from input ).
┗━ (99 - 12) = 87     ->  87  has 2 digits, the same as the input (12) , so this is correct.



ANY number that STARTS with a '9', is given a target number of all '1's. The length of the
target number is one more than the as the input number.
This will ensure that ANY number beginning with a '9' can make a palindrome, while adding a value
that has the same number of digits as the input.
ex:
(971) has 3 digits, so the target number is (1111) <- has 4 digits ( (input = 3) + 1 ).
┗━ (1111 - 971) = 140  ->  140 has 3 digits, the same as the input (971), so this is correct.

(92)  has 2 digits, so the target number is (111)  <- has 3 digits ( (input = 2) + 1 ).
┗━ (111 - 92) = 19     ->  19  has 2 digits, the same as the input (92) , so this is correct.



As shown in the examples, after we have made the target number (palindrome), we perform:
( TARGET_NUMBER ) - ( INPUT_NUMBER ) = PRODUCT

The PRODUCT is then added to a vector of strings called 'allNumbers'. After all inputs have been processed,
we output all the elements of the 'allNumbers' vector.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define l long
#define lu unsigned long
#define ll long long
#define ull unsigned long long
#define ld long double
#define ar array
#define len(x) (int((x).length()))
#define a assert(false);

// Function to get the first element in a CHAR array, and return as INT.
int firstChar( string number ) {
  char fCHAR = number.front();
  int fINT = fCHAR - '0';
  return fINT;
}

/*
  Function to make the target number (for input numbers with starting digit '9').
  The function will make a string of '1's that is one digit longer than the input number.

  The reason I divide the size by two and check if its odd is to be able to add '1's to
  the string, in pairs of two.

  Adding the '1's in pairs of two, then adding an extra at the end if its odd, is much
  faster if we are making a very long target number.
*/
string make_FD9_Ones_STR( int num_of_dig ) {
  string fd9_TARGET_ONES_STRING;
  int sizeOf_FD9_TARGET_STR = num_of_dig + 1;
  int half_of_FD9_size = 0;
  bool half_of_FD9_is_ODD = false;

  if ( sizeOf_FD9_TARGET_STR % 2 == 0 ) {
    half_of_FD9_size = sizeOf_FD9_TARGET_STR / 2;

  } else {
    half_of_FD9_size = (sizeOf_FD9_TARGET_STR - 1) / 2;
    half_of_FD9_is_ODD = true;
  }

  // Speed up the process of making fd9_TARGET_ONES_STRING
  for ( int x=0; x < half_of_FD9_size; x++ ) {
    fd9_TARGET_ONES_STRING += "11";
  }
  if ( half_of_FD9_is_ODD == true ) {
    fd9_TARGET_ONES_STRING += "1";
  }
  return fd9_TARGET_ONES_STRING;
}

// Vector of strings to temporarily store all answers, before printing
vector <string> allNumbers;

int main() {

  cin.tie(&cout);

  int t = 0;
  cin >> t;

  while ( t-- ) {
    int numOfDigitsInCurInt = 0;

    cin >> numOfDigitsInCurInt;
    string currentNumberSTRING;
    string currentNumberCHANGE_STRING;

    bool numOfDIGITSisONE = false;
    string xyz;

    /*
      We use an extra 'getline' here, to get rid of the '\n' that comes after the number of testcases in the stream.
      The line terminator in the stream is saved to 'xyz', and is not used.
      An alternative to this is to use 'ignore()'.
    */
    getline(cin, xyz);
    getline(cin, currentNumberSTRING);

    if ( numOfDigitsInCurInt == 1 ) {
      cout << "0" << endl;
      numOfDIGITSisONE = true;
    }

    // Use the 'firstChar()' function to get the first digit of the input number, returned as INT.
    int firstDIGIT = firstChar( currentNumberSTRING );

    if ( numOfDIGITSisONE == false ) {

      if ( firstDIGIT == 9 ) {
        // Use the 'make_FD9_Ones_STR()' function to make the target number for an input starting with '9'.
        string target_FD9_STR = make_FD9_Ones_STR(numOfDigitsInCurInt);

        /*
          Add zero to the start of the input number to make the input number the same lenth as
          the target number (for inputs starting with a '9' is made one digit longer than the input number).
          This is to guarantee that numbers starting with a '9' are able to make a palindrome, while adding a
          number with the same number of digits.
          ( Making '99' with '63' takes two digits (36), but making '99' with '91' takes one digit (8), so
          input numbers starting with a '9' must be separated from other input numbers. )
        */
        currentNumberSTRING.insert(0, "0");

        vector <char> totalchange;

        int currentCHANGE_INT = 0;
        char currentCHANGE_CHAR;
        string currentCHANGE_STRING;

        string totalCHANGE_STRING;

        for ( int y=numOfDigitsInCurInt; y >= 0; y-- ) {
          // Save the current CHAR of the currentNumberSTRING, using 'y'
          char currentDIGIT_CHAR = currentNumberSTRING.at(y);

          // Convert CHAR -> INT
          int currentDIGIT_INT = currentDIGIT_CHAR - '0';

          if ( currentDIGIT_INT > (target_FD9_STR.at(y)-'0') ) {

            // Take '1' from the next place over, if the current digit is > than the current target digit
            target_FD9_STR.at(y-1) = ( (target_FD9_STR.at(y-1)-'0') -1 ) + '0';

            // Add the passed '1' to the current digit ( +10 )
            target_FD9_STR.at(y  ) = ( (target_FD9_STR.at(y  )-'0') +10) + '0';

            // After adding the passed 1, calculate the change needed to make the 'target number', then store as INT
            currentCHANGE_INT = (target_FD9_STR.at(y)-'0') - currentDIGIT_INT;

            /*
              Since we are subtracting from the back digit to the front digit, we want to remove the '0' we added
              to the front of the 'current number', in an earlier step.
              We added the '0' to the front of the input number to give it the same number of digits as the target
              number.
              Adding the zero to the front of the input was done to make using the target and input numbers easier,
              since we start from the last digit of each number.
            */
            if ( y != 0 ) {
              // Converting the integer into a string
              currentCHANGE_STRING = to_string(currentCHANGE_INT);
              // We are inserting the current change at the start of the string because the number is being read backwards.
              totalCHANGE_STRING.insert(0, currentCHANGE_STRING);
            }

          } else {
            // If the current input digit IS NOT greater than the current digit for the target number
            currentCHANGE_INT = (target_FD9_STR.at(y)-'0') - currentDIGIT_INT;


            /*
              Since we are subtracting from the back digit to the front digit, we want to remove the '0' we added
              to the front of the 'current number', in an earlier step.
              We added the '0' to the front of the input number to give it the same number of digits as the target
              number.
              Adding the zero to the front of the input was done to make using the target and input numbers easier,
              since we start from the last digit of each number.
            */
            if ( y != 0 ) {
              // Converting the integer into a string
              currentCHANGE_STRING = to_string(currentCHANGE_INT);
              // We are inserting the current change at the start of the string because the number is being read backwards.
              totalCHANGE_STRING.insert(0, currentCHANGE_STRING);
            }

          }
        }
        allNumbers.push_back(totalCHANGE_STRING);

      } else {

        for ( int x=0; x < numOfDigitsInCurInt; x++ ) {

          // Save the current CHAR of the currentNumberSTRING, using 'x'
          char currentDIGIT_CHAR = currentNumberSTRING.at(x);

          // Initialize
          int currentCHANGE_INT = 0;
          // Initialize
          int currentDIGIT_INT = 0;

          currentDIGIT_INT = currentDIGIT_CHAR - '0';

          // Get the amount needed to make 9, when added to the value we initially get
          currentCHANGE_INT = 9 - currentDIGIT_INT;

          // Convert the change needed to make 9, for the single digit, from INT to CHAR
          char currentCHANGE_CHAR = currentCHANGE_INT + '0';

          // Add the CHAR version of the amount you need to add to make 9, to the change STRING
          currentNumberCHANGE_STRING += currentCHANGE_CHAR;
        }
        allNumbers.push_back(currentNumberCHANGE_STRING);
      }
    }
  }

  // Output all the answers at once
  for ( string i: allNumbers ) {
    cout << i << '\n';
  }

  return(0);
}
