#include <iostream>



 void playGuessTheNumber()

{
  int target_number;
  int guess;

  // randomly generates a number between 1 - 10
  srand(time(0));
  target_number = (rand() % 10) + 1;

  // ask user to guess a number
  std::cout << "\nWelcome to Guess the Number game...\n";
  std::cout << "\nGuess a number between 1 and 10 then hit enter...\n";
  std::cin >> guess;

  for (int attempts = 0; attempts < 4; attempts++)

  {
    if (guess == target_number)
    {
      // if the user guesses correctly
      std::cout << "That's correct...!\n";
      break;
    }

    else if (guess < target_number)
    {
      // if the users guess is lower than the target number
      std::cout << "That's too low, guess again...\n";
      std::cin >> guess;
    }

    else
    {
      // if the users guess is higher than target number
      std::cout << "That's too high, guess again...\n";
      std::cin >> guess;
    }

    if (attempts == 3)
    {
      // if user uses up all 5 of their guesses
      std::cout << "\nYou lose...! The correct number was " << target_number << "\n";
    }
  }
}

 void playRockPaperScissorsGame()
{
  char player_choice;
  char computer_guess;
  char play_again;
  bool is_running = true;
  int comp_win_tally = 0;
  int player_win_tally = 0;

  std::cout << "\nWelcome to Rock, Paper, Scissors!\n";

  //seed random number at start 
  srand(time(0));

  while (is_running)
  {
    // player options
    
    std::cout << "\nChoose one of the following:\n";
    std::cout << "\nR = Rock\n";
    std::cout << "P = Paper\n";
    std::cout << "S = Scissors\n";
    std::cout << "\nEnter your choice (R/P/S)...\n";
    std::cin >> player_choice;

    // Convert player input to uppercase to handle lowercase input
    player_choice = toupper(player_choice);

    // Generate random choice for computer
    int random_number = (rand() % 3) + 1;

    // assign rock, paper, scissors based on number
    if (random_number == 1)
    {
      computer_guess = 'R';
    }
    else if (random_number == 2)
    {
      computer_guess = 'P';
    }
    else
    {
      computer_guess = 'S';
    }

    // output player choice
    switch (player_choice)
    {
      case 'R':
        std::cout << "\nYou chose Rock...\n";
        break;
      case 'P':
        std::cout << "\nYou chose Paper...\n";
        break;
      case 'S':
        std::cout << "\nYou chose Scissors...\n";
        break;
    }

    // output computer choice
    switch (computer_guess)
    {
      case 'R':
        std::cout << "Computer chose Rock...\n";
        break;
      case 'P':
        std::cout << "Computer chose Paper...\n";
        break;
      case 'S':
        std::cout << "Computer chose Scissors...\n";
        break;
    }

    if (player_choice == computer_guess)
    {
      std::cout << "\nIt's a draw!\n";
    }
    else if (
      (player_choice == 'R' && computer_guess == 'S') || // Rock beats Scissors
      (player_choice == 'P' && computer_guess == 'R') ||  // Paper beats Rock
      (player_choice == 'S' && computer_guess == 'P'))    // Scissors beats Paper
    {
      std::cout << "\nYou win!\n";
      player_win_tally++;
    }
    else
    {
      std::cout << "\nYou lose!\n";
      comp_win_tally++;
    }

    // ask player if they want to play again 
    std::cout << "\nWould you like to play again? y/n\n";
    std::cin >> play_again;

    if (play_again == 'n')
    {
      is_running = false;
      std::cout << "\nFinal scores...\n";
      std::cout << "\nPlayer: " << player_win_tally << "\n";
      std::cout << "Computer: " << comp_win_tally << "\n";

      // Determine and output the overall winner
      if (player_win_tally > comp_win_tally)
      {
        std::cout << "\nYou are the overall winner!\n";
      }
      else if (comp_win_tally > player_win_tally)
      {
        std::cout << "\nThe computer is the overall winner!\n";
      }
      else
      {
        std::cout << "\nIt's a tie overall!\n";
        continue;
      }
    }
  }
}

 int main()
 {
   char game_choice;
   char play_again;
   bool is_running = true; 

   while (is_running)
   {
     // welcome message and game choice
     std::cout << "\nHello there, welcome to Console Games.\n";
     std::cout << "\nPress 1 to play Guess The Number Game\n";
     std::cout << "Press 2 to play Rock, Paper, Scissors\n";
     std::cout << "\nPress 'q' to quit\n";

     std::cin >> game_choice;

     if (game_choice == '1')
     {
       playGuessTheNumber();
     }
     else if (game_choice == '2')
     {
       playRockPaperScissorsGame();
     }
     else if (game_choice == 'Q' || game_choice == 'q')
     {
       std::cout << "\nGoodbye...\n";
       break;
     }

     //asking player if they want to play again 
     std::cout << "\nWould you like to play again? (y/n):\n";
     std::cin >> play_again;

     if (play_again == 'n')
     {
       is_running = false;
       std::cout << "\nGoodbye...\n";
     }
     else if (play_again == 'y')
     {
       continue;
     }
    
  

   }
   return 0;
 }

 