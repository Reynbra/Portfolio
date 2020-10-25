
/**
 * FinalMethods.java
 * Brandyn Reynolds
 * CSC119 - Introduction to Programming
 *  
 * This class holds the methods necessary for the input, sorting, and output processes of the user filled array.
 * Essentially, it does the heavy lifting for the small and simple driver.
 */
import java.lang.*;
import java.util.Arrays;
// Imports API method for Arrays for use throughout methods in printing. 
import java.util.Scanner;
// Imports API method for Scanner system.
public class FinalMethods
{
    Scanner scan = new Scanner(System.in);
    // Creates scan object for use throughout methods.
    int amountOfNumbers = 0;
    // Declares integer to avoid compilation error when used in methods below.
    double numArray[];
    // Declares array for user inputted numbers without initialized amount of memory allocations.
    String sortChoice = "";
    // Declares container for user input when determing sort choice.
    long startTime, endTime, sortTime;
    // Declares variables for use in tracking the amount of time the algorithms take to transpire.
    //***************************************************************************************************************************************************************
    
    // This method is called from the driver to create an array, allocate spaces based on user inputted amount, then fills the array for sorting processes. 
    
    public void arrayFiller()
    {
        char responseOops = 'y';
        // Declaration of char for use in repetition of filling array in case the user made a mistake when entering numbers.
        do // Do - While for repetition in filling array if the user made a mistake in entering numbers.
        {
            System.out.println("How many numbers would you like to sort? ");
            // Prompts user to enter the number they would like to sort.
            while (!(scan.hasNextInt()))
            {
                System.out.println("Invalid Input. Please enter a whole number value for the amount of numbers you would like to sort: ");
                // If input is invalid, this message is printed to provide user with instructions once more.
                scan.next();     
                // Scans and uses next input to return to program function.
            } 
            int amountOfNumbers = scan.nextInt();
            // Stores the user's integer as a variable for use in array initialization.
            numArray = new double[amountOfNumbers];
            // Initilizes String array and allocates spaces for the names based on user inputted integer.
            for (int i = 0; i < amountOfNumbers; i++)
            {
                System.out.println("Please enter a number you would like to sort: ");
                // Prompts user repeatedly to fill the array by entering unsorted numbers until the allocated number of memory slots within the array are filled.
                while (!(scan.hasNextDouble()))
                {
                    System.out.println("Invalid Input. Please enter a NUMBER value you would like to sort: ");
                    // If input is invalid, this message is printed to provide user with instructions once more.
                    scan.next();
                    // Scans and uses next input to return to program function.
                } // Provides input validation for data entry into array.
                double userNum = scan.nextDouble();
                // Initializes and scans the numbers into a double container.
                numArray[i] = userNum;
                // Stores the numbers within the array based on the number of allocated memory spaces for the array they designated earlier.
            } // Prompts user to enter numbers and stores them within the array for sorting.            
            System.out.println(Arrays.toString(numArray));
            // Prints current state of array so user can see if their inputted numbers are correct.
            System.out.println("Are the numbers and amount of numbers shown above correct? (Y/N): ");
            // Prompts user to enter a char response to the question if they would like to repeat the the array refil in case of error of input.
            responseOops = scan.next().charAt(0);
            // Scans, stores, and grabs first letter of repsonse for either repeating the array filling process or continuing into the sort.
        } while (responseOops == ('n') || responseOops == ('N'));
        if (responseOops == ('y') || responseOops == ('Y'))
        {
            sortChooser();
            // Local call to method to choose sorting process.
        }
    }
    //***************************************************************************************************************************************************************

    // This method prompts the user to choose their prefered sorting algorithm based on the options printed.

