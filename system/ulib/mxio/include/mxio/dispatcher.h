// Copyright 2016 The Fuchsia Authors
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

#pragma once

#include <magenta/types.h>
#include <system/compiler.h>

__BEGIN_CDECLS

typedef struct mxio_dispatcher mxio_dispatcher_t;

typedef mx_status_t (*mxio_dispatcher_cb_t)(mx_handle_t h, void* cb, void* cookie);

// Create a dispatcher that will process messages from many message pipes.
//
// The provided handler will be called when a handle is readable, and passed
// the cb and cookie pointers that are associated with that handle.
//
// If the remote side of the message pipe is closed, the handler will be
// called and passed a zero handle.
//
// A non-zero return will cause the handle to be closed.  If the non-zero
// return is *negative*, the handler will be called one last time, as if
// the message pipe had been closed remotely (zero handle).
mx_status_t mxio_dispatcher_create(mxio_dispatcher_t** out, mxio_dispatcher_cb_t cb);

// create a thread for a dispatcher and start it running
mx_status_t mxio_dispatcher_start(mxio_dispatcher_t* md);

// run the dispatcher loop on the current thread, never to return
void mxio_dispatcher_run(mxio_dispatcher_t* md);

// add a pipe and handler to a dispatcher
mx_status_t mxio_dispatcher_add(mxio_dispatcher_t* md, mx_handle_t h, void* cb, void* cookie);

// dispatcher callback return code that there were no messages to read
#define ERR_DISPATCHER_NO_WORK (-9999)

// indicates message handed off to another server
// used by rio remote handler for deferred reply pipe completion
#define ERR_DISPATCHER_INDIRECT (-9998)

__END_CDECLS
