///game_board.hpp
#pragma once

#include <vector>

#include "ships.hpp"
#include "ship_factory.hpp"

using namespace Battle_Shipz;


class game_board
{
  private :
  //const int row = 10; // Sets up Grid*
  //const int collum = 10; // Sets up grid
  const char water = 247; // Water on grid
  const char hit = 'x'; //Displyed when a ship is hit
  //const char Pship = 's'; //Displayed where a player places a ship
  int maxship = 5;
   //Sets Max # of ships on AI board
  char user_matrix[row][collum];
  char AI_marrix[row][collum]; //*
  const int shipnum = 5;
  std::vector<ships*> user_ship_vec;
  std::vector<ships*> AI_ship_vec;
  ship_factory ship_fac;

  public :

  void create_user_ships();
  void create_AI_ships();

 ~game_board()
 {
   for (size_t i = user_ship_vec.size(); i<0; i--)
    {
      delete[] user_ship_vec.at(i);
      user_ship_vec.pop_back();
    }

    for (size_t i = AI_ship_vec.size(); i<0; i--)
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
