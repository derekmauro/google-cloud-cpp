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
// source: google/cloud/memcache/v1/cloud_memcache.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_MEMCACHE_V1_CLOUD_MEMCACHE_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_MEMCACHE_V1_CLOUD_MEMCACHE_CLIENT_H

#include "google/cloud/memcache/v1/cloud_memcache_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <map>
#include <memory>

namespace google {
namespace cloud {
namespace memcache_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// Configures and manages Cloud Memorystore for Memcached instances.
///
///
/// The `memcache.googleapis.com` service implements the Google Cloud
/// Memorystore for Memcached API and defines the following resource model for
/// managing Memorystore Memcached (also called Memcached below) instances:
/// * The service works with a collection of cloud projects, named:
/// `/projects/*`
/// * Each project has a collection of available locations, named:
/// `/locations/*`
/// * Each location has a collection of Memcached instances, named:
/// `/instances/*`
/// * As such, Memcached instances are resources of the form:
///   `/projects/{project_id}/locations/{location_id}/instances/{instance_id}`
///
/// Note that location_id must be a GCP `region`; for example:
/// * `projects/my-memcached-project/locations/us-central1/instances/my-memcached`
///
/// @par Equality
///
/// Instances of this class created via copy-construction or copy-assignment
/// always compare equal. Instances created with equal
/// `std::shared_ptr<*Connection>` objects compare equal. Objects that compare
/// equal share the same underlying resources.
///
/// @par Performance
///
/// Creating a new instance of this class is a relatively expensive operation,
/// new objects establish new connections to the service. In contrast,
/// copy-construction, move-construction, and the corresponding assignment
/// operations are relatively efficient as the copies share all underlying
/// resources.
///
/// @par Thread Safety
///
/// Concurrent access to different instances of this class, even if they compare
/// equal, is guaranteed to work. Two or more threads operating on the same
/// instance of this class is not guaranteed to work. Since copy-construction
/// and move-construction is a relatively efficient operation, consider using
/// such a copy when using this class from multiple threads.
///
class CloudMemcacheClient {
 public:
  explicit CloudMemcacheClient(
      std::shared_ptr<CloudMemcacheConnection> connection, Options opts = {});
  ~CloudMemcacheClient();

  ///@{
  /// @name Copy and move support
  CloudMemcacheClient(CloudMemcacheClient const&) = default;
  CloudMemcacheClient& operator=(CloudMemcacheClient const&) = default;
  CloudMemcacheClient(CloudMemcacheClient&&) = default;
  CloudMemcacheClient& operator=(CloudMemcacheClient&&) = default;
  ///@}

  ///@{
  /// @name Equality
  friend bool operator==(CloudMemcacheClient const& a,
                         CloudMemcacheClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(CloudMemcacheClient const& a,
                         CloudMemcacheClient const& b) {
    return !(a == b);
  }
  ///@}

  ///
  /// Lists Instances in a given location.
  ///
  /// @param parent  Required. The resource name of the instance location using
  /// the form:
  ///      `projects/{project_id}/locations/{location_id}`
  ///  where `location_id` refers to a GCP region
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::memcache::v1::Instance,google/cloud/memcache/v1/cloud_memcache.proto#L153}
  ///
  /// [google.cloud.memcache.v1.Instance]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L153}
  /// [google.cloud.memcache.v1.ListInstancesRequest]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L409}
  ///
  StreamRange<google::cloud::memcache::v1::Instance> ListInstances(
      std::string const& parent, Options opts = {});

  ///
  /// Lists Instances in a given location.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::memcache::v1::ListInstancesRequest,google/cloud/memcache/v1/cloud_memcache.proto#L409}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::memcache::v1::Instance,google/cloud/memcache/v1/cloud_memcache.proto#L153}
  ///
  /// [google.cloud.memcache.v1.Instance]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L153}
  /// [google.cloud.memcache.v1.ListInstancesRequest]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L409}
  ///
  StreamRange<google::cloud::memcache::v1::Instance> ListInstances(
      google::cloud::memcache::v1::ListInstancesRequest request,
      Options opts = {});

  ///
  /// Gets details of a single Instance.
  ///
  /// @param name  Required. Memcached instance resource name in the format:
  ///      `projects/{project_id}/locations/{location_id}/instances/{instance_id}`
  ///  where `location_id` refers to a GCP region
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::memcache::v1::Instance,google/cloud/memcache/v1/cloud_memcache.proto#L153}
  ///
  /// [google.cloud.memcache.v1.GetInstanceRequest]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L458}
  /// [google.cloud.memcache.v1.Instance]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L153}
  ///
  StatusOr<google::cloud::memcache::v1::Instance> GetInstance(
      std::string const& name, Options opts = {});

  ///
  /// Gets details of a single Instance.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::memcache::v1::GetInstanceRequest,google/cloud/memcache/v1/cloud_memcache.proto#L458}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::memcache::v1::Instance,google/cloud/memcache/v1/cloud_memcache.proto#L153}
  ///
  /// [google.cloud.memcache.v1.GetInstanceRequest]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L458}
  /// [google.cloud.memcache.v1.Instance]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L153}
  ///
  StatusOr<google::cloud::memcache::v1::Instance> GetInstance(
      google::cloud::memcache::v1::GetInstanceRequest const& request,
      Options opts = {});

  ///
  /// Creates a new Instance in a given location.
  ///
  /// @param parent  Required. The resource name of the instance location using
  /// the form:
  ///      `projects/{project_id}/locations/{location_id}`
  ///  where `location_id` refers to a GCP region
  /// @param instance  Required. A Memcached Instance
  /// @param instance_id  Required. The logical name of the Memcached instance
  /// in the user
  ///  project with the following restrictions:
  ///  * Must contain only lowercase letters, numbers, and hyphens.
  ///  * Must start with a letter.
  ///  * Must be between 1-40 characters.
  ///  * Must end with a number or a letter.
  ///  * Must be unique within the user project / location.
  ///  If any of the above are not met, the API raises an invalid argument
  ///  error.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::memcache::v1::Instance,google/cloud/memcache/v1/cloud_memcache.proto#L153}
  ///
  /// [google.cloud.memcache.v1.CreateInstanceRequest]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L471}
  /// [google.cloud.memcache.v1.Instance]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L153}
  ///
  future<StatusOr<google::cloud::memcache::v1::Instance>> CreateInstance(
      std::string const& parent,
      google::cloud::memcache::v1::Instance const& instance,
      std::string const& instance_id, Options opts = {});

  ///
  /// Creates a new Instance in a given location.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::memcache::v1::CreateInstanceRequest,google/cloud/memcache/v1/cloud_memcache.proto#L471}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::memcache::v1::Instance,google/cloud/memcache/v1/cloud_memcache.proto#L153}
  ///
  /// [google.cloud.memcache.v1.CreateInstanceRequest]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L471}
  /// [google.cloud.memcache.v1.Instance]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L153}
  ///
  future<StatusOr<google::cloud::memcache::v1::Instance>> CreateInstance(
      google::cloud::memcache::v1::CreateInstanceRequest const& request,
      Options opts = {});

  ///
  /// Updates an existing Instance in a given project and location.
  ///
  /// @param instance  Required. A Memcached Instance.
  ///  Only fields specified in update_mask are updated.
  /// @param update_mask  Required. Mask of fields to update.
  ///   *   `displayName`
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::memcache::v1::Instance,google/cloud/memcache/v1/cloud_memcache.proto#L153}
  ///
  /// [google.cloud.memcache.v1.Instance]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L153}
  /// [google.cloud.memcache.v1.UpdateInstanceRequest]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L499}
  ///
  future<StatusOr<google::cloud::memcache::v1::Instance>> UpdateInstance(
      google::cloud::memcache::v1::Instance const& instance,
      google::protobuf::FieldMask const& update_mask, Options opts = {});

  ///
  /// Updates an existing Instance in a given project and location.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::memcache::v1::UpdateInstanceRequest,google/cloud/memcache/v1/cloud_memcache.proto#L499}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::memcache::v1::Instance,google/cloud/memcache/v1/cloud_memcache.proto#L153}
  ///
  /// [google.cloud.memcache.v1.Instance]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L153}
  /// [google.cloud.memcache.v1.UpdateInstanceRequest]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L499}
  ///
  future<StatusOr<google::cloud::memcache::v1::Instance>> UpdateInstance(
      google::cloud::memcache::v1::UpdateInstanceRequest const& request,
      Options opts = {});

  ///
  /// Updates the defined Memcached parameters for an existing instance.
  /// This method only stages the parameters, it must be followed by
  /// `ApplyParameters` to apply the parameters to nodes of the Memcached
  /// instance.
  ///
  /// @param name  Required. Resource name of the Memcached instance for which
  /// the parameters should be
  ///  updated.
  /// @param update_mask  Required. Mask of fields to update.
  /// @param parameters  The parameters to apply to the instance.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::memcache::v1::Instance,google/cloud/memcache/v1/cloud_memcache.proto#L153}
  ///
  /// [google.cloud.memcache.v1.Instance]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L153}
  /// [google.cloud.memcache.v1.UpdateParametersRequest]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L544}
  ///
  future<StatusOr<google::cloud::memcache::v1::Instance>> UpdateParameters(
      std::string const& name, google::protobuf::FieldMask const& update_mask,
      google::cloud::memcache::v1::MemcacheParameters const& parameters,
      Options opts = {});

  ///
  /// Updates the defined Memcached parameters for an existing instance.
  /// This method only stages the parameters, it must be followed by
  /// `ApplyParameters` to apply the parameters to nodes of the Memcached
  /// instance.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::memcache::v1::UpdateParametersRequest,google/cloud/memcache/v1/cloud_memcache.proto#L544}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::memcache::v1::Instance,google/cloud/memcache/v1/cloud_memcache.proto#L153}
  ///
  /// [google.cloud.memcache.v1.Instance]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L153}
  /// [google.cloud.memcache.v1.UpdateParametersRequest]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L544}
  ///
  future<StatusOr<google::cloud::memcache::v1::Instance>> UpdateParameters(
      google::cloud::memcache::v1::UpdateParametersRequest const& request,
      Options opts = {});

  ///
  /// Deletes a single Instance.
  ///
  /// @param name  Required. Memcached instance resource name in the format:
  ///      `projects/{project_id}/locations/{location_id}/instances/{instance_id}`
  ///  where `location_id` refers to a GCP region
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::memcache::v1::OperationMetadata,google/cloud/memcache/v1/cloud_memcache.proto#L582}
  ///
  /// [google.cloud.memcache.v1.DeleteInstanceRequest]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L511}
  /// [google.cloud.memcache.v1.OperationMetadata]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L582}
  ///
  future<StatusOr<google::cloud::memcache::v1::OperationMetadata>>
  DeleteInstance(std::string const& name, Options opts = {});

  ///
  /// Deletes a single Instance.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::memcache::v1::DeleteInstanceRequest,google/cloud/memcache/v1/cloud_memcache.proto#L511}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::memcache::v1::OperationMetadata,google/cloud/memcache/v1/cloud_memcache.proto#L582}
  ///
  /// [google.cloud.memcache.v1.DeleteInstanceRequest]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L511}
  /// [google.cloud.memcache.v1.OperationMetadata]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L582}
  ///
  future<StatusOr<google::cloud::memcache::v1::OperationMetadata>>
  DeleteInstance(
      google::cloud::memcache::v1::DeleteInstanceRequest const& request,
      Options opts = {});

  ///
  /// `ApplyParameters` restarts the set of specified nodes in order to update
  /// them to the current set of parameters for the Memcached Instance.
  ///
  /// @param name  Required. Resource name of the Memcached instance for which
  /// parameter group updates
  ///  should be applied.
  /// @param node_ids  Nodes to which the instance-level parameter group is
  /// applied.
  /// @param apply_all  Whether to apply instance-level parameter group to all
  /// nodes. If set to
  ///  true, users are restricted from specifying individual nodes, and
  ///  `ApplyParameters` updates all nodes within the instance.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::memcache::v1::Instance,google/cloud/memcache/v1/cloud_memcache.proto#L153}
  ///
  /// [google.cloud.memcache.v1.ApplyParametersRequest]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L524}
  /// [google.cloud.memcache.v1.Instance]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L153}
  ///
  future<StatusOr<google::cloud::memcache::v1::Instance>> ApplyParameters(
      std::string const& name, std::vector<std::string> const& node_ids,
      bool apply_all, Options opts = {});

  ///
  /// `ApplyParameters` restarts the set of specified nodes in order to update
  /// them to the current set of parameters for the Memcached Instance.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::memcache::v1::ApplyParametersRequest,google/cloud/memcache/v1/cloud_memcache.proto#L524}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::memcache::v1::Instance,google/cloud/memcache/v1/cloud_memcache.proto#L153}
  ///
  /// [google.cloud.memcache.v1.ApplyParametersRequest]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L524}
  /// [google.cloud.memcache.v1.Instance]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L153}
  ///
  future<StatusOr<google::cloud::memcache::v1::Instance>> ApplyParameters(
      google::cloud::memcache::v1::ApplyParametersRequest const& request,
      Options opts = {});

  ///
  /// Reschedules upcoming maintenance event.
  ///
  /// @param instance  Required. Memcache instance resource name using the form:
  ///      `projects/{project_id}/locations/{location_id}/instances/{instance_id}`
  ///  where `location_id` refers to a GCP region.
  /// @param reschedule_type  Required. If reschedule type is SPECIFIC_TIME,
  /// must set up schedule_time as well.
  /// @param schedule_time  Timestamp when the maintenance shall be rescheduled
  /// to if
  ///  reschedule_type=SPECIFIC_TIME, in RFC 3339 format, for
  ///  example `2012-11-15T16:19:00.094Z`.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::memcache::v1::Instance,google/cloud/memcache/v1/cloud_memcache.proto#L153}
  ///
  /// [google.cloud.memcache.v1.Instance]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L153}
  /// [google.cloud.memcache.v1.RescheduleMaintenanceRequest]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L372}
  ///
  future<StatusOr<google::cloud::memcache::v1::Instance>> RescheduleMaintenance(
      std::string const& instance,
      google::cloud::memcache::v1::RescheduleMaintenanceRequest::RescheduleType
          reschedule_type,
      google::protobuf::Timestamp const& schedule_time, Options opts = {});

  ///
  /// Reschedules upcoming maintenance event.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::memcache::v1::RescheduleMaintenanceRequest,google/cloud/memcache/v1/cloud_memcache.proto#L372}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::memcache::v1::Instance,google/cloud/memcache/v1/cloud_memcache.proto#L153}
  ///
  /// [google.cloud.memcache.v1.Instance]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L153}
  /// [google.cloud.memcache.v1.RescheduleMaintenanceRequest]:
  /// @googleapis_reference_link{google/cloud/memcache/v1/cloud_memcache.proto#L372}
  ///
  future<StatusOr<google::cloud::memcache::v1::Instance>> RescheduleMaintenance(
      google::cloud::memcache::v1::RescheduleMaintenanceRequest const& request,
      Options opts = {});

 private:
  std::shared_ptr<CloudMemcacheConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace memcache_v1
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_MEMCACHE_V1_CLOUD_MEMCACHE_CLIENT_H
