#ifndef CMDSTAN_ARGUMENTS_ARG_STOCHASTIC_KL_HPP
#define CMDSTAN_ARGUMENTS_ARG_STOCHASTIC_KL_HPP

#include <cmdstan/arguments/singleton_argument.hpp>

namespace cmdstan {

class arg_stochastic_kl : public bool_argument {
 public:
  arg_stochastic_kl() : bool_argument() {
    _name = "stochastic_kl";
    _description = "Flag whether to compute inner-loop KL(q||p) stochastically or by frozen noise";
    _validity = "[0, 1]";
    _default = "1";
    _default_value = false;
    _constrained = false;
    _good_value = 1;
    _value = _default_value;
  }
};

}  // namespace cmdstan
#endif
