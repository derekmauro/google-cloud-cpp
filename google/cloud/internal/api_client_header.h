// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_INTERNAL_API_CLIENT_HEADER_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_INTERNAL_API_CLIENT_HEADER_H

#include "google/cloud/version.h"
#include <string>

namespace google {
namespace cloud {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN
namespace internal {

/// Return the semantic versioning string (https://semver.org/).
std::string ApiClientVersion(std::string const& build_identifier);

/// Return the value for the x-goog-api-client header (aka metadata).
std::string ApiClientHeader(std::string const& build_identifier = "");

/// The value for the x-goog-api-client header for hand-crafted libraries.
std::string HandCraftedLibClientHeader();

/// The value for the x-goog-api-client header for generated libraries.
std::string GeneratedLibClientHeader();

}  // namespace internal
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_INTERNAL_API_CLIENT_HEADER_H
