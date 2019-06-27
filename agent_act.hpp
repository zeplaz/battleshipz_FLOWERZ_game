

#pragma once
#include <cassert>
#include <iostream>

#include "ships.hpp"
#include "game_board.hpp"
#include "agent_decision_component.hpp"
#include "agent_sensor_memorx.hpp"
//#include "tela_dispacher.hpp"

const static double MEM_DEPTH = -12.00;

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
    agent_sensor_memorx<agentz*, double>* senz_memrx;
    agent_decision_component<agentz*> agent_dis_comp;


    ~agentz()
    {
      delete senz_memrx;
    }


    agentz();


     inline agentz* get_self_ptr()
     {
       return this;
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

  void scan_other(agentz* other_ptr_agnztz);

  template<class unit_type>

  std::vector<unit_type*> capture_ai_controlist(agentz* prt_to_contact)
  {
  //  if(prt_to_contact->senz_memrx())
  }

  size_t get_unit_ctllistcount()
  {
    return this->agent_dis_comp.contl_list_size();
  }

  void scan_proccedure_incomeing();

  void update_agent_visionz()
  {


  }



  template<class recordable_idenity>
  recordable_idenity* scanned_by_contact(agentz* incoming_scan_prt)
  {
  //  incoming_scan_prt->scan_proccedure_incomeing();

    /* last_time_spotted(-999),
                   time_found_visible(-999),

                   //last_time_visible(0),
                   comm_range(-0.99),
                     incoming_scan_prt->known_uint_count =
                   ,pridicted_rate_change_of_influnce(0)
                     {
                       comrad_statuz.danger =-999;
                       comrad_statuz.like_ability=-999;
                       comrad_statuz.ambivalents=-999;
                       int array_2d[2] = {0,0};
                       prev_incouter_vec.push_back(std::make_tuple(array_2d,0.0,0.0));
                     }
                     */
    return get_self_ptr();
  }

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

    void ship_sunk(int vec_loc);




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
