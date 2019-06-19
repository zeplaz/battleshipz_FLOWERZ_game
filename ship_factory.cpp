

#include "ship_factory.hpp"


void ship_factory::operator() (int shiptype, std::vector<ships*>* prt_ship_vec, char (*matrix)[collum],bool is_AI)
{
  switch (shiptype)
    {
      /*
    case aircraft_carrier :
    break;
    */

    case battleship :
    Battleship*  prt_AC =  new Battleship();
    //Aircraft_Carrier*  newship2;
    if(is_AI)
    {
      prt_AC->set_ship_to_AI();
      prt_AC->set_location(matrix);
      prt_ship_vec->push_back(prt_AC);
    }
    else
    {
     prt_AC->set_location(matrix);
     prt_ship_vec->push_back(prt_AC);
    }
    break;
/*
    case Submarine :

    break;

    case Crusier :

    break;

    case Patrol_boat :

    break;
    */
  }
}
