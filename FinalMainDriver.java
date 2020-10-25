
/**
 * FinalMainDriver.java
 * Brandyn Reynolds
 * CSC119 - Introduction to Programming
 *  
 * This program prompts the user to enter how many numbers they would like to sort into an array. 
 * Then using one pre-built quicksort and three full algorithms, the numbers are sorted and displayed,
 * unsorted and sorted, to the user. 
 * Overall, I built this program to be efficient and simple for the user and programmers to understand.
 */

import java.util.Arrays;
// Imports API method for Arrays for use throughout methods in printing. 
import java.util.Scanner;
// Imports API method for Scanner system.
public class FinalMainDriver
{
    public static void main (String[] args)
    {
        Scanner scan = new Scanner(System.in);        
        // Creates scan object for use throughout driver.
        FinalMethods link = new FinalMethods();        
        // Declaration of object used to link and call methods from the second class.
        char responseAnother = 'y';        
        // Declaration of character used within response to Do - While loop and if statement.
        char responseOopsAnother = 'y';
        // Declaration of character used within response to second Do - While loop for input validation and second if statement.
        System.out.println("Hello, and welcome. Please read the starting instructions, as well as the other instructions that pop up later on.");
        System.out.println("_______Starting Instructions_______");
        System.out.println("This program will have you enter numbers.\nThen, it will offer you four different ways to organize them.\nFinally, it will print both the sorted and unsorted numbers,\nalong with information regarding the sorting method that you choose.");
        // Greets and informs user of the program's purpose/function.
        do // Do - While performs fuction of repeating the program's core operations.
        {
            link.arrayFiller();
            // Calls method to fill array based on user inputted numbers
            System.out.println("Do you want to sort another list of numbers? (Y/N): ");
            // Prompts user to enter a char response to the question if they would like to repeat the program.
            responseAnother = scan.next().charAt(0);
            // Scans, stores, and grabs first letter of repsonse for either repeating or quiting the program.            
        } while (responseAnother == ('y') || responseAnother == ('Y'));
        // Char response with outputted instrucitons allows user to recall and repeat core program fuctions, while also clearing previous entries.
        if (responseAnother == ('n') || responseAnother == ('N'))
        {
            System.out.println("Goodbye, and thanks for using this program!");    
        }
        else if (responseAnother != ('y') || responseAnother != ('Y') || responseAnother != ('n') || responseAnother != ('N'))
        {
            System.out.println("Invalid Input. Do you want to sort another list of numbers? (Y/N): ");            
            do // Do - While performs fuction of repeating the program's core functions.
            {
                link.arrayFiller();
                // Calls method to fill array based on user inputted numbers
                System.out.println("Do you want to sort another list of numbers? (Y/N): ");
                // Prompts user to enter a char response to the question if they would like to repeat the program.
                responseOopsAnother = scan.next().charAt(0);
                // Scans, stores, and grabs first letter of repsonse for either repeating or quiting the program.            
            } while (responseOopsAnother == ('y') || responseOopsAnother == ('Y'));
            if (responseOopsAnother == ('n') || responseOopsAnother == ('N'))
            {
                System.out.println("Goodbye, and thanks for using this program!");    
            }
        }
    }
}
