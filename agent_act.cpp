
#include "agent_act.hpp"


 int agentz::next_agent_id=0;

//void agentz::set_id()
  agentz::agentz()
  {
    set_id();
    agentz* this_temp_agemt = &*this;
    senz_memrx = new agent_sensor_memorx<agentz*,double>(this_temp_agemt,MEM_DEPTH);

  }




void agentz::scan_other(agentz* other_ptr_agnztz)
{

  senz_memrx->make_new_rec_IFNOTPREZ(other_ptr_agnztz);
  //senz_memrx->remove_contact_from_memx();
//  MemoryRecord& info = m_MemoryMap[*curBot];
//   MemoryMap::const_iterator it = senz_memrx.find(other_ptr_agnztz);
  // inst_memx_map[other_ptr_agnztz]
  //senz_memrx
  // known_uint_count = other_ptr_agnztz->get_unit_ctllistcount();
}


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

  ship_dis_comp.move_factorz(*matrix);

  for(int i =0; i < ship_dis_comp.agent_toalz; i++)
  {
    ships* prt_cut_ctl =  ship_dis_comp.unit_radm_access_ctl_list(i);
           prt_cut_ctl-> unit_move_addtion(tes_moveoffset,*matrix);
  }
 }

}

void agentz::scan_proccedure_incomeing()
{
  //senz_memrx.known_uint_count= agentz::get_unit_ctllistcount();
  std::cout << "AGENTZ::scannnnz...vailded controllistztom mexz...";
  //calculatecorrent_cmrdstatz
}
