


#pragma once

#include <time.h>

#include "telagram.h"


#define tranzmitor tela_dipacher::instance()

const double send_zero_t = 0.0;
const int no_info = 0;
const int void_id_sender =-1;


class tela_dipacher
{
  private :
  ~tela_dipacher() = default;
  tela_dipacher() = default;

  tela_dipacher(const consttela_dipacher&);

  tela_dipacher& operator=(const consttela_dipacher&);

  public :

  static tela_dipacher* instance();

  <template class enity_type>
  void call_receiver_transmit(enity_type* prt_receiver,
                              const telagram& tela);

  template <class other_data>
    void trazmit_telagram(double time, int sender, int reciver, float priority,
                        int msg, other_data* other_data);

};


#include <unordered_map>

class tela_cmd_office
{

  std::vector<> lesoning_post
  void listenTo_tela(*);

  this->send_to_tela_office();
  void Register_at_post();
  void Deregiztarz();

  template< typename tela_type>
  publish();

  template< typename tela_type>
  secribez();

  void broadcast_tela(telagram* full_trazmition);
  {

  }


};


#include "tela_dipacher.hpp"

  tela_dipacher* tela_dipacher::instance()
  {
    printf("tela_dis_inilaized\n");
    static tela_dipacher instance;
    return &instance;
  }

template <class enity_type>
  void tela_dipacher::call_receiver_transmit(enity_type* prt_receiver,
                                              const telagram& tela)
       {
        {
          if(!prt_receiver->Handle_telagram(tela))
           {
            printf("msg not figured ",\n);
           }
        }
       }

    template <class other_data, nametype recv_type>
    void tela_dipacher::trazmit_telagram(double time, int sender, int reciver, float priority,
                                         int msg, other_data* other_data)
      {
        printf("TELA__TRAZMIZ_:: locating:reciver",\n);
        //location of entityz
        recv_type* ptr_reciver  = get_enity_via_id();

        telagram tela_prep(send_zero_t,sender,reciver,priority,msg,other_data);

        if(time <=0.0f)
         {
          printf("---->><<<>>>DISPATCH:: undelayed TELA at: %s \n",std::clock());
          call_receiver_transmit(prt_reciver, tela_prep);
         }
       }
