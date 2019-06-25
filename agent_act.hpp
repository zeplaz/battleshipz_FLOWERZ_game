

#pragma once
#include <cassert>
#include <iostream>

#include "ships.hpp"
#include "game_board.hpp"
#include "agent_decision_component.hpp"
//#include "tela_dispacher.hpp"

class game_board;
class agentz
{
  private :
  int a_id=-1;
  static int next_agent_id;

   agent_decision_component<ships*> ship_dis_comp;
   std::vector<game_board*> gb_ptr_collection;
   //agent_decision_component<game_board*> bord_dis_comp;
   //std::vector<ships*> contrl_list_ships;

    public :
    ~agentz() = default;

    agentz()
     {
      set_id();
     }

     void create_gb_setup(game_board* prt_toactive_gid)
     {
        std::cout <<"LOADING BOARD TO AGENTZID:" << a_id << 'n'
        << "*-ptr->gb|" << prt_toactive_gid << '\n';
        gb_ptr_collection.push_back(prt_toactive_gid);
        //bord_dis_comp.add_unit_tocrl_list(prt_toactive_gid);
        std::cout << "newsizeCLTZ:" << gb_ptr_collection.size() << '\n' <<'\n';
     }

    void set_id()
    { std::cout << "next_agent_id" <<next_agent_id << "prevezuz id:" << a_id << '\n';

      //assert ((a_id > next_agent_id)&& "<agent::set_id: broken ID>");
      a_id = next_agent_id;
      next_agent_id=a_id+1;
    }

    int get_id()
    {
      return a_id;
    }

    bool Calculate_playr_probedata(size_t& toalsipz)
    { size_t res_error;
      res_error = ship_dis_comp.diffrence_in_user_known(toalsipz);
      if(toalsipz-res_error>3)
      {
        //        tranzmitor.trazmit_telagram();
        return false;
      }
      return true;
    }
//template <typename uni_tpy>
  void test_ctl_list();

  //std::cout <<

    void agent_exuc()
    {
      bool need_update;
      //need_update =Calculate_playr_probedata();
      //// do more
    }

    template <class unit_type*>
    void agent_addz_uint_toMap(unit_type* in_uint)
    {
      ship_dis_comp.regstar_unit_inmap(in_uint);
    }


    void add_ship_tocomp_ctl_list(ships* in_ship)
    {
      //  contrl_list_ships.push_back(in_ship);
      ship_dis_comp.add_unit_tocrl_list(in_ship);
      std::cout << "SHIPADDED_CTLLIST FOR AGENTID:" << a_id << " size:ofCLZ-|"
                << ship_dis_comp.get_ctl_list_size()  << '\n';
    }

    template<class unit_type>
    void anilzcomp_data(agent_decision_component<unit_type*>& in_comp)
     {
      // in_comp.agent_controlist();
     }

    template<class unit_type>
    agent_decision_component<unit_type*>*  create_agent_dis_comp()
    {
      agent_decision_component<unit_type*>* tmp_comp_ptr = new agent_decision_component<unit_type>();
      return tmp_comp_ptr;
      //agent_dis_comp_ptr_vec.push_back(tmp_comp_ptr);
    }

    template<class unit_type>
    void cleanup(agent_decision_component<unit_type>* to_remove)
    {
      delete[]to_remove;
    }

  //  void registar_listen_channel()
  //  {
  //    .listenTo_tela ()std::bind(&Foo::test, foo));
  //  }



    //bool handle_tela()
  //  {

  //  }

    template<class unit_type>
    void dis_factory_order()
    {
    //  switch factory_type()
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
