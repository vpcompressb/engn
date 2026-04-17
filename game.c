////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// keywords.

#define restrict __restrict
#define inline static inline __attribute__((always_inline))
#define alignas(a) __attribute__((aligned(a)))
#define typeof(a) __typeof__(a)
#define assert(a) ({if((a)==0)__builtin_debugtrap();})

#define NIL (0U)
#define INV (~NIL)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// types.

typedef void                    V;
typedef unsigned char          UB;
typedef unsigned short         UH;
typedef unsigned int           UW;
typedef unsigned long long int UL;
typedef UB                      B;
typedef UH                      H;
typedef UW                      W;
typedef UL                      L;
#define TR_(t,o) ((t *restrict)(o))
#define TV_(t,o) ((t volatile*)(o))

typedef L (*C0)();
typedef L (*C1)(L);
typedef L (*C2)(L,L);
typedef L (*C3)(L,L,L);
typedef L (*C4)(L,L,L,L);
typedef L (*C5)(L,L,L,L,L);
typedef L (*C6)(L,L,L,L,L,L);
typedef L (*C7)(L,L,L,L,L,L,L);
#define C0_( a) ((C0)(a))
#define C1_( a) ((C1)(a))
#define C2_( a) ((C2)(a))
#define C3_( a) ((C3)(a))
#define C4_( a) ((C4)(a))
#define C5_( a) ((C5)(a))
#define C6_( a) ((C6)(a))
#define C7_( a) ((C7)(a))
#define C0L_(a) (C0_(a)(L_(a)))
#define C1L_(a) (C1_(a)(L_(a),L_(a)))
#define C2L_(a) (C2_(a)(L_(a),L_(a),L_(a)))
#define C3L_(a) (C3_(a)(L_(a),L_(a),L_(a),L_(a)))
#define C4L_(a) (C4_(a)(L_(a),L_(a),L_(a),L_(a),L_(a)))
#define C5L_(a) (C5_(a)(L_(a),L_(a),L_(a),L_(a),L_(a),L_(a)))
#define C6L_(a) (C6_(a)(L_(a),L_(a),L_(a),L_(a),L_(a),L_(a),L_(a)))
#define C7L_(a) (C7_(a)(L_(a),L_(a),L_(a),L_(a),L_(a),L_(a),L_(a),L_(a)))

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// constants.

#define CORE_COUNT_MAX          4U // 
#define TIME_RANK      1000000000U // 
#define TICK_RATE               8U // 
#define TICK_SPAN         7812500U // = TIME_RANK / TICK_RATE
#define DISK_RATE        33554432U // = 4 GB / TICK_RATE
#define PAGE_ALIGN_MAX       4096U // 
#define LINE_ALIGN_MAX         64U // 
#define COUNT_MAX_DEFAULT      32U // 

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// procedures imports.

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// operations.

inline V  PAUSE(V){__asm__ volatile("pause":::"memory");}
inline UL CLOCK(V){UL c;QueryPerformanceCounter((PLARGE_INTEGER)&c);return c;}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// callbacks.

#if defined(_WIN32)
static L window_message_callback(L window,W message,L w_param,L l_param);
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// statics.

#define NAME "ENGN"
static B const name[]=NAME;

//
// BOT
//
// data used during initialization.
typedef struct
{
  // platform
#if defined(_WIN32)
alignas(LINE_ALIGN_MAX)
  struct
  {
    W cbSize;
    W style;
    L lpfnWndProc;
    W cbClsExtra;
    W cbWndExtra;
    L hInstance;
    L hIcon;
    L hCursor;
    L hbrBackground;
    L lpszMenuName;
    L lpszClassName;
    L hIconSm;
  } window_class; // WNDCLASSEXA
  struct
  {
    L x;
    L y;
  } window_cursor_point; // POINT
  L window_monitor; // HMONITOR
  struct
  {
    W cbSize;
    struct
    {
      L left;
      L top;
      L right;
      L bottom;
    } rcMonitor;
    struct
    {
      L left;
      L top;
      L right;
      L bottom;
    } rcWork;
  } window_monitor_info; // MONITORINFOEXA
  L window; // HWND
  struct
  {
    H usUsagePage;
    H usUsage;
    W dwFlags;
    L hwndTarget;
  } window_raw_input_device; // RAWINPUTDEVICE
  struct
  {
    L hwnd;
    W message;
    L wParam;
    L lParam;
    W time;
    struct
    {
      L x;
      L y;
    } pt;
    W lPrivate;
  } window_message; // MSG
  L window_message_result; // LRESULT
  struct
  {
    struct
    {
      W dwType;
      W dwSize;
      L hDevice;
      L wParam;
    } header;
    struct
    {
      H MakeCode;
      H Flags;
      H Reserved;
      H VKey;
      W Message;
      L ExtraInformation;
    } data;
  } window_raw_input_keyboard; // RAWINPUT
  W window_raw_input_size;
#elif defined(__unix__)
  // TODO: UNIX platforms
#endif

// Vulkan
alignas(LINE_ALIGN_MAX)
  L vk; // HMODULE
  struct
  {
    W sType;
    L pNext;
    L pApplicationName;
    W applicationVersion;
    L pEngineName;
    W engineVersion;
    W apiVersion;
  } vk_application_info; // VkApplicationInfo
#define VK_INSTANCE_ENABLED_LAYER_COUNT 1U
  L vk_instance_enabled_layer_name_array[VK_INSTANCE_ENABLED_LAYER_COUNT]; // UTF8
#define VK_INSTANCE_ENABLED_EXTENSION_COUNT 2U
  L vk_instance_enabled_extension_name_array[VK_INSTANCE_ENABLED_EXTENSION_COUNT]; // UTF8
  struct
  {
    W sType;
    L pNext;
    W flags;
    L pApplicationInfo;
    W enabledLayerCount;
    L ppEnabledLayerNames;
    W enabledExtensionCount;
    L ppEnabledExtensionNames;
  } vk_instance_create_info; // VkInstanceCreateInfo
  L vk_instance; // VkInstance
  W vk_physical_device_count; // uint32_t
#define VK_DEVICE_ENABLED_EXTENSION_COUNT 1U
  L vk_physical_device_array[VK_DEVICE_ENABLED_EXTENSION_COUNT]; // VkPhysicalDevice
#define VK_PHYSICAL_DEVICE_COUNT_MAX COUNT_MAX_DEFAULT
  struct
  {
    W apiVersion;
    W driverVersion;
    W vendorID;
    W deviceID;
    W deviceType;
#define VK_PHYSICAL_DEVICE_NAME_SIZE_MAX 256U
    B deviceName[VK_PHYSICAL_DEVICE_NAME_SIZE_MAX];
#define VK_UUID_SIZE 16U
    B pipelineCacheUUID[VK_UUID_SIZE];
    struct
    {
      W maxImageDimension1D;
      W maxImageDimension2D;
      W maxImageDimension3D;
      W maxImageDimensionCube;
      W maxImageArrayLayers;
      W maxTexelBufferElements;
      W maxUniformBufferRange;
      W maxStorageBufferRange;
      W maxPushConstantsSize;
      W maxMemoryAllocationCount;
      W maxSamplerAllocationCount;
      L bufferImageGranularity;
      L sparseAddressSpaceSize;
      W maxBoundDescriptorSets;
      W maxPerStageDescriptorSamplers;
      W maxPerStageDescriptorUniformBuffers;
      W maxPerStageDescriptorStorageBuffers;
      W maxPerStageDescriptorSampledImages;
      W maxPerStageDescriptorStorageImages;
      W maxPerStageDescriptorInputAttachments;
      W maxPerStageResources;
      W maxDescriptorSetSamplers;
      W maxDescriptorSetUniformBuffers;
      W maxDescriptorSetUniformBuffersDynamic;
      W maxDescriptorSetStorageBuffers;
      W maxDescriptorSetStorageBuffersDynamic;
      W maxDescriptorSetSampledImages;
      W maxDescriptorSetStorageImages;
      W maxDescriptorSetInputAttachments;
      W maxVertexInputAttributes;
      W maxVertexInputBindings;
      W maxVertexInputAttributeOffset;
      W maxVertexInputBindingStride;
      W maxVertexOutputComponents;
      W maxTessellationGenerationLevel;
      W maxTessellationPatchSize;
      W maxTessellationControlPerVertexInputComponents;
      W maxTessellationControlPerVertexOutputComponents;
      W maxTessellationControlPerPatchOutputComponents;
      W maxTessellationControlTotalOutputComponents;
      W maxTessellationEvaluationInputComponents;
      W maxTessellationEvaluationOutputComponents;
      W maxGeometryShaderInvocations;
      W maxGeometryInputComponents;
      W maxGeometryOutputComponents;
      W maxGeometryOutputVertices;
      W maxGeometryTotalOutputComponents;
      W maxFragmentInputComponents;
      W maxFragmentOutputAttachments;
      W maxFragmentDualSrcAttachments;
      W maxFragmentCombinedOutputResources;
      W maxComputeSharedMemorySize;
      W maxComputeWorkGroupCount[3];
      W maxComputeWorkGroupInvocations;
      W maxComputeWorkGroupSize[3];
      W subPixelPrecisionBits;
      W subTexelPrecisionBits;
      W mipmapPrecisionBits;
      W maxDrawIndexedIndexValue;
      W maxDrawIndirectCount;
      W maxSamplerLodBias;
      W maxSamplerAnisotropy;
      W maxViewports;
      W maxViewportDimensions[2];
      W viewportBoundsRange[2];
      W viewportSubPixelBits;
      L minMemoryMapAlignment;
      L minTexelBufferOffsetAlignment;
      L minUniformBufferOffsetAlignment;
      L minStorageBufferOffsetAlignment;
      W minTexelOffset;
      W maxTexelOffset;
      W minTexelGatherOffset;
      W maxTexelGatherOffset;
      W minInterpolationOffset;
      W maxInterpolationOffset;
      W subPixelInterpolationOffsetBits;
      W maxFramebufferWidth;
      W maxFramebufferHeight;
      W maxFramebufferLayers;
      W framebufferColorSampleCounts;
      W framebufferDepthSampleCounts;
      W framebufferStencilSampleCounts;
      W framebufferNoAttachmentsSampleCounts;
      W maxColorAttachments;
      W sampledImageColorSampleCounts;
      W sampledImageIntegerSampleCounts;
      W sampledImageDepthSampleCounts;
      W sampledImageStencilSampleCounts;
      W storageImageSampleCounts;
      W maxSampleMaskWords;
      W timestampComputeAndGraphics;
      W timestampPeriod;
      W maxClipDistances;
      W maxCullDistances;
      W maxCombinedClipAndCullDistances;
      W discreteQueuePriorities;
      W pointSizeRange[2];
      W lineWidthRange[2];
      W pointSizeGranularity;
      W lineWidthGranularity;
      W strictLines;
      W standardSampleLocations;
      L optimalBufferCopyOffsetAlignment;
      L optimalBufferCopyRowPitchAlignment;
      L nonCoherentAtomSize;
    } limits; // VkPhysicalDeviceLimits
    struct
    {
      W residencyStandard2DBlockShape;
      W residencyStandard2DMultisampleBlockShape;
      W residencyStandard3DBlockShape;
      W residencyAlignedMipSize;
      W residencyNonResidentStrict;
    } sparseProperties; // VkPhysicalDeviceSparseProperties
  } vk_physical_device_properties_array[VK_PHYSICAL_DEVICE_COUNT_MAX]; // VkPhysicalDeviceProperties
  W vk_queue_priority; // VkPhysicalDeviceProperties2
  struct
  {
    W sType;
    L pNext;
    W flags;
    W queueFamilyIndex;
    W queueCount;
    L pQueuePriorities;
  } vk_device_queue_create_info; // VkDeviceQueueCreateInfo
#define VK_DEVICE_ENABLED_EXTENSION_COUNT_MAX COUNT_MAX_DEFAULT
  L vk_device_enabled_extension_name_array[VK_DEVICE_ENABLED_EXTENSION_COUNT_MAX]; // UTF8
  struct
  {
    W sType;
    L pNext;
    W flags;
    W queueCreateInfoCount;
    L pQueueCreateInfos;
    W enabledLayerCount;
    L ppEnabledLayerNames;
    W enabledExtensionCount;
    L ppEnabledExtensionNames;
    L pEnabledFeatures;
  } vk_device_create_info; // VkDeviceCreateInfo
  L vk_device; // VkDeviceCreateInfo
  L vk_queue; // VkQueue
} BOT;
static BOT bot_=
{
  // platform
#if defined(_WIN32)
  .window_class.cbSize                =sizeof(bot_.window_class),
  .window_class.lpfnWndProc           =&window_message_callback,
  .window_class.lpszClassName         =name,
  .window_monitor_info.cbSize         =sizeof(bot_.window_monitor_info),
  .window_raw_input_device.usUsagePage=0x01 /* HID_USAGE_GENERIC */,
  .window_raw_input_device.usUsage    =0x06 /* HID_USAGE_GENERIC_KEYBOARD */,
  .window_raw_input_device.dwFlags    =0x030|0x200 /*RIDEV_NOLEGACY|RIDEV_NOHOTKEYS */,
  .window_raw_input_size              =sizeof(bot_.window_raw_input_keyboard),
#elif defined(__unix__)
  // TODO: UNIX platforms.
#endif

  // Vulkan
  .vk_application_info.sType                      =VK_STRUCTURE_TYPE_APPLICATION_INFO,
  .vk_application_info.apiVersion                 =((((W)(0))<<29U)|(((W)(1))<<22U)|(((W)(2))<<12U)|((W)(0))),
  .vk_instance_enabled_layer_name_array           ={"VK_LAYER_KHRONOS_validation"},
  .vk_instance_enabled_extension_name_array       ={"VK_KHR_surface","VK_KHR_WIN32_surface"},
  .vk_instance_create_info.sType                  =VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
  .vk_instance_create_info.pApplicationInfo       =&bot_.vk_application_info,
  .vk_instance_create_info.enabledLayerCount      =VK_INSTANCE_ENABLED_LAYER_COUNT,
  .vk_instance_create_info.ppEnabledLayerNames    =bot_.vk_instance_enabled_layer_name_array,
  .vk_instance_create_info.enabledExtensionCount  =VK_INSTANCE_ENABLED_EXTENSION_COUNT,
  .vk_instance_create_info.ppEnabledExtensionNames=bot_.vk_instance_enabled_extension_name_array,
  .vk_physical_device_count                       =VK_PHYSICAL_DEVICE_COUNT_MAX,
  .vk_queue_priority                              =1.f,
  .vk_device_queue_create_info.sType              =VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,
  .vk_device_queue_create_info.queueFamilyIndex   =INV,
#define VK_QUEUE_COUNT 1U
  .vk_device_queue_create_info.queueCount         =VK_QUEUE_COUNT,
  .vk_device_queue_create_info.pQueuePriorities   =&bot_.vk_queue_priority,
  .vk_device_enabled_extension_name_array         ={"VK_KHR_swapchain"},
  .vk_device_create_info.sType                    =VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
  .vk_device_create_info.queueCreateInfoCount     =VK_QUEUE_COUNT,
  .vk_device_create_info.pQueueCreateInfos        =&bot_.vk_device_queue_create_info,
  .vk_device_create_info.enabledExtensionCount    =VK_DEVICE_ENABLED_EXTENSION_COUNT,
  .vk_device_create_info.ppEnabledExtensionNames  =bot_.vk_device_enabled_extension_name_array,
};
#define bot_r TR_(BOT,&bot_)
#define bot_v TV_(BOT,&bot_)

