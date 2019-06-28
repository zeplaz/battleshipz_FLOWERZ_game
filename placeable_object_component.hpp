
/*PLACEABLE_OBJECT_COMPONENT.HPP
    currntly template seficc commonet, can set to floats or doubles or ints.
    though may not all be 100% stable.
    ->gives the object a interface to the phiscis existance, and collion systemz


    current work is on the int, but will be doing a float or double.

  a compoent that can be added, to enties, will allow them to exist on the board.
  currntly it is also the home for the game bord dimetions playing space
  and the enum for craft types,..the reson is this compent is wishs to limit libs
  abd needing any local includes. to fit in order piple and be easly adapted to other new objects, or enties.

  currently working on the some collison stuff and experments with template dypedefs to be utilzied
  on the posiongs and adding in a more sobust gide system whcih will be ealsy 3rd if ever wished.
  but will be used for the calcuations of mathmaics. and not the displayz.!in the same way..
  collison will be moved to its own compoent later..
*/
#pragma once

#include <iostream>
#include <vector>
//#include <climits>
//#include <cstdint>
#include <type_traits>
#include <utility>
#include <stack>
#include <valarray>

//using namespace Battle_Shipz;
#include "rad_genz.hpp"

namespace Battle_Shipz
  {
   #define row 20
   #define collum 75
   enum    {aircraft_carrier=1,battleship=2,
            submarine=3,crusier=4, patrol_boat=5};
  }


   //template <typename T>
//lass MyVector : public std::vector<T, MyCustomAllocator<T> > {};

  template<typename std_type>
  using tpl_vector = std::vector<std_type,std::allocator<std_type>>;

  template<typename std_type>
  using tpl_vector_vector =  std::vector<std_type,std::allocator<std_type>>;

  template<typename std_type>
  using tpl_valarray = std::valarray<std_type>;


  template<typename std_type>
  struct sb_place_d
   {
     tpl_vector<std_type> loc_data;
     tpl_valarray<std_type> val_place_flags;
   };

   typedef sb_place_d<int> sint_place_d;
   typedef sb_place_d<float> sfloat_place_d;
   typedef tpl_vector<int> vec_int;
   typedef tpl_vector_vector<int> vector_in_vector_;


template<typename std_type>
  class placeable_object_component
  {
   protected :


   public :

    sint_place_d   loc_cord_ints_Wflags;
    sfloat_place_d loc_cord_floatz_Wflags;

    //vec_int
    std::vector<std::vector<std_type>> obj_locnodez;
    std::stack<std::vector<std_type>*>  colsid_stack;

    rad_genz randomgen_bool{0,1};
    rad_genz rad_row{0,row};
    rad_genz rad_col{0,collum};


    //nifz cordent unfolding
    template<typename... Coordinates>
      auto point_move_vector_addion(Coordinates... coordinates)
      {
       return (coordinates + ...);
      }

    template<typename...pointpramz>
      inline  void add_obj_points (pointpramz&&... coordinates)
        {
         std::cout <<"INSIDE_ADD_OBJ_POINTZ" << "---------"
                   <<obj_locnodez.size() <<'\n';

          if(obj_locnodez.size()>=1)
           {
            std::vector<std_type>* ptr_shpontz = obj_locnodez.data();
             for (size_t i = 0; i<obj_locnodez.size();i++)
              {
                std::vector<std_type> temp_vec= *ptr_shpontz++;
                std::cout << "_________==prt_vec_obkjz at being: "
                          << temp_vec.at(0)  << " "<< temp_vec.at(1)
                          << '\n' <<"_____"<< '\n';
              }
            }

           std::vector<std_type> tmep_cord;
           static_assert((std::is_constructible_v<std_type, pointpramz&&> && ...));
           (tmep_cord.push_back(std::forward<pointpramz>(coordinates)), ...);
           obj_locnodez.push_back(tmep_cord);

           for (size_t i = 0; i<obj_locnodez.size();i++)
            {
             tmep_cord = obj_locnodez.at(i);
             std::cout << "--------------" << '\n' <<"temp poitzadded: " << tmep_cord.at(0) <<" "
                       << tmep_cord.at(1) << '\n';
            }
         }

    // OPRATORZ OVERLOADED
      inline bool operator ==(const std::vector<std::vector<std_type>>& other)
        {
          for(size_t i = obj_locnodez.size(); i>0; i--)
            {
             if(other.at(i) != obj_locnodez.at(i))
             {return false;}
            }
             return true;
        }

        inline bool operator !=(const std::vector<std::vector<std_type>>& other)
         {
           return {!(other == obj_locnodez)};
         }


    inline std::vector<std::vector<std_type>>* get_ptr_ship_loc()
     {return &obj_locnodez;}


    void set_colided_at(std::vector<std_type>* in_colid_cornetz)
     {
      std::cout <<"COLIAOZNST TO::" << in_colid_cornetz->at(0) << in_colid_cornetz->at(1) << '\n' << '\n';
      colsid_stack.push(in_colid_cornetz);
     }
    auto prt_reutn_vec_data()
     {
      return obj_locnodez.data();
     }

    inline bool coltion_intersection(std::vector<std_type> &in_point)
    {
     for(size_t i = obj_locnodez.size(); i>0; i--)
     {
       std::vector<std_type> temp_vec = obj_locnodez.at(i);

       if (temp_vec != in_point)
       {return false;}
     }
     return true;
     }





};

/* template<typename T, typename... Args>
 void push_back_vec (std::vector<T>& v, Args&&... args)
 {
   static_assert((std::is_constructible_v<T, Args&&> && ...));
   (v.push_back(std::forward<Args>(args)), ...);
 }*/
