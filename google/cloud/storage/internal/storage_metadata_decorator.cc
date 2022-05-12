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
// source: google/storage/v2/storage.proto

#include "google/cloud/storage/internal/storage_metadata_decorator.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/status_or.h"
#include <google/storage/v2/storage.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace storage_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

StorageMetadata::StorageMetadata(std::shared_ptr<StorageStub> child)
    : child_(std::move(child)),
      api_client_header_(
          google::cloud::internal::ApiClientHeader("generator")) {}

Status StorageMetadata::DeleteBucket(
    grpc::ClientContext& context,
    google::storage::v2::DeleteBucketRequest const& request) {
  SetMetadata(context, {});
  return child_->DeleteBucket(context, request);
}

StatusOr<google::storage::v2::Bucket> StorageMetadata::GetBucket(
    grpc::ClientContext& context,
    google::storage::v2::GetBucketRequest const& request) {
  SetMetadata(context, {});
  return child_->GetBucket(context, request);
}

StatusOr<google::storage::v2::Bucket> StorageMetadata::CreateBucket(
    grpc::ClientContext& context,
    google::storage::v2::CreateBucketRequest const& request) {
  SetMetadata(context, {});
  return child_->CreateBucket(context, request);
}

StatusOr<google::storage::v2::ListBucketsResponse> StorageMetadata::ListBuckets(
    grpc::ClientContext& context,
    google::storage::v2::ListBucketsRequest const& request) {
  SetMetadata(context, {});
  return child_->ListBuckets(context, request);
}

StatusOr<google::storage::v2::Bucket>
StorageMetadata::LockBucketRetentionPolicy(
    grpc::ClientContext& context,
    google::storage::v2::LockBucketRetentionPolicyRequest const& request) {
  SetMetadata(context, {});
  return child_->LockBucketRetentionPolicy(context, request);
}

StatusOr<google::iam::v1::Policy> StorageMetadata::GetIamPolicy(
    grpc::ClientContext& context,
    google::iam::v1::GetIamPolicyRequest const& request) {
  SetMetadata(context, {});
  return child_->GetIamPolicy(context, request);
}

StatusOr<google::iam::v1::Policy> StorageMetadata::SetIamPolicy(
    grpc::ClientContext& context,
    google::iam::v1::SetIamPolicyRequest const& request) {
  SetMetadata(context, {});
  return child_->SetIamPolicy(context, request);
}

StatusOr<google::iam::v1::TestIamPermissionsResponse>
StorageMetadata::TestIamPermissions(
    grpc::ClientContext& context,
    google::iam::v1::TestIamPermissionsRequest const& request) {
  SetMetadata(context, {});
  return child_->TestIamPermissions(context, request);
}

StatusOr<google::storage::v2::Bucket> StorageMetadata::UpdateBucket(
    grpc::ClientContext& context,
    google::storage::v2::UpdateBucketRequest const& request) {
  SetMetadata(context, {});
  return child_->UpdateBucket(context, request);
}

StatusOr<google::storage::v2::Object> StorageMetadata::ComposeObject(
    grpc::ClientContext& context,
    google::storage::v2::ComposeObjectRequest const& request) {
  SetMetadata(context, {});
  return child_->ComposeObject(context, request);
}

Status StorageMetadata::DeleteObject(
    grpc::ClientContext& context,
    google::storage::v2::DeleteObjectRequest const& request) {
  SetMetadata(context, {});
  return child_->DeleteObject(context, request);
}

StatusOr<google::storage::v2::Object> StorageMetadata::GetObject(
    grpc::ClientContext& context,
    google::storage::v2::GetObjectRequest const& request) {
  SetMetadata(context, {});
  return child_->GetObject(context, request);
}

std::unique_ptr<google::cloud::internal::StreamingReadRpc<
    google::storage::v2::ReadObjectResponse>>
StorageMetadata::ReadObject(
    std::unique_ptr<grpc::ClientContext> context,
    google::storage::v2::ReadObjectRequest const& request) {
  SetMetadata(*context, {});
  return child_->ReadObject(std::move(context), request);
}

StatusOr<google::storage::v2::Object> StorageMetadata::UpdateObject(
    grpc::ClientContext& context,
    google::storage::v2::UpdateObjectRequest const& request) {
  SetMetadata(context, {});
  return child_->UpdateObject(context, request);
}

std::unique_ptr<::google::cloud::internal::StreamingWriteRpc<
    google::storage::v2::WriteObjectRequest,
    google::storage::v2::WriteObjectResponse>>
StorageMetadata::WriteObject(std::unique_ptr<grpc::ClientContext> context) {
  SetMetadata(*context);
  return child_->WriteObject(std::move(context));
}

StatusOr<google::storage::v2::ListObjectsResponse> StorageMetadata::ListObjects(
    grpc::ClientContext& context,
    google::storage::v2::ListObjectsRequest const& request) {
  SetMetadata(context, {});
  return child_->ListObjects(context, request);
}

StatusOr<google::storage::v2::RewriteResponse> StorageMetadata::RewriteObject(
    grpc::ClientContext& context,
    google::storage::v2::RewriteObjectRequest const& request) {
  SetMetadata(context, {});
  return child_->RewriteObject(context, request);
}

StatusOr<google::storage::v2::StartResumableWriteResponse>
StorageMetadata::StartResumableWrite(
    grpc::ClientContext& context,
    google::storage::v2::StartResumableWriteRequest const& request) {
  SetMetadata(context, {});
  return child_->StartResumableWrite(context, request);
}

StatusOr<google::storage::v2::QueryWriteStatusResponse>
StorageMetadata::QueryWriteStatus(
    grpc::ClientContext& context,
    google::storage::v2::QueryWriteStatusRequest const& request) {
  SetMetadata(context, {});
  return child_->QueryWriteStatus(context, request);
}

StatusOr<google::storage::v2::ServiceAccount>
StorageMetadata::GetServiceAccount(
    grpc::ClientContext& context,
    google::storage::v2::GetServiceAccountRequest const& request) {
  SetMetadata(context, {});
  return child_->GetServiceAccount(context, request);
}

Status StorageMetadata::DeleteHmacKey(
    grpc::ClientContext& context,
    google::storage::v2::DeleteHmacKeyRequest const& request) {
  SetMetadata(context, {});
  return child_->DeleteHmacKey(context, request);
}

StatusOr<google::storage::v2::HmacKeyMetadata> StorageMetadata::GetHmacKey(
    grpc::ClientContext& context,
    google::storage::v2::GetHmacKeyRequest const& request) {
  SetMetadata(context, {});
  return child_->GetHmacKey(context, request);
}

StatusOr<google::storage::v2::HmacKeyMetadata> StorageMetadata::UpdateHmacKey(
    grpc::ClientContext& context,
    google::storage::v2::UpdateHmacKeyRequest const& request) {
  SetMetadata(context, {});
  return child_->UpdateHmacKey(context, request);
}

void StorageMetadata::SetMetadata(grpc::ClientContext& context,
                                  std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context);
}

void StorageMetadata::SetMetadata(grpc::ClientContext& context) {
  context.AddMetadata("x-goog-api-client", api_client_header_);
  auto const& options = internal::CurrentOptions();
  if (options.has<UserProjectOption>()) {
    context.AddMetadata("x-goog-user-project",
                        options.get<UserProjectOption>());
  }
  auto const& authority = options.get<AuthorityOption>();
  if (!authority.empty()) context.set_authority(authority);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace storage_internal
}  // namespace cloud
}  // namespace google
