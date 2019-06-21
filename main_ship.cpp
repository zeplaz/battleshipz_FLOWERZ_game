
#include <iostream>
#include <ctime>

#include <string>
#include <vector>

#include "ships.hpp"
#include "game_board.hpp"
#include "ship_factory.hpp"
//Set up Variables
//Set up Menu
//Set Up AI Grid
//Set up Player Grid
//Set up Playerships




using namespace  Battle_Shipz;

int main(int argc, char* argv[])
{
  game_board g_board;

  bool Quit = 0; //If Quit = 1 it will exit the program
  //Player Selection Menu

  std::cout << "1: Play Game \n"
      "2: Quit Game \n"
      "3: Game Credits \n"
      "4: How To Play \n";

  int Select; //Variable to allow player to select a option
  std::cout << "Please Enter a Number from the Options: ";
  std::cin >> Select;

  if (Select == 1)
  {
      std::cout << "\n"
          "\n"
          "\n";

      srand(time(NULL));

      g_board.clear();
      g_board.create_user_ships();
      g_board.create_AI_ships();
      //g_board.show();
      //g_board.show(); // Shows AI Board (Testing Feature only)*
      std::cout << "------------------------" << '\n';
      // setshipsuser();
      // show();
      int pos1, pos2;

      while (1)
      {   g_board.show();
          std::cout << "Please input Location To attack (X then Y):";
          std::cin >> pos1 >> pos2; // Asking player where to "fire"
          if (pos1 < 0 || pos1>row || pos2 < 0 || pos2>collum)
          {
            char quit;
            std::cout << "ERROR NOT VAILD POSTION!" << '\n';
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "you want to quit? input q to quit, or anything else to contune";
            std::cin >> quit;
            if(quit =='q')
              {
                break;
              }
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
          }

          if (g_board.attack(pos1, pos2)) //If the hit is succesful
              std::cout << "Hit succesful" << '\n';
          else
          {
            std::cout << "Hit Failed" << '\n'; //If there is no hit
            std::cout << "Remaining Ships: " << g_board.enemy_ships_remain() << '\n';

          }

      if (g_board.enemy_ships_remain() == 0)
        {
        std::cout << "Remaining Ships: " << '0' << '\n';
        std::cout << "You are out of ships!";
        system("pause");
        }
        g_board.clear();
        g_board.update_board();

      }// endloop
    }// end if


return 0;
}
