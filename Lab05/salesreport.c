#include <stdio.h>
#include <stdlib.h>

#define SALES_SIZE 12 //Initialized the size of the sales array

int main()
{
    FILE *file; //Created a deassignment value for the file
    float sales[SALES_SIZE]; //Created the values of the sales array
    int count = 0;//Counter thats used to iterate over the array
    const char *months[12]; //Array of months that doesn't get changed
    months[0] = "January";
    months[1] = "February";
    months[2] = "March";
    months[3] = "April";
    months[4] = "May";
    months[5] = "June";
    months[6] = "July";
    months[7] = "August";
    months[8] = "September";
    months[9] = "October";
    months[10] = "November";
    months[11] = "December";
    

    file = fopen("input.txt", "r"); //Reads the content from input file
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    while (count < SALES_SIZE && fscanf(file, "%f", &sales[count]) == 1) //Stores the content of the sales into the sales array
    {
        count++; //Iterates the count variable
    }

    fclose(file);

    printf("Monthly Sales Report 2024\n\n");

    printf("Month        Sales\n");
    for (int i = 0; i < count; i++)
    {
        printf("%-12s %.2f\n", months[i], sales[i]); //Prints months based on each assigned sale
    }

    printf("\nSales summary report:\n\n"); // Beginning of sales report output
    float least = sales[0]; //Initialization of smallest sales value
    int least_index = 0; //Initialization of smallest sales index
    float most = sales[0]; //Initialization of largest sales value
    int most_index = 0; //Initialization of largest sales index
    float avg; //Initialization of average sales value
    float total; //Initialization of total sales value
    float six_m_avg; //Initialization of 6 month sales average
    float six_m_total; //Initialization of 6 month total

    for (int j = 0; j < count; j++) //Iterates through sales array
    {
        if (sales[j] < least) //Finds value for smallest index and compares it to initial index in sales
        {
            least = sales[j]; //Reassigns value
            least_index = j; //Reassigns index
        }
    }

    for (int k = 0; k < count; k++) //Iterates through sales array
    {
        if (sales[k] > most) //Finds value for largest index and compares it to initial index in sales
        {
            most = sales[k]; //Reassigns value
            most_index = k; //Reassigns index
        }
    }

    for (int l = 0; l < count; l++) //Iterates through sales array
    {
        total += sales[l]; //Total becomes the combined value of sales array
    }
    avg = total / SALES_SIZE; //Average is total divided by the size of sales array

    printf("Minimum Sales: %.2f (%s)\n", least, months[least_index]);
    printf("Maximum Sales: %.2f (%s)\n", most, months[most_index]);
    printf("Average Sales: %.2f\n", avg);

    printf("\nSix-Month moving average report:\n\n");

    for (int m = 0; m <= count - 6; m++) //Iterates the count through every first 6 values within the array
    {
        float six_m_total = 0.0; //Intitialized the value for 6 month total
        for (int n = m; n < m + 6; n++) //Shifts the value of the array every time n gets iterated
        { 
            six_m_total += sales[n]; //Total becomes the combined value of each 6 month section of the sales array
        }
        float six_m_avg = six_m_total / 6.0; //Average is total divided by 6 months
        printf("%s-%s average: %.2f\n", months[m], months[m + 5], six_m_avg);
    }
    six_m_avg = six_m_total / SALES_SIZE;

    
    for (int o = 0; o < count; o++) //Iterates through array
    {
        int most_index = o; //Reassigns value for max index
        for (int p = o; p < count; p++) 
        {
            if (sales[p] > sales[most_index]) 
            {
                most_index = p; //Reassigns once more based on values of sales
            }
        }
        
        // Swap the sales values based on the corresponding max
        float tempSale = sales[o];
        sales[o] = sales[most_index];
        sales[most_index] = tempSale;

        // Swap the corresponding months
        const char *tempMonth = months[o];
        months[o] = months[most_index];
        months[most_index] = tempMonth;
    }

    // Output the sorted sales and months
    printf("\nSales report (highest to lowest):\n\n");
    printf("Month        Sales\n");
    
    for (int q = 0; q < count; q++) 
    {
        printf("%-12s %.2f\n", months[q], sales[q]); //Outputs based on rearranged values
    }
    
}
