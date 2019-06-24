
#include "tela_dispacher.hpp"

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

        recv_type* ptr_reciver  = tela_cmd_office.get_rec_ptr_via_ID(reciver);

        telagram tela_prep(send_zero_t,sender,reciver,priority,msg,other_data);

        if(time <=0.0f)
         {
          printf("---->><<<>>>DISPATCH:: undelayed TELA at: %s \n",std::clock());
          call_receiver_transmit(prt_reciver, tela_prep);
         }
       }
