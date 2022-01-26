#ifndef CMDSTAN_ARGUMENTS_ARG_ISVI_HPP
#define CMDSTAN_ARGUMENTS_ARG_ISVI_HPP

#include <cmdstan/arguments/arg_adapt.hpp>
#include <cmdstan/arguments/arg_num_chains.hpp>
#include <cmdstan/arguments/arg_num_samples.hpp>
#include <cmdstan/arguments/arg_num_warmup.hpp>
#include <cmdstan/arguments/arg_sample_algo.hpp>
#include <cmdstan/arguments/arg_save_warmup.hpp>
#include <cmdstan/arguments/arg_thin.hpp>
#include <cmdstan/arguments/categorical_argument.hpp>

namespace cmdstan {

class arg_isvi : public categorical_argument {
 public:
  arg_isvi() {
    _name = "isvi";
    _description = "Bayesian inference with Markov Chain Monte Carlo over parameters";

    _subarguments.push_back(new arg_num_samples());
    _subarguments.push_back(new arg_num_warmup());
    _subarguments.push_back(new arg_save_warmup());
    _subarguments.push_back(new arg_thin());
    _subarguments.push_back(new arg_adapt());
    _subarguments.push_back(new arg_sample_algo());
    _subarguments.push_back(new arg_num_chains());
  }
};

}  // namespace cmdstan
#endif