typedef struct
{
alignas(LINE_ALIGN_MAX)
#define SYNC_COUNT_MAX 2U
  W sync_count;
  L time_scale;
  L tick_clock;
  L tick_count;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // message loop data.
  //
  // 256 B = 4 CL
  //
alignas(LINE_ALIGN_MAX)
  L window; // HWND
  struct
  {
    L hwnd;
    W message;
    L wParam;
    L lParam;
    W time;
    struct
    {
      L x;
      L y;
    } pt;
    W lPrivate;
  } window_message; // MSG
  L window_message_result; // LRESULT
  struct
  {
    struct
    {
      W dwType;
      W dwSize;
      L hDevice;
      L wParam;
    } header;
    struct
    {
      H MakeCode;
      H Flags;
      H Reserved;
      H VKey;
      W Message;
      L ExtraInformation;
    } data;
  } window_raw_input_keyboard; // RAWINPUT
  W window_raw_input_size; // DWORD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // render loop code.

alignas(LINE_ALIGN_MAX)
  // TODO: ...

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // render loop data.
  //
  // 256 B = 4 CL
  //
alignas(LINE_ALIGN_MAX)
  L vk_device; // VkDevice
  L vk_semaphore; // VkSemaphore
  struct
  {
    W sType;
    L pNext;
    W flags;
    L pInheritanceInfo;
  } vk_command_buffer_begin_info; // VkCommandBufferBeginInfo
  L vk_command_buffer; // VkCommandBuffer
  L vk_swapchain; // VkSwapchainKHR
  L vk_pipeline; // VkPipeline
  L vk_pipeline_layout; // VkPipelineLayout
  L vk_descriptor_set; // VkDescriptorSet
  W vk_dispatch_group_count; // uint32_t
  L vk_queue; // VkQueue
  struct
  {
    W sType;
    L pNext;
    W waitSemaphoreCount;
    L pWaitSemaphores;
    L pWaitDstStageMask;
    W commandBufferCount;
    L pCommandBuffers;
    W signalSemaphoreCount;
    L pSignalSemaphores;
  } vk_submit_info; // VkSubmitInfo
  struct
  {
    W sType;
    L pNext;
    W waitSemaphoreCount;
    L pWaitSemaphores;
    W swapchainCount;
    L pSwapchains;
    L pImageIndices;
    L pResults;
  } vk_present_info; // VkPresentInfoKHR
} RAM;
static RAM ram_;
#define ram_r TR_(RAM,&ram_)
#define ram_v TV_(RAM,&ram_)

