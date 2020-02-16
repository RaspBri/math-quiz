
/*
 This program is a modular program that creates a ten question quiz over fraction addition,
 subtraction, multiplication, and division as selected by the user. The menu will display,
 Prompting the user for a char. The user inputs a char variable that will decipher which part
 of the program will run. If the user gives an incorrect answer the program will show the
 correct answer. After that, the program will run 10 questions for the user and tally
 the score. At the end the score will be displayed and the menu will show again.

 */

#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

const int MAX_VALUE = 10; // MAX constant for the randomNumbers function
const int MIN_VALUE = 1; // MIN constant for the randomNumbers function

void menuDisplay(bool &additionCase, bool &subtractionCase, bool &multiCase, bool &divCase, bool &quit, bool &invalid); // Menu display
void randomNumbers(int &num1, int &denom1, int &num2, int &denom2); // Generate numbers for math problem
int gcd(int, int); // Find greatest common divisor

void addFractions(int num1, int denom1, int num2, int denom2, int &resultNum, int &resultDenom); // Add fractions
void subFractions(int num1, int denom1, int num2, int denom2, int &resultNum, int &resultDenom); // Subtract fractions
void multiFractions(int num1, int denom1, int num2, int denom2, int &resultNum, int &resultDenom); // Multiply fractions
void divFractions(int num1, int denom1, int num2, int denom2, int &resultNum, int &resultDenom); // Divide fractions

void displayQuestion(int num1, int denom1, int num2, int denom2, int resultNum, int resultDenom, char type); // Displays question
bool checkAnswer(int &resultNum,int &resultDenom); // Checks user's answer
bool callProgram(); // Calls the program

int main() // Main calls the callProgram function to run
{
    bool reRun = true; // If still true the program will run again

    while(reRun == true)
    {
        reRun = callProgram();
    }

    cout << "Goodbye!" << endl; // Only displays once user decides to quit

   return 0;
} // End of main function.

/*
 This function will not return any values. It takes in the reference of additionCase, subtractionCase, multiCase,
 divCase, quit, and invalid as bool. All are preset to false, once the user inputs a valid response to the menu
 choice, the following choice is changed to true, while the remaining stay false. That value is reassigned,
 due to being a reference. Any input not expected will result in the invalid variable returning true to the main
 function, where it will be taken care of through there.
 */

void menuDisplay(bool &additionCase, bool &subtractionCase, bool &multiCase, bool &divCase, bool &quit, bool &invalid)
{
    // Reset each bool value when the menu is displayed.
    additionCase = false;
    subtractionCase = false;
    multiCase = false;
    divCase = false;
    quit = false;
    invalid = false;

    char choice; // Variable for switch case.

    // Menu

    cout << "Welcome to the fraction tutor!\n" << endl;
    cout << "\tA - Fraction Addition Quiz" << endl
         << "\tS - Fraction Subtraction Quiz" << endl
         << "\tM - Fraction Multiplication Quiz" << endl
         << "\tD - Fraction Division Quiz" << endl
         << "\tQ - Quit the program" << endl << endl;
    cout << "Enter the letter for your selection [A, S, M, D, Q]: "; // Prompt user for menu selection.
    cin >> choice;

    switch (toupper(choice)) // Menu selection switch case.
    {
        case 'A': // Addition case
            additionCase = true;
            break;
        case 'S': // Subtraction case
            subtractionCase = true;
            break;
        case 'M': // Multiplication case
            multiCase = true;
            break;
        case 'D': // Division Case
            divCase = true;
            break;
        case 'Q': // Quit Case
            quit = true;
            break;
        default: // Any other input = default
            invalid = true;
            cout << endl << "Invalid input. Enter either: A, S, M, D, or Q\n" << endl;
    }
} // End of menuDisplay function

/*
 This function does not return any variables. However, the
 function does reference num1, denom1, num2, and denom2 and
 randomizes those variables.
 */

void randomNumbers(int &num1, int &denom1, int &num2, int &denom2)
{
    unsigned seed = time(0);
    srand(seed);

    num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    denom1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

    num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    denom2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
} // End of randomNumbers function

