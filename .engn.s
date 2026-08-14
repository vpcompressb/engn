    section .data

    STRING_ALIGNMENT equ 32
         B_ALIGNMENT equ  1
         W_ALIGNMENT equ  2
         D_ALIGNMENT equ  4
         Q_ALIGNMENT equ  8
         C_ALIGNMENT equ 64
    STRING_ALIGNMENT_SHIFT equ 5

section .bss

    align C_ALIGNMENT
    SCRATCH_SIZE_BYTE equ 4096
SCRATCH:
    resb SCRATCH_SIZE_BYTE

    section .data


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    align STRING_ALIGNMENT
VULKAN_LIBRARY_NAME:
    db "vulkan-1.dll",0
    align STRING_ALIGNMENT
VULKAN_LIBRARY_PROCEDURE_NAME_vkGetInstanceProcAddr:
    db "vkGetInstanceProcAddr",0
    align STRING_ALIGNMENT
VULKAN_INSTANCE_PROCEDURE_NAME_vkCreateInstance:
    db "vkCreateInstance",0

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    align Q_ALIGNMENT
vkCreateInstance:
    dq 0
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
    align Q_ALIGNMENT
VULKAN_INSTANCE:
    dq 0

    ; Vulkan instance layers.
    align STRING_ALIGNMENT 
VULKAN_INSTANCE_LAYER_NAME_ARRAY:
    db "VK_LAYER_KHRONOS_validation",0
VULKAN_INSTANCE_LAYER_COUNT equ 1
    align Q_ALIGNMENT
VULKAN_INSTANCE_LAYER_NAME_POINTER_ARRAY:
    dq VULKAN_INSTANCE_LAYER_NAME_ARRAY+0*STRING_ALIGNMENT

    ; Vulkan instance extensions.
    align STRING_ALIGNMENT
VULKAN_INSTANCE_EXTENSION_NAME_ARRAY:
    db "VK_KHR_surface",0
    align STRING_ALIGNMENT
    db "VK_KHR_win32_surface",0
VULKAN_INSTANCE_EXTENSION_COUNT equ 2
    align Q_ALIGNMENT
VULKAN_INSTANCE_EXTENSION_NAME_POINTER_ARRAY:
    dq VULKAN_INSTANCE_EXTENSION_NAME_ARRAY+0*STRING_ALIGNMENT
    align Q_ALIGNMENT
    dq VULKAN_INSTANCE_EXTENSION_NAME_ARRAY+1*STRING_ALIGNMENT
    align Q_ALIGNMENT

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    align Q_ALIGNMENT
vkGetInstanceProcAddr:
    dq 0
    align STRING_ALIGNMENT
VULKAN_INSTANCE_PROCEDURE_NAME_ARRAY: ; WARNING: ENSURE THAT THE SIZE OF EACH ENTRY OF THIS ARRAY IS `STRING_ALIGNMENT`.
    db "vkEnumeratePhysicalDevices",0
    align STRING_ALIGNMENT
    db "vkCreateDevice",0
    align STRING_ALIGNMENT
    db "vkCreateSaderModule",0
VULKAN_INSTANCE_PROCEDURE_COUNT equ 3

%if 0
    align Q_ALIGNMENT
VULKAN_INSTANCE_1:
    dq 0
    align Q_ALIGNMENT
vkEnumeratePhysicalDevices:
    dq 0
VULKAN_PHYSICAL_DEVICE_COUNT_MAX equ 4
    align Q_ALIGNMENT
VULKAN_PHYSICAL_DEVICE_COUNT:
    dq VULKAN_PHYSICAL_DEVICE_COUNT_MAX
    align Q_ALIGNMENT
VULKAN_PHYSICAL_DEVICE_ARRAY:
    times VULKAN_PHYSICAL_DEVICE_COUNT_MAX dq 0

    align Q_ALIGNMENT
VULKAN_PHYSICAL_DEVICE_0:
    dq 0
    align Q_ALIGNMENT
vkCreateDevice:
    dq 0
    align Q_ALIGNMENT
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
    align Q_ALIGNMENT
VULKAN_QUEUE_CREATE_INFO:
    dq 2                           ; sType
    dq 0                           ; pNext
    dd 0                           ; flags
    dd VULKAN_QUEUE_FAMILY_INDEX   ; queueFamilyIndex
    dd VULKAN_QUEUE_COUNT          ; queueCount
    dd 0
    dq VULKAN_QUEUE_PRIORITY_ARRAY ; pQueuePriorities
    align D_ALIGNMENT
VULKAN_QUEUE_PRIORITY_ARRAY:
    dd 1.0
VULKAN_DEVICE_EXTENSION_COUNT equ 1
    align STRING_ALIGNMENT
VULKAN_DEVICE_EXTENSION_NAME_ARRAY:
    db "VK_KHR_swapchain",0
    align Q_ALIGNMENT
VULKAN_DEVICE_EXTENSION_NAME_POINTER_ARRAY:
    dq VULKAN_DEVICE_EXTENSION_NAME_ARRAY+0*STRING_ALIGNMENT

    align Q_ALIGNMENT
VULKAN_DEVICE_0:
    dq 0
    align Q_ALIGNMENT
vkCreateShaderModule: ; TODO
    dq 0
    align Q_ALIGNMENT
VULKAN_SHADER_MODULE_CREATE_INFO:
    dd 16                             ; sType
    dd 0
    dq 0                              ; pNext
    dd 0                              ; flags
    dd 0
    dd VULKAN_SHADER_MODULE_CODE_SIZE ; codeSize
    dd 0
    dq VULKAN_SHADER_MODULE_CODE      ; pCode

