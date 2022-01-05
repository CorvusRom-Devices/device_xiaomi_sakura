/*
 * Copyright (C) 2022 The Android Open Source Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _BDROID_BUILDCFG_H
#define _BDROID_BUILDCFG_H
#define BTM_DEF_LOCAL_NAME "Redmi 6 Pro"
// Disables read remote device feature
#define MAX_ACL_CONNECTIONS    16
#define MAX_L2CAP_CHANNELS    32
#define BLE_VND_INCLUDED   TRUE
#define GATT_MAX_PHY_CHANNEL  10

// Wide-band speech support
#define BTIF_HF_WBS_PREFERRED TRUE

// skips conn update at conn completion
#define BT_CLEAN_TURN_ON_DISABLED 1

/* Disable enhanced sco commands */
#define BTM_SCO_ENHANCED_SYNC_ENABLED FALSE

#define BTM_WBS_INCLUDED TRUE
#define BTIF_HF_WBS_PREFERRED TRUE

#define AVDT_NUM_SEPS 35

#endif /* _BDROID_BUILDCFG_H */
