#include <stdio.h>

int main()
{
    int score; //Initializes the score to be stored as an integer
    int TD = 6; //Initializes the points for a touchdown
    int FG = 3; //Initializes the points for a fieldgoal
    int TD_C = 8; //Initializes the points for a touchdown conversion
    int TD_FG = 7; //Initializes the points for a touchdown with a fieldgoal
    int SAFETY = 2; //Initializes the points for a saftey
    int valid = 1; //Creates a value to determine if the number the user input is valid
    while(1) //Created a while loop that would always run by returning true
    {
    printf("Enter 0 or 1 to STOP\n");
    printf("Enter the NFL score:"); //Asked the user for the score as an input
    scanf("%d", &score);//Scanned the input to where it can be read and stored

    if (score == 0 || score == 1) //Stops the program if the score entered is 0 or 1
    {
        break; //Ends the program
    }
    if (score < 0) //Loops back to the original print statements and changes the valid integer to 0
    {
        valid = 0; //User's input is invalid
        printf("Invalid expression.\n\n"); //Print statement before the program loops
    }
    else //Makes it so the expression going forward is valid
    {
        valid = 1; //The number input by the user is valid
    }

    if (valid)
    {
        printf("Possible combinations of scoring plays if a team’s score is %d:\n\n", score); //Outputs the number listed by the user then prompts the cycle of for loops
    for (int td_c_ctr = 0; td_c_ctr <= score / TD_C; td_c_ctr++) //Counts the number of Touchdowns with 2 point conversions until it's greater than or equal to the score
    {
        for (int td_fg_ctr = 0; td_fg_ctr <= score / TD_FG; td_fg_ctr++) //Counts the number of Touchdowns with fieldgoals until it's greater than or equal to the score
        {
            for(int td_ctr = 0; td_ctr <= score / TD; td_ctr++) //Counts the number of Touchdowns until it's greater than or equal to the score
            {
                for(int fg_ctr = 0; fg_ctr <= score / FG; fg_ctr++) //Counts the number of fieldgoals until it's greater than or equal to the score
                {
                    for(int safety_ctr = 0; safety_ctr <= score / SAFETY; safety_ctr++) //Counts the number of safetys until it's greater than or equal to the score
                    {
                        int total = td_c_ctr * TD_C + td_fg_ctr * TD_FG + td_ctr * TD + fg_ctr * FG + safety_ctr * SAFETY; //Combines the counters that were iterated with the types of achievable points to create the totals
                        if (total == score)
                        {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_c_ctr, td_fg_ctr, td_ctr, fg_ctr, safety_ctr); //Outputs the score once the total is the same value
                        }
                    }
                }
            }

        }
    }
    }
    }
    
}
