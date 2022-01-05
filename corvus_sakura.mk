#
# Copyright (C) 2022 The Android Open-Source Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

#
# All components inherited here go to system_ext image
#
$(call inherit-product, $(SRC_TARGET_DIR)/product/handheld_system_ext.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/telephony_system_ext.mk)

# Inherit from mido device
$(call inherit-product, device/xiaomi/sakura/device.mk)

# Inherit some common corvusOS stuff.
$(call inherit-product, vendor/corvus/config/common_full_phone.mk)

# Poduct spec
IS_PHONE := true
scr_resolution := 1080

# Device identifier. This must come after all inclusions
CORVUS_MAINTAINER := Yadavmohit19
PRODUCT_DEVICE := sakura
PRODUCT_NAME := corvus_sakura
BOARD_VENDOR := Xiaomi
PRODUCT_BRAND := Xiaomi
PRODUCT_MODEL := Redmi 6 Pro
PRODUCT_MANUFACTURER := Xiaomi
TARGET_VENDOR := Xiaomi

PRODUCT_GMS_CLIENTID_BASE := android-xiaomi

# Face Unlock Flag
TARGET_FACE_UNLOCK_SUPPORTED := true

# Gapps Flag
TARGET_GAPPS_ARCH := arm64
TARGET_SUPPORTS_GOOGLE_RECORDER := true
TARGET_INCLUDE_STOCK_ARCORE := true
