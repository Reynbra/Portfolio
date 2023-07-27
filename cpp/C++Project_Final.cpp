//
#include <iostream>
#include <string>
using namespace std;

int main()
{
        char menuChoice;        //Initialization of menu choice input

        const int quit = 3;
        //Initialization of quit menu choice
        const int AA99trunc = 10;
        //Initialization of constant variable used if input is below 10 for AA99 Algorithm
        const int AA99notNegative = -1;
        //

        int AA99input;
        //Initialization of input used in first algorithum
        //int inputAA99LessThan10;
        //

        int truncResult;        //Trucated result for AA99
        int AA99tens,
            AA99result0,
            AA99forOnes,
            AA99ones,
            AA99reverseOnes,
            AA99reverse,
            AA99result1;

        int AA99result2;
        int AA99tens1;
        int AA99forOnes1;
        int AA99ones1;
        int AA99reverseOnes1;
        int AA99reverse1;
        int AA99finalResult;
        //Each result stored as a value to print out and use for each step.

        int A3input,
            A3result0,
            A3result1,
            A3result2,
            A3result3,
            A3finalResult;
        //Initialization of input and calculations used in A3 algorithum.

        char inputInvalid;
        char restartInput;
        //Initialization of input used for default input validation/restart.

       do
        {
                if (menuChoice != quit)
		{
                        //Beginning of Switch set with three options
                        cout << "\nPlease enter the corresponding number"
                        << " for the option you wish you to choose.\n";
                        cout << "\n1. Almost Always 99 algorithm\n";
                        //Print out Almost Always 99 option
                        cout << "\n2. Always 3 algorithm\n";
                        //Print out Always 3 option
                        cout << "\n3. Exit program\n";
                        //Print out Exit option
                        //Take user input and store as menuChoice variable
                        cin >> menuChoice;
                                //while (menuChoice < 1 || menuChoice > 3)
                                //{
                                //      cout << "\nSorry, that's not a valid input.\n
                                //      cin >> menuChoice;
                                //}

                                //if (menuChoice != quit)
                                //{
                                //}

                        switch (menuChoice)
                        {
                                //Case 1 - Almost Always 99 algorithm
                                case '1': if (menuChoice != quit)
                                          {
                                                cout << "Please enter an integer.\n";
                                                //Prompting user to input integer
                                                cin >> AA99input;
                                                //If/else if with trailing else ensures
                                                //AA99input is within 0 to 99 range
                                          }
                                          else if (AA99input < 0 || AA99input > 99)
                                          {
                                                cout << "\nSorry, that's not a"
                                                << "number between 0 and 99\n"
                                                << "\nPlease enter a number"
                                                << "between that range.\n" << endl;
                                                cin >> AA99input;
                                          }
                                          //If else ensures inputAA99 is less than 10,
                                          //it is multiplied by 10
                                          else if (AA99input < 10)
                                                AA99input = (AA99input * 10);
                                          else
                                          {     cout << "\nSorry, that's not a"
                                                << "valid input.\n"
                                                << "\nPlease enter a number"
                                                << "between that range.\n" << endl;
                                                cin >> AA99input;
                                          }

                                          AA99tens = AA99input / AA99trunc;
                                                //Division of prior variables with both as
                                                //integers so result is truncated
						 //Store trucated result as trucResult
                                          AA99forOnes = AA99tens * 10;
                                                cout << AA99forOnes << "\n";
                                          AA99ones = AA99input - AA99forOnes;
                                                cout << AA99ones << "\n";
                                          AA99reverseOnes = AA99ones * 10;
                                                cout << AA99reverseOnes << "\n";
                                          AA99reverse = AA99reverseOnes + AA99tens;
                                                cout << AA99reverse << "\n";
                                          AA99result1 = AA99input - AA99reverse;
                                          if (AA99result1 <= -1)
                                          {
                                                cout << "\nAA99result1 was negative.\n";
                                                AA99result1 = AA99result1 * AA99notNegative;
                                                cout << AA99result1 << "\n";
                                          }
                                          if (AA99result1 < 10)
                                          {
                                                cout << "\nAA99result1 was less than 10.\n";
                                                AA99result1 = AA99result1 * 10;
                                                cout << AA99result1 << "\n";
                                          }
                                          AA99tens1 = AA99result1 / AA99trunc;
                                                //Division of prior variables with both as
                                                //integers so result is truncated
                                                //Store trucated result as trucResult
                                          AA99forOnes1 = AA99tens1 * 10;
                                                cout << AA99forOnes1 << "\n";
                                          AA99ones1 = AA99result1 - AA99forOnes1;
                                                cout << AA99ones1 << "\n";
                                          AA99reverseOnes1 = AA99ones1 * 10;
                                                cout << AA99reverseOnes1 << "\n";
                                          AA99reverse1 = AA99reverseOnes1 + AA99tens1;
                                                cout << AA99reverse1 << "\n";
                                          AA99finalResult = AA99reverse1 + AA99result1;

                                          //if (A99

                                          if (AA99finalResult == 99)
                                                cout << "\nCongratulations!\n" << endl;
                                          else //(AA99FinalResult != 99)
                                                cout << "\nI may have done something wrong.\n" << endl;
                                break;
                                //Case 2 - Always 3 algorithm
                                case '2': cout << "\n(Please note, if you enter a number that is not an integer,"
                                        << "\n it will derived into an integer for the algorithum.)\n"
                                        << "\nPlease enter an integer which will be"
                                        << " mathematically transfered into 3.\n"
                                        << endl; //Prompting user to input integer
                                        cin >> A3input;

                                        //if (std::cin.fail())
                                        //{
                                        //      std::cout << "\nSorry, that's not a valid input.\n";
                                        //      std::cin.clear();
                                        //      std::cin >> A3input;
					 //      break;
                                        //}
                                        A3result0 = A3input * 2;
                                                cout << A3result0 << "\n";
                                        A3result1 = A3result0 + 9;
                                                cout << A3result1 << "\n";
                                        A3result2 = A3result1 - 3;
                                                cout << A3result2 << "\n";
                                        A3result3 = A3result2 / 2;
                                                cout << A3result3 << "\n";
                                        A3finalResult = A3result3 - A3input;
                                                cout << A3finalResult << "\n";
                                        if (A3finalResult != 3)
                                                cout << "\nI may have done something wrong.\n";
                                        else
                                                cout << "\nCongratulations!\n";
                                break;

                                //Case 3 exits Switch and program
                                case '3': cout << "\nThank you for trying this program. Goodbye!\n";
                                        return 0;
                                break;

                                //Default for Switch is input validation for case set choice
                                default: cout << "\n\tSorry, that's not a valid input.\n" << endl;
                                        //cout << "\nPlease enter Y if you would like to try again, N if you\n";
                                        //cout << "would like to quit the program.\n";
                                         //cin >> restartInput;
                                         //while (restartInput == 'y' && restartInput == 'Y')
                                         //{
                                         //     "Would you like to restart the program?\n";
                                         //     cin >> restartInput;

                                                //if(restartInput != 'y' && restartInput != 'Y')
                                                        //cout << "Please enter Y if you would like to try again,"
                                                        //<< " N if you\n"
                                                        //<< "would like to quit the program.\n";
                                                        //cin >> restartInput;
                        }
                }
        } while (menuChoice != 1 && menuChoice != 2 && menuChoice != 3 && menuChoice != quit);
          //Store choice as inputValid and evaluate, restart case or exit program
        return 0;
}



					


