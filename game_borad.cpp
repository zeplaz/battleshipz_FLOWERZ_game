
#include "game_board.hpp"


void game_board::create_user_ships()
{ //int (*prt_matrix)[row][collum] = &matrix;
 //int* ptr_matrix = &matrix[row][collum];
  int ship_type;
  for (int i=0; i<2; i++)
  {
    std::cout << "select Ship type: 1:Aircraft_Carrier, 2:Battleship, 3:Submarine, 4:Crusier, 5:Patrol_boat";
    std::cin >> ship_type;
    if(ship_type >5 || ship_type<1)
      {
        std::cout << "ERROR NONEVAILD SHIP";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        i--;
      }
     else
      {
        ship_fac(ship_type,&user_ship_vec,user_matrix,false);
        // so it ends the loading for testing!
      }
   }
}

void game_board::create_AI_ships()
{
  int ship_type;

  ship_type=2;// cuz only class setup!
  ship_fac(ship_type,&AI_ship_vec,AI_marrix,true);

}
