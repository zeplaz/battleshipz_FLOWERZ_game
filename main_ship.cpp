
#include <iostream>
#include <ctime>

#include <string>
#include <vector>

#include "ships.hpp"
#include "game_board.hpp"
#include "ship_factory.hpp"
#include "user_interface_player.hpp"
//Set up Variables
//Set up Menu
//Set Up AI Grid
//Set up Player Grid
//Set up Playerships




using namespace  Battle_Shipz;

int main(int argc, char* argv[])
{
    game_board g_board;
    game_board* ptr_g_board = &g_board;
    user_interface_player ui_plr_usr;

   //If Quit = 1 it will exit the program
    bool run =1;
    //c_random to be realace.
     srand(time(NULL));
      //Player Selection Menu

      int ui_int_ovride;
      //inalze user inpt

      run = ui_plr_usr.Inialz_A_STATE(INIALZ);

      ui_plr_usr.cycle();
      g_board.clear();

      //

      agentz* prt_agent1  = g_board.new_agent();

      g_board.create_AI_ships(g_board.new_agent());

      g_board.set_agentz_defl_parmz(ptr_g_board);

      g_board.create_user_ships(&ui_plr_usr);
      
      g_board.create_AI_ships(prt_agent1);


      while (run)
      {
        ui_plr_usr.Inialz_A_STATE(CMD_INPUT);

         g_board.update_board();

        //  g_board.show();
        run = ui_plr_usr.cycle();

        if (g_board.enemy_ships_remain() == 0 || !g_board.Quit)
         {
            ui_plr_usr.Inialz_A_STATE(GAME_OVER);
            run = ui_plr_usr.cycle();
            std::cout << run;
         }

         //run = !g_board.Quit;
      }// endloop

//shudown?
  return 0;
}
