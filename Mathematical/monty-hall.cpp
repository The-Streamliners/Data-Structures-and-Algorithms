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

  do
  {
    do
    {
      revealedDoor = rand() % 3 + 1;
    } while (revealedDoor == chosenDoor || revealedDoor == winningDoor);

    do
    {
      remainingDoor = rand() % 3 + 1;
    } while (remainingDoor == chosenDoor || remainingDoor == revealedDoor);

    option = rand() % 2 + 1;
    if (option == 1)
    {
      if (chosenDoor == winningDoor)
      {
        stayWins++;
      }
    }
    if (option == 2)
    {
      chosenDoor = remainingDoor;
      if (chosenDoor == winningDoor)
      {
        switchWins++;
      }
    }
    games++;
  } while (games < 10000);

  cout << "Out of all the games, the contestant won " << stayWins << " times by staying with their original choice and won " << switchWins << " times by switching their choice.\n";

  return 0;
}