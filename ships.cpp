

#include "ships.hpp"


int ships::next_ship_id = 0;

  void ships::rotate()
  {
    if(!AI_Ship)
     {
      char c_rotate;
      std::cout<< "roate ship? to Horizontal y/n?";
      std::cin >> c_rotate;
      std::cout << '\n';

      if(c_rotate =='y')
        { rotation = true;}
      else
        {
          std::cin.clear();
          std::cin.ignore(10000, '\n');
          rotation = false;
        }
      }
     if(AI_Ship)
      {
        rotation = bool_radom();
        std::cout << "rotation AI val:" << rotation <<'\n';
      }
   }


   /////////////////////////////////Aircraft_Carrier

   inline std::tuple<double,std::vector<bool>> Aircraft_Carrier::damage_report()
   {
     damage_taken = (double)ojk_ship_placr.colsid_stack.size();

     std::cout <<"#TESZ_DAMGE_REPROLLLZKKKOUT damgetakenz:::" << damage_taken <<'\n'
               <<"------------------------------------------------||"<<'\n';

     if(damage_taken>=1)
     {
         if(ojk_ship_placr.colsid_stack.size()>=ship_size)
         {
           sunk = true;
           std::cout<<"SHIPREPORTEDSUnKz!;-AiCRAFT_carryz^^^^IDZ:" << get_id() << '\n'
           << "______(((***^^&%$)))___" <<'\n';
           damage_model.set();
         }
         else
          { for(size_t i =0; i< ojk_ship_placr.colsid_stack.size(); i++)
            {
              std::vector<int>* temp_col_ptr = ojk_ship_placr.colsid_stack.top();
              damage_model.set((location[0]-temp_col_ptr->at(0))-
                               (location[1]-temp_col_ptr->at(1)));
              ojk_ship_placr.colsid_stack.pop();
              std::cout << "-AiCRAFT_carryz^^^dmagedz at:"
              << damage_model[(location[0]-temp_col_ptr->at(0))-
                               (location[1]-temp_col_ptr->at(1))];
            }
          }

         if(damage_model[ship_size])
          {
            std::cout << "#->damage_rudder+AiCRAFT_carryz" << '\n';
            disabled = true;
            damage_taken +=(3+ship_size)/ship_size;
            std::cout <<"dadamage_taken..==_+" << damage_taken << '\n'
                      <<"________________||||" <<'\n';
           }

         if (damage_model.count()> (ship_size -(ship_size/2)))
           {
               std::cout << "#->taken_damagez:zSEVRKZ! UNITDISABLEDZ|AiCRAFT_carryz" << '\n';
                disabled = true;
                damage_taken +=(ship_size+ojk_ship_placr.colsid_stack.size()/ship_size+3);

               std::cout << damage_taken << '\n';
           }
         }//enddamzgreate1
       //  std::bitset<5>*  ptrbitset = &damage_model;
       std::vector<bool> vec_damge;

         for (size_t i=0; i< damage_model.size(); i++)
         {
           vec_damge.push_back(damage_model[i]);
         }                //std::vector<bool> ptr_dmg_vec = &vec_damge;
       //  auto t =;
         return std::make_tuple(damage_taken,vec_damge);
     }




  std::vector<int> Aircraft_Carrier::rad_loc_placer()
  {
    std::vector<int> locxy;
    std::cout <<"loading random AI Aircraft_Carrier" << '\n';

    if(get_Rotation())
    {
      locxy.push_back(rad_rowH());
      locxy.push_back(ojk_ship_placr.rad_col());
      std::cout <<"ailoc horz: "<< locxy.at(0) << " " << locxy.at(1) << '\n';
        }
    else
    {
      locxy.push_back(ojk_ship_placr.rad_row());
      locxy.push_back(rad_colH());
      std::cout <<"ailoc: vert: "<< locxy.at(0) << " " << locxy.at(1) << '\n';
        }
    return {locxy};
  }


  void Aircraft_Carrier::set_location(char (*matrix)[collum])
  {
   int x, y;
   if(!AI_Ship)
     {
      bool vaild_location= false;
      while(!vaild_location)
      {
        std::cout << "set Ship Location and Orintation" << '\n';
        rotate();
        std::cout <<"input x and y location for front of ship";
        std::cin >> x >> y;
        std::cout << '\n';

        if (x<0 || x>row || y<0 || y>collum ||
           (get_Rotation() && y+ship_size >collum)||
           (!get_Rotation() && x+ship_size >row))
        {
           std::cout <<  "ERROR invaild point" << '\n';
           std::cin.clear();
           std::cin.ignore(10000, '\n');
        }
        else
          {
            location[0] = x;
            location[1] = y;

            if(get_Rotation())
            {
              for (int i =0; i < ship_size; i++)
              {
                if (matrix[location[0]][location[1]+i] !='#')
                {
                 std::cout << "your ship crosses another ship NOT VAILD" << '\n';
                 vaild_location= false;
                 break;
                }
               vaild_location= true;
              }
             }
             if(!get_Rotation())
             {
               for (int i =0; i < ship_size; i++)
               {
                 if(matrix[location[0]+i][location[1]] != '#')
                 {
                  std::cout << "your ship crosses another ship NOT VAILD" << '\n';
                  vaild_location= false;
                  break;
                 }
                vaild_location= true;
               }
              }
            }
          }//end of while found a vaild location
          if(vaild_location)
          {
            if(get_Rotation())
            { std::cout << "rotatedship! being placed!" << '\n';
              for (size_t i =0; i < ship_size; i++)
              {
               matrix[location[0]][location[1]+i] = ship_symbl;
               ojk_ship_placr.add_obj_points(location[0],location[1]+i);
              }
            }
              if(!get_Rotation())
            {
              for (size_t i =0; i < ship_size; i++)
              {
                matrix[location[0]+i][location[1]] = ship_symbl;
                ojk_ship_placr.add_obj_points(location[0]+i,location[1]);
              }
            }
           }
         }//end of player setup
     //ai setup
     if(AI_Ship)
     {
       std::cout <<"LOading AI ship LOCATIONz" << '\n';
       bool vaild_location= false;
       int round=0;
       while (!vaild_location)
       {
         round++;
         std::cout << "seeking vaild round: " << round << '\n';
         std::vector<int> locxy;
         rotate();
         locxy = rad_loc_placer();

         if (!(locxy.at(0)>row || locxy.at(1)>collum ||
            (get_Rotation() &&  locxy.at(1)+ship_size >collum)||
            (!get_Rotation() && locxy.at(0)+ship_size >row)))
          {
            std::cout <<"in vaild locplacer" <<'\n';
            location[0] = locxy.at(0);
            location[1] = locxy.at(1);

            if(get_Rotation())
            {
              for (int i =0; i < ship_size; i++)
              { if(matrix[location[0]][location[1]+i] == '3')
               {
                 vaild_location = false;
                 std::cout << "ai_ship_interscted reserching.." <<"\n";
                 break;
               }
               vaild_location = true;
              }
            }
            else
            {
              for (int i =0; i < ship_size; i++)
              {
               if(matrix[location[0]+i][location[1]] == '3')
                {
                 vaild_location = false;
                 std::cout << "ai_ship_interscted reserching.." <<"\n";
                 break;
                }
               vaild_location = true;
              }
            }

            if(vaild_location)
            {
              if(get_Rotation())
              {
                for (int i =0; i < ship_size; i++)
                {
                   matrix[location[0]][location[1]+i] = '3';
                   ojk_ship_placr.add_obj_points(location[0],location[1]+i);

                }
              }
              else
              {
                for (int i =0; i < ship_size; i++)
                {
                  matrix[location[0]+i][location[1]] = '3';
                  ojk_ship_placr.add_obj_points(location[0]+i,location[1]);
                }
              }
              std::cout << "Vaild location found ship Placed!" << '\n' << '\n';
            }
          }
        }
      }
  }



