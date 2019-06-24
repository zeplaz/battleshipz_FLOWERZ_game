
#pragma once

#include <unordered_map>
#include <memory>
#include <array>

#include "tela_cmdz.h"
#include "game_board.hpp"
#include "agent_act.hpp"

typedef std::shared_ptr<CMD_Z*> Cmz_Ptr;
#define tela_office_manger tela_cmd_office::Instance();

class tela_cmd_office
{

  private :

  tela_cmd_office(const tela_cmd_office&);
  tela_cmd_office& operator =(const tela_cmd_office&);


  std::vector<game_board*> gameBordz_ptr;
  std::unordered_map<int,agentz*> agent_listed;
  typedef decltype(agentz*) agent_type_name;
  typedef decltype(game_board*) game_board_type_name;
  //std::unordered_map<int,ships*>
  //std::array<int,Cmz_Ptr>
  //std::array<>
  public :

  static tela_cmd_office* Instance();

   tela_cmd_office() = default; // deal with id latr.

   ~tela_cmd_office() = default;


  void listenTo_tela(void* in_channel);

  //this->send_to_tela_office();
  template< typename rejitary_type>
  void Register_at_post(rejitary_type in_rigstar)
  {
      if (game_board_type_name == decltype(in_rigstar))
      {
        gameBordz_ptr.push_back(in_rigstar);
      }
      if(agent_type_name==in_rigstar)
      {
        agent_listed.insert(in_rigstar->get_id(),in_rigstar);
      }

  }

  void Deregiztarz();

  template< typename tela_type>
  publish();

  template< typename tela_type>
  secribez();

  //template<class... Args>
//  void listenTo_tela(const std::string& in_channel, std::function<void(Args...)> callback);




  void broadcast_tela(telagram* full_trazmition);
  {

  }

  template<class unit_type>
  unit_type* get_rec_ptr_via_ID(int& type, int reciver)
  {
    if( reciver <0)
    {
    //  return gameBordz_ptr.at(reciver*-1);
    }

    else
    {
      agent_listed.find(reciver);
    }

  }

  /*
  virtual void clearListeners() = 0;


          void clearListeners() override
          {
              //Erase-remove idiom
              _listeners.erase(std::remove_if(
                                              _listeners.begin(),
                                              _listeners.end(),
                                              [](const listener& listener)
                                              {
                                                  return !*listener.first;
                                              }
                                              ),
                              _listeners.end());
          }
          */
};