VULKAN_SHADER_MODULE_CODE_SIZE equ VULKAN_SHADER_MODULE_CODE_END-VULKAN_SHADER_MODULE_CODE
    align STRING_ALIGNMENT
VULKAN_SHADER_MODULE_CODE:
    incbin "engn.spv"
VULKAN_SHADER_MODULE_CODE_END:

    align Q_ALIGNMENT
VULKAN_DEVICE_1:
    dq 0
    align Q_ALIGNMENT
VULKAN_DESCRIPTOR_SET_LAYOUT_CREATE_INFO:
    dd 32                                         ; sType
    dd 0
    dq 0                                          ; pNext
    dd 0                                          ; flags
    dd 0
    dd VULKAN_DESCRIPTOR_SET_LAYOUT_BINDING_COUNT ; bindingCount
    dd 0
    dq VULKAN_DESCRIPTOR_SET_LAYOUT_BINDING_ARRAY ; pBindings
VULKAN_DESCRIPTOR_SET_LAYOUT_BINDING_COUNT equ 1
    align Q_ALIGNMENT
VULKAN_DESCRIPTOR_SET_LAYOUT_BINDING_ARRAY:
    dq 0          ; binding
    dq 7          ; descriptorType
    dq 1          ; descriptorCount
    dq 0x00000020 ; stageFlags = VK_SHADER_STAGE_COMPUTE_BIT
    dq 0          ; pImmutableSamplers

    align Q_ALIGNMENT
VULKAN_DEVICE_2:
    dq 0
    align Q_ALIGNMENT
vkCreatePipelineLayout:
    dq 0
    align Q_ALIGNMENT
VULKAN_PIPELINE_LAYOUT_CREATE_INFO:
    dq 30                           ; sType
    dq 0                            ; pNext
    dq 0                            ; flags
    dq 1                            ; setLayoutCount
    dq VULKAN_DESCRIPTOR_SET_LAYOUT ; pSetLayouts
    dq 0                            ; pushConstantRangeCount
    dq 0                            ; pPushContantRanges
    align Q_ALIGNMENT
VULKAN_DESCRIPTOR_SET_LAYOUT:
    dq 0

    align Q_ALIGNMENT
VULKAN_DEVICE_3:
    dq 0
    align Q_ALIGNMENT
vkCreateComputePipelines:
    dq 0
    align Q_ALIGNMENT
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
    align Q_ALIGNMENT
VULKAN_SHADER_STAGE_NAME:
    db "main",0
%endif

    section .text

    extern LoadLibraryA
    extern GetProcAddress


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    ; `ENGN` is the entry point of this program,
    ; so it must be exposed globally for the linker to recognize it.
    global ENGN

    ; the code of `ENGN` should be aligned by a cache line.
    align C_ALIGNMENT

ENGN:

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ; Win32 requires the stack to reserve 32 bytes plus a 16 byte alignment
    ; padding.

    sub rsp,40

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    ; load "vulkan-1.dll" via the external static Win32 procedure `LoadLibraryA`.
    lea  rcx,[rel VULKAN_LIBRARY_NAME] ; lpLibFileName
    call LoadLibraryA
    mov  rcx,rax
    ; load `vkGetInstanceProc` from "vulkan-1.dll".
    lea  rdx,[rel VULKAN_LIBRARY_PROCEDURE_NAME_vkGetInstanceProcAddr] ; lpProcName
    call GetProcAddress
    mov  [rel vkGetInstanceProcAddr_0],rax
    mov  [rel vkGetInstanceProcAddr_1],rax
    ; load `vkCreateInstance` from "vulkan-1.dll".
    xor  rcx,rcx                                                  ; instance
    lea  rdx,[rel VULKAN_LIBRARY_PROCEDURE_NAME_vkCreateInstance] ; pName
    call [rel vkGetInstanceProcAddr_0]
    mov  [rel vkCreateInstance],rax

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    ; create the `VkInstance`.
    lea  rcx,[rel VULKAN_INSTANCE_CREATE_INFO] ; pCreateInfo
    xor  rdx,rdx                               ; pAllocator
    lea  r8 ,[rel VULKAN_INSTANCE_0]           ; pInstance
    call [rel vkCreateInstance]
    mov  rax,[rel VULKAN_INSTANCE_0]
    mov  [rel VULKAN_INSTANCE_1],rax

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    ; initialize the loop's iteration index (`r12d`) to 0.
    xor r12d,r12d

.LOOP_VULKAN_LOAD_INSTANCE_PROCEDURE:

    ; ...
    mov rcx,[VULKAN_INSTANCE] ; instance

    ; load the procedure's name from an array of `STRING_ALIGNMENT` (32) byte
    ; strides. `r12d` is translated from byte increments to `STRING_ALIGNMENT`
    ; increments via a left-shift of `STRING_ALIGNMENT_SHIFT` (5).
    mov r13d,r12d
    shl r13d,STRING_ALIGNMENT_SHIFT
    lea rdx,[VULKAN_INSTANCE_PROCEDURE_NAME_ARRAY+r13d] ; pName

    ; ...
    call [vkGetInstanceProcAddr_1]

    ; store the procedure pointer into an array of qword strides.  
    mov [SCRATCH+r12d*Q_ALIGNMENT],rax

    ; end the loop.
    inc r12d
    cmp r12d,VULKAN_INSTANCE_PROCEDURE_COUNT
    je .LOOP_VULKAN_LOAD_INSTANCE_PROCEDURE

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

%if 0

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
%endif
