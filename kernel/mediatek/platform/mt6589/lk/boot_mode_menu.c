/*This file implements MTK boot mode.*/

#include <sys/types.h>
#include <debug.h>
#include <err.h>
#include <reg.h>

#include <platform/mt_typedefs.h>
#include <platform/boot_mode.h>
#include <platform/mt_reg_base.h>
#include <platform/mtk_key.h>

#include <target/cust_key.h>

#define MODULE_NAME "[BOOT_MENU]"
extern char g_CMDLINE [];
bool g_boot_menu = false;

void boot_mode_menu_select()
{
          int select = 0;  // 0=recovery mode, 1=fastboot.  2=normal boot
          const char* title_msg = "Select Boot Mode:\n[VOLUME UP/DOWN to move.  POWER to select.]\n\n";
          video_clean_screen();
          video_set_cursor(video_get_rows()/3, 0);
          video_printf(title_msg);
#if (defined(MTK_NCP1851_SUPPORT) || defined(MTK_BQ24196_SUPPORT))
                         mt_disp_power(TRUE);
#endif
#if (defined(MTK_NCP1851_SUPPORT) || defined(MTK_BQ24196_SUPPORT))
                         mt65xx_backlight_on();
#endif

//MTK modify  121106+
			    video_printf("[Please select below mode to enter...] <<==\n");
                            video_printf("  [Reboot system now.................]     \n");
                            video_printf("  [Apply update from external storage]     \n");
                            video_printf("  [Wipe data/factory reset...........]     \n");
		            video_printf("  [Demo Mode.........................]     \n");
//MTK -
          while(1)
          {
             if(mtk_detect_key(MT65XX_BOOT_MENU_KEY))//VOL_UP
             {
                    g_boot_menu = true;
                    switch(select) {

                        case 0:
#ifdef MTK_FASTBOOT_SUPPORT
                            select = 0;

                            video_set_cursor(video_get_rows()/3, 0);
                            video_printf(title_msg);
//MTK modify 121108 +
			    video_printf("[Please select below mode to enter...] <<==\n");
                            video_printf("  [Reboot system now.................]     \n");
                            video_printf("  [Apply update from external storage]     \n");
                            video_printf("  [Wipe data/factory reset...........]     \n");
		            video_printf("  [Demo Mode.........................]     \n");
//MTK modify 121108 -
                        break;
#endif
                        case 1:
                            select = 0;

                            video_set_cursor(video_get_rows()/3, 0);
                            video_printf(title_msg);
//MTK modifu 121108 +
			    video_printf("[Please select below mode to enter...] <<==\n");
                            video_printf("  [Reboot system now.................]     \n");
                            video_printf("  [Apply update from external storage]     \n");
                            video_printf("  [Wipe data/factory reset...........]     \n");
		            video_printf("  [Demo Mode.........................]     \n");
//MTK -
                        break;

                        case 2:
                            select = 1;
    
                            video_set_cursor(video_get_rows()/3, 0);
                            video_printf(title_msg);
//MTK modifu 121108 +
			    video_printf("[Please select below mode to enter...]     \n");
                            video_printf("  [Reboot system now.................] <<==\n");
                            video_printf("  [Apply update from external storage]     \n");
                            video_printf("  [Wipe data/factory reset...........]     \n");
		            video_printf("  [Demo Mode.........................]     \n");
//MTK -
                        break;

                        case 3:
                            select = 2;


                            video_set_cursor(video_get_rows()/3, 0);
                            video_printf(title_msg);
//MTK modifu 121108 +
			    video_printf("[Please select below mode to enter...]     \n");
                            video_printf("  [Reboot system now.................]     \n");
                            video_printf("  [Apply update from external storage] <<==\n");
                            video_printf("  [Wipe data/factory reset...........]     \n");
		            video_printf("  [Demo Mode.........................]     \n");
//MTK -
                        break;

                        case 4:
                            select = 3;
    
                            video_set_cursor(video_get_rows()/3, 0);
                            video_printf(title_msg);
			    video_printf("[Please select below mode to enter...]     \n");
                            video_printf("  [Reboot system now.................]     \n");
                            video_printf("  [Apply update from external storage]     \n");
                            video_printf("  [Wipe data/factory reset...........] <<==\n");
		            video_printf("  [Demo Mode.........................]     \n");
//MTK -
                        break;
                        default: 
                        break;
                    }
                    dprintf(0,  "[Power]Key Detect, current select:%d\n", select);
                    mdelay(300);
             }
             if(mtk_detect_key(1))//VOL_DOWN
             {
                    g_boot_menu = true;
                    switch(select) {

                        case 0:

                            select = 1;

                            video_set_cursor(video_get_rows()/3, 0);
                            video_printf(title_msg);
//MTK modify 121108 +
			    video_printf("[Please select below mode to enter...]     \n");
                            video_printf("  [Reboot system now.................] <<==\n");
                            video_printf("  [Apply update from external storage]     \n");
                            video_printf("  [Wipe data/factory reset...........]     \n");
		            video_printf("  [Demo Mode.........................]     \n");
//MTK modify 121108 -
                        break;

                        case 1:
                            select = 2;

                            video_set_cursor(video_get_rows()/3, 0);
                            video_printf(title_msg);
//MTK modifu 121108 +
			    video_printf("[Please select below mode to enter...]     \n");
                            video_printf("  [Reboot system now.................]     \n");
                            video_printf("  [Apply update from external storage] <<==\n");
                            video_printf("  [Wipe data/factory reset...........]     \n");
		            video_printf("  [Demo Mode.........................]     \n");
//MTK -
                        break;

                        case 2:
                            select = 3;
    
                            video_set_cursor(video_get_rows()/3, 0);
                            video_printf(title_msg);
//MTK modifu 121108 +
			    video_printf("[Please select below mode to enter...]     \n");
                            video_printf("  [Reboot system now.................]     \n");
                            video_printf("  [Apply update from external storage]     \n");
                            video_printf("  [Wipe data/factory reset...........] <<==\n");
		            video_printf("  [Demo Mode.........................]     \n");
//MTK -
                        break;

                        case 3:
                            select = 4;
    
                            video_set_cursor(video_get_rows()/3, 0);
                            video_printf(title_msg);
//MTK modifu 121108 +
			    video_printf("[Please select below mode to enter...]     \n");
                            video_printf("  [Reboot system now.................]     \n");
                            video_printf("  [Apply update from external storage]     \n");
                            video_printf("  [Wipe data/factory reset...........]     \n");
		            video_printf("  [Demo Mode.........................] <<==\n");
                        break;
                        case 4:
                            select = 4;
                            
                            video_set_cursor(video_get_rows()/3, 0);
                            video_printf(title_msg);
//MTK modifu 121108 +
			    video_printf("[Please select below mode to enter...]     \n");
                            video_printf("  [Reboot system now.................]     \n");
                            video_printf("  [Apply update from external storage]     \n");
                            video_printf("  [Wipe data/factory reset...........]     \n");
		            video_printf("  [Demo Mode.........................] <<==\n");
                        break;

                        default: 
                        break;
                    }
                    dprintf(0,  "[Power]Key Detect, current select:%d\n", select);
                    mdelay(300);
             }

             else if(mtk_detect_key(8) && select!=0)//POWER,
             {
                 //use for OK
                 break;
             }
             else
             {
                //pass
             }
          }
          if(select == 1)
          {
               g_boot_mode = RECOVERY_BOOT;
		g_demo_boot_mode = 2;
          }
          else if(select == 2)
          {
               g_boot_mode = RECOVERY_BOOT;
		g_demo_boot_mode = 3;
//                g_boot_mode = FASTBOOT;
          }
          else if(select == 3)
          {
               g_boot_mode = RECOVERY_BOOT;
		g_demo_boot_mode = 4;
//                g_boot_mode = NORMAL_BOOT;
          }
          else if(select == 4)
          {
                g_boot_mode = NORMAL_BOOT;
		g_demo_boot_mode = 1;
          }
          else
          {
                //pass
          }
          video_set_cursor(video_get_rows()/3 +8, 0);
          return;
}

BOOL boot_menu_key_trigger(void)
{
#if 1
	//wait
    ulong begin = get_timer(0);
    printf("\n%s Check  boot menu\n",MODULE_NAME);
    printf("%s Wait 50ms for special keys\n",MODULE_NAME);

    //let some case of recovery mode pass.
    if(unshield_recovery_detection())
    {
        return TRUE;
    }

    while(get_timer(begin)<50)
    {
		if(mtk_detect_key(MT65XX_BOOT_MENU_KEY))
		{
                           mtk_wdt_disable();
                           boot_mode_menu_select();
                           mtk_wdt_init();
                           return TRUE;
		}
    }
#endif
     return FALSE;
}

BOOL boot_menu_detection(void)
{
    return boot_menu_key_trigger();
}


int unshield_recovery_detection(void)
{
    //because recovery_check_command_trigger's BOOL is different from the BOOL in this file.
    //so use code like this type.
    return recovery_check_command_trigger()? TRUE:FALSE;
}

