
struct stan_model;

template double
stan_model::log_prob<true, true>(std::vector<double>&,
                                 std::vector<int>&,
                                 std::ostream*) const;

template stan::math::var
stan_model::log_prob<true, true>(Eigen::Matrix<stan::math::var, -1, 1>& params_r,
                                 std::ostream* pstream) const;

template double
stan_model::log_prob<true, false>(std::vector<double>&,
                                  std::vector<int>&,
                                  std::ostream*) const;

template stan::math::var
stan_model::log_prob<true, false>(Eigen::Matrix<stan::math::var, -1, 1>& params_r,
                                  std::ostream* pstream) const;

template double
stan_model::log_prob<false, false>(std::vector<double>&,
                                  std::vector<int>&,
                                  std::ostream*) const;

template stan::math::var
stan_model::log_prob<false, false>(Eigen::Matrix<stan::math::var, -1, 1>& params_r,
                                  std::ostream* pstream) const;

template double
stan_model::log_prob<false, true>(std::vector<double>&,
                                  std::vector<int>&,
                                  std::ostream*) const;

template double
stan_model::log_prob<false, true>(Eigen::Matrix<double, -1, 1>& params_r,
                                  std::ostream* pstream) const;


template void
stan_model::write_array(boost::ecuyer1988& base_rng__,
                        std::vector<double>& params_r__,
                        std::vector<int>& params_i__,
                        std::vector<double>& vars__,
                        bool include_tparams__ = true,
                        bool include_gqs__ = true,
                        std::ostream* pstream__) const;

template void
stan_model::write_array(boost::ecuyer1988& base_rng,
                        Eigen::Matrix<double, -1, 1>& params_r,
                        Eigen::Matrix<double, -1, 1>& vars,
                        bool include_tparams = true,
                        bool include_gqs = true,
                        std::ostream* pstream) const;
