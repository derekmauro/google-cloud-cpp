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
// source: google/cloud/metastore/v1/metastore_federation.proto

#include "google/cloud/metastore/v1/dataproc_metastore_federation_connection.h"
#include "google/cloud/metastore/v1/dataproc_metastore_federation_options.h"
#include "google/cloud/metastore/v1/internal/dataproc_metastore_federation_connection_impl.h"
#include "google/cloud/metastore/v1/internal/dataproc_metastore_federation_option_defaults.h"
#include "google/cloud/metastore/v1/internal/dataproc_metastore_federation_stub_factory.h"
#include "google/cloud/metastore/v1/internal/dataproc_metastore_federation_tracing_connection.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/credentials.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/unified_grpc_credentials.h"
#include <memory>

namespace google {
namespace cloud {
namespace metastore_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

DataprocMetastoreFederationConnection::
    ~DataprocMetastoreFederationConnection() = default;

StreamRange<google::cloud::metastore::v1::Federation>
DataprocMetastoreFederationConnection::ListFederations(
    google::cloud::metastore::v1::
        ListFederationsRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::cloud::metastore::v1::Federation>>();
}

StatusOr<google::cloud::metastore::v1::Federation>
DataprocMetastoreFederationConnection::GetFederation(
    google::cloud::metastore::v1::GetFederationRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

future<StatusOr<google::cloud::metastore::v1::Federation>>
DataprocMetastoreFederationConnection::CreateFederation(
    google::cloud::metastore::v1::CreateFederationRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::metastore::v1::Federation>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::metastore::v1::Federation>>
DataprocMetastoreFederationConnection::UpdateFederation(
    google::cloud::metastore::v1::UpdateFederationRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::metastore::v1::Federation>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::metastore::v1::OperationMetadata>>
DataprocMetastoreFederationConnection::DeleteFederation(
    google::cloud::metastore::v1::DeleteFederationRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::metastore::v1::OperationMetadata>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

std::shared_ptr<DataprocMetastoreFederationConnection>
MakeDataprocMetastoreFederationConnection(Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 UnifiedCredentialsOptionList,
                                 DataprocMetastoreFederationPolicyOptionList>(
      options, __func__);
  options = metastore_v1_internal::DataprocMetastoreFederationDefaultOptions(
      std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto auth = internal::CreateAuthenticationStrategy(background->cq(), options);
  auto stub =
      metastore_v1_internal::CreateDefaultDataprocMetastoreFederationStub(
          std::move(auth), options);
  return metastore_v1_internal::
      MakeDataprocMetastoreFederationTracingConnection(
          std::make_shared<
              metastore_v1_internal::DataprocMetastoreFederationConnectionImpl>(
              std::move(background), std::move(stub), std::move(options)));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace metastore_v1
}  // namespace cloud
}  // namespace google
