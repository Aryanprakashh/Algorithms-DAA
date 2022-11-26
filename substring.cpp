/* input - Input String
 *  output - Save the result in the output array (passed as argument). You don’t have to
 *  print or return the result
 */
void minLengthWord(char input[], char output[])
{

    // Write your code here
    int len = 0;
    int start = 0;

    for (int i = 0; input[i] != '\0'; i++)
    {
        len++;
    }

    int count = 0;
    int min = 100000;
    char str[len];

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (i == len - 1)
        {
            count++;
            if (count < min)
            {
                min = count;
                int end = i , j = 0;
                while (start <= end)
                {
                    output[j] = input[start];
                    j++;
                    start++;
                }
                output[j] = '\0';
            }
        }
        else if (input[i] != ' ')
        {
            count++;
        }
        else
        {
            if (count < min)
            {
                min = count;
                int end = i-1, j = 0;
                while (start <= end)
                {
                    output[j] = input[start];
                    start++;
                    j++;
                }
                output[j] = '\0';
            }
            count = 0;
            start = i + 1;
        }
    }
}