/////////////////////////////////Battleship

inline std::tuple<double,std::vector<bool>> Battleship::damage_report()
{
  damage_taken = (double)ojk_ship_placr.colsid_stack.size();

  std::cout <<"#TESZ_DAMGE_REPROLLLZKKKOUT damgetakenz:::" << damage_taken <<'\n'
            <<"------------------------------------------------||"<<'\n';

  if(damage_taken>=1)
  {
      if(ojk_ship_placr.colsid_stack.size()>=ship_size)
      {
        sunk = true;
        std::cout<<"SHIPREPORTEDSUnKz!;-Battleship^^^^IDZ:" << get_id() << '\n'
        << "______(((***^^&%$)))___" <<'\n';
        damage_model.set();
      }
      else
       { for(size_t i =0; i< ojk_ship_placr.colsid_stack.size(); i++)
         {
           std::vector<int>* temp_col_ptr = ojk_ship_placr.colsid_stack.top();
           damage_model.set((location[0]-temp_col_ptr->at(0))-
                            (location[1]-temp_col_ptr->at(1)));
           ojk_ship_placr.colsid_stack.pop();
           std::cout << "-Battleship^^^dmagedz at:"
           << damage_model[(location[0]-temp_col_ptr->at(0))-
                            (location[1]-temp_col_ptr->at(1))];
         }
       }

      if(damage_model[ship_size])
       {
         std::cout << "#->damage_rudderBattleship" << '\n';
         disabled = true;
         damage_taken +=(3+ship_size)/ship_size;
         std::cout <<"dadamage_taken..==_+" << damage_taken << '\n'
                   <<"________________||||" <<'\n';
        }

      if (damage_model.count()> (ship_size -(ship_size/2)))
        {
            std::cout << "#->taken_damagez:zSEVRKZ! UNITDISABLEDZ|Battleship" << '\n';
             disabled = true;
             damage_taken +=(ship_size+ojk_ship_placr.colsid_stack.size()/ship_size+3);

            std::cout << damage_taken << '\n';
        }
      }//enddamzgreate1
    //  std::bitset<5>*  ptrbitset = &damage_model;
    std::vector<bool> vec_damge;

      for (size_t i=0; i< damage_model.size(); i++)
      {
        vec_damge.push_back(damage_model[i]);
      }                //std::vector<bool> ptr_dmg_vec = &vec_damge;
    //  auto t =;
      return std::make_tuple(damage_taken,vec_damge);
  }


