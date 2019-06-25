
#include "agent_act.hpp"


 int agentz::next_agent_id=0;

//void agentz::set_id()


void agentz::test_ctl_list()
{ // bord_dis_comp.contl_list_size();

  int cltsize = gb_ptr_collection.size();
  std::cout <<"##ctllistboad testz:size:" << cltsize << '\n';

  if(cltsize !=0)
 {// move parmz
  std::valarray<int> tes_moveoffset{1,1};

//load board.
  game_board* prt_to_actgb = gb_ptr_collection.at(0);

//reticvematrix data
  //bord_dis_comp.unit_radm_access_ctl_list(0);
  auto matrix = prt_to_actgb->get_ai_board_data();

// send out moves to ships...
ship_dis_comp.agent_toalz  = ship_dis_comp.get_ctl_list_size();

//  std::valarray<int>* ptr_moveoffset = &tes_moveoffset;

  for(int i =0; i < ship_dis_comp.agent_toalz; i++)
  {
    ships* prt_cut_ctl =  ship_dis_comp.unit_radm_access_ctl_list(i);
           prt_cut_ctl-> unit_move_addtion(tes_moveoffset,*matrix);
  }
 }

}
