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
// source: google/cloud/orgpolicy/v2/orgpolicy.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_ORGPOLICY_V2_ORG_POLICY_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_ORGPOLICY_V2_ORG_POLICY_CONNECTION_H

#include "google/cloud/orgpolicy/v2/internal/org_policy_retry_traits.h"
#include "google/cloud/orgpolicy/v2/internal/org_policy_stub.h"
#include "google/cloud/orgpolicy/v2/org_policy_connection_idempotency_policy.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace orgpolicy_v2 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using OrgPolicyRetryPolicy = ::google::cloud::internal::TraitBasedRetryPolicy<
    orgpolicy_v2_internal::OrgPolicyRetryTraits>;

using OrgPolicyLimitedTimeRetryPolicy =
    ::google::cloud::internal::LimitedTimeRetryPolicy<
        orgpolicy_v2_internal::OrgPolicyRetryTraits>;

using OrgPolicyLimitedErrorCountRetryPolicy =
    ::google::cloud::internal::LimitedErrorCountRetryPolicy<
        orgpolicy_v2_internal::OrgPolicyRetryTraits>;

/**
 * The `OrgPolicyConnection` object for `OrgPolicyClient`.
 *
 * This interface defines virtual methods for each of the user-facing overload
 * sets in `OrgPolicyClient`. This allows users to inject custom behavior
 * (e.g., with a Google Mock object) when writing tests that use objects of type
 * `OrgPolicyClient`.
 *
 * To create a concrete instance, see `MakeOrgPolicyConnection()`.
 *
 * For mocking, see `orgpolicy_v2_mocks::MockOrgPolicyConnection`.
 */
class OrgPolicyConnection {
 public:
  virtual ~OrgPolicyConnection() = 0;

  virtual Options options() { return Options{}; }

  virtual StreamRange<google::cloud::orgpolicy::v2::Constraint> ListConstraints(
      google::cloud::orgpolicy::v2::ListConstraintsRequest request);

  virtual StreamRange<google::cloud::orgpolicy::v2::Policy> ListPolicies(
      google::cloud::orgpolicy::v2::ListPoliciesRequest request);

  virtual StatusOr<google::cloud::orgpolicy::v2::Policy> GetPolicy(
      google::cloud::orgpolicy::v2::GetPolicyRequest const& request);

  virtual StatusOr<google::cloud::orgpolicy::v2::Policy> GetEffectivePolicy(
      google::cloud::orgpolicy::v2::GetEffectivePolicyRequest const& request);

  virtual StatusOr<google::cloud::orgpolicy::v2::Policy> CreatePolicy(
      google::cloud::orgpolicy::v2::CreatePolicyRequest const& request);

  virtual StatusOr<google::cloud::orgpolicy::v2::Policy> UpdatePolicy(
      google::cloud::orgpolicy::v2::UpdatePolicyRequest const& request);

  virtual Status DeletePolicy(
      google::cloud::orgpolicy::v2::DeletePolicyRequest const& request);
};

/**
 * A factory function to construct an object of type `OrgPolicyConnection`.
 *
 * The returned connection object should not be used directly; instead it
 * should be passed as an argument to the constructor of OrgPolicyClient.
 *
 * The optional @p options argument may be used to configure aspects of the
 * returned `OrgPolicyConnection`. Expected options are any of the types in
 * the following option lists:
 *
 * - `google::cloud::CommonOptionList`
 * - `google::cloud::GrpcOptionList`
 * - `google::cloud::UnifiedCredentialsOptionList`
 * - `google::cloud::orgpolicy_v2::OrgPolicyPolicyOptionList`
 *
 * @note Unexpected options will be ignored. To log unexpected options instead,
 *     set `GOOGLE_CLOUD_CPP_ENABLE_CLOG=yes` in the environment.
 *
 * @param options (optional) Configure the `OrgPolicyConnection` created by
 * this function.
 */
std::shared_ptr<OrgPolicyConnection> MakeOrgPolicyConnection(
    Options options = {});

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace orgpolicy_v2
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_ORGPOLICY_V2_ORG_POLICY_CONNECTION_H
