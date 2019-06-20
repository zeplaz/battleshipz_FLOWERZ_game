


class rad_genz {
    // random seed by default
    private :

    std::mt19937 gen_;
    std::uniform_int_distribution<size_t> dist_;
    std::random_device seeder;

    public:
    /*  ... some convenient ctors ... */

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

};*/
