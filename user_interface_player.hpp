/*
USER_INTERFACE_PLAYER.HPP
this is a help[er class to deal with user inptus, keepingit safe, also be useful to plug in usb stuff,
there a few vecs holding some data, and a base state system. will be intregaed into polling.

*/

#pragma once

#include <unordered_map>
#include <vector>
#include <iostream>

#include "tela_cmdz.h"
//#include "tela_dispacher.hpp"

  namespace Battle_Shipz
  {
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
    int status_cmd;
    char char_symb;

    public :


//state funcz
    int get_state()
    {
      return UI_state;
    }

//func to set next state.
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

        case WAITING :
        {
          UI_state = WAITING;
          new_state=false;
          return true;
         break;
        }
        //default WAITING :
        return true;
      }
      return false;

    }

//interface beging loadpage.
  bool  intrfcz_Inialz()
  {
    std::cout << "1: Play Game \n"
        "2: Quit Game \n"
                            //"3: Game Credits \n"
        "4: How To Play \n";

    int Select; //Variable to allow player to select a option
    std::cout << "Please Enter a Number from the Options: ";
    std::cin >> Select;

    if (Select == 1)
    {
      std::cout << "\n"
      "\n" "\n";
      return true;
    }

    if (Select == 2)
    {
      return false;
    }

    if(Select ==4)
    {
      run_help();
    }

   return true;
   }


//runs of the srtate outputzetc
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

  bool game_over()
  {
     std::cout << "Remaining Ships: " << '0' << '\n';
     std::cout << "You are out of ships!";

     return (keybord_text_input(GAME_OVER));
  }


  bool waiting()
  {
    return true;
  }

  int cmd_inputz()
  {
    std::cout << "||->YOU HAVE ACESSED CMD INPUT< GIVE CMD_L: ";

      std::cin >> char_symb;
      //  enum CMD_Z{ FORCE_STATE,INPUT_EVT,DISIZON,WRITE_DEBUG_LOG,VERBOSITY};
      //when log class done!
      if (char_symb == WRITE_DEBUG_LOG)
      {

      }

      if (char_symb == FORCE_STATE)
      {
        if(!keybord_text_input(FORCE_STATE))
          {
            return -1;
          }

       return FORCE_STATE;
       }
   }


//void run_inlizt();

//diffrent kinds of updates, which can be threaded to redcue costs. or to allow for difrnt pathways to fire.

//the genreal update, should be a minmial as possavle. could also do any cleanup or gcscans a just alittle each time.
  void update()
   {
    std::cout << "update_progrgz_UI" << '\n';
   //fire_cordz(int& pos1, int&pos2);
   }


//the genreal cycle of currnt loaded state, and ttrger the everytime updates, retruvals
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
        std::cout << "inside _ilsizeswitch..."<<'\n'
        <<"______________________________________________"<<'\n';
        Inialz_A_STATE(WAITING);
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
         status_cmd = cmd_inputz();

         if(status_cmd ==-1)
         {
          new_state = false;
          return false;
         }


         return true;
        }


       return false;
      }

   new_state = false;
   return   true;
    //defultpassover
   }
   return false;
 }

  void usr_add_unit();


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

  void add_unit();

  void remove_unit();

  void enter_cmd_order();


  bool keybord_text_input(int inp_type)
  {

    //inout for GAMEOVER
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

  //inout for FORCE_STATE
    if (inp_type == FORCE_STATE)
    {
      int f_state;
      std::cout << "^_ENTER STATE# FORCED:STATE_UI{INIALZ,DEBUG,UNIT_SETUP,WAITING,CMD_INPUT,GAME_OVER}" << '\n';
      std::cin >> f_state;

      if(f_state =='0'|| f_state =='1'|| f_state =='2'||f_state =='3'||f_state =='4'||f_state =='5')
      {
         UI_state =f_state;

         std::cout << "SET state as NEW OR old=defult to set NEW y or 1:";
         std::cin >> f_state;

        if(f_state =='1' || f_state=='y')
        {
          new_state = true;
        }
        else   new_state = false;
        return true;
        }
      else
      {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout <<  '\n' << "NOT VAILD STATE q to quit:";
        std::cin >> f_state;

        if( f_state== 'q')
        {
          return false;
        }
        std::cin.clear();
        std::cin.ignore(10000, '\n');
      }
      return true;
    }
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    return true; //defult run through
   }

  bool terminal_text_out(std::string& out_string)
  {
    return false;
  }

  bool scedual_tela();


};
