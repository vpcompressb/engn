section .data

	align	32
SYSTEM_LIBRARY_NAME_vulkan:
	db	"vulkan-1.dll",0
	align	32
SYSTEM_LIBRARY_PROCEDURE_NAME_vkGetInstanceProcAddr:
	db	"vkGetInstanceProcAddr",0
	align	32
SYSTEM_LIBRARY_PROCEDURE_NAME_vkCreateInstance:
	db	"vkCreateInstance",0

	align	8
vkGetInstanceProcAddr:
	dq	0
	align	8
vkCreateInstance:
	dq	0


	align	8
VULKAN_INSTANCE_CREATE_INFO:
	dq 	1                                            ; sType
	dq 	0                                            ; pNext
	dd 	0                                            ; flags
	dd 	0
	dq 	0                                            ; pApplicationInfo
	dd 	VULKAN_INSTANCE_LAYER_COUNT                  ; enabledLayerCount
	dd 	0
	dq 	VULKAN_INSTANCE_LAYER_NAME_POINTER_ARRAY     ; ppEnabledLayerNames
	dd 	VULKAN_INSTANCE_EXTENSION_COUNT              ; enabledExtensionCount
	dd 	0
	dq 	VULKAN_INSTANCE_EXTENSION_NAME_POINTER_ARRAY ; ppEnabledExtensionNames

	align	32
VULKAN_INSTANCE_LAYER_NAME_ARRAY:
	db	"VK_LAYER_KHRONOS_validation",0
VULKAN_INSTANCE_LAYER_COUNT equ 1
	align	8
VULKAN_INSTANCE_LAYER_NAME_POINTER_ARRAY:
	dq	VULKAN_INSTANCE_LAYER_NAME_ARRAY+0*32

	align	32
VULKAN_INSTANCE_EXTENSION_NAME_ARRAY:
	db	"VK_KHR_surface",0
	align	32
	db	"VK_KHR_win32_surface",0
VULKAN_INSTANCE_EXTENSION_COUNT equ 2
	align	8
VULKAN_INSTANCE_EXTENSION_NAME_POINTER_ARRAY:
	dq	VULKAN_INSTANCE_EXTENSION_NAME_ARRAY+0*32
	dq	VULKAN_INSTANCE_EXTENSION_NAME_ARRAY+1*32
	align	8
VULKAN_INSTANCE:
	dq	0

VULKAN_STRING_ALIGNMENT equ 32
	align	VULKAN_STRING_ALIGNMENT
VULKAN_INSTANCE_PROCEDURE_NAME_ARRAY:
	db	"vkEnumeratePhysicalDevices"
	align	VULKAN_STRING_ALIGNMENT
	db	"vkCreateDevice"
	align	VULKAN_STRING_ALIGNMENT
	db	"vkCreateShaderModule"
	align	VULKAN_STRING_ALIGNMENT

section .text

extern LoadLibraryA
extern GetProcAddress

global ENTRY

ENTRY:
	sub	rsp,40

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	; load "vulkan-1.dll".
	lea	rcx,[rel SYSTEM_LIBRARY_NAME_vulkan]
	call	LoadLibraryA

	; load "vkGetInstanceProcAddr".
	mov	rcx,rax
	lea	rdx,[rel SYSTEM_LIBRARY_PROCEDURE_NAME_vkGetInstanceProcAddr]
	call	GetProcAddress
	mov	[rel vkGetInstanceProcAddr],rax

	; load "vkCreateInstance".
	xor	rcx,rcx
	lea	rdx,[rel SYSTEM_LIBRARY_PROCEDURE_NAME_vkCreateInstance]
	call	[rel vkGetInstanceProcAddr]
	mov	[rel vkCreateInstance],rax

	; create the `VkInstance`.
	lea	rcx,[rel VULKAN_INSTANCE_CREATE_INFO]
	xor	rdx,rdx
	lea	r8,[rel VULKAN_INSTANCE]
	call	[rel vkCreateInstance]


	; load Vulkan procedures.
	xor	r12d,r12d ; r12d is the procedure index.
.VULKAN_LOAD_INSTANCE_PROCEDURE:
	mov	rcx,[rel VULKAN_INSTANCE]
	mov	r13d,r12d
	shl	r13d,VULKAN_STRING_ALIGNMENT_SHIFT
	lea	rdx,[rel VULKAN_INSTANCE_PROCEDURE_NAME_ARRAY+r13d]
	call	[rel vkGetInstanceProcAddr]
	mov	[rel VULKAN_PROCEDURE_POINTER_ARRAY+r12d*W64_ALIGNMENT],rax
	inc	r12d
	cmp	r12d,VULKAN_INSTANCE_PROCEDURE_COUNT
	je	.VULKAN_LOAD_INSTANCE_PROCEDURE

	; VkPhysicalDevice
	; VkDevice
	; VkQueue
	; VkCommandBuffer
	; VkCommandPool
	; VkSemaphore
	; VkEvent
	; VkShaderModule
	; VkPipeline
	; VkDeviceMemory
	; VkBuffer
	; VkBufferView
	; VkImage
	; VkImageView
	; VkSampler
	; VkDescriptorSetLayout
	; VkPipelineLayout
	; VkDescriptorPool
	; VkDescriptorSet
	; VkQueryPool
	; VkSurfaceKHR
	; VkSwapchainKHR

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	add	rsp,40
	ret
