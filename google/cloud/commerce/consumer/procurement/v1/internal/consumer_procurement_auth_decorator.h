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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_COMMERCE_CONSUMER_PROCUREMENT_V1_INTERNAL_CONSUMER_PROCUREMENT_AUTH_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_COMMERCE_CONSUMER_PROCUREMENT_V1_INTERNAL_CONSUMER_PROCUREMENT_AUTH_DECORATOR_H

#include "google/cloud/commerce/consumer/procurement/v1/internal/consumer_procurement_stub.h"
#include "google/cloud/internal/unified_grpc_credentials.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>
#include <set>
#include <string>

namespace google {
namespace cloud {
namespace commerce_consumer_procurement_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class ConsumerProcurementServiceAuth : public ConsumerProcurementServiceStub {
 public:
  ~ConsumerProcurementServiceAuth() override = default;
  ConsumerProcurementServiceAuth(
      std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
      std::shared_ptr<ConsumerProcurementServiceStub> child);

  future<StatusOr<google::longrunning::Operation>> AsyncPlaceOrder(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::commerce::consumer::procurement::v1::
          PlaceOrderRequest const& request) override;

  StatusOr<google::cloud::commerce::consumer::procurement::v1::Order> GetOrder(
      grpc::ClientContext& context,
      google::cloud::commerce::consumer::procurement::v1::GetOrderRequest const&
          request) override;

  StatusOr<
      google::cloud::commerce::consumer::procurement::v1::ListOrdersResponse>
  ListOrders(grpc::ClientContext& context,
             google::cloud::commerce::consumer::procurement::v1::
                 ListOrdersRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth_;
  std::shared_ptr<ConsumerProcurementServiceStub> child_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace commerce_consumer_procurement_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_COMMERCE_CONSUMER_PROCUREMENT_V1_INTERNAL_CONSUMER_PROCUREMENT_AUTH_DECORATOR_H