/*
 This function will take in two integers and will return an integer
 back to its calling function. The function will process those two
 original integers and find the greatest common divisor between the
 both of them, and will return that value.
 */

int gcd(int numerator, int denominator)
{
    int divisor; // Assign variable

    do
    {
        divisor = denominator % numerator; // Assign value to divisor

        if(divisor != 0) // Continue until divisor == 0
        {
            denominator = numerator;
            numerator = divisor;
        }
    }
    while(divisor != 0); // End of do while loop

    return numerator;
} // End of gcd function.

/*
 This function takes in the input of all numerator/denominators, in addition to the reference of
 the numerator and denominator when added which gets assigned after the calculation. The return
 is void.
 */

void addFractions(int num1, int denom1, int num2, int denom2, int &resultNum, int &resultDenom)
{
    if(denom1 != denom2) // If the denominators are not equal
    {
        resultNum = ((num1 * denom2) + (denom1 * num2));
        resultDenom = (denom1 * denom2);
    }
    else
    {
        resultNum = num1 + num2;
        resultDenom = denom1;
    }

    int greatestDivisor = gcd(resultNum, resultDenom); // int value
    resultNum /= greatestDivisor; // Simplify numerator
    resultDenom /= greatestDivisor; // Simplify denom


} // End of addFractions function.

/*
This function takes in the input of all numerator/denominators, in addition to the reference of
the numerator and denominator, when subtracted, which gets assigned after the calculation.
 The return is void.
*/

void subFractions(int num1, int denom1, int num2, int denom2, int &resultNum, int &resultDenom)
{
    if(denom1 != denom2) // If the denominators are not equal
    {
        resultNum = (num1 * denom2) - (num2 * denom1);
        resultDenom = denom1 * denom2;
    }
    else
    {
        resultNum = num1 - num2;
        resultDenom = denom1;
    }
    int greatestDivisor = gcd(resultNum, resultDenom); // int value
    resultNum /= greatestDivisor; // Simplify numerator
    resultDenom /= greatestDivisor; // Simplify denom


} // End of subtraction function.

/*
This function takes in the input of all numerator/denominators, in addition to the reference of
the numerator and denominator, when multiplied, which gets assigned after the calculation.
 The return is void.
*/

void multiFractions(int num1, int denom1, int num2, int denom2, int &resultNum, int &resultDenom)
{
    if(denom1 != denom2) // If the denominators are not equal
    {
        resultNum = num1 * num2;
        resultDenom = denom1 * denom2;
    }
    else
    {
        resultNum = num1 * num2;
        resultDenom = denom1;
    }
    int greatestDivisor = gcd(resultNum, resultDenom); // int value
    resultNum /= greatestDivisor; // Simplify numerator
    resultDenom /= greatestDivisor; // Simplify denom

} // End of multiplication function.

/*
This function takes in the input of all numerator/denominators, in addition to the reference of
the numerator and denominator, when divided, which gets assigned after the calculation.
 The return is void.
*/

void divFractions(int num1, int denom1, int num2, int denom2, int &resultNum, int &resultDenom)
{
    if(denom1 != denom2) // If the denominators are not equal
    {
        resultNum = num1 * denom2;
        resultDenom = denom1 * num2;
    }
    else
    {
        resultNum = num1 / num2;
        resultDenom = denom1;
    }
    int greatestDivisor = gcd(resultNum, resultDenom); // int value
    resultNum /= greatestDivisor; // Simplify numerator
    resultDenom /= greatestDivisor; // Simplify denom

} // End of division function.

/*
 This function is void, however it takes in all numerator and denom variables, in addition to the
 reference of the numerator and denominator after calculations done. It also takes in the user's answer
 choice to know which display line is needed when prompted to display the question to the user.
 */

void displayQuestion(int num1, int denom1, int num2, int denom2, int resultNum, int resultDenom, char type)
{
   cout << setw(3) << num1 << setw(7) << num2 << endl; // Display numerators

    switch(type) // Determine which math sign to display
    {
        case 'A':
            cout << "---- + ----" << endl;
            break;
        case 'S':
            cout << "---- - ----" << endl;
            break;
        case 'M':
            cout << "---- * ----" << endl;
            break;
        case 'D':
            cout << "---- / ----" << endl;
            break;
    } // End of switch statement

    cout << setw(3) << denom1 << setw(7) << denom2 << endl; // Display denominators
} // End of displayQuestion function.

