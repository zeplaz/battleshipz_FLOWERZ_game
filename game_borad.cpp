
#include "game_board.hpp"


  void game_board::create_user_ships(user_interface_player* for_player)
  { //int (*prt_matrix)[row][collum] = &matrix;
   //int* ptr_matrix = &matrix[row][collum];
    int ship_type;
    toMAIN_UI_prt  =for_player;

    for (int i=0; i<2; i++)
    {
      std::cout << "select Ship type: 1:Aircraft_Carrier, 2:Battleship, 3:Submarine";
      std::cin >> ship_type;
      if(ship_type >3 || ship_type<1)
        {
          std::cout << "ERROR NONEVAILD SHIP";
          std::cin.clear();
          std::cin.ignore(10000, '\n');
          i--;
        }
       else
        {
          //user_datz.regstar_unit_inmap(

           ship_fac(ship_type,
                    &user_ship_vec,user_matrix,false);
          // so it ends the loading for testing!
          std::cout << "------------------------" << '\n';
        }
     }
  }

  void game_board::create_AI_ships(agentz* for_agent)
  {
    //int ship_type;
    //for_agent.create_agent_dis_comp<ships>();
    //ship_type=2;// cuz only class setup!
    //ship_fac(ship_type,&AI_ship_vec,AI_marrix,true);
    //agentz_shipz_cmp.add_unit_tolist(;
    //for_agent->
  //  std::cout <<"AI-EXITEDexit_facoty_andregistarz" <<'\n';
  //  for_agent->
    for (auto agt = agent_list.cbegin(); agt != agent_list.cend(); agt++)
    {
      agentz* ptr_agent = new agentz(*agt);
      ptr_agent->add_ship_tocomp_ctl_list(ship_fac(aircraft_carrier,&AI_ship_vec,AI_marrix,true));
      ptr_agent->add_ship_tocomp_ctl_list(ship_fac(submarine,&AI_ship_vec,AI_marrix,true));
      ptr_agent->add_ship_tocomp_ctl_list(ship_fac(battleship,&AI_ship_vec,AI_marrix,true));
      delete ptr_agent;
    }
    //ship_fac(ship_type,&AI_ship_vec,AI_marrix,true);
    //ship_fac(ship_type,&AI_ship_vec,AI_marrix,true);
    //ship_fac(ship_type,&AI_ship_vec,AI_marrix,true);
  }

  agentz*  game_board::new_agent()
   {
    agentz new_agent;
    agent_list.push_front(new_agent);
    return &new_agent;
    //agent_list.emplace_front(agentz);
   }


   void game_board::set_agentz_defl_parmz(game_board* prt_toactive_gid)
   {
     for (auto agt = agent_list.cbegin(); agt != agent_list.cend(); agt++)
     {
       //user_ship_vec.size()/
            //game_board* gb_ptr=  prt_gb();
        agentz* ptr_agent = new agentz(*agt);
        ptr_agent->create_gb_setup(prt_toactive_gid);

        if (agent_list.cbegin() == agent_list.cend())
            std::cout << "forward_list 'agent_list' is emptyz.\n";

       delete ptr_agent;
      }

   }

  void game_board::update_board()
  {
      ships* prt_temp_ship;
      //preform moveoderz
      prt_temp_ship = AI_ship_vec.at(0);
      //prt_temp_ship->move();
      agentz temp_agent   = agent_list.front();
      temp_agent.test_ctl_list();
      //update matrix moves      //ai moveupdatez
      for(size_t i =0; i < AI_ship_vec.size(); i++)
      {
        prt_temp_ship = AI_ship_vec.at(i);
        std::cout << "->UPDATE: ship_ID: "<< prt_temp_ship-> get_id() <<'\n'
                  << prt_temp_ship->get_ship_size()<<  "+++++++++++++" <<'\n';

        std::vector<std::vector<int>>* temp_vec_prt = prt_temp_ship->ojk_ship_placr.get_ptr_ship_loc();

        std::cout << "##size of ptrz arrayz:"
                  << temp_vec_prt->size() << "@@@@@@@@"
                  << prt_temp_ship->get_ship_symbol() << '\n' << '\n';

            for(size_t j=0; j <temp_vec_prt->size(); j++ )
            {
              std::vector<int>* ptr_cord_vec = &temp_vec_prt->at(j);
            //  std::cout << ptr_cord_vec->at(0)
              AI_marrix[ptr_cord_vec->at(0)][ptr_cord_vec->at(1)] = prt_temp_ship->get_ship_symbol();
            }
        }

        // for player_redaw
       for(size_t i =0; i < user_ship_vec.size(); i++)
         {
           prt_temp_ship = user_ship_vec.at(i);

           for (size_t j=0; j< prt_temp_ship->get_ship_size();j++)
            {
              std::cout  << "@@ship symbol:" << prt_temp_ship->get_ship_symbol() << '\n';
              auto cur_point_prt = prt_temp_ship->ojk_ship_placr.prt_reutn_vec_data();

              std::cout <<"## val test.UPDATE:" << cur_point_prt->at(0) <<" "<< cur_point_prt->at(1) << '\n';
              user_matrix[cur_point_prt->at(0)][cur_point_prt->at(1)] =  prt_temp_ship->get_ship_symbol();
              cur_point_prt++;
              }
          }

          game_board::show();
          Quit = game_board::usr_pollz();
          game_board::clear();
          game_board::currentGB_count++;
}
          //  x =
          //  y = cur_point_prt.at(1);
          //  std::cout <<"-> NEW XY:" << x << " " << y <<'\n';
        //
        //  ship_loc_dat_ptr++;







/*
            //  void* temp_vec_prt
                          //  = static_cast<std::vector<int>>();


            //  for(size_t j =0 ; temp_vec_prt->size(); j++)
            //    {
              //    auto x = temp_vec_prt->at(0);
              //    auto y =temp_vec_prt->at(1);

                  //std::cout << "newPOITZinUPDATE:" << x <<" " << y << '\n';
              //  }
                //std::vector<int>* ship_loc_dat_ptr  =
                      //auto x=  ship_loc_dat_ptr->at(0);
                //auto x = ship_loc_dat_ptr[0];
                //auto y = ship_loc_dat_ptr[1];

            //  std::cout << *ship_loc_dat_ptr;


              */