    public void sortChooser()
    {
        System.out.println("Now that you have entered your numbers, this program offers four different processes to sort them.");
        // Informs user once more of the next step and how many sorting options are available.
        System.out.println("To sort them using a 'Quick Sort', type the word Quick or the words Quick Sort, then press enter.");
        // Prints instructions for Quick Sort selection to user.
        System.out.println("To sort them using a 'Bubble Sort', type either the word Bubble or the words Bubble Sort, then press enter.");
        // Prints instructions for Bubble Sort selection to user.
        System.out.println("To sort them using an 'Insertion Sort', type either the word Insertion or the words Insertion Sort, then press enter.");
        // Prints instructions for Insertion Sort selection to user.
        System.out.println("To sort them using a 'Merge Sort', type either the word Merge or the words Merge Sort, then press enter.");
        // Prints instructions for Merge Sort selection to user.
        String sortChoice = scan.next();
        // Scans and stores their choice for the algorithm selection process in if statements below.
        if (sortChoice.equalsIgnoreCase("Quick") || sortChoice.equalsIgnoreCase("Quick Sort"))
        {
            sortQuick();            
        } // Local call to Quick Sort method.        

        else if (sortChoice.equalsIgnoreCase("Bubble") || sortChoice.equalsIgnoreCase("Bubble Sort"))
        {
            sortBubble();            
        } // Local call to Bubble Sort method.        

        else if (sortChoice.equalsIgnoreCase("Insertion") || sortChoice.equalsIgnoreCase("Insertion Sort"))
        {
            sortInsertion();            
        } // Local call to Insertion Sort method.        

        else if (sortChoice.equalsIgnoreCase("Merge") || sortChoice.equalsIgnoreCase("Merge Sort"))
        {
            sortMerge();            
        } // Local call to Merge Sort method.
        else  
        {
            System.out.println("Sorry, that input is invalid. Please try again.");
            // Prints message to user if input is not recognized.
            sortChooser();
            // If input is invalid, sortChooser method is recalled to maintain array data, provide user with instructions/sort options once more.
        }
    }
    //***********************************************************************************************************************************************

    // This method sorts the user filled array into desired order using pre-built Quick Sort process.

    public void sortQuick()
    {
        getArray();
        // Creates local copy of array contents for use in Quick Sort. 
        System.out.println("Would you like the numbers to be sorted into Ascending or Descending order using Quick Sort?: (A/D)");
        // Prompts user to choose how they would like the numbers sorted.
        String sortAOrD = scan.next();
        // Scans and stores choice for Ascending or Descending order in sorts below.
        if (sortAOrD.equalsIgnoreCase("Ascending") || sortAOrD.equalsIgnoreCase("A"))
        {
            System.out.println("Here are your numbers BEFORE sorting..." +(Arrays.toString(numArray)));
            // Prints current state of array once more before sorting for user.
            startTime = System.nanoTime();
            // Begins process for tracking time transpired for sorting process.
            Arrays.sort(numArray);
            // Call to API array method which is a modified quick sort.
            endTime = System.nanoTime();
            // Ends process for tracking time transpired for sorting process.
            System.out.println("Here are your numbers AFTER sorting..." +(Arrays.toString(numArray)));
            // Prints current state of array after sorting for user.
            System.out.println("This sort took:\n" + (endTime - startTime) + '\t' + "nanoseconds");
            // Uses stored variables created through nanotime time-tracking process to calcuate difference and print the time traspired to user.            
        }
        else if (sortAOrD.equalsIgnoreCase("Descending") || sortAOrD.equalsIgnoreCase("D"))
        {
            System.out.println("Here are your numbers BEFORE sorting..." +(Arrays.toString(numArray)));
            // Prints current state of array once more before sorting for user.
            //startTime = System.nanoTime();
            startTime = System.nanoTime();
            // Begins process for tracking time transpired for sorting process.
            Arrays.sort(numArray);
            // Call to API array method which is a modified quick sort. 
             for(int i = 0; i < (numArray.length / 2); i++) 
            {
                double temp = numArray[i];
                numArray[i] = numArray[numArray.length - i - 1];
                numArray[numArray.length - i - 1] = temp;
            } // Algorithm reverses order of the elements by flipping/exchanging the array to produce desired order.
            //endTime = System.nanoTime();            
            endTime = System.nanoTime();
            // Ends process for tracking time transpired for sorting process.
            System.out.println("Here are your numbers AFTER sorting..." +(Arrays.toString(numArray)));           
            // Prints current state of array after sorting for user.
            System.out.println("This sort took:\n" + (endTime - startTime) + '\t' + "nanoseconds");
            // Uses stored variables created through nanotime time-tracking process to calcuate difference and print the time traspired to user.
        }
        else 
        {
            System.out.println("Sorry, that input is invalid. Please try again.");
            // Prints message to user if input is not recognized.
            sortQuick();
            // If input is invalid, the sort method is recalled to maintain array data and provide user with instructions/sort options once more.
        }
    }
    //***********************************************************************************************************************************************

    // This method sorts the user filled array into desired order using Bubble Sort algorithm.

