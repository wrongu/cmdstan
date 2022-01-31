#ifndef CMDSTAN_ARGUMENTS_ARG_NUM_KL_SAMPLES_HPP
#define CMDSTAN_ARGUMENTS_ARG_NUM_KL_SAMPLES_HPP

#include <cmdstan/arguments/singleton_argument.hpp>

namespace cmdstan {

class arg_num_kl_samples : public int_argument {
 public:
  arg_num_kl_samples() : int_argument() {
    _name = "num_kl_samples";
    _description = "Number of samples of q when evaluating KL(q||p)";
    _validity = "0 <= num_kl_samples";
    _default = "10";
    _default_value = 10;
    _constrained = true;
    _good_value = 2.0;
    _bad_value = -1.0;
    _value = _default_value;
  }

  bool is_valid(int value) { return value >= 0; }
};

}  // namespace cmdstan
#endif
