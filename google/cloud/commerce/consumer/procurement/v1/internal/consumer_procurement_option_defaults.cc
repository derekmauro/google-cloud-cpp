// Copyright 2023 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source:
// google/cloud/commerce/consumer/procurement/v1/procurement_service.proto

#include "google/cloud/commerce/consumer/procurement/v1/internal/consumer_procurement_option_defaults.h"
#include "google/cloud/commerce/consumer/procurement/v1/consumer_procurement_connection.h"
#include "google/cloud/commerce/consumer/procurement/v1/consumer_procurement_options.h"
#include "google/cloud/internal/populate_common_options.h"
#include "google/cloud/internal/populate_grpc_options.h"
#include <memory>

namespace google {
namespace cloud {
namespace commerce_consumer_procurement_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

namespace {
auto constexpr kBackoffScaling = 2.0;
}  // namespace

Options ConsumerProcurementServiceDefaultOptions(Options options) {
  options = google::cloud::internal::PopulateCommonOptions(
      std::move(options),
      "GOOGLE_CLOUD_CPP_CONSUMER_PROCUREMENT_SERVICE_ENDPOINT", "",
      "GOOGLE_CLOUD_CPP_CONSUMER_PROCUREMENT_SERVICE_AUTHORITY",
      "cloudcommerceconsumerprocurement.googleapis.com");
  options =
      google::cloud::internal::PopulateGrpcOptions(std::move(options), "");
  if (!options.has<commerce_consumer_procurement_v1::
                       ConsumerProcurementServiceRetryPolicyOption>()) {
    options.set<commerce_consumer_procurement_v1::
                    ConsumerProcurementServiceRetryPolicyOption>(
        commerce_consumer_procurement_v1::
            ConsumerProcurementServiceLimitedTimeRetryPolicy(
                std::chrono::minutes(30))
                .clone());
  }
  if (!options.has<commerce_consumer_procurement_v1::
                       ConsumerProcurementServiceBackoffPolicyOption>()) {
    options.set<commerce_consumer_procurement_v1::
                    ConsumerProcurementServiceBackoffPolicyOption>(
        ExponentialBackoffPolicy(
            std::chrono::seconds(0), std::chrono::seconds(1),
            std::chrono::minutes(5), kBackoffScaling, kBackoffScaling)
            .clone());
  }
  if (!options.has<commerce_consumer_procurement_v1::
                       ConsumerProcurementServicePollingPolicyOption>()) {
    options.set<commerce_consumer_procurement_v1::
                    ConsumerProcurementServicePollingPolicyOption>(
        GenericPollingPolicy<
            commerce_consumer_procurement_v1::
                ConsumerProcurementServiceRetryPolicyOption::Type,
            commerce_consumer_procurement_v1::
                ConsumerProcurementServiceBackoffPolicyOption::Type>(
            options
                .get<commerce_consumer_procurement_v1::
                         ConsumerProcurementServiceRetryPolicyOption>()
                ->clone(),
            ExponentialBackoffPolicy(std::chrono::seconds(1),
                                     std::chrono::minutes(5), kBackoffScaling)
                .clone())
            .clone());
  }
  if (!options.has<
          commerce_consumer_procurement_v1::
              ConsumerProcurementServiceConnectionIdempotencyPolicyOption>()) {
    options.set<
        commerce_consumer_procurement_v1::
            ConsumerProcurementServiceConnectionIdempotencyPolicyOption>(
        commerce_consumer_procurement_v1::
            MakeDefaultConsumerProcurementServiceConnectionIdempotencyPolicy());
  }

  return options;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace commerce_consumer_procurement_v1_internal
}  // namespace cloud
}  // namespace google
