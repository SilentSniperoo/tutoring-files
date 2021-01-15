// Use "game.h" to get "Start", "playing", "Update", and "End"
#include "game.h"

// There should be a function PROTOTYPE named "Start"
// The function has an integer return type
// The function has no parameters (the parameter type is void)
int main(void)
{
  // Call the Start function
  Start();
  // Loop until playing is no longer true
  while (playing)
  {
    // Call the Update function
    Update();
  }
  // Call the End function
  End();
}
