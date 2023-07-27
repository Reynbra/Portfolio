
/**
 * Write a description of class exampleBubbleSort here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class exampleExchangeSort
{
    public static void main(String[] args)
    {
        String[ ] names = {"joe", "slim", "ed", "george"};
        sortStringExchange (names);
        for (int k = 0; k < 4; k++)
        {
            System.out.println(names [ k ]);
        }
    }

    public static void sortStringExchange(String x[])
    {
        //int i, j;
        //String temp;

        for (int i = 0;  i < x.length - 1;  i++)
        {
            for (int j = i + 1;  j < x.length; j++)
            { 
                if ( x [ i ].compareToIgnoreCase(x [j]) > 0)
                {                                             
                    // ascending sort
                    String temp = x [ i ];
                    x [ i ] = x [ j ];    // swapping
                    x [ j ] = temp;

                }
            }
        }
    }
}

