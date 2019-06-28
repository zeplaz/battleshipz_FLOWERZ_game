



#include <fstream>
#include <string>

class log_file_helpr
{
  private :
  std::string logfile_name;
  std::string output_string_work;

  logfile_name = 'LOG_SYSMZz' + (std::string) std::chrono::system_clock::now();

  std::ofstream log_file("log_sytemz.txt", std::ios_base::out | std::ios_base::app);


template<typename intype>
  bool add_to_log(intype in_tolog) 
    {

      output_string_work = reinterpret_cast<std::string>
    }

  bool write()
};
