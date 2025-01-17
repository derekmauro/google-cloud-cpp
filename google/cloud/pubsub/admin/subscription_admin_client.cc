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
// source: google/pubsub/v1/pubsub.proto

#include "google/cloud/pubsub/admin/subscription_admin_client.h"
#include <memory>

namespace google {
namespace cloud {
namespace pubsub_admin {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

SubscriptionAdminClient::SubscriptionAdminClient(
    std::shared_ptr<SubscriptionAdminConnection> connection, Options opts)
    : connection_(std::move(connection)),
      options_(
          internal::MergeOptions(std::move(opts), connection_->options())) {}
SubscriptionAdminClient::~SubscriptionAdminClient() = default;

StatusOr<google::pubsub::v1::Subscription>
SubscriptionAdminClient::CreateSubscription(
    std::string const& name, std::string const& topic,
    google::pubsub::v1::PushConfig const& push_config,
    std::int32_t ack_deadline_seconds, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::pubsub::v1::Subscription request;
  request.set_name(name);
  request.set_topic(topic);
  *request.mutable_push_config() = push_config;
  request.set_ack_deadline_seconds(ack_deadline_seconds);
  return connection_->CreateSubscription(request);
}

StatusOr<google::pubsub::v1::Subscription>
SubscriptionAdminClient::CreateSubscription(
    google::pubsub::v1::Subscription const& request, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->CreateSubscription(request);
}

StatusOr<google::pubsub::v1::Subscription>
SubscriptionAdminClient::GetSubscription(std::string const& subscription,
                                         Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::pubsub::v1::GetSubscriptionRequest request;
  request.set_subscription(subscription);
  return connection_->GetSubscription(request);
}

StatusOr<google::pubsub::v1::Subscription>
SubscriptionAdminClient::GetSubscription(
    google::pubsub::v1::GetSubscriptionRequest const& request, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->GetSubscription(request);
}

StatusOr<google::pubsub::v1::Subscription>
SubscriptionAdminClient::UpdateSubscription(
    google::pubsub::v1::Subscription const& subscription,
    google::protobuf::FieldMask const& update_mask, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::pubsub::v1::UpdateSubscriptionRequest request;
  *request.mutable_subscription() = subscription;
  *request.mutable_update_mask() = update_mask;
  return connection_->UpdateSubscription(request);
}

StatusOr<google::pubsub::v1::Subscription>
SubscriptionAdminClient::UpdateSubscription(
    google::pubsub::v1::UpdateSubscriptionRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->UpdateSubscription(request);
}

StreamRange<google::pubsub::v1::Subscription>
SubscriptionAdminClient::ListSubscriptions(std::string const& project,
                                           Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::pubsub::v1::ListSubscriptionsRequest request;
  request.set_project(project);
  return connection_->ListSubscriptions(request);
}

StreamRange<google::pubsub::v1::Subscription>
SubscriptionAdminClient::ListSubscriptions(
    google::pubsub::v1::ListSubscriptionsRequest request, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->ListSubscriptions(std::move(request));
}

Status SubscriptionAdminClient::DeleteSubscription(
    std::string const& subscription, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::pubsub::v1::DeleteSubscriptionRequest request;
  request.set_subscription(subscription);
  return connection_->DeleteSubscription(request);
}

Status SubscriptionAdminClient::DeleteSubscription(
    google::pubsub::v1::DeleteSubscriptionRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->DeleteSubscription(request);
}

Status SubscriptionAdminClient::ModifyPushConfig(
    std::string const& subscription,
    google::pubsub::v1::PushConfig const& push_config, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::pubsub::v1::ModifyPushConfigRequest request;
  request.set_subscription(subscription);
  *request.mutable_push_config() = push_config;
  return connection_->ModifyPushConfig(request);
}

Status SubscriptionAdminClient::ModifyPushConfig(
    google::pubsub::v1::ModifyPushConfigRequest const& request, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->ModifyPushConfig(request);
}

StatusOr<google::pubsub::v1::Snapshot> SubscriptionAdminClient::GetSnapshot(
    std::string const& snapshot, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::pubsub::v1::GetSnapshotRequest request;
  request.set_snapshot(snapshot);
  return connection_->GetSnapshot(request);
}

StatusOr<google::pubsub::v1::Snapshot> SubscriptionAdminClient::GetSnapshot(
    google::pubsub::v1::GetSnapshotRequest const& request, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->GetSnapshot(request);
}

StreamRange<google::pubsub::v1::Snapshot>
SubscriptionAdminClient::ListSnapshots(std::string const& project,
                                       Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::pubsub::v1::ListSnapshotsRequest request;
  request.set_project(project);
  return connection_->ListSnapshots(request);
}

StreamRange<google::pubsub::v1::Snapshot>
SubscriptionAdminClient::ListSnapshots(
    google::pubsub::v1::ListSnapshotsRequest request, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->ListSnapshots(std::move(request));
}

StatusOr<google::pubsub::v1::Snapshot> SubscriptionAdminClient::CreateSnapshot(
    std::string const& name, std::string const& subscription, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::pubsub::v1::CreateSnapshotRequest request;
  request.set_name(name);
  request.set_subscription(subscription);
  return connection_->CreateSnapshot(request);
}

StatusOr<google::pubsub::v1::Snapshot> SubscriptionAdminClient::CreateSnapshot(
    google::pubsub::v1::CreateSnapshotRequest const& request, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->CreateSnapshot(request);
}

StatusOr<google::pubsub::v1::Snapshot> SubscriptionAdminClient::UpdateSnapshot(
    google::pubsub::v1::Snapshot const& snapshot,
    google::protobuf::FieldMask const& update_mask, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::pubsub::v1::UpdateSnapshotRequest request;
  *request.mutable_snapshot() = snapshot;
  *request.mutable_update_mask() = update_mask;
  return connection_->UpdateSnapshot(request);
}

StatusOr<google::pubsub::v1::Snapshot> SubscriptionAdminClient::UpdateSnapshot(
    google::pubsub::v1::UpdateSnapshotRequest const& request, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->UpdateSnapshot(request);
}

Status SubscriptionAdminClient::DeleteSnapshot(std::string const& snapshot,
                                               Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::pubsub::v1::DeleteSnapshotRequest request;
  request.set_snapshot(snapshot);
  return connection_->DeleteSnapshot(request);
}

Status SubscriptionAdminClient::DeleteSnapshot(
    google::pubsub::v1::DeleteSnapshotRequest const& request, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->DeleteSnapshot(request);
}

StatusOr<google::pubsub::v1::SeekResponse> SubscriptionAdminClient::Seek(
    google::pubsub::v1::SeekRequest const& request, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->Seek(request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub_admin
}  // namespace cloud
}  // namespace google
