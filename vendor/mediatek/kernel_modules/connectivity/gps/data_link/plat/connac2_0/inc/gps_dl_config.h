/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2019-2021 MediaTek Inc.
 */
#ifndef _GPS_DL_CONFIG_H
#define _GPS_DL_CONFIG_H

enum gps_dl_link_id_enum {
	GPS_DATA_LINK_ID0	= 0,
	GPS_DATA_LINK_ID1	= 1,
	GPS_DATA_LINK_NUM	= 2,
};

#define LINK_ID_IS_VALID(link_id) \
	(((link_id) >= 0) && ((link_id) < GPS_DATA_LINK_NUM))

#define CHOOSE_BY_LINK_ID(link_id, val_for_id0, val_for_id1, val_for_otherwise) \
	(!LINK_ID_IS_VALID((link_id)) ? (val_for_otherwise) : ( \
		(link_id == GPS_DATA_LINK_ID0) ? val_for_id0 : val_for_id1))

#ifdef GPS_DL_HAS_MOCK
#define GPS_DL_HW_IS_MOCK     (1)
#define GPS_DL_MOCK_HAL       (1)
#else
#define GPS_DL_HW_IS_MOCK     (0)
#define GPS_DL_MOCK_HAL       (0)
#endif

#define GPS_DL_MOCK_RX_TIMEOUT (0)

#define GPS_DL_ON_LINUX       (1)
#define GPS_DL_ON_CTP         (0)

#define GPS_DL_HAS_CTRLD      (1)
#define GPS_DL_NO_USE_IRQ     (0)
#define GPS_DL_USE_THREADED_IRQ (1)

#ifndef GPS_DL_HAS_CONNINFRA_DRV
#define GPS_DL_HAS_CONNINFRA_DRV (0)
#endif

#define GPS_DL_HAS_PLAT_DRV   (1)
#define GPS_DL_HAS_PTA        (1)
#define GPS_DL_USE_TIA        (0)
#define GPS_DL_USE_TOP_EMI_REQ_FOR_TIA (1) /* Only set to 1 for MT6885/MT6893 */
#define GPS_DL_USE_BGF_SEL_SEMA (0)

#define GPS_DL_IS_MODULE      (1)

#define GPS_DL_USE_MTK_SYNC_WRITE    (1)
#define GPS_DL_SET_EMI_MPU_CFG       (1)
#define GPS_DL_GET_RSV_MEM_IN_MODULE (0)

#define GPS_DL_EMI_MPU_DOMAIN_AP      (0)
#define GPS_DL_EMI_MPU_DOMAIN_CONN    (2)
#define GPS_DL_EMI_MPU_REGION_NUM     (29)

#include "gps_dl_log.h"

#endif /* _GPS_DL_CONFIG_H */

