#ifndef CMDSTAN_ARGUMENTS_ARG_MAX_OMEGA_HPP
#define CMDSTAN_ARGUMENTS_ARG_MAX_OMEGA_HPP

#include <cmdstan/arguments/singleton_argument.hpp>

namespace cmdstan {

class arg_max_omega : public real_argument {
 public:
  arg_max_omega() : real_argument() {
    _name = "max_omega";
    _description = "Minimum sane value of log(sigma) for mixture components. Log is base e.";
    _validity = "max_omega > log(1e3)";
    _default = "log(1e20)";
    _default_value = +46.0;
    _constrained = false;
    _good_value = +46.0;
    _bad_value = 0.0;
    _value = _default_value;
  }
};

}  // namespace cmdstan
#endif
