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
// source: google/cloud/resourcemanager/v3/tag_holds.proto

#include "google/cloud/resourcemanager/v3/internal/tag_holds_connection_impl.h"
#include "google/cloud/resourcemanager/v3/internal/tag_holds_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/async_long_running_operation.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace resourcemanager_v3_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

TagHoldsConnectionImpl::TagHoldsConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<resourcemanager_v3_internal::TagHoldsStub> stub,
    Options options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      options_(internal::MergeOptions(std::move(options),
                                      TagHoldsConnection::options())) {}

future<StatusOr<google::cloud::resourcemanager::v3::TagHold>>
TagHoldsConnectionImpl::CreateTagHold(
    google::cloud::resourcemanager::v3::CreateTagHoldRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::resourcemanager::v3::TagHold>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::resourcemanager::v3::CreateTagHoldRequest const&
                 request) {
        return stub->AsyncCreateTagHold(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::resourcemanager::v3::TagHold>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateTagHold(request), polling_policy(), __func__);
}

future<StatusOr<google::cloud::resourcemanager::v3::DeleteTagHoldMetadata>>
TagHoldsConnectionImpl::DeleteTagHold(
    google::cloud::resourcemanager::v3::DeleteTagHoldRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::resourcemanager::v3::DeleteTagHoldMetadata>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::resourcemanager::v3::DeleteTagHoldRequest const&
                 request) {
        return stub->AsyncDeleteTagHold(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultMetadata<
          google::cloud::resourcemanager::v3::DeleteTagHoldMetadata>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteTagHold(request), polling_policy(), __func__);
}

StreamRange<google::cloud::resourcemanager::v3::TagHold>
TagHoldsConnectionImpl::ListTagHolds(
    google::cloud::resourcemanager::v3::ListTagHoldsRequest request) {
  request.clear_page_token();
  auto& stub = stub_;
  auto retry = std::shared_ptr<resourcemanager_v3::TagHoldsRetryPolicy const>(
      retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListTagHolds(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::resourcemanager::v3::TagHold>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::cloud::resourcemanager::v3::ListTagHoldsRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](
                grpc::ClientContext& context,
                google::cloud::resourcemanager::v3::ListTagHoldsRequest const&
                    request) { return stub->ListTagHolds(context, request); },
            r, function_name);
      },
      [](google::cloud::resourcemanager::v3::ListTagHoldsResponse r) {
        std::vector<google::cloud::resourcemanager::v3::TagHold> result(
            r.tag_holds().size());
        auto& messages = *r.mutable_tag_holds();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace resourcemanager_v3_internal
}  // namespace cloud
}  // namespace google
