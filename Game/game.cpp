// Use <iostream> to get "std::cout" and "std::endl"
#include <iostream>
// Use <random> to get "srand" and "rand"
#include <random>
// Use <ctime> to get "time"
#include <ctime>

// Declared as "extern" in "game.h"
bool playing = true;

// The map should be an unnamed struct with only one instance named "map"
struct
{
  // The struct should contain an integer named "width"
  int width;
  // The struct should contain an integer named "height"
  int height;
} map;

// There should be a "Position" struct with one instance named "player"
struct Position
{
  // The struct should contain an integer named "column"
  int column;
  // The struct should contain an integer named "row"
  int row;
} player;

// There should be a constant "coin_count" that controls the number of coins
const int coin_count = 5;

// There should be a "Coin" struct with an array of instances named "coins"
// The array of instances should use "coin_count" and an empty initializer list
struct Coin
{
  // The struct should contain a Boolean named "alive"
  bool alive;
  // The struct should contain a "Position" named "position"
  Position position;
} coins[coin_count] = {};

// There should be a function named "IsPosition"
// The return type of the function is a Boolean
// The parameters of the function are:
//  - a pointer to a constant "Position" named "position"
//  - an integer named "column"
//  - an integer named "row"
bool IsPosition(const Position * position, int column, int row)
{
  // Return true if the position's column and row are equal to the others
  return position->column == column && position->row == row;
}

// There should be a function named "PrintTile"
// The function has no return value (the return type is void)
// The parameters of the function are:
//  - an integer named "column"
//  - an integer named "row"
void PrintTile(int column, int row)
{
  // If the player is at the column and row
  if (IsPosition(&player, column, row))
  {
    // Print the player
    std::cout << 'p';
    // Don't print anything else (return out of the function)
    return;
  }

  // Loop through the coins
  for (int i = 0; i < coin_count; ++i)
  {
    // Get a pointer to the current coin
    Coin * coin = (coins + i);
    // Skip the coin if it is not alive (already collected)
    if (coin->alive == false)
      continue;
    // If the coin is at the column and row
    if (IsPosition(&coin->position, column, row))
    {
      // Print the coin (a, b, c, d, e...)
      std::cout << static_cast<char>('a' + i);
      // Don't print anything else (return out of the function)
      return;
    }
  }

  // Print an empty tile
  std::cout << ' ';
}

// There should be a function named "PrintMap"
// The function has no return value (the return type is void)
// The function has no parameters
void PrintMap()
{
  // Print top border
  for (int column = 0; column < map.width + 2; ++column)
  {
    std::cout << '+';
  }
  // Move to next line
  std::cout << std::endl;
  // Print middle section
  for (int row = 0; row < map.height; ++row)
  {
    // Print left border
    std::cout << '+';
    // Print tiles
    for (int column = 0; column < map.width; ++column)
    {
      PrintTile(column, row);
    }
    // Print right border
    std::cout << '+';
    // Move to next line
    std::cout << std::endl;
  }
  // Print bottom border
  for (int column = 0; column < map.width + 2; ++column)
  {
    std::cout << '+';
  }
  // Move to next line
  std::cout << std::endl;
}

// There should be a Boolean named "seeded" which starts as false
bool seeded = false;

// There should be a function called "PrintMap"
// The function has an integer return type
// The function has an integer parameter named "end"
int RandomIndex(int end)
{
  // If seeded is false
  if (!seeded)
  {
    // Use srand and time to seed the random number generator
    srand(static_cast<unsigned>(time(0)));
    // Set seeded to true
    seeded = true;
  }
  // Return a value from 0 to end - 1 by using the modulo operator
  return rand() % end;
}

// There should be a function named "Start"
// The function has no return value (the return type is void)
// The function has no parameters
void Start()
{
  // Print instructions to enter the width
  std::cout << "Enter the width of the map: " << std::endl;
  // Read the width of the map from the console
  std::cin >> map.width;

  // Print instructions to enter the height
  std::cout << "Enter the height of the map: " << std::endl;
  // Read the height of the map from the console
  std::cin >> map.height;

  // Loop through the coins
  for (int i = 0; i < coin_count; ++i)
  {
    // Set the coin to alive (not collected yet)
    coins[i].alive = true;
    // Set the coin to a random column using RandomIndex
    coins[i].position.column = RandomIndex(map.width);
    // Set the coin to a random row using RandomIndex
    coins[i].position.row = RandomIndex(map.height);
  }
}

// There should be a function named "CollectCoins"
// The function has a Boolean return type
// The function has no parameters
bool CollectCoins()
{
  // Loop through the coins
  for (int i = 0; i < coin_count; ++i)
  {
    // Get a pointer to the current coin
    Coin * coin = (coins + i);
    // If the coin is at the column and row of the player
    if (IsPosition(&coin->position, player.column, player.row))
    {
      // Set the coin to not alive (collected)
      coin->alive = false;
    }

    // If the coin is alive (not collected yet)
    if (coin->alive)
      // Return false (not all of the coins have been collected yet)
      return false;
  }
  // If the loop finishes without returning false, that means all the
  // coins have been collected, so return true
  return true;
}

// There should be a function named "Update"
// The function has no return value (the return type is void)
// The function has no parameters
void Update()
{
  // Clear the screen
  /* system("clear"); */
  system("clear");
  // Print the map using PrintMap
  PrintMap();
  // If the coins have been collected (use CollectCoins)
  if (CollectCoins())
  {
    // Set playing to false
    playing = false;
    // Don't do anything else (return out of the function)
    return;
  }

  // Print instructions to enter w, a, s, or d to move or q to quit
  std::cout << "Enter w, a, s, or d to move or q to quit: ";
  // Read the move or quit input
  char input = 'x';
  std::cin >> input;

  // Use a switch statement to handle the move or quit input
  switch (input)
  {
  case 'W':
  case 'w':
    // On 'W' or 'w', move the player up (decrease the player's row)
    --player.row;
    if (player.row < 0) player.row = 0;
    break;
  case 'S':
  case 's':
    // On 'S' or 's', move the player down (increase the player's row)
    ++player.row;
    if (player.row >= map.height) player.row = map.height - 1;
    break;
  case 'A':
  case 'a':
    // On 'A' or 'a', move the player left (decrease the player's column)
    --player.column;
    if (player.column < 0) player.column = 0;
    break;
  case 'D':
  case 'd':
    // On 'D' or 'd', move the player right (increase the player's column)
    ++player.column;
    if (player.column >= map.width) player.column = map.width - 1;
    break;
  case 'Q':
  case 'q':
    // On 'Q' or 'q', set playing to false
    playing = false;
    break;
  default:
    // On any other input, print an error message, like "Oops! Bad input!"
    std::cout << "Oops! Invalid input!" << std::endl;
    break;
  }
}

// There should be a function named "End"
// The function has no return value (the return type is void)
// The function has no parameters
void End()
{
  // Put a breakpoint here if you want to debug collecting the last coin
  // Print a goodbye message to the player
  std::cout << "Goodbye!" << std::endl;
}