/*
 This function takes in the resultNum, resultDenom, and greatestDivisor
 variables and outputs a boolean value based off of the user's answer.
 The function will simplify the result of the fraction and return the
 reference variables to their calling function.
 */

bool checkAnswer(int &resultNum, int &resultDenom)
{
    // Assign Values.

    int userNum, userDenom;
    char character;
    bool answer;

    cout << "Enter your answer in the form numerator / denominator: ";

    cin >> userNum; // Prompt user for input.
    cin.get(character); // Read next character.

    while(character != '\n' && character != '/') // Look for a new line of '/'
    {
        cin.get(character);
    }

    if(character == '/') // Only prompt user for division if '/' is read
    {
        cin >> userDenom;
    }

    if(resultDenom < 0) // Convert to standard view.
    {
        resultNum *= -1;
        resultDenom *= -1;
    }

    if(userDenom < 0) // Convert to standard view.
    {
        userDenom *= -1;
        userNum *= -1;
    }

    if(character == '\n') // Read input given by user when number is over 1
    {
        if(userNum == resultNum && resultDenom == 1)
        {
            answer = true;
        }
        else
        {
            answer = false;
        }
    }

    if(userNum != resultNum || userDenom != resultDenom) // Check for false input
    {
        answer = false;
    }
    else // Default
    {
        answer = true;
    }
    return answer;
} // End of checkAnswer function.


/*
 This function is called by main and returns a bool variable back to main if the function is to runs again. If not,
 the program will end and return back to main with a farewell message. The function takes in no variables, but calls
 multiple functions, some of which take in variables, to quiz the user on simple math facts.
 */