    public void sortBubble()
    {
        getArray(); 
        // Creates local copy of array contents for use in Bubble Sort.
        System.out.println("Would you like the numbers to be sorted into Ascending or Descending order using Bubble Sort?: (A/D)");
        // Prompts user to choose how they would like the numbers sorted.
        String sortAOrD = scan.next();        
        // Scans and stores choice for Ascending or Descending order in sorts below.
        if (sortAOrD.equalsIgnoreCase("Ascending") || sortAOrD.equalsIgnoreCase("A"))
        {
            System.out.println("Here are your numbers BEFORE sorting..." +(Arrays.toString(numArray)));
            // Prints current state of array once more before sorting for user.
            startTime = System.nanoTime();
            // Begins process for tracking time transpired for sorting process.
            for (int i = (numArray.length - 1); i >= 0; i--)
            {
                for (int j = 1; j <= i; j++)
                {
                    if (numArray[j-1] > numArray[j])
                    {
                        double temp = numArray[j - 1];
                        numArray[j - 1] = numArray[j];
                        numArray[j] = temp;                   
                    } 
                }
            }
            endTime = System.nanoTime();
            // Ends process for tracking time transpired for sorting process.
            System.out.println("Here are your numbers AFTER sorting..." +(Arrays.toString(numArray)));
            // Prints current state of array after sorting for user.
            System.out.println("This sort took:\n" + (endTime - startTime) + '\t' + "nanoseconds");
            // Uses stored variables created through nanotime time-tracking process to calcuate difference and print the time traspired to user.
        }
        else if (sortAOrD.equalsIgnoreCase("Descending") || sortAOrD.equalsIgnoreCase("D"))
        {
            System.out.println("Here are your numbers BEFORE sorting..." +(Arrays.toString(numArray)));
            // Prints current state of array once more before sorting for user.
            startTime = System.nanoTime();            
            // Begins process for tracking time transpired for sorting process.
            for (int i = (numArray.length - 1); i >= 0; i--)
            {
                for (int j = 1; j <= i; j++)
                {
                    if (numArray[j-1] < numArray[j])
                    {
                        double temp = numArray[j - 1];
                        numArray[j - 1] = numArray[j];
                        numArray[j] = temp;                        
                    } 
                }
            }
            endTime = System.nanoTime();
            // Ends process for tracking time transpired for sorting process.
            System.out.println("Here are your numbers AFTER sorting..." +(Arrays.toString(numArray)));
            // Prints current state of array after sorting for user.
            System.out.println("This sort took:\n" + (endTime - startTime) + '\t' + "nanoseconds");
            // Uses stored variables created through nanotime time-tracking process to calcuate difference and print the time traspired to user.
        }
        else
        {
            System.out.println("Sorry, that input is invalid. Please try again.");
            // Prints message to user if input is not recognized.
            sortBubble();
            // If input is invalid, the sort method is recalled to maintain array data and provide user with instructions/sort options once more.
        }
    }
    //***********************************************************************************************************************************************

    // This method sorts the user filled array into desired order using Insertion Sort algorithm.

    public void sortInsertion()
    {
        getArray(); 
        // Creates local copy of array contents for use in Insertion Sort.
        System.out.println("Would you like the numbers to be sorted into Ascending or Descending order using Insertion Sort?: (A/D)");
        // Prompts user to choose how they would like the numbers sorted.
        String sortAOrD = scan.next();
        // Scans and stores choice for Ascending or Descending order in sorts below.
        if (sortAOrD.equalsIgnoreCase("Ascending") || sortAOrD.equalsIgnoreCase("A"))
        {
            System.out.println("Here are your numbers BEFORE sorting..." +(Arrays.toString(numArray)));
            // Prints current state of array once more before sorting for user.
            startTime = System.nanoTime();            
            // Begins process for tracking time transpired for sorting process.
            for (int i = 1; i < numArray.length; i++)
            {
                double index = numArray[i]; 
                int j;
                for (j = i - 1; (j >= 0) && (numArray[j] > index); j--)
                {
                    numArray[j + 1] = numArray[j];
                }
                numArray[j + 1] = index;
            } 
            endTime = System.nanoTime();
            // Ends process for tracking time transpired for sorting process.
            System.out.println("Here are your numbers AFTER sorting..." +(Arrays.toString(numArray))); 
            // Prints current state of array after sorting for user.
            System.out.println("This sort took:\n" + (endTime - startTime) + '\t' + "nanoseconds");
            // Uses stored variables created through nanotime time-tracking process to calcuate difference and print the time traspired to user.
        }
        else if (sortAOrD.equalsIgnoreCase("Descending") || sortAOrD.equalsIgnoreCase("D"))
        {
            System.out.println("Here are your numbers BEFORE sorting..." +(Arrays.toString(numArray)));
            // Prints current state of array once more before sorting for user.
            startTime = System.nanoTime();
            // Begins process for tracking time transpired for sorting process.
            for (int i = 1; i < numArray.length; i++)
            {
                double index = numArray[i]; 
                int j;
                for (j = i - 1; (j >= 0) && (numArray[j] < index); j--)
                {
                    numArray[j + 1] = numArray[j];
                }
                numArray[j + 1] = index;
            } 
            endTime = System.nanoTime();
            // Ends process for tracking time transpired for sorting process.
            System.out.println("Here are your numbers AFTER sorting..." +(Arrays.toString(numArray)));
            // Prints current state of array after sorting for user.
            System.out.println("This sort took:\n" + (endTime - startTime) + '\t' + "nanoseconds");
            // Uses stored variables created through nanotime time-tracking process to calcuate difference and print the time traspired to user.
        }
        else
        {
            System.out.println("Sorry, that input is invalid. Please try again.");
            // Prints message to user if input is not recognized.
            sortInsertion();
            // If input is invalid, the sort method is recalled to maintain array data and provide user with instructions/sort options once more.
        }
    }
    //***********************************************************************************************************************************************

