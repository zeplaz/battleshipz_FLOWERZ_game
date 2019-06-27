///game_board.hpp
#pragma once

#include <vector>
#include <forward_list>
#include <memory>


#include "ships.hpp"
#include "ship_factory.hpp"

#include "agent_decision_component.hpp"
#include "agent_act.hpp"

#include "user_interface_player.hpp"

using namespace Battle_Shipz;


class agentz;

class game_board
{
  private :


  struct fixed_run_paramatrz
  {
    const int ply_unitz=3;
    const int agent_limit=5;
    const int ship_limit=20;
    const int max_start_ships = 5;
    const char water = 247;
    const char hit = 'x';

   }fixed_run_paramatrz;

  struct log_datz_data
  {
    int total_ships_intal;
    int total_ships_final;

    size_t ship_current;

    int max_player_count;
    int facotory_toal_count;
    int factory_ply_count;

    int agent_ship_count;
    int number_damge_reocd;

    double damge_avg;
    double ratio_damge_ai;


  }log_datz_data;


  char quit;
   //Sets Max # of ships on AI board
  char user_matrix[row][collum];
  char AI_marrix[row][collum]; //*
  char (*ptr_USR_matrix)[row][collum] = &user_matrix;
  char (*ptr_AI_marrix)[row][collum] = &AI_marrix;
  uint64_t currentGB_count;
  int pos1, pos2;
  user_interface_player* toMAIN_UI_prt;
// struct of some sarmaz

//unit potr_vectors
  std::vector<ships*> user_ship_vec;
  std::vector<ships*> AI_ship_vec;




  //factoreiz
  ship_factory ship_fac;


//componetz
  //agent_decision_component<ships*> user_datz;
  //agent_decision_component<ships> agentz_shipz_cmp;


  std::forward_list<agentz>  agent_list;
  //lamadas for probality agent diesion mekimsn,

  public :

  int enemy_shipz;
  bool Quit = 0;
  ~game_board()
   {
    for (size_t i=0; i<user_ship_vec.size(); i++)
     {
       delete[] user_ship_vec.at(i);
       user_ship_vec.pop_back();
     }

     for (size_t i = 0; i< AI_ship_vec.size(); i++)
      {
        delete[] AI_ship_vec.at(i);
        AI_ship_vec.pop_back();
      }
   }

   game_board() = default;

  game_board* prt_gb()
   {
     return this;
   }

   //char (*)[row][collum] get_ai_board_data()
   auto get_ai_board_data()
   {
     std::shared_ptr<char(*)[collum]> ptr_AI_marrix = std::make_shared<char (*)[collum]>(AI_marrix);
     return ptr_AI_marrix;
   }

   //get_player_matrix_data()

   /////***agentopz

   agentz*  new_agent();

   void set_agentz_defl_parmz(game_board* prt_toactive_gid);
  //board_AIagentz

/////***startypz
//startupfuncionzon newload
  void create_AI_ships(agentz* for_agent);


  void create_user_ships(user_interface_player* for_player);
/////***main_loopz
  //update area

  void update_board();


   void update_usr_prob()
   {
      int us_num_ship = user_ship_vec.size();
      int aiknown_toal = AI_ship_vec.size();
      log_datz_data.ship_current = us_num_ship+aiknown_toal;
     //user_ship_vec.size() !=
    //  double eror_vk = static_cast<double>(user_datz.diffrence_in_user_known(log_datz_data.ship_current));
      // user_datz.regstar_unit_inmap();
      std::cout <<"AI SHOULD_BE THINKINherz..shoul use tela t-0 cmd update on plzcounzt:"
      //  << eror_vk << "-/ERRO_VK"  << '\n'
        << aiknown_toal <<"<-agent_idfied_toalshipz"<< '\n' << '\n';

     }

     bool usr_pollz()
     {
       if(!toMAIN_UI_prt->fire_cordz(pos1,pos2))
        {
         std::cout <<"some eror in firecontlz;" << '\n';
         std::cout << "you want to quit? input q to quit, or anything else to contune";
         std::cin >> quit;
         if(quit =='q')
           {
             return false;
           }
         std::cin.clear();
         std::cin.ignore(10000, '\n');
      //   return true;
        }
        else
        {
          if(game_board::attack(pos1,pos2))
           {
            std::cout << "Hit succesful" << '\n';
           }
          else
           {
            std::cout << "Hit Failed" << '\n'; //If there is no hit
            std::cout << "Remaining Ships: " << game_board::enemy_ships_remain() << '\n';
            enemy_shipz = game_board::enemy_ships_remain();
           }
           return true;
        }
     }


  //
  //old funcionz

  inline void clear()
  {
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < collum; j++)
        {
            user_matrix[i][j] = '#';
            AI_marrix[i][j]   = '#';
        }
    }
  }

inline void show()
{
  for (int i = 0; i < row; i++)
  {
      for (int j = 0; j < collum; j++)
      {
          std::cout << user_matrix[i][j] << " ";
      }
      std::cout << '\n';
    }

    std::cout << "------------------------" << '\n';

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < collum; j++)
        {
          std::cout << AI_marrix[i][j] << " ";
        }
      std::cout << '\n';
     }

    std::cout << "------------------------" << '\n';
}

 inline int enemy_ships_remain()
  {
      int c = 0;
      for (int i = 0; i < row; i++)
      {
        for (int j = 0; j < collum; j++)
         {
           if (AI_marrix[i][j] =='V' || AI_marrix[i][j] =='X') //
            c--;
            if(AI_marrix[i][j] =='S' || AI_marrix[i][j] == 'B' ||AI_marrix[i][j]=='C')
            {c++;}
         }
       }
      return c;
   }


inline bool AI_attack_player(int x, int y)
{
  if (user_matrix[x][y] == 'C' || user_matrix[x][y] == 'B' || user_matrix[x][y] == 'C' )
  {
      user_matrix[x][y] = 'X';
      return true;
  }
}

inline bool attack(int x, int y)
{

  if (AI_marrix[x][y] == 'C' || AI_marrix[x][y] == 'B' || AI_marrix[x][y] == 'C' )
  {
      AI_marrix[x][y] = 'X';
      return true;
  }
  return false;
}


};
