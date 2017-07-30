#include "scan_eb_zip.h"
#include "EBZIPscan.h"

Rcpp::List scan_eb_zip_cpp(const arma::umat& counts,
                           const arma::mat& baselines,
                           const arma::mat& probs,
                           const arma::uvec& zones,
                           const arma::uvec& zone_lengths,
                           const int num_locs,
                           const int num_zones,
                           const int max_dur,
                           const double rel_tol,
                           const bool store_everything,
                           const int num_mcsim) {

  EBZIPscan ob {counts, baselines, probs, zones, zone_lengths, num_locs,
                num_zones, max_dur, rel_tol, store_everything, num_mcsim};
  ob.run_scan();
  ob.run_mcsim();
  return Rcpp::List::create(
    Rcpp::Named("observed") = ob.get_scan(),
    Rcpp::Named("simulated") = ob.get_mcsim());
}

