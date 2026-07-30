    default rel

    section .data

    align 8
LIBRARY_NAME_VULKAN:
    db "vulkan-1.dll",0
    align 8
LIBRARY_VULKAN:
    dq 0
    align 8
LIBRARY_SYMBOL_vkGetInstanceProcAddr:
    db "vkGetInstanceProcAddr",0
    align 8
vkGetInstanceProcAddr_0:
    dq 0
    align 8
LIBRARY_SYMBOL_vkCreateInstance:
    db "vkCreateInstance",0

    align 8
vkCreateInstance:
    dq 0
VULKAN_INSTANCE_LAYER_COUNT equ 1
    align 8
VULKAN_INSTANCE_LAYER_NAME_ARRAY:
    db "VK_LAYER_KHRONOS_validation",0
    align 8
VULKAN_INSTANCE_LAYER_NAME_POINTER_ARRAY:
    dq VULKAN_INSTANCE_LAYER_NAME_ARRAY+0
VULKAN_INSTANCE_EXTENSION_COUNT equ 2
    align 8
VULKAN_INSTANCE_EXTENSION_NAME_ARRAY:
    db "VK_KHR_surface",0
    align 8
    db "VK_KHR_win32_surface",0
    align 8
VULKAN_INSTANCE_EXTENSION_NAME_POINTER_ARRAY:
    dq VULKAN_INSTANCE_EXTENSION_NAME_ARRAY+0
    align 8
    dq VULKAN_INSTANCE_EXTENSION_NAME_ARRAY+32
    align 8
VULKAN_INSTANCE_CREATE_INFO:
    dq 1                                            ; sType
    dq 0                                            ; pNext
    dd 0                                            ; flags
    dd 0
    dq 0                                            ; pApplicationInfo
    dd VULKAN_INSTANCE_LAYER_COUNT                  ; enabledLayerCount
    dd 0
    dq VULKAN_INSTANCE_LAYER_NAME_POINTER_ARRAY     ; ppEnabledLayerNames
    dd VULKAN_INSTANCE_EXTENSION_COUNT              ; enabledExtensionCount
    dd 0
    dq VULKAN_INSTANCE_EXTENSION_NAME_POINTER_ARRAY ; ppEnabledExtensionNames

    align 8
VULKAN_INSTANCE_0:
    dq 0
    align 8
vkGetInstanceProcAddr_1:
    dq 0
    align 8
LIBRARY_SYMBOL_vkEnumeratePhysicalDevices:
    db "vkEnumeratePhysicalDevices",0
    align 8
LIBRARY_SYMBOL_vkCreateDevice:
    db "vkCreateDevice",0

    align 8
VULKAN_INSTANCE_1:
    dq 0
    align 8
vkEnumeratePhysicalDevices:
    dq 0
VULKAN_PHYSICAL_DEVICE_COUNT_MAX equ 4
    align 8
VULKAN_PHYSICAL_DEVICE_COUNT:
    dq VULKAN_PHYSICAL_DEVICE_COUNT_MAX
    align 8
VULKAN_PHYSICAL_DEVICE_ARRAY:
    times VULKAN_PHYSICAL_DEVICE_COUNT_MAX dq 0

    align 8
VULKAN_PHYSICAL_DEVICE_0:
    dq 0
    align 8
vkCreateDevice:
    dq 0
    align 8
VULKAN_DEVICE_CREATE_INFO:
    dq 3                                          ; sType
    dq 0                                          ; pNext
    dd 0                                          ; flags
    dd 1                                          ; queueCreateInfoCount
    dq VULKAN_QUEUE_CREATE_INFO                   ; pQueueCreateInfos
    dd 0                                          ; enabledLayerCount
    dd 0
    dq 0                                          ; ppEnabledLayerNames
    dd VULKAN_DEVICE_EXTENSION_COUNT              ; enabledExtensionCount
    dd 0
    dq VULKAN_DEVICE_EXTENSION_NAME_POINTER_ARRAY ; ppEnabledExtensionNames
    dq 0                                          ; pEnabledFeatures
