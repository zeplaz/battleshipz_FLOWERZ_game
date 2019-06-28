/*
SHIP_FACTORY.hpp
  |-$-|stable alpha 0.00001
  TOD0: make sure use of base pointer is not slicing off data later on... or
  the proper overloads can acess correct data, and its lives. once more aspect finalzed
  will add other ship classes...for time being waiting to see final setup.
*/

#pragma once
#include "ships.hpp"
using namespace  Battle_Shipz;

/*SHIP FACTORY IS CURRENTLY ONLT A FUNCTOR
   ->takes a gide matrix and will after some baisc tests, place new ship base pointer to the ship vec,
   NOTE that the ships created ARE of the full class of that ship type, overloads are provided, for nessary functions
   otherwise, acessor funcions are in base as pure vertual or vertialz.acessbale.{need to conferm slicing does not interfar.}
   run the consturction tests and if vaild place the ship in the ininstal gride..
   future adding, need to be perhaps throw in othr places it could be sent vs the raw ship vector..
   threaded with the trasfer of raw shipe from the facotory//
   to be injecked and prorly registart were it atlest needs to be to be registar somewhere.
*/

  class ship_factory
    {
      public :
        ships* operator() (int shiptype, std::vector<ships*>* prt_ship_vec, char (*matrix)[collum],bool is_AI);
    };
