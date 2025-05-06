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

#ifndef GRPC_SRC_CORE_LIB_IOMGR_SOCKET_FACTORY_POSIX_H
#define GRPC_SRC_CORE_LIB_IOMGR_SOCKET_FACTORY_POSIX_H

#include <grpc/impl/grpc_types.h>
#include <grpc/support/port_platform.h>
#include <grpc/support/sync.h>

#include "src/core/lib/iomgr/resolve_address.h"

/// The virtual table of grpc_socket_factory
struct grpc_socket_factory_vtable {
  /// Replacement for socket(2)
  int (*socket)(int domain, int type, int protocol);
  /// Replacement for getsockopt(2)
  int (*getsockopt)(int sockfd, int level, int optname,
                    void *optval, socklen_t *optlen);
  /// Replacement for setsockopt(2)
  int (*setsockopt)(int sockfd, int level, int optname,
                    const void *optval, socklen_t optlen);
  /// Replacement for ioctl(2)
  int (*ioctl)(int fd, unsigned long op, ...);
  /// Replacement for close(2)
  int (*close)(int fd);
  /// Replacement for read(2)
  ssize_t (*read)(int fd, void* buf, size_t count);
  /// Replacement for bind(2)
  int (*bind)(int sockfd, const struct sockaddr* addr, socklen_t len);
  /// Replacement for shutdown(2)
  int (*shutdown)(int sockfd, int how);
};

/// Perform the equivalent of a socket(2) operation using \a factory
int grpc_socket_factory_socket(int domain, int type, int protocol);

/// Perform the equivalent of a getsockopt(2) operation using \a factory
int grpc_socket_factory_getsockopt(int sockfd, int level, int optname,
                                   void *optval, socklen_t *optlen);

/// Perform the equivalent of a setsockopt(2) operation using \a factory
int grpc_socket_factory_setsockopt(int sockfd, int level, int optname,
                                   const void *optval, socklen_t optlen);

/// Perform the equivalent of a ioctl(2) operation using \a factory
int grpc_socket_factory_ioctl(int fd, unsigned long op, ...);

/// Perform the equivalent of a close(2) operation using \a factory
int grpc_socket_factory_close(int fd);

/// Perform the equivalent of a read(2) operation using \a factory
ssize_t grpc_socket_factory_read(int fd, void* buf, size_t count);

/// Perform the equivalent of a bind(2) operation using \a factory
int grpc_socket_factory_bind(int sockfd, const grpc_resolved_address* addr);
int grpc_socket_factory_bind(int sockfd, const struct sockaddr* addr, socklen_t len);

/// Perform the equivalent of a shutdown(2) operation using \a factory
int grpc_socket_factory_shutdown(int sockfd, int how);

#endif  // GRPC_SRC_CORE_LIB_IOMGR_SOCKET_FACTORY_POSIX_H
