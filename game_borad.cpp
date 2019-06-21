
#include "game_board.hpp"


  void game_board::create_user_ships()
  { //int (*prt_matrix)[row][collum] = &matrix;
   //int* ptr_matrix = &matrix[row][collum];
    int ship_type;
    for (int i=0; i<2; i++)
    {
      std::cout << "select Ship type: 1:Aircraft_Carrier, 2:Battleship, 3:Submarine, 4:Crusier, 5:Patrol_boat";
      std::cin >> ship_type;
      if(ship_type >5 || ship_type<1)
        {
          std::cout << "ERROR NONEVAILD SHIP";
          std::cin.clear();
          std::cin.ignore(10000, '\n');
          i--;
        }
       else
        {
          ship_fac(ship_type,&user_ship_vec,user_matrix,false);
          // so it ends the loading for testing!
        }
     }
  }

  void game_board::create_AI_ships()
  {
    int ship_type;
    ship_type=2;// cuz only class setup!
    //ship_fac(ship_type,&AI_ship_vec,AI_marrix,true);
    ship_fac(1,&AI_ship_vec,AI_marrix,true);
    ship_fac(2,&AI_ship_vec,AI_marrix,true);
    ship_fac(3,&AI_ship_vec,AI_marrix,true);
    //ship_fac(ship_type,&AI_ship_vec,AI_marrix,true);
    //ship_fac(ship_type,&AI_ship_vec,AI_marrix,true);
    //ship_fac(ship_type,&AI_ship_vec,AI_marrix,true);
  }

  void game_board::update_board()
  {
      ships* prt_temp_ship;
      //preform moveoderz

      prt_temp_ship = AI_ship_vec.at(0);
      //prt_temp_ship->move();
      //update matrix moves
      //int x,y;

      for(size_t i =0; i < AI_ship_vec.size(); i++)
      {
        prt_temp_ship = AI_ship_vec.at(i);
        std::cout << "->UPDATE: ship_ID: "<< prt_temp_ship-> get_id() <<'\n'
                  << prt_temp_ship->get_ship_size()<<  "+++++++++++++" <<'\n';

        auto  temp_vec_prt = prt_temp_ship->ojk_ship_placr.get_ptr_ship_loc();


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
      /*
          for (size_t j=0; j< prt_temp_ship->get_ship_size();j++)
          {
            //std::vector<int> cur_point_prt = *ship_loc_dat_ptr;

            std::cout  << "ship symbol:" << prt_temp_ship->get_ship_symbol() << '\n';
            char tmep_sym =prt_temp_ship->get_ship_symbol();

            //std::cout <<"## val test.UPDATE:" << cur_point_prt.at(0); '\n';
            //  x =
            //  y = cur_point_prt.at(1);
            //  std::cout <<"-> NEW XY:" << x << " " << y <<'\n';
          //  AI_marrix[x][y] =tmep_sym;
          //  ship_loc_dat_ptr++;
          }
        */
        }
      }
