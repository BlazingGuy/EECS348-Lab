#include <stdio.h>

//Function initialization for all conversions of temps prior to the main function
float celsius_to_fahrenheit (float celsius); 
float fahrenheit_to_celsius (float fahrenheit);
float celsius_to_kelvin (float celsius);
float kelvin_to_celsius (float kelvin);
float fahrenheit_to_kelvin (float fahrenheit);
float kelvin_to_fahrenheit (float kelvin);
void categorize_temperature(float celsius);


int main()
{
    float temp; //Creates the temperature variable as a float type
    int temp_type; //Intializes the first type that the temperature is being converted from
    int des_type; //Intializes the desired temp conversion type
    float result; //Temp variable to store the result of the functions
    float temp_in_celsius; //Intialized temperature in celsius to determine the catagories

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
        printf("\nWhat do you want to convert to?\nFarenheit - 1\nCelcius - 2\nKelvin - 3\n"); //Asks the user for the first temperature type
        scanf("%d",&des_type); //Stores the type for desired temperature as an integer
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
    
    if (temp_type == 1) //When temperature is in fahrenheit
    {
        temp_in_celsius = fahrenheit_to_celsius(temp); //Assigns the converted fahrenheit temp to temp in celsius
    }
    else if (temp_type == 2) //When temperature is in celsus
    {
        temp_in_celsius = temp; // Already in celsius
    }
    else if (temp_type == 3)
    {
        temp_in_celsius = kelvin_to_celsius(temp); //Assigns the converted kelvin temp to temp in celsius
    }

    if (des_type == 1) //Condition for when the desired temperature type is fahrenheit
    {
        if (temp_type == 2) //When the initial temp type is in celsius
        {
            result = celsius_to_fahrenheit(temp); //Converts result to fahrenheit
            printf("Converted Temperature: %f F\n", result); //Outputs result
        }
        else if (temp_type == 3) //When the initial temp type is in kelvin
        {
            result = kelvin_to_fahrenheit(temp); //Converts result to fahrenheit
            printf("Converted Temperature: %f F\n", result); //Outputs result
        }
        else
        {
            printf("Already in Fahrenheit.\n"); //When intial temp type and desired temp types are equal
        }
    }
    else if (des_type == 2) //Condition for when the desired temperature type is celsius
    {
        if (temp_type == 1) //When the initial temp type is in fahrenheit
        {
            result = fahrenheit_to_celsius(temp); //Converts result to celsius
            printf("Converted Temperature: %f C\n", result); //Outputs result
        }
        else if (temp_type == 3) //When the initial temp type is in kelvin
        {
            result = kelvin_to_celsius(temp); //Converts result to celsius
            printf("Converted Temperature: %f C\n", result); //Outputs result
        }
        else
        {
            printf("Already in Celsius.\n"); //When intial temp type and desired temp types are equal
        }
    }
    else if (des_type == 3) //Condition for when the desired temperature type is kelvin
    {
        if (temp_type == 1) //When the initial temp type is in fahrenheit
        {
            result = fahrenheit_to_kelvin(temp); //Converts result to kelvin
            printf("Converted Temperature: %f K\n", result); //Outputs result
        }
        else if (temp_type == 2) //When the initial temp type is in celsius
        {
            result = celsius_to_kelvin(temp); //Converts result to kelvin
            printf("Converted Temperature: %f K\n", result); //Outputs result
        }
        else
        {
            printf("Already in Kelvin.\n"); //When intial temp type and desired temp types are equal
        }
    }
    categorize_temperature(temp_in_celsius); //Outputs the catagories based on the temperature in celsius
}

void categorize_temperature(float celsius) //Initialize the catagory function
{
    if (celsius <= 0) //When temp in celsius is below 0
    {
        printf("Temperature category: Freezing\nWeather advisory: Stay Indoors.\n");
    }
    else if (celsius > 0 && celsius <= 10) //When temp in celsius is greater than 0 and less than or equal to 10
    {
        printf("Temperature category: Cold\nWeather advisory: Wear a Jacket.\n");
    }
    else if (celsius > 10 && celsius <= 25) //When temp in celsius is greater than 10 and less than or equal to 25
    {
        printf("Temperature category: Comfortable\nWeather advisory: You should feel comfortable.\n");
    }
    else if (celsius > 25 && celsius <= 35) //When temp in celsius is greater than 25 and less than or equal to 35
    {
        printf("Temperature category: Hot\nWeather advisory: Stay hydrated.\n");
    }
    else //When temp in celsius is greater than 35
    {
        printf("Temperature category: Extreme Heat\nWeather advisory: Potential Heatstroke Incoming\n");
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
