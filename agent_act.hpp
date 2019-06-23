
#include <cassert>
#include <iostream>

#include "ships.hpp"
#include "agent_decision_component.hpp"




class agentz
{
  private :
  int a_id;
  static int next_agent_id=0;

  agent_decision_component<ships*> ship_dis_comp;


    public :
    ~agentz() = default;

    agentz()
     {
      set_id(id);
     }

    void set_id()
    {
      assert ((val>=next_agent_id)&& "<agent::set_id: broken ID>");
      a_id = val;
      next_agent_id=a_id+1;
    }

    template <class unit_type*>
    agent_addz_uint_toMap(unit_type* in_uint)
    {
      ship_dis_comp.regstar_unit_inmap(in_uint);

    }


    template<class unittype>
    void anilzcomp_data(agent_decision_component<unittype*>& in_comp)
     {
       in_comp.agent_controlist();
     }

    template<class unittype>
    agent_decision_component<unittype*>*  create_agent_dis_comp()
    {
      agent_decision_component<unittype*>* tmp_comp_ptr = new agent_decision_component<unittype>();
      return tmp_comp_ptr;
      //agent_dis_comp_ptr_vec.push_back(tmp_comp_ptr);
    }

    void cleanup(agent_decision_component<unittype>* to_remove)
    {
      delete[]to_remove;
    }



/*  {
    for(size_t i; i< agent_dis_comp_ptr_vec.size();i++ )
    {
      delete[] agent_dis_comp_ptr_vec.at(i);
    }
  }

  void update_telmz()
  {
    for (auto adc = agent_dis_comp_ptr_vec.begin();
         adc != agent_dis_comp_ptr_vec.end(); ++adc)
    {
      //adc.move_factorz();
      //  adc.
    }
  }
  */
};
