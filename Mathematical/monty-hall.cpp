#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
  int games = 0;
  int stayWins = 0;
  int switchWins = 0;
  int chosenDoor;
  int remainingDoor;
  int revealedDoor;
  int winningDoor;
  int option;

  srand(time(NULL));
  chosenDoor = rand() % 3 + 1;
  winningDoor = rand() % 3 + 1;

  /*Beginning of the iterting loop of our simulation*/
  do
  {
    // If randomly, the revealed door turns out to be the chosen door and the door with the prize inside, this is the condition
    do
    {
      revealedDoor = rand() % 3 + 1;
    } while (revealedDoor == chosenDoor || revealedDoor == winningDoor);

    // If randomly, the remaining door turns out to be the chosen door, we select the remaining door as the revealed door
    do
    {
      remainingDoor = rand() % 3 + 1;
    } while (remainingDoor == chosenDoor || remainingDoor == revealedDoor);

    // IMPORTANT STEP: Written below is the condition for which incrementation happens as per the condition
    option = rand() % 2 + 1;
    if (option == 1)
    {
      if (chosenDoor == winningDoor)
      {
        stayWins++; //Incrementing the stayWins variable when one simulation wins the prize with the previously chosen door
      }
    }
    if (option == 2)
    {
      chosenDoor = remainingDoor;
      if (chosenDoor == winningDoor)
      {
        switchWins++; //Incrementing the switchWins variable when one simulation wins the prize after switching from the previous choice
      }
    }
    games++; //Incrementing the total number of games played
  } while (games < 10000);

  cout << "Out of all the games, the contestant won " << stayWins << " times by staying with their original choice and won " << switchWins << " times by switching their choice.\n";

  return 0;
}