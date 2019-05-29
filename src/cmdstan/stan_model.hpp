#ifndef CMDSTAN_STAN_MODEL_HPP
#define CMDSTAN_STAN_MODEL_HPP

#include <stan/math/prim/mat/fun/Eigen.hpp>
#include <stan/io/var_context.hpp>
#include <iostream>
#include <utility>
#include <vector>

// static int current_statement_begin__;

// stan::io::program_reader prog_reader__();

struct stan_model {

  stan_model(stan::io::var_context& context__,
             std::ostream* pstream__ = 0);

  stan_model(stan::io::var_context& context__,
             unsigned int random_seed__,
             std::ostream* pstream__ = 0);

  ~stan_model();

  void ctor_body(stan::io::var_context& context__,
                 unsigned int random_seed__,
                 std::ostream* pstream__);

  // was originally static, making it member
  std::string model_name() const;

  void transform_inits(const stan::io::var_context& context__,
                       std::vector<int>& params_i__,
                       std::vector<double>& params_r__,
                       std::ostream* pstream__) const;

  void transform_inits(const stan::io::var_context& context,
                       Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                       std::ostream* pstream__) const;

  template <bool propto__, bool jacobian__, typename T__>
  T__ log_prob(std::vector<T__>& params_r__,
               std::vector<int>& params_i__,
               std::ostream* pstream__ = 0) const;

  template <bool propto, bool jacobian, typename T_>
  T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
              std::ostream* pstream = 0) const;

  void get_param_names(std::vector<std::string>& names__) const;

  void get_dims(std::vector<std::vector<size_t> >& dimss__) const;

  template <typename RNG>
  void write_array(RNG& base_rng__,
                   std::vector<double>& params_r__,
                   std::vector<int>& params_i__,
                   std::vector<double>& vars__,
                   bool include_tparams__ = true,
                   bool include_gqs__ = true,
                   std::ostream* pstream__ = 0) const;

  template <typename RNG>
  void write_array(RNG& base_rng,
                   Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                   Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                   bool include_tparams = true,
                   bool include_gqs = true,
                   std::ostream* pstream = 0) const;

  void constrained_param_names(std::vector<std::string>& param_names__,
                               bool include_tparams__ = true,
                               bool include_gqs__ = true) const;

  void unconstrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const;

  size_t num_params_r() const;

  size_t num_params_i() const;

  std::pair<int, int> param_range_i(size_t idx) const;

  size_t num_params_r__;
  std::vector<std::pair<int, int> > param_ranges_i__;

};

#endif
