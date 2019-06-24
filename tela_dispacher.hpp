

#pragma once

#include <time.h>
#include "telagram.h"
#include "tela_cmd_office.hpp"

#define tranzmitor tela_dipacher::instance()

const double send_zero_t = 0.0;
const int no_info = 0;
const int void_id_sender =-1;


class tela_dipacher
{
  private :
  ~tela_dipacher() = default;
  tela_dipacher() = default;

  tela_dipacher(const tela_dipacher&);

  tela_dipacher& operator=(const tela_dipacher&);

  public :

  static tela_dipacher* instance();

  <template class enity_type>
  void call_receiver_transmit(enity_type* prt_receiver,
                              const telagram& tela);

  template <class other_data>
    void trazmit_telagram(double time, int sender, int reciver, float priority,
                        int msg, other_data* other_data);

};
