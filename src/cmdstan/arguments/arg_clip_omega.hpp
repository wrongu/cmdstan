#ifndef CMDSTAN_ARGUMENTS_ARG_CLIP_OMEGA_HPP
#define CMDSTAN_ARGUMENTS_ARG_CLIP_OMEGA_HPP

#include <cmdstan/arguments/singleton_argument.hpp>

namespace cmdstan {

class arg_clip_omega : public real_argument {
 public:
  arg_clip_omega() : real_argument() {
    _name = "clip_omega";
    _description = "Minimum sane value of log(sigma) for mixture components. Log is base e.";
    _validity = "clip_omega < log(1e-3)";
    _default = "log(2.06e-09)";
    _default_value = -20.0;
    _constrained = false;
    _good_value = -20.0;
    _bad_value = 0.0;
    _value = _default_value;
  }
};

}  // namespace cmdstan
#endif
