/*Author: David Coles
**05/18/2016
**CtCI 1.4
**Write a method that will replace a space with %20.
 */

#include<stdio.h>
#define SIZE 100
#define ASCII_SIZE 127

//Get rid of implicit declaration warning.
int print_string(char str[], int length);

int replace_space(char str[], int length)
{
    char new_string[SIZE];
    int count = 0;

    //Find number of vaild chars in string.
    for (int i = 0; i < length; i++)
    {
        //Ignores non-printing values.
        //32 is for white space.
        if((str[i] > 33 && str[i] < 126) || str[i] == 32)
        {
            if(str[i] == 32)
            {
                new_string[count] = '%';
                count++;
                new_string[count] = '2';
                count++;
                new_string[count] = '0';
                count++;
            }
            else{
                new_string[count] = str[i];
                count++;
            }
        }
    }
    print_string(new_string, count);
    return 0;
}

//Print string.
int print_string(char str[], int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}

//Unit test for replace_space tests one strings.
int unit_test_replace_space(){
    printf("Unit Test: replace_space\n");
    printf("Testing: string 'abc zyx'.'\n");
    char test_string_1[SIZE] = {'a', 'b', 'c',' ', 'z','y','x'};
    replace_space(test_string_1, SIZE);
}

int main(int argc, char **argv)
{
    unit_test_replace_space();
    char input_string[SIZE] = {0};
    printf("\nEnter the input string: ");
    fgets(input_string, 100, stdin);
    replace_space(input_string, SIZE);
    return 0;
}