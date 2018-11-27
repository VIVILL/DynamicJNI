LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := dynamic
LOCAL_SRC_FILES :=  dynamicJni.cpp
include $(BUILD_SHARED_LIBRARY)