
/**
 * Write a description of class exampleSort here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
import java.util.Arrays;
public class testBench
{
    public static void main(String[] args)
    {
        double exArray[] = {3.2, 1.2, 9.7, 6.2, 4.5};

        //Arrays.sort(exArray);

        //System.out.println(Arrays.toString(exArray));

        System.out.println("Here are your numbers BEFORE sorting..." +(Arrays.toString(exArray)));
        for (int i = 0; i < exArray.length - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < exArray.length; j++)
            {
                if (exArray[j] < exArray[min])
                {
                    min = j;             
                }
            }
            double temp = exArray[min];
            exArray[min] = exArray[i];
            exArray[i] = temp;
        }
        //
        for(int i = 0; i < exArray.length / 2; i++)
        {
            double temp = exArray[i];
            exArray[i] = exArray[exArray.length - i - 1];
            exArray[exArray.length - i - 1] = temp;
        }
        System.out.println("Here are your numbers AFTER sorting..." +(Arrays.toString(exArray)));
         
    }
}