VULKAN_QUEUE_FAMILY_INDEX equ 0
VULKAN_QUEUE_COUNT        equ 1
    align 8
VULKAN_QUEUE_CREATE_INFO:
    dq 2                           ; sType
    dq 0                           ; pNext
    dd 0                           ; flags
    dd VULKAN_QUEUE_FAMILY_INDEX   ; queueFamilyIndex
    dd VULKAN_QUEUE_COUNT          ; queueCount
    dd 0
    dq VULKAN_QUEUE_PRIORITY_ARRAY ; pQueuePriorities
    align 4
VULKAN_QUEUE_PRIORITY_ARRAY:
    dd 1.0
VULKAN_DEVICE_EXTENSION_COUNT equ 1
    align 8
VULKAN_DEVICE_EXTENSION_NAME_ARRAY:
    db "VK_KHR_swapchain",0
    align 8
VULKAN_DEVICE_EXTENSION_NAME_POINTER_ARRAY:
    dq VULKAN_DEVICE_EXTENSION_NAME_ARRAY+0

    align 8
VULKAN_DEVICE_0:
    dq 0
    align 8
vkCreateShaderModule: ; TODO
    dq 0
    align 8
VULKAN_SHADER_MODULE_CREATE_INFO:
    dq 16                             ; sType
    dq 0                              ; pNext
    dq 0                              ; flags
    dq VULKAN_SHADER_MODULE_CODE_SIZE ; codeSize
    dq VULKAN_SHADER_MODULE_CODE      ; pCode

VULKAN_SHADER_MODULE_CODE_SIZE equ 0
    align 8
VULKAN_SHADER_MODULE_CODE:
    dq 0

    align 8
VULKAN_DEVICE_1:
    dq 0
    align 8
VULKAN_DESCRIPTOR_SET_LAYOUT_CREATE_INFO:
    dq 32                                         ; sType
    dq 0                                          ; pNext
    dq 0                                          ; flags
    dq VULKAN_DESCRIPTOR_SET_LAYOUT_BINDING_COUNT ; bindingCount
    dq VULKAN_DESCRIPTOR_SET_LAYOUT_BINDING_ARRAY ; pBindings
VULKAN_DESCRIPTOR_SET_LAYOUT_BINDING_COUNT equ 1
    align 8
VULKAN_DESCRIPTOR_SET_LAYOUT_BINDING_ARRAY:
    dq 0          ; binding
    dq 7          ; descriptorType
    dq 1          ; descriptorCount
    dq 0x00000020 ; stageFlags
    dq 0          ; pImmutableSamplers

    align 8
VULKAN_DEVICE_2:
    dq 0
    align 8
vkCreatePipelineLayout:
    dq 0
    align 8
VULKAN_PIPELINE_LAYOUT_CREATE_INFO:
    dq 30                           ; sType
    dq 0                            ; pNext
    dq 0                            ; flags
    dq 1                            ; setLayoutCount
    dq VULKAN_DESCRIPTOR_SET_LAYOUT ; pSetLayouts
    dq 0                            ; pushConstantRangeCount
    dq 0                            ; pPushContantRanges
    align 8
VULKAN_DESCRIPTOR_SET_LAYOUT:
    dq 0

    align 8
VULKAN_DEVICE_3:
    dq 0
    align 8
vkCreateComputePipelines:
    dq 0
    align 8
VULKAN_PIPELINE_CREATE_INFO:
    dq 29                       ; sType
    dq 0                        ; pNext
    dq 0                        ; flags
    dq 18                       ; stage.sType
    dq 0                        ; stage.pNext
    dq 0                        ; stage.flags
    dq 0x00000020               ; stage.stage = VK_SHADER_STAGE_COMPUTE_BIT
VULKAN_SHADER_MODULE:
    dq 0                        ; stage.module
    dq VULKAN_SHADER_STAGE_NAME ; stage.pName
    dq 0                        ; stage.pSpecializationInfo
