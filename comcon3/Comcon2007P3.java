// NAMES		: Owen Su, Prakash Shekhar
// GROUP		: DM
// DATE			: OCT 4th
// PROBLEM NAME	: COMCON OCT 2007 P2

import java.util.Scanner;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.io.FileNotFoundException;
public class Comcon2007P3
{
    public static void main(String[] args) throws FileNotFoundException
    {
        int counter = 0;
        int primes = 0;
        int latestPrime = 0;
        boolean isPrime = true;
        int[] nums = new int[5];
        Scanner scan = new Scanner(new File("./PROGRAM3.DAT"));
        for (int i = 0; i < 5; i++)
        {
            nums[i] = scan.nextInt();
        }
        for (int i = 0; i < 5; i++)
        {
            counter = 2;
            primes = 0;
            while (primes < nums[i])
            {
                isPrime = true;
                for (int j = 1; j < counter; j++)
                {
                    if (j!= 1 && counter % j == 0)
                    {
                        isPrime = false;
                        break;
                    }

                }
                if (isPrime)
                {
                    latestPrime = counter;
                    primes++;
                }
                counter++;
            }
            System.out.println (latestPrime);
        }
    }
}
