#include <iostream>
#include <cstdlib>
#include <ctime>

// Constant ranges to compare user input
const int MAX_NUM_BALL = 7;
const int MIN_NUM_BALL = 3;

const int MAX_RANGE_NUM = 70;
const int MIN_RANGE_NUM = 45;

const int MAX_NUM_TICKET = 100;
const int MIN_NUM_TICKET = 1;

using namespace std;

// Prototypes for each input function
int numOfBall(int *input);
int largestNum(int *input);
int numOfTicket(int *input);

// Prototype for final ticket function
void ticketNum(int numOfBall, int largestNum, int numOfTicket);

int main() {

    // Random seed based on time
    srand(time(nullptr));

    // integer variables and pointers for user input
    int numOfBallInput;
    int *ballptr = &numOfBallInput;

    int largestNumInput;
    int *largetptr = &largestNumInput;

    int numOfTicketInput;
    int *ticketptr = &numOfTicketInput;

    // Introduction statement and call of all functions
    cout << "Suggested Lottery Number Generator! \n ";
    cout << "\nEnter the number of balls you wish to pick from: \n ";

    cout << "\nThe numbers will range from (3 to 7): ";
    cin >> numOfBallInput;
    numOfBall(ballptr);

    cout << "\nThe numbers will range from (45 to 70): ";
    cin >> largestNumInput;
    largestNum(largetptr);

    cout << "\nThe numbers will range from (1 to 100): ";
    cin >> numOfTicketInput;
    numOfTicket(ticketptr);

    // Echo statements (Number of numbers, Range of Values, Number of ticket guesses)
    cout << "\nYou have selected (" << numOfBall(ballptr) << ") number(s). \n ";
    cout << "\nThe numbers will range from (1 to " << largestNum(largetptr) <<").\n ";
    cout << "\nYou have selected (" << numOfTicket(ticketptr) <<") ticket(s). \n ";

    // Echo of array of ticket(s)
    cout << "\nYOUR LOTTERY SELECTIONS ARE: \n\n";
    ticketNum(numOfBall(ballptr), largestNum(largetptr), numOfTicket(ticketptr));

    return 0;
}

int numOfBall(int *input) // Function to get number of balls for users ticket(s)
{
    while(*input < MIN_NUM_BALL | *input > MAX_NUM_BALL)
    {
        if (*input < MIN_NUM_BALL | *input > MAX_NUM_BALL)
        {
            cout << "\nInvalid number please enter numbers that range from (3 to 7): ";
            cin >> *input;
        }
    }
    return *input;
}

int largestNum(int *input) // Function to get the largest number for users ticket(s)
{
    while (*input < MIN_RANGE_NUM | *input > MAX_RANGE_NUM)
    {
        if (*input < MIN_RANGE_NUM | *input > MAX_RANGE_NUM)
        {
            cout << "\nInvalid number please enter range from (45 to 70): ";
            cin >> *input;
        }
    }
    return *input;
}

int numOfTicket(int *input) // Function to get the number of users ticket(s)
{
    while (*input < MIN_NUM_TICKET | *input > MAX_NUM_TICKET)
    {
        if (*input < MIN_NUM_TICKET | *input > MAX_NUM_TICKET)
        {
            cout << "\nInvalid number please enter range from (1 to 100): ";
            cin >> *input;
        }
    }
    return *input;
}

void ticketNum(int numOfBall, int largestNum, int numOfTicket) // Function to get unique array output of ticket(s)
{
    int array[numOfBall];
    int randomNumber = 0;

    for (int j = 0; j < numOfTicket; j++)
    {
        // Create ticket
        for (int i = 0; i < numOfBall; i++)
        {
            bool unique;
            do
            {
                unique = true;
                randomNumber = rand() % largestNum + 1;
                for (int k = 0; k < numOfBall; k++)
                {
                    if (array[k] == randomNumber)
                    {
                        unique = false;
                        break;
                    }
                }
            }while(!unique);
            // Print ticket
            array[i] = randomNumber;
            cout << array[i] << " ";
        }
        cout << "\n\n";
    }
}