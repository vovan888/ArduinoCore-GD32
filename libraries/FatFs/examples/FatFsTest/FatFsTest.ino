#include "Arduino.h"
#include "FatFs.h"
#include "usbh_msc_core.h"
#include "usbh_usr.h"

// Select Tools->USB Support->USB Host

FATFS FatFs;      /* FatFs work area needed for each volume */
FIL file;         /* File object needed for each open file */

static bool user_app_runs = false;

void test_fatfs() {
  UINT bytes_written = 0;
  FRESULT fr;

  Serial2.println("USB file write test");

  fr = f_open(&file, "newfile.txt", FA_WRITE | FA_CREATE_ALWAYS);  /* Create a file */
  if (fr != FR_OK) {
    Serial2.print("File open error ");
    Serial2.println(fr);
  } else {
    fr = f_write(&file, "It works!\r\n", 11, &bytes_written);        /* Write data to the file */
    if (fr != FR_OK) {
      Serial2.print("File write error ");
      Serial2.println(fr);
    }
    fr = f_close(&file);                                                     /* Close the file */
    if (fr == FR_OK && bytes_written == 11) {          /* Lights green LED if data written well */
      Serial2.println("File written OK");
    } else {
      Serial2.print("File close error ");
      Serial2.println(fr);
    }
  }
}

void setup() {
  delay(1000);
  Serial2.begin(19200);

  Serial2.println("FatFsTest");

  // Do not access USB in setup(), it is not ready yet
}

void loop() {
  // put your main code here, to run repeatedly:

  static bool loop_entered = false;
  if (!loop_entered) {
    Serial2.println("loop()");
    loop_entered = true;
  }

  static bool test_done = false;

  if (user_app_runs && !test_done) {
    // try to mount default drive
    if (f_mount(&FatFs, "", 0) == FR_OK) {
      test_fatfs();
      test_done = true;
    }
  }
}

// The functions below can be safely removed
// except for usbh_usr_msc_application()

/*!
    \brief      user operation for host-mode initialization
    \param[in]  none
    \param[out] none
    \retval     none
*/
void usbh_user_init(void)
{
  Serial2.println("usbh_user_init");
}

/*!
    \brief      user operation for device attached
    \param[in]  none
    \param[out] none
    \retval     none
*/
void usbh_user_device_connected(void)
{
  Serial2.println("usbh_user_device_connected");
}

/*!
    \brief      user operation when unrecoveredError happens
    \param[in]  none
    \param[out] none
    \retval     none
*/
void usbh_user_unrecovered_error(void)
{
  Serial2.println("usbh_user_unrecovered_error");
}

/*!
    \brief      user operation for device disconnect event
    \param[in]  none
    \param[out] none
    \retval     none
*/
void usbh_user_device_disconnected(void)
{
  Serial2.println("usbh_user_device_disconnected");
}

/*!
    \brief      user operation for reset USB Device
    \param[in]  none
    \param[out] none
    \retval     none
*/
void usbh_user_device_reset(void)
{
  Serial2.println("usbh_user_device_reset");
}

/*!
    \brief      user operation for detectting device speed
    \param[in]  device_speed: device speed
    \param[out] none
    \retval     none
*/
void usbh_user_device_speed_detected(uint32_t device_speed)
{
  Serial2.println("usbh_user_device_speed_detected");
}

/*!
    \brief      user operation when device descriptor is available
    \param[in]  device_desc: device descriptor
    \param[out] none
    \retval     none
*/
void usbh_user_device_desc_available(void *device_desc)
{
  Serial2.println("usbh_user_device_desc_available");
}

/*!
    \brief      usb device is successfully assigned the Address
    \param[in]  none
    \param[out] none
    \retval     none
*/
void usbh_user_device_address_assigned(void)
{
  Serial2.println("usbh_user_device_address_assigned");
}

/*!
    \brief      user operation when configuration descriptor is available
    \param[in]  cfg_desc: pointer to configuration descriptor
    \param[in]  itf_desc: pointer to interface descriptor
    \param[in]  ep_desc: pointer to endpoint descriptor
    \param[out] none
    \retval     none
*/
void usbh_user_configuration_descavailable(usb_desc_config *cfg_desc,
    usb_desc_itf *itf_desc,
    usb_desc_ep *ep_desc)
{
  Serial2.println("usbh_user_configuration_descavailable");
}

/*!
    \brief      user operation when manufacturer string exists
    \param[in]  manufacturer_string: manufacturer string of usb device
    \param[out] none
    \retval     none
*/
void usbh_user_manufacturer_string(void *manufacturer_string)
{
  Serial2.print("usbh_user_manufacturer_string: ");
  Serial2.println((char *)manufacturer_string);
}

/*!
    \brief      user operation when product string exists
    \param[in]  product_string: product string of usb device
    \param[out] none
    \retval     none
*/
void usbh_user_product_string(void *product_string)
{
  Serial2.print("usbh_user_product_string: ");
  Serial2.println((char *)product_string);
}

/*!
    \brief      user operatin when serialNum string exists
    \param[in]  serial_num_string: serialNum string of usb device
    \param[out] none
    \retval     none
*/
void usbh_user_serialnum_string(void *serial_num_string)
{
  Serial2.print("usbh_user_serialnum_string: ");
  Serial2.println((char *)serial_num_string);
}

/*!
    \brief      user response request is displayed to ask for application jump to class
    \param[in]  none
    \param[out] none
    \retval     none
*/
void usbh_user_enumeration_finish(void)
{
  Serial2.println("usbh_user_enumeration_finish");
}

/*!
    \brief      user operation when device is not supported
    \param[in]  none
    \param[out] none
    \retval     none
*/
void usbh_user_device_not_supported(void)
{
  Serial2.println("usbh_user_device_not_supported");
}

/*!
    \brief      user action for application state entry
    \param[in]  none
    \param[out] none
    \retval     user response for user key
*/
usbh_user_status usbh_user_userinput(void)
{
  Serial2.println("usbh_user_userinput");
  return USBH_USER_RESP_OK;
}

/*!
    \brief      user operation for device overcurrent detection event
    \param[in]  none
    \param[out] none
    \retval     none
*/
void usbh_user_over_current_detected(void)
{
  Serial2.println("usbh_user_over_current_detected");
}

/*!
    \brief      demo application for mass storage
    \param[in]  pudev: pointer to device
    \param[in]  id: no use here
    \param[out] none
    \retval     status
*/
int usbh_usr_msc_application(void)
{
//  Serial2.println("usbh_usr_msc_application");
  user_app_runs = true;
  return 0;
}

/*!
    \brief      deinit user state and associated variables
    \param[in]  none
    \param[out] none
    \retval     none
*/
void usbh_user_deinit(void)
{
  Serial2.println("usbh_user_deinit");
}
