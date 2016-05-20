/*Author: David Coles
**05/18/2016
**CtCI 1.2
**Write a method that will replace a space with %20.
 */



#include<stdio.h>
#define SIZE 100
#define ASCII_SIZE 127

//Get rid of implicit declaration warning.
int print_string(char str[], int length);

int reverse_string(char str[], int length)
{
    char reversed_str[SIZE];
    int count = 0;
    
    //Find number of vaild chars in string.
    for (int i = 0; i < length; i++)
    {
        //Ignores non-printing values.
        //32 is for white space.
        if(str[i] > 33 && str[i] < 126 || str[i] == 32)
        {
            if(str[i] == 32)
            {
                str[i] = '%20';
            }
        }
    }
    //Note count is not base on zero-based indexs, hence [count-1];
    int temp_count = count;
    //Reverse array
    for (int j = 0; j < temp_count; j++)
    {
        //Ignores non-printing values.
        //32 is for white space.
        if(str[j] > 33 && str[j] < 126 || str[j] == 32)
        {
            reversed_str[j] = str[count-1];
            count--;
        }
    }
    print_string(reversed_str, temp_count);
    return 1;
}

//Print string.
int print_string(char str[], int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%c", str[i]);
    }
    return 0;
    printf("\n");
}

//Unit test for reversed_string tests one strings.
/*int unit_test_reverse_string(){
    printf("Unit Test: reverse_string\n");
    printf("Testing: string 'abc zyx'.'\n");
    char test_string_1[SIZE] = {'a', 'b', 'c',' ', 'z','y','x'};
    reverse_string(test_string_1, SIZE);
}*/

int main(int argc, char **argv)
{
    //unit_test_reverse_string();
    char input_string[SIZE] = {0};
    printf("\nEnter the input string: ");
    fgets(input_string, 100, stdin);
    reverse_string(input_string, SIZE);
    return 0;
}