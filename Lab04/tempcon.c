#include <stdio.h>

//Function initialization for all conversions of temps prior to the main function
float celsius_to_fahrenheit (float celsius); 
float fahrenheit_to_celsius (float fahrenheit);
float celsius_to_kelvin (float celsius);
float kelvin_to_celsius (float kelvin);
float fahrenheit_to_kelvin (float fahrenheit);
float kelvin_to_fahrenheit (float kelvin);


int main()
{
    float temp; //Creates the temperature variable as a float type
    int temp_type; //Intializes the first type that the temperature is being converted from
    int des_type; //Intializes the desired temp conversion type
    float result; //Temp variable to store the result of the functions

    printf("Enter a temperature:\n"); //Asks for a value of the temperature from the user
    scanf("%f", &temp); //Stores the value of the temp
    
    do //Beginning of the do-while loop
    {
        printf("Enter intial temp scale:\nFarenheit - 1\nCelcius - 2\nKelvin - 3\n"); //Asks the user for the first temperature type
        scanf("%d", &temp_type); //Stores the type for temperature as an integer
        if (temp_type < 1 || temp_type > 3) //Condition for if the temp is outside of the range
        {
            printf("Invalid choice, try again.\n\n"); //Tells the user that the option is not in the correct range
        }
        else
        {
            break; //Ends the cycle of the while loop and temp scale menu
        }
    }
    while(1);
    do
    {
        printf("\nWhat do you want to convert to?\nFarenheit - 1\nCelcius - 2\nKelvin - 3\n");
        scanf("%d",&des_type);
        if (des_type < 1 || des_type > 3) //Condition for if the temp is outside of the range
        {
            printf("Invalid choice, try again.\n\n"); //Tells the user that the option is not in the correct range
        }
        else
        {
            break; //Ends the cycle of the while loop and new temp scale menu
        }
    }
    while(1);

    if (temp_type == 1) //When the temperature is in Fahrenheit
    {
        if (des_type == 2) //Condition for if the user wants to convert to Celcius
        {
            result = fahrenheit_to_celsius(temp); //Assigns the temporary variable of result to the output of the fahrenheit_to_celsius function
            printf("The new temperature is: %f C\n\n", result); //Prints the result
        }
        else if (des_type == 3) //Condition for if the user wants to convert to Kelvin
        {
            result = fahrenheit_to_kelvin(temp); //Assigns the temporary variable of result to the output of the fahrenheit_to_kelvin function
            printf("The new temperature is: %f K\n\n", result); //Prints the result
        }
        else
        {
            printf("Already in fahrenheit.\n\n"); //Outputs if temp_type and des_type are the same value
        }
    }
    if (temp_type == 2) //When the temperature is in Celcius
    {
        if (des_type == 1) //Condition for if the user wants to convert to Fahrenheit
        {
            result = celsius_to_fahrenheit(temp); //Assigns the temporary variable of result to the output of the celsius_to_fahrenheit function
            printf("The new temperature is: %f F\n\n", result); //Prints the result
        }
        else if (des_type == 3) //Condition for if the user wants to convert to Kelvin
        {
            result = celsius_to_kelvin(temp); //Assigns the temporary variable of result to the output of the celsius_to_kelvin function
            printf("The new temperature is: %f K\n\n", result); //Prints the result
        }
        else
        {
            printf("Already in celcius.\n\n"); //Outputs if temp_type and des_type are the same value
        }
    }
    if (temp_type == 3) //When the temperature is in Kelvin
    {
        if (des_type == 1) //Condition for if the user wants to convert to Fahrenheit
        {
            result = kelvin_to_fahrenheit(temp); //Assigns the temporary variable of result to the output of the kelvin_to_fahrenheit function
            printf("The new temperature is: %f F\n\n", result); //Prints the result
        }
        else if (des_type == 2) //Condition for if the user wants to convert to Celcius
        {
            result = kelvin_to_celsius(temp); //Assigns the temporary variable of result to the output of the kelvin_to_celsius function
            printf("The new temperature is: %f C\n\n", result); //Prints the result
        }
        else
        {
            printf("Already in kelvin.\n\n"); //Outputs if temp_type and des_type are the same value
        }
    }
}

float celsius_to_fahrenheit (float celsius) //Creates the celsius_to_fahrenheit function
{
    return ((9.0/5.0) * celsius + 32.0); //Outputs the float of fahrenheit from celcius
}

float fahrenheit_to_celsius (float fahrenheit) //Creates the fahrenheit_to_celsius function
{
    return ((5.0/9.0) * (fahrenheit - 32.0)); //Outputs the float of celcius from fahrenheit
}

float celsius_to_kelvin (float celsius) //Creates the celsius_to_kelvin function
{
    return (celsius + 273.15); //Outputs the float of kelvin from celcius
}

float kelvin_to_celsius (float kelvin) //Creates the kelvin_to_celsius function
{
    return (kelvin - 273.15); //Outputs the float of celcius from kelvin
}

float fahrenheit_to_kelvin (float fahrenheit) //Creates the fahrenheit_to_kelvin function
{
    return ((fahrenheit - 32.0) * (5.0/9.0) + 273.15); //Outputs the float of kelvin from fahrenheit
}

float kelvin_to_fahrenheit (float kelvin) //Creates the kelvin_to_fahrenheit function
{
    return ((kelvin - 273.15) * (9.0/5.0) + 32.0); //Outputs the float of fahrenheit from kelvin
}