std::vector<int> Battleship::rad_loc_placer()
{
  std::vector<int> locxy;
  std::cout <<"loading random AI battlehsip" << '\n';

  if(get_Rotation())
  {
    locxy.push_back(rad_rowH());
    locxy.push_back(ojk_ship_placr.rad_col());
    std::cout <<"ailoc horz: "<< locxy.at(0) << " " << locxy.at(1) << '\n';
      }
  else
  {
    locxy.push_back(ojk_ship_placr.rad_row());
    locxy.push_back(rad_colH());
    std::cout <<"ailoc: vert: "<< locxy.at(0) << " " << locxy.at(1) << '\n';
      }
  return {locxy};
}



void Battleship::set_location(char (*matrix)[collum])
{
 int x, y;
 if(!AI_Ship)
   {
    bool vaild_location= false;
    while(!vaild_location)
    {
      std::cout << "set Ship Location and Orintation" << '\n';
      rotate();
      std::cout <<"input x and y location for front of ship";
      std::cin >> x >> y;
      std::cout << '\n';

      if (x<0 || x>row || y<0 || y>collum ||
         (get_Rotation() && y+ship_size >collum)||
         (!get_Rotation() && x+ship_size >row))
      {
         std::cout <<  "ERROR invaild point" << '\n';
         std::cin.clear();
         std::cin.ignore(10000, '\n');
      }
      else
        {
          location[0] = x;
          location[1] = y;

          if(get_Rotation())
          {
            for (int i =0; i < ship_size; i++)
            {
              if (matrix[location[0]][location[1]+i] !='#')
              {
               std::cout << "your ship crosses another ship NOT VAILD" << '\n';
               vaild_location= false;
               break;
              }
             vaild_location= true;
            }
           }
           if(!get_Rotation())
           {
             for (int i =0; i < ship_size; i++)
             {
               if(matrix[location[0]+i][location[1]] != '#')
               {
                std::cout << "your ship crosses another ship NOT VAILD" << '\n';
                vaild_location= false;
                break;
               }
              vaild_location= true;
             }
            }
          }
        }//end of while found a vaild location
        if(vaild_location)
        {
          if(get_Rotation())
          { std::cout << "rotatedship! being placed!" << '\n';
            for (size_t i =0; i < ship_size; i++)
            {
             matrix[location[0]][location[1]+i] = ship_symbl;
             ojk_ship_placr.add_obj_points(location[0],location[1]+i);
            }
          }
            if(!get_Rotation())
          {
            for (size_t i =0; i < ship_size; i++)
            {
              matrix[location[0]+i][location[1]] = ship_symbl;
              ojk_ship_placr.add_obj_points(location[0]+i,location[1]);
            }
          }
         }
       }//end of player setup
   //ai setup
   if(AI_Ship)
   {
     std::cout <<"LOading AI ship LOCATIONz" << '\n';
     bool vaild_location= false;
     int round=0;
     while (!vaild_location)
     {
       round++;
       std::cout << "seeking vaild round: " << round << '\n';
       std::vector<int> locxy;
       rotate();
       locxy = rad_loc_placer();

       if (!(locxy.at(0)>row || locxy.at(1)>collum ||
          (get_Rotation() &&  locxy.at(1)+ship_size >collum)||
          (!get_Rotation() && locxy.at(0)+ship_size >row)))
        {
          std::cout <<"in vaild locplacer" <<'\n';
          location[0] = locxy.at(0);
          location[1] = locxy.at(1);

          if(get_Rotation())
          {
            for (int i =0; i < ship_size; i++)
            { if(matrix[location[0]][location[1]+i] == '3')
             {
               vaild_location = false;
               std::cout << "ai_ship_interscted reserching.." <<"\n";
               break;
             }
             vaild_location = true;
            }
          }
          else
          {
            for (int i =0; i < ship_size; i++)
            {
             if(matrix[location[0]+i][location[1]] == '3')
              {
               vaild_location = false;
               std::cout << "ai_ship_interscted reserching.." <<"\n";
               break;
              }
             vaild_location = true;
            }
          }

          if(vaild_location)
          {
            if(get_Rotation())
            {
              for (int i =0; i < ship_size; i++)
              {
                 matrix[location[0]][location[1]+i] = '3';
                 ojk_ship_placr.add_obj_points(location[0],location[1]+i);

              }
            }
            else
            {
              for (int i =0; i < ship_size; i++)
              {
                matrix[location[0]+i][location[1]] = '3';
                ojk_ship_placr.add_obj_points(location[0]+i,location[1]);
              }
            }
            std::cout << "Vaild location found ship Placed!" << '\n' << '\n';
          }
        }
      }
    }
}

