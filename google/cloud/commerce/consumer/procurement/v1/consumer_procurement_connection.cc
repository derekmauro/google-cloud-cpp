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

#include "google/cloud/commerce/consumer/procurement/v1/consumer_procurement_connection.h"
#include "google/cloud/commerce/consumer/procurement/v1/consumer_procurement_options.h"
#include "google/cloud/commerce/consumer/procurement/v1/internal/consumer_procurement_connection_impl.h"
#include "google/cloud/commerce/consumer/procurement/v1/internal/consumer_procurement_option_defaults.h"
#include "google/cloud/commerce/consumer/procurement/v1/internal/consumer_procurement_stub_factory.h"
#include "google/cloud/commerce/consumer/procurement/v1/internal/consumer_procurement_tracing_connection.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/credentials.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace commerce_consumer_procurement_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ConsumerProcurementServiceConnection::~ConsumerProcurementServiceConnection() =
    default;

future<StatusOr<google::cloud::commerce::consumer::procurement::v1::Order>>
ConsumerProcurementServiceConnection::PlaceOrder(
    google::cloud::commerce::consumer::procurement::v1::
        PlaceOrderRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::commerce::consumer::procurement::v1::Order>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

StatusOr<google::cloud::commerce::consumer::procurement::v1::Order>
ConsumerProcurementServiceConnection::GetOrder(
    google::cloud::commerce::consumer::procurement::v1::
        GetOrderRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<google::cloud::commerce::consumer::procurement::v1::Order>
ConsumerProcurementServiceConnection::ListOrders(
    google::cloud::commerce::consumer::procurement::v1::
        ListOrdersRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::cloud::commerce::consumer::procurement::v1::Order>>();
}

std::shared_ptr<ConsumerProcurementServiceConnection>
MakeConsumerProcurementServiceConnection(Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 UnifiedCredentialsOptionList,
                                 ConsumerProcurementServicePolicyOptionList>(
      options, __func__);
  options = commerce_consumer_procurement_v1_internal::
      ConsumerProcurementServiceDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = commerce_consumer_procurement_v1_internal::
      CreateDefaultConsumerProcurementServiceStub(background->cq(), options);
  return commerce_consumer_procurement_v1_internal::
      MakeConsumerProcurementServiceTracingConnection(
          std::make_shared<commerce_consumer_procurement_v1_internal::
                               ConsumerProcurementServiceConnectionImpl>(
              std::move(background), std::move(stub), std::move(options)));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace commerce_consumer_procurement_v1
}  // namespace cloud
}  // namespace google