    // This method sorts the user filled array into desired order using Merge Sort algorithm.

    public void sortMerge()
    {
        getArray();
        // Creates local copy of array contents for use in Merge Sort.
        System.out.println("Would you like the numbers to be sorted into Ascending or Descending order using Merge Sort?: (A/D)");
        // Prompts user to choose how they would like the numbers sorted.
        String sortAOrD = scan.next();
        // Scans and stores choice for Ascending or Descending order in sorts below.
        if (sortAOrD.equalsIgnoreCase("Ascending") || sortAOrD.equalsIgnoreCase("A"))
        {
            System.out.println("Here are your numbers BEFORE sorting..." +(Arrays.toString(numArray))); 
            // Prints current state of array once more before sorting for user.
            startTime = System.nanoTime();
            // Begins process for tracking time transpired for sorting process.
            for (int i = 0; i < numArray.length - 1; i++)
            {
                int index = i;
                for (int j = i + 1; j < numArray.length; j++)
                {
                    if (numArray[j] < numArray[index])
                    {
                        index = j;         
                    }
                }
                double temp = numArray[index];
                numArray[index] = numArray[i];
                numArray[i] = temp;
            }
            endTime = System.nanoTime();
            // Ends process for tracking time transpired for sorting process.
            System.out.println("Here are your numbers AFTER sorting..." +(Arrays.toString(numArray)));
            // Prints current state of array after sorting for user.
            System.out.println("This sort took:\n" + (endTime - startTime) + '\t' + "nanoseconds");
            // Uses stored variables created through nanotime time-tracking process to calcuate difference and print the time traspired to user.
        }
        else if (sortAOrD.equalsIgnoreCase("Descending") || sortAOrD.equalsIgnoreCase("D"))
        {
            System.out.println("Here are your numbers BEFORE sorting..." +(Arrays.toString(numArray)));
            // Prints current state of array once more before sorting for user.
            startTime = System.nanoTime();
            // Begins process for tracking time transpired for sorting process.
            for (int i = 0; i < numArray.length - 1; i++)
            {
                int min = i;
                for (int j = i + 1; j < numArray.length; j++)
                {
                    if (numArray[j] < numArray[min])
                    {
                        min = j;
                    }
                }
                double temp = numArray[min];
                numArray[min] = numArray[i];
                numArray[i] = temp;
            }
            for(int i = 0; i < numArray.length / 2; i++)
            {
                double temp = numArray[i];
                numArray[i] = numArray[numArray.length - i - 1];
                numArray[numArray.length - i - 1] = temp;
            }
            endTime = System.nanoTime();
            // Ends process for tracking time transpired for sorting process.
            System.out.println("Here are your numbers AFTER sorting..." +(Arrays.toString(numArray)));
            // Prints current state of array after sorting for user.
            System.out.println("This sort took:\n" + (endTime - startTime) + '\t' + "nanoseconds");
            // Uses stored variables created through nanotime time-tracking process to calcuate difference and print the time traspired to user.
        }
        else
        {
            System.out.println("Sorry, that input is invalid. Please try again.");
            // Prints message to user if input is not recognized.
            sortMerge();
            // If input is invalid, the sort method is recalled to maintain array data and provide user with instructions/sort options once more.
        }
    }
    //***********************************************************************************************************************************************

    // This method creates a copy of the array data for use in the sorting methods.

    public double[] getArray()
    {
        return (double[]) numArray.clone();
        // Clones array data from local method and returns it to use in each sort.
    }
} // end class FinalMethods
