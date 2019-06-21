//ship.hpp

#pragma once

#include <iostream>
#include <vector>
#include <random>
//#include <functional>
#include <random>
#include <bitset>
#include <cassert>


#include "placeable_object_component.hpp"



using namespace Battle_Shipz;



  class ships
  {
    private :
    size_t ship_size = 0;

    protected :

    int  id;
    static int next_ship_id;
    //static int be_NextValidID;
    int  location[2];
    bool rotation;
    bool AI_Ship;
    bool alive;
    bool disabled;

    //compontelistz
    placeable_object_component<int> ojk_ship_placr;


    //genratorezrad
    rad_genz rad_rowH{0,row-ship_size};
    rad_genz rad_colH{0,collum-ship_size};
    //distrabutions
    public :

    virtual ~ships() =  default ;

     ships(int id)
    {
      set_id(id);
    }

    inline virtual void set_id(int val)
    {
      assert ((val>=next_ship_id)&& "<ships::set_id: broken ID>");
      id = val;
      next_ship_id=id+1;
    }

    inline virtual int get_id()
    {
      return id;
    }


    inline virtual bool bool_radom()
    {
      return ojk_ship_placr.randomgen_bool();
    }

    inline virtual void set_ship_to_AI()
      {AI_Ship = true;}
      inline virtual void set_ship_to_user()
        {AI_Ship = false;}

    inline virtual bool is_ship_AI()
      {return AI_Ship;}

    inline virtual bool get_Rotation()
        {return rotation; }

    virtual void rotate();

    virtual std::vector<int> rad_loc_placer()=0;

    virtual void set_location (char (*matrix)[collum])=0;

  };

  class Aircraft_Carrier : public ships
    {
      private :
      size_t ship_size = 5;
      std::bitset<5> damage_model;

      public :

      Aircraft_Carrier():ships(next_ship_id){}
      virtual ~Aircraft_Carrier() = default;

      virtual std::vector<int> rad_loc_placer();
      virtual void set_location (char (*matrix)[collum]);


    };

  class Battleship : public ships
  {
    private :
    size_t ship_size = 4;
    std::bitset<4> damage_model;

    public :
    Battleship():ships(next_ship_id){}

    virtual ~Battleship() = default;

    virtual std::vector<int> rad_loc_placer();
    virtual void set_location (char (*matrix)[collum]);



  };

  class Submarine : public ships
  {
    private :
    size_t ship_size = 3;
    std::bitset<3> damage_model;

    public :
    Submarine():ships(next_ship_id){}

    virtual ~Submarine() = default;

    virtual std::vector<int> rad_loc_placer();
    virtual void set_location (char (*matrix)[collum]);

  };


/*




class Aircraft_Carrier : public  ships
{
  private :

    int ship_size = 5;

  public :

  inline bool get_rotation()
  {
    return rotation;
  }

  Aircraft_Carrier()
    {
      set_id();
    }

   //void set_location  (char (*matrix)[collum]) ;

  inline void set_id()
  {
    id = ship_id;
    ship_id++;
  }

  inline  void roatate()
  {
    char roate;
    std::cout<< "roate ship? y/n?";
    std::cin >> roate;
    std::cout << '\n';

    if(!(roate =='y'))
      { rotation = false;}
      else
        {
          std::cin.clear();
          std::cin.ignore(10000, '\n');
          rotation = true;
        }
  }

 inline bool get_hit(int* loc)
  {
    if(loc[0]== location[0]&& loc[1]==location[1])
    {return true;}
    return false;
  }

};
*/
