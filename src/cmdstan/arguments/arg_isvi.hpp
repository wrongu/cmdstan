#ifndef CMDSTAN_ARGUMENTS_ARG_ISVI_HPP
#define CMDSTAN_ARGUMENTS_ARG_ISVI_HPP

#include <cmdstan/arguments/arg_adapt.hpp>
#include <cmdstan/arguments/arg_lambda.hpp>
#include <cmdstan/arguments/arg_stochastic_kl.hpp>
#include <cmdstan/arguments/arg_clip_omega.hpp>
#include <cmdstan/arguments/arg_max_depth.hpp>
#include <cmdstan/arguments/arg_num_kl_samples.hpp>
#include <cmdstan/arguments/arg_num_samples.hpp>
#include <cmdstan/arguments/arg_num_warmup.hpp>
#include <cmdstan/arguments/arg_save_warmup.hpp>
#include <cmdstan/arguments/arg_stepsize.hpp>
#include <cmdstan/arguments/arg_stepsize_jitter.hpp>
#include <cmdstan/arguments/arg_thin.hpp>
#include <cmdstan/arguments/categorical_argument.hpp>

namespace cmdstan {

class arg_isvi : public categorical_argument {
 public:
  arg_isvi() {
    _name = "isvi";
    _description = "Bayesian inference with Markov Chain Monte Carlo over variational parameters";

    _subarguments.push_back(new arg_adapt());
    _subarguments.push_back(new arg_lambda());
    _subarguments.push_back(new arg_stochastic_kl());
    _subarguments.push_back(new arg_clip_omega());
    _subarguments.push_back(new arg_num_samples());
    _subarguments.push_back(new arg_num_warmup());
    _subarguments.push_back(new arg_save_warmup());
    _subarguments.push_back(new arg_thin());
    _subarguments.push_back(new arg_stepsize());
    _subarguments.push_back(new arg_stepsize_jitter());
    _subarguments.push_back(new arg_max_depth());
    _subarguments.push_back(new arg_num_kl_samples());
  }
};

}  // namespace cmdstan
#endif