VULKAN_PIPELINE_LAYOUT:
    dq 0                        ; layout
    dq 0                        ; basePipelineHandle
    dq 0                        ; basePipelineIndex
    align 8
VULKAN_SHADER_STAGE_NAME:
    db "main",0

    section .text

    extern LoadLibraryA
    extern GetProcAddress

    global ENGN
    align 64
ENGN:
    sub rsp,40

    ; Load "vulkan-1.dll".
    ; vulkan_1_dll=LoadLibraryA("vulkan-1.dll")
    lea  rcx,[LIBRARY_NAME_VULKAN]
    call LoadLibraryA
    mov  [LIBRARY_VULKAN],rax
    mov  rcx,rax

    ; Load routines from "vulkan-1.dll".
    ; vkGetInstanceProcAddr=GetProcAddress(vulkan_dll,"vkGetInstanceProcAddr")
    lea  rdx,[LIBRARY_SYMBOL_vkGetInstanceProcAddr] ; lpProcName
    call GetProcAddress
    mov  [vkGetInstanceProcAddr_0],rax
    mov  [vkGetInstanceProcAddr_1],rax
    ; vkCreateInstance=vkGetInstanceProcAddr(VK_NULL_HANDLE,"vkCreateInstance")
    xor  rcx,rcx                               ; instance
    lea  rdx,[LIBRARY_SYMBOL_vkCreateInstance] ; pName
    call [vkGetInstanceProcAddr_0]
    mov  [vkCreateInstance],rax

    ; Create the Vulkan instance.
    ; vkCreateInstance(VkInstaceCreateInfo,VK_NULL_HANDLE,VkInstance)
    lea  rcx,[VULKAN_INSTANCE_CREATE_INFO] ; pCreateInfo
    xor  rdx,rdx                           ; pAllocator
    lea  r8 ,[VULKAN_INSTANCE_0]           ; pInstance
    call [vkCreateInstance]
    mov  rax,[VULKAN_INSTANCE_0]
    mov  [VULKAN_INSTANCE_1],rax

    ; vkEnumeratePhysicalDevices=vkGetInstanceProcAddr(VkInstance,"vkEnumeratePhysicalDevices")
    mov  rcx,[VULKAN_INSTANCE_0]                         ; instance
    lea  rdx,[LIBRARY_SYMBOL_vkEnumeratePhysicalDevices] ; pName
    call [vkGetInstanceProcAddr_1]
    mov  [vkEnumeratePhysicalDevices],rax
    ; vkCreateDevice=vkGetInstanceProcAddr(VkInstance,"vkCreateDevice")
    mov  rcx,[VULKAN_INSTANCE_0]             ; instance
    lea  rdx,[LIBRARY_SYMBOL_vkCreateDevice] ; pName
    call [vkGetInstanceProcAddr_1]
    mov  [vkCreateDevice],rax

    ; vkEnumeratePhysicalDevices
    mov  rcx,[VULKAN_INSTANCE_1]            ; instance
    lea  rdx,[VULKAN_PHYSICAL_DEVICE_COUNT] ; pPhysicalDeviceCount
    lea  r8 ,[VULKAN_PHYSICAL_DEVICE_ARRAY] ; pPhysicalDevices
    call [vkEnumeratePhysicalDevices]
    mov  rax,[VULKAN_PHYSICAL_DEVICE_ARRAY]
    mov  [VULKAN_PHYSICAL_DEVICE_0],rax

    ; vkCreateDevice
    mov  rcx,[VULKAN_PHYSICAL_DEVICE_0]  ; physicalDevice
    lea  rdx,[VULKAN_DEVICE_CREATE_INFO] ; pCreateInfo
    xor  r8 ,r8                          ; pAllocator
    lea  r9 ,[VULKAN_DEVICE_0]           ; pDevice
    call [vkCreateDevice]
    mov  rax,[VULKAN_DEVICE_0]
    mov  [VULKAN_DEVICE_1],rax
    mov  [VULKAN_DEVICE_2],rax
    mov  [VULKAN_DEVICE_3],rax

    ; vkCreateComputePipelines

    add rsp,40
    ret