/////////////////////////////////Submarine



inline std::tuple<double,std::vector<bool>> Submarine::damage_report()
{
  damage_taken = (double)ojk_ship_placr.colsid_stack.size();

  std::cout <<"#TESZ_DAMGE_REPROLLLZKKKOUT damgetakenz:::" << damage_taken <<'\n'
            <<"------------------------------------------------||"<<'\n';

  if(damage_taken>=1)
  {
      if(ojk_ship_placr.colsid_stack.size()>=ship_size)
      {
        sunk = true;
        std::cout<<"SHIPREPORTEDSUnKz!;-Submarine^^^^IDZ:" << get_id() << '\n'
        << "______(((***^^&%$)))___" <<'\n';
        damage_model.set();
      }
      else
       { for(size_t i =0; i< ojk_ship_placr.colsid_stack.size(); i++)
         {
           std::vector<int>* temp_col_ptr = ojk_ship_placr.colsid_stack.top();
           damage_model.set((location[0]-temp_col_ptr->at(0))-
                            (location[1]-temp_col_ptr->at(1)));
           ojk_ship_placr.colsid_stack.pop();
           std::cout << "-Submarine^^^dmagedz at:"
           << damage_model[(location[0]-temp_col_ptr->at(0))-
                            (location[1]-temp_col_ptr->at(1))];
         }
       }

      if(damage_model[ship_size])
       {
         std::cout << "#->damage_rudderSubmarine" << '\n';
         disabled = true;
         damage_taken +=(3+ship_size)/ship_size;
         std::cout <<"dadamage_taken..==_+" << damage_taken << '\n'
                   <<"________________||||" <<'\n';
        }

      if (damage_model.count()> (ship_size -(ship_size/2)))
        {
            std::cout << "#->taken_damagez:zSEVRKZ! UNITDISABLEDZ|Submarine" << '\n';
             disabled = true;
             damage_taken +=(ship_size+ojk_ship_placr.colsid_stack.size()/ship_size+3);

            std::cout << damage_taken << '\n';
        }
      }//enddamzgreate1
    //  std::bitset<5>*  ptrbitset = &damage_model;
    std::vector<bool> vec_damge;

      for (size_t i=0; i< damage_model.size(); i++)
      {
        vec_damge.push_back(damage_model[i]);
      }                //std::vector<bool> ptr_dmg_vec = &vec_damge;
    //  auto t =;
      return std::make_tuple(damage_taken,vec_damge);
  }

