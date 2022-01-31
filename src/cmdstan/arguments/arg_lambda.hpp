#ifndef CMDSTAN_ARGUMENTS_ARG_LAMBDA_HPP
#define CMDSTAN_ARGUMENTS_ARG_LAMBDA_HPP

#include <cmdstan/arguments/singleton_argument.hpp>

namespace cmdstan {

class arg_lambda : public real_argument {
 public:
  arg_lambda() : real_argument() {
    _name = "lambda";
    _description = "Hyperparameter trading off sampling-like behavior (lambda=1.0) with variational-like behavior (lambda=infinity).";
    _validity = "1.0 <= lambda";
    _default = "2.0";
    _default_value = 2.0;
    _constrained = true;
    _good_value = 2.0;
    _bad_value = 0.5;
    _value = _default_value;
  }

  bool is_valid(int value) { return value >= 1.0; }
};

}  // namespace cmdstan
#endif
