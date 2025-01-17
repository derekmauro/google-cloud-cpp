// Copyright 2022 Google LLC
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
// source: google/cloud/dataproc/v1/batches.proto

#include "google/cloud/dataproc/v1/internal/batch_controller_tracing_connection.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/internal/traced_stream_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace dataproc_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

BatchControllerTracingConnection::BatchControllerTracingConnection(
    std::shared_ptr<dataproc_v1::BatchControllerConnection> child)
    : child_(std::move(child)) {}

future<StatusOr<google::cloud::dataproc::v1::Batch>>
BatchControllerTracingConnection::CreateBatch(
    google::cloud::dataproc::v1::CreateBatchRequest const& request) {
  auto span =
      internal::MakeSpan("dataproc_v1::BatchControllerConnection::CreateBatch");
  internal::OTelScope scope(span);
  return internal::EndSpan(std::move(span), child_->CreateBatch(request));
}

StatusOr<google::cloud::dataproc::v1::Batch>
BatchControllerTracingConnection::GetBatch(
    google::cloud::dataproc::v1::GetBatchRequest const& request) {
  auto span =
      internal::MakeSpan("dataproc_v1::BatchControllerConnection::GetBatch");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetBatch(request));
}

StreamRange<google::cloud::dataproc::v1::Batch>
BatchControllerTracingConnection::ListBatches(
    google::cloud::dataproc::v1::ListBatchesRequest request) {
  auto span =
      internal::MakeSpan("dataproc_v1::BatchControllerConnection::ListBatches");
  internal::OTelScope scope(span);
  auto sr = child_->ListBatches(std::move(request));
  return internal::MakeTracedStreamRange<google::cloud::dataproc::v1::Batch>(
      std::move(span), std::move(sr));
}

Status BatchControllerTracingConnection::DeleteBatch(
    google::cloud::dataproc::v1::DeleteBatchRequest const& request) {
  auto span =
      internal::MakeSpan("dataproc_v1::BatchControllerConnection::DeleteBatch");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->DeleteBatch(request));
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<dataproc_v1::BatchControllerConnection>
MakeBatchControllerTracingConnection(
    std::shared_ptr<dataproc_v1::BatchControllerConnection> conn) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  if (internal::TracingEnabled(conn->options())) {
    conn = std::make_shared<BatchControllerTracingConnection>(std::move(conn));
  }
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return conn;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dataproc_v1_internal
}  // namespace cloud
}  // namespace google
