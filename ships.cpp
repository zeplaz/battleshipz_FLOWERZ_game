

#include "ships.hpp"

  void ships::rotate()
  {
    if(!AI_Ship)
     {
      char c_rotate;
      std::cout<< "roate ship? to Horizontal y/n?";
      std::cin >> c_rotate;
      std::cout << '\n';

      if(!(c_rotate =='y'))
        { rotation = false;}
      else
        {
          std::cin.clear();
          std::cin.ignore(10000, '\n');
          rotation = false;
        }
      }
     else
      {
        rotation= bool_radom();
      }
   }


  std::vector<int> Battleship::rad_loc_placer()
  {
    std::vector<int> locxy;
    std::cout <<"loading random AI battlehsip" << '\n';
    const auto seed = seeder.entropy()? seeder() : time(nullptr);
    std::mt19937 eng(static_cast<std::mt19937::result_type>(seed));

    std::uniform_int_distribution<int>dis_r(0,row);
    std::uniform_int_distribution<int>dis_r2(0,row-ship_size);
    std::uniform_int_distribution<int>dis_c(0,collum);
    std::uniform_int_distribution<int>dis_c2(0,collum-ship_size);
  //  auto gen1 = std::bind(dis_r,eng);
  //  auto gen2 =std::bind(dis_r2,eng);
  //  auto gen3 =std::bind(dis_c,eng);
  //  auto gen4 =std::bind(dis_c2,eng);

    if(get_Rotation())
    {
      locxy.push_back(dis_r2(eng));
      locxy.push_back(dis_c(eng));
      std::cout <<"ailoc horz: "<< locxy.at(0) << " " << locxy.at(1) << '\n';
    }
    else
    {
      locxy.push_back(dis_r(eng));
      locxy.push_back(dis_c2(eng));
      std::cout <<"ailoc: vert: "<< locxy.at(0) << " " << locxy.at(1) << '\n';
    }
    return {locxy};
  }

  void Battleship::set_location(char (*matrix)[collum])
  {
    int x, y;
    if(!AI_Ship)
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

     }//end of player setup
     //ai setup
     else
     { std::cout <<"LOading AI ship LOCATIONz" << '\n';
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
            vaild_location = true;
            location[0] = locxy.at(0);
            location[1] = locxy.at(1);

            if(get_Rotation())
            {
              for (int i =0; i < ship_size; i++)
              {
                 matrix[location[0]][location[1]+i] = '3';
              }
            }

            else
            {
              for (int i =0; i < ship_size; i++)
              {
                matrix[location[0]+i][location[1]] = '3';
              }
            }
            std::cout << "Vaild location found ship Placed!" << '\n';
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
