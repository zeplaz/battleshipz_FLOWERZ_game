/* SHIPS_HPP
  #file holds the base class ships, used as aa loss raw pontiner often,
  ->lage amoutn of reltivle mirroed proces code, for the the classes,s but, seemly
  it feels like its alot of abit spacues code, but, should comple clean enough. im not suew
  though when i start, factoring in the facoitres, as a cost space, but, feel. the ship build wille allow for
  a fluid yet, restfice reprecuesons of the system. its ahrd to ravel over the loose soilz.
      {i havw resverions about some lost data, elsewhere, in the casting down to the base pointer.
      }
  i have to say major revisations around, how ships have been played, i think the expaive nature
  of the class with seemly alot dumped but very miroriedly into subclass makes it reflective
  but, there some structal constrantes, which next obkect would hopepful be able to "trsgress"
  so, the metaprogrmaical "saea" . will be the strrictions. id like to keep them from having much
  more then the plcable componet, a comms componet, seem fair. and limited telgram acess, as clsassical sssumped.
  telgram msgsing with restrcions.z
*/
//

#pragma once

#include <iostream>
#include <vector>
#include <random>
//#include <functional>
#include <random>
#include <bitset>
#include <cassert>
#include <valarray>
#include <tuple>

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
    double damage_taken;
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
    virtual std::tuple<double,std::vector<bool>>  damage_report() =0;


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
    inline virtual void has_collided(std::vector<int>* colsionvec)
    {
      ojk_ship_placr.set_colided_at(colsionvec);
    }


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
/*
    virtual void move()
    { std::cout<< '\n'<<"###INSIZEMOVE_TEST FUNC####" <<'\n';

      unit_move_addtion(temp_moveoffset);

    }*/

    virtual void unit_move_addtion(std::valarray<int>& to_mov_val_ary,char (*matrix)[collum])
    {
      std::vector<int>* prt_vec_or_val = ojk_ship_placr.obj_locnodez.data();

        //std::cout <<"##test.prtr_capture_vecdata";
                  //<< prt_vec_or_val1->at(0) <<" "
                //  << prt_vec_or_val2->at(1) << '\n';
                std::valarray<int> temp(2);
                for (size_t i = 0;i< ojk_ship_placr.obj_locnodez.size(); i++)
                {
                  std::vector<int>* temp_vec = prt_vec_or_val++;
                  temp[0] =temp_vec->at(0);
                  temp[1] =temp_vec->at(1);

                  //std::cout <<"##test.valarrayr_captured vecdata: " << temp[0]
                            //<<" "<< temp[1] << '\n';
                  temp = ojk_ship_placr.point_move_vector_addion(to_mov_val_ary,temp);

                  if(matrix[temp[0]][temp[1]] !='0'&& matrix[temp[0]][temp[1]] !=ship_symbl)
                  {
                    std::cout << "|->move_colliton into another ship||" << '\n';

                    has_collided(temp_vec);

                    break;
                  }
                  if(temp[0]>row)
                  {
                    temp[0]= 0;
                  }
                  if(temp[1]>collum)
                  {
                    temp[1]= 0;
                  }
                  temp_vec->at(0) =  temp[0];
                  temp_vec->at(1) =  temp[1];

                  //std::cout <<"##test.valarrayrmzaddior: " << temp[0] <<" " << temp[1] << '\n';
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

  ////new ship classes!

  class Aircraft_Carrier : public ships
    {
      private :
      size_t ship_size = 5;
      char ship_symbl = 'C';
      std::bitset<5> damage_model;
      //std::vector<bool> vec_damge;
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

     inline std::tuple<double,std::vector<bool>> damage_report();

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
    inline std::tuple<double,std::vector<bool>> damage_report();


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

    inline std::tuple<double,std::vector<bool>> damage_report();


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