// global sync
inline V SYNC(V){ram_v->sync_count+=1;while(ram_v->sync_count!=SYNC_COUNT_MAX)PAUSE();}

L window_message_callback(L window_,W message_,L w_param_,L l_param_)
{
  register L window =window_;
  register W message=message_;
  register L w_param=w_param_;
  register L l_param=l_param_;

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
      // TODO: this is temporary. later on we should pass the input data to the GPU.
      switch(ram_r->window_raw_input.data.keyboard.VKey)
      {
      case VK_ESCAPE:
        DestroyWindow(window);
        break;
      default:
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

alignas(PAGE_ALIGN_MAX) static V game_1(V)
{
  register UW i;

  // load libraries and procedures here.
  {
    register HMODULE vk;
    vk=LoadLibraryA("vulkan-1");
    assert(vk!=NULL);
#define F_(NAME_) ram_r->NAME_=(void*)GetProcAddress(vk,#NAME_);assert(ram_r->NAME_!=NULL);
    VK_PROCEDURE_NAME_TABLE_MACRO(F_)
#undef F_
    bot_r->vk=vk;
  }

  // initialize thread settings.
  SetThreadPriority(GetCurrentThread(),THREAD_PRIORITY_TIME_CRITICAL);

  // create the Vulkan device.
  register VkInstance       vk_instance;
  register VkPhysicalDevice vk_physical_device;
  register VkDevice         vk_device;
  ram_r->vkCreateInstance(&bot_r->vk_instance_create_info,0,&bot_r->vk_instance);
  vk_instance=bot_r->vk_instance;
  ram_r->vkEnumeratePhysicalDevices(vk_instance,&bot_r->vk_physical_device_count,bot_r->vk_physical_device_array);
#define VK_PHYSICAL_DEVICE_INDEX_DEFAULT 0U
  vk_physical_device=bot_r->vk_physical_device_array[VK_PHYSICAL_DEVICE_INDEX_DEFAULT];
  ram_r->vkCreateDevice(vk_physical_device,&bot_r->vk_device_create_info,0,&bot_r->vk_device);
  vk_device=bot_r->vk_device;

  // TODO: define resources here.

  // create the swapchain.

  // TODO: use VK_PRESENT_MODE_MAILBOX_KHR

  for(i=0;i<bot_r->vk_physical_device_count;i+=1)
  {
    bot_r->vk_physical_device_properties_array[i].sType=VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2;
    vkGetPhysicalDeviceProperties2(bot_r->vk_physical_device_array[i],&bot_r->vk_physical_device_properties_array[i]);
  }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  // TODO: record command buffers here before the end of initialization.

  // end initialization.
  SYNC();                    // wait for all threads to finish initialization.
  ram_r->tick_clock=CLOCK(); // begin tick timer.

  // render loop.
  for(;;)
  {
    #if 0
    // acquire the swapchain image now before transfering data to the GPU.
    // use a semaphore for this since `vkQueuePresentKHR` waits for it at the end of the tick.
    vkAcquireNextImageKHR();

    // TODO: transfer data to GPU here.

    vkFlushMappedMemoryRanges();

    vkResetFences();
    vkQueueSubmit();
    vkWaitForFences();
    vkQueuePresentKHR();

    // a lot of free time here since presentation is currently occuring.
    #endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // sync to next tick.
    //
    // the tick ends here since all rendered and available data should now be available.

    {
      register UL tS,tR,tD;
      tS=ram_r->tick_clock;tR=ram_r->time_scale;          // cache data.
      do{PAUSE();tD=CLOCK();}while((tD-tS)*tR<TICK_SPAN); // wait until the tick ends.
      ram_r->tick_clock =tD;                              // the next tick starts here.
      ram_r->tick_count+=1;                               // commit the tick.
    }
  }

  return;
}

extern L LoadLibraryA(  L);
extern L GetProcAddress(L,L);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// game_0
alignas(PAGE_ALIGN_MAX) V game_0(V)
{
  // TODO: query CPU and RAM info at the immediate start.

  bot_r->kernel32_dll=LoadLibraryA("kernel32.dll");

  // initialize platform settings.
  SetPriorityClass(GetCurrentProcess(),REALTIME_PRIORITY_CLASS);
  QueryPerformanceFrequency((PLARGE_INTEGER)&ram_r->time_scale);
  ram_r->time_scale=TIME_RANK/ram_r->time_scale;

  // launch the render thread.
  CreateThread(0,0,(LPTHREAD_START_ROUTINE)&game_1,0,0,0);

  // create a window that covers the entire monitor that the cursor is on.
  bot_r->window_class.hInstance=GetModuleHandleA(0);
  bot_r->window_class.hCursor  =LoadCursorA(0,IDC_ARROW);
  RegisterClassExA(&bot_r->window_class);
  GetCursorPos(&bot_r->window_cursor_point);
  bot_r->window_monitor=MonitorFromPoint(bot_r->window_cursor_point,MONITOR_DEFAULTTONEAREST);
  GetMonitorInfoA(bot_r->window_monitor,(LPMONITORINFO)&bot_r->window_monitor_info);
  ram_r->window=CreateWindowExA(WS_EX_APPWINDOW,name,name,WS_VISIBLE|WS_POPUP|WS_CLIPSIBLINGS|WS_CLIPCHILDREN,bot_r->window_monitor_info.rcMonitor.left,bot_r->window_monitor_info.rcMonitor.top,bot_r->window_monitor_info.rcMonitor.right-bot_r->window_monitor_info.rcMonitor.left,bot_r->window_monitor_info.rcMonitor.bottom-bot_r->window_monitor_info.rcMonitor.top,0,0,bot_r->window_class.hInstance,0);

  // enable raw input.
  bot_r->window_raw_input_device.hwndTarget=ram_r->window;
  RegisterRawInputDevices(&bot_r->window_raw_input_device,1,sizeof(bot_r->window_raw_input_device));

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  // TODO: destroy temporary initialization data and code.
  SYNC();

  // message loop.
  while(GetMessageA(&ram_r->window_message,0,0,0)>0)DispatchMessageA(&ram_r->window_message);

  SYNC();

  // TODO: save game state into disk here.

  ExitProcess(0);

  return;
}
