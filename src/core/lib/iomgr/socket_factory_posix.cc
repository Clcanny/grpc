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

grpc_socket_factory_vtable grpc_default_socket_factory_vtable = {
    socket, getsockopt, setsockopt, ioctl,   fcntl, close,
    read,   write,      sendmsg,    recvmsg, bind,  shutdown,
};

grpc_socket_factory_vtable* grpc_socket_factory_impl =
    &grpc_default_socket_factory_vtable;

int grpc_socket_factory_socket(int domain, int type, int protocol) {
  return grpc_socket_factory_impl->socket(domain, type, protocol);
}

int grpc_socket_factory_getsockopt(int sockfd, int level, int optname,
                                   void* optval, socklen_t* optlen) {
  return grpc_socket_factory_impl->getsockopt(sockfd, level, optname, optval,
                                              optlen);
}

int grpc_socket_factory_setsockopt(int sockfd, int level, int optname,
                                   const void* optval, socklen_t optlen) {
  return grpc_socket_factory_impl->setsockopt(sockfd, level, optname, optval,
                                              optlen);
}

int grpc_socket_factory_ioctl(int fd, unsigned long op, ...) {
  return grpc_socket_factory_impl->ioctl(fd, op, ...);
}

int grpc_socket_factory_fcntl(int fd, int op, ...) {
  return grpc_socket_factory_impl->fcntl(fd, op, ...);
}

int grpc_socket_factory_close(int fd) {
  return grpc_socket_factory_impl->close(fd);
}

ssize_t grpc_socket_factory_read(int fd, void* buf, size_t count) {
  return grpc_socket_factory_impl->read(fd, buf, count);
}

ssize_t grpc_socket_factory_write(int fd, const void* buf, size_t count) {
  return grpc_socket_factory_impl->write(fd, buf, count);
}

ssize_t grpc_socket_factory_sendmsg(int fd, const struct msghdr* msg,
                                    int flags) {
  return grpc_socket_factory_impl->sendmsg(fd, msg, flags);
}

ssize_t grpc_socket_factory_recvmsg(int sockfd, struct msghdr* msg, int flags) {
  return grpc_socket_factory_impl->recvmsg(sockfd, msg, flags);
}

int grpc_socket_factory_accept(int sockfd, struct sockaddr* addr,
                               socklen_t* addrlen) {
  return grpc_socket_factory_impl->accept(sockfd, addr, addrlen);
}

int grpc_socket_factory_accept4(int sockfd, struct sockaddr* addr,
                                socklen_t* addrlen, int flags) {
  return grpc_socket_factory_impl->accept4(sockfd, addr, addrlen, flags);
}

int grpc_socket_factory_listen(int sockfd, int backlog) {
  return grpc_socket_factory_impl->listen(sockfd, backlog);
}

int grpc_socket_factory_bind(int sockfd, const grpc_resolved_address* addr) {
  return grpc_socket_factory_impl->bind(sockfd, (struct sockaddr*)addr->addr,
                                        addr->len);
}

int grpc_socket_factory_bind(int sockfd, const struct sockaddr* addr,
                             socklen_t len) {
  return grpc_socket_factory_impl->bind(sockfd, addr, len);
}

int grpc_socket_factory_connect(int sockfd, const struct sockaddr* addr,
                                socklen_t addrlen) {
  return grpc_socket_factory_impl->connect(sockfd, addr, addrlen);
}

int grpc_socket_factory_getpeername(int sockfd, struct sockaddr* addr,
                                    socklen_t* addrlen) {
  return grpc_socket_factory_impl->getpeername(sockfd, addr, addrlen);
}

int grpc_socket_factory_shutdown(int sockfd, int how) {
  return grpc_socket_factory_impl->shutdown(sockfd, how);
}

#endif
