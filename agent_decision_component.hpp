
#pragma once

#include <vector>
#include <unordered_map>


class base_agent_dsc
{
  //private :
  public :
  virtual ~base_agent_dsc();

};

  template<class unittype>
  class agent_decision_component
  {
    private :
    int total_tracz;
    size_t Usr_ship_count;
    int agent_toalz;
    double intel_eror;

    std::vector<unittype> uint_controlist;
    std::unordered_map<int,unittype> uint_id_map;

    public:
    ~agent_decision_component() = default;

    size_t get_ctl_list_size()
    {
      return uint_controlist.size();
    }
    size_t get_unit_id_map_size()
    {
      return uint_id_map.size();
    }

    size_t diffrence_in_user_known(size_t& total_shipz)
    {
      intel_eror = static_cast<double>(total_shipz -Usr_ship_count - get_unit_id_map_size() -get_ctl_list_size());
      return (total_shipz -Usr_ship_count - get_unit_id_map_size() -get_ctl_list_size());
    }

    void move_factorz(char (*matrix)[collum])
    {
      double ent_map_sizevar = (double)get_unit_id_map_size();
    double clt_list_size = (double)  get_ctl_list_size();

    //double probzneedmove =                      (ent_map_sizevar/clt_list_size)
      for (auto actl = uint_controlist.begin();
           actl != uint_controlist.end(); ++actl)
       {
         size_t size_of_ship = actl->get_ship_size();
      //  = actl->ojk_ship_placr.coltion_intersection();
         matrix[size_of_ship][size_of_ship] = 'V';
         size_t rspaal_dp = size_of_ship/uint_controlist.size();

          if('0'!=matrix[rspaal_dp+1][rspaal_dp+1])
          {
            actl->roatate();
          }
       }
     }


    inline void add_unit_tocrl_list(unittype in_unit_ptr)
     {  std::cout <<"AI_ADDED_UNITZ"<< '\n';
        uint_controlist.push_back(in_unit_ptr);
     }



    unittype unit_radm_access_ctl_list(int unit_at_vec_place)
     {
      return uint_controlist.at(0);
     }

     template <class unit_type>


    void regstar_unit_inmap(unit_type* in_uint)
     {
      uint_id_map.insert({in_uint->get_id(), in_uint});
     }


/*
   unittype*  lookup_unit_map(int in_id)
     {
      auto search = agent_id_map.find(in_id)
      {
        if (search != agent_id_map.end())
      {
        return search->second;
      }
      else
      {
        std::cout << "->>UNITNOTFOUNDZ ID:" << in_id << '\n' << '\n';
        return nullptr;
      }
      }
    }
    */

};
