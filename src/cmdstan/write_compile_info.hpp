#ifndef CMDSTAN_WRITE_COMPILE_INFO_HPP
#define CMDSTAN_WRITE_COMPILE_INFO_HPP

#include <stan/callbacks/writer.hpp>
#include <stan/version.hpp>
#include <string>
#include <vector>

namespace cmdstan {
void write_compile_info(stan::callbacks::writer &writer,
                 std::vector<std::string>& compile_info) {
    writer("STAN_VERSION = " + stan::MAJOR_VERSION + "." + stan::MINOR_VERSION + "." + stan::PATCH_VERSION);
    for (int i = 0; i < compile_info.size(); i++) {
       writer(compile_info[i]);
    }
#ifdef STAN_THREADS
    writer("STAN_THREADS=true");
#endif
#ifdef STAN_MPI
    writer("STAN_MPI=true");
#endif
#ifdef STAN_OPENCL
    writer("STAN_OPENCL=true");
    std::stringstream msg;
    msg << "OPENCL_PLATFORM_ID=" << OPENCL_PLATFORM_ID << "\n"
        << "OPENCL_DEVICE_ID=" << OPENCL_DEVICE_ID;
    writer(msg.str());
#endif
}
}  // namespace cmdstan
#endif
