//ship.hpp

#pragma once

#include <iostream>
#include <vector>
#include <random>
//#include <functional>
#include <random>
#include <bitset>
#include <cassert>
#include <valarray>

#include "placeable_object_component.hpp"



using namespace Battle_Shipz;



  class ships
  {
    private :
    size_t ship_size = 0;
    char ship_symbl;
    protected :

    int  id;
    static int next_ship_id;
    //static int be_NextValidID;
    int  location[2];
    bool rotation;
    bool AI_Ship;

    bool sunk;
    bool disabled;
    bool changed_postion;





    //genratorezrad
    rad_genz rad_rowH{0,row-ship_size};
    rad_genz rad_colH{0,collum-ship_size};
    //distrabutions
    public :
    //compontelistz
    placeable_object_component<int> ojk_ship_placr;

    virtual ~ships() =  default ;
    ships(int id)
    {set_id(id);}

    //pure virtualz
    virtual std::vector<int> rad_loc_placer()=0;
    virtual void set_location (char (*matrix)[collum])=0;


    // overloaded funcs
    inline virtual size_t get_ship_size()
    {
      return ship_size;
    }

    inline  virtual char get_ship_symbol()
    {
      return ship_symbl;
    }

    //inlined fucnz



    inline bool has_pos_changed()
    {
      return changed_postion;
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


    //stand_virtual fucnz
    virtual void rotate();

    //virtual void update_location() =0;

    virtual void move()
    { std::cout<< '\n'<<"###INSIZEMOVE_TEST FUNC####" <<'\n';
      std::valarray<int> temp_moveoffset{2,2};
      unit_move_addtion(temp_moveoffset);

    }

    virtual void unit_move_addtion(std::valarray<int>& to_mov_val_ary)
    {
      std::vector<int>* prt_vec_or_val = ojk_ship_placr.obj_locnodez.data();

        std::cout <<"##test.prtr_capture_vecdata";
                  //<< prt_vec_or_val1->at(0) <<" "
                //  << prt_vec_or_val2->at(1) << '\n';
                std::valarray<int> temp(2);
                for (size_t i = 0;i< ojk_ship_placr.obj_locnodez.size(); i++)
                {
                  std::vector<int>* temp_vec = prt_vec_or_val++;
                  temp[0] =temp_vec->at(0);
                  temp[1] =temp_vec->at(1);

                  std::cout <<"##test.valarrayr_captured vecdata: " << temp[0]
                            <<" "<< temp[1] << '\n';
                  temp = ojk_ship_placr.point_move_vector_addion(to_mov_val_ary,temp);
                  temp_vec->at(0) =  temp[0];
                  temp_vec->at(1) =  temp[1];

                  std::cout <<"##test.valarrayrmzaddior: " << temp[0] <<" " << temp[1] << '\n';
                  std::cout <<"##test.obehjcvk: " << ojk_ship_placr.obj_locnodez.data()->at(0)
                            <<" " <<  ojk_ship_placr.obj_locnodez.data()->at(1)<< '\n'
                            << "-----------------------" << '\n';

                }


                    location[0]= ojk_ship_placr.obj_locnodez.data()->at(0);
                    location[1]= ojk_ship_placr.obj_locnodez.data()->at(1);
                    /*
                    for (auto i =0; i<ojk_ship_placr.obj_locnodez.size(); i++)
                    {
                     matrix[ojk_ship_placr.obj_locnodez.data()->at(0)]
                           [ojk_ship_placr.obj_locnodez.data()->at(1)]= ship_symbl;
                    }*/
    }



  };

  class Aircraft_Carrier : public ships
    {
      private :
      size_t ship_size = 5;
      char ship_symbl = 'C';
      std::bitset<5> damage_model;

      public :

      Aircraft_Carrier():ships(next_ship_id){}
      virtual ~Aircraft_Carrier() = default;

      virtual std::vector<int> rad_loc_placer();
      virtual void set_location (char (*matrix)[collum]);

      inline virtual size_t get_ship_size() override
      {
        return ship_size;
      }

      inline virtual char get_ship_symbol() override
      {
        return ship_symbl;
      }
    //  virtual void update_location();


    };

  class Battleship : public ships
  {
    private :
    size_t ship_size = 4;
    char ship_symbl= 'B';
    std::bitset<4> damage_model;

    public :
    Battleship():ships(next_ship_id){}

    virtual ~Battleship() = default;

    virtual std::vector<int> rad_loc_placer();
    virtual void set_location (char (*matrix)[collum]);

    inline virtual size_t get_ship_size() override
    {
      return ship_size;
    }

    inline virtual char get_ship_symbol() override
    {
      return ship_symbl;
    }

    //virtual void update_location();



  };

  class Submarine : public ships
  {
    private :
    size_t ship_size = 3;
    char ship_symbl=  'S';
    std::bitset<3> damage_model;

    public :
    Submarine():ships(next_ship_id){}

    virtual ~Submarine() = default;

    virtual std::vector<int> rad_loc_placer();
    virtual void set_location (char (*matrix)[collum]);

    inline virtual size_t get_ship_size() override
    {
      return ship_size;
    }

    inline virtual char get_ship_symbol() override
    {
      return ship_symbl;
    }
  //  virtual void update_location();

  };


/*

//std::valarray<int> temp{ojk_ship_placr.obj_locnodez.at(0), ojk_ship_placr.obj_locnodez.(1)};
    //std::valarray<double> v1= {4.f,2.f,4.f};
    //  std::valarray<double> v2 = {0.3,0.6,0.4};
    //  std::valarray<double> v3 =
    // *ojk_ship_placr.obj_locnodez.data()=temp;


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
