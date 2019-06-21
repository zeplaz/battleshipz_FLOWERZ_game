

#include "ship_factory.hpp"


void ship_factory::operator() (int shiptype, std::vector<ships*>* prt_ship_vec, char (*matrix)[collum],bool is_AI)
{
  switch (shiptype)
    {

    case aircraft_carrier :
    {
      Aircraft_Carrier*  prt_AC =  new Aircraft_Carrier();

      if(is_AI)
      {
        prt_AC->set_ship_to_AI();
        prt_AC->set_location(matrix);
        prt_ship_vec->push_back(prt_AC);
      }
      else
      {
       prt_AC->set_ship_to_user();
       prt_AC->set_location(matrix);
       prt_ship_vec->push_back(prt_AC);
       //std::cout <<"NEW ai AC ID: " << prt_AC->get_id();
      }

     break;
     }

    case battleship :
 {
    Battleship*  prt_B =  new Battleship();

    if(is_AI)
    {
      prt_B->set_ship_to_AI();
      prt_B->set_location(matrix);
      prt_ship_vec->push_back(prt_B);
      std::cout <<"NEW ai B ID: " << prt_B->get_id() << '\n' << '\n';
          
    }
    else
    {
     prt_B->set_ship_to_user();
     prt_B->set_location(matrix);
     prt_ship_vec->push_back(prt_B);
     std::cout <<"NEW player B ID: " << prt_B->get_id() << '\n'<< '\n';
    }
    break;
    }

    case submarine :
    Submarine*  prt_S =  new Submarine();
    {
    if(is_AI)
    {
      prt_S->set_ship_to_AI();
      prt_S->set_location(matrix);
      prt_ship_vec->push_back(prt_S);
      std::cout <<"NEW ai S ID: " << prt_S->get_id() << '\n' << '\n';


    }
    else
    {
     prt_S->set_ship_to_user();
     prt_S->set_location(matrix);
     prt_ship_vec->push_back(prt_S);
     std::cout <<"NEW player S ID: " << prt_S->get_id() << '\n' << '\n';
    }
    break;
    }
    /*
    case Crusier :

    break;

    case Patrol_boat :

    break;
    */
  }
}
