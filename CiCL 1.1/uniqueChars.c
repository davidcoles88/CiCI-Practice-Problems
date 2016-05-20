/*Author: David Coles
**05/18/2016
**CtCI 1.1 
**Implement an algorithm to determine if a string has all unique characters.  What if you cannot use additional data structures?*/

#include<stdio.h>
#define SIZE 100
#define ASCII_SIZE 127

//1; not all values are unique. 0; All values are unique.
int check_unique_chars(char input_string[], int length)
{
    /*If allUnique is a bool value; either 0 or 1.
     **0 is false and 1 is true.*/
    int all_unique = 0;
    int temp_ascii[ASCII_SIZE] = {0};
    
    for (int i = 0; i < length; i++ )
    {
        //Ignores non-printing values.
        if(input_string[i] > 33 && input_string[i] < 126)
        {
            temp_ascii[input_string[i]] += 1;
            if(temp_ascii[input_string[i]] > 1)
            {
                all_unique = 1;
            }
        }
    }
    if(all_unique == 0)
    {
        printf("All values are unique.\n");
        return 1;
    }
    else
    {
        printf("Repeating values exist in inputted string.\n");
        print_repeating_values(temp_ascii, ASCII_SIZE);
        return 0;
    }
}

//Print repeating values.
int print_repeating_values(int temp_ascii[], int length)
{
    for(int i = 0; i < length; i++)
    {
        if(temp_ascii[i] > 1)
        {
            printf("%c occurs %d times.", i, temp_ascii[i]);
            printf("\n");
        }
    }
    return 0;
}

//Unit test for unique_chars tests two strings.
int unit_test_unique_chars(){
    printf("Unit Test: check_unique_chars\n");
    printf("Testing: string 'aabbc'\n");
    char test_string_1[SIZE] = {'a', 'a', 'b', 'b', 'c'};
    if(check_unique_chars(test_string_1, SIZE) == 0)
    {
        printf("String 'aabbc' passes.\n");
    }
    else
    {
        printf("String 'aabbc' fails.\n");
    }
    printf("Testing: string 'aabbc'\n");
    char test_string_2[SIZE] = {'a', 'b', 'c', 'd', 'e'};
    if(check_unique_chars(test_string_2, SIZE) == 1)
    {
        printf("String 'abcde' passes.\n");
    }
    else
    {
        printf("String 'abcde' fails.\n");
    }
  
}

int main(int argc, char **argv)
{
    print("\n");
    unit_test_unique_chars();
    char input_string[SIZE] = {0};
    printf("\nEnter the input string: ");
    fgets(input_string, 100, stdin);
    check_unique_chars(input_string, SIZE);
    return 0;
}