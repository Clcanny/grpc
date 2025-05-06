//
//
// Copyright 2017 gRPC authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//

#include <grpc/support/port_platform.h>

#include "src/core/lib/iomgr/port.h"

#ifdef GRPC_POSIX_SOCKET_SOCKET_FACTORY

#include <grpc/impl/grpc_types.h>
#include <grpc/support/sync.h>

#include "src/core/lib/channel/channel_args.h"
#include "src/core/lib/iomgr/socket_factory_posix.h"
#include "src/core/util/useful.h"

grpc_socket_factory_vtable* grpc_socket_factory_impl;

int grpc_socket_factory_socket(int domain, int type, int protocol) {
  return grpc_socket_factory_impl->socket(domain, type, protocol);
}

int grpc_socket_factory_bind(int sockfd, const grpc_resolved_address* addr) {
  return grpc_socket_factory_impl->bind(sockfd, (struct sockaddr*)addr->addr, addr->len);
}

int grpc_socket_factory_bind(int sockfd, const struct sockaddr* addr, socklen_t len) {
  return grpc_socket_factory_impl->bind(sockfd, addr, len);
}

#endif