bool callProgram()
{
    bool reRun = false;

    bool additionCase = false, subtractionCase = false, multiCase = false, divCase = false, quit = false, invalid = false; // Bool values for menuDisplay function
    int num1, num2, denom1, denom2; // Variables for randomNumbers function
    int resultNum, resultDenom; // Result variables for all void Fraction functions
    char type; // For display type in add, sub, div, multi choices


    int score = 0; // correct score count
    int runTime = 1; // # of loop count

    do // Run menuDisplay function.
    {
        menuDisplay(additionCase, subtractionCase, multiCase, divCase, quit, invalid);
    }
    while(invalid == true); // Continue to redisplay menuDisplay function until valid input is given.


    // Processing cases for which math questions to produce


    if(additionCase == true)
    {
        do
        {
            randomNumbers(num1, denom1, num2, denom2); // Generate random numbers for the following function
            addFractions(num1, denom1, num2, denom2, resultNum, resultDenom); // Calculate result


            cout << endl << "Question " << runTime << ": What is the result of the following?" << endl << endl; // Prompt question
            displayQuestion(num1, denom1, num2, denom2, resultNum, resultDenom, type = 'A'); // Function assigned case type A

            cout << endl;

            bool result = checkAnswer(resultNum, resultDenom); // Check user input with actual answer.
            if(result == true)
            {
                cout << endl << "That is correct!" << endl;
                score++;
            }
            else
            {
                cout << endl << "I am sorry, that is not correct." << endl << endl;
                cout << setw(3) << num1 << setw(7) << num2 << setw(7) << resultNum << endl;
                cout << "---- + ---- = ----" << endl;
                cout << setw(3) << denom1 << setw(7) << denom2 << setw(7) << resultDenom << endl << endl;
            }
            runTime++;
        }
        while(runTime <= 10);

        cout << "You got " << score << " out of " << --runTime << " correct." << endl; // Display Score
        if(score < runTime)
        {
            cout << "Keep practicing!" << endl << endl;
        }
        else
        {
            cout << "Great job!" << endl << endl;
        }
    } // End of addition if statement.

    else if(subtractionCase == true)
    {
        do
        {
            randomNumbers(num1, denom1, num2, denom2); // Generate random numbers for the following function
            subFractions(num1, denom1, num2, denom2, resultNum, resultDenom); // Calculate result

            cout << endl << "Question " << runTime << ": What is the result of the following?" << endl << endl; // Prompt question
            displayQuestion(num1, denom1, num2, denom2, resultNum, resultDenom, type = 'S'); // Function assigned case type S

            cout << endl;

            bool result = checkAnswer(resultNum, resultDenom); // Check user input with actual answer.
            if(result == true)
            {
                cout << endl << "That is correct!" << endl;
                score++;
            }
            else
            {
                cout << endl << "I am sorry, that is not correct." << endl << endl;
                cout << setw(3) << num1 << setw(7) << num2 << setw(7) << resultNum << endl;
                cout << "---- - ---- = ----" << endl;
                cout << setw(3) << denom1 << setw(7) << denom2 << setw(7) << resultDenom << endl;
            }
            runTime++;
        }
        while(runTime <= 10);

        cout << "You got " << score << " out of " << --runTime << " correct." << endl; // Display score.
        if(score < runTime)
        {
            cout << "Keep practicing!" << endl << endl;
        }
        else
        {
            cout << "Great job!" << endl << endl;
        }
    } // End of subtraction if statement.

    else if(multiCase == true)
    {
        do
        {
            randomNumbers(num1, denom1, num2, denom2); // Generate random numbers for the following function
            multiFractions(num1, denom1, num2, denom2, resultNum, resultDenom); // Calculate result

            cout << endl << "Question " << runTime << ": What is the result of the following?" << endl << endl; // Prompt question
            displayQuestion(num1, denom1, num2, denom2, resultNum, resultDenom, type = 'M'); // Function assigned case type M

            cout << endl;

            bool result = checkAnswer(resultNum, resultDenom); // Check user input with actual answer.
            if(result == true)
            {
                cout << endl << "That is correct!" << endl;
                score++;
            }
            else
            {
                cout << endl << "I am sorry, that is not correct." << endl << endl;
                cout << setw(3) << num1 << setw(7) << num2 << setw(7) << resultNum << endl;
                cout << "---- * ---- = ----" << endl;
                cout << setw(3) << denom1 << setw(7) << denom2 << setw(7) << resultDenom << endl;
            }
            runTime++;
        }
        while(runTime <= 10);

        cout << "You got " << score << " out of " << --runTime << " correct." << endl; // Display score.
        if(score < runTime)
        {
            cout << "Keep practicing!" << endl << endl;
        }
        else
        {
            cout << "Great job!" << endl << endl;
        }
    } // End of multiplication if statement.

    else if(divCase == true)
    {
        do
        {
            randomNumbers(num1, denom1, num2, denom2); // Generate random numbers for the following function
            divFractions(num1, denom1, num2, denom2, resultNum, resultDenom); // Calculate result

            cout << endl << "Question " << runTime << ": What is the result of the following?" << endl << endl; // Prompt question
            displayQuestion(num1, denom1, num2, denom2, resultNum, resultDenom, type = 'D'); // Function assigned case type D

            cout << endl;

            bool result = checkAnswer(resultNum, resultDenom); // Check user input with actual answer.
            if(result == true)
            {
                cout << endl << "That is correct!" << endl;
                score++;
            }
            else
            {
                cout << endl << "I am sorry, that is not correct." << endl << endl;
                cout << setw(3) << num1 << setw(7) << num2 << setw(7) << resultNum << endl;
                cout << "---- / ---- = ----" << endl;
                cout << setw(3) << denom1 << setw(7) << denom2 << setw(7) << resultDenom << endl;
            }
            runTime++;
        }
        while(runTime <= 10);

        cout << "You got " << score << " out of " << --runTime << " correct." << endl; // Display score.
        if(score < runTime)
        {
            cout << "Keep practicing!" << endl << endl;
        }
        else
        {
            cout << "Great job!" << endl << endl;
        }
    } // End of division if statement.

    if(quit == true) // Check if user has decided to quit program, if true return false to reRun bool.
    {
        reRun = false;
    }
    else // Otherwise, the program will continue to run as usual.
    {
        reRun = true;
    }

    return reRun; // Return the bool variable
}
