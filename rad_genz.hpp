

/* RAD_GENZ.HPP
  |-$-|stable alpha 0.00001
    ##a base radom genrator, like need to expalnd this working or move it osmewhere...
    some basic gens, and a useful little use class, trying to cleanup stuff. but whaver.works now will expand or move.
*/

#pragma once

class rad_genz {

    private :

    std::mt19937 gen_;
    std::uniform_int_distribution<size_t> dist_;
    std::random_device seeder;

    public:
      rad_genz(size_t min, size_t max,unsigned int seed = std::random_device{}())
        : gen_{seed}, dist_{min, max}
          {

          }
    size_t operator()() {
        return dist_(gen_);
    }
};
/*
class rad_genz
{const auto seed = seeder.entropy()? seeder() : time(nullptr);
gen_(seed);
  private:
    auto gen_bool = std::bind(std::uniform_int_distribution<int>(0,1),
                      std::default_random_engine());
  public :
  std::random_device seeder;
  auto run_gen();

};


    //std::uniform_int_distribution<int>dis_r(0,row);
    //std::uniform_int_distribution<int>dis_r2(0,row-ship_size);
    //std::uniform_int_distribution<int>dis_c(0,collum);
  //  std::uniform_int_distribution<int>dis_c2(0,collum-ship_size);
  //  auto gen1 = std::bind(dis_r,eng);
  //  auto gen2 =std::bind(dis_r2,eng);
  //  auto gen3 =std::bind(dis_c,eng);
  //  auto gen4 =std::bind(dis_c2,eng);
*/
