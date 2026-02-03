#include<Windows.h>
#include<hidusage.h>

#define VK_USE_PLATFORM_WIN32_KHR
#include<vulkan/vulkan.h>

#define restrict __restrict

typedef unsigned char UB;
typedef unsigned int  UW;

#define TR_(type, object) ((         type *restrict)(object))
#define TV_(type, object) ((volatile type *        )(object))

#define DEFAULT_MAX_COUNT 32U

#define NAME "ENGN"
static const char name[]=NAME;

static LRESULT CALLBACK window_message_callback(HWND window,UINT message,WPARAM w_param,LPARAM l_param);

typedef struct
{
#ifdef _WIN32
__declspec(align(64))
  WNDCLASSEXA    window_class;
  MONITORINFOEXA window_monitor_info;
  HWND           window;
  RAWINPUTDEVICE window_raw_input_device;
  MSG            window_message;
  LRESULT        window_message_result;
  RAWINPUT       window_raw_input;
  UINT           window_raw_input_size;
#endif

__declspec(align(64))
  VkApplicationInfo    vk_application_info;
  char           const*vk_instance_enabled_layer_name_array[DEFAULT_MAX_COUNT];
  char           const*vk_instance_enabled_extension_name_array[DEFAULT_MAX_COUNT];
  VkInstanceCreateInfo vk_instance_create_info;
  VkInstance           vk_instance;
}
RAM;
static RAM ram_=
{
  .window_class           ={.cbSize=sizeof(ram_.window_class),.lpfnWndProc=&window_message_callback,.lpszClassName=name},
  .window_monitor_info    ={.cbSize=sizeof(ram_.window_monitor_info)},
  .window_raw_input_device={.usUsagePage=HID_USAGE_PAGE_GENERIC,.usUsage=HID_USAGE_GENERIC_KEYBOARD,.dwFlags=RIDEV_NOLEGACY|RIDEV_NOHOTKEYS},
  .window_raw_input_size  =sizeof(ram_.window_raw_input),

  .vk_application_info                     ={.sType=VK_STRUCTURE_TYPE_APPLICATION_INFO,.apiVersion=VK_API_VERSION_1_3},
  .vk_instance_enabled_layer_name_array    ={"VK_LAYER_KHRONOS_validation"},
  .vk_instance_enabled_extension_name_array={VK_KHR_SURFACE_EXTENSION_NAME,VK_KHR_WIN32_SURFACE_EXTENSION_NAME,VK_KHR_SWAPCHAIN_EXTENSION_NAME},
  .vk_instance_create_info                 ={.sType=VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,.pApplicationInfo=&ram_.vk_application_info,.enabledLayerCount=1,.ppEnabledLayerNames=ram_.vk_instance_enabled_layer_name_array,.enabledExtensionCount=3,.ppEnabledExtensionNames=ram_.vk_instance_enabled_extension_name_array}
};
#define ram_r TR_(RAM,&ram_)
#define ram_v TV_(RAM,&ram_)

LRESULT window_message_callback(HWND window,UINT message,WPARAM w_param,LPARAM l_param)
{
  switch(message)
  {
  case WM_CREATE:
    ShowWindow(window,SW_SHOW);
    SetForegroundWindow(window);
    SetFocus(window);
    break;
  case WM_INPUT:
    if(GetRawInputData((HRAWINPUT)l_param,RID_INPUT,&ram_r->window_raw_input,&ram_r->window_raw_input_size,sizeof(ram_r->window_raw_input.header))>0)
    {
      switch(ram_r->window_raw_input.data.keyboard.VKey)
      {
      case VK_ESCAPE:
        DestroyWindow(window);
        break;
      }
    }
    break;
  case WM_CLOSE:
    DestroyWindow(window);
    break;
  case WM_DESTROY:
    PostQuitMessage(0);
    break;
  case WM_ACTIVATEAPP:
    if(w_param==TRUE)SetThreadPriority(GetCurrentThread(),THREAD_PRIORITY_LOWEST       );
    else             SetThreadPriority(GetCurrentThread(),THREAD_PRIORITY_TIME_CRITICAL);
    break;
  default:
    ram_r->window_message_result=DefWindowProcA(window,message,w_param,l_param);
    break;
  }
  return ram_r->window_message_result;
}

void engn_1(void)
{
  SetThreadPriority(GetCurrentThread(),THREAD_PRIORITY_TIME_CRITICAL);

  vkCreateInstance(&ram_r->vk_instance_create_info,0,&ram_r->vk_instance);

}

void engn(void)
{
  SetPriorityClass(GetCurrentProcess(),REALTIME_PRIORITY_CLASS);
  CreateThread(0,0,(LPTHREAD_START_ROUTINE)&engn_1,0,0,0);

  ram_r->window_class.hInstance=GetModuleHandleA(0);
  ram_r->window_class.hCursor  =LoadCursorA(0,IDC_ARROW);
  RegisterClassExA(&ram_r->window_class);

  GetMonitorInfoA(MonitorFromWindow(GetDesktopWindow(),MONITOR_DEFAULTTOPRIMARY),(LPMONITORINFO)&ram_r->window_monitor_info);
  ram_r->window=CreateWindowExA(WS_EX_APPWINDOW,name,name,WS_VISIBLE|WS_POPUP|WS_CLIPSIBLINGS|WS_CLIPCHILDREN,ram_r->window_monitor_info.rcMonitor.left,ram_r->window_monitor_info.rcMonitor.top,ram_r->window_monitor_info.rcMonitor.right-ram_r->window_monitor_info.rcMonitor.left,ram_r->window_monitor_info.rcMonitor.bottom-ram_r->window_monitor_info.rcMonitor.top,0,0,ram_r->window_class.hInstance,0);

  ram_r->window_raw_input_device.hwndTarget=ram_r->window;
  RegisterRawInputDevices(&ram_r->window_raw_input_device,1,sizeof(ram_r->window_raw_input_device));

  while(GetMessageA(&ram_r->window_message,0,0,0)>0)DispatchMessageA(&ram_r->window_message);

  return;
}