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
// source: google/cloud/notebooks/v1/service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_NOTEBOOKS_V1_MOCKS_MOCK_NOTEBOOK_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_NOTEBOOKS_V1_MOCKS_MOCK_NOTEBOOK_CONNECTION_H

#include "google/cloud/notebooks/v1/notebook_connection.h"
#include <gmock/gmock.h>

namespace google {
namespace cloud {
namespace notebooks_v1_mocks {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

/**
 * A class to mock `NotebookServiceConnection`.
 *
 * Application developers may want to test their code with simulated responses,
 * including errors, from an object of type `NotebookServiceClient`. To do so,
 * construct an object of type `NotebookServiceClient` with an instance of this
 * class. Then use the Google Test framework functions to program the behavior
 * of this mock.
 *
 * @see [This example][bq-mock] for how to test your application with GoogleTest.
 * While the example showcases types from the BigQuery library, the underlying
 * principles apply for any pair of `*Client` and `*Connection`.
 *
 * [bq-mock]: @googleapis_dev_link{bigquery,bigquery-read-mock.html}
 */
class MockNotebookServiceConnection
    : public notebooks_v1::NotebookServiceConnection {
 public:
  MOCK_METHOD(Options, options, (), (override));

  MOCK_METHOD(StreamRange<google::cloud::notebooks::v1::Instance>,
              ListInstances,
              (google::cloud::notebooks::v1::ListInstancesRequest request),
              (override));

  MOCK_METHOD(StatusOr<google::cloud::notebooks::v1::Instance>, GetInstance,
              (google::cloud::notebooks::v1::GetInstanceRequest const& request),
              (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::notebooks::v1::Instance>>, CreateInstance,
      (google::cloud::notebooks::v1::CreateInstanceRequest const& request),
      (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::notebooks::v1::Instance>>,
      RegisterInstance,
      (google::cloud::notebooks::v1::RegisterInstanceRequest const& request),
      (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::notebooks::v1::Instance>>,
      SetInstanceAccelerator,
      (google::cloud::notebooks::v1::SetInstanceAcceleratorRequest const&
           request),
      (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::notebooks::v1::Instance>>,
      SetInstanceMachineType,
      (google::cloud::notebooks::v1::SetInstanceMachineTypeRequest const&
           request),
      (override));

  MOCK_METHOD(future<StatusOr<google::cloud::notebooks::v1::Instance>>,
              UpdateInstanceConfig,
              (google::cloud::notebooks::v1::UpdateInstanceConfigRequest const&
                   request),
              (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::notebooks::v1::Instance>>,
      UpdateShieldedInstanceConfig,
      (google::cloud::notebooks::v1::UpdateShieldedInstanceConfigRequest const&
           request),
      (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::notebooks::v1::Instance>>,
      SetInstanceLabels,
      (google::cloud::notebooks::v1::SetInstanceLabelsRequest const& request),
      (override));

  MOCK_METHOD(
      StatusOr<
          google::cloud::notebooks::v1::UpdateInstanceMetadataItemsResponse>,
      UpdateInstanceMetadataItems,
      (google::cloud::notebooks::v1::UpdateInstanceMetadataItemsRequest const&
           request),
      (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::notebooks::v1::OperationMetadata>>,
      DeleteInstance,
      (google::cloud::notebooks::v1::DeleteInstanceRequest const& request),
      (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::notebooks::v1::Instance>>, StartInstance,
      (google::cloud::notebooks::v1::StartInstanceRequest const& request),
      (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::notebooks::v1::Instance>>, StopInstance,
      (google::cloud::notebooks::v1::StopInstanceRequest const& request),
      (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::notebooks::v1::Instance>>, ResetInstance,
      (google::cloud::notebooks::v1::ResetInstanceRequest const& request),
      (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::notebooks::v1::Instance>>,
      ReportInstanceInfo,
      (google::cloud::notebooks::v1::ReportInstanceInfoRequest const& request),
      (override));

  MOCK_METHOD(
      StatusOr<google::cloud::notebooks::v1::IsInstanceUpgradeableResponse>,
      IsInstanceUpgradeable,
      (google::cloud::notebooks::v1::IsInstanceUpgradeableRequest const&
           request),
      (override));

  MOCK_METHOD(
      StatusOr<google::cloud::notebooks::v1::GetInstanceHealthResponse>,
      GetInstanceHealth,
      (google::cloud::notebooks::v1::GetInstanceHealthRequest const& request),
      (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::notebooks::v1::Instance>>, UpgradeInstance,
      (google::cloud::notebooks::v1::UpgradeInstanceRequest const& request),
      (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::notebooks::v1::Instance>>,
      RollbackInstance,
      (google::cloud::notebooks::v1::RollbackInstanceRequest const& request),
      (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::notebooks::v1::Instance>>,
      DiagnoseInstance,
      (google::cloud::notebooks::v1::DiagnoseInstanceRequest const& request),
      (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::notebooks::v1::Instance>>,
      UpgradeInstanceInternal,
      (google::cloud::notebooks::v1::UpgradeInstanceInternalRequest const&
           request),
      (override));

  MOCK_METHOD(StreamRange<google::cloud::notebooks::v1::Environment>,
              ListEnvironments,
              (google::cloud::notebooks::v1::ListEnvironmentsRequest request),
              (override));

  MOCK_METHOD(
      StatusOr<google::cloud::notebooks::v1::Environment>, GetEnvironment,
      (google::cloud::notebooks::v1::GetEnvironmentRequest const& request),
      (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::notebooks::v1::Environment>>,
      CreateEnvironment,
      (google::cloud::notebooks::v1::CreateEnvironmentRequest const& request),
      (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::notebooks::v1::OperationMetadata>>,
      DeleteEnvironment,
      (google::cloud::notebooks::v1::DeleteEnvironmentRequest const& request),
      (override));

  MOCK_METHOD(StreamRange<google::cloud::notebooks::v1::Schedule>,
              ListSchedules,
              (google::cloud::notebooks::v1::ListSchedulesRequest request),
              (override));

  MOCK_METHOD(StatusOr<google::cloud::notebooks::v1::Schedule>, GetSchedule,
              (google::cloud::notebooks::v1::GetScheduleRequest const& request),
              (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::notebooks::v1::OperationMetadata>>,
      DeleteSchedule,
      (google::cloud::notebooks::v1::DeleteScheduleRequest const& request),
      (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::notebooks::v1::Schedule>>, CreateSchedule,
      (google::cloud::notebooks::v1::CreateScheduleRequest const& request),
      (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::notebooks::v1::Schedule>>, TriggerSchedule,
      (google::cloud::notebooks::v1::TriggerScheduleRequest const& request),
      (override));

  MOCK_METHOD(StreamRange<google::cloud::notebooks::v1::Execution>,
              ListExecutions,
              (google::cloud::notebooks::v1::ListExecutionsRequest request),
              (override));

  MOCK_METHOD(
      StatusOr<google::cloud::notebooks::v1::Execution>, GetExecution,
      (google::cloud::notebooks::v1::GetExecutionRequest const& request),
      (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::notebooks::v1::OperationMetadata>>,
      DeleteExecution,
      (google::cloud::notebooks::v1::DeleteExecutionRequest const& request),
      (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::notebooks::v1::Execution>>,
      CreateExecution,
      (google::cloud::notebooks::v1::CreateExecutionRequest const& request),
      (override));
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace notebooks_v1_mocks
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_NOTEBOOKS_V1_MOCKS_MOCK_NOTEBOOK_CONNECTION_H
