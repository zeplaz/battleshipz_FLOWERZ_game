
#pragma once

#include <iostream>
#include <vector>
//#include <climits>
//#include <cstdint>
#include <type_traits>
#include <utility>

//using namespace Battle_Shipz;
#include "rad_genz.hpp"

namespace Battle_Shipz
  {
   #define row 15
   #define collum 20
   enum    {aircraft_carrier=1,battleship=2,
            submarine=3,crusier=4, patrol_boat=5};
  }



template<typename std_type>
  class placeable_object_component
{
  protected :


  public :

    std::vector<std::vector<std_type>> obj_locnodez;

    rad_genz randomgen_bool{0,1};
    rad_genz rad_row{0,row};
    rad_genz rad_col{0,collum};

    auto prt_reutn_vec_data()
    {
      return obj_locnodez.data();
    }

    inline std::vector<std::vector<std_type>>* get_ptr_ship_loc()
    {return &obj_locnodez;}

template <typename...pointpramz>
  inline  void add_obj_points (pointpramz&&... coordinates)
    {
       std::cout <<"INSIDE_ADD_OBJ_POINTZ" << "---------"
                  <<obj_locnodez.size() <<'\n';

                  if(obj_locnodez.size()>=1)
                  {
                    std::vector<std_type>* ptr_shpontz = obj_locnodez.data();
                    for (size_t i = 0; i<obj_locnodez.size();i++)
                    {
                        //  ptr_shpontz += i;
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

 template<typename... Coordinates>
   auto point_move_vector_addion(Coordinates... coordinates)
   {
     //std::vector<std_type> temp_vec;
      return (coordinates + ...);
    }






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

};

/* template<typename T, typename... Args>
 void push_back_vec (std::vector<T>& v, Args&&... args)
 {
   static_assert((std::is_constructible_v<T, Args&&> && ...));
   (v.push_back(std::forward<Args>(args)), ...);
 }*/
