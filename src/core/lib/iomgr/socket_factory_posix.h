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
  int (*socket)(int domain, int type, int protocol);
  int (*getsockopt)(int sockfd, int level, int optname, void* optval,
                    socklen_t* optlen);
  int (*setsockopt)(int sockfd, int level, int optname, const void* optval,
                    socklen_t optlen);
  int (*ioctl)(int fd, unsigned long op, ...);
  int (*fcntl)(int fd, int op, ...);
  int (*close)(int fd);
  ssize_t (*read)(int fd, void* buf, size_t count);
  ssize_t (*write)(int fd, void* buf, size_t count);
  ssize_t (*sendmsg)(int fd, const struct msghdr* msg, int flags);
  ssize_t (*recvmsg)(int sockfd, struct msghdr* msg, int flags);
  int (*accept)(int sockfd, struct sockaddr* addr, socklen_t* addrlen);
  int (*accept4)(int sockfd, struct sockaddr* addr, socklen_t* addrlen,
                 int flags);
  int (*listen)(int sockfd, int backlog);
  int (*bind)(int sockfd, const struct sockaddr* addr, socklen_t len);
  int (*connect)(int sockfd, const struct sockaddr* addr, socklen_t addrlen);
  int (*getpeername)(int sockfd, struct sockaddr* addr, socklen_t* addrlen);
  int (*shutdown)(int sockfd, int how);
};

int grpc_socket_factory_socket(int domain, int type, int protocol);

int grpc_socket_factory_getsockopt(int sockfd, int level, int optname,
                                   void* optval, socklen_t* optlen);

int grpc_socket_factory_setsockopt(int sockfd, int level, int optname,
                                   const void* optval, socklen_t optlen);

int grpc_socket_factory_ioctl(int fd, unsigned long op, ...);

int grpc_socket_factory_fcntl(int fd, int op, ...);

int grpc_socket_factory_close(int fd);

ssize_t grpc_socket_factory_read(int fd, void* buf, size_t count);

ssize_t grpc_socket_factory_write(int fd, void* buf, size_t count);

ssize_t grpc_socket_factory_sendmsg(int fd, const struct msghdr* msg,
                                    int flags);

ssize_t grpc_socket_factory_recvmsg(int sockfd, struct msghdr* msg, int flags);

int grpc_socket_factory_accept(int sockfd, struct sockaddr* addr,
                               socklen_t* addrlen);

int grpc_socket_factory_accept4(int sockfd, struct sockaddr* addr,
                                socklen_t* addrlen, int flags);

int grpc_socket_factory_listen(int sockfd, int backlog);

int grpc_socket_factory_bind(int sockfd, const grpc_resolved_address* addr);
int grpc_socket_factory_bind(int sockfd, const struct sockaddr* addr,
                             socklen_t len);

int grpc_socket_factory_connect(int sockfd, const struct sockaddr* addr,
                                socklen_t addrlen);

int grpc_socket_factory_getpeername(int sockfd, struct sockaddr* addr,
                                    socklen_t* addrlen);

int grpc_socket_factory_shutdown(int sockfd, int how);

#endif  // GRPC_SRC_CORE_LIB_IOMGR_SOCKET_FACTORY_POSIX_H
