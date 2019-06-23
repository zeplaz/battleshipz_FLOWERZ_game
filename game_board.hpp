///game_board.hpp
#pragma once

#include <vector>
#include <forward_list>


#include "ships.hpp"
#include "ship_factory.hpp"
#include "agent_decision_component.hpp"
#include "agent_act.hpp"

using namespace Battle_Shipz;


class game_board
{
  private :

  const char water = 247;
  const char hit = 'x';
  int maxship = 5;
   //Sets Max # of ships on AI board
  char user_matrix[row][collum];
  char AI_marrix[row][collum]; //*
  const int shipnum = 5;

//unit potr_vectors
  std::vector<ships*> user_ship_vec;
  std::vector<ships*> AI_ship_vec;


  //factoreiz
  ship_factory ship_fac;


//componetz
  agent_decision_component<ships*> user_datz;
  //agent_decision_component<ships> agentz_shipz_cmp;


  std::forward_list<agentz>  agent_list;
  //lamadas for probality agent diesion mekimsn,

  public :

/////***agentopz

   void  new_agent()
   {
     agentz new_agent;
     agent_list.push_front(new_agent);
   }

   void set_agentz_defl_parmz()
   {
     for (auto agt = agent_list.cbegin(); agt != agent_list.cend(); agt++)
     {

     }
    if (empty.begin() == empty.end())
		std::cout << "forward_list 'agent_list' is emptyz.\n";
   }

//board_AIagentz




/////***startypz
//startupfuncionzon newload
  void create_user_ships();
  void create_AI_ships(agentz& for_agent);

/////***main_loopz
//update area
  void update_board();


  //

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




  inline void clear()
  {
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < collum; j++)
        {
            user_matrix[i][j] = '0';
            AI_marrix[i][j]   = '0';
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
           if (AI_marrix[i][j] == '3') //
            c++;
         }
       }
      return c;
   }


inline bool attack(int x, int y)
{
  if (AI_marrix[x][y] == '3')
  {
      AI_marrix[x][y] = 'x';
      return true;
  }
  return false;
}


};