std::vector<int> Submarine::rad_loc_placer()
{
  std::vector<int> locxy;
  std::cout <<"loading random AI Submarine" << '\n';

  if(get_Rotation())
  {
    locxy.push_back(rad_rowH());
    locxy.push_back(ojk_ship_placr.rad_col());
    std::cout <<"ailoc horz: "<< locxy.at(0) << " " << locxy.at(1) << '\n';
  }
  else
  {
    locxy.push_back(ojk_ship_placr.rad_row());
    locxy.push_back(rad_colH());
    std::cout <<"ailoc: vert: "<< locxy.at(0) << " " << locxy.at(1) << '\n';
  }
  return {locxy};
}



void Submarine::set_location(char (*matrix)[collum])
{
 int x, y;
 if(!AI_Ship)
   {
    bool vaild_location= false;
    while(!vaild_location)
    {
      std::cout << "set Ship Location and Orintation" << '\n';
      rotate();
      std::cout <<"input x and y location for front of ship";
      std::cin >> x >> y;
      std::cout << '\n';

      if (x<0 || x>row || y<0 || y>collum ||
         (get_Rotation() && y+ship_size >collum)||
         (!get_Rotation() && x+ship_size >row))
      {
         std::cout <<  "ERROR invaild point" << '\n';
         std::cin.clear();
         std::cin.ignore(10000, '\n');
      }
      else
        {
          location[0] = x;
          location[1] = y;

          if(get_Rotation())
          {
            for (int i =0; i < ship_size; i++)
            {
              if (matrix[location[0]][location[1]+i] !='#')
              {
               std::cout << "your ship crosses another ship NOT VAILD" << '\n';
               vaild_location= false;
               break;
              }
             vaild_location= true;
            }
           }
           if(!get_Rotation())
           {
             for (int i =0; i < ship_size; i++)
             {
               if(matrix[location[0]+i][location[1]] != '#')
               {
                std::cout << "your ship crosses another ship NOT VAILD" << '\n';
                vaild_location= false;
                break;
               }
              vaild_location= true;
             }
            }
          }
        }//end of while found a vaild location
        if(vaild_location)
        {
          if(get_Rotation())
          { std::cout << "rotatedship! being placed!" << '\n';
            for (int i =0; i < ship_size; i++)
            {
              matrix[location[0]][location[1]+i] = ship_symbl;
              ojk_ship_placr.add_obj_points(location[0],location[1]+i);

            }
          }
            if(!get_Rotation())
          {
            for (int i =0; i < ship_size; i++)
            {
              matrix[location[0]+i][location[1]] = ship_symbl;
              ojk_ship_placr.add_obj_points(location[0]+i,location[1]);
            }
          }
         }
       }//end of player setup
   //ai setup
   if(AI_Ship)
   {
     std::cout <<"LOading AI ship LOCATIONz" << '\n';
     bool vaild_location= false;
     int round=0;
     while (!vaild_location)
     {
       round++;
       std::cout << "seeking vaild round: " << round << '\n';
       std::vector<int> locxy;
       rotate();
       locxy = rad_loc_placer();

       if (!(locxy.at(0)>row || locxy.at(1)>collum ||
          (get_Rotation() &&  locxy.at(1)+ship_size >collum)||
          (!get_Rotation() && locxy.at(0)+ship_size >row)))
        {
          std::cout <<"in vaild locplacer" <<'\n';
          location[0] = locxy.at(0);
          location[1] = locxy.at(1);


          if(get_Rotation())
          {
            for (int i =0; i < ship_size; i++)
            { if(matrix[location[0]][location[1]+i] == '3')
             {
               vaild_location = false;
               std::cout << "ai_ship_interscted reserching.." <<"\n";
               break;
             }
             vaild_location = true;
            }
          }
          else
          {
            for (int i =0; i < ship_size; i++)
            {
             if(matrix[location[0]+i][location[1]] == '3')
              {
               vaild_location = false;
               std::cout << "ai_ship_interscted reserching.." <<"\n";
               break;
              }
             vaild_location = true;
            }
          }

          if(vaild_location)
          {
            if(get_Rotation())
            {
              for (int i =0; i < ship_size; i++)
              {
                 matrix[location[0]][location[1]+i] = '3';
                 ojk_ship_placr.add_obj_points(location[0],location[1]+i);

              }
            }
            else
            {
              for (int i =0; i < ship_size; i++)
              {
                matrix[location[0]+i][location[1]] = '3';
                ojk_ship_placr.add_obj_points(location[0]+i,location[1]);
              }
            }
            std::cout << "Vaild location found ship Placed!" << '\n'<< '\n';
          }
        }
      }
    }
}

