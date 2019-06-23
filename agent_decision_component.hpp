
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

    std::vector<unittype*> uint_controlist;
    std::unordered_map<int,unittype*> uint_id_map;

    public:
    ~agent_decision_component() = default;

    void move_factorz(char (*matrix)[collum])
    {
      for (auto actl = agent_controlist.begin();
           actl != agent_controlist.end(); ++actl)
       {
         size_t size_of_ship = actl->get_ship_size();
      //  = actl->ojk_ship_placr.coltion_intersection();
        matrix[size_of_ship][size_of_ship] = 'V';
        size_t rspaal_dp size_of_ship/agent_controlist.size()

          if('0'!=matrix[rspaal_dp+1][rspaal_dp+1])
          {
            actl->roatate();
          }
       }
     }


    void add_unit_tolist(unittype* in_unit_ptr)
     {
      agent_controlist.push_back(in_unit_ptr);
     }

    unittype* uint_fromctl_list(int unit_at_vec_place)
     {
      return agent_controlist.at(unit_at_vec_place);
     }

    void regstar_unit_inmap(unittype* in_uint)
     {
      agent_id_map.insert({in_uint->get_id(), in_uint});
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
