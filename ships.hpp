//ship.hpp

#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include <random>
#include "rad_genz.hpp"

 namespace Battle_Shipz
   {
    #define row 10
    #define collum 10
    enum    {aircraft_carrier=1,battleship=2,
             submarine=3,crusier=4, patrol_boat=5};
   }

  static int ship_id =0;

  class ships
  {
    private :
    int ship_size = 0;
    protected :

    int  id;
    int  location[2];
    bool rotation;
    bool AI_Ship;
    bool alive;

    //genratorezrad
    rad_genz randomgen_bool{0,1};
    rad_genz rad_row{0,row};
    rad_genz rad_rowH{0,row-ship_size};
    rad_genz rad_col{0,collum};
    rad_genz rad_colH{0,collum-ship_size};

//distrabutions



    public :

    virtual ~ships() =  default ;

    inline virtual bool bool_radom()
    {
      return randomgen_bool();

      //auto gen = std::bind(std::uniform_int_distribution<int>(0,1),
        //                std::default_random_engine());

    //  return gen();
    }

    inline virtual void set_id()
    {
      id = ship_id;
      ship_id++;
    }

    inline virtual void set_ship_to_AI()
      {AI_Ship = true;}

    inline virtual bool is_ship_AI()
      {return AI_Ship;}

    inline virtual bool get_Rotation()
        {return rotation; }

    virtual void rotate();

    virtual std::vector<int> rad_loc_placer() = 0;

    virtual void set_location (char (*matrix)[collum]) = 0;

  };

  class Aircraft_Carrier : public ships
    {
      private :
      int ship_size = 5;

      public :
      virtual void set_location (char (*matrix)[collum]);
      virtual std::vector<int> rad_loc_placer();
    };

  class Battleship : public ships
  {
    private :
    int ship_size = 4;

    public :
    virtual void set_location (char (*matrix)[collum]);
    virtual std::vector<int> rad_loc_placer();
  };

  class Submarine : public ships
  {
    private :
    int ship_size = 3;

    public :
    virtual void set_location (char (*matrix)[collum]);
    virtual std::vector<int> rad_loc_placer();
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
