# Copyright 2016 The Fuchsia Authors
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_TYPE := userlib

MODULE_SRCS += \
    $(LOCAL_DIR)/bootfs.c \
    $(LOCAL_DIR)/debug.c \
    $(LOCAL_DIR)/dispatcher-v2.c \
    $(LOCAL_DIR)/logger.c \
    $(LOCAL_DIR)/null.c \
    $(LOCAL_DIR)/pipe.c \
    $(LOCAL_DIR)/remoteio.c \
    $(LOCAL_DIR)/socket.c \
    $(LOCAL_DIR)/unistd.c \
    $(LOCAL_DIR)/startup-handles.c \
    $(LOCAL_DIR)/stubs.c \
    $(LOCAL_DIR)/loader-service.c \

MODULE_EXPORT := mxio

MODULE_SO_NAME := mxio
MODULE_STATIC_LIBS := ulib/runtime
MODULE_LIBS := ulib/magenta ulib/musl

include make/module.mk
