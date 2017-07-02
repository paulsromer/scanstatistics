#ifndef SCAN_EB_POI_H
#define SCAN_EB_POI_H

#include "RcppArmadillo.h"
// [[depends(RcppArmadillo)]]

//' Calculate the highest-value EB ZIP loglihood ratio statistic.
//'
//' Calculate the expectation-based ZIP loglihood ratio statistic for each zone
//' and duration, but only keep the zone and duration with the highest value
//' (the MLC). The estimate of the relative risk is also calculated, along with
//' the number of iterations the EM algorithm performed.
//' @param counts matrix
//' @param baselines matrix
//' @param zones list of integer vectors
//' @param zone_lengths vector
//' @param num_locs int
//' @param num_zones int
//' @param max_dur int
//' @param store_everything boolean
//' @return A data frame with five columns:
//'    \describe{
//'      \item{zone}{The top-scoring zone (spatial component of MLC).}
//'      \item{duration}{The corresponding duration (time-length of MLC).}
//'      \item{score}{The value of the loglihood ratio statistic (the scan
//'                   statistic).}
//'      \item{relrisk_in}{The estimated relative risk inside.}
//'      \item{relrisk_in}{The estimated relative risk outside.}
//'    }
//' @export
//' @keywords internal
// [[Rcpp::export]]
Rcpp::DataFrame scan_eb_poisson_cpp(const arma::umat& counts,
                                    const arma::mat& baselines,
                                    const arma::uvec& zones,
                                    const arma::uvec& zone_lengths,
                                    const int num_locs,
                                    const int num_zones,
                                    const int max_dur,
                                    const bool store_everything);


#endif