// Copyright 2021 Google LLC
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
// source: google/spanner/admin/database/v1/spanner_database_admin.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SPANNER_ADMIN_DATABASE_ADMIN_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SPANNER_ADMIN_DATABASE_ADMIN_CLIENT_H

#include "google/cloud/spanner/admin/database_admin_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/iam_updater.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace spanner_admin {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

/**
 * Cloud Spanner Database Admin API
 *
 * The Cloud Spanner Database Admin API can be used to create, drop, and
 * list databases. It also enables updating the schema of pre-existing
 * databases. It can be also used to create, delete and list backups for a
 * database and to restore from an existing backup.
 */
class DatabaseAdminClient {
 public:
  explicit DatabaseAdminClient(
      std::shared_ptr<DatabaseAdminConnection> connection);
  ~DatabaseAdminClient();

  //@{
  // @name Copy and move support
  DatabaseAdminClient(DatabaseAdminClient const&) = default;
  DatabaseAdminClient& operator=(DatabaseAdminClient const&) = default;
  DatabaseAdminClient(DatabaseAdminClient&&) = default;
  DatabaseAdminClient& operator=(DatabaseAdminClient&&) = default;
  //@}

  //@{
  // @name Equality
  friend bool operator==(DatabaseAdminClient const& a,
                         DatabaseAdminClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(DatabaseAdminClient const& a,
                         DatabaseAdminClient const& b) {
    return !(a == b);
  }
  //@}

  /**
   * Lists Cloud Spanner databases.
   *
   * @param parent  Required. The instance whose databases should be listed.
   *  Values are of the form `projects/<project>/instances/<instance>`.
   * @return
   * [google::spanner::admin::database::v1::Database](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/spanner_database_admin.proto#L326)
   */
  StreamRange<google::spanner::admin::database::v1::Database> ListDatabases(
      std::string const& parent);

  /**
   * Creates a new Cloud Spanner database and starts to prepare it for serving.
   * The returned [long-running operation][google.longrunning.Operation] will
   * have a name of the format `<database_name>/operations/<operation_id>` and
   * can be used to track preparation of the database. The
   * [metadata][google.longrunning.Operation.metadata] field type is
   * [CreateDatabaseMetadata][google.spanner.admin.database.v1.CreateDatabaseMetadata].
   * The [response][google.longrunning.Operation.response] field type is
   * [Database][google.spanner.admin.database.v1.Database], if successful.
   *
   * @param parent  Required. The name of the instance that will serve the new
   * database. Values are of the form `projects/<project>/instances/<instance>`.
   * @param create_statement  Required. A `CREATE DATABASE` statement, which
   * specifies the ID of the new database.  The database ID must conform to the
   * regular expression
   *  `[a-z][a-z0-9_\-]*[a-z0-9]` and be between 2 and 30 characters in length.
   *  If the database ID is a reserved word or if it contains a hyphen, the
   *  database ID must be enclosed in backticks (`` ` ``).
   * @return
   * [google::spanner::admin::database::v1::Database](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/spanner_database_admin.proto#L326)
   */
  future<StatusOr<google::spanner::admin::database::v1::Database>>
  CreateDatabase(std::string const& parent,
                 std::string const& create_statement);

  /**
   * Gets the state of a Cloud Spanner database.
   *
   * @param name  Required. The name of the requested database. Values are of
   * the form `projects/<project>/instances/<instance>/databases/<database>`.
   * @return
   * [google::spanner::admin::database::v1::Database](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/spanner_database_admin.proto#L326)
   */
  StatusOr<google::spanner::admin::database::v1::Database> GetDatabase(
      std::string const& name);

  /**
   * Updates the schema of a Cloud Spanner database by
   * creating/altering/dropping tables, columns, indexes, etc. The returned
   * [long-running operation][google.longrunning.Operation] will have a name of
   * the format `<database_name>/operations/<operation_id>` and can be used to
   * track execution of the schema change(s). The
   * [metadata][google.longrunning.Operation.metadata] field type is
   * [UpdateDatabaseDdlMetadata][google.spanner.admin.database.v1.UpdateDatabaseDdlMetadata].
   * The operation has no response.
   *
   * @param database  Required. The database to update.
   * @param statements  Required. DDL statements to be applied to the database.
   * @return
   * [google::spanner::admin::database::v1::UpdateDatabaseDdlMetadata](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/spanner_database_admin.proto#L547)
   */
  future<
      StatusOr<google::spanner::admin::database::v1::UpdateDatabaseDdlMetadata>>
  UpdateDatabaseDdl(std::string const& database,
                    std::vector<std::string> const& statements);

  /**
   * Drops (aka deletes) a Cloud Spanner database.
   * Completed backups for the database will be retained according to their
   * `expire_time`.
   *
   * @param database  Required. The database to be dropped.
   */
  Status DropDatabase(std::string const& database);

  /**
   * Returns the schema of a Cloud Spanner database as a list of formatted
   * DDL statements. This method does not show pending schema updates, those may
   * be queried using the [Operations][google.longrunning.Operations] API.
   *
   * @param database  Required. The database whose schema we wish to get.
   *  Values are of the form
   *  `projects/<project>/instances/<instance>/databases/<database>`
   * @return
   * [google::spanner::admin::database::v1::GetDatabaseDdlResponse](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/spanner_database_admin.proto#L603)
   */
  StatusOr<google::spanner::admin::database::v1::GetDatabaseDdlResponse>
  GetDatabaseDdl(std::string const& database);

  /**
   * Sets the access control policy on a database or backup resource.
   * Replaces any existing policy.
   *
   * Authorization requires `spanner.databases.setIamPolicy`
   * permission on [resource][google.iam.v1.SetIamPolicyRequest.resource].
   * For backups, authorization requires `spanner.backups.setIamPolicy`
   * permission on [resource][google.iam.v1.SetIamPolicyRequest.resource].
   *
   * @param resource  REQUIRED: The resource for which the policy is being
   * specified. See the operation documentation for the appropriate value for
   * this field.
   * @param policy  REQUIRED: The complete policy to be applied to the
   * `resource`. The size of the policy is limited to a few 10s of KB. An empty
   * policy is a valid policy but certain Cloud Platform services (such as
   * Projects) might reject them.
   * @return
   * [google::iam::v1::Policy](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/iam/v1/policy.proto#L88)
   */
  StatusOr<google::iam::v1::Policy> SetIamPolicy(
      std::string const& resource, google::iam::v1::Policy const& policy);

  /**
   * Updates the IAM policy for @p resource using an optimistic concurrency
   * control loop.
   *
   * The loop fetches the current policy for @p resource, and passes it to @p
   * updater, which should return the new policy. This new policy should use the
   * current etag so that the read-modify-write cycle can detect races and rerun
   * the update when there is a mismatch. If the new policy does not have an
   * etag, the existing policy will be blindly overwritten. If @p updater does
   * not yield a policy, the control loop is terminated and kCancelled is
   * returned.
   *
   * @param resource  Required. The resource for which the policy is being
   * specified. See the operation documentation for the appropriate value for
   * this field.
   * @param updater  Required. Functor to map the current policy to a new one.
   * @param options  Optional. Options to control the loop. Expected options
   * are:
   *       - `DatabaseAdminBackoffPolicyOption`
   * @return google::iam::v1::Policy
   */
  StatusOr<google::iam::v1::Policy> SetIamPolicy(std::string const& resource,
                                                 IamUpdater const& updater,
                                                 Options options = {});

  /**
   * Gets the access control policy for a database or backup resource.
   * Returns an empty policy if a database or backup exists but does not have a
   * policy set.
   *
   * Authorization requires `spanner.databases.getIamPolicy` permission on
   * [resource][google.iam.v1.GetIamPolicyRequest.resource].
   * For backups, authorization requires `spanner.backups.getIamPolicy`
   * permission on [resource][google.iam.v1.GetIamPolicyRequest.resource].
   *
   * @param resource  REQUIRED: The resource for which the policy is being
   * requested. See the operation documentation for the appropriate value for
   * this field.
   * @return
   * [google::iam::v1::Policy](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/iam/v1/policy.proto#L88)
   */
  StatusOr<google::iam::v1::Policy> GetIamPolicy(std::string const& resource);

  /**
   * Returns permissions that the caller has on the specified database or backup
   * resource.
   *
   * Attempting this RPC on a non-existent Cloud Spanner database will
   * result in a NOT_FOUND error if the user has
   * `spanner.databases.list` permission on the containing Cloud
   * Spanner instance. Otherwise returns an empty set of permissions.
   * Calling this method on a backup that does not exist will
   * result in a NOT_FOUND error if the user has
   * `spanner.backups.list` permission on the containing instance.
   *
   * @param resource  REQUIRED: The resource for which the policy detail is
   * being requested. See the operation documentation for the appropriate value
   * for this field.
   * @param permissions  The set of permissions to check for the `resource`.
   * Permissions with wildcards (such as '*' or 'storage.*') are not allowed.
   * For more information see [IAM
   * Overview](https://cloud.google.com/iam/docs/overview#permissions).
   * @return
   * [google::iam::v1::TestIamPermissionsResponse](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/iam/v1/iam_policy.proto#L141)
   */
  StatusOr<google::iam::v1::TestIamPermissionsResponse> TestIamPermissions(
      std::string const& resource, std::vector<std::string> const& permissions);

  /**
   * Starts creating a new Cloud Spanner Backup.
   * The returned backup [long-running operation][google.longrunning.Operation]
   * will have a name of the format
   * `projects/<project>/instances/<instance>/backups/<backup>/operations/<operation_id>`
   * and can be used to track creation of the backup. The
   * [metadata][google.longrunning.Operation.metadata] field type is
   * [CreateBackupMetadata][google.spanner.admin.database.v1.CreateBackupMetadata].
   * The [response][google.longrunning.Operation.response] field type is
   * [Backup][google.spanner.admin.database.v1.Backup], if successful.
   * Cancelling the returned operation will stop the creation and delete the
   * backup. There can be only one pending backup creation per database. Backup
   * creation of different databases can run concurrently.
   *
   * @param parent  Required. The name of the instance in which the backup will
   * be created. This must be the same instance that contains the database the
   *  backup will be created from. The backup will be stored in the
   *  location(s) specified in the instance configuration of this
   *  instance. Values are of the form
   *  `projects/<project>/instances/<instance>`.
   * @param backup  Required. The backup to create.
   * @param backup_id  Required. The id of the backup to be created. The
   * `backup_id` appended to `parent` forms the full backup name of the form
   *  `projects/<project>/instances/<instance>/backups/<backup_id>`.
   * @return
   * [google::spanner::admin::database::v1::Backup](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/backup.proto#L36)
   */
  future<StatusOr<google::spanner::admin::database::v1::Backup>> CreateBackup(
      std::string const& parent,
      google::spanner::admin::database::v1::Backup const& backup,
      std::string const& backup_id);

  /**
   * Gets metadata on a pending or completed
   * [Backup][google.spanner.admin.database.v1.Backup].
   *
   * @param name  Required. Name of the backup.
   *  Values are of the form
   *  `projects/<project>/instances/<instance>/backups/<backup>`.
   * @return
   * [google::spanner::admin::database::v1::Backup](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/backup.proto#L36)
   */
  StatusOr<google::spanner::admin::database::v1::Backup> GetBackup(
      std::string const& name);

  /**
   * Updates a pending or completed
   * [Backup][google.spanner.admin.database.v1.Backup].
   *
   * @param backup  Required. The backup to update. `backup.name`, and the
   * fields to be updated as specified by `update_mask` are required. Other
   * fields are ignored. Update is only supported for the following fields:
   *   * `backup.expire_time`.
   * @param update_mask  Required. A mask specifying which fields (e.g.
   * `expire_time`) in the Backup resource should be updated. This mask is
   * relative to the Backup resource, not to the request message. The field mask
   * must always be specified; this prevents any future fields from being erased
   * accidentally by clients that do not know about them.
   * @return
   * [google::spanner::admin::database::v1::Backup](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/backup.proto#L36)
   */
  StatusOr<google::spanner::admin::database::v1::Backup> UpdateBackup(
      google::spanner::admin::database::v1::Backup const& backup,
      google::protobuf::FieldMask const& update_mask);

  /**
   * Deletes a pending or completed
   * [Backup][google.spanner.admin.database.v1.Backup].
   *
   * @param name  Required. Name of the backup to delete.
   *  Values are of the form
   *  `projects/<project>/instances/<instance>/backups/<backup>`.
   */
  Status DeleteBackup(std::string const& name);

  /**
   * Lists completed and pending backups.
   * Backups returned are ordered by `create_time` in descending order,
   * starting from the most recent `create_time`.
   *
   * @param parent  Required. The instance to list backups from.  Values are of
   * the form `projects/<project>/instances/<instance>`.
   * @return
   * [google::spanner::admin::database::v1::Backup](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/backup.proto#L36)
   */
  StreamRange<google::spanner::admin::database::v1::Backup> ListBackups(
      std::string const& parent);

  /**
   * Create a new database by restoring from a completed backup. The new
   * database must be in the same project and in an instance with the same
   * instance configuration as the instance containing
   * the backup. The returned database [long-running
   * operation][google.longrunning.Operation] has a name of the format
   * `projects/<project>/instances/<instance>/databases/<database>/operations/<operation_id>`,
   * and can be used to track the progress of the operation, and to cancel it.
   * The [metadata][google.longrunning.Operation.metadata] field type is
   * [RestoreDatabaseMetadata][google.spanner.admin.database.v1.RestoreDatabaseMetadata].
   * The [response][google.longrunning.Operation.response] type
   * is [Database][google.spanner.admin.database.v1.Database], if
   * successful. Cancelling the returned operation will stop the restore and
   * delete the database.
   * There can be only one database being restored into an instance at a time.
   * Once the restore operation completes, a new restore operation can be
   * initiated, without waiting for the optimize operation associated with the
   * first restore to complete.
   *
   * @param parent  Required. The name of the instance in which to create the
   *  restored database. This instance must be in the same project and
   *  have the same instance configuration as the instance containing
   *  the source backup. Values are of the form
   *  `projects/<project>/instances/<instance>`.
   * @param database_id  Required. The id of the database to create and restore
   * to. This database must not already exist. The `database_id` appended to
   *  `parent` forms the full database name of the form
   *  `projects/<project>/instances/<instance>/databases/<database_id>`.
   * @param backup  Name of the backup from which to restore.  Values are of the
   * form `projects/<project>/instances/<instance>/backups/<backup>`.
   * @return
   * [google::spanner::admin::database::v1::Database](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/spanner_database_admin.proto#L326)
   */
  future<StatusOr<google::spanner::admin::database::v1::Database>>
  RestoreDatabase(std::string const& parent, std::string const& database_id,
                  std::string const& backup);

  /**
   * Lists database [longrunning-operations][google.longrunning.Operation].
   * A database operation has a name of the form
   * `projects/<project>/instances/<instance>/databases/<database>/operations/<operation>`.
   * The long-running operation
   * [metadata][google.longrunning.Operation.metadata] field type
   * `metadata.type_url` describes the type of the metadata. Operations returned
   * include those that have completed/failed/canceled within the last 7 days,
   * and pending operations.
   *
   * @param parent  Required. The instance of the database operations.
   *  Values are of the form `projects/<project>/instances/<instance>`.
   * @return
   * [google::longrunning::Operation](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/longrunning/operations.proto#L128)
   */
  StreamRange<google::longrunning::Operation> ListDatabaseOperations(
      std::string const& parent);

  /**
   * Lists the backup [long-running operations][google.longrunning.Operation] in
   * the given instance. A backup operation has a name of the form
   * `projects/<project>/instances/<instance>/backups/<backup>/operations/<operation>`.
   * The long-running operation
   * [metadata][google.longrunning.Operation.metadata] field type
   * `metadata.type_url` describes the type of the metadata. Operations returned
   * include those that have completed/failed/canceled within the last 7 days,
   * and pending operations. Operations returned are ordered by
   * `operation.metadata.value.progress.start_time` in descending order starting
   * from the most recently started operation.
   *
   * @param parent  Required. The instance of the backup operations. Values are
   * of the form `projects/<project>/instances/<instance>`.
   * @return
   * [google::longrunning::Operation](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/longrunning/operations.proto#L128)
   */
  StreamRange<google::longrunning::Operation> ListBackupOperations(
      std::string const& parent);

  /**
   * Lists Cloud Spanner databases.
   *
   * @param request
   * [google::spanner::admin::database::v1::ListDatabasesRequest](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/spanner_database_admin.proto#L413)
   * @return
   * [google::spanner::admin::database::v1::Database](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/spanner_database_admin.proto#L326)
   */
  StreamRange<google::spanner::admin::database::v1::Database> ListDatabases(
      google::spanner::admin::database::v1::ListDatabasesRequest request);

  /**
   * Creates a new Cloud Spanner database and starts to prepare it for serving.
   * The returned [long-running operation][google.longrunning.Operation] will
   * have a name of the format `<database_name>/operations/<operation_id>` and
   * can be used to track preparation of the database. The
   * [metadata][google.longrunning.Operation.metadata] field type is
   * [CreateDatabaseMetadata][google.spanner.admin.database.v1.CreateDatabaseMetadata].
   * The [response][google.longrunning.Operation.response] field type is
   * [Database][google.spanner.admin.database.v1.Database], if successful.
   *
   * @param request
   * [google::spanner::admin::database::v1::CreateDatabaseRequest](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/spanner_database_admin.proto#L445)
   * @return
   * [google::spanner::admin::database::v1::Database](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/spanner_database_admin.proto#L326)
   */
  future<StatusOr<google::spanner::admin::database::v1::Database>>
  CreateDatabase(
      google::spanner::admin::database::v1::CreateDatabaseRequest const&
          request);

  /**
   * Gets the state of a Cloud Spanner database.
   *
   * @param request
   * [google::spanner::admin::database::v1::GetDatabaseRequest](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/spanner_database_admin.proto#L484)
   * @return
   * [google::spanner::admin::database::v1::Database](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/spanner_database_admin.proto#L326)
   */
  StatusOr<google::spanner::admin::database::v1::Database> GetDatabase(
      google::spanner::admin::database::v1::GetDatabaseRequest const& request);

  /**
   * Updates the schema of a Cloud Spanner database by
   * creating/altering/dropping tables, columns, indexes, etc. The returned
   * [long-running operation][google.longrunning.Operation] will have a name of
   * the format `<database_name>/operations/<operation_id>` and can be used to
   * track execution of the schema change(s). The
   * [metadata][google.longrunning.Operation.metadata] field type is
   * [UpdateDatabaseDdlMetadata][google.spanner.admin.database.v1.UpdateDatabaseDdlMetadata].
   * The operation has no response.
   *
   * @param request
   * [google::spanner::admin::database::v1::UpdateDatabaseDdlRequest](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/spanner_database_admin.proto#L511)
   * @return
   * [google::spanner::admin::database::v1::UpdateDatabaseDdlMetadata](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/spanner_database_admin.proto#L547)
   */
  future<
      StatusOr<google::spanner::admin::database::v1::UpdateDatabaseDdlMetadata>>
  UpdateDatabaseDdl(
      google::spanner::admin::database::v1::UpdateDatabaseDdlRequest const&
          request);

  /**
   * Drops (aka deletes) a Cloud Spanner database.
   * Completed backups for the database will be retained according to their
   * `expire_time`.
   *
   * @param request
   * [google::spanner::admin::database::v1::DropDatabaseRequest](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/spanner_database_admin.proto#L579)
   */
  Status DropDatabase(
      google::spanner::admin::database::v1::DropDatabaseRequest const& request);

  /**
   * Returns the schema of a Cloud Spanner database as a list of formatted
   * DDL statements. This method does not show pending schema updates, those may
   * be queried using the [Operations][google.longrunning.Operations] API.
   *
   * @param request
   * [google::spanner::admin::database::v1::GetDatabaseDdlRequest](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/spanner_database_admin.proto#L590)
   * @return
   * [google::spanner::admin::database::v1::GetDatabaseDdlResponse](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/spanner_database_admin.proto#L603)
   */
  StatusOr<google::spanner::admin::database::v1::GetDatabaseDdlResponse>
  GetDatabaseDdl(
      google::spanner::admin::database::v1::GetDatabaseDdlRequest const&
          request);

  /**
   * Sets the access control policy on a database or backup resource.
   * Replaces any existing policy.
   *
   * Authorization requires `spanner.databases.setIamPolicy`
   * permission on [resource][google.iam.v1.SetIamPolicyRequest.resource].
   * For backups, authorization requires `spanner.backups.setIamPolicy`
   * permission on [resource][google.iam.v1.SetIamPolicyRequest.resource].
   *
   * @param request
   * [google::iam::v1::SetIamPolicyRequest](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/iam/v1/iam_policy.proto#L98)
   * @return
   * [google::iam::v1::Policy](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/iam/v1/policy.proto#L88)
   */
  StatusOr<google::iam::v1::Policy> SetIamPolicy(
      google::iam::v1::SetIamPolicyRequest const& request);

  /**
   * Gets the access control policy for a database or backup resource.
   * Returns an empty policy if a database or backup exists but does not have a
   * policy set.
   *
   * Authorization requires `spanner.databases.getIamPolicy` permission on
   * [resource][google.iam.v1.GetIamPolicyRequest.resource].
   * For backups, authorization requires `spanner.backups.getIamPolicy`
   * permission on [resource][google.iam.v1.GetIamPolicyRequest.resource].
   *
   * @param request
   * [google::iam::v1::GetIamPolicyRequest](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/iam/v1/iam_policy.proto#L113)
   * @return
   * [google::iam::v1::Policy](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/iam/v1/policy.proto#L88)
   */
  StatusOr<google::iam::v1::Policy> GetIamPolicy(
      google::iam::v1::GetIamPolicyRequest const& request);

  /**
   * Returns permissions that the caller has on the specified database or backup
   * resource.
   *
   * Attempting this RPC on a non-existent Cloud Spanner database will
   * result in a NOT_FOUND error if the user has
   * `spanner.databases.list` permission on the containing Cloud
   * Spanner instance. Otherwise returns an empty set of permissions.
   * Calling this method on a backup that does not exist will
   * result in a NOT_FOUND error if the user has
   * `spanner.backups.list` permission on the containing instance.
   *
   * @param request
   * [google::iam::v1::TestIamPermissionsRequest](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/iam/v1/iam_policy.proto#L126)
   * @return
   * [google::iam::v1::TestIamPermissionsResponse](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/iam/v1/iam_policy.proto#L141)
   */
  StatusOr<google::iam::v1::TestIamPermissionsResponse> TestIamPermissions(
      google::iam::v1::TestIamPermissionsRequest const& request);

  /**
   * Starts creating a new Cloud Spanner Backup.
   * The returned backup [long-running operation][google.longrunning.Operation]
   * will have a name of the format
   * `projects/<project>/instances/<instance>/backups/<backup>/operations/<operation_id>`
   * and can be used to track creation of the backup. The
   * [metadata][google.longrunning.Operation.metadata] field type is
   * [CreateBackupMetadata][google.spanner.admin.database.v1.CreateBackupMetadata].
   * The [response][google.longrunning.Operation.response] field type is
   * [Backup][google.spanner.admin.database.v1.Backup], if successful.
   * Cancelling the returned operation will stop the creation and delete the
   * backup. There can be only one pending backup creation per database. Backup
   * creation of different databases can run concurrently.
   *
   * @param request
   * [google::spanner::admin::database::v1::CreateBackupRequest](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/backup.proto#L123)
   * @return
   * [google::spanner::admin::database::v1::Backup](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/backup.proto#L36)
   */
  future<StatusOr<google::spanner::admin::database::v1::Backup>> CreateBackup(
      google::spanner::admin::database::v1::CreateBackupRequest const& request);

  /**
   * Gets metadata on a pending or completed
   * [Backup][google.spanner.admin.database.v1.Backup].
   *
   * @param request
   * [google::spanner::admin::database::v1::GetBackupRequest](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/backup.proto#L202)
   * @return
   * [google::spanner::admin::database::v1::Backup](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/backup.proto#L36)
   */
  StatusOr<google::spanner::admin::database::v1::Backup> GetBackup(
      google::spanner::admin::database::v1::GetBackupRequest const& request);

  /**
   * Updates a pending or completed
   * [Backup][google.spanner.admin.database.v1.Backup].
   *
   * @param request
   * [google::spanner::admin::database::v1::UpdateBackupRequest](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/backup.proto#L186)
   * @return
   * [google::spanner::admin::database::v1::Backup](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/backup.proto#L36)
   */
  StatusOr<google::spanner::admin::database::v1::Backup> UpdateBackup(
      google::spanner::admin::database::v1::UpdateBackupRequest const& request);

  /**
   * Deletes a pending or completed
   * [Backup][google.spanner.admin.database.v1.Backup].
   *
   * @param request
   * [google::spanner::admin::database::v1::DeleteBackupRequest](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/backup.proto#L215)
   */
  Status DeleteBackup(
      google::spanner::admin::database::v1::DeleteBackupRequest const& request);

  /**
   * Lists completed and pending backups.
   * Backups returned are ordered by `create_time` in descending order,
   * starting from the most recent `create_time`.
   *
   * @param request
   * [google::spanner::admin::database::v1::ListBackupsRequest](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/backup.proto#L228)
   * @return
   * [google::spanner::admin::database::v1::Backup](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/backup.proto#L36)
   */
  StreamRange<google::spanner::admin::database::v1::Backup> ListBackups(
      google::spanner::admin::database::v1::ListBackupsRequest request);

  /**
   * Create a new database by restoring from a completed backup. The new
   * database must be in the same project and in an instance with the same
   * instance configuration as the instance containing
   * the backup. The returned database [long-running
   * operation][google.longrunning.Operation] has a name of the format
   * `projects/<project>/instances/<instance>/databases/<database>/operations/<operation_id>`,
   * and can be used to track the progress of the operation, and to cancel it.
   * The [metadata][google.longrunning.Operation.metadata] field type is
   * [RestoreDatabaseMetadata][google.spanner.admin.database.v1.RestoreDatabaseMetadata].
   * The [response][google.longrunning.Operation.response] type
   * is [Database][google.spanner.admin.database.v1.Database], if
   * successful. Cancelling the returned operation will stop the restore and
   * delete the database.
   * There can be only one database being restored into an instance at a time.
   * Once the restore operation completes, a new restore operation can be
   * initiated, without waiting for the optimize operation associated with the
   * first restore to complete.
   *
   * @param request
   * [google::spanner::admin::database::v1::RestoreDatabaseRequest](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/spanner_database_admin.proto#L692)
   * @return
   * [google::spanner::admin::database::v1::Database](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/spanner_database_admin.proto#L326)
   */
  future<StatusOr<google::spanner::admin::database::v1::Database>>
  RestoreDatabase(
      google::spanner::admin::database::v1::RestoreDatabaseRequest const&
          request);

  /**
   * Lists database [longrunning-operations][google.longrunning.Operation].
   * A database operation has a name of the form
   * `projects/<project>/instances/<instance>/databases/<database>/operations/<operation>`.
   * The long-running operation
   * [metadata][google.longrunning.Operation.metadata] field type
   * `metadata.type_url` describes the type of the metadata. Operations returned
   * include those that have completed/failed/canceled within the last 7 days,
   * and pending operations.
   *
   * @param request
   * [google::spanner::admin::database::v1::ListDatabaseOperationsRequest](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/spanner_database_admin.proto#L611)
   * @return
   * [google::longrunning::Operation](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/longrunning/operations.proto#L128)
   */
  StreamRange<google::longrunning::Operation> ListDatabaseOperations(
      google::spanner::admin::database::v1::ListDatabaseOperationsRequest
          request);

  /**
   * Lists the backup [long-running operations][google.longrunning.Operation] in
   * the given instance. A backup operation has a name of the form
   * `projects/<project>/instances/<instance>/backups/<backup>/operations/<operation>`.
   * The long-running operation
   * [metadata][google.longrunning.Operation.metadata] field type
   * `metadata.type_url` describes the type of the metadata. Operations returned
   * include those that have completed/failed/canceled within the last 7 days,
   * and pending operations. Operations returned are ordered by
   * `operation.metadata.value.progress.start_time` in descending order starting
   * from the most recently started operation.
   *
   * @param request
   * [google::spanner::admin::database::v1::ListBackupOperationsRequest](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/spanner/admin/database/v1/backup.proto#L300)
   * @return
   * [google::longrunning::Operation](https://github.com/googleapis/googleapis/blob/9bac62dbc7a1f7b19baf578d6fbb550dbaff0d49/google/longrunning/operations.proto#L128)
   */
  StreamRange<google::longrunning::Operation> ListBackupOperations(
      google::spanner::admin::database::v1::ListBackupOperationsRequest
          request);

 private:
  std::shared_ptr<DatabaseAdminConnection> connection_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace spanner_admin
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SPANNER_ADMIN_DATABASE_ADMIN_CLIENT_H