/*



void Aircraft_Carrier::set_location(char (*matrix)[collum])
{


  int x, y;
  std::cout <<"input x and y location for front of ship";
  std::cin >> x >> y;
  std::cout << '\n';
  roatate();

  if (x<0 || x>row || y<0 || y>collum ||
     (get_rotation() && y+ship_size >collum)||
     (!get_rotation() && x+ship_size >row))
  {
    std::cout << "ERROR invaild point" << '\n';
    std::cin.clear();
    std::cin.ignore(10000, '\n');
  }
  else
  {
    location[0] = x;
    location[1] = y;

    if(get_Rotation())
    {
      for (int i =0; i < ship_size; i++)
      {
         matrix[x][y+i] = 'p';
      }
    }

    else
    {
      for (int i =0; i < ship_size; i++)
      {
        matrix[x+i][y] = 'p';
      }
    }
  }
}


*/



/*
player_select_shiptypes()
{   int num_ships=5;
    enum {Aircraft_Carrier,Battleship,Submarine,Crusier, Patrol_boat};
    bool used[5];
    int ship_to_place;
    int x,y;
    cout << "Select Shiptype to place: \
            0:Aircraft_Carrier, 1:Battleship, 2:Submarine, 3:Crusier, 4:Patrol_boat,";

    for (int sn =0; sn<num_ships;)
    { sn++
      cin>> ship_to_place;
      if(ship_to_place>5||ship_to_place<1)
      {
        cout << "ERROR not vaild ship" << '\n';
        cin.clear();
        cin.ignore(10000, '\n');
      }
      else
      {
         if(used[ship_to_place])
        {
          cout << "You have already placed this shiptype";
          sn--;
          continue;
        }
        used[ship_to_place] = true;
        cout << "enter front of ship x Coordinate:";
        cin >> x;
        cout << '\n'<< "enter front of ship y Coordinate:";
        cin >> y;
        cout << "roate ship? y/n";

       }

    }

}
*/
