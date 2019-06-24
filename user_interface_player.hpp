
#pragma once

#include <unordered_map>
#include <vector>
#include <iostream>

#include "tela_cmdz.h"
//#include "tela_dispacher.hpp"

namespace Battle_Shipz {
  enum STATE_UI{INIALZ,DEBUG,UNIT_SETUP,WAITING,CMD_INPUT,GAME_OVER};
}


class user_interface_player
{
  private :
  std::vector<int> ship_index;
  std::vector<CMD_Z*>  cmd_line_list_prt_vec;
  //std::unordered_map<int,agentz*> call_agent_list;
  int UI_state =-1;
  bool new_state;

  char char_symb;
  public :

  int get_state()
  {
    return UI_state;
  }


  int  intrfcz_Inialz()
  {
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

    }
    if(Select ==4)
    {
      run_help();
    }

  return Select;
}

  void run_help()
  {
    std::cout << "&&&+++++__(**************)<<||" <<'\n' << "|->|WELCOME TO HELP!...there is little info now...but you are asks to enter" << '\n'
    << "ship types, working ship times AC, B, S all other are invald dontt ry" << '\n'
    << " ---------------------***|you then must enter, locaion or if to roate the fornt" <<'\n'
    << "will allow you to avoid collions as later ships crashing cause damage!"
    << " cordents, which tests location for other ships, if a hit is regisar it updates,"<< '\n'
    << " ships can be moved, but currntly the interface is not up.." << '\n'
    << "easy exit is inputing x y" << '\n'
    << " above the gide size, it will get pickedup and offer you a" << '\n'
    << "quick termnation via q. try keep numarc"<< '\n'
    << " as i mean, not all bad input results in clean exists yet."<< '\n'
    << "soo ya.. more stuff will be added. and oh debug mode will be dugable i hope.. "
    << '\n'<< '\n';
  }
//void run_inlizt();

void update()
{
  std::cout << "update_progrgz_UI" << '\n';

 //fire_cordz(int& pos1, int&pos2);
}

bool cycle()
  {
    std::cout <<"STATEID:" << UI_state << '\n';

    if(UI_state!=-1)
    {
      if(!new_state)
      {
        std::cout <<"NOT NEW STATE NORMLUPDZ" <<'\n';
        update();
        return true;
      }

    if(new_state)
     {
      if(UI_state==INIALZ)
      {
        new_state = false;
        std::cout << "inside _ilsizeswitch...";
        return intrfcz_Inialz();
      }

      if(UI_state==UNIT_SETUP)
      {
      //return  usr_add_unit();
      }

      if(UI_state==GAME_OVER)
      {
        new_state = false;
        return game_over();
      }

      if( UI_state==CMD_INPUT)
      {
        new_state = false;
        return true;
      }
     }
    return false;
   }
  new_state = false;
  return   true; //defultpassover
  }

void usr_add_unit()
{

}

bool game_over()
{
   std::cout << "Remaining Ships: " << '0' << '\n';
   std::cout << "You are out of ships!";

   return (keybord_text_input(GAME_OVER));
}

  bool fire_cordz(int& pos1, int&pos2)
  {
    std::cout << "Please input Location To attack (X then Y):";
    std::cin >> pos1 >> pos2; // Asking player where to "fire"

    if (pos1 < 0 || pos1>row || pos2 < 0 || pos2>collum)
    {
      char quit;
      std::cout << "ERROR NOT VAILD POSTION!" << '\n';
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      return false;

      }

      std::cin.clear();
      std::cin.ignore(10000, '\n');
      return true;
    }


  bool Inialz_A_STATE(const int& in_STATE)
  {
    std::cout <<"#->insize_state_inlziaser:stiwch to: " << in_STATE <<"from: " << UI_state<<'\n';
    switch(in_STATE)
    {
      case INIALZ :
      {
        UI_state = INIALZ;
        new_state= true;
        return true;
       break;
      }
      case UNIT_SETUP :
      {
        UI_state = UNIT_SETUP;
        new_state= true;
        return true;
       break;
      }
      case CMD_INPUT :
      {
        UI_state = CMD_INPUT;
        new_state=true;
        return true;
       break;
      }

      case GAME_OVER :
      {
        UI_state = GAME_OVER;
        new_state=true;
        return true;
       break;
      }

      //default WAITING :
      return true;
    }
    return false;

  }




  void add_unit();

  void remove_unit();

  void enter_cmd_order();


  bool keybord_text_input(int inp_type)
  {
    if (inp_type == GAME_OVER)
    {
      std::cout <<"WOULD YOU LIKE TO QUIT? or something else.. q to quit";
      std::cin  >> char_symb;
      std::cout << '\n';
      if(char_symb =='q')
      {
        return false;
      }
      return true;
    }
  }
  bool terminal_text_out(std::string& out_string)
  {
    return false;
  }

  bool scedual_tela();


};
