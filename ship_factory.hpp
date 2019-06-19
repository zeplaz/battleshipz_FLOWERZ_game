
#pragma once

#include "ships.hpp"
using namespace  Battle_Shipz;

//#include "Aircraft_Carrier.hpp"


class ship_factory
  {
    public :
      void operator() (int shiptype, std::vector<ships*>* prt_ship_vec, char (*matrix)[collum],bool is_AI);
  };
