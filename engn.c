#define ALIGN_(alignment) __declspec(align(alignment))

typedef void                   W0;
typedef unsigned char          W1;
typedef unsigned short int     W2;
typedef unsigned int           W3;
typedef unsigned long long int W4;

typedef W4 (*C0)(W0);
typedef W4 (*C1)(W4);
typedef W4 (*C2)(W4,W4);
typedef W4 (*C3)(W4,W4,W4);

#define STRING_SIZE_T1  8U
#define STRING_SIZE_T2 16U
#define STRING_SIZE_T3 32U

struct MEM
{
ALIGN_(64)
    W1 vulkan_library_name[STRING_SIZE_T2];
    W4 vulkan_library;
    W1 vulkan_routine_name_create_instance[STRING_SIZE_T3];

ALIGN_(64)
    C3 vulkan_create_instance;

ALIGN_(64)
#define VULKAN_INSTANCE_LAYER_ENABLED_COUNT 1U
    W1 vulkan_instance_layer_enabled_array[VULKAN_INSTANCE_LAYER_ENABLED_COUNT][STRING_SIZE_T3];
    W4 vulkan_instance_layer_enabled_pointer_array[VULKAN_INSTANCE_LAYER_ENABLED_COUNT];
#define VULKAN_INSTANCE_EXTENSION_ENABLED_COUNT 2U
    W1 vulkan_instance_extension_enabled_array[VULKAN_INSTANCE_EXTENSION_ENABLED_COUNT][STRING_SIZE_T3];
    W4 vulkan_instance_extension_enabled_pointer_array[VULKAN_INSTANCE_EXTENSION_ENABLED_COUNT];

ALIGN_(64)
#define VULKAN_STRUCTURE_TYPE_INSTANCE_CREATE_INFO 1U
    W3 vulkan_instance_struct_type;
    W3 padding_0;
    W4 vulkan_instance_struct_next_pointer;
    W3 vulkan_instance_struct_flags;
    W3 padding_1;
    W4 vulkan_instance_application_info_pointer;
    W3 vulkan_instance_layer_enabled_count;
    W3 padding_2;
    W4 vulkan_instance_layer_enabled_pointer_array_pointer;
    W3 vulkan_instance_extension_enabled_count;
    W3 padding_3;
    W4 vulkan_instance_extension_enabled_pointer_array_pointer;

ALIGN_(64)
    W4 vulkan_instance;
};
static struct MEM mem=
{
    .vulkan_library_name                ="vulkan-1.dll",
    .vulkan_routine_name_create_instance="vkCreateInstance",

    .vulkan_instance_layer_enabled_array=
    {
        [0]="VK_LAYER_KHRONOS_validation",
    },
    .vulkan_instance_layer_enabled_pointer_array=
    {
        [0]=(W4)&mem.vulkan_instance_layer_enabled_array[0],
    },
    .vulkan_instance_extension_enabled_array=
    {
        [0]="VK_KHR_surface",
        [1]="VK_KHR_win32_surface",
    },
    .vulkan_instance_extension_enabled_pointer_array=
    {
        [0]=(W4)&mem.vulkan_instance_extension_enabled_array[0],
        [1]=(W4)&mem.vulkan_instance_extension_enabled_array[1],
    },

    .vulkan_instance_struct_type                            =VULKAN_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
    .vulkan_instance_layer_enabled_count                    =VULKAN_INSTANCE_LAYER_ENABLED_COUNT,
    .vulkan_instance_layer_enabled_pointer_array_pointer    =(W4)&mem.vulkan_instance_layer_enabled_pointer_array,
    .vulkan_instance_extension_enabled_count                =VULKAN_INSTANCE_EXTENSION_ENABLED_COUNT,
    .vulkan_instance_extension_enabled_pointer_array_pointer=(W4)&mem.vulkan_instance_extension_enabled_pointer_array,

#if 0
    .vulkan_device_extension_enabled_array=
    {
        [0]="VK_KHR_swapchain",
    },
#endif
};

extern W4 LoadLibraryA(W4);
extern W4 GetProcAddress(W4,W4);

W0 ENGN(W0)
{
    mem.vulkan_library=LoadLibraryA((W4)&mem.vulkan_library_name);
    mem.vulkan_create_instance=(C3)GetProcAddress(mem.vulkan_library,(W4)&mem.vulkan_routine_name_create_instance);

    mem.vulkan_create_instance((W4)&mem.vulkan_instance_struct_type,0,(W4)&mem.vulkan_instance);
    return;
}
