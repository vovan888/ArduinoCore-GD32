
#include "usb.h"

#if defined(USE_HOST_MODE) || defined(USE_DEVICE_MODE)

#include "drv_usb_hw.h"
#include "usbh_core.h"
#include "usbh_usr.h"
#include "usbh_msc_core.h"
#include "drv_usbh_int.h"

usbh_host usb_host = {0};
extern usbh_user_cb usr_cb;
extern usb_core_driver usbh_core;

#if defined (GD32F20x)

/*!
    \brief      this function handles USBD interrupt
    \param[in]  none
    \param[out] none
    \retval     none
*/
void USBFS_IRQHandler(void)
{
    usbh_isr(&usbh_core);
}

#endif // GD32F20x

#endif // USE_HOST_MODE || USE_DEVICE_MODE

void usb_init(void)
{
#if defined(USE_HOST_MODE) || defined(USE_DEVICE_MODE)
    usb_rcu_config();

//    usb_timer_init();

    /* configure GPIO pin used for switching VBUS power and charge pump I/O */
    usb_vbus_config();

#if defined(USE_HOST_MODE)
    usbh_class_register(&usb_host, &usbh_msc);

    /* initialize host library */
    usbh_init(&usb_host, &usr_cb);
#endif

    /* enable interrupts */
    usb_intr_config();
#endif
}


void usb_task(void)
{
#if defined(USE_HOST_MODE)
    usbh_core_task(&usb_host);
#endif
}


#if defined(USE_HOST_MODE) || defined(USE_DEVICE_MODE)
#include "drv_usb_core.c"
#endif

#if defined(USE_DEVICE_MODE)
#include "drv_usb_dev.c"
#include "drv_usbd_int.c"

// TODO
#endif

#if defined(USE_HOST_MODE)
#include "drv_usb_host.c"
#include "drv_usbh_int.c"

#include "usbh_msc_bbb.c"
#include "usbh_msc_core.c"
//#include "usbh_msc_fatfs.c"
#include "usbh_msc_scsi.c"

#include "usbh_core.c"
#include "usbh_enum.c"
#include "usbh_pipe.c"
#include "usbh_transc.c"
#endif
