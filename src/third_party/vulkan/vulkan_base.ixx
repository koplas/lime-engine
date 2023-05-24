// Copyright 2015-2022 The Khronos Group Inc.
//
// SPDX-License-Identifier: Apache-2.0 OR MIT
//

// This header is generated from the Khronos Vulkan XML API Registry.

module;

#define VULKAN_HPP_NO_EXCEPTIONS

#define VULKAN_HPP_NO_CONSTRUCTOR
#define VULKAN_HPP_NO_STRUCT_CONSTRUCTORS
#define VULKAN_HPP_NO_UNION_CONSTRUCTORS

#define VULKAN_HPP_DISPATCH_LOADER_DYNAMIC 1

#if defined( _MSVC_LANG )
#  define VULKAN_HPP_CPLUSPLUS _MSVC_LANG
#else
#  define VULKAN_HPP_CPLUSPLUS __cplusplus
#endif

#if 201703L < VULKAN_HPP_CPLUSPLUS
#  define VULKAN_HPP_CPP_VERSION 20
#elif 201402L < VULKAN_HPP_CPLUSPLUS
#  define VULKAN_HPP_CPP_VERSION 17
#elif 201103L < VULKAN_HPP_CPLUSPLUS
#  define VULKAN_HPP_CPP_VERSION 14
#elif 199711L < VULKAN_HPP_CPLUSPLUS
#  define VULKAN_HPP_CPP_VERSION 11
#else
#  error "vulkan.hpp needs at least c++ standard version 11"
#endif

#include <algorithm>
#include <array>   // ArrayWrapperND
#include <string>  // std::string
#include <vulkan/vulkan.h>
#if 17 <= VULKAN_HPP_CPP_VERSION
#  include <string_view>  // std::string_view
#endif

#if defined( VULKAN_HPP_DISABLE_ENHANCED_MODE )
#  if !defined( VULKAN_HPP_NO_SMART_HANDLE )
#    define VULKAN_HPP_NO_SMART_HANDLE
#  endif
#else
#  include <tuple>   // std::tie
#  include <vector>  // std::vector
#endif

#if !defined( VULKAN_HPP_NO_EXCEPTIONS )
#  include <system_error>  // std::is_error_code_enum
#endif

#if defined( VULKAN_HPP_NO_CONSTRUCTORS )
#  if !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )
#    define VULKAN_HPP_NO_STRUCT_CONSTRUCTORS
#  endif
#  if !defined( VULKAN_HPP_NO_UNION_CONSTRUCTORS )
#    define VULKAN_HPP_NO_UNION_CONSTRUCTORS
#  endif
#endif

#if defined( VULKAN_HPP_NO_SETTERS )
#  if !defined( VULKAN_HPP_NO_STRUCT_SETTERS )
#    define VULKAN_HPP_NO_STRUCT_SETTERS
#  endif
#  if !defined( VULKAN_HPP_NO_UNION_SETTERS )
#    define VULKAN_HPP_NO_UNION_SETTERS
#  endif
#endif

#if !defined( VULKAN_HPP_ASSERT )
#  include <cassert>
#  define VULKAN_HPP_ASSERT assert
#endif

#if !defined( VULKAN_HPP_ASSERT_ON_RESULT )
#  define VULKAN_HPP_ASSERT_ON_RESULT VULKAN_HPP_ASSERT
#endif

#if !defined( VULKAN_HPP_STATIC_ASSERT )
#  define VULKAN_HPP_STATIC_ASSERT static_assert
#endif

#if !defined( VULKAN_HPP_ENABLE_DYNAMIC_LOADER_TOOL )
#  define VULKAN_HPP_ENABLE_DYNAMIC_LOADER_TOOL 1
#endif

#if VULKAN_HPP_ENABLE_DYNAMIC_LOADER_TOOL == 1
#  if defined( __unix__ ) || defined( __APPLE__ ) || defined( __QNXNTO__ ) || defined( __Fuchsia__ )
#    include <dlfcn.h>
#  elif defined( _WIN32 )
typedef struct HINSTANCE__ * HINSTANCE;
#    if defined( _WIN64 )
typedef int64_t( __stdcall * FARPROC )();
#    else
typedef int( __stdcall * FARPROC )();
#    endif
extern "C" __declspec( dllimport ) HINSTANCE __stdcall LoadLibraryA( char const * lpLibFileName );
extern "C" __declspec( dllimport ) int __stdcall FreeLibrary( HINSTANCE hLibModule );
extern "C" __declspec( dllimport ) FARPROC __stdcall GetProcAddress( HINSTANCE hModule, const char * lpProcName );
#  endif
#endif

#if !defined( __has_include )
#  define __has_include( x ) false
#endif

#if ( 201907 <= __cpp_lib_three_way_comparison ) && __has_include( <compare> ) && !defined( VULKAN_HPP_NO_SPACESHIP_OPERATOR )
#  define VULKAN_HPP_HAS_SPACESHIP_OPERATOR
#endif
#if defined( VULKAN_HPP_HAS_SPACESHIP_OPERATOR )
#  include <compare>
#endif

#if ( 201803 <= __cpp_lib_span )
#  define VULKAN_HPP_SUPPORT_SPAN
#  include <span>
#endif

// <tuple> includes <sys/sysmacros.h> through some other header
// this results in major(x) being resolved to gnu_dev_major(x)
// which is an expression in a constructor initializer list.
#if defined( major )
#  undef major
#endif
#if defined( minor )
#  undef minor
#endif

// Windows defines MemoryBarrier which is deprecated and collides
// with the VULKAN_HPP_NAMESPACE::MemoryBarrier struct.
#if defined( MemoryBarrier )
#  undef MemoryBarrier
#endif

#if !defined( VULKAN_HPP_HAS_UNRESTRICTED_UNIONS )
#  if defined( __clang__ )
#    if __has_feature( cxx_unrestricted_unions )
#      define VULKAN_HPP_HAS_UNRESTRICTED_UNIONS
#    endif
#  elif defined( __GNUC__ )
#    define GCC_VERSION ( __GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__ )
#    if 40600 <= GCC_VERSION
#      define VULKAN_HPP_HAS_UNRESTRICTED_UNIONS
#    endif
#  elif defined( _MSC_VER )
#    if 1900 <= _MSC_VER
#      define VULKAN_HPP_HAS_UNRESTRICTED_UNIONS
#    endif
#  endif
#endif

#if !defined( VULKAN_HPP_INLINE )
#  if defined( __clang__ )
#    if __has_attribute( always_inline )
#      define VULKAN_HPP_INLINE __attribute__( ( always_inline ) ) __inline__
#    else
#      define VULKAN_HPP_INLINE inline
#    endif
#  elif defined( __GNUC__ )
#    define VULKAN_HPP_INLINE __attribute__( ( always_inline ) ) __inline__
#  elif defined( _MSC_VER )
#    define VULKAN_HPP_INLINE inline
#  else
#    define VULKAN_HPP_INLINE inline
#  endif
#endif

#if defined( VULKAN_HPP_TYPESAFE_CONVERSION )
#  define VULKAN_HPP_TYPESAFE_EXPLICIT
#else
#  define VULKAN_HPP_TYPESAFE_EXPLICIT explicit
#endif

#if defined( __cpp_constexpr )
#  define VULKAN_HPP_CONSTEXPR constexpr
#  if __cpp_constexpr >= 201304
#    define VULKAN_HPP_CONSTEXPR_14 constexpr
#  else
#    define VULKAN_HPP_CONSTEXPR_14
#  endif
#  define VULKAN_HPP_CONST_OR_CONSTEXPR constexpr
#else
#  define VULKAN_HPP_CONSTEXPR
#  define VULKAN_HPP_CONSTEXPR_14
#  define VULKAN_HPP_CONST_OR_CONSTEXPR const
#endif

#if !defined( VULKAN_HPP_NOEXCEPT )
#  if defined( _MSC_VER ) && ( _MSC_VER <= 1800 )
#    define VULKAN_HPP_NOEXCEPT
#  else
#    define VULKAN_HPP_NOEXCEPT     noexcept
#    define VULKAN_HPP_HAS_NOEXCEPT 1
#    if defined( VULKAN_HPP_NO_EXCEPTIONS )
#      define VULKAN_HPP_NOEXCEPT_WHEN_NO_EXCEPTIONS noexcept
#    else
#      define VULKAN_HPP_NOEXCEPT_WHEN_NO_EXCEPTIONS
#    endif
#  endif
#endif

#if 14 <= VULKAN_HPP_CPP_VERSION
#  define VULKAN_HPP_DEPRECATED( msg ) [[deprecated( msg )]]
#else
#  define VULKAN_HPP_DEPRECATED( msg )
#endif

#if ( 17 <= VULKAN_HPP_CPP_VERSION ) && !defined( VULKAN_HPP_NO_NODISCARD_WARNINGS )
#  define VULKAN_HPP_NODISCARD [[nodiscard]]
#  if defined( VULKAN_HPP_NO_EXCEPTIONS )
#    define VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS [[nodiscard]]
#  else
#    define VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS
#  endif
#else
#  define VULKAN_HPP_NODISCARD
#  define VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS
#endif

#if !defined( VULKAN_HPP_NAMESPACE )
#  define VULKAN_HPP_NAMESPACE vk
#endif

#define VULKAN_HPP_STRINGIFY2( text ) #text
#define VULKAN_HPP_STRINGIFY( text )  VULKAN_HPP_STRINGIFY2( text )
#define VULKAN_HPP_NAMESPACE_STRING   VULKAN_HPP_STRINGIFY( VULKAN_HPP_NAMESPACE )

class DispatchLoaderDynamic;
#if !defined( VULKAN_HPP_DISPATCH_LOADER_DYNAMIC )
#  if defined( VK_NO_PROTOTYPES )
#    define VULKAN_HPP_DISPATCH_LOADER_DYNAMIC 1
#  else
#    define VULKAN_HPP_DISPATCH_LOADER_DYNAMIC 0
#  endif
#endif

#if !defined( VULKAN_HPP_STORAGE_API )
#  if defined( VULKAN_HPP_STORAGE_SHARED )
#    if defined( _MSC_VER )
#      if defined( VULKAN_HPP_STORAGE_SHARED_EXPORT )
#        define VULKAN_HPP_STORAGE_API __declspec( dllexport )
#      else
#        define VULKAN_HPP_STORAGE_API __declspec( dllimport )
#      endif
#    elif defined( __clang__ ) || defined( __GNUC__ )
#      if defined( VULKAN_HPP_STORAGE_SHARED_EXPORT )
#        define VULKAN_HPP_STORAGE_API __attribute__( ( visibility( "default" ) ) )
#      else
#        define VULKAN_HPP_STORAGE_API
#      endif
#    else
#      define VULKAN_HPP_STORAGE_API
#      pragma warning Unknown import / export semantics
#    endif
#  else
#    define VULKAN_HPP_STORAGE_API
#  endif
#endif

#if !defined( VULKAN_HPP_DEFAULT_DISPATCHER )
#  if VULKAN_HPP_DISPATCH_LOADER_DYNAMIC == 1
#    define VULKAN_HPP_DEFAULT_DISPATCHER ::VULKAN_HPP_NAMESPACE::defaultDispatchLoaderDynamic
#    define VULKAN_HPP_DEFAULT_DISPATCH_LOADER_DYNAMIC_STORAGE                     \
      namespace VULKAN_HPP_NAMESPACE                                               \
      {                                                                            \
        VULKAN_HPP_STORAGE_API DispatchLoaderDynamic defaultDispatchLoaderDynamic; \
      }
extern VULKAN_HPP_STORAGE_API DispatchLoaderDynamic defaultDispatchLoaderDynamic;
#  else
#    define VULKAN_HPP_DEFAULT_DISPATCHER ::VULKAN_HPP_NAMESPACE::getDispatchLoaderStatic()
#    define VULKAN_HPP_DEFAULT_DISPATCH_LOADER_DYNAMIC_STORAGE
#  endif
#endif

#if !defined( VULKAN_HPP_DEFAULT_DISPATCHER_TYPE )
#  if VULKAN_HPP_DISPATCH_LOADER_DYNAMIC == 1
#    define VULKAN_HPP_DEFAULT_DISPATCHER_TYPE ::VULKAN_HPP_NAMESPACE::DispatchLoaderDynamic
#  else
#    define VULKAN_HPP_DEFAULT_DISPATCHER_TYPE ::VULKAN_HPP_NAMESPACE::DispatchLoaderStatic
#  endif
#endif

#if defined( VULKAN_HPP_NO_DEFAULT_DISPATCHER )
#  define VULKAN_HPP_DEFAULT_ARGUMENT_ASSIGNMENT
#  define VULKAN_HPP_DEFAULT_ARGUMENT_NULLPTR_ASSIGNMENT
#  define VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT
#else
#  define VULKAN_HPP_DEFAULT_ARGUMENT_ASSIGNMENT         = {}
#  define VULKAN_HPP_DEFAULT_ARGUMENT_NULLPTR_ASSIGNMENT = nullptr
#  define VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT       = VULKAN_HPP_DEFAULT_DISPATCHER
#endif

export module vulkan:base;

export namespace VULKAN_HPP_NAMESPACE
{
  class DispatchLoaderBase
  {
  public:
    DispatchLoaderBase() = default;
    DispatchLoaderBase( std::nullptr_t )
#if !defined( NDEBUG )
      : m_valid( false )
#endif
    {
    }

#if !defined( NDEBUG )
    size_t getVkHeaderVersion() const
    {
      VULKAN_HPP_ASSERT( m_valid );
      return vkHeaderVersion;
    }

  private:
    size_t vkHeaderVersion = VK_HEADER_VERSION;
    bool   m_valid         = true;
#endif
  };

  class DispatchLoaderDynamic;
#if !defined( VULKAN_HPP_DISPATCH_LOADER_DYNAMIC )
#  if defined( VK_NO_PROTOTYPES )
#    define VULKAN_HPP_DISPATCH_LOADER_DYNAMIC 1
#  else
#    define VULKAN_HPP_DISPATCH_LOADER_DYNAMIC 0
#  endif
#endif

#if !defined( VULKAN_HPP_STORAGE_API )
#  if defined( VULKAN_HPP_STORAGE_SHARED )
#    if defined( _MSC_VER )
#      if defined( VULKAN_HPP_STORAGE_SHARED_EXPORT )
#        define VULKAN_HPP_STORAGE_API __declspec( dllexport )
#      else
#        define VULKAN_HPP_STORAGE_API __declspec( dllimport )
#      endif
#    elif defined( __clang__ ) || defined( __GNUC__ )
#      if defined( VULKAN_HPP_STORAGE_SHARED_EXPORT )
#        define VULKAN_HPP_STORAGE_API __attribute__( ( visibility( "default" ) ) )
#      else
#        define VULKAN_HPP_STORAGE_API
#      endif
#    else
#      define VULKAN_HPP_STORAGE_API
#      pragma warning Unknown import / export semantics
#    endif
#  else
#    define VULKAN_HPP_STORAGE_API
#  endif
#endif



#if !defined( VULKAN_HPP_DEFAULT_DISPATCHER_TYPE )
#  if VULKAN_HPP_DISPATCH_LOADER_DYNAMIC == 1
#    define VULKAN_HPP_DEFAULT_DISPATCHER_TYPE ::VULKAN_HPP_NAMESPACE::DispatchLoaderDynamic
#  else
#    define VULKAN_HPP_DEFAULT_DISPATCHER_TYPE ::VULKAN_HPP_NAMESPACE::DispatchLoaderStatic
#  endif
#endif

#if defined( VULKAN_HPP_NO_DEFAULT_DISPATCHER )
#  define VULKAN_HPP_DEFAULT_ARGUMENT_ASSIGNMENT
#  define VULKAN_HPP_DEFAULT_ARGUMENT_NULLPTR_ASSIGNMENT
#  define VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT
#else
#  define VULKAN_HPP_DEFAULT_ARGUMENT_ASSIGNMENT         = {}
#  define VULKAN_HPP_DEFAULT_ARGUMENT_NULLPTR_ASSIGNMENT = nullptr
#  define VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT       = VULKAN_HPP_DEFAULT_DISPATCHER
#endif

#if !defined( VK_NO_PROTOTYPES )

#endif

}  // namespace VULKAN_HPP_NAMESPACE

export namespace VULKAN_HPP_NAMESPACE
{
#if VULKAN_HPP_ENABLE_DYNAMIC_LOADER_TOOL
  class DynamicLoader
  {
  public:
#  ifdef VULKAN_HPP_NO_EXCEPTIONS
    DynamicLoader( std::string const & vulkanLibraryName = {} ) VULKAN_HPP_NOEXCEPT
#  else
    DynamicLoader( std::string const & vulkanLibraryName = {} )
#  endif
    {
      if ( !vulkanLibraryName.empty() )
      {
#  if defined( __unix__ ) || defined( __APPLE__ ) || defined( __QNXNTO__ ) || defined( __Fuchsia__ )
        m_library = dlopen( vulkanLibraryName.c_str(), RTLD_NOW | RTLD_LOCAL );
#  elif defined( _WIN32 )
        m_library = ::LoadLibraryA( vulkanLibraryName.c_str() );
#  else
#    error unsupported platform
#  endif
      }
      else
      {
#  if defined( __unix__ ) || defined( __QNXNTO__ ) || defined( __Fuchsia__ )
        m_library = dlopen( "libvulkan.so", RTLD_NOW | RTLD_LOCAL );
        if ( m_library == nullptr )
        {
          m_library = dlopen( "libvulkan.so.1", RTLD_NOW | RTLD_LOCAL );
        }
#  elif defined( __APPLE__ )
        m_library = dlopen( "libvulkan.dylib", RTLD_NOW | RTLD_LOCAL );
#  elif defined( _WIN32 )
        m_library = ::LoadLibraryA( "vulkan-1.dll" );
#  else
#    error unsupported platform
#  endif
      }

#  ifndef VULKAN_HPP_NO_EXCEPTIONS
      if ( m_library == nullptr )
      {
        // NOTE there should be an InitializationFailedError, but msvc insists on the symbol does not exist within the scope of this function.
        throw std::runtime_error( "Failed to load vulkan library!" );
      }
#  endif
    }

    DynamicLoader( DynamicLoader const & ) = delete;

    DynamicLoader( DynamicLoader && other ) VULKAN_HPP_NOEXCEPT : m_library( other.m_library )
    {
      other.m_library = nullptr;
    }

    DynamicLoader & operator=( DynamicLoader const & ) = delete;

    DynamicLoader & operator=( DynamicLoader && other ) VULKAN_HPP_NOEXCEPT
    {
      std::swap( m_library, other.m_library );
      return *this;
    }

    ~DynamicLoader() VULKAN_HPP_NOEXCEPT
    {
      if ( m_library )
      {
#  if defined( __unix__ ) || defined( __APPLE__ ) || defined( __QNXNTO__ ) || defined( __Fuchsia__ )
        dlclose( m_library );
#  elif defined( _WIN32 )
        ::FreeLibrary( m_library );
#  else
#    error unsupported platform
#  endif
      }
    }

    template <typename T>
    T getProcAddress( const char * function ) const VULKAN_HPP_NOEXCEPT
    {
#  if defined( __unix__ ) || defined( __APPLE__ ) || defined( __QNXNTO__ ) || defined( __Fuchsia__ )
      return (T)dlsym( m_library, function );
#  elif defined( _WIN32 )
      return ( T )::GetProcAddress( m_library, function );
#  else
#    error unsupported platform
#  endif
    }

    bool success() const VULKAN_HPP_NOEXCEPT
    {
      return m_library != nullptr;
    }

  private:
#  if defined( __unix__ ) || defined( __APPLE__ ) || defined( __QNXNTO__ ) || defined( __Fuchsia__ )
    void * m_library;
#  elif defined( _WIN32 )
    ::HINSTANCE m_library;
#  else
#    error unsupported platform
#  endif
  };
#endif

  using PFN_dummy = void ( * )();

  class DispatchLoaderDynamic : public DispatchLoaderBase
  {
  public:
    //=== VK_VERSION_1_0 ===
    PFN_vkCreateInstance                               vkCreateInstance                               = 0;
    PFN_vkDestroyInstance                              vkDestroyInstance                              = 0;
    PFN_vkEnumeratePhysicalDevices                     vkEnumeratePhysicalDevices                     = 0;
    PFN_vkGetPhysicalDeviceFeatures                    vkGetPhysicalDeviceFeatures                    = 0;
    PFN_vkGetPhysicalDeviceFormatProperties            vkGetPhysicalDeviceFormatProperties            = 0;
    PFN_vkGetPhysicalDeviceImageFormatProperties       vkGetPhysicalDeviceImageFormatProperties       = 0;
    PFN_vkGetPhysicalDeviceProperties                  vkGetPhysicalDeviceProperties                  = 0;
    PFN_vkGetPhysicalDeviceQueueFamilyProperties       vkGetPhysicalDeviceQueueFamilyProperties       = 0;
    PFN_vkGetPhysicalDeviceMemoryProperties            vkGetPhysicalDeviceMemoryProperties            = 0;
    PFN_vkGetInstanceProcAddr                          vkGetInstanceProcAddr                          = 0;
    PFN_vkGetDeviceProcAddr                            vkGetDeviceProcAddr                            = 0;
    PFN_vkCreateDevice                                 vkCreateDevice                                 = 0;
    PFN_vkDestroyDevice                                vkDestroyDevice                                = 0;
    PFN_vkEnumerateInstanceExtensionProperties         vkEnumerateInstanceExtensionProperties         = 0;
    PFN_vkEnumerateDeviceExtensionProperties           vkEnumerateDeviceExtensionProperties           = 0;
    PFN_vkEnumerateInstanceLayerProperties             vkEnumerateInstanceLayerProperties             = 0;
    PFN_vkEnumerateDeviceLayerProperties               vkEnumerateDeviceLayerProperties               = 0;
    PFN_vkGetDeviceQueue                               vkGetDeviceQueue                               = 0;
    PFN_vkQueueSubmit                                  vkQueueSubmit                                  = 0;
    PFN_vkQueueWaitIdle                                vkQueueWaitIdle                                = 0;
    PFN_vkDeviceWaitIdle                               vkDeviceWaitIdle                               = 0;
    PFN_vkAllocateMemory                               vkAllocateMemory                               = 0;
    PFN_vkFreeMemory                                   vkFreeMemory                                   = 0;
    PFN_vkMapMemory                                    vkMapMemory                                    = 0;
    PFN_vkUnmapMemory                                  vkUnmapMemory                                  = 0;
    PFN_vkFlushMappedMemoryRanges                      vkFlushMappedMemoryRanges                      = 0;
    PFN_vkInvalidateMappedMemoryRanges                 vkInvalidateMappedMemoryRanges                 = 0;
    PFN_vkGetDeviceMemoryCommitment                    vkGetDeviceMemoryCommitment                    = 0;
    PFN_vkBindBufferMemory                             vkBindBufferMemory                             = 0;
    PFN_vkBindImageMemory                              vkBindImageMemory                              = 0;
    PFN_vkGetBufferMemoryRequirements                  vkGetBufferMemoryRequirements                  = 0;
    PFN_vkGetImageMemoryRequirements                   vkGetImageMemoryRequirements                   = 0;
    PFN_vkGetImageSparseMemoryRequirements             vkGetImageSparseMemoryRequirements             = 0;
    PFN_vkGetPhysicalDeviceSparseImageFormatProperties vkGetPhysicalDeviceSparseImageFormatProperties = 0;
    PFN_vkQueueBindSparse                              vkQueueBindSparse                              = 0;
    PFN_vkCreateFence                                  vkCreateFence                                  = 0;
    PFN_vkDestroyFence                                 vkDestroyFence                                 = 0;
    PFN_vkResetFences                                  vkResetFences                                  = 0;
    PFN_vkGetFenceStatus                               vkGetFenceStatus                               = 0;
    PFN_vkWaitForFences                                vkWaitForFences                                = 0;
    PFN_vkCreateSemaphore                              vkCreateSemaphore                              = 0;
    PFN_vkDestroySemaphore                             vkDestroySemaphore                             = 0;
    PFN_vkCreateEvent                                  vkCreateEvent                                  = 0;
    PFN_vkDestroyEvent                                 vkDestroyEvent                                 = 0;
    PFN_vkGetEventStatus                               vkGetEventStatus                               = 0;
    PFN_vkSetEvent                                     vkSetEvent                                     = 0;
    PFN_vkResetEvent                                   vkResetEvent                                   = 0;
    PFN_vkCreateQueryPool                              vkCreateQueryPool                              = 0;
    PFN_vkDestroyQueryPool                             vkDestroyQueryPool                             = 0;
    PFN_vkGetQueryPoolResults                          vkGetQueryPoolResults                          = 0;
    PFN_vkCreateBuffer                                 vkCreateBuffer                                 = 0;
    PFN_vkDestroyBuffer                                vkDestroyBuffer                                = 0;
    PFN_vkCreateBufferView                             vkCreateBufferView                             = 0;
    PFN_vkDestroyBufferView                            vkDestroyBufferView                            = 0;
    PFN_vkCreateImage                                  vkCreateImage                                  = 0;
    PFN_vkDestroyImage                                 vkDestroyImage                                 = 0;
    PFN_vkGetImageSubresourceLayout                    vkGetImageSubresourceLayout                    = 0;
    PFN_vkCreateImageView                              vkCreateImageView                              = 0;
    PFN_vkDestroyImageView                             vkDestroyImageView                             = 0;
    PFN_vkCreateShaderModule                           vkCreateShaderModule                           = 0;
    PFN_vkDestroyShaderModule                          vkDestroyShaderModule                          = 0;
    PFN_vkCreatePipelineCache                          vkCreatePipelineCache                          = 0;
    PFN_vkDestroyPipelineCache                         vkDestroyPipelineCache                         = 0;
    PFN_vkGetPipelineCacheData                         vkGetPipelineCacheData                         = 0;
    PFN_vkMergePipelineCaches                          vkMergePipelineCaches                          = 0;
    PFN_vkCreateGraphicsPipelines                      vkCreateGraphicsPipelines                      = 0;
    PFN_vkCreateComputePipelines                       vkCreateComputePipelines                       = 0;
    PFN_vkDestroyPipeline                              vkDestroyPipeline                              = 0;
    PFN_vkCreatePipelineLayout                         vkCreatePipelineLayout                         = 0;
    PFN_vkDestroyPipelineLayout                        vkDestroyPipelineLayout                        = 0;
    PFN_vkCreateSampler                                vkCreateSampler                                = 0;
    PFN_vkDestroySampler                               vkDestroySampler                               = 0;
    PFN_vkCreateDescriptorSetLayout                    vkCreateDescriptorSetLayout                    = 0;
    PFN_vkDestroyDescriptorSetLayout                   vkDestroyDescriptorSetLayout                   = 0;
    PFN_vkCreateDescriptorPool                         vkCreateDescriptorPool                         = 0;
    PFN_vkDestroyDescriptorPool                        vkDestroyDescriptorPool                        = 0;
    PFN_vkResetDescriptorPool                          vkResetDescriptorPool                          = 0;
    PFN_vkAllocateDescriptorSets                       vkAllocateDescriptorSets                       = 0;
    PFN_vkFreeDescriptorSets                           vkFreeDescriptorSets                           = 0;
    PFN_vkUpdateDescriptorSets                         vkUpdateDescriptorSets                         = 0;
    PFN_vkCreateFramebuffer                            vkCreateFramebuffer                            = 0;
    PFN_vkDestroyFramebuffer                           vkDestroyFramebuffer                           = 0;
    PFN_vkCreateRenderPass                             vkCreateRenderPass                             = 0;
    PFN_vkDestroyRenderPass                            vkDestroyRenderPass                            = 0;
    PFN_vkGetRenderAreaGranularity                     vkGetRenderAreaGranularity                     = 0;
    PFN_vkCreateCommandPool                            vkCreateCommandPool                            = 0;
    PFN_vkDestroyCommandPool                           vkDestroyCommandPool                           = 0;
    PFN_vkResetCommandPool                             vkResetCommandPool                             = 0;
    PFN_vkAllocateCommandBuffers                       vkAllocateCommandBuffers                       = 0;
    PFN_vkFreeCommandBuffers                           vkFreeCommandBuffers                           = 0;
    PFN_vkBeginCommandBuffer                           vkBeginCommandBuffer                           = 0;
    PFN_vkEndCommandBuffer                             vkEndCommandBuffer                             = 0;
    PFN_vkResetCommandBuffer                           vkResetCommandBuffer                           = 0;
    PFN_vkCmdBindPipeline                              vkCmdBindPipeline                              = 0;
    PFN_vkCmdSetViewport                               vkCmdSetViewport                               = 0;
    PFN_vkCmdSetScissor                                vkCmdSetScissor                                = 0;
    PFN_vkCmdSetLineWidth                              vkCmdSetLineWidth                              = 0;
    PFN_vkCmdSetDepthBias                              vkCmdSetDepthBias                              = 0;
    PFN_vkCmdSetBlendConstants                         vkCmdSetBlendConstants                         = 0;
    PFN_vkCmdSetDepthBounds                            vkCmdSetDepthBounds                            = 0;
    PFN_vkCmdSetStencilCompareMask                     vkCmdSetStencilCompareMask                     = 0;
    PFN_vkCmdSetStencilWriteMask                       vkCmdSetStencilWriteMask                       = 0;
    PFN_vkCmdSetStencilReference                       vkCmdSetStencilReference                       = 0;
    PFN_vkCmdBindDescriptorSets                        vkCmdBindDescriptorSets                        = 0;
    PFN_vkCmdBindIndexBuffer                           vkCmdBindIndexBuffer                           = 0;
    PFN_vkCmdBindVertexBuffers                         vkCmdBindVertexBuffers                         = 0;
    PFN_vkCmdDraw                                      vkCmdDraw                                      = 0;
    PFN_vkCmdDrawIndexed                               vkCmdDrawIndexed                               = 0;
    PFN_vkCmdDrawIndirect                              vkCmdDrawIndirect                              = 0;
    PFN_vkCmdDrawIndexedIndirect                       vkCmdDrawIndexedIndirect                       = 0;
    PFN_vkCmdDispatch                                  vkCmdDispatch                                  = 0;
    PFN_vkCmdDispatchIndirect                          vkCmdDispatchIndirect                          = 0;
    PFN_vkCmdCopyBuffer                                vkCmdCopyBuffer                                = 0;
    PFN_vkCmdCopyImage                                 vkCmdCopyImage                                 = 0;
    PFN_vkCmdBlitImage                                 vkCmdBlitImage                                 = 0;
    PFN_vkCmdCopyBufferToImage                         vkCmdCopyBufferToImage                         = 0;
    PFN_vkCmdCopyImageToBuffer                         vkCmdCopyImageToBuffer                         = 0;
    PFN_vkCmdUpdateBuffer                              vkCmdUpdateBuffer                              = 0;
    PFN_vkCmdFillBuffer                                vkCmdFillBuffer                                = 0;
    PFN_vkCmdClearColorImage                           vkCmdClearColorImage                           = 0;
    PFN_vkCmdClearDepthStencilImage                    vkCmdClearDepthStencilImage                    = 0;
    PFN_vkCmdClearAttachments                          vkCmdClearAttachments                          = 0;
    PFN_vkCmdResolveImage                              vkCmdResolveImage                              = 0;
    PFN_vkCmdSetEvent                                  vkCmdSetEvent                                  = 0;
    PFN_vkCmdResetEvent                                vkCmdResetEvent                                = 0;
    PFN_vkCmdWaitEvents                                vkCmdWaitEvents                                = 0;
    PFN_vkCmdPipelineBarrier                           vkCmdPipelineBarrier                           = 0;
    PFN_vkCmdBeginQuery                                vkCmdBeginQuery                                = 0;
    PFN_vkCmdEndQuery                                  vkCmdEndQuery                                  = 0;
    PFN_vkCmdResetQueryPool                            vkCmdResetQueryPool                            = 0;
    PFN_vkCmdWriteTimestamp                            vkCmdWriteTimestamp                            = 0;
    PFN_vkCmdCopyQueryPoolResults                      vkCmdCopyQueryPoolResults                      = 0;
    PFN_vkCmdPushConstants                             vkCmdPushConstants                             = 0;
    PFN_vkCmdBeginRenderPass                           vkCmdBeginRenderPass                           = 0;
    PFN_vkCmdNextSubpass                               vkCmdNextSubpass                               = 0;
    PFN_vkCmdEndRenderPass                             vkCmdEndRenderPass                             = 0;
    PFN_vkCmdExecuteCommands                           vkCmdExecuteCommands                           = 0;

    //=== VK_VERSION_1_1 ===
    PFN_vkEnumerateInstanceVersion                      vkEnumerateInstanceVersion                      = 0;
    PFN_vkBindBufferMemory2                             vkBindBufferMemory2                             = 0;
    PFN_vkBindImageMemory2                              vkBindImageMemory2                              = 0;
    PFN_vkGetDeviceGroupPeerMemoryFeatures              vkGetDeviceGroupPeerMemoryFeatures              = 0;
    PFN_vkCmdSetDeviceMask                              vkCmdSetDeviceMask                              = 0;
    PFN_vkCmdDispatchBase                               vkCmdDispatchBase                               = 0;
    PFN_vkEnumeratePhysicalDeviceGroups                 vkEnumeratePhysicalDeviceGroups                 = 0;
    PFN_vkGetImageMemoryRequirements2                   vkGetImageMemoryRequirements2                   = 0;
    PFN_vkGetBufferMemoryRequirements2                  vkGetBufferMemoryRequirements2                  = 0;
    PFN_vkGetImageSparseMemoryRequirements2             vkGetImageSparseMemoryRequirements2             = 0;
    PFN_vkGetPhysicalDeviceFeatures2                    vkGetPhysicalDeviceFeatures2                    = 0;
    PFN_vkGetPhysicalDeviceProperties2                  vkGetPhysicalDeviceProperties2                  = 0;
    PFN_vkGetPhysicalDeviceFormatProperties2            vkGetPhysicalDeviceFormatProperties2            = 0;
    PFN_vkGetPhysicalDeviceImageFormatProperties2       vkGetPhysicalDeviceImageFormatProperties2       = 0;
    PFN_vkGetPhysicalDeviceQueueFamilyProperties2       vkGetPhysicalDeviceQueueFamilyProperties2       = 0;
    PFN_vkGetPhysicalDeviceMemoryProperties2            vkGetPhysicalDeviceMemoryProperties2            = 0;
    PFN_vkGetPhysicalDeviceSparseImageFormatProperties2 vkGetPhysicalDeviceSparseImageFormatProperties2 = 0;
    PFN_vkTrimCommandPool                               vkTrimCommandPool                               = 0;
    PFN_vkGetDeviceQueue2                               vkGetDeviceQueue2                               = 0;
    PFN_vkCreateSamplerYcbcrConversion                  vkCreateSamplerYcbcrConversion                  = 0;
    PFN_vkDestroySamplerYcbcrConversion                 vkDestroySamplerYcbcrConversion                 = 0;
    PFN_vkCreateDescriptorUpdateTemplate                vkCreateDescriptorUpdateTemplate                = 0;
    PFN_vkDestroyDescriptorUpdateTemplate               vkDestroyDescriptorUpdateTemplate               = 0;
    PFN_vkUpdateDescriptorSetWithTemplate               vkUpdateDescriptorSetWithTemplate               = 0;
    PFN_vkGetPhysicalDeviceExternalBufferProperties     vkGetPhysicalDeviceExternalBufferProperties     = 0;
    PFN_vkGetPhysicalDeviceExternalFenceProperties      vkGetPhysicalDeviceExternalFenceProperties      = 0;
    PFN_vkGetPhysicalDeviceExternalSemaphoreProperties  vkGetPhysicalDeviceExternalSemaphoreProperties  = 0;
    PFN_vkGetDescriptorSetLayoutSupport                 vkGetDescriptorSetLayoutSupport                 = 0;

    //=== VK_VERSION_1_2 ===
    PFN_vkCmdDrawIndirectCount                vkCmdDrawIndirectCount                = 0;
    PFN_vkCmdDrawIndexedIndirectCount         vkCmdDrawIndexedIndirectCount         = 0;
    PFN_vkCreateRenderPass2                   vkCreateRenderPass2                   = 0;
    PFN_vkCmdBeginRenderPass2                 vkCmdBeginRenderPass2                 = 0;
    PFN_vkCmdNextSubpass2                     vkCmdNextSubpass2                     = 0;
    PFN_vkCmdEndRenderPass2                   vkCmdEndRenderPass2                   = 0;
    PFN_vkResetQueryPool                      vkResetQueryPool                      = 0;
    PFN_vkGetSemaphoreCounterValue            vkGetSemaphoreCounterValue            = 0;
    PFN_vkWaitSemaphores                      vkWaitSemaphores                      = 0;
    PFN_vkSignalSemaphore                     vkSignalSemaphore                     = 0;
    PFN_vkGetBufferDeviceAddress              vkGetBufferDeviceAddress              = 0;
    PFN_vkGetBufferOpaqueCaptureAddress       vkGetBufferOpaqueCaptureAddress       = 0;
    PFN_vkGetDeviceMemoryOpaqueCaptureAddress vkGetDeviceMemoryOpaqueCaptureAddress = 0;

    //=== VK_VERSION_1_3 ===
    PFN_vkGetPhysicalDeviceToolProperties        vkGetPhysicalDeviceToolProperties        = 0;
    PFN_vkCreatePrivateDataSlot                  vkCreatePrivateDataSlot                  = 0;
    PFN_vkDestroyPrivateDataSlot                 vkDestroyPrivateDataSlot                 = 0;
    PFN_vkSetPrivateData                         vkSetPrivateData                         = 0;
    PFN_vkGetPrivateData                         vkGetPrivateData                         = 0;
    PFN_vkCmdSetEvent2                           vkCmdSetEvent2                           = 0;
    PFN_vkCmdResetEvent2                         vkCmdResetEvent2                         = 0;
    PFN_vkCmdWaitEvents2                         vkCmdWaitEvents2                         = 0;
    PFN_vkCmdPipelineBarrier2                    vkCmdPipelineBarrier2                    = 0;
    PFN_vkCmdWriteTimestamp2                     vkCmdWriteTimestamp2                     = 0;
    PFN_vkQueueSubmit2                           vkQueueSubmit2                           = 0;
    PFN_vkCmdCopyBuffer2                         vkCmdCopyBuffer2                         = 0;
    PFN_vkCmdCopyImage2                          vkCmdCopyImage2                          = 0;
    PFN_vkCmdCopyBufferToImage2                  vkCmdCopyBufferToImage2                  = 0;
    PFN_vkCmdCopyImageToBuffer2                  vkCmdCopyImageToBuffer2                  = 0;
    PFN_vkCmdBlitImage2                          vkCmdBlitImage2                          = 0;
    PFN_vkCmdResolveImage2                       vkCmdResolveImage2                       = 0;
    PFN_vkCmdBeginRendering                      vkCmdBeginRendering                      = 0;
    PFN_vkCmdEndRendering                        vkCmdEndRendering                        = 0;
    PFN_vkCmdSetCullMode                         vkCmdSetCullMode                         = 0;
    PFN_vkCmdSetFrontFace                        vkCmdSetFrontFace                        = 0;
    PFN_vkCmdSetPrimitiveTopology                vkCmdSetPrimitiveTopology                = 0;
    PFN_vkCmdSetViewportWithCount                vkCmdSetViewportWithCount                = 0;
    PFN_vkCmdSetScissorWithCount                 vkCmdSetScissorWithCount                 = 0;
    PFN_vkCmdBindVertexBuffers2                  vkCmdBindVertexBuffers2                  = 0;
    PFN_vkCmdSetDepthTestEnable                  vkCmdSetDepthTestEnable                  = 0;
    PFN_vkCmdSetDepthWriteEnable                 vkCmdSetDepthWriteEnable                 = 0;
    PFN_vkCmdSetDepthCompareOp                   vkCmdSetDepthCompareOp                   = 0;
    PFN_vkCmdSetDepthBoundsTestEnable            vkCmdSetDepthBoundsTestEnable            = 0;
    PFN_vkCmdSetStencilTestEnable                vkCmdSetStencilTestEnable                = 0;
    PFN_vkCmdSetStencilOp                        vkCmdSetStencilOp                        = 0;
    PFN_vkCmdSetRasterizerDiscardEnable          vkCmdSetRasterizerDiscardEnable          = 0;
    PFN_vkCmdSetDepthBiasEnable                  vkCmdSetDepthBiasEnable                  = 0;
    PFN_vkCmdSetPrimitiveRestartEnable           vkCmdSetPrimitiveRestartEnable           = 0;
    PFN_vkGetDeviceBufferMemoryRequirements      vkGetDeviceBufferMemoryRequirements      = 0;
    PFN_vkGetDeviceImageMemoryRequirements       vkGetDeviceImageMemoryRequirements       = 0;
    PFN_vkGetDeviceImageSparseMemoryRequirements vkGetDeviceImageSparseMemoryRequirements = 0;

    //=== VK_KHR_surface ===
    PFN_vkDestroySurfaceKHR                       vkDestroySurfaceKHR                       = 0;
    PFN_vkGetPhysicalDeviceSurfaceSupportKHR      vkGetPhysicalDeviceSurfaceSupportKHR      = 0;
    PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR vkGetPhysicalDeviceSurfaceCapabilitiesKHR = 0;
    PFN_vkGetPhysicalDeviceSurfaceFormatsKHR      vkGetPhysicalDeviceSurfaceFormatsKHR      = 0;
    PFN_vkGetPhysicalDeviceSurfacePresentModesKHR vkGetPhysicalDeviceSurfacePresentModesKHR = 0;

    //=== VK_KHR_swapchain ===
    PFN_vkCreateSwapchainKHR                    vkCreateSwapchainKHR                    = 0;
    PFN_vkDestroySwapchainKHR                   vkDestroySwapchainKHR                   = 0;
    PFN_vkGetSwapchainImagesKHR                 vkGetSwapchainImagesKHR                 = 0;
    PFN_vkAcquireNextImageKHR                   vkAcquireNextImageKHR                   = 0;
    PFN_vkQueuePresentKHR                       vkQueuePresentKHR                       = 0;
    PFN_vkGetDeviceGroupPresentCapabilitiesKHR  vkGetDeviceGroupPresentCapabilitiesKHR  = 0;
    PFN_vkGetDeviceGroupSurfacePresentModesKHR  vkGetDeviceGroupSurfacePresentModesKHR  = 0;
    PFN_vkGetPhysicalDevicePresentRectanglesKHR vkGetPhysicalDevicePresentRectanglesKHR = 0;
    PFN_vkAcquireNextImage2KHR                  vkAcquireNextImage2KHR                  = 0;

    //=== VK_KHR_display ===
    PFN_vkGetPhysicalDeviceDisplayPropertiesKHR      vkGetPhysicalDeviceDisplayPropertiesKHR      = 0;
    PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR vkGetPhysicalDeviceDisplayPlanePropertiesKHR = 0;
    PFN_vkGetDisplayPlaneSupportedDisplaysKHR        vkGetDisplayPlaneSupportedDisplaysKHR        = 0;
    PFN_vkGetDisplayModePropertiesKHR                vkGetDisplayModePropertiesKHR                = 0;
    PFN_vkCreateDisplayModeKHR                       vkCreateDisplayModeKHR                       = 0;
    PFN_vkGetDisplayPlaneCapabilitiesKHR             vkGetDisplayPlaneCapabilitiesKHR             = 0;
    PFN_vkCreateDisplayPlaneSurfaceKHR               vkCreateDisplayPlaneSurfaceKHR               = 0;

    //=== VK_KHR_display_swapchain ===
    PFN_vkCreateSharedSwapchainsKHR vkCreateSharedSwapchainsKHR = 0;

#if defined( VK_USE_PLATFORM_XLIB_KHR )
    //=== VK_KHR_xlib_surface ===
    PFN_vkCreateXlibSurfaceKHR                        vkCreateXlibSurfaceKHR                        = 0;
    PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR vkGetPhysicalDeviceXlibPresentationSupportKHR = 0;
#else
    PFN_dummy vkCreateXlibSurfaceKHR_placeholder                            = 0;
    PFN_dummy vkGetPhysicalDeviceXlibPresentationSupportKHR_placeholder     = 0;
#endif /*VK_USE_PLATFORM_XLIB_KHR*/

#if defined( VK_USE_PLATFORM_XCB_KHR )
    //=== VK_KHR_xcb_surface ===
    PFN_vkCreateXcbSurfaceKHR                        vkCreateXcbSurfaceKHR                        = 0;
    PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR vkGetPhysicalDeviceXcbPresentationSupportKHR = 0;
#else
    PFN_dummy vkCreateXcbSurfaceKHR_placeholder                             = 0;
    PFN_dummy vkGetPhysicalDeviceXcbPresentationSupportKHR_placeholder      = 0;
#endif /*VK_USE_PLATFORM_XCB_KHR*/

#if defined( VK_USE_PLATFORM_WAYLAND_KHR )
    //=== VK_KHR_wayland_surface ===
    PFN_vkCreateWaylandSurfaceKHR                        vkCreateWaylandSurfaceKHR                        = 0;
    PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR vkGetPhysicalDeviceWaylandPresentationSupportKHR = 0;
#else
    PFN_dummy vkCreateWaylandSurfaceKHR_placeholder                         = 0;
    PFN_dummy vkGetPhysicalDeviceWaylandPresentationSupportKHR_placeholder  = 0;
#endif /*VK_USE_PLATFORM_WAYLAND_KHR*/

#if defined( VK_USE_PLATFORM_ANDROID_KHR )
    //=== VK_KHR_android_surface ===
    PFN_vkCreateAndroidSurfaceKHR vkCreateAndroidSurfaceKHR = 0;
#else
    PFN_dummy vkCreateAndroidSurfaceKHR_placeholder                         = 0;
#endif /*VK_USE_PLATFORM_ANDROID_KHR*/

#if defined( VK_USE_PLATFORM_WIN32_KHR )
    //=== VK_KHR_win32_surface ===
    PFN_vkCreateWin32SurfaceKHR                        vkCreateWin32SurfaceKHR                        = 0;
    PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR vkGetPhysicalDeviceWin32PresentationSupportKHR = 0;
#else
    PFN_dummy vkCreateWin32SurfaceKHR_placeholder                           = 0;
    PFN_dummy vkGetPhysicalDeviceWin32PresentationSupportKHR_placeholder    = 0;
#endif /*VK_USE_PLATFORM_WIN32_KHR*/

       //=== VK_EXT_debug_report ===
    PFN_vkCreateDebugReportCallbackEXT  vkCreateDebugReportCallbackEXT  = 0;
    PFN_vkDestroyDebugReportCallbackEXT vkDestroyDebugReportCallbackEXT = 0;
    PFN_vkDebugReportMessageEXT         vkDebugReportMessageEXT         = 0;

    //=== VK_EXT_debug_marker ===
    PFN_vkDebugMarkerSetObjectTagEXT  vkDebugMarkerSetObjectTagEXT  = 0;
    PFN_vkDebugMarkerSetObjectNameEXT vkDebugMarkerSetObjectNameEXT = 0;
    PFN_vkCmdDebugMarkerBeginEXT      vkCmdDebugMarkerBeginEXT      = 0;
    PFN_vkCmdDebugMarkerEndEXT        vkCmdDebugMarkerEndEXT        = 0;
    PFN_vkCmdDebugMarkerInsertEXT     vkCmdDebugMarkerInsertEXT     = 0;

    //=== VK_KHR_video_queue ===
    PFN_vkGetPhysicalDeviceVideoCapabilitiesKHR     vkGetPhysicalDeviceVideoCapabilitiesKHR     = 0;
    PFN_vkGetPhysicalDeviceVideoFormatPropertiesKHR vkGetPhysicalDeviceVideoFormatPropertiesKHR = 0;
    PFN_vkCreateVideoSessionKHR                     vkCreateVideoSessionKHR                     = 0;
    PFN_vkDestroyVideoSessionKHR                    vkDestroyVideoSessionKHR                    = 0;
    PFN_vkGetVideoSessionMemoryRequirementsKHR      vkGetVideoSessionMemoryRequirementsKHR      = 0;
    PFN_vkBindVideoSessionMemoryKHR                 vkBindVideoSessionMemoryKHR                 = 0;
    PFN_vkCreateVideoSessionParametersKHR           vkCreateVideoSessionParametersKHR           = 0;
    PFN_vkUpdateVideoSessionParametersKHR           vkUpdateVideoSessionParametersKHR           = 0;
    PFN_vkDestroyVideoSessionParametersKHR          vkDestroyVideoSessionParametersKHR          = 0;
    PFN_vkCmdBeginVideoCodingKHR                    vkCmdBeginVideoCodingKHR                    = 0;
    PFN_vkCmdEndVideoCodingKHR                      vkCmdEndVideoCodingKHR                      = 0;
    PFN_vkCmdControlVideoCodingKHR                  vkCmdControlVideoCodingKHR                  = 0;

    //=== VK_KHR_video_decode_queue ===
    PFN_vkCmdDecodeVideoKHR vkCmdDecodeVideoKHR = 0;

    //=== VK_EXT_transform_feedback ===
    PFN_vkCmdBindTransformFeedbackBuffersEXT vkCmdBindTransformFeedbackBuffersEXT = 0;
    PFN_vkCmdBeginTransformFeedbackEXT       vkCmdBeginTransformFeedbackEXT       = 0;
    PFN_vkCmdEndTransformFeedbackEXT         vkCmdEndTransformFeedbackEXT         = 0;
    PFN_vkCmdBeginQueryIndexedEXT            vkCmdBeginQueryIndexedEXT            = 0;
    PFN_vkCmdEndQueryIndexedEXT              vkCmdEndQueryIndexedEXT              = 0;
    PFN_vkCmdDrawIndirectByteCountEXT        vkCmdDrawIndirectByteCountEXT        = 0;

    //=== VK_NVX_binary_import ===
    PFN_vkCreateCuModuleNVX    vkCreateCuModuleNVX    = 0;
    PFN_vkCreateCuFunctionNVX  vkCreateCuFunctionNVX  = 0;
    PFN_vkDestroyCuModuleNVX   vkDestroyCuModuleNVX   = 0;
    PFN_vkDestroyCuFunctionNVX vkDestroyCuFunctionNVX = 0;
    PFN_vkCmdCuLaunchKernelNVX vkCmdCuLaunchKernelNVX = 0;

    //=== VK_NVX_image_view_handle ===
    PFN_vkGetImageViewHandleNVX  vkGetImageViewHandleNVX  = 0;
    PFN_vkGetImageViewAddressNVX vkGetImageViewAddressNVX = 0;

    //=== VK_AMD_draw_indirect_count ===
    PFN_vkCmdDrawIndirectCountAMD        vkCmdDrawIndirectCountAMD        = 0;
    PFN_vkCmdDrawIndexedIndirectCountAMD vkCmdDrawIndexedIndirectCountAMD = 0;

    //=== VK_AMD_shader_info ===
    PFN_vkGetShaderInfoAMD vkGetShaderInfoAMD = 0;

    //=== VK_KHR_dynamic_rendering ===
    PFN_vkCmdBeginRenderingKHR vkCmdBeginRenderingKHR = 0;
    PFN_vkCmdEndRenderingKHR   vkCmdEndRenderingKHR   = 0;

#if defined( VK_USE_PLATFORM_GGP )
    //=== VK_GGP_stream_descriptor_surface ===
    PFN_vkCreateStreamDescriptorSurfaceGGP vkCreateStreamDescriptorSurfaceGGP = 0;
#else
    PFN_dummy vkCreateStreamDescriptorSurfaceGGP_placeholder                = 0;
#endif /*VK_USE_PLATFORM_GGP*/

       //=== VK_NV_external_memory_capabilities ===
    PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV vkGetPhysicalDeviceExternalImageFormatPropertiesNV = 0;

#if defined( VK_USE_PLATFORM_WIN32_KHR )
    //=== VK_NV_external_memory_win32 ===
    PFN_vkGetMemoryWin32HandleNV vkGetMemoryWin32HandleNV = 0;
#else
    PFN_dummy vkGetMemoryWin32HandleNV_placeholder                          = 0;
#endif /*VK_USE_PLATFORM_WIN32_KHR*/

       //=== VK_KHR_get_physical_device_properties2 ===
    PFN_vkGetPhysicalDeviceFeatures2KHR                    vkGetPhysicalDeviceFeatures2KHR                    = 0;
    PFN_vkGetPhysicalDeviceProperties2KHR                  vkGetPhysicalDeviceProperties2KHR                  = 0;
    PFN_vkGetPhysicalDeviceFormatProperties2KHR            vkGetPhysicalDeviceFormatProperties2KHR            = 0;
    PFN_vkGetPhysicalDeviceImageFormatProperties2KHR       vkGetPhysicalDeviceImageFormatProperties2KHR       = 0;
    PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR       vkGetPhysicalDeviceQueueFamilyProperties2KHR       = 0;
    PFN_vkGetPhysicalDeviceMemoryProperties2KHR            vkGetPhysicalDeviceMemoryProperties2KHR            = 0;
    PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR vkGetPhysicalDeviceSparseImageFormatProperties2KHR = 0;

    //=== VK_KHR_device_group ===
    PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR vkGetDeviceGroupPeerMemoryFeaturesKHR = 0;
    PFN_vkCmdSetDeviceMaskKHR                 vkCmdSetDeviceMaskKHR                 = 0;
    PFN_vkCmdDispatchBaseKHR                  vkCmdDispatchBaseKHR                  = 0;

#if defined( VK_USE_PLATFORM_VI_NN )
    //=== VK_NN_vi_surface ===
    PFN_vkCreateViSurfaceNN vkCreateViSurfaceNN = 0;
#else
    PFN_dummy vkCreateViSurfaceNN_placeholder                               = 0;
#endif /*VK_USE_PLATFORM_VI_NN*/

       //=== VK_KHR_maintenance1 ===
    PFN_vkTrimCommandPoolKHR vkTrimCommandPoolKHR = 0;

    //=== VK_KHR_device_group_creation ===
    PFN_vkEnumeratePhysicalDeviceGroupsKHR vkEnumeratePhysicalDeviceGroupsKHR = 0;

    //=== VK_KHR_external_memory_capabilities ===
    PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR vkGetPhysicalDeviceExternalBufferPropertiesKHR = 0;

#if defined( VK_USE_PLATFORM_WIN32_KHR )
    //=== VK_KHR_external_memory_win32 ===
    PFN_vkGetMemoryWin32HandleKHR           vkGetMemoryWin32HandleKHR           = 0;
    PFN_vkGetMemoryWin32HandlePropertiesKHR vkGetMemoryWin32HandlePropertiesKHR = 0;
#else
    PFN_dummy vkGetMemoryWin32HandleKHR_placeholder                         = 0;
    PFN_dummy vkGetMemoryWin32HandlePropertiesKHR_placeholder               = 0;
#endif /*VK_USE_PLATFORM_WIN32_KHR*/

       //=== VK_KHR_external_memory_fd ===
    PFN_vkGetMemoryFdKHR           vkGetMemoryFdKHR           = 0;
    PFN_vkGetMemoryFdPropertiesKHR vkGetMemoryFdPropertiesKHR = 0;

    //=== VK_KHR_external_semaphore_capabilities ===
    PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR vkGetPhysicalDeviceExternalSemaphorePropertiesKHR = 0;

#if defined( VK_USE_PLATFORM_WIN32_KHR )
    //=== VK_KHR_external_semaphore_win32 ===
    PFN_vkImportSemaphoreWin32HandleKHR vkImportSemaphoreWin32HandleKHR = 0;
    PFN_vkGetSemaphoreWin32HandleKHR    vkGetSemaphoreWin32HandleKHR    = 0;
#else
    PFN_dummy vkImportSemaphoreWin32HandleKHR_placeholder                   = 0;
    PFN_dummy vkGetSemaphoreWin32HandleKHR_placeholder                      = 0;
#endif /*VK_USE_PLATFORM_WIN32_KHR*/

       //=== VK_KHR_external_semaphore_fd ===
    PFN_vkImportSemaphoreFdKHR vkImportSemaphoreFdKHR = 0;
    PFN_vkGetSemaphoreFdKHR    vkGetSemaphoreFdKHR    = 0;

    //=== VK_KHR_push_descriptor ===
    PFN_vkCmdPushDescriptorSetKHR             vkCmdPushDescriptorSetKHR             = 0;
    PFN_vkCmdPushDescriptorSetWithTemplateKHR vkCmdPushDescriptorSetWithTemplateKHR = 0;

    //=== VK_EXT_conditional_rendering ===
    PFN_vkCmdBeginConditionalRenderingEXT vkCmdBeginConditionalRenderingEXT = 0;
    PFN_vkCmdEndConditionalRenderingEXT   vkCmdEndConditionalRenderingEXT   = 0;

    //=== VK_KHR_descriptor_update_template ===
    PFN_vkCreateDescriptorUpdateTemplateKHR  vkCreateDescriptorUpdateTemplateKHR  = 0;
    PFN_vkDestroyDescriptorUpdateTemplateKHR vkDestroyDescriptorUpdateTemplateKHR = 0;
    PFN_vkUpdateDescriptorSetWithTemplateKHR vkUpdateDescriptorSetWithTemplateKHR = 0;

    //=== VK_NV_clip_space_w_scaling ===
    PFN_vkCmdSetViewportWScalingNV vkCmdSetViewportWScalingNV = 0;

    //=== VK_EXT_direct_mode_display ===
    PFN_vkReleaseDisplayEXT vkReleaseDisplayEXT = 0;

#if defined( VK_USE_PLATFORM_XLIB_XRANDR_EXT )
    //=== VK_EXT_acquire_xlib_display ===
    PFN_vkAcquireXlibDisplayEXT    vkAcquireXlibDisplayEXT    = 0;
    PFN_vkGetRandROutputDisplayEXT vkGetRandROutputDisplayEXT = 0;
#else
    PFN_dummy vkAcquireXlibDisplayEXT_placeholder                           = 0;
    PFN_dummy vkGetRandROutputDisplayEXT_placeholder                        = 0;
#endif /*VK_USE_PLATFORM_XLIB_XRANDR_EXT*/

       //=== VK_EXT_display_surface_counter ===
    PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT vkGetPhysicalDeviceSurfaceCapabilities2EXT = 0;

    //=== VK_EXT_display_control ===
    PFN_vkDisplayPowerControlEXT  vkDisplayPowerControlEXT  = 0;
    PFN_vkRegisterDeviceEventEXT  vkRegisterDeviceEventEXT  = 0;
    PFN_vkRegisterDisplayEventEXT vkRegisterDisplayEventEXT = 0;
    PFN_vkGetSwapchainCounterEXT  vkGetSwapchainCounterEXT  = 0;

    //=== VK_GOOGLE_display_timing ===
    PFN_vkGetRefreshCycleDurationGOOGLE   vkGetRefreshCycleDurationGOOGLE   = 0;
    PFN_vkGetPastPresentationTimingGOOGLE vkGetPastPresentationTimingGOOGLE = 0;

    //=== VK_EXT_discard_rectangles ===
    PFN_vkCmdSetDiscardRectangleEXT vkCmdSetDiscardRectangleEXT = 0;

    //=== VK_EXT_hdr_metadata ===
    PFN_vkSetHdrMetadataEXT vkSetHdrMetadataEXT = 0;

    //=== VK_KHR_create_renderpass2 ===
    PFN_vkCreateRenderPass2KHR   vkCreateRenderPass2KHR   = 0;
    PFN_vkCmdBeginRenderPass2KHR vkCmdBeginRenderPass2KHR = 0;
    PFN_vkCmdNextSubpass2KHR     vkCmdNextSubpass2KHR     = 0;
    PFN_vkCmdEndRenderPass2KHR   vkCmdEndRenderPass2KHR   = 0;

    //=== VK_KHR_shared_presentable_image ===
    PFN_vkGetSwapchainStatusKHR vkGetSwapchainStatusKHR = 0;

    //=== VK_KHR_external_fence_capabilities ===
    PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR vkGetPhysicalDeviceExternalFencePropertiesKHR = 0;

#if defined( VK_USE_PLATFORM_WIN32_KHR )
    //=== VK_KHR_external_fence_win32 ===
    PFN_vkImportFenceWin32HandleKHR vkImportFenceWin32HandleKHR = 0;
    PFN_vkGetFenceWin32HandleKHR    vkGetFenceWin32HandleKHR    = 0;
#else
    PFN_dummy vkImportFenceWin32HandleKHR_placeholder                       = 0;
    PFN_dummy vkGetFenceWin32HandleKHR_placeholder                          = 0;
#endif /*VK_USE_PLATFORM_WIN32_KHR*/

       //=== VK_KHR_external_fence_fd ===
    PFN_vkImportFenceFdKHR vkImportFenceFdKHR = 0;
    PFN_vkGetFenceFdKHR    vkGetFenceFdKHR    = 0;

    //=== VK_KHR_performance_query ===
    PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR = 0;
    PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR         vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR         = 0;
    PFN_vkAcquireProfilingLockKHR                                       vkAcquireProfilingLockKHR                                       = 0;
    PFN_vkReleaseProfilingLockKHR                                       vkReleaseProfilingLockKHR                                       = 0;

    //=== VK_KHR_get_surface_capabilities2 ===
    PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR vkGetPhysicalDeviceSurfaceCapabilities2KHR = 0;
    PFN_vkGetPhysicalDeviceSurfaceFormats2KHR      vkGetPhysicalDeviceSurfaceFormats2KHR      = 0;

    //=== VK_KHR_get_display_properties2 ===
    PFN_vkGetPhysicalDeviceDisplayProperties2KHR      vkGetPhysicalDeviceDisplayProperties2KHR      = 0;
    PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR vkGetPhysicalDeviceDisplayPlaneProperties2KHR = 0;
    PFN_vkGetDisplayModeProperties2KHR                vkGetDisplayModeProperties2KHR                = 0;
    PFN_vkGetDisplayPlaneCapabilities2KHR             vkGetDisplayPlaneCapabilities2KHR             = 0;

#if defined( VK_USE_PLATFORM_IOS_MVK )
    //=== VK_MVK_ios_surface ===
    PFN_vkCreateIOSSurfaceMVK vkCreateIOSSurfaceMVK = 0;
#else
    PFN_dummy vkCreateIOSSurfaceMVK_placeholder                             = 0;
#endif /*VK_USE_PLATFORM_IOS_MVK*/

#if defined( VK_USE_PLATFORM_MACOS_MVK )
    //=== VK_MVK_macos_surface ===
    PFN_vkCreateMacOSSurfaceMVK vkCreateMacOSSurfaceMVK = 0;
#else
    PFN_dummy vkCreateMacOSSurfaceMVK_placeholder                           = 0;
#endif /*VK_USE_PLATFORM_MACOS_MVK*/

       //=== VK_EXT_debug_utils ===
    PFN_vkSetDebugUtilsObjectNameEXT    vkSetDebugUtilsObjectNameEXT    = 0;
    PFN_vkSetDebugUtilsObjectTagEXT     vkSetDebugUtilsObjectTagEXT     = 0;
    PFN_vkQueueBeginDebugUtilsLabelEXT  vkQueueBeginDebugUtilsLabelEXT  = 0;
    PFN_vkQueueEndDebugUtilsLabelEXT    vkQueueEndDebugUtilsLabelEXT    = 0;
    PFN_vkQueueInsertDebugUtilsLabelEXT vkQueueInsertDebugUtilsLabelEXT = 0;
    PFN_vkCmdBeginDebugUtilsLabelEXT    vkCmdBeginDebugUtilsLabelEXT    = 0;
    PFN_vkCmdEndDebugUtilsLabelEXT      vkCmdEndDebugUtilsLabelEXT      = 0;
    PFN_vkCmdInsertDebugUtilsLabelEXT   vkCmdInsertDebugUtilsLabelEXT   = 0;
    PFN_vkCreateDebugUtilsMessengerEXT  vkCreateDebugUtilsMessengerEXT  = 0;
    PFN_vkDestroyDebugUtilsMessengerEXT vkDestroyDebugUtilsMessengerEXT = 0;
    PFN_vkSubmitDebugUtilsMessageEXT    vkSubmitDebugUtilsMessageEXT    = 0;

#if defined( VK_USE_PLATFORM_ANDROID_KHR )
    //=== VK_ANDROID_external_memory_android_hardware_buffer ===
    PFN_vkGetAndroidHardwareBufferPropertiesANDROID vkGetAndroidHardwareBufferPropertiesANDROID = 0;
    PFN_vkGetMemoryAndroidHardwareBufferANDROID     vkGetMemoryAndroidHardwareBufferANDROID     = 0;
#else
    PFN_dummy vkGetAndroidHardwareBufferPropertiesANDROID_placeholder       = 0;
    PFN_dummy vkGetMemoryAndroidHardwareBufferANDROID_placeholder           = 0;
#endif /*VK_USE_PLATFORM_ANDROID_KHR*/

       //=== VK_EXT_sample_locations ===
    PFN_vkCmdSetSampleLocationsEXT                  vkCmdSetSampleLocationsEXT                  = 0;
    PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT vkGetPhysicalDeviceMultisamplePropertiesEXT = 0;

    //=== VK_KHR_get_memory_requirements2 ===
    PFN_vkGetImageMemoryRequirements2KHR       vkGetImageMemoryRequirements2KHR       = 0;
    PFN_vkGetBufferMemoryRequirements2KHR      vkGetBufferMemoryRequirements2KHR      = 0;
    PFN_vkGetImageSparseMemoryRequirements2KHR vkGetImageSparseMemoryRequirements2KHR = 0;

    //=== VK_KHR_acceleration_structure ===
    PFN_vkCreateAccelerationStructureKHR                 vkCreateAccelerationStructureKHR                 = 0;
    PFN_vkDestroyAccelerationStructureKHR                vkDestroyAccelerationStructureKHR                = 0;
    PFN_vkCmdBuildAccelerationStructuresKHR              vkCmdBuildAccelerationStructuresKHR              = 0;
    PFN_vkCmdBuildAccelerationStructuresIndirectKHR      vkCmdBuildAccelerationStructuresIndirectKHR      = 0;
    PFN_vkBuildAccelerationStructuresKHR                 vkBuildAccelerationStructuresKHR                 = 0;
    PFN_vkCopyAccelerationStructureKHR                   vkCopyAccelerationStructureKHR                   = 0;
    PFN_vkCopyAccelerationStructureToMemoryKHR           vkCopyAccelerationStructureToMemoryKHR           = 0;
    PFN_vkCopyMemoryToAccelerationStructureKHR           vkCopyMemoryToAccelerationStructureKHR           = 0;
    PFN_vkWriteAccelerationStructuresPropertiesKHR       vkWriteAccelerationStructuresPropertiesKHR       = 0;
    PFN_vkCmdCopyAccelerationStructureKHR                vkCmdCopyAccelerationStructureKHR                = 0;
    PFN_vkCmdCopyAccelerationStructureToMemoryKHR        vkCmdCopyAccelerationStructureToMemoryKHR        = 0;
    PFN_vkCmdCopyMemoryToAccelerationStructureKHR        vkCmdCopyMemoryToAccelerationStructureKHR        = 0;
    PFN_vkGetAccelerationStructureDeviceAddressKHR       vkGetAccelerationStructureDeviceAddressKHR       = 0;
    PFN_vkCmdWriteAccelerationStructuresPropertiesKHR    vkCmdWriteAccelerationStructuresPropertiesKHR    = 0;
    PFN_vkGetDeviceAccelerationStructureCompatibilityKHR vkGetDeviceAccelerationStructureCompatibilityKHR = 0;
    PFN_vkGetAccelerationStructureBuildSizesKHR          vkGetAccelerationStructureBuildSizesKHR          = 0;

    //=== VK_KHR_sampler_ycbcr_conversion ===
    PFN_vkCreateSamplerYcbcrConversionKHR  vkCreateSamplerYcbcrConversionKHR  = 0;
    PFN_vkDestroySamplerYcbcrConversionKHR vkDestroySamplerYcbcrConversionKHR = 0;

    //=== VK_KHR_bind_memory2 ===
    PFN_vkBindBufferMemory2KHR vkBindBufferMemory2KHR = 0;
    PFN_vkBindImageMemory2KHR  vkBindImageMemory2KHR  = 0;

    //=== VK_EXT_image_drm_format_modifier ===
    PFN_vkGetImageDrmFormatModifierPropertiesEXT vkGetImageDrmFormatModifierPropertiesEXT = 0;

    //=== VK_EXT_validation_cache ===
    PFN_vkCreateValidationCacheEXT  vkCreateValidationCacheEXT  = 0;
    PFN_vkDestroyValidationCacheEXT vkDestroyValidationCacheEXT = 0;
    PFN_vkMergeValidationCachesEXT  vkMergeValidationCachesEXT  = 0;
    PFN_vkGetValidationCacheDataEXT vkGetValidationCacheDataEXT = 0;

    //=== VK_NV_shading_rate_image ===
    PFN_vkCmdBindShadingRateImageNV          vkCmdBindShadingRateImageNV          = 0;
    PFN_vkCmdSetViewportShadingRatePaletteNV vkCmdSetViewportShadingRatePaletteNV = 0;
    PFN_vkCmdSetCoarseSampleOrderNV          vkCmdSetCoarseSampleOrderNV          = 0;

    //=== VK_NV_ray_tracing ===
    PFN_vkCreateAccelerationStructureNV                vkCreateAccelerationStructureNV                = 0;
    PFN_vkDestroyAccelerationStructureNV               vkDestroyAccelerationStructureNV               = 0;
    PFN_vkGetAccelerationStructureMemoryRequirementsNV vkGetAccelerationStructureMemoryRequirementsNV = 0;
    PFN_vkBindAccelerationStructureMemoryNV            vkBindAccelerationStructureMemoryNV            = 0;
    PFN_vkCmdBuildAccelerationStructureNV              vkCmdBuildAccelerationStructureNV              = 0;
    PFN_vkCmdCopyAccelerationStructureNV               vkCmdCopyAccelerationStructureNV               = 0;
    PFN_vkCmdTraceRaysNV                               vkCmdTraceRaysNV                               = 0;
    PFN_vkCreateRayTracingPipelinesNV                  vkCreateRayTracingPipelinesNV                  = 0;
    PFN_vkGetRayTracingShaderGroupHandlesNV            vkGetRayTracingShaderGroupHandlesNV            = 0;
    PFN_vkGetAccelerationStructureHandleNV             vkGetAccelerationStructureHandleNV             = 0;
    PFN_vkCmdWriteAccelerationStructuresPropertiesNV   vkCmdWriteAccelerationStructuresPropertiesNV   = 0;
    PFN_vkCompileDeferredNV                            vkCompileDeferredNV                            = 0;

    //=== VK_KHR_maintenance3 ===
    PFN_vkGetDescriptorSetLayoutSupportKHR vkGetDescriptorSetLayoutSupportKHR = 0;

    //=== VK_KHR_draw_indirect_count ===
    PFN_vkCmdDrawIndirectCountKHR        vkCmdDrawIndirectCountKHR        = 0;
    PFN_vkCmdDrawIndexedIndirectCountKHR vkCmdDrawIndexedIndirectCountKHR = 0;

    //=== VK_EXT_external_memory_host ===
    PFN_vkGetMemoryHostPointerPropertiesEXT vkGetMemoryHostPointerPropertiesEXT = 0;

    //=== VK_AMD_buffer_marker ===
    PFN_vkCmdWriteBufferMarkerAMD vkCmdWriteBufferMarkerAMD = 0;

    //=== VK_EXT_calibrated_timestamps ===
    PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT vkGetPhysicalDeviceCalibrateableTimeDomainsEXT = 0;
    PFN_vkGetCalibratedTimestampsEXT                   vkGetCalibratedTimestampsEXT                   = 0;

    //=== VK_NV_mesh_shader ===
    PFN_vkCmdDrawMeshTasksNV              vkCmdDrawMeshTasksNV              = 0;
    PFN_vkCmdDrawMeshTasksIndirectNV      vkCmdDrawMeshTasksIndirectNV      = 0;
    PFN_vkCmdDrawMeshTasksIndirectCountNV vkCmdDrawMeshTasksIndirectCountNV = 0;

    //=== VK_NV_scissor_exclusive ===
    PFN_vkCmdSetExclusiveScissorNV vkCmdSetExclusiveScissorNV = 0;

    //=== VK_NV_device_diagnostic_checkpoints ===
    PFN_vkCmdSetCheckpointNV       vkCmdSetCheckpointNV       = 0;
    PFN_vkGetQueueCheckpointDataNV vkGetQueueCheckpointDataNV = 0;

    //=== VK_KHR_timeline_semaphore ===
    PFN_vkGetSemaphoreCounterValueKHR vkGetSemaphoreCounterValueKHR = 0;
    PFN_vkWaitSemaphoresKHR           vkWaitSemaphoresKHR           = 0;
    PFN_vkSignalSemaphoreKHR          vkSignalSemaphoreKHR          = 0;

    //=== VK_INTEL_performance_query ===
    PFN_vkInitializePerformanceApiINTEL         vkInitializePerformanceApiINTEL         = 0;
    PFN_vkUninitializePerformanceApiINTEL       vkUninitializePerformanceApiINTEL       = 0;
    PFN_vkCmdSetPerformanceMarkerINTEL          vkCmdSetPerformanceMarkerINTEL          = 0;
    PFN_vkCmdSetPerformanceStreamMarkerINTEL    vkCmdSetPerformanceStreamMarkerINTEL    = 0;
    PFN_vkCmdSetPerformanceOverrideINTEL        vkCmdSetPerformanceOverrideINTEL        = 0;
    PFN_vkAcquirePerformanceConfigurationINTEL  vkAcquirePerformanceConfigurationINTEL  = 0;
    PFN_vkReleasePerformanceConfigurationINTEL  vkReleasePerformanceConfigurationINTEL  = 0;
    PFN_vkQueueSetPerformanceConfigurationINTEL vkQueueSetPerformanceConfigurationINTEL = 0;
    PFN_vkGetPerformanceParameterINTEL          vkGetPerformanceParameterINTEL          = 0;

    //=== VK_AMD_display_native_hdr ===
    PFN_vkSetLocalDimmingAMD vkSetLocalDimmingAMD = 0;

#if defined( VK_USE_PLATFORM_FUCHSIA )
    //=== VK_FUCHSIA_imagepipe_surface ===
    PFN_vkCreateImagePipeSurfaceFUCHSIA vkCreateImagePipeSurfaceFUCHSIA = 0;
#else
    PFN_dummy vkCreateImagePipeSurfaceFUCHSIA_placeholder                   = 0;
#endif /*VK_USE_PLATFORM_FUCHSIA*/

#if defined( VK_USE_PLATFORM_METAL_EXT )
    //=== VK_EXT_metal_surface ===
    PFN_vkCreateMetalSurfaceEXT vkCreateMetalSurfaceEXT = 0;
#else
    PFN_dummy vkCreateMetalSurfaceEXT_placeholder                           = 0;
#endif /*VK_USE_PLATFORM_METAL_EXT*/

       //=== VK_KHR_fragment_shading_rate ===
    PFN_vkGetPhysicalDeviceFragmentShadingRatesKHR vkGetPhysicalDeviceFragmentShadingRatesKHR = 0;
    PFN_vkCmdSetFragmentShadingRateKHR             vkCmdSetFragmentShadingRateKHR             = 0;

    //=== VK_EXT_buffer_device_address ===
    PFN_vkGetBufferDeviceAddressEXT vkGetBufferDeviceAddressEXT = 0;

    //=== VK_EXT_tooling_info ===
    PFN_vkGetPhysicalDeviceToolPropertiesEXT vkGetPhysicalDeviceToolPropertiesEXT = 0;

    //=== VK_KHR_present_wait ===
    PFN_vkWaitForPresentKHR vkWaitForPresentKHR = 0;

    //=== VK_NV_cooperative_matrix ===
    PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV vkGetPhysicalDeviceCooperativeMatrixPropertiesNV = 0;

    //=== VK_NV_coverage_reduction_mode ===
    PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV = 0;

#if defined( VK_USE_PLATFORM_WIN32_KHR )
    //=== VK_EXT_full_screen_exclusive ===
    PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT vkGetPhysicalDeviceSurfacePresentModes2EXT = 0;
    PFN_vkAcquireFullScreenExclusiveModeEXT        vkAcquireFullScreenExclusiveModeEXT        = 0;
    PFN_vkReleaseFullScreenExclusiveModeEXT        vkReleaseFullScreenExclusiveModeEXT        = 0;
    PFN_vkGetDeviceGroupSurfacePresentModes2EXT    vkGetDeviceGroupSurfacePresentModes2EXT    = 0;
#else
    PFN_dummy vkGetPhysicalDeviceSurfacePresentModes2EXT_placeholder        = 0;
    PFN_dummy vkAcquireFullScreenExclusiveModeEXT_placeholder               = 0;
    PFN_dummy vkReleaseFullScreenExclusiveModeEXT_placeholder               = 0;
    PFN_dummy vkGetDeviceGroupSurfacePresentModes2EXT_placeholder           = 0;
#endif /*VK_USE_PLATFORM_WIN32_KHR*/

       //=== VK_EXT_headless_surface ===
    PFN_vkCreateHeadlessSurfaceEXT vkCreateHeadlessSurfaceEXT = 0;

    //=== VK_KHR_buffer_device_address ===
    PFN_vkGetBufferDeviceAddressKHR              vkGetBufferDeviceAddressKHR              = 0;
    PFN_vkGetBufferOpaqueCaptureAddressKHR       vkGetBufferOpaqueCaptureAddressKHR       = 0;
    PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR vkGetDeviceMemoryOpaqueCaptureAddressKHR = 0;

    //=== VK_EXT_line_rasterization ===
    PFN_vkCmdSetLineStippleEXT vkCmdSetLineStippleEXT = 0;

    //=== VK_EXT_host_query_reset ===
    PFN_vkResetQueryPoolEXT vkResetQueryPoolEXT = 0;

    //=== VK_EXT_extended_dynamic_state ===
    PFN_vkCmdSetCullModeEXT              vkCmdSetCullModeEXT              = 0;
    PFN_vkCmdSetFrontFaceEXT             vkCmdSetFrontFaceEXT             = 0;
    PFN_vkCmdSetPrimitiveTopologyEXT     vkCmdSetPrimitiveTopologyEXT     = 0;
    PFN_vkCmdSetViewportWithCountEXT     vkCmdSetViewportWithCountEXT     = 0;
    PFN_vkCmdSetScissorWithCountEXT      vkCmdSetScissorWithCountEXT      = 0;
    PFN_vkCmdBindVertexBuffers2EXT       vkCmdBindVertexBuffers2EXT       = 0;
    PFN_vkCmdSetDepthTestEnableEXT       vkCmdSetDepthTestEnableEXT       = 0;
    PFN_vkCmdSetDepthWriteEnableEXT      vkCmdSetDepthWriteEnableEXT      = 0;
    PFN_vkCmdSetDepthCompareOpEXT        vkCmdSetDepthCompareOpEXT        = 0;
    PFN_vkCmdSetDepthBoundsTestEnableEXT vkCmdSetDepthBoundsTestEnableEXT = 0;
    PFN_vkCmdSetStencilTestEnableEXT     vkCmdSetStencilTestEnableEXT     = 0;
    PFN_vkCmdSetStencilOpEXT             vkCmdSetStencilOpEXT             = 0;

    //=== VK_KHR_deferred_host_operations ===
    PFN_vkCreateDeferredOperationKHR            vkCreateDeferredOperationKHR            = 0;
    PFN_vkDestroyDeferredOperationKHR           vkDestroyDeferredOperationKHR           = 0;
    PFN_vkGetDeferredOperationMaxConcurrencyKHR vkGetDeferredOperationMaxConcurrencyKHR = 0;
    PFN_vkGetDeferredOperationResultKHR         vkGetDeferredOperationResultKHR         = 0;
    PFN_vkDeferredOperationJoinKHR              vkDeferredOperationJoinKHR              = 0;

    //=== VK_KHR_pipeline_executable_properties ===
    PFN_vkGetPipelineExecutablePropertiesKHR              vkGetPipelineExecutablePropertiesKHR              = 0;
    PFN_vkGetPipelineExecutableStatisticsKHR              vkGetPipelineExecutableStatisticsKHR              = 0;
    PFN_vkGetPipelineExecutableInternalRepresentationsKHR vkGetPipelineExecutableInternalRepresentationsKHR = 0;

    //=== VK_EXT_swapchain_maintenance1 ===
    PFN_vkReleaseSwapchainImagesEXT vkReleaseSwapchainImagesEXT = 0;

    //=== VK_NV_device_generated_commands ===
    PFN_vkGetGeneratedCommandsMemoryRequirementsNV vkGetGeneratedCommandsMemoryRequirementsNV = 0;
    PFN_vkCmdPreprocessGeneratedCommandsNV         vkCmdPreprocessGeneratedCommandsNV         = 0;
    PFN_vkCmdExecuteGeneratedCommandsNV            vkCmdExecuteGeneratedCommandsNV            = 0;
    PFN_vkCmdBindPipelineShaderGroupNV             vkCmdBindPipelineShaderGroupNV             = 0;
    PFN_vkCreateIndirectCommandsLayoutNV           vkCreateIndirectCommandsLayoutNV           = 0;
    PFN_vkDestroyIndirectCommandsLayoutNV          vkDestroyIndirectCommandsLayoutNV          = 0;

    //=== VK_EXT_acquire_drm_display ===
    PFN_vkAcquireDrmDisplayEXT vkAcquireDrmDisplayEXT = 0;
    PFN_vkGetDrmDisplayEXT     vkGetDrmDisplayEXT     = 0;

    //=== VK_EXT_private_data ===
    PFN_vkCreatePrivateDataSlotEXT  vkCreatePrivateDataSlotEXT  = 0;
    PFN_vkDestroyPrivateDataSlotEXT vkDestroyPrivateDataSlotEXT = 0;
    PFN_vkSetPrivateDataEXT         vkSetPrivateDataEXT         = 0;
    PFN_vkGetPrivateDataEXT         vkGetPrivateDataEXT         = 0;

#if defined( VK_ENABLE_BETA_EXTENSIONS )
    //=== VK_KHR_video_encode_queue ===
    PFN_vkCmdEncodeVideoKHR vkCmdEncodeVideoKHR = 0;
#else
    PFN_dummy vkCmdEncodeVideoKHR_placeholder                               = 0;
#endif /*VK_ENABLE_BETA_EXTENSIONS*/

#if defined( VK_USE_PLATFORM_METAL_EXT )
    //=== VK_EXT_metal_objects ===
    PFN_vkExportMetalObjectsEXT vkExportMetalObjectsEXT = 0;
#else
    PFN_dummy vkExportMetalObjectsEXT_placeholder                           = 0;
#endif /*VK_USE_PLATFORM_METAL_EXT*/

       //=== VK_KHR_synchronization2 ===
    PFN_vkCmdSetEvent2KHR           vkCmdSetEvent2KHR           = 0;
    PFN_vkCmdResetEvent2KHR         vkCmdResetEvent2KHR         = 0;
    PFN_vkCmdWaitEvents2KHR         vkCmdWaitEvents2KHR         = 0;
    PFN_vkCmdPipelineBarrier2KHR    vkCmdPipelineBarrier2KHR    = 0;
    PFN_vkCmdWriteTimestamp2KHR     vkCmdWriteTimestamp2KHR     = 0;
    PFN_vkQueueSubmit2KHR           vkQueueSubmit2KHR           = 0;
    PFN_vkCmdWriteBufferMarker2AMD  vkCmdWriteBufferMarker2AMD  = 0;
    PFN_vkGetQueueCheckpointData2NV vkGetQueueCheckpointData2NV = 0;

    //=== VK_EXT_descriptor_buffer ===
    PFN_vkGetDescriptorSetLayoutSizeEXT                          vkGetDescriptorSetLayoutSizeEXT                          = 0;
    PFN_vkGetDescriptorSetLayoutBindingOffsetEXT                 vkGetDescriptorSetLayoutBindingOffsetEXT                 = 0;
    PFN_vkGetDescriptorEXT                                       vkGetDescriptorEXT                                       = 0;
    PFN_vkCmdBindDescriptorBuffersEXT                            vkCmdBindDescriptorBuffersEXT                            = 0;
    PFN_vkCmdSetDescriptorBufferOffsetsEXT                       vkCmdSetDescriptorBufferOffsetsEXT                       = 0;
    PFN_vkCmdBindDescriptorBufferEmbeddedSamplersEXT             vkCmdBindDescriptorBufferEmbeddedSamplersEXT             = 0;
    PFN_vkGetBufferOpaqueCaptureDescriptorDataEXT                vkGetBufferOpaqueCaptureDescriptorDataEXT                = 0;
    PFN_vkGetImageOpaqueCaptureDescriptorDataEXT                 vkGetImageOpaqueCaptureDescriptorDataEXT                 = 0;
    PFN_vkGetImageViewOpaqueCaptureDescriptorDataEXT             vkGetImageViewOpaqueCaptureDescriptorDataEXT             = 0;
    PFN_vkGetSamplerOpaqueCaptureDescriptorDataEXT               vkGetSamplerOpaqueCaptureDescriptorDataEXT               = 0;
    PFN_vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT = 0;

    //=== VK_NV_fragment_shading_rate_enums ===
    PFN_vkCmdSetFragmentShadingRateEnumNV vkCmdSetFragmentShadingRateEnumNV = 0;

    //=== VK_EXT_mesh_shader ===
    PFN_vkCmdDrawMeshTasksEXT              vkCmdDrawMeshTasksEXT              = 0;
    PFN_vkCmdDrawMeshTasksIndirectEXT      vkCmdDrawMeshTasksIndirectEXT      = 0;
    PFN_vkCmdDrawMeshTasksIndirectCountEXT vkCmdDrawMeshTasksIndirectCountEXT = 0;

    //=== VK_KHR_copy_commands2 ===
    PFN_vkCmdCopyBuffer2KHR        vkCmdCopyBuffer2KHR        = 0;
    PFN_vkCmdCopyImage2KHR         vkCmdCopyImage2KHR         = 0;
    PFN_vkCmdCopyBufferToImage2KHR vkCmdCopyBufferToImage2KHR = 0;
    PFN_vkCmdCopyImageToBuffer2KHR vkCmdCopyImageToBuffer2KHR = 0;
    PFN_vkCmdBlitImage2KHR         vkCmdBlitImage2KHR         = 0;
    PFN_vkCmdResolveImage2KHR      vkCmdResolveImage2KHR      = 0;

    //=== VK_EXT_image_compression_control ===
    PFN_vkGetImageSubresourceLayout2EXT vkGetImageSubresourceLayout2EXT = 0;

    //=== VK_EXT_device_fault ===
    PFN_vkGetDeviceFaultInfoEXT vkGetDeviceFaultInfoEXT = 0;

#if defined( VK_USE_PLATFORM_WIN32_KHR )
    //=== VK_NV_acquire_winrt_display ===
    PFN_vkAcquireWinrtDisplayNV vkAcquireWinrtDisplayNV = 0;
    PFN_vkGetWinrtDisplayNV     vkGetWinrtDisplayNV     = 0;
#else
    PFN_dummy vkAcquireWinrtDisplayNV_placeholder                           = 0;
    PFN_dummy vkGetWinrtDisplayNV_placeholder                               = 0;
#endif /*VK_USE_PLATFORM_WIN32_KHR*/

#if defined( VK_USE_PLATFORM_DIRECTFB_EXT )
    //=== VK_EXT_directfb_surface ===
    PFN_vkCreateDirectFBSurfaceEXT                        vkCreateDirectFBSurfaceEXT                        = 0;
    PFN_vkGetPhysicalDeviceDirectFBPresentationSupportEXT vkGetPhysicalDeviceDirectFBPresentationSupportEXT = 0;
#else
    PFN_dummy vkCreateDirectFBSurfaceEXT_placeholder                        = 0;
    PFN_dummy vkGetPhysicalDeviceDirectFBPresentationSupportEXT_placeholder = 0;
#endif /*VK_USE_PLATFORM_DIRECTFB_EXT*/

       //=== VK_KHR_ray_tracing_pipeline ===
    PFN_vkCmdTraceRaysKHR                                 vkCmdTraceRaysKHR                                 = 0;
    PFN_vkCreateRayTracingPipelinesKHR                    vkCreateRayTracingPipelinesKHR                    = 0;
    PFN_vkGetRayTracingShaderGroupHandlesKHR              vkGetRayTracingShaderGroupHandlesKHR              = 0;
    PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR vkGetRayTracingCaptureReplayShaderGroupHandlesKHR = 0;
    PFN_vkCmdTraceRaysIndirectKHR                         vkCmdTraceRaysIndirectKHR                         = 0;
    PFN_vkGetRayTracingShaderGroupStackSizeKHR            vkGetRayTracingShaderGroupStackSizeKHR            = 0;
    PFN_vkCmdSetRayTracingPipelineStackSizeKHR            vkCmdSetRayTracingPipelineStackSizeKHR            = 0;

    //=== VK_EXT_vertex_input_dynamic_state ===
    PFN_vkCmdSetVertexInputEXT vkCmdSetVertexInputEXT = 0;

#if defined( VK_USE_PLATFORM_FUCHSIA )
    //=== VK_FUCHSIA_external_memory ===
    PFN_vkGetMemoryZirconHandleFUCHSIA           vkGetMemoryZirconHandleFUCHSIA           = 0;
    PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA vkGetMemoryZirconHandlePropertiesFUCHSIA = 0;
#else
    PFN_dummy vkGetMemoryZirconHandleFUCHSIA_placeholder                    = 0;
    PFN_dummy vkGetMemoryZirconHandlePropertiesFUCHSIA_placeholder          = 0;
#endif /*VK_USE_PLATFORM_FUCHSIA*/

#if defined( VK_USE_PLATFORM_FUCHSIA )
    //=== VK_FUCHSIA_external_semaphore ===
    PFN_vkImportSemaphoreZirconHandleFUCHSIA vkImportSemaphoreZirconHandleFUCHSIA = 0;
    PFN_vkGetSemaphoreZirconHandleFUCHSIA    vkGetSemaphoreZirconHandleFUCHSIA    = 0;
#else
    PFN_dummy vkImportSemaphoreZirconHandleFUCHSIA_placeholder              = 0;
    PFN_dummy vkGetSemaphoreZirconHandleFUCHSIA_placeholder                 = 0;
#endif /*VK_USE_PLATFORM_FUCHSIA*/

#if defined( VK_USE_PLATFORM_FUCHSIA )
    //=== VK_FUCHSIA_buffer_collection ===
    PFN_vkCreateBufferCollectionFUCHSIA               vkCreateBufferCollectionFUCHSIA               = 0;
    PFN_vkSetBufferCollectionImageConstraintsFUCHSIA  vkSetBufferCollectionImageConstraintsFUCHSIA  = 0;
    PFN_vkSetBufferCollectionBufferConstraintsFUCHSIA vkSetBufferCollectionBufferConstraintsFUCHSIA = 0;
    PFN_vkDestroyBufferCollectionFUCHSIA              vkDestroyBufferCollectionFUCHSIA              = 0;
    PFN_vkGetBufferCollectionPropertiesFUCHSIA        vkGetBufferCollectionPropertiesFUCHSIA        = 0;
#else
    PFN_dummy vkCreateBufferCollectionFUCHSIA_placeholder                   = 0;
    PFN_dummy vkSetBufferCollectionImageConstraintsFUCHSIA_placeholder      = 0;
    PFN_dummy vkSetBufferCollectionBufferConstraintsFUCHSIA_placeholder     = 0;
    PFN_dummy vkDestroyBufferCollectionFUCHSIA_placeholder                  = 0;
    PFN_dummy vkGetBufferCollectionPropertiesFUCHSIA_placeholder            = 0;
#endif /*VK_USE_PLATFORM_FUCHSIA*/

       //=== VK_HUAWEI_subpass_shading ===
    PFN_vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI = 0;
    PFN_vkCmdSubpassShadingHUAWEI                       vkCmdSubpassShadingHUAWEI                       = 0;

    //=== VK_HUAWEI_invocation_mask ===
    PFN_vkCmdBindInvocationMaskHUAWEI vkCmdBindInvocationMaskHUAWEI = 0;

    //=== VK_NV_external_memory_rdma ===
    PFN_vkGetMemoryRemoteAddressNV vkGetMemoryRemoteAddressNV = 0;

    //=== VK_EXT_pipeline_properties ===
    PFN_vkGetPipelinePropertiesEXT vkGetPipelinePropertiesEXT = 0;

    //=== VK_EXT_extended_dynamic_state2 ===
    PFN_vkCmdSetPatchControlPointsEXT      vkCmdSetPatchControlPointsEXT      = 0;
    PFN_vkCmdSetRasterizerDiscardEnableEXT vkCmdSetRasterizerDiscardEnableEXT = 0;
    PFN_vkCmdSetDepthBiasEnableEXT         vkCmdSetDepthBiasEnableEXT         = 0;
    PFN_vkCmdSetLogicOpEXT                 vkCmdSetLogicOpEXT                 = 0;
    PFN_vkCmdSetPrimitiveRestartEnableEXT  vkCmdSetPrimitiveRestartEnableEXT  = 0;

#if defined( VK_USE_PLATFORM_SCREEN_QNX )
    //=== VK_QNX_screen_surface ===
    PFN_vkCreateScreenSurfaceQNX                        vkCreateScreenSurfaceQNX                        = 0;
    PFN_vkGetPhysicalDeviceScreenPresentationSupportQNX vkGetPhysicalDeviceScreenPresentationSupportQNX = 0;
#else
    PFN_dummy vkCreateScreenSurfaceQNX_placeholder                          = 0;
    PFN_dummy vkGetPhysicalDeviceScreenPresentationSupportQNX_placeholder   = 0;
#endif /*VK_USE_PLATFORM_SCREEN_QNX*/

       //=== VK_EXT_color_write_enable ===
    PFN_vkCmdSetColorWriteEnableEXT vkCmdSetColorWriteEnableEXT = 0;

    //=== VK_KHR_ray_tracing_maintenance1 ===
    PFN_vkCmdTraceRaysIndirect2KHR vkCmdTraceRaysIndirect2KHR = 0;

    //=== VK_EXT_multi_draw ===
    PFN_vkCmdDrawMultiEXT        vkCmdDrawMultiEXT        = 0;
    PFN_vkCmdDrawMultiIndexedEXT vkCmdDrawMultiIndexedEXT = 0;

    //=== VK_EXT_opacity_micromap ===
    PFN_vkCreateMicromapEXT                 vkCreateMicromapEXT                 = 0;
    PFN_vkDestroyMicromapEXT                vkDestroyMicromapEXT                = 0;
    PFN_vkCmdBuildMicromapsEXT              vkCmdBuildMicromapsEXT              = 0;
    PFN_vkBuildMicromapsEXT                 vkBuildMicromapsEXT                 = 0;
    PFN_vkCopyMicromapEXT                   vkCopyMicromapEXT                   = 0;
    PFN_vkCopyMicromapToMemoryEXT           vkCopyMicromapToMemoryEXT           = 0;
    PFN_vkCopyMemoryToMicromapEXT           vkCopyMemoryToMicromapEXT           = 0;
    PFN_vkWriteMicromapsPropertiesEXT       vkWriteMicromapsPropertiesEXT       = 0;
    PFN_vkCmdCopyMicromapEXT                vkCmdCopyMicromapEXT                = 0;
    PFN_vkCmdCopyMicromapToMemoryEXT        vkCmdCopyMicromapToMemoryEXT        = 0;
    PFN_vkCmdCopyMemoryToMicromapEXT        vkCmdCopyMemoryToMicromapEXT        = 0;
    PFN_vkCmdWriteMicromapsPropertiesEXT    vkCmdWriteMicromapsPropertiesEXT    = 0;
    PFN_vkGetDeviceMicromapCompatibilityEXT vkGetDeviceMicromapCompatibilityEXT = 0;
    PFN_vkGetMicromapBuildSizesEXT          vkGetMicromapBuildSizesEXT          = 0;

    //=== VK_HUAWEI_cluster_culling_shader ===
    PFN_vkCmdDrawClusterHUAWEI         vkCmdDrawClusterHUAWEI         = 0;
    PFN_vkCmdDrawClusterIndirectHUAWEI vkCmdDrawClusterIndirectHUAWEI = 0;

    //=== VK_EXT_pageable_device_local_memory ===
    PFN_vkSetDeviceMemoryPriorityEXT vkSetDeviceMemoryPriorityEXT = 0;

    //=== VK_KHR_maintenance4 ===
    PFN_vkGetDeviceBufferMemoryRequirementsKHR      vkGetDeviceBufferMemoryRequirementsKHR      = 0;
    PFN_vkGetDeviceImageMemoryRequirementsKHR       vkGetDeviceImageMemoryRequirementsKHR       = 0;
    PFN_vkGetDeviceImageSparseMemoryRequirementsKHR vkGetDeviceImageSparseMemoryRequirementsKHR = 0;

    //=== VK_VALVE_descriptor_set_host_mapping ===
    PFN_vkGetDescriptorSetLayoutHostMappingInfoVALVE vkGetDescriptorSetLayoutHostMappingInfoVALVE = 0;
    PFN_vkGetDescriptorSetHostMappingVALVE           vkGetDescriptorSetHostMappingVALVE           = 0;

    //=== VK_NV_copy_memory_indirect ===
    PFN_vkCmdCopyMemoryIndirectNV        vkCmdCopyMemoryIndirectNV        = 0;
    PFN_vkCmdCopyMemoryToImageIndirectNV vkCmdCopyMemoryToImageIndirectNV = 0;

    //=== VK_NV_memory_decompression ===
    PFN_vkCmdDecompressMemoryNV              vkCmdDecompressMemoryNV              = 0;
    PFN_vkCmdDecompressMemoryIndirectCountNV vkCmdDecompressMemoryIndirectCountNV = 0;

    //=== VK_EXT_extended_dynamic_state3 ===
    PFN_vkCmdSetTessellationDomainOriginEXT         vkCmdSetTessellationDomainOriginEXT         = 0;
    PFN_vkCmdSetDepthClampEnableEXT                 vkCmdSetDepthClampEnableEXT                 = 0;
    PFN_vkCmdSetPolygonModeEXT                      vkCmdSetPolygonModeEXT                      = 0;
    PFN_vkCmdSetRasterizationSamplesEXT             vkCmdSetRasterizationSamplesEXT             = 0;
    PFN_vkCmdSetSampleMaskEXT                       vkCmdSetSampleMaskEXT                       = 0;
    PFN_vkCmdSetAlphaToCoverageEnableEXT            vkCmdSetAlphaToCoverageEnableEXT            = 0;
    PFN_vkCmdSetAlphaToOneEnableEXT                 vkCmdSetAlphaToOneEnableEXT                 = 0;
    PFN_vkCmdSetLogicOpEnableEXT                    vkCmdSetLogicOpEnableEXT                    = 0;
    PFN_vkCmdSetColorBlendEnableEXT                 vkCmdSetColorBlendEnableEXT                 = 0;
    PFN_vkCmdSetColorBlendEquationEXT               vkCmdSetColorBlendEquationEXT               = 0;
    PFN_vkCmdSetColorWriteMaskEXT                   vkCmdSetColorWriteMaskEXT                   = 0;
    PFN_vkCmdSetRasterizationStreamEXT              vkCmdSetRasterizationStreamEXT              = 0;
    PFN_vkCmdSetConservativeRasterizationModeEXT    vkCmdSetConservativeRasterizationModeEXT    = 0;
    PFN_vkCmdSetExtraPrimitiveOverestimationSizeEXT vkCmdSetExtraPrimitiveOverestimationSizeEXT = 0;
    PFN_vkCmdSetDepthClipEnableEXT                  vkCmdSetDepthClipEnableEXT                  = 0;
    PFN_vkCmdSetSampleLocationsEnableEXT            vkCmdSetSampleLocationsEnableEXT            = 0;
    PFN_vkCmdSetColorBlendAdvancedEXT               vkCmdSetColorBlendAdvancedEXT               = 0;
    PFN_vkCmdSetProvokingVertexModeEXT              vkCmdSetProvokingVertexModeEXT              = 0;
    PFN_vkCmdSetLineRasterizationModeEXT            vkCmdSetLineRasterizationModeEXT            = 0;
    PFN_vkCmdSetLineStippleEnableEXT                vkCmdSetLineStippleEnableEXT                = 0;
    PFN_vkCmdSetDepthClipNegativeOneToOneEXT        vkCmdSetDepthClipNegativeOneToOneEXT        = 0;
    PFN_vkCmdSetViewportWScalingEnableNV            vkCmdSetViewportWScalingEnableNV            = 0;
    PFN_vkCmdSetViewportSwizzleNV                   vkCmdSetViewportSwizzleNV                   = 0;
    PFN_vkCmdSetCoverageToColorEnableNV             vkCmdSetCoverageToColorEnableNV             = 0;
    PFN_vkCmdSetCoverageToColorLocationNV           vkCmdSetCoverageToColorLocationNV           = 0;
    PFN_vkCmdSetCoverageModulationModeNV            vkCmdSetCoverageModulationModeNV            = 0;
    PFN_vkCmdSetCoverageModulationTableEnableNV     vkCmdSetCoverageModulationTableEnableNV     = 0;
    PFN_vkCmdSetCoverageModulationTableNV           vkCmdSetCoverageModulationTableNV           = 0;
    PFN_vkCmdSetShadingRateImageEnableNV            vkCmdSetShadingRateImageEnableNV            = 0;
    PFN_vkCmdSetRepresentativeFragmentTestEnableNV  vkCmdSetRepresentativeFragmentTestEnableNV  = 0;
    PFN_vkCmdSetCoverageReductionModeNV             vkCmdSetCoverageReductionModeNV             = 0;

    //=== VK_EXT_shader_module_identifier ===
    PFN_vkGetShaderModuleIdentifierEXT           vkGetShaderModuleIdentifierEXT           = 0;
    PFN_vkGetShaderModuleCreateInfoIdentifierEXT vkGetShaderModuleCreateInfoIdentifierEXT = 0;

    //=== VK_NV_optical_flow ===
    PFN_vkGetPhysicalDeviceOpticalFlowImageFormatsNV vkGetPhysicalDeviceOpticalFlowImageFormatsNV = 0;
    PFN_vkCreateOpticalFlowSessionNV                 vkCreateOpticalFlowSessionNV                 = 0;
    PFN_vkDestroyOpticalFlowSessionNV                vkDestroyOpticalFlowSessionNV                = 0;
    PFN_vkBindOpticalFlowSessionImageNV              vkBindOpticalFlowSessionImageNV              = 0;
    PFN_vkCmdOpticalFlowExecuteNV                    vkCmdOpticalFlowExecuteNV                    = 0;

    //=== VK_QCOM_tile_properties ===
    PFN_vkGetFramebufferTilePropertiesQCOM      vkGetFramebufferTilePropertiesQCOM      = 0;
    PFN_vkGetDynamicRenderingTilePropertiesQCOM vkGetDynamicRenderingTilePropertiesQCOM = 0;

  public:
    DispatchLoaderDynamic() VULKAN_HPP_NOEXCEPT                                    = default;
    DispatchLoaderDynamic( DispatchLoaderDynamic const & rhs ) VULKAN_HPP_NOEXCEPT = default;

    DispatchLoaderDynamic( PFN_vkGetInstanceProcAddr getInstanceProcAddr ) VULKAN_HPP_NOEXCEPT
    {
      init( getInstanceProcAddr );
    }

    void init( PFN_vkGetInstanceProcAddr getInstanceProcAddr ) VULKAN_HPP_NOEXCEPT
    {
      VULKAN_HPP_ASSERT( getInstanceProcAddr );

      vkGetInstanceProcAddr = getInstanceProcAddr;

      //=== VK_VERSION_1_0 ===
      vkCreateInstance = PFN_vkCreateInstance( vkGetInstanceProcAddr( NULL, "vkCreateInstance" ) );
      vkEnumerateInstanceExtensionProperties =
        PFN_vkEnumerateInstanceExtensionProperties( vkGetInstanceProcAddr( NULL, "vkEnumerateInstanceExtensionProperties" ) );
      vkEnumerateInstanceLayerProperties = PFN_vkEnumerateInstanceLayerProperties( vkGetInstanceProcAddr( NULL, "vkEnumerateInstanceLayerProperties" ) );

      //=== VK_VERSION_1_1 ===
      vkEnumerateInstanceVersion = PFN_vkEnumerateInstanceVersion( vkGetInstanceProcAddr( NULL, "vkEnumerateInstanceVersion" ) );
    }

    // This interface does not require a linked vulkan library.
    DispatchLoaderDynamic( VkInstance                instance,
                           PFN_vkGetInstanceProcAddr getInstanceProcAddr,
                           VkDevice                  device            = {},
                           PFN_vkGetDeviceProcAddr   getDeviceProcAddr = nullptr ) VULKAN_HPP_NOEXCEPT
    {
      init( instance, getInstanceProcAddr, device, getDeviceProcAddr );
    }

    // This interface does not require a linked vulkan library.
    void init( VkInstance                instance,
               PFN_vkGetInstanceProcAddr getInstanceProcAddr,
               VkDevice                  device              = {},
               PFN_vkGetDeviceProcAddr /*getDeviceProcAddr*/ = nullptr ) VULKAN_HPP_NOEXCEPT
    {
      VULKAN_HPP_ASSERT( instance && getInstanceProcAddr );
      vkGetInstanceProcAddr = getInstanceProcAddr;
      init( instance );
      if ( device )
      {
        init( device );
      }
    }

    void init( VkInstance instance ) VULKAN_HPP_NOEXCEPT
    {
      //=== VK_VERSION_1_0 ===
      vkDestroyInstance                   = PFN_vkDestroyInstance( vkGetInstanceProcAddr( instance, "vkDestroyInstance" ) );
      vkEnumeratePhysicalDevices          = PFN_vkEnumeratePhysicalDevices( vkGetInstanceProcAddr( instance, "vkEnumeratePhysicalDevices" ) );
      vkGetPhysicalDeviceFeatures         = PFN_vkGetPhysicalDeviceFeatures( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceFeatures" ) );
      vkGetPhysicalDeviceFormatProperties = PFN_vkGetPhysicalDeviceFormatProperties( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceFormatProperties" ) );
      vkGetPhysicalDeviceImageFormatProperties =
        PFN_vkGetPhysicalDeviceImageFormatProperties( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceImageFormatProperties" ) );
      vkGetPhysicalDeviceProperties = PFN_vkGetPhysicalDeviceProperties( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceProperties" ) );
      vkGetPhysicalDeviceQueueFamilyProperties =
        PFN_vkGetPhysicalDeviceQueueFamilyProperties( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceQueueFamilyProperties" ) );
      vkGetPhysicalDeviceMemoryProperties = PFN_vkGetPhysicalDeviceMemoryProperties( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceMemoryProperties" ) );
      vkGetDeviceProcAddr                 = PFN_vkGetDeviceProcAddr( vkGetInstanceProcAddr( instance, "vkGetDeviceProcAddr" ) );
      vkCreateDevice                      = PFN_vkCreateDevice( vkGetInstanceProcAddr( instance, "vkCreateDevice" ) );
      vkDestroyDevice                     = PFN_vkDestroyDevice( vkGetInstanceProcAddr( instance, "vkDestroyDevice" ) );
      vkEnumerateDeviceExtensionProperties =
        PFN_vkEnumerateDeviceExtensionProperties( vkGetInstanceProcAddr( instance, "vkEnumerateDeviceExtensionProperties" ) );
      vkEnumerateDeviceLayerProperties   = PFN_vkEnumerateDeviceLayerProperties( vkGetInstanceProcAddr( instance, "vkEnumerateDeviceLayerProperties" ) );
      vkGetDeviceQueue                   = PFN_vkGetDeviceQueue( vkGetInstanceProcAddr( instance, "vkGetDeviceQueue" ) );
      vkQueueSubmit                      = PFN_vkQueueSubmit( vkGetInstanceProcAddr( instance, "vkQueueSubmit" ) );
      vkQueueWaitIdle                    = PFN_vkQueueWaitIdle( vkGetInstanceProcAddr( instance, "vkQueueWaitIdle" ) );
      vkDeviceWaitIdle                   = PFN_vkDeviceWaitIdle( vkGetInstanceProcAddr( instance, "vkDeviceWaitIdle" ) );
      vkAllocateMemory                   = PFN_vkAllocateMemory( vkGetInstanceProcAddr( instance, "vkAllocateMemory" ) );
      vkFreeMemory                       = PFN_vkFreeMemory( vkGetInstanceProcAddr( instance, "vkFreeMemory" ) );
      vkMapMemory                        = PFN_vkMapMemory( vkGetInstanceProcAddr( instance, "vkMapMemory" ) );
      vkUnmapMemory                      = PFN_vkUnmapMemory( vkGetInstanceProcAddr( instance, "vkUnmapMemory" ) );
      vkFlushMappedMemoryRanges          = PFN_vkFlushMappedMemoryRanges( vkGetInstanceProcAddr( instance, "vkFlushMappedMemoryRanges" ) );
      vkInvalidateMappedMemoryRanges     = PFN_vkInvalidateMappedMemoryRanges( vkGetInstanceProcAddr( instance, "vkInvalidateMappedMemoryRanges" ) );
      vkGetDeviceMemoryCommitment        = PFN_vkGetDeviceMemoryCommitment( vkGetInstanceProcAddr( instance, "vkGetDeviceMemoryCommitment" ) );
      vkBindBufferMemory                 = PFN_vkBindBufferMemory( vkGetInstanceProcAddr( instance, "vkBindBufferMemory" ) );
      vkBindImageMemory                  = PFN_vkBindImageMemory( vkGetInstanceProcAddr( instance, "vkBindImageMemory" ) );
      vkGetBufferMemoryRequirements      = PFN_vkGetBufferMemoryRequirements( vkGetInstanceProcAddr( instance, "vkGetBufferMemoryRequirements" ) );
      vkGetImageMemoryRequirements       = PFN_vkGetImageMemoryRequirements( vkGetInstanceProcAddr( instance, "vkGetImageMemoryRequirements" ) );
      vkGetImageSparseMemoryRequirements = PFN_vkGetImageSparseMemoryRequirements( vkGetInstanceProcAddr( instance, "vkGetImageSparseMemoryRequirements" ) );
      vkGetPhysicalDeviceSparseImageFormatProperties =
        PFN_vkGetPhysicalDeviceSparseImageFormatProperties( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceSparseImageFormatProperties" ) );
      vkQueueBindSparse            = PFN_vkQueueBindSparse( vkGetInstanceProcAddr( instance, "vkQueueBindSparse" ) );
      vkCreateFence                = PFN_vkCreateFence( vkGetInstanceProcAddr( instance, "vkCreateFence" ) );
      vkDestroyFence               = PFN_vkDestroyFence( vkGetInstanceProcAddr( instance, "vkDestroyFence" ) );
      vkResetFences                = PFN_vkResetFences( vkGetInstanceProcAddr( instance, "vkResetFences" ) );
      vkGetFenceStatus             = PFN_vkGetFenceStatus( vkGetInstanceProcAddr( instance, "vkGetFenceStatus" ) );
      vkWaitForFences              = PFN_vkWaitForFences( vkGetInstanceProcAddr( instance, "vkWaitForFences" ) );
      vkCreateSemaphore            = PFN_vkCreateSemaphore( vkGetInstanceProcAddr( instance, "vkCreateSemaphore" ) );
      vkDestroySemaphore           = PFN_vkDestroySemaphore( vkGetInstanceProcAddr( instance, "vkDestroySemaphore" ) );
      vkCreateEvent                = PFN_vkCreateEvent( vkGetInstanceProcAddr( instance, "vkCreateEvent" ) );
      vkDestroyEvent               = PFN_vkDestroyEvent( vkGetInstanceProcAddr( instance, "vkDestroyEvent" ) );
      vkGetEventStatus             = PFN_vkGetEventStatus( vkGetInstanceProcAddr( instance, "vkGetEventStatus" ) );
      vkSetEvent                   = PFN_vkSetEvent( vkGetInstanceProcAddr( instance, "vkSetEvent" ) );
      vkResetEvent                 = PFN_vkResetEvent( vkGetInstanceProcAddr( instance, "vkResetEvent" ) );
      vkCreateQueryPool            = PFN_vkCreateQueryPool( vkGetInstanceProcAddr( instance, "vkCreateQueryPool" ) );
      vkDestroyQueryPool           = PFN_vkDestroyQueryPool( vkGetInstanceProcAddr( instance, "vkDestroyQueryPool" ) );
      vkGetQueryPoolResults        = PFN_vkGetQueryPoolResults( vkGetInstanceProcAddr( instance, "vkGetQueryPoolResults" ) );
      vkCreateBuffer               = PFN_vkCreateBuffer( vkGetInstanceProcAddr( instance, "vkCreateBuffer" ) );
      vkDestroyBuffer              = PFN_vkDestroyBuffer( vkGetInstanceProcAddr( instance, "vkDestroyBuffer" ) );
      vkCreateBufferView           = PFN_vkCreateBufferView( vkGetInstanceProcAddr( instance, "vkCreateBufferView" ) );
      vkDestroyBufferView          = PFN_vkDestroyBufferView( vkGetInstanceProcAddr( instance, "vkDestroyBufferView" ) );
      vkCreateImage                = PFN_vkCreateImage( vkGetInstanceProcAddr( instance, "vkCreateImage" ) );
      vkDestroyImage               = PFN_vkDestroyImage( vkGetInstanceProcAddr( instance, "vkDestroyImage" ) );
      vkGetImageSubresourceLayout  = PFN_vkGetImageSubresourceLayout( vkGetInstanceProcAddr( instance, "vkGetImageSubresourceLayout" ) );
      vkCreateImageView            = PFN_vkCreateImageView( vkGetInstanceProcAddr( instance, "vkCreateImageView" ) );
      vkDestroyImageView           = PFN_vkDestroyImageView( vkGetInstanceProcAddr( instance, "vkDestroyImageView" ) );
      vkCreateShaderModule         = PFN_vkCreateShaderModule( vkGetInstanceProcAddr( instance, "vkCreateShaderModule" ) );
      vkDestroyShaderModule        = PFN_vkDestroyShaderModule( vkGetInstanceProcAddr( instance, "vkDestroyShaderModule" ) );
      vkCreatePipelineCache        = PFN_vkCreatePipelineCache( vkGetInstanceProcAddr( instance, "vkCreatePipelineCache" ) );
      vkDestroyPipelineCache       = PFN_vkDestroyPipelineCache( vkGetInstanceProcAddr( instance, "vkDestroyPipelineCache" ) );
      vkGetPipelineCacheData       = PFN_vkGetPipelineCacheData( vkGetInstanceProcAddr( instance, "vkGetPipelineCacheData" ) );
      vkMergePipelineCaches        = PFN_vkMergePipelineCaches( vkGetInstanceProcAddr( instance, "vkMergePipelineCaches" ) );
      vkCreateGraphicsPipelines    = PFN_vkCreateGraphicsPipelines( vkGetInstanceProcAddr( instance, "vkCreateGraphicsPipelines" ) );
      vkCreateComputePipelines     = PFN_vkCreateComputePipelines( vkGetInstanceProcAddr( instance, "vkCreateComputePipelines" ) );
      vkDestroyPipeline            = PFN_vkDestroyPipeline( vkGetInstanceProcAddr( instance, "vkDestroyPipeline" ) );
      vkCreatePipelineLayout       = PFN_vkCreatePipelineLayout( vkGetInstanceProcAddr( instance, "vkCreatePipelineLayout" ) );
      vkDestroyPipelineLayout      = PFN_vkDestroyPipelineLayout( vkGetInstanceProcAddr( instance, "vkDestroyPipelineLayout" ) );
      vkCreateSampler              = PFN_vkCreateSampler( vkGetInstanceProcAddr( instance, "vkCreateSampler" ) );
      vkDestroySampler             = PFN_vkDestroySampler( vkGetInstanceProcAddr( instance, "vkDestroySampler" ) );
      vkCreateDescriptorSetLayout  = PFN_vkCreateDescriptorSetLayout( vkGetInstanceProcAddr( instance, "vkCreateDescriptorSetLayout" ) );
      vkDestroyDescriptorSetLayout = PFN_vkDestroyDescriptorSetLayout( vkGetInstanceProcAddr( instance, "vkDestroyDescriptorSetLayout" ) );
      vkCreateDescriptorPool       = PFN_vkCreateDescriptorPool( vkGetInstanceProcAddr( instance, "vkCreateDescriptorPool" ) );
      vkDestroyDescriptorPool      = PFN_vkDestroyDescriptorPool( vkGetInstanceProcAddr( instance, "vkDestroyDescriptorPool" ) );
      vkResetDescriptorPool        = PFN_vkResetDescriptorPool( vkGetInstanceProcAddr( instance, "vkResetDescriptorPool" ) );
      vkAllocateDescriptorSets     = PFN_vkAllocateDescriptorSets( vkGetInstanceProcAddr( instance, "vkAllocateDescriptorSets" ) );
      vkFreeDescriptorSets         = PFN_vkFreeDescriptorSets( vkGetInstanceProcAddr( instance, "vkFreeDescriptorSets" ) );
      vkUpdateDescriptorSets       = PFN_vkUpdateDescriptorSets( vkGetInstanceProcAddr( instance, "vkUpdateDescriptorSets" ) );
      vkCreateFramebuffer          = PFN_vkCreateFramebuffer( vkGetInstanceProcAddr( instance, "vkCreateFramebuffer" ) );
      vkDestroyFramebuffer         = PFN_vkDestroyFramebuffer( vkGetInstanceProcAddr( instance, "vkDestroyFramebuffer" ) );
      vkCreateRenderPass           = PFN_vkCreateRenderPass( vkGetInstanceProcAddr( instance, "vkCreateRenderPass" ) );
      vkDestroyRenderPass          = PFN_vkDestroyRenderPass( vkGetInstanceProcAddr( instance, "vkDestroyRenderPass" ) );
      vkGetRenderAreaGranularity   = PFN_vkGetRenderAreaGranularity( vkGetInstanceProcAddr( instance, "vkGetRenderAreaGranularity" ) );
      vkCreateCommandPool          = PFN_vkCreateCommandPool( vkGetInstanceProcAddr( instance, "vkCreateCommandPool" ) );
      vkDestroyCommandPool         = PFN_vkDestroyCommandPool( vkGetInstanceProcAddr( instance, "vkDestroyCommandPool" ) );
      vkResetCommandPool           = PFN_vkResetCommandPool( vkGetInstanceProcAddr( instance, "vkResetCommandPool" ) );
      vkAllocateCommandBuffers     = PFN_vkAllocateCommandBuffers( vkGetInstanceProcAddr( instance, "vkAllocateCommandBuffers" ) );
      vkFreeCommandBuffers         = PFN_vkFreeCommandBuffers( vkGetInstanceProcAddr( instance, "vkFreeCommandBuffers" ) );
      vkBeginCommandBuffer         = PFN_vkBeginCommandBuffer( vkGetInstanceProcAddr( instance, "vkBeginCommandBuffer" ) );
      vkEndCommandBuffer           = PFN_vkEndCommandBuffer( vkGetInstanceProcAddr( instance, "vkEndCommandBuffer" ) );
      vkResetCommandBuffer         = PFN_vkResetCommandBuffer( vkGetInstanceProcAddr( instance, "vkResetCommandBuffer" ) );
      vkCmdBindPipeline            = PFN_vkCmdBindPipeline( vkGetInstanceProcAddr( instance, "vkCmdBindPipeline" ) );
      vkCmdSetViewport             = PFN_vkCmdSetViewport( vkGetInstanceProcAddr( instance, "vkCmdSetViewport" ) );
      vkCmdSetScissor              = PFN_vkCmdSetScissor( vkGetInstanceProcAddr( instance, "vkCmdSetScissor" ) );
      vkCmdSetLineWidth            = PFN_vkCmdSetLineWidth( vkGetInstanceProcAddr( instance, "vkCmdSetLineWidth" ) );
      vkCmdSetDepthBias            = PFN_vkCmdSetDepthBias( vkGetInstanceProcAddr( instance, "vkCmdSetDepthBias" ) );
      vkCmdSetBlendConstants       = PFN_vkCmdSetBlendConstants( vkGetInstanceProcAddr( instance, "vkCmdSetBlendConstants" ) );
      vkCmdSetDepthBounds          = PFN_vkCmdSetDepthBounds( vkGetInstanceProcAddr( instance, "vkCmdSetDepthBounds" ) );
      vkCmdSetStencilCompareMask   = PFN_vkCmdSetStencilCompareMask( vkGetInstanceProcAddr( instance, "vkCmdSetStencilCompareMask" ) );
      vkCmdSetStencilWriteMask     = PFN_vkCmdSetStencilWriteMask( vkGetInstanceProcAddr( instance, "vkCmdSetStencilWriteMask" ) );
      vkCmdSetStencilReference     = PFN_vkCmdSetStencilReference( vkGetInstanceProcAddr( instance, "vkCmdSetStencilReference" ) );
      vkCmdBindDescriptorSets      = PFN_vkCmdBindDescriptorSets( vkGetInstanceProcAddr( instance, "vkCmdBindDescriptorSets" ) );
      vkCmdBindIndexBuffer         = PFN_vkCmdBindIndexBuffer( vkGetInstanceProcAddr( instance, "vkCmdBindIndexBuffer" ) );
      vkCmdBindVertexBuffers       = PFN_vkCmdBindVertexBuffers( vkGetInstanceProcAddr( instance, "vkCmdBindVertexBuffers" ) );
      vkCmdDraw                    = PFN_vkCmdDraw( vkGetInstanceProcAddr( instance, "vkCmdDraw" ) );
      vkCmdDrawIndexed             = PFN_vkCmdDrawIndexed( vkGetInstanceProcAddr( instance, "vkCmdDrawIndexed" ) );
      vkCmdDrawIndirect            = PFN_vkCmdDrawIndirect( vkGetInstanceProcAddr( instance, "vkCmdDrawIndirect" ) );
      vkCmdDrawIndexedIndirect     = PFN_vkCmdDrawIndexedIndirect( vkGetInstanceProcAddr( instance, "vkCmdDrawIndexedIndirect" ) );
      vkCmdDispatch                = PFN_vkCmdDispatch( vkGetInstanceProcAddr( instance, "vkCmdDispatch" ) );
      vkCmdDispatchIndirect        = PFN_vkCmdDispatchIndirect( vkGetInstanceProcAddr( instance, "vkCmdDispatchIndirect" ) );
      vkCmdCopyBuffer              = PFN_vkCmdCopyBuffer( vkGetInstanceProcAddr( instance, "vkCmdCopyBuffer" ) );
      vkCmdCopyImage               = PFN_vkCmdCopyImage( vkGetInstanceProcAddr( instance, "vkCmdCopyImage" ) );
      vkCmdBlitImage               = PFN_vkCmdBlitImage( vkGetInstanceProcAddr( instance, "vkCmdBlitImage" ) );
      vkCmdCopyBufferToImage       = PFN_vkCmdCopyBufferToImage( vkGetInstanceProcAddr( instance, "vkCmdCopyBufferToImage" ) );
      vkCmdCopyImageToBuffer       = PFN_vkCmdCopyImageToBuffer( vkGetInstanceProcAddr( instance, "vkCmdCopyImageToBuffer" ) );
      vkCmdUpdateBuffer            = PFN_vkCmdUpdateBuffer( vkGetInstanceProcAddr( instance, "vkCmdUpdateBuffer" ) );
      vkCmdFillBuffer              = PFN_vkCmdFillBuffer( vkGetInstanceProcAddr( instance, "vkCmdFillBuffer" ) );
      vkCmdClearColorImage         = PFN_vkCmdClearColorImage( vkGetInstanceProcAddr( instance, "vkCmdClearColorImage" ) );
      vkCmdClearDepthStencilImage  = PFN_vkCmdClearDepthStencilImage( vkGetInstanceProcAddr( instance, "vkCmdClearDepthStencilImage" ) );
      vkCmdClearAttachments        = PFN_vkCmdClearAttachments( vkGetInstanceProcAddr( instance, "vkCmdClearAttachments" ) );
      vkCmdResolveImage            = PFN_vkCmdResolveImage( vkGetInstanceProcAddr( instance, "vkCmdResolveImage" ) );
      vkCmdSetEvent                = PFN_vkCmdSetEvent( vkGetInstanceProcAddr( instance, "vkCmdSetEvent" ) );
      vkCmdResetEvent              = PFN_vkCmdResetEvent( vkGetInstanceProcAddr( instance, "vkCmdResetEvent" ) );
      vkCmdWaitEvents              = PFN_vkCmdWaitEvents( vkGetInstanceProcAddr( instance, "vkCmdWaitEvents" ) );
      vkCmdPipelineBarrier         = PFN_vkCmdPipelineBarrier( vkGetInstanceProcAddr( instance, "vkCmdPipelineBarrier" ) );
      vkCmdBeginQuery              = PFN_vkCmdBeginQuery( vkGetInstanceProcAddr( instance, "vkCmdBeginQuery" ) );
      vkCmdEndQuery                = PFN_vkCmdEndQuery( vkGetInstanceProcAddr( instance, "vkCmdEndQuery" ) );
      vkCmdResetQueryPool          = PFN_vkCmdResetQueryPool( vkGetInstanceProcAddr( instance, "vkCmdResetQueryPool" ) );
      vkCmdWriteTimestamp          = PFN_vkCmdWriteTimestamp( vkGetInstanceProcAddr( instance, "vkCmdWriteTimestamp" ) );
      vkCmdCopyQueryPoolResults    = PFN_vkCmdCopyQueryPoolResults( vkGetInstanceProcAddr( instance, "vkCmdCopyQueryPoolResults" ) );
      vkCmdPushConstants           = PFN_vkCmdPushConstants( vkGetInstanceProcAddr( instance, "vkCmdPushConstants" ) );
      vkCmdBeginRenderPass         = PFN_vkCmdBeginRenderPass( vkGetInstanceProcAddr( instance, "vkCmdBeginRenderPass" ) );
      vkCmdNextSubpass             = PFN_vkCmdNextSubpass( vkGetInstanceProcAddr( instance, "vkCmdNextSubpass" ) );
      vkCmdEndRenderPass           = PFN_vkCmdEndRenderPass( vkGetInstanceProcAddr( instance, "vkCmdEndRenderPass" ) );
      vkCmdExecuteCommands         = PFN_vkCmdExecuteCommands( vkGetInstanceProcAddr( instance, "vkCmdExecuteCommands" ) );

      //=== VK_VERSION_1_1 ===
      vkBindBufferMemory2                 = PFN_vkBindBufferMemory2( vkGetInstanceProcAddr( instance, "vkBindBufferMemory2" ) );
      vkBindImageMemory2                  = PFN_vkBindImageMemory2( vkGetInstanceProcAddr( instance, "vkBindImageMemory2" ) );
      vkGetDeviceGroupPeerMemoryFeatures  = PFN_vkGetDeviceGroupPeerMemoryFeatures( vkGetInstanceProcAddr( instance, "vkGetDeviceGroupPeerMemoryFeatures" ) );
      vkCmdSetDeviceMask                  = PFN_vkCmdSetDeviceMask( vkGetInstanceProcAddr( instance, "vkCmdSetDeviceMask" ) );
      vkCmdDispatchBase                   = PFN_vkCmdDispatchBase( vkGetInstanceProcAddr( instance, "vkCmdDispatchBase" ) );
      vkEnumeratePhysicalDeviceGroups     = PFN_vkEnumeratePhysicalDeviceGroups( vkGetInstanceProcAddr( instance, "vkEnumeratePhysicalDeviceGroups" ) );
      vkGetImageMemoryRequirements2       = PFN_vkGetImageMemoryRequirements2( vkGetInstanceProcAddr( instance, "vkGetImageMemoryRequirements2" ) );
      vkGetBufferMemoryRequirements2      = PFN_vkGetBufferMemoryRequirements2( vkGetInstanceProcAddr( instance, "vkGetBufferMemoryRequirements2" ) );
      vkGetImageSparseMemoryRequirements2 = PFN_vkGetImageSparseMemoryRequirements2( vkGetInstanceProcAddr( instance, "vkGetImageSparseMemoryRequirements2" ) );
      vkGetPhysicalDeviceFeatures2        = PFN_vkGetPhysicalDeviceFeatures2( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceFeatures2" ) );
      vkGetPhysicalDeviceProperties2      = PFN_vkGetPhysicalDeviceProperties2( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceProperties2" ) );
      vkGetPhysicalDeviceFormatProperties2 =
        PFN_vkGetPhysicalDeviceFormatProperties2( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceFormatProperties2" ) );
      vkGetPhysicalDeviceImageFormatProperties2 =
        PFN_vkGetPhysicalDeviceImageFormatProperties2( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceImageFormatProperties2" ) );
      vkGetPhysicalDeviceQueueFamilyProperties2 =
        PFN_vkGetPhysicalDeviceQueueFamilyProperties2( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceQueueFamilyProperties2" ) );
      vkGetPhysicalDeviceMemoryProperties2 =
        PFN_vkGetPhysicalDeviceMemoryProperties2( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceMemoryProperties2" ) );
      vkGetPhysicalDeviceSparseImageFormatProperties2 =
        PFN_vkGetPhysicalDeviceSparseImageFormatProperties2( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceSparseImageFormatProperties2" ) );
      vkTrimCommandPool                 = PFN_vkTrimCommandPool( vkGetInstanceProcAddr( instance, "vkTrimCommandPool" ) );
      vkGetDeviceQueue2                 = PFN_vkGetDeviceQueue2( vkGetInstanceProcAddr( instance, "vkGetDeviceQueue2" ) );
      vkCreateSamplerYcbcrConversion    = PFN_vkCreateSamplerYcbcrConversion( vkGetInstanceProcAddr( instance, "vkCreateSamplerYcbcrConversion" ) );
      vkDestroySamplerYcbcrConversion   = PFN_vkDestroySamplerYcbcrConversion( vkGetInstanceProcAddr( instance, "vkDestroySamplerYcbcrConversion" ) );
      vkCreateDescriptorUpdateTemplate  = PFN_vkCreateDescriptorUpdateTemplate( vkGetInstanceProcAddr( instance, "vkCreateDescriptorUpdateTemplate" ) );
      vkDestroyDescriptorUpdateTemplate = PFN_vkDestroyDescriptorUpdateTemplate( vkGetInstanceProcAddr( instance, "vkDestroyDescriptorUpdateTemplate" ) );
      vkUpdateDescriptorSetWithTemplate = PFN_vkUpdateDescriptorSetWithTemplate( vkGetInstanceProcAddr( instance, "vkUpdateDescriptorSetWithTemplate" ) );
      vkGetPhysicalDeviceExternalBufferProperties =
        PFN_vkGetPhysicalDeviceExternalBufferProperties( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceExternalBufferProperties" ) );
      vkGetPhysicalDeviceExternalFenceProperties =
        PFN_vkGetPhysicalDeviceExternalFenceProperties( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceExternalFenceProperties" ) );
      vkGetPhysicalDeviceExternalSemaphoreProperties =
        PFN_vkGetPhysicalDeviceExternalSemaphoreProperties( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceExternalSemaphoreProperties" ) );
      vkGetDescriptorSetLayoutSupport = PFN_vkGetDescriptorSetLayoutSupport( vkGetInstanceProcAddr( instance, "vkGetDescriptorSetLayoutSupport" ) );

      //=== VK_VERSION_1_2 ===
      vkCmdDrawIndirectCount          = PFN_vkCmdDrawIndirectCount( vkGetInstanceProcAddr( instance, "vkCmdDrawIndirectCount" ) );
      vkCmdDrawIndexedIndirectCount   = PFN_vkCmdDrawIndexedIndirectCount( vkGetInstanceProcAddr( instance, "vkCmdDrawIndexedIndirectCount" ) );
      vkCreateRenderPass2             = PFN_vkCreateRenderPass2( vkGetInstanceProcAddr( instance, "vkCreateRenderPass2" ) );
      vkCmdBeginRenderPass2           = PFN_vkCmdBeginRenderPass2( vkGetInstanceProcAddr( instance, "vkCmdBeginRenderPass2" ) );
      vkCmdNextSubpass2               = PFN_vkCmdNextSubpass2( vkGetInstanceProcAddr( instance, "vkCmdNextSubpass2" ) );
      vkCmdEndRenderPass2             = PFN_vkCmdEndRenderPass2( vkGetInstanceProcAddr( instance, "vkCmdEndRenderPass2" ) );
      vkResetQueryPool                = PFN_vkResetQueryPool( vkGetInstanceProcAddr( instance, "vkResetQueryPool" ) );
      vkGetSemaphoreCounterValue      = PFN_vkGetSemaphoreCounterValue( vkGetInstanceProcAddr( instance, "vkGetSemaphoreCounterValue" ) );
      vkWaitSemaphores                = PFN_vkWaitSemaphores( vkGetInstanceProcAddr( instance, "vkWaitSemaphores" ) );
      vkSignalSemaphore               = PFN_vkSignalSemaphore( vkGetInstanceProcAddr( instance, "vkSignalSemaphore" ) );
      vkGetBufferDeviceAddress        = PFN_vkGetBufferDeviceAddress( vkGetInstanceProcAddr( instance, "vkGetBufferDeviceAddress" ) );
      vkGetBufferOpaqueCaptureAddress = PFN_vkGetBufferOpaqueCaptureAddress( vkGetInstanceProcAddr( instance, "vkGetBufferOpaqueCaptureAddress" ) );
      vkGetDeviceMemoryOpaqueCaptureAddress =
        PFN_vkGetDeviceMemoryOpaqueCaptureAddress( vkGetInstanceProcAddr( instance, "vkGetDeviceMemoryOpaqueCaptureAddress" ) );

      //=== VK_VERSION_1_3 ===
      vkGetPhysicalDeviceToolProperties   = PFN_vkGetPhysicalDeviceToolProperties( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceToolProperties" ) );
      vkCreatePrivateDataSlot             = PFN_vkCreatePrivateDataSlot( vkGetInstanceProcAddr( instance, "vkCreatePrivateDataSlot" ) );
      vkDestroyPrivateDataSlot            = PFN_vkDestroyPrivateDataSlot( vkGetInstanceProcAddr( instance, "vkDestroyPrivateDataSlot" ) );
      vkSetPrivateData                    = PFN_vkSetPrivateData( vkGetInstanceProcAddr( instance, "vkSetPrivateData" ) );
      vkGetPrivateData                    = PFN_vkGetPrivateData( vkGetInstanceProcAddr( instance, "vkGetPrivateData" ) );
      vkCmdSetEvent2                      = PFN_vkCmdSetEvent2( vkGetInstanceProcAddr( instance, "vkCmdSetEvent2" ) );
      vkCmdResetEvent2                    = PFN_vkCmdResetEvent2( vkGetInstanceProcAddr( instance, "vkCmdResetEvent2" ) );
      vkCmdWaitEvents2                    = PFN_vkCmdWaitEvents2( vkGetInstanceProcAddr( instance, "vkCmdWaitEvents2" ) );
      vkCmdPipelineBarrier2               = PFN_vkCmdPipelineBarrier2( vkGetInstanceProcAddr( instance, "vkCmdPipelineBarrier2" ) );
      vkCmdWriteTimestamp2                = PFN_vkCmdWriteTimestamp2( vkGetInstanceProcAddr( instance, "vkCmdWriteTimestamp2" ) );
      vkQueueSubmit2                      = PFN_vkQueueSubmit2( vkGetInstanceProcAddr( instance, "vkQueueSubmit2" ) );
      vkCmdCopyBuffer2                    = PFN_vkCmdCopyBuffer2( vkGetInstanceProcAddr( instance, "vkCmdCopyBuffer2" ) );
      vkCmdCopyImage2                     = PFN_vkCmdCopyImage2( vkGetInstanceProcAddr( instance, "vkCmdCopyImage2" ) );
      vkCmdCopyBufferToImage2             = PFN_vkCmdCopyBufferToImage2( vkGetInstanceProcAddr( instance, "vkCmdCopyBufferToImage2" ) );
      vkCmdCopyImageToBuffer2             = PFN_vkCmdCopyImageToBuffer2( vkGetInstanceProcAddr( instance, "vkCmdCopyImageToBuffer2" ) );
      vkCmdBlitImage2                     = PFN_vkCmdBlitImage2( vkGetInstanceProcAddr( instance, "vkCmdBlitImage2" ) );
      vkCmdResolveImage2                  = PFN_vkCmdResolveImage2( vkGetInstanceProcAddr( instance, "vkCmdResolveImage2" ) );
      vkCmdBeginRendering                 = PFN_vkCmdBeginRendering( vkGetInstanceProcAddr( instance, "vkCmdBeginRendering" ) );
      vkCmdEndRendering                   = PFN_vkCmdEndRendering( vkGetInstanceProcAddr( instance, "vkCmdEndRendering" ) );
      vkCmdSetCullMode                    = PFN_vkCmdSetCullMode( vkGetInstanceProcAddr( instance, "vkCmdSetCullMode" ) );
      vkCmdSetFrontFace                   = PFN_vkCmdSetFrontFace( vkGetInstanceProcAddr( instance, "vkCmdSetFrontFace" ) );
      vkCmdSetPrimitiveTopology           = PFN_vkCmdSetPrimitiveTopology( vkGetInstanceProcAddr( instance, "vkCmdSetPrimitiveTopology" ) );
      vkCmdSetViewportWithCount           = PFN_vkCmdSetViewportWithCount( vkGetInstanceProcAddr( instance, "vkCmdSetViewportWithCount" ) );
      vkCmdSetScissorWithCount            = PFN_vkCmdSetScissorWithCount( vkGetInstanceProcAddr( instance, "vkCmdSetScissorWithCount" ) );
      vkCmdBindVertexBuffers2             = PFN_vkCmdBindVertexBuffers2( vkGetInstanceProcAddr( instance, "vkCmdBindVertexBuffers2" ) );
      vkCmdSetDepthTestEnable             = PFN_vkCmdSetDepthTestEnable( vkGetInstanceProcAddr( instance, "vkCmdSetDepthTestEnable" ) );
      vkCmdSetDepthWriteEnable            = PFN_vkCmdSetDepthWriteEnable( vkGetInstanceProcAddr( instance, "vkCmdSetDepthWriteEnable" ) );
      vkCmdSetDepthCompareOp              = PFN_vkCmdSetDepthCompareOp( vkGetInstanceProcAddr( instance, "vkCmdSetDepthCompareOp" ) );
      vkCmdSetDepthBoundsTestEnable       = PFN_vkCmdSetDepthBoundsTestEnable( vkGetInstanceProcAddr( instance, "vkCmdSetDepthBoundsTestEnable" ) );
      vkCmdSetStencilTestEnable           = PFN_vkCmdSetStencilTestEnable( vkGetInstanceProcAddr( instance, "vkCmdSetStencilTestEnable" ) );
      vkCmdSetStencilOp                   = PFN_vkCmdSetStencilOp( vkGetInstanceProcAddr( instance, "vkCmdSetStencilOp" ) );
      vkCmdSetRasterizerDiscardEnable     = PFN_vkCmdSetRasterizerDiscardEnable( vkGetInstanceProcAddr( instance, "vkCmdSetRasterizerDiscardEnable" ) );
      vkCmdSetDepthBiasEnable             = PFN_vkCmdSetDepthBiasEnable( vkGetInstanceProcAddr( instance, "vkCmdSetDepthBiasEnable" ) );
      vkCmdSetPrimitiveRestartEnable      = PFN_vkCmdSetPrimitiveRestartEnable( vkGetInstanceProcAddr( instance, "vkCmdSetPrimitiveRestartEnable" ) );
      vkGetDeviceBufferMemoryRequirements = PFN_vkGetDeviceBufferMemoryRequirements( vkGetInstanceProcAddr( instance, "vkGetDeviceBufferMemoryRequirements" ) );
      vkGetDeviceImageMemoryRequirements  = PFN_vkGetDeviceImageMemoryRequirements( vkGetInstanceProcAddr( instance, "vkGetDeviceImageMemoryRequirements" ) );
      vkGetDeviceImageSparseMemoryRequirements =
        PFN_vkGetDeviceImageSparseMemoryRequirements( vkGetInstanceProcAddr( instance, "vkGetDeviceImageSparseMemoryRequirements" ) );

      //=== VK_KHR_surface ===
      vkDestroySurfaceKHR = PFN_vkDestroySurfaceKHR( vkGetInstanceProcAddr( instance, "vkDestroySurfaceKHR" ) );
      vkGetPhysicalDeviceSurfaceSupportKHR =
        PFN_vkGetPhysicalDeviceSurfaceSupportKHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceSurfaceSupportKHR" ) );
      vkGetPhysicalDeviceSurfaceCapabilitiesKHR =
        PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR" ) );
      vkGetPhysicalDeviceSurfaceFormatsKHR =
        PFN_vkGetPhysicalDeviceSurfaceFormatsKHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceSurfaceFormatsKHR" ) );
      vkGetPhysicalDeviceSurfacePresentModesKHR =
        PFN_vkGetPhysicalDeviceSurfacePresentModesKHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceSurfacePresentModesKHR" ) );

      //=== VK_KHR_swapchain ===
      vkCreateSwapchainKHR    = PFN_vkCreateSwapchainKHR( vkGetInstanceProcAddr( instance, "vkCreateSwapchainKHR" ) );
      vkDestroySwapchainKHR   = PFN_vkDestroySwapchainKHR( vkGetInstanceProcAddr( instance, "vkDestroySwapchainKHR" ) );
      vkGetSwapchainImagesKHR = PFN_vkGetSwapchainImagesKHR( vkGetInstanceProcAddr( instance, "vkGetSwapchainImagesKHR" ) );
      vkAcquireNextImageKHR   = PFN_vkAcquireNextImageKHR( vkGetInstanceProcAddr( instance, "vkAcquireNextImageKHR" ) );
      vkQueuePresentKHR       = PFN_vkQueuePresentKHR( vkGetInstanceProcAddr( instance, "vkQueuePresentKHR" ) );
      vkGetDeviceGroupPresentCapabilitiesKHR =
        PFN_vkGetDeviceGroupPresentCapabilitiesKHR( vkGetInstanceProcAddr( instance, "vkGetDeviceGroupPresentCapabilitiesKHR" ) );
      vkGetDeviceGroupSurfacePresentModesKHR =
        PFN_vkGetDeviceGroupSurfacePresentModesKHR( vkGetInstanceProcAddr( instance, "vkGetDeviceGroupSurfacePresentModesKHR" ) );
      vkGetPhysicalDevicePresentRectanglesKHR =
        PFN_vkGetPhysicalDevicePresentRectanglesKHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDevicePresentRectanglesKHR" ) );
      vkAcquireNextImage2KHR = PFN_vkAcquireNextImage2KHR( vkGetInstanceProcAddr( instance, "vkAcquireNextImage2KHR" ) );

      //=== VK_KHR_display ===
      vkGetPhysicalDeviceDisplayPropertiesKHR =
        PFN_vkGetPhysicalDeviceDisplayPropertiesKHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceDisplayPropertiesKHR" ) );
      vkGetPhysicalDeviceDisplayPlanePropertiesKHR =
        PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR" ) );
      vkGetDisplayPlaneSupportedDisplaysKHR =
        PFN_vkGetDisplayPlaneSupportedDisplaysKHR( vkGetInstanceProcAddr( instance, "vkGetDisplayPlaneSupportedDisplaysKHR" ) );
      vkGetDisplayModePropertiesKHR    = PFN_vkGetDisplayModePropertiesKHR( vkGetInstanceProcAddr( instance, "vkGetDisplayModePropertiesKHR" ) );
      vkCreateDisplayModeKHR           = PFN_vkCreateDisplayModeKHR( vkGetInstanceProcAddr( instance, "vkCreateDisplayModeKHR" ) );
      vkGetDisplayPlaneCapabilitiesKHR = PFN_vkGetDisplayPlaneCapabilitiesKHR( vkGetInstanceProcAddr( instance, "vkGetDisplayPlaneCapabilitiesKHR" ) );
      vkCreateDisplayPlaneSurfaceKHR   = PFN_vkCreateDisplayPlaneSurfaceKHR( vkGetInstanceProcAddr( instance, "vkCreateDisplayPlaneSurfaceKHR" ) );

      //=== VK_KHR_display_swapchain ===
      vkCreateSharedSwapchainsKHR = PFN_vkCreateSharedSwapchainsKHR( vkGetInstanceProcAddr( instance, "vkCreateSharedSwapchainsKHR" ) );

#if defined( VK_USE_PLATFORM_XLIB_KHR )
      //=== VK_KHR_xlib_surface ===
      vkCreateXlibSurfaceKHR = PFN_vkCreateXlibSurfaceKHR( vkGetInstanceProcAddr( instance, "vkCreateXlibSurfaceKHR" ) );
      vkGetPhysicalDeviceXlibPresentationSupportKHR =
        PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceXlibPresentationSupportKHR" ) );
#endif /*VK_USE_PLATFORM_XLIB_KHR*/

#if defined( VK_USE_PLATFORM_XCB_KHR )
      //=== VK_KHR_xcb_surface ===
      vkCreateXcbSurfaceKHR = PFN_vkCreateXcbSurfaceKHR( vkGetInstanceProcAddr( instance, "vkCreateXcbSurfaceKHR" ) );
      vkGetPhysicalDeviceXcbPresentationSupportKHR =
        PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceXcbPresentationSupportKHR" ) );
#endif /*VK_USE_PLATFORM_XCB_KHR*/

#if defined( VK_USE_PLATFORM_WAYLAND_KHR )
      //=== VK_KHR_wayland_surface ===
      vkCreateWaylandSurfaceKHR = PFN_vkCreateWaylandSurfaceKHR( vkGetInstanceProcAddr( instance, "vkCreateWaylandSurfaceKHR" ) );
      vkGetPhysicalDeviceWaylandPresentationSupportKHR =
        PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceWaylandPresentationSupportKHR" ) );
#endif /*VK_USE_PLATFORM_WAYLAND_KHR*/

#if defined( VK_USE_PLATFORM_ANDROID_KHR )
      //=== VK_KHR_android_surface ===
      vkCreateAndroidSurfaceKHR = PFN_vkCreateAndroidSurfaceKHR( vkGetInstanceProcAddr( instance, "vkCreateAndroidSurfaceKHR" ) );
#endif /*VK_USE_PLATFORM_ANDROID_KHR*/

#if defined( VK_USE_PLATFORM_WIN32_KHR )
      //=== VK_KHR_win32_surface ===
      vkCreateWin32SurfaceKHR = PFN_vkCreateWin32SurfaceKHR( vkGetInstanceProcAddr( instance, "vkCreateWin32SurfaceKHR" ) );
      vkGetPhysicalDeviceWin32PresentationSupportKHR =
        PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceWin32PresentationSupportKHR" ) );
#endif /*VK_USE_PLATFORM_WIN32_KHR*/

       //=== VK_EXT_debug_report ===
      vkCreateDebugReportCallbackEXT  = PFN_vkCreateDebugReportCallbackEXT( vkGetInstanceProcAddr( instance, "vkCreateDebugReportCallbackEXT" ) );
      vkDestroyDebugReportCallbackEXT = PFN_vkDestroyDebugReportCallbackEXT( vkGetInstanceProcAddr( instance, "vkDestroyDebugReportCallbackEXT" ) );
      vkDebugReportMessageEXT         = PFN_vkDebugReportMessageEXT( vkGetInstanceProcAddr( instance, "vkDebugReportMessageEXT" ) );

      //=== VK_EXT_debug_marker ===
      vkDebugMarkerSetObjectTagEXT  = PFN_vkDebugMarkerSetObjectTagEXT( vkGetInstanceProcAddr( instance, "vkDebugMarkerSetObjectTagEXT" ) );
      vkDebugMarkerSetObjectNameEXT = PFN_vkDebugMarkerSetObjectNameEXT( vkGetInstanceProcAddr( instance, "vkDebugMarkerSetObjectNameEXT" ) );
      vkCmdDebugMarkerBeginEXT      = PFN_vkCmdDebugMarkerBeginEXT( vkGetInstanceProcAddr( instance, "vkCmdDebugMarkerBeginEXT" ) );
      vkCmdDebugMarkerEndEXT        = PFN_vkCmdDebugMarkerEndEXT( vkGetInstanceProcAddr( instance, "vkCmdDebugMarkerEndEXT" ) );
      vkCmdDebugMarkerInsertEXT     = PFN_vkCmdDebugMarkerInsertEXT( vkGetInstanceProcAddr( instance, "vkCmdDebugMarkerInsertEXT" ) );

      //=== VK_KHR_video_queue ===
      vkGetPhysicalDeviceVideoCapabilitiesKHR =
        PFN_vkGetPhysicalDeviceVideoCapabilitiesKHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceVideoCapabilitiesKHR" ) );
      vkGetPhysicalDeviceVideoFormatPropertiesKHR =
        PFN_vkGetPhysicalDeviceVideoFormatPropertiesKHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceVideoFormatPropertiesKHR" ) );
      vkCreateVideoSessionKHR  = PFN_vkCreateVideoSessionKHR( vkGetInstanceProcAddr( instance, "vkCreateVideoSessionKHR" ) );
      vkDestroyVideoSessionKHR = PFN_vkDestroyVideoSessionKHR( vkGetInstanceProcAddr( instance, "vkDestroyVideoSessionKHR" ) );
      vkGetVideoSessionMemoryRequirementsKHR =
        PFN_vkGetVideoSessionMemoryRequirementsKHR( vkGetInstanceProcAddr( instance, "vkGetVideoSessionMemoryRequirementsKHR" ) );
      vkBindVideoSessionMemoryKHR        = PFN_vkBindVideoSessionMemoryKHR( vkGetInstanceProcAddr( instance, "vkBindVideoSessionMemoryKHR" ) );
      vkCreateVideoSessionParametersKHR  = PFN_vkCreateVideoSessionParametersKHR( vkGetInstanceProcAddr( instance, "vkCreateVideoSessionParametersKHR" ) );
      vkUpdateVideoSessionParametersKHR  = PFN_vkUpdateVideoSessionParametersKHR( vkGetInstanceProcAddr( instance, "vkUpdateVideoSessionParametersKHR" ) );
      vkDestroyVideoSessionParametersKHR = PFN_vkDestroyVideoSessionParametersKHR( vkGetInstanceProcAddr( instance, "vkDestroyVideoSessionParametersKHR" ) );
      vkCmdBeginVideoCodingKHR           = PFN_vkCmdBeginVideoCodingKHR( vkGetInstanceProcAddr( instance, "vkCmdBeginVideoCodingKHR" ) );
      vkCmdEndVideoCodingKHR             = PFN_vkCmdEndVideoCodingKHR( vkGetInstanceProcAddr( instance, "vkCmdEndVideoCodingKHR" ) );
      vkCmdControlVideoCodingKHR         = PFN_vkCmdControlVideoCodingKHR( vkGetInstanceProcAddr( instance, "vkCmdControlVideoCodingKHR" ) );

      //=== VK_KHR_video_decode_queue ===
      vkCmdDecodeVideoKHR = PFN_vkCmdDecodeVideoKHR( vkGetInstanceProcAddr( instance, "vkCmdDecodeVideoKHR" ) );

      //=== VK_EXT_transform_feedback ===
      vkCmdBindTransformFeedbackBuffersEXT =
        PFN_vkCmdBindTransformFeedbackBuffersEXT( vkGetInstanceProcAddr( instance, "vkCmdBindTransformFeedbackBuffersEXT" ) );
      vkCmdBeginTransformFeedbackEXT = PFN_vkCmdBeginTransformFeedbackEXT( vkGetInstanceProcAddr( instance, "vkCmdBeginTransformFeedbackEXT" ) );
      vkCmdEndTransformFeedbackEXT   = PFN_vkCmdEndTransformFeedbackEXT( vkGetInstanceProcAddr( instance, "vkCmdEndTransformFeedbackEXT" ) );
      vkCmdBeginQueryIndexedEXT      = PFN_vkCmdBeginQueryIndexedEXT( vkGetInstanceProcAddr( instance, "vkCmdBeginQueryIndexedEXT" ) );
      vkCmdEndQueryIndexedEXT        = PFN_vkCmdEndQueryIndexedEXT( vkGetInstanceProcAddr( instance, "vkCmdEndQueryIndexedEXT" ) );
      vkCmdDrawIndirectByteCountEXT  = PFN_vkCmdDrawIndirectByteCountEXT( vkGetInstanceProcAddr( instance, "vkCmdDrawIndirectByteCountEXT" ) );

      //=== VK_NVX_binary_import ===
      vkCreateCuModuleNVX    = PFN_vkCreateCuModuleNVX( vkGetInstanceProcAddr( instance, "vkCreateCuModuleNVX" ) );
      vkCreateCuFunctionNVX  = PFN_vkCreateCuFunctionNVX( vkGetInstanceProcAddr( instance, "vkCreateCuFunctionNVX" ) );
      vkDestroyCuModuleNVX   = PFN_vkDestroyCuModuleNVX( vkGetInstanceProcAddr( instance, "vkDestroyCuModuleNVX" ) );
      vkDestroyCuFunctionNVX = PFN_vkDestroyCuFunctionNVX( vkGetInstanceProcAddr( instance, "vkDestroyCuFunctionNVX" ) );
      vkCmdCuLaunchKernelNVX = PFN_vkCmdCuLaunchKernelNVX( vkGetInstanceProcAddr( instance, "vkCmdCuLaunchKernelNVX" ) );

      //=== VK_NVX_image_view_handle ===
      vkGetImageViewHandleNVX  = PFN_vkGetImageViewHandleNVX( vkGetInstanceProcAddr( instance, "vkGetImageViewHandleNVX" ) );
      vkGetImageViewAddressNVX = PFN_vkGetImageViewAddressNVX( vkGetInstanceProcAddr( instance, "vkGetImageViewAddressNVX" ) );

      //=== VK_AMD_draw_indirect_count ===
      vkCmdDrawIndirectCountAMD = PFN_vkCmdDrawIndirectCountAMD( vkGetInstanceProcAddr( instance, "vkCmdDrawIndirectCountAMD" ) );
      if ( !vkCmdDrawIndirectCount )
        vkCmdDrawIndirectCount = vkCmdDrawIndirectCountAMD;
      vkCmdDrawIndexedIndirectCountAMD = PFN_vkCmdDrawIndexedIndirectCountAMD( vkGetInstanceProcAddr( instance, "vkCmdDrawIndexedIndirectCountAMD" ) );
      if ( !vkCmdDrawIndexedIndirectCount )
        vkCmdDrawIndexedIndirectCount = vkCmdDrawIndexedIndirectCountAMD;

      //=== VK_AMD_shader_info ===
      vkGetShaderInfoAMD = PFN_vkGetShaderInfoAMD( vkGetInstanceProcAddr( instance, "vkGetShaderInfoAMD" ) );

      //=== VK_KHR_dynamic_rendering ===
      vkCmdBeginRenderingKHR = PFN_vkCmdBeginRenderingKHR( vkGetInstanceProcAddr( instance, "vkCmdBeginRenderingKHR" ) );
      if ( !vkCmdBeginRendering )
        vkCmdBeginRendering = vkCmdBeginRenderingKHR;
      vkCmdEndRenderingKHR = PFN_vkCmdEndRenderingKHR( vkGetInstanceProcAddr( instance, "vkCmdEndRenderingKHR" ) );
      if ( !vkCmdEndRendering )
        vkCmdEndRendering = vkCmdEndRenderingKHR;

#if defined( VK_USE_PLATFORM_GGP )
      //=== VK_GGP_stream_descriptor_surface ===
      vkCreateStreamDescriptorSurfaceGGP = PFN_vkCreateStreamDescriptorSurfaceGGP( vkGetInstanceProcAddr( instance, "vkCreateStreamDescriptorSurfaceGGP" ) );
#endif /*VK_USE_PLATFORM_GGP*/

       //=== VK_NV_external_memory_capabilities ===
      vkGetPhysicalDeviceExternalImageFormatPropertiesNV =
        PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceExternalImageFormatPropertiesNV" ) );

#if defined( VK_USE_PLATFORM_WIN32_KHR )
      //=== VK_NV_external_memory_win32 ===
      vkGetMemoryWin32HandleNV = PFN_vkGetMemoryWin32HandleNV( vkGetInstanceProcAddr( instance, "vkGetMemoryWin32HandleNV" ) );
#endif /*VK_USE_PLATFORM_WIN32_KHR*/

       //=== VK_KHR_get_physical_device_properties2 ===
      vkGetPhysicalDeviceFeatures2KHR = PFN_vkGetPhysicalDeviceFeatures2KHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceFeatures2KHR" ) );
      if ( !vkGetPhysicalDeviceFeatures2 )
        vkGetPhysicalDeviceFeatures2 = vkGetPhysicalDeviceFeatures2KHR;
      vkGetPhysicalDeviceProperties2KHR = PFN_vkGetPhysicalDeviceProperties2KHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceProperties2KHR" ) );
      if ( !vkGetPhysicalDeviceProperties2 )
        vkGetPhysicalDeviceProperties2 = vkGetPhysicalDeviceProperties2KHR;
      vkGetPhysicalDeviceFormatProperties2KHR =
        PFN_vkGetPhysicalDeviceFormatProperties2KHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceFormatProperties2KHR" ) );
      if ( !vkGetPhysicalDeviceFormatProperties2 )
        vkGetPhysicalDeviceFormatProperties2 = vkGetPhysicalDeviceFormatProperties2KHR;
      vkGetPhysicalDeviceImageFormatProperties2KHR =
        PFN_vkGetPhysicalDeviceImageFormatProperties2KHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceImageFormatProperties2KHR" ) );
      if ( !vkGetPhysicalDeviceImageFormatProperties2 )
        vkGetPhysicalDeviceImageFormatProperties2 = vkGetPhysicalDeviceImageFormatProperties2KHR;
      vkGetPhysicalDeviceQueueFamilyProperties2KHR =
        PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceQueueFamilyProperties2KHR" ) );
      if ( !vkGetPhysicalDeviceQueueFamilyProperties2 )
        vkGetPhysicalDeviceQueueFamilyProperties2 = vkGetPhysicalDeviceQueueFamilyProperties2KHR;
      vkGetPhysicalDeviceMemoryProperties2KHR =
        PFN_vkGetPhysicalDeviceMemoryProperties2KHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceMemoryProperties2KHR" ) );
      if ( !vkGetPhysicalDeviceMemoryProperties2 )
        vkGetPhysicalDeviceMemoryProperties2 = vkGetPhysicalDeviceMemoryProperties2KHR;
      vkGetPhysicalDeviceSparseImageFormatProperties2KHR =
        PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR" ) );
      if ( !vkGetPhysicalDeviceSparseImageFormatProperties2 )
        vkGetPhysicalDeviceSparseImageFormatProperties2 = vkGetPhysicalDeviceSparseImageFormatProperties2KHR;

      //=== VK_KHR_device_group ===
      vkGetDeviceGroupPeerMemoryFeaturesKHR =
        PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR( vkGetInstanceProcAddr( instance, "vkGetDeviceGroupPeerMemoryFeaturesKHR" ) );
      if ( !vkGetDeviceGroupPeerMemoryFeatures )
        vkGetDeviceGroupPeerMemoryFeatures = vkGetDeviceGroupPeerMemoryFeaturesKHR;
      vkCmdSetDeviceMaskKHR = PFN_vkCmdSetDeviceMaskKHR( vkGetInstanceProcAddr( instance, "vkCmdSetDeviceMaskKHR" ) );
      if ( !vkCmdSetDeviceMask )
        vkCmdSetDeviceMask = vkCmdSetDeviceMaskKHR;
      vkCmdDispatchBaseKHR = PFN_vkCmdDispatchBaseKHR( vkGetInstanceProcAddr( instance, "vkCmdDispatchBaseKHR" ) );
      if ( !vkCmdDispatchBase )
        vkCmdDispatchBase = vkCmdDispatchBaseKHR;

#if defined( VK_USE_PLATFORM_VI_NN )
      //=== VK_NN_vi_surface ===
      vkCreateViSurfaceNN = PFN_vkCreateViSurfaceNN( vkGetInstanceProcAddr( instance, "vkCreateViSurfaceNN" ) );
#endif /*VK_USE_PLATFORM_VI_NN*/

       //=== VK_KHR_maintenance1 ===
      vkTrimCommandPoolKHR = PFN_vkTrimCommandPoolKHR( vkGetInstanceProcAddr( instance, "vkTrimCommandPoolKHR" ) );
      if ( !vkTrimCommandPool )
        vkTrimCommandPool = vkTrimCommandPoolKHR;

      //=== VK_KHR_device_group_creation ===
      vkEnumeratePhysicalDeviceGroupsKHR = PFN_vkEnumeratePhysicalDeviceGroupsKHR( vkGetInstanceProcAddr( instance, "vkEnumeratePhysicalDeviceGroupsKHR" ) );
      if ( !vkEnumeratePhysicalDeviceGroups )
        vkEnumeratePhysicalDeviceGroups = vkEnumeratePhysicalDeviceGroupsKHR;

      //=== VK_KHR_external_memory_capabilities ===
      vkGetPhysicalDeviceExternalBufferPropertiesKHR =
        PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceExternalBufferPropertiesKHR" ) );
      if ( !vkGetPhysicalDeviceExternalBufferProperties )
        vkGetPhysicalDeviceExternalBufferProperties = vkGetPhysicalDeviceExternalBufferPropertiesKHR;

#if defined( VK_USE_PLATFORM_WIN32_KHR )
      //=== VK_KHR_external_memory_win32 ===
      vkGetMemoryWin32HandleKHR           = PFN_vkGetMemoryWin32HandleKHR( vkGetInstanceProcAddr( instance, "vkGetMemoryWin32HandleKHR" ) );
      vkGetMemoryWin32HandlePropertiesKHR = PFN_vkGetMemoryWin32HandlePropertiesKHR( vkGetInstanceProcAddr( instance, "vkGetMemoryWin32HandlePropertiesKHR" ) );
#endif /*VK_USE_PLATFORM_WIN32_KHR*/

       //=== VK_KHR_external_memory_fd ===
      vkGetMemoryFdKHR           = PFN_vkGetMemoryFdKHR( vkGetInstanceProcAddr( instance, "vkGetMemoryFdKHR" ) );
      vkGetMemoryFdPropertiesKHR = PFN_vkGetMemoryFdPropertiesKHR( vkGetInstanceProcAddr( instance, "vkGetMemoryFdPropertiesKHR" ) );

      //=== VK_KHR_external_semaphore_capabilities ===
      vkGetPhysicalDeviceExternalSemaphorePropertiesKHR =
        PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR" ) );
      if ( !vkGetPhysicalDeviceExternalSemaphoreProperties )
        vkGetPhysicalDeviceExternalSemaphoreProperties = vkGetPhysicalDeviceExternalSemaphorePropertiesKHR;

#if defined( VK_USE_PLATFORM_WIN32_KHR )
      //=== VK_KHR_external_semaphore_win32 ===
      vkImportSemaphoreWin32HandleKHR = PFN_vkImportSemaphoreWin32HandleKHR( vkGetInstanceProcAddr( instance, "vkImportSemaphoreWin32HandleKHR" ) );
      vkGetSemaphoreWin32HandleKHR    = PFN_vkGetSemaphoreWin32HandleKHR( vkGetInstanceProcAddr( instance, "vkGetSemaphoreWin32HandleKHR" ) );
#endif /*VK_USE_PLATFORM_WIN32_KHR*/

       //=== VK_KHR_external_semaphore_fd ===
      vkImportSemaphoreFdKHR = PFN_vkImportSemaphoreFdKHR( vkGetInstanceProcAddr( instance, "vkImportSemaphoreFdKHR" ) );
      vkGetSemaphoreFdKHR    = PFN_vkGetSemaphoreFdKHR( vkGetInstanceProcAddr( instance, "vkGetSemaphoreFdKHR" ) );

      //=== VK_KHR_push_descriptor ===
      vkCmdPushDescriptorSetKHR = PFN_vkCmdPushDescriptorSetKHR( vkGetInstanceProcAddr( instance, "vkCmdPushDescriptorSetKHR" ) );
      vkCmdPushDescriptorSetWithTemplateKHR =
        PFN_vkCmdPushDescriptorSetWithTemplateKHR( vkGetInstanceProcAddr( instance, "vkCmdPushDescriptorSetWithTemplateKHR" ) );

      //=== VK_EXT_conditional_rendering ===
      vkCmdBeginConditionalRenderingEXT = PFN_vkCmdBeginConditionalRenderingEXT( vkGetInstanceProcAddr( instance, "vkCmdBeginConditionalRenderingEXT" ) );
      vkCmdEndConditionalRenderingEXT   = PFN_vkCmdEndConditionalRenderingEXT( vkGetInstanceProcAddr( instance, "vkCmdEndConditionalRenderingEXT" ) );

      //=== VK_KHR_descriptor_update_template ===
      vkCreateDescriptorUpdateTemplateKHR = PFN_vkCreateDescriptorUpdateTemplateKHR( vkGetInstanceProcAddr( instance, "vkCreateDescriptorUpdateTemplateKHR" ) );
      if ( !vkCreateDescriptorUpdateTemplate )
        vkCreateDescriptorUpdateTemplate = vkCreateDescriptorUpdateTemplateKHR;
      vkDestroyDescriptorUpdateTemplateKHR =
        PFN_vkDestroyDescriptorUpdateTemplateKHR( vkGetInstanceProcAddr( instance, "vkDestroyDescriptorUpdateTemplateKHR" ) );
      if ( !vkDestroyDescriptorUpdateTemplate )
        vkDestroyDescriptorUpdateTemplate = vkDestroyDescriptorUpdateTemplateKHR;
      vkUpdateDescriptorSetWithTemplateKHR =
        PFN_vkUpdateDescriptorSetWithTemplateKHR( vkGetInstanceProcAddr( instance, "vkUpdateDescriptorSetWithTemplateKHR" ) );
      if ( !vkUpdateDescriptorSetWithTemplate )
        vkUpdateDescriptorSetWithTemplate = vkUpdateDescriptorSetWithTemplateKHR;

      //=== VK_NV_clip_space_w_scaling ===
      vkCmdSetViewportWScalingNV = PFN_vkCmdSetViewportWScalingNV( vkGetInstanceProcAddr( instance, "vkCmdSetViewportWScalingNV" ) );

      //=== VK_EXT_direct_mode_display ===
      vkReleaseDisplayEXT = PFN_vkReleaseDisplayEXT( vkGetInstanceProcAddr( instance, "vkReleaseDisplayEXT" ) );

#if defined( VK_USE_PLATFORM_XLIB_XRANDR_EXT )
      //=== VK_EXT_acquire_xlib_display ===
      vkAcquireXlibDisplayEXT    = PFN_vkAcquireXlibDisplayEXT( vkGetInstanceProcAddr( instance, "vkAcquireXlibDisplayEXT" ) );
      vkGetRandROutputDisplayEXT = PFN_vkGetRandROutputDisplayEXT( vkGetInstanceProcAddr( instance, "vkGetRandROutputDisplayEXT" ) );
#endif /*VK_USE_PLATFORM_XLIB_XRANDR_EXT*/

       //=== VK_EXT_display_surface_counter ===
      vkGetPhysicalDeviceSurfaceCapabilities2EXT =
        PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceSurfaceCapabilities2EXT" ) );

      //=== VK_EXT_display_control ===
      vkDisplayPowerControlEXT  = PFN_vkDisplayPowerControlEXT( vkGetInstanceProcAddr( instance, "vkDisplayPowerControlEXT" ) );
      vkRegisterDeviceEventEXT  = PFN_vkRegisterDeviceEventEXT( vkGetInstanceProcAddr( instance, "vkRegisterDeviceEventEXT" ) );
      vkRegisterDisplayEventEXT = PFN_vkRegisterDisplayEventEXT( vkGetInstanceProcAddr( instance, "vkRegisterDisplayEventEXT" ) );
      vkGetSwapchainCounterEXT  = PFN_vkGetSwapchainCounterEXT( vkGetInstanceProcAddr( instance, "vkGetSwapchainCounterEXT" ) );

      //=== VK_GOOGLE_display_timing ===
      vkGetRefreshCycleDurationGOOGLE   = PFN_vkGetRefreshCycleDurationGOOGLE( vkGetInstanceProcAddr( instance, "vkGetRefreshCycleDurationGOOGLE" ) );
      vkGetPastPresentationTimingGOOGLE = PFN_vkGetPastPresentationTimingGOOGLE( vkGetInstanceProcAddr( instance, "vkGetPastPresentationTimingGOOGLE" ) );

      //=== VK_EXT_discard_rectangles ===
      vkCmdSetDiscardRectangleEXT = PFN_vkCmdSetDiscardRectangleEXT( vkGetInstanceProcAddr( instance, "vkCmdSetDiscardRectangleEXT" ) );

      //=== VK_EXT_hdr_metadata ===
      vkSetHdrMetadataEXT = PFN_vkSetHdrMetadataEXT( vkGetInstanceProcAddr( instance, "vkSetHdrMetadataEXT" ) );

      //=== VK_KHR_create_renderpass2 ===
      vkCreateRenderPass2KHR = PFN_vkCreateRenderPass2KHR( vkGetInstanceProcAddr( instance, "vkCreateRenderPass2KHR" ) );
      if ( !vkCreateRenderPass2 )
        vkCreateRenderPass2 = vkCreateRenderPass2KHR;
      vkCmdBeginRenderPass2KHR = PFN_vkCmdBeginRenderPass2KHR( vkGetInstanceProcAddr( instance, "vkCmdBeginRenderPass2KHR" ) );
      if ( !vkCmdBeginRenderPass2 )
        vkCmdBeginRenderPass2 = vkCmdBeginRenderPass2KHR;
      vkCmdNextSubpass2KHR = PFN_vkCmdNextSubpass2KHR( vkGetInstanceProcAddr( instance, "vkCmdNextSubpass2KHR" ) );
      if ( !vkCmdNextSubpass2 )
        vkCmdNextSubpass2 = vkCmdNextSubpass2KHR;
      vkCmdEndRenderPass2KHR = PFN_vkCmdEndRenderPass2KHR( vkGetInstanceProcAddr( instance, "vkCmdEndRenderPass2KHR" ) );
      if ( !vkCmdEndRenderPass2 )
        vkCmdEndRenderPass2 = vkCmdEndRenderPass2KHR;

      //=== VK_KHR_shared_presentable_image ===
      vkGetSwapchainStatusKHR = PFN_vkGetSwapchainStatusKHR( vkGetInstanceProcAddr( instance, "vkGetSwapchainStatusKHR" ) );

      //=== VK_KHR_external_fence_capabilities ===
      vkGetPhysicalDeviceExternalFencePropertiesKHR =
        PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceExternalFencePropertiesKHR" ) );
      if ( !vkGetPhysicalDeviceExternalFenceProperties )
        vkGetPhysicalDeviceExternalFenceProperties = vkGetPhysicalDeviceExternalFencePropertiesKHR;

#if defined( VK_USE_PLATFORM_WIN32_KHR )
      //=== VK_KHR_external_fence_win32 ===
      vkImportFenceWin32HandleKHR = PFN_vkImportFenceWin32HandleKHR( vkGetInstanceProcAddr( instance, "vkImportFenceWin32HandleKHR" ) );
      vkGetFenceWin32HandleKHR    = PFN_vkGetFenceWin32HandleKHR( vkGetInstanceProcAddr( instance, "vkGetFenceWin32HandleKHR" ) );
#endif /*VK_USE_PLATFORM_WIN32_KHR*/

       //=== VK_KHR_external_fence_fd ===
      vkImportFenceFdKHR = PFN_vkImportFenceFdKHR( vkGetInstanceProcAddr( instance, "vkImportFenceFdKHR" ) );
      vkGetFenceFdKHR    = PFN_vkGetFenceFdKHR( vkGetInstanceProcAddr( instance, "vkGetFenceFdKHR" ) );

      //=== VK_KHR_performance_query ===
      vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR = PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
        vkGetInstanceProcAddr( instance, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR" ) );
      vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR = PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
        vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR" ) );
      vkAcquireProfilingLockKHR = PFN_vkAcquireProfilingLockKHR( vkGetInstanceProcAddr( instance, "vkAcquireProfilingLockKHR" ) );
      vkReleaseProfilingLockKHR = PFN_vkReleaseProfilingLockKHR( vkGetInstanceProcAddr( instance, "vkReleaseProfilingLockKHR" ) );

      //=== VK_KHR_get_surface_capabilities2 ===
      vkGetPhysicalDeviceSurfaceCapabilities2KHR =
        PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceSurfaceCapabilities2KHR" ) );
      vkGetPhysicalDeviceSurfaceFormats2KHR =
        PFN_vkGetPhysicalDeviceSurfaceFormats2KHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceSurfaceFormats2KHR" ) );

      //=== VK_KHR_get_display_properties2 ===
      vkGetPhysicalDeviceDisplayProperties2KHR =
        PFN_vkGetPhysicalDeviceDisplayProperties2KHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceDisplayProperties2KHR" ) );
      vkGetPhysicalDeviceDisplayPlaneProperties2KHR =
        PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR" ) );
      vkGetDisplayModeProperties2KHR    = PFN_vkGetDisplayModeProperties2KHR( vkGetInstanceProcAddr( instance, "vkGetDisplayModeProperties2KHR" ) );
      vkGetDisplayPlaneCapabilities2KHR = PFN_vkGetDisplayPlaneCapabilities2KHR( vkGetInstanceProcAddr( instance, "vkGetDisplayPlaneCapabilities2KHR" ) );

#if defined( VK_USE_PLATFORM_IOS_MVK )
      //=== VK_MVK_ios_surface ===
      vkCreateIOSSurfaceMVK = PFN_vkCreateIOSSurfaceMVK( vkGetInstanceProcAddr( instance, "vkCreateIOSSurfaceMVK" ) );
#endif /*VK_USE_PLATFORM_IOS_MVK*/

#if defined( VK_USE_PLATFORM_MACOS_MVK )
      //=== VK_MVK_macos_surface ===
      vkCreateMacOSSurfaceMVK = PFN_vkCreateMacOSSurfaceMVK( vkGetInstanceProcAddr( instance, "vkCreateMacOSSurfaceMVK" ) );
#endif /*VK_USE_PLATFORM_MACOS_MVK*/

       //=== VK_EXT_debug_utils ===
      vkSetDebugUtilsObjectNameEXT    = PFN_vkSetDebugUtilsObjectNameEXT( vkGetInstanceProcAddr( instance, "vkSetDebugUtilsObjectNameEXT" ) );
      vkSetDebugUtilsObjectTagEXT     = PFN_vkSetDebugUtilsObjectTagEXT( vkGetInstanceProcAddr( instance, "vkSetDebugUtilsObjectTagEXT" ) );
      vkQueueBeginDebugUtilsLabelEXT  = PFN_vkQueueBeginDebugUtilsLabelEXT( vkGetInstanceProcAddr( instance, "vkQueueBeginDebugUtilsLabelEXT" ) );
      vkQueueEndDebugUtilsLabelEXT    = PFN_vkQueueEndDebugUtilsLabelEXT( vkGetInstanceProcAddr( instance, "vkQueueEndDebugUtilsLabelEXT" ) );
      vkQueueInsertDebugUtilsLabelEXT = PFN_vkQueueInsertDebugUtilsLabelEXT( vkGetInstanceProcAddr( instance, "vkQueueInsertDebugUtilsLabelEXT" ) );
      vkCmdBeginDebugUtilsLabelEXT    = PFN_vkCmdBeginDebugUtilsLabelEXT( vkGetInstanceProcAddr( instance, "vkCmdBeginDebugUtilsLabelEXT" ) );
      vkCmdEndDebugUtilsLabelEXT      = PFN_vkCmdEndDebugUtilsLabelEXT( vkGetInstanceProcAddr( instance, "vkCmdEndDebugUtilsLabelEXT" ) );
      vkCmdInsertDebugUtilsLabelEXT   = PFN_vkCmdInsertDebugUtilsLabelEXT( vkGetInstanceProcAddr( instance, "vkCmdInsertDebugUtilsLabelEXT" ) );
      vkCreateDebugUtilsMessengerEXT  = PFN_vkCreateDebugUtilsMessengerEXT( vkGetInstanceProcAddr( instance, "vkCreateDebugUtilsMessengerEXT" ) );
      vkDestroyDebugUtilsMessengerEXT = PFN_vkDestroyDebugUtilsMessengerEXT( vkGetInstanceProcAddr( instance, "vkDestroyDebugUtilsMessengerEXT" ) );
      vkSubmitDebugUtilsMessageEXT    = PFN_vkSubmitDebugUtilsMessageEXT( vkGetInstanceProcAddr( instance, "vkSubmitDebugUtilsMessageEXT" ) );

#if defined( VK_USE_PLATFORM_ANDROID_KHR )
      //=== VK_ANDROID_external_memory_android_hardware_buffer ===
      vkGetAndroidHardwareBufferPropertiesANDROID =
        PFN_vkGetAndroidHardwareBufferPropertiesANDROID( vkGetInstanceProcAddr( instance, "vkGetAndroidHardwareBufferPropertiesANDROID" ) );
      vkGetMemoryAndroidHardwareBufferANDROID =
        PFN_vkGetMemoryAndroidHardwareBufferANDROID( vkGetInstanceProcAddr( instance, "vkGetMemoryAndroidHardwareBufferANDROID" ) );
#endif /*VK_USE_PLATFORM_ANDROID_KHR*/

       //=== VK_EXT_sample_locations ===
      vkCmdSetSampleLocationsEXT = PFN_vkCmdSetSampleLocationsEXT( vkGetInstanceProcAddr( instance, "vkCmdSetSampleLocationsEXT" ) );
      vkGetPhysicalDeviceMultisamplePropertiesEXT =
        PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceMultisamplePropertiesEXT" ) );

      //=== VK_KHR_get_memory_requirements2 ===
      vkGetImageMemoryRequirements2KHR = PFN_vkGetImageMemoryRequirements2KHR( vkGetInstanceProcAddr( instance, "vkGetImageMemoryRequirements2KHR" ) );
      if ( !vkGetImageMemoryRequirements2 )
        vkGetImageMemoryRequirements2 = vkGetImageMemoryRequirements2KHR;
      vkGetBufferMemoryRequirements2KHR = PFN_vkGetBufferMemoryRequirements2KHR( vkGetInstanceProcAddr( instance, "vkGetBufferMemoryRequirements2KHR" ) );
      if ( !vkGetBufferMemoryRequirements2 )
        vkGetBufferMemoryRequirements2 = vkGetBufferMemoryRequirements2KHR;
      vkGetImageSparseMemoryRequirements2KHR =
        PFN_vkGetImageSparseMemoryRequirements2KHR( vkGetInstanceProcAddr( instance, "vkGetImageSparseMemoryRequirements2KHR" ) );
      if ( !vkGetImageSparseMemoryRequirements2 )
        vkGetImageSparseMemoryRequirements2 = vkGetImageSparseMemoryRequirements2KHR;

      //=== VK_KHR_acceleration_structure ===
      vkCreateAccelerationStructureKHR    = PFN_vkCreateAccelerationStructureKHR( vkGetInstanceProcAddr( instance, "vkCreateAccelerationStructureKHR" ) );
      vkDestroyAccelerationStructureKHR   = PFN_vkDestroyAccelerationStructureKHR( vkGetInstanceProcAddr( instance, "vkDestroyAccelerationStructureKHR" ) );
      vkCmdBuildAccelerationStructuresKHR = PFN_vkCmdBuildAccelerationStructuresKHR( vkGetInstanceProcAddr( instance, "vkCmdBuildAccelerationStructuresKHR" ) );
      vkCmdBuildAccelerationStructuresIndirectKHR =
        PFN_vkCmdBuildAccelerationStructuresIndirectKHR( vkGetInstanceProcAddr( instance, "vkCmdBuildAccelerationStructuresIndirectKHR" ) );
      vkBuildAccelerationStructuresKHR = PFN_vkBuildAccelerationStructuresKHR( vkGetInstanceProcAddr( instance, "vkBuildAccelerationStructuresKHR" ) );
      vkCopyAccelerationStructureKHR   = PFN_vkCopyAccelerationStructureKHR( vkGetInstanceProcAddr( instance, "vkCopyAccelerationStructureKHR" ) );
      vkCopyAccelerationStructureToMemoryKHR =
        PFN_vkCopyAccelerationStructureToMemoryKHR( vkGetInstanceProcAddr( instance, "vkCopyAccelerationStructureToMemoryKHR" ) );
      vkCopyMemoryToAccelerationStructureKHR =
        PFN_vkCopyMemoryToAccelerationStructureKHR( vkGetInstanceProcAddr( instance, "vkCopyMemoryToAccelerationStructureKHR" ) );
      vkWriteAccelerationStructuresPropertiesKHR =
        PFN_vkWriteAccelerationStructuresPropertiesKHR( vkGetInstanceProcAddr( instance, "vkWriteAccelerationStructuresPropertiesKHR" ) );
      vkCmdCopyAccelerationStructureKHR = PFN_vkCmdCopyAccelerationStructureKHR( vkGetInstanceProcAddr( instance, "vkCmdCopyAccelerationStructureKHR" ) );
      vkCmdCopyAccelerationStructureToMemoryKHR =
        PFN_vkCmdCopyAccelerationStructureToMemoryKHR( vkGetInstanceProcAddr( instance, "vkCmdCopyAccelerationStructureToMemoryKHR" ) );
      vkCmdCopyMemoryToAccelerationStructureKHR =
        PFN_vkCmdCopyMemoryToAccelerationStructureKHR( vkGetInstanceProcAddr( instance, "vkCmdCopyMemoryToAccelerationStructureKHR" ) );
      vkGetAccelerationStructureDeviceAddressKHR =
        PFN_vkGetAccelerationStructureDeviceAddressKHR( vkGetInstanceProcAddr( instance, "vkGetAccelerationStructureDeviceAddressKHR" ) );
      vkCmdWriteAccelerationStructuresPropertiesKHR =
        PFN_vkCmdWriteAccelerationStructuresPropertiesKHR( vkGetInstanceProcAddr( instance, "vkCmdWriteAccelerationStructuresPropertiesKHR" ) );
      vkGetDeviceAccelerationStructureCompatibilityKHR =
        PFN_vkGetDeviceAccelerationStructureCompatibilityKHR( vkGetInstanceProcAddr( instance, "vkGetDeviceAccelerationStructureCompatibilityKHR" ) );
      vkGetAccelerationStructureBuildSizesKHR =
        PFN_vkGetAccelerationStructureBuildSizesKHR( vkGetInstanceProcAddr( instance, "vkGetAccelerationStructureBuildSizesKHR" ) );

      //=== VK_KHR_sampler_ycbcr_conversion ===
      vkCreateSamplerYcbcrConversionKHR = PFN_vkCreateSamplerYcbcrConversionKHR( vkGetInstanceProcAddr( instance, "vkCreateSamplerYcbcrConversionKHR" ) );
      if ( !vkCreateSamplerYcbcrConversion )
        vkCreateSamplerYcbcrConversion = vkCreateSamplerYcbcrConversionKHR;
      vkDestroySamplerYcbcrConversionKHR = PFN_vkDestroySamplerYcbcrConversionKHR( vkGetInstanceProcAddr( instance, "vkDestroySamplerYcbcrConversionKHR" ) );
      if ( !vkDestroySamplerYcbcrConversion )
        vkDestroySamplerYcbcrConversion = vkDestroySamplerYcbcrConversionKHR;

      //=== VK_KHR_bind_memory2 ===
      vkBindBufferMemory2KHR = PFN_vkBindBufferMemory2KHR( vkGetInstanceProcAddr( instance, "vkBindBufferMemory2KHR" ) );
      if ( !vkBindBufferMemory2 )
        vkBindBufferMemory2 = vkBindBufferMemory2KHR;
      vkBindImageMemory2KHR = PFN_vkBindImageMemory2KHR( vkGetInstanceProcAddr( instance, "vkBindImageMemory2KHR" ) );
      if ( !vkBindImageMemory2 )
        vkBindImageMemory2 = vkBindImageMemory2KHR;

      //=== VK_EXT_image_drm_format_modifier ===
      vkGetImageDrmFormatModifierPropertiesEXT =
        PFN_vkGetImageDrmFormatModifierPropertiesEXT( vkGetInstanceProcAddr( instance, "vkGetImageDrmFormatModifierPropertiesEXT" ) );

      //=== VK_EXT_validation_cache ===
      vkCreateValidationCacheEXT  = PFN_vkCreateValidationCacheEXT( vkGetInstanceProcAddr( instance, "vkCreateValidationCacheEXT" ) );
      vkDestroyValidationCacheEXT = PFN_vkDestroyValidationCacheEXT( vkGetInstanceProcAddr( instance, "vkDestroyValidationCacheEXT" ) );
      vkMergeValidationCachesEXT  = PFN_vkMergeValidationCachesEXT( vkGetInstanceProcAddr( instance, "vkMergeValidationCachesEXT" ) );
      vkGetValidationCacheDataEXT = PFN_vkGetValidationCacheDataEXT( vkGetInstanceProcAddr( instance, "vkGetValidationCacheDataEXT" ) );

      //=== VK_NV_shading_rate_image ===
      vkCmdBindShadingRateImageNV = PFN_vkCmdBindShadingRateImageNV( vkGetInstanceProcAddr( instance, "vkCmdBindShadingRateImageNV" ) );
      vkCmdSetViewportShadingRatePaletteNV =
        PFN_vkCmdSetViewportShadingRatePaletteNV( vkGetInstanceProcAddr( instance, "vkCmdSetViewportShadingRatePaletteNV" ) );
      vkCmdSetCoarseSampleOrderNV = PFN_vkCmdSetCoarseSampleOrderNV( vkGetInstanceProcAddr( instance, "vkCmdSetCoarseSampleOrderNV" ) );

      //=== VK_NV_ray_tracing ===
      vkCreateAccelerationStructureNV  = PFN_vkCreateAccelerationStructureNV( vkGetInstanceProcAddr( instance, "vkCreateAccelerationStructureNV" ) );
      vkDestroyAccelerationStructureNV = PFN_vkDestroyAccelerationStructureNV( vkGetInstanceProcAddr( instance, "vkDestroyAccelerationStructureNV" ) );
      vkGetAccelerationStructureMemoryRequirementsNV =
        PFN_vkGetAccelerationStructureMemoryRequirementsNV( vkGetInstanceProcAddr( instance, "vkGetAccelerationStructureMemoryRequirementsNV" ) );
      vkBindAccelerationStructureMemoryNV = PFN_vkBindAccelerationStructureMemoryNV( vkGetInstanceProcAddr( instance, "vkBindAccelerationStructureMemoryNV" ) );
      vkCmdBuildAccelerationStructureNV   = PFN_vkCmdBuildAccelerationStructureNV( vkGetInstanceProcAddr( instance, "vkCmdBuildAccelerationStructureNV" ) );
      vkCmdCopyAccelerationStructureNV    = PFN_vkCmdCopyAccelerationStructureNV( vkGetInstanceProcAddr( instance, "vkCmdCopyAccelerationStructureNV" ) );
      vkCmdTraceRaysNV                    = PFN_vkCmdTraceRaysNV( vkGetInstanceProcAddr( instance, "vkCmdTraceRaysNV" ) );
      vkCreateRayTracingPipelinesNV       = PFN_vkCreateRayTracingPipelinesNV( vkGetInstanceProcAddr( instance, "vkCreateRayTracingPipelinesNV" ) );
      vkGetRayTracingShaderGroupHandlesNV = PFN_vkGetRayTracingShaderGroupHandlesNV( vkGetInstanceProcAddr( instance, "vkGetRayTracingShaderGroupHandlesNV" ) );
      if ( !vkGetRayTracingShaderGroupHandlesKHR )
        vkGetRayTracingShaderGroupHandlesKHR = vkGetRayTracingShaderGroupHandlesNV;
      vkGetAccelerationStructureHandleNV = PFN_vkGetAccelerationStructureHandleNV( vkGetInstanceProcAddr( instance, "vkGetAccelerationStructureHandleNV" ) );
      vkCmdWriteAccelerationStructuresPropertiesNV =
        PFN_vkCmdWriteAccelerationStructuresPropertiesNV( vkGetInstanceProcAddr( instance, "vkCmdWriteAccelerationStructuresPropertiesNV" ) );
      vkCompileDeferredNV = PFN_vkCompileDeferredNV( vkGetInstanceProcAddr( instance, "vkCompileDeferredNV" ) );

      //=== VK_KHR_maintenance3 ===
      vkGetDescriptorSetLayoutSupportKHR = PFN_vkGetDescriptorSetLayoutSupportKHR( vkGetInstanceProcAddr( instance, "vkGetDescriptorSetLayoutSupportKHR" ) );
      if ( !vkGetDescriptorSetLayoutSupport )
        vkGetDescriptorSetLayoutSupport = vkGetDescriptorSetLayoutSupportKHR;

      //=== VK_KHR_draw_indirect_count ===
      vkCmdDrawIndirectCountKHR = PFN_vkCmdDrawIndirectCountKHR( vkGetInstanceProcAddr( instance, "vkCmdDrawIndirectCountKHR" ) );
      if ( !vkCmdDrawIndirectCount )
        vkCmdDrawIndirectCount = vkCmdDrawIndirectCountKHR;
      vkCmdDrawIndexedIndirectCountKHR = PFN_vkCmdDrawIndexedIndirectCountKHR( vkGetInstanceProcAddr( instance, "vkCmdDrawIndexedIndirectCountKHR" ) );
      if ( !vkCmdDrawIndexedIndirectCount )
        vkCmdDrawIndexedIndirectCount = vkCmdDrawIndexedIndirectCountKHR;

      //=== VK_EXT_external_memory_host ===
      vkGetMemoryHostPointerPropertiesEXT = PFN_vkGetMemoryHostPointerPropertiesEXT( vkGetInstanceProcAddr( instance, "vkGetMemoryHostPointerPropertiesEXT" ) );

      //=== VK_AMD_buffer_marker ===
      vkCmdWriteBufferMarkerAMD = PFN_vkCmdWriteBufferMarkerAMD( vkGetInstanceProcAddr( instance, "vkCmdWriteBufferMarkerAMD" ) );

      //=== VK_EXT_calibrated_timestamps ===
      vkGetPhysicalDeviceCalibrateableTimeDomainsEXT =
        PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT" ) );
      vkGetCalibratedTimestampsEXT = PFN_vkGetCalibratedTimestampsEXT( vkGetInstanceProcAddr( instance, "vkGetCalibratedTimestampsEXT" ) );

      //=== VK_NV_mesh_shader ===
      vkCmdDrawMeshTasksNV              = PFN_vkCmdDrawMeshTasksNV( vkGetInstanceProcAddr( instance, "vkCmdDrawMeshTasksNV" ) );
      vkCmdDrawMeshTasksIndirectNV      = PFN_vkCmdDrawMeshTasksIndirectNV( vkGetInstanceProcAddr( instance, "vkCmdDrawMeshTasksIndirectNV" ) );
      vkCmdDrawMeshTasksIndirectCountNV = PFN_vkCmdDrawMeshTasksIndirectCountNV( vkGetInstanceProcAddr( instance, "vkCmdDrawMeshTasksIndirectCountNV" ) );

      //=== VK_NV_scissor_exclusive ===
      vkCmdSetExclusiveScissorNV = PFN_vkCmdSetExclusiveScissorNV( vkGetInstanceProcAddr( instance, "vkCmdSetExclusiveScissorNV" ) );

      //=== VK_NV_device_diagnostic_checkpoints ===
      vkCmdSetCheckpointNV       = PFN_vkCmdSetCheckpointNV( vkGetInstanceProcAddr( instance, "vkCmdSetCheckpointNV" ) );
      vkGetQueueCheckpointDataNV = PFN_vkGetQueueCheckpointDataNV( vkGetInstanceProcAddr( instance, "vkGetQueueCheckpointDataNV" ) );

      //=== VK_KHR_timeline_semaphore ===
      vkGetSemaphoreCounterValueKHR = PFN_vkGetSemaphoreCounterValueKHR( vkGetInstanceProcAddr( instance, "vkGetSemaphoreCounterValueKHR" ) );
      if ( !vkGetSemaphoreCounterValue )
        vkGetSemaphoreCounterValue = vkGetSemaphoreCounterValueKHR;
      vkWaitSemaphoresKHR = PFN_vkWaitSemaphoresKHR( vkGetInstanceProcAddr( instance, "vkWaitSemaphoresKHR" ) );
      if ( !vkWaitSemaphores )
        vkWaitSemaphores = vkWaitSemaphoresKHR;
      vkSignalSemaphoreKHR = PFN_vkSignalSemaphoreKHR( vkGetInstanceProcAddr( instance, "vkSignalSemaphoreKHR" ) );
      if ( !vkSignalSemaphore )
        vkSignalSemaphore = vkSignalSemaphoreKHR;

      //=== VK_INTEL_performance_query ===
      vkInitializePerformanceApiINTEL   = PFN_vkInitializePerformanceApiINTEL( vkGetInstanceProcAddr( instance, "vkInitializePerformanceApiINTEL" ) );
      vkUninitializePerformanceApiINTEL = PFN_vkUninitializePerformanceApiINTEL( vkGetInstanceProcAddr( instance, "vkUninitializePerformanceApiINTEL" ) );
      vkCmdSetPerformanceMarkerINTEL    = PFN_vkCmdSetPerformanceMarkerINTEL( vkGetInstanceProcAddr( instance, "vkCmdSetPerformanceMarkerINTEL" ) );
      vkCmdSetPerformanceStreamMarkerINTEL =
        PFN_vkCmdSetPerformanceStreamMarkerINTEL( vkGetInstanceProcAddr( instance, "vkCmdSetPerformanceStreamMarkerINTEL" ) );
      vkCmdSetPerformanceOverrideINTEL = PFN_vkCmdSetPerformanceOverrideINTEL( vkGetInstanceProcAddr( instance, "vkCmdSetPerformanceOverrideINTEL" ) );
      vkAcquirePerformanceConfigurationINTEL =
        PFN_vkAcquirePerformanceConfigurationINTEL( vkGetInstanceProcAddr( instance, "vkAcquirePerformanceConfigurationINTEL" ) );
      vkReleasePerformanceConfigurationINTEL =
        PFN_vkReleasePerformanceConfigurationINTEL( vkGetInstanceProcAddr( instance, "vkReleasePerformanceConfigurationINTEL" ) );
      vkQueueSetPerformanceConfigurationINTEL =
        PFN_vkQueueSetPerformanceConfigurationINTEL( vkGetInstanceProcAddr( instance, "vkQueueSetPerformanceConfigurationINTEL" ) );
      vkGetPerformanceParameterINTEL = PFN_vkGetPerformanceParameterINTEL( vkGetInstanceProcAddr( instance, "vkGetPerformanceParameterINTEL" ) );

      //=== VK_AMD_display_native_hdr ===
      vkSetLocalDimmingAMD = PFN_vkSetLocalDimmingAMD( vkGetInstanceProcAddr( instance, "vkSetLocalDimmingAMD" ) );

#if defined( VK_USE_PLATFORM_FUCHSIA )
      //=== VK_FUCHSIA_imagepipe_surface ===
      vkCreateImagePipeSurfaceFUCHSIA = PFN_vkCreateImagePipeSurfaceFUCHSIA( vkGetInstanceProcAddr( instance, "vkCreateImagePipeSurfaceFUCHSIA" ) );
#endif /*VK_USE_PLATFORM_FUCHSIA*/

#if defined( VK_USE_PLATFORM_METAL_EXT )
      //=== VK_EXT_metal_surface ===
      vkCreateMetalSurfaceEXT = PFN_vkCreateMetalSurfaceEXT( vkGetInstanceProcAddr( instance, "vkCreateMetalSurfaceEXT" ) );
#endif /*VK_USE_PLATFORM_METAL_EXT*/

       //=== VK_KHR_fragment_shading_rate ===
      vkGetPhysicalDeviceFragmentShadingRatesKHR =
        PFN_vkGetPhysicalDeviceFragmentShadingRatesKHR( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceFragmentShadingRatesKHR" ) );
      vkCmdSetFragmentShadingRateKHR = PFN_vkCmdSetFragmentShadingRateKHR( vkGetInstanceProcAddr( instance, "vkCmdSetFragmentShadingRateKHR" ) );

      //=== VK_EXT_buffer_device_address ===
      vkGetBufferDeviceAddressEXT = PFN_vkGetBufferDeviceAddressEXT( vkGetInstanceProcAddr( instance, "vkGetBufferDeviceAddressEXT" ) );
      if ( !vkGetBufferDeviceAddress )
        vkGetBufferDeviceAddress = vkGetBufferDeviceAddressEXT;

      //=== VK_EXT_tooling_info ===
      vkGetPhysicalDeviceToolPropertiesEXT =
        PFN_vkGetPhysicalDeviceToolPropertiesEXT( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceToolPropertiesEXT" ) );
      if ( !vkGetPhysicalDeviceToolProperties )
        vkGetPhysicalDeviceToolProperties = vkGetPhysicalDeviceToolPropertiesEXT;

      //=== VK_KHR_present_wait ===
      vkWaitForPresentKHR = PFN_vkWaitForPresentKHR( vkGetInstanceProcAddr( instance, "vkWaitForPresentKHR" ) );

      //=== VK_NV_cooperative_matrix ===
      vkGetPhysicalDeviceCooperativeMatrixPropertiesNV =
        PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV" ) );

      //=== VK_NV_coverage_reduction_mode ===
      vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV = PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
        vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV" ) );

#if defined( VK_USE_PLATFORM_WIN32_KHR )
      //=== VK_EXT_full_screen_exclusive ===
      vkGetPhysicalDeviceSurfacePresentModes2EXT =
        PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceSurfacePresentModes2EXT" ) );
      vkAcquireFullScreenExclusiveModeEXT = PFN_vkAcquireFullScreenExclusiveModeEXT( vkGetInstanceProcAddr( instance, "vkAcquireFullScreenExclusiveModeEXT" ) );
      vkReleaseFullScreenExclusiveModeEXT = PFN_vkReleaseFullScreenExclusiveModeEXT( vkGetInstanceProcAddr( instance, "vkReleaseFullScreenExclusiveModeEXT" ) );
      vkGetDeviceGroupSurfacePresentModes2EXT =
        PFN_vkGetDeviceGroupSurfacePresentModes2EXT( vkGetInstanceProcAddr( instance, "vkGetDeviceGroupSurfacePresentModes2EXT" ) );
#endif /*VK_USE_PLATFORM_WIN32_KHR*/

       //=== VK_EXT_headless_surface ===
      vkCreateHeadlessSurfaceEXT = PFN_vkCreateHeadlessSurfaceEXT( vkGetInstanceProcAddr( instance, "vkCreateHeadlessSurfaceEXT" ) );

      //=== VK_KHR_buffer_device_address ===
      vkGetBufferDeviceAddressKHR = PFN_vkGetBufferDeviceAddressKHR( vkGetInstanceProcAddr( instance, "vkGetBufferDeviceAddressKHR" ) );
      if ( !vkGetBufferDeviceAddress )
        vkGetBufferDeviceAddress = vkGetBufferDeviceAddressKHR;
      vkGetBufferOpaqueCaptureAddressKHR = PFN_vkGetBufferOpaqueCaptureAddressKHR( vkGetInstanceProcAddr( instance, "vkGetBufferOpaqueCaptureAddressKHR" ) );
      if ( !vkGetBufferOpaqueCaptureAddress )
        vkGetBufferOpaqueCaptureAddress = vkGetBufferOpaqueCaptureAddressKHR;
      vkGetDeviceMemoryOpaqueCaptureAddressKHR =
        PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR( vkGetInstanceProcAddr( instance, "vkGetDeviceMemoryOpaqueCaptureAddressKHR" ) );
      if ( !vkGetDeviceMemoryOpaqueCaptureAddress )
        vkGetDeviceMemoryOpaqueCaptureAddress = vkGetDeviceMemoryOpaqueCaptureAddressKHR;

      //=== VK_EXT_line_rasterization ===
      vkCmdSetLineStippleEXT = PFN_vkCmdSetLineStippleEXT( vkGetInstanceProcAddr( instance, "vkCmdSetLineStippleEXT" ) );

      //=== VK_EXT_host_query_reset ===
      vkResetQueryPoolEXT = PFN_vkResetQueryPoolEXT( vkGetInstanceProcAddr( instance, "vkResetQueryPoolEXT" ) );
      if ( !vkResetQueryPool )
        vkResetQueryPool = vkResetQueryPoolEXT;

      //=== VK_EXT_extended_dynamic_state ===
      vkCmdSetCullModeEXT = PFN_vkCmdSetCullModeEXT( vkGetInstanceProcAddr( instance, "vkCmdSetCullModeEXT" ) );
      if ( !vkCmdSetCullMode )
        vkCmdSetCullMode = vkCmdSetCullModeEXT;
      vkCmdSetFrontFaceEXT = PFN_vkCmdSetFrontFaceEXT( vkGetInstanceProcAddr( instance, "vkCmdSetFrontFaceEXT" ) );
      if ( !vkCmdSetFrontFace )
        vkCmdSetFrontFace = vkCmdSetFrontFaceEXT;
      vkCmdSetPrimitiveTopologyEXT = PFN_vkCmdSetPrimitiveTopologyEXT( vkGetInstanceProcAddr( instance, "vkCmdSetPrimitiveTopologyEXT" ) );
      if ( !vkCmdSetPrimitiveTopology )
        vkCmdSetPrimitiveTopology = vkCmdSetPrimitiveTopologyEXT;
      vkCmdSetViewportWithCountEXT = PFN_vkCmdSetViewportWithCountEXT( vkGetInstanceProcAddr( instance, "vkCmdSetViewportWithCountEXT" ) );
      if ( !vkCmdSetViewportWithCount )
        vkCmdSetViewportWithCount = vkCmdSetViewportWithCountEXT;
      vkCmdSetScissorWithCountEXT = PFN_vkCmdSetScissorWithCountEXT( vkGetInstanceProcAddr( instance, "vkCmdSetScissorWithCountEXT" ) );
      if ( !vkCmdSetScissorWithCount )
        vkCmdSetScissorWithCount = vkCmdSetScissorWithCountEXT;
      vkCmdBindVertexBuffers2EXT = PFN_vkCmdBindVertexBuffers2EXT( vkGetInstanceProcAddr( instance, "vkCmdBindVertexBuffers2EXT" ) );
      if ( !vkCmdBindVertexBuffers2 )
        vkCmdBindVertexBuffers2 = vkCmdBindVertexBuffers2EXT;
      vkCmdSetDepthTestEnableEXT = PFN_vkCmdSetDepthTestEnableEXT( vkGetInstanceProcAddr( instance, "vkCmdSetDepthTestEnableEXT" ) );
      if ( !vkCmdSetDepthTestEnable )
        vkCmdSetDepthTestEnable = vkCmdSetDepthTestEnableEXT;
      vkCmdSetDepthWriteEnableEXT = PFN_vkCmdSetDepthWriteEnableEXT( vkGetInstanceProcAddr( instance, "vkCmdSetDepthWriteEnableEXT" ) );
      if ( !vkCmdSetDepthWriteEnable )
        vkCmdSetDepthWriteEnable = vkCmdSetDepthWriteEnableEXT;
      vkCmdSetDepthCompareOpEXT = PFN_vkCmdSetDepthCompareOpEXT( vkGetInstanceProcAddr( instance, "vkCmdSetDepthCompareOpEXT" ) );
      if ( !vkCmdSetDepthCompareOp )
        vkCmdSetDepthCompareOp = vkCmdSetDepthCompareOpEXT;
      vkCmdSetDepthBoundsTestEnableEXT = PFN_vkCmdSetDepthBoundsTestEnableEXT( vkGetInstanceProcAddr( instance, "vkCmdSetDepthBoundsTestEnableEXT" ) );
      if ( !vkCmdSetDepthBoundsTestEnable )
        vkCmdSetDepthBoundsTestEnable = vkCmdSetDepthBoundsTestEnableEXT;
      vkCmdSetStencilTestEnableEXT = PFN_vkCmdSetStencilTestEnableEXT( vkGetInstanceProcAddr( instance, "vkCmdSetStencilTestEnableEXT" ) );
      if ( !vkCmdSetStencilTestEnable )
        vkCmdSetStencilTestEnable = vkCmdSetStencilTestEnableEXT;
      vkCmdSetStencilOpEXT = PFN_vkCmdSetStencilOpEXT( vkGetInstanceProcAddr( instance, "vkCmdSetStencilOpEXT" ) );
      if ( !vkCmdSetStencilOp )
        vkCmdSetStencilOp = vkCmdSetStencilOpEXT;

      //=== VK_KHR_deferred_host_operations ===
      vkCreateDeferredOperationKHR  = PFN_vkCreateDeferredOperationKHR( vkGetInstanceProcAddr( instance, "vkCreateDeferredOperationKHR" ) );
      vkDestroyDeferredOperationKHR = PFN_vkDestroyDeferredOperationKHR( vkGetInstanceProcAddr( instance, "vkDestroyDeferredOperationKHR" ) );
      vkGetDeferredOperationMaxConcurrencyKHR =
        PFN_vkGetDeferredOperationMaxConcurrencyKHR( vkGetInstanceProcAddr( instance, "vkGetDeferredOperationMaxConcurrencyKHR" ) );
      vkGetDeferredOperationResultKHR = PFN_vkGetDeferredOperationResultKHR( vkGetInstanceProcAddr( instance, "vkGetDeferredOperationResultKHR" ) );
      vkDeferredOperationJoinKHR      = PFN_vkDeferredOperationJoinKHR( vkGetInstanceProcAddr( instance, "vkDeferredOperationJoinKHR" ) );

      //=== VK_KHR_pipeline_executable_properties ===
      vkGetPipelineExecutablePropertiesKHR =
        PFN_vkGetPipelineExecutablePropertiesKHR( vkGetInstanceProcAddr( instance, "vkGetPipelineExecutablePropertiesKHR" ) );
      vkGetPipelineExecutableStatisticsKHR =
        PFN_vkGetPipelineExecutableStatisticsKHR( vkGetInstanceProcAddr( instance, "vkGetPipelineExecutableStatisticsKHR" ) );
      vkGetPipelineExecutableInternalRepresentationsKHR =
        PFN_vkGetPipelineExecutableInternalRepresentationsKHR( vkGetInstanceProcAddr( instance, "vkGetPipelineExecutableInternalRepresentationsKHR" ) );

      //=== VK_EXT_swapchain_maintenance1 ===
      vkReleaseSwapchainImagesEXT = PFN_vkReleaseSwapchainImagesEXT( vkGetInstanceProcAddr( instance, "vkReleaseSwapchainImagesEXT" ) );

      //=== VK_NV_device_generated_commands ===
      vkGetGeneratedCommandsMemoryRequirementsNV =
        PFN_vkGetGeneratedCommandsMemoryRequirementsNV( vkGetInstanceProcAddr( instance, "vkGetGeneratedCommandsMemoryRequirementsNV" ) );
      vkCmdPreprocessGeneratedCommandsNV = PFN_vkCmdPreprocessGeneratedCommandsNV( vkGetInstanceProcAddr( instance, "vkCmdPreprocessGeneratedCommandsNV" ) );
      vkCmdExecuteGeneratedCommandsNV    = PFN_vkCmdExecuteGeneratedCommandsNV( vkGetInstanceProcAddr( instance, "vkCmdExecuteGeneratedCommandsNV" ) );
      vkCmdBindPipelineShaderGroupNV     = PFN_vkCmdBindPipelineShaderGroupNV( vkGetInstanceProcAddr( instance, "vkCmdBindPipelineShaderGroupNV" ) );
      vkCreateIndirectCommandsLayoutNV   = PFN_vkCreateIndirectCommandsLayoutNV( vkGetInstanceProcAddr( instance, "vkCreateIndirectCommandsLayoutNV" ) );
      vkDestroyIndirectCommandsLayoutNV  = PFN_vkDestroyIndirectCommandsLayoutNV( vkGetInstanceProcAddr( instance, "vkDestroyIndirectCommandsLayoutNV" ) );

      //=== VK_EXT_acquire_drm_display ===
      vkAcquireDrmDisplayEXT = PFN_vkAcquireDrmDisplayEXT( vkGetInstanceProcAddr( instance, "vkAcquireDrmDisplayEXT" ) );
      vkGetDrmDisplayEXT     = PFN_vkGetDrmDisplayEXT( vkGetInstanceProcAddr( instance, "vkGetDrmDisplayEXT" ) );

      //=== VK_EXT_private_data ===
      vkCreatePrivateDataSlotEXT = PFN_vkCreatePrivateDataSlotEXT( vkGetInstanceProcAddr( instance, "vkCreatePrivateDataSlotEXT" ) );
      if ( !vkCreatePrivateDataSlot )
        vkCreatePrivateDataSlot = vkCreatePrivateDataSlotEXT;
      vkDestroyPrivateDataSlotEXT = PFN_vkDestroyPrivateDataSlotEXT( vkGetInstanceProcAddr( instance, "vkDestroyPrivateDataSlotEXT" ) );
      if ( !vkDestroyPrivateDataSlot )
        vkDestroyPrivateDataSlot = vkDestroyPrivateDataSlotEXT;
      vkSetPrivateDataEXT = PFN_vkSetPrivateDataEXT( vkGetInstanceProcAddr( instance, "vkSetPrivateDataEXT" ) );
      if ( !vkSetPrivateData )
        vkSetPrivateData = vkSetPrivateDataEXT;
      vkGetPrivateDataEXT = PFN_vkGetPrivateDataEXT( vkGetInstanceProcAddr( instance, "vkGetPrivateDataEXT" ) );
      if ( !vkGetPrivateData )
        vkGetPrivateData = vkGetPrivateDataEXT;

#if defined( VK_ENABLE_BETA_EXTENSIONS )
      //=== VK_KHR_video_encode_queue ===
      vkCmdEncodeVideoKHR = PFN_vkCmdEncodeVideoKHR( vkGetInstanceProcAddr( instance, "vkCmdEncodeVideoKHR" ) );
#endif /*VK_ENABLE_BETA_EXTENSIONS*/

#if defined( VK_USE_PLATFORM_METAL_EXT )
      //=== VK_EXT_metal_objects ===
      vkExportMetalObjectsEXT = PFN_vkExportMetalObjectsEXT( vkGetInstanceProcAddr( instance, "vkExportMetalObjectsEXT" ) );
#endif /*VK_USE_PLATFORM_METAL_EXT*/

       //=== VK_KHR_synchronization2 ===
      vkCmdSetEvent2KHR = PFN_vkCmdSetEvent2KHR( vkGetInstanceProcAddr( instance, "vkCmdSetEvent2KHR" ) );
      if ( !vkCmdSetEvent2 )
        vkCmdSetEvent2 = vkCmdSetEvent2KHR;
      vkCmdResetEvent2KHR = PFN_vkCmdResetEvent2KHR( vkGetInstanceProcAddr( instance, "vkCmdResetEvent2KHR" ) );
      if ( !vkCmdResetEvent2 )
        vkCmdResetEvent2 = vkCmdResetEvent2KHR;
      vkCmdWaitEvents2KHR = PFN_vkCmdWaitEvents2KHR( vkGetInstanceProcAddr( instance, "vkCmdWaitEvents2KHR" ) );
      if ( !vkCmdWaitEvents2 )
        vkCmdWaitEvents2 = vkCmdWaitEvents2KHR;
      vkCmdPipelineBarrier2KHR = PFN_vkCmdPipelineBarrier2KHR( vkGetInstanceProcAddr( instance, "vkCmdPipelineBarrier2KHR" ) );
      if ( !vkCmdPipelineBarrier2 )
        vkCmdPipelineBarrier2 = vkCmdPipelineBarrier2KHR;
      vkCmdWriteTimestamp2KHR = PFN_vkCmdWriteTimestamp2KHR( vkGetInstanceProcAddr( instance, "vkCmdWriteTimestamp2KHR" ) );
      if ( !vkCmdWriteTimestamp2 )
        vkCmdWriteTimestamp2 = vkCmdWriteTimestamp2KHR;
      vkQueueSubmit2KHR = PFN_vkQueueSubmit2KHR( vkGetInstanceProcAddr( instance, "vkQueueSubmit2KHR" ) );
      if ( !vkQueueSubmit2 )
        vkQueueSubmit2 = vkQueueSubmit2KHR;
      vkCmdWriteBufferMarker2AMD  = PFN_vkCmdWriteBufferMarker2AMD( vkGetInstanceProcAddr( instance, "vkCmdWriteBufferMarker2AMD" ) );
      vkGetQueueCheckpointData2NV = PFN_vkGetQueueCheckpointData2NV( vkGetInstanceProcAddr( instance, "vkGetQueueCheckpointData2NV" ) );

      //=== VK_EXT_descriptor_buffer ===
      vkGetDescriptorSetLayoutSizeEXT = PFN_vkGetDescriptorSetLayoutSizeEXT( vkGetInstanceProcAddr( instance, "vkGetDescriptorSetLayoutSizeEXT" ) );
      vkGetDescriptorSetLayoutBindingOffsetEXT =
        PFN_vkGetDescriptorSetLayoutBindingOffsetEXT( vkGetInstanceProcAddr( instance, "vkGetDescriptorSetLayoutBindingOffsetEXT" ) );
      vkGetDescriptorEXT                 = PFN_vkGetDescriptorEXT( vkGetInstanceProcAddr( instance, "vkGetDescriptorEXT" ) );
      vkCmdBindDescriptorBuffersEXT      = PFN_vkCmdBindDescriptorBuffersEXT( vkGetInstanceProcAddr( instance, "vkCmdBindDescriptorBuffersEXT" ) );
      vkCmdSetDescriptorBufferOffsetsEXT = PFN_vkCmdSetDescriptorBufferOffsetsEXT( vkGetInstanceProcAddr( instance, "vkCmdSetDescriptorBufferOffsetsEXT" ) );
      vkCmdBindDescriptorBufferEmbeddedSamplersEXT =
        PFN_vkCmdBindDescriptorBufferEmbeddedSamplersEXT( vkGetInstanceProcAddr( instance, "vkCmdBindDescriptorBufferEmbeddedSamplersEXT" ) );
      vkGetBufferOpaqueCaptureDescriptorDataEXT =
        PFN_vkGetBufferOpaqueCaptureDescriptorDataEXT( vkGetInstanceProcAddr( instance, "vkGetBufferOpaqueCaptureDescriptorDataEXT" ) );
      vkGetImageOpaqueCaptureDescriptorDataEXT =
        PFN_vkGetImageOpaqueCaptureDescriptorDataEXT( vkGetInstanceProcAddr( instance, "vkGetImageOpaqueCaptureDescriptorDataEXT" ) );
      vkGetImageViewOpaqueCaptureDescriptorDataEXT =
        PFN_vkGetImageViewOpaqueCaptureDescriptorDataEXT( vkGetInstanceProcAddr( instance, "vkGetImageViewOpaqueCaptureDescriptorDataEXT" ) );
      vkGetSamplerOpaqueCaptureDescriptorDataEXT =
        PFN_vkGetSamplerOpaqueCaptureDescriptorDataEXT( vkGetInstanceProcAddr( instance, "vkGetSamplerOpaqueCaptureDescriptorDataEXT" ) );
      vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT = PFN_vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT(
        vkGetInstanceProcAddr( instance, "vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT" ) );

      //=== VK_NV_fragment_shading_rate_enums ===
      vkCmdSetFragmentShadingRateEnumNV = PFN_vkCmdSetFragmentShadingRateEnumNV( vkGetInstanceProcAddr( instance, "vkCmdSetFragmentShadingRateEnumNV" ) );

      //=== VK_EXT_mesh_shader ===
      vkCmdDrawMeshTasksEXT              = PFN_vkCmdDrawMeshTasksEXT( vkGetInstanceProcAddr( instance, "vkCmdDrawMeshTasksEXT" ) );
      vkCmdDrawMeshTasksIndirectEXT      = PFN_vkCmdDrawMeshTasksIndirectEXT( vkGetInstanceProcAddr( instance, "vkCmdDrawMeshTasksIndirectEXT" ) );
      vkCmdDrawMeshTasksIndirectCountEXT = PFN_vkCmdDrawMeshTasksIndirectCountEXT( vkGetInstanceProcAddr( instance, "vkCmdDrawMeshTasksIndirectCountEXT" ) );

      //=== VK_KHR_copy_commands2 ===
      vkCmdCopyBuffer2KHR = PFN_vkCmdCopyBuffer2KHR( vkGetInstanceProcAddr( instance, "vkCmdCopyBuffer2KHR" ) );
      if ( !vkCmdCopyBuffer2 )
        vkCmdCopyBuffer2 = vkCmdCopyBuffer2KHR;
      vkCmdCopyImage2KHR = PFN_vkCmdCopyImage2KHR( vkGetInstanceProcAddr( instance, "vkCmdCopyImage2KHR" ) );
      if ( !vkCmdCopyImage2 )
        vkCmdCopyImage2 = vkCmdCopyImage2KHR;
      vkCmdCopyBufferToImage2KHR = PFN_vkCmdCopyBufferToImage2KHR( vkGetInstanceProcAddr( instance, "vkCmdCopyBufferToImage2KHR" ) );
      if ( !vkCmdCopyBufferToImage2 )
        vkCmdCopyBufferToImage2 = vkCmdCopyBufferToImage2KHR;
      vkCmdCopyImageToBuffer2KHR = PFN_vkCmdCopyImageToBuffer2KHR( vkGetInstanceProcAddr( instance, "vkCmdCopyImageToBuffer2KHR" ) );
      if ( !vkCmdCopyImageToBuffer2 )
        vkCmdCopyImageToBuffer2 = vkCmdCopyImageToBuffer2KHR;
      vkCmdBlitImage2KHR = PFN_vkCmdBlitImage2KHR( vkGetInstanceProcAddr( instance, "vkCmdBlitImage2KHR" ) );
      if ( !vkCmdBlitImage2 )
        vkCmdBlitImage2 = vkCmdBlitImage2KHR;
      vkCmdResolveImage2KHR = PFN_vkCmdResolveImage2KHR( vkGetInstanceProcAddr( instance, "vkCmdResolveImage2KHR" ) );
      if ( !vkCmdResolveImage2 )
        vkCmdResolveImage2 = vkCmdResolveImage2KHR;

      //=== VK_EXT_image_compression_control ===
      vkGetImageSubresourceLayout2EXT = PFN_vkGetImageSubresourceLayout2EXT( vkGetInstanceProcAddr( instance, "vkGetImageSubresourceLayout2EXT" ) );

      //=== VK_EXT_device_fault ===
      vkGetDeviceFaultInfoEXT = PFN_vkGetDeviceFaultInfoEXT( vkGetInstanceProcAddr( instance, "vkGetDeviceFaultInfoEXT" ) );

#if defined( VK_USE_PLATFORM_WIN32_KHR )
      //=== VK_NV_acquire_winrt_display ===
      vkAcquireWinrtDisplayNV = PFN_vkAcquireWinrtDisplayNV( vkGetInstanceProcAddr( instance, "vkAcquireWinrtDisplayNV" ) );
      vkGetWinrtDisplayNV     = PFN_vkGetWinrtDisplayNV( vkGetInstanceProcAddr( instance, "vkGetWinrtDisplayNV" ) );
#endif /*VK_USE_PLATFORM_WIN32_KHR*/

#if defined( VK_USE_PLATFORM_DIRECTFB_EXT )
      //=== VK_EXT_directfb_surface ===
      vkCreateDirectFBSurfaceEXT = PFN_vkCreateDirectFBSurfaceEXT( vkGetInstanceProcAddr( instance, "vkCreateDirectFBSurfaceEXT" ) );
      vkGetPhysicalDeviceDirectFBPresentationSupportEXT =
        PFN_vkGetPhysicalDeviceDirectFBPresentationSupportEXT( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceDirectFBPresentationSupportEXT" ) );
#endif /*VK_USE_PLATFORM_DIRECTFB_EXT*/

       //=== VK_KHR_ray_tracing_pipeline ===
      vkCmdTraceRaysKHR              = PFN_vkCmdTraceRaysKHR( vkGetInstanceProcAddr( instance, "vkCmdTraceRaysKHR" ) );
      vkCreateRayTracingPipelinesKHR = PFN_vkCreateRayTracingPipelinesKHR( vkGetInstanceProcAddr( instance, "vkCreateRayTracingPipelinesKHR" ) );
      vkGetRayTracingShaderGroupHandlesKHR =
        PFN_vkGetRayTracingShaderGroupHandlesKHR( vkGetInstanceProcAddr( instance, "vkGetRayTracingShaderGroupHandlesKHR" ) );
      vkGetRayTracingCaptureReplayShaderGroupHandlesKHR =
        PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR( vkGetInstanceProcAddr( instance, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR" ) );
      vkCmdTraceRaysIndirectKHR = PFN_vkCmdTraceRaysIndirectKHR( vkGetInstanceProcAddr( instance, "vkCmdTraceRaysIndirectKHR" ) );
      vkGetRayTracingShaderGroupStackSizeKHR =
        PFN_vkGetRayTracingShaderGroupStackSizeKHR( vkGetInstanceProcAddr( instance, "vkGetRayTracingShaderGroupStackSizeKHR" ) );
      vkCmdSetRayTracingPipelineStackSizeKHR =
        PFN_vkCmdSetRayTracingPipelineStackSizeKHR( vkGetInstanceProcAddr( instance, "vkCmdSetRayTracingPipelineStackSizeKHR" ) );

      //=== VK_EXT_vertex_input_dynamic_state ===
      vkCmdSetVertexInputEXT = PFN_vkCmdSetVertexInputEXT( vkGetInstanceProcAddr( instance, "vkCmdSetVertexInputEXT" ) );

#if defined( VK_USE_PLATFORM_FUCHSIA )
      //=== VK_FUCHSIA_external_memory ===
      vkGetMemoryZirconHandleFUCHSIA = PFN_vkGetMemoryZirconHandleFUCHSIA( vkGetInstanceProcAddr( instance, "vkGetMemoryZirconHandleFUCHSIA" ) );
      vkGetMemoryZirconHandlePropertiesFUCHSIA =
        PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA( vkGetInstanceProcAddr( instance, "vkGetMemoryZirconHandlePropertiesFUCHSIA" ) );
#endif /*VK_USE_PLATFORM_FUCHSIA*/

#if defined( VK_USE_PLATFORM_FUCHSIA )
      //=== VK_FUCHSIA_external_semaphore ===
      vkImportSemaphoreZirconHandleFUCHSIA =
        PFN_vkImportSemaphoreZirconHandleFUCHSIA( vkGetInstanceProcAddr( instance, "vkImportSemaphoreZirconHandleFUCHSIA" ) );
      vkGetSemaphoreZirconHandleFUCHSIA = PFN_vkGetSemaphoreZirconHandleFUCHSIA( vkGetInstanceProcAddr( instance, "vkGetSemaphoreZirconHandleFUCHSIA" ) );
#endif /*VK_USE_PLATFORM_FUCHSIA*/

#if defined( VK_USE_PLATFORM_FUCHSIA )
      //=== VK_FUCHSIA_buffer_collection ===
      vkCreateBufferCollectionFUCHSIA = PFN_vkCreateBufferCollectionFUCHSIA( vkGetInstanceProcAddr( instance, "vkCreateBufferCollectionFUCHSIA" ) );
      vkSetBufferCollectionImageConstraintsFUCHSIA =
        PFN_vkSetBufferCollectionImageConstraintsFUCHSIA( vkGetInstanceProcAddr( instance, "vkSetBufferCollectionImageConstraintsFUCHSIA" ) );
      vkSetBufferCollectionBufferConstraintsFUCHSIA =
        PFN_vkSetBufferCollectionBufferConstraintsFUCHSIA( vkGetInstanceProcAddr( instance, "vkSetBufferCollectionBufferConstraintsFUCHSIA" ) );
      vkDestroyBufferCollectionFUCHSIA = PFN_vkDestroyBufferCollectionFUCHSIA( vkGetInstanceProcAddr( instance, "vkDestroyBufferCollectionFUCHSIA" ) );
      vkGetBufferCollectionPropertiesFUCHSIA =
        PFN_vkGetBufferCollectionPropertiesFUCHSIA( vkGetInstanceProcAddr( instance, "vkGetBufferCollectionPropertiesFUCHSIA" ) );
#endif /*VK_USE_PLATFORM_FUCHSIA*/

       //=== VK_HUAWEI_subpass_shading ===
      vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI =
        PFN_vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI( vkGetInstanceProcAddr( instance, "vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI" ) );
      vkCmdSubpassShadingHUAWEI = PFN_vkCmdSubpassShadingHUAWEI( vkGetInstanceProcAddr( instance, "vkCmdSubpassShadingHUAWEI" ) );

      //=== VK_HUAWEI_invocation_mask ===
      vkCmdBindInvocationMaskHUAWEI = PFN_vkCmdBindInvocationMaskHUAWEI( vkGetInstanceProcAddr( instance, "vkCmdBindInvocationMaskHUAWEI" ) );

      //=== VK_NV_external_memory_rdma ===
      vkGetMemoryRemoteAddressNV = PFN_vkGetMemoryRemoteAddressNV( vkGetInstanceProcAddr( instance, "vkGetMemoryRemoteAddressNV" ) );

      //=== VK_EXT_pipeline_properties ===
      vkGetPipelinePropertiesEXT = PFN_vkGetPipelinePropertiesEXT( vkGetInstanceProcAddr( instance, "vkGetPipelinePropertiesEXT" ) );

      //=== VK_EXT_extended_dynamic_state2 ===
      vkCmdSetPatchControlPointsEXT      = PFN_vkCmdSetPatchControlPointsEXT( vkGetInstanceProcAddr( instance, "vkCmdSetPatchControlPointsEXT" ) );
      vkCmdSetRasterizerDiscardEnableEXT = PFN_vkCmdSetRasterizerDiscardEnableEXT( vkGetInstanceProcAddr( instance, "vkCmdSetRasterizerDiscardEnableEXT" ) );
      if ( !vkCmdSetRasterizerDiscardEnable )
        vkCmdSetRasterizerDiscardEnable = vkCmdSetRasterizerDiscardEnableEXT;
      vkCmdSetDepthBiasEnableEXT = PFN_vkCmdSetDepthBiasEnableEXT( vkGetInstanceProcAddr( instance, "vkCmdSetDepthBiasEnableEXT" ) );
      if ( !vkCmdSetDepthBiasEnable )
        vkCmdSetDepthBiasEnable = vkCmdSetDepthBiasEnableEXT;
      vkCmdSetLogicOpEXT                = PFN_vkCmdSetLogicOpEXT( vkGetInstanceProcAddr( instance, "vkCmdSetLogicOpEXT" ) );
      vkCmdSetPrimitiveRestartEnableEXT = PFN_vkCmdSetPrimitiveRestartEnableEXT( vkGetInstanceProcAddr( instance, "vkCmdSetPrimitiveRestartEnableEXT" ) );
      if ( !vkCmdSetPrimitiveRestartEnable )
        vkCmdSetPrimitiveRestartEnable = vkCmdSetPrimitiveRestartEnableEXT;

#if defined( VK_USE_PLATFORM_SCREEN_QNX )
      //=== VK_QNX_screen_surface ===
      vkCreateScreenSurfaceQNX = PFN_vkCreateScreenSurfaceQNX( vkGetInstanceProcAddr( instance, "vkCreateScreenSurfaceQNX" ) );
      vkGetPhysicalDeviceScreenPresentationSupportQNX =
        PFN_vkGetPhysicalDeviceScreenPresentationSupportQNX( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceScreenPresentationSupportQNX" ) );
#endif /*VK_USE_PLATFORM_SCREEN_QNX*/

       //=== VK_EXT_color_write_enable ===
      vkCmdSetColorWriteEnableEXT = PFN_vkCmdSetColorWriteEnableEXT( vkGetInstanceProcAddr( instance, "vkCmdSetColorWriteEnableEXT" ) );

      //=== VK_KHR_ray_tracing_maintenance1 ===
      vkCmdTraceRaysIndirect2KHR = PFN_vkCmdTraceRaysIndirect2KHR( vkGetInstanceProcAddr( instance, "vkCmdTraceRaysIndirect2KHR" ) );

      //=== VK_EXT_multi_draw ===
      vkCmdDrawMultiEXT        = PFN_vkCmdDrawMultiEXT( vkGetInstanceProcAddr( instance, "vkCmdDrawMultiEXT" ) );
      vkCmdDrawMultiIndexedEXT = PFN_vkCmdDrawMultiIndexedEXT( vkGetInstanceProcAddr( instance, "vkCmdDrawMultiIndexedEXT" ) );

      //=== VK_EXT_opacity_micromap ===
      vkCreateMicromapEXT                 = PFN_vkCreateMicromapEXT( vkGetInstanceProcAddr( instance, "vkCreateMicromapEXT" ) );
      vkDestroyMicromapEXT                = PFN_vkDestroyMicromapEXT( vkGetInstanceProcAddr( instance, "vkDestroyMicromapEXT" ) );
      vkCmdBuildMicromapsEXT              = PFN_vkCmdBuildMicromapsEXT( vkGetInstanceProcAddr( instance, "vkCmdBuildMicromapsEXT" ) );
      vkBuildMicromapsEXT                 = PFN_vkBuildMicromapsEXT( vkGetInstanceProcAddr( instance, "vkBuildMicromapsEXT" ) );
      vkCopyMicromapEXT                   = PFN_vkCopyMicromapEXT( vkGetInstanceProcAddr( instance, "vkCopyMicromapEXT" ) );
      vkCopyMicromapToMemoryEXT           = PFN_vkCopyMicromapToMemoryEXT( vkGetInstanceProcAddr( instance, "vkCopyMicromapToMemoryEXT" ) );
      vkCopyMemoryToMicromapEXT           = PFN_vkCopyMemoryToMicromapEXT( vkGetInstanceProcAddr( instance, "vkCopyMemoryToMicromapEXT" ) );
      vkWriteMicromapsPropertiesEXT       = PFN_vkWriteMicromapsPropertiesEXT( vkGetInstanceProcAddr( instance, "vkWriteMicromapsPropertiesEXT" ) );
      vkCmdCopyMicromapEXT                = PFN_vkCmdCopyMicromapEXT( vkGetInstanceProcAddr( instance, "vkCmdCopyMicromapEXT" ) );
      vkCmdCopyMicromapToMemoryEXT        = PFN_vkCmdCopyMicromapToMemoryEXT( vkGetInstanceProcAddr( instance, "vkCmdCopyMicromapToMemoryEXT" ) );
      vkCmdCopyMemoryToMicromapEXT        = PFN_vkCmdCopyMemoryToMicromapEXT( vkGetInstanceProcAddr( instance, "vkCmdCopyMemoryToMicromapEXT" ) );
      vkCmdWriteMicromapsPropertiesEXT    = PFN_vkCmdWriteMicromapsPropertiesEXT( vkGetInstanceProcAddr( instance, "vkCmdWriteMicromapsPropertiesEXT" ) );
      vkGetDeviceMicromapCompatibilityEXT = PFN_vkGetDeviceMicromapCompatibilityEXT( vkGetInstanceProcAddr( instance, "vkGetDeviceMicromapCompatibilityEXT" ) );
      vkGetMicromapBuildSizesEXT          = PFN_vkGetMicromapBuildSizesEXT( vkGetInstanceProcAddr( instance, "vkGetMicromapBuildSizesEXT" ) );

      //=== VK_HUAWEI_cluster_culling_shader ===
      vkCmdDrawClusterHUAWEI         = PFN_vkCmdDrawClusterHUAWEI( vkGetInstanceProcAddr( instance, "vkCmdDrawClusterHUAWEI" ) );
      vkCmdDrawClusterIndirectHUAWEI = PFN_vkCmdDrawClusterIndirectHUAWEI( vkGetInstanceProcAddr( instance, "vkCmdDrawClusterIndirectHUAWEI" ) );

      //=== VK_EXT_pageable_device_local_memory ===
      vkSetDeviceMemoryPriorityEXT = PFN_vkSetDeviceMemoryPriorityEXT( vkGetInstanceProcAddr( instance, "vkSetDeviceMemoryPriorityEXT" ) );

      //=== VK_KHR_maintenance4 ===
      vkGetDeviceBufferMemoryRequirementsKHR =
        PFN_vkGetDeviceBufferMemoryRequirementsKHR( vkGetInstanceProcAddr( instance, "vkGetDeviceBufferMemoryRequirementsKHR" ) );
      if ( !vkGetDeviceBufferMemoryRequirements )
        vkGetDeviceBufferMemoryRequirements = vkGetDeviceBufferMemoryRequirementsKHR;
      vkGetDeviceImageMemoryRequirementsKHR =
        PFN_vkGetDeviceImageMemoryRequirementsKHR( vkGetInstanceProcAddr( instance, "vkGetDeviceImageMemoryRequirementsKHR" ) );
      if ( !vkGetDeviceImageMemoryRequirements )
        vkGetDeviceImageMemoryRequirements = vkGetDeviceImageMemoryRequirementsKHR;
      vkGetDeviceImageSparseMemoryRequirementsKHR =
        PFN_vkGetDeviceImageSparseMemoryRequirementsKHR( vkGetInstanceProcAddr( instance, "vkGetDeviceImageSparseMemoryRequirementsKHR" ) );
      if ( !vkGetDeviceImageSparseMemoryRequirements )
        vkGetDeviceImageSparseMemoryRequirements = vkGetDeviceImageSparseMemoryRequirementsKHR;

      //=== VK_VALVE_descriptor_set_host_mapping ===
      vkGetDescriptorSetLayoutHostMappingInfoVALVE =
        PFN_vkGetDescriptorSetLayoutHostMappingInfoVALVE( vkGetInstanceProcAddr( instance, "vkGetDescriptorSetLayoutHostMappingInfoVALVE" ) );
      vkGetDescriptorSetHostMappingVALVE = PFN_vkGetDescriptorSetHostMappingVALVE( vkGetInstanceProcAddr( instance, "vkGetDescriptorSetHostMappingVALVE" ) );

      //=== VK_NV_copy_memory_indirect ===
      vkCmdCopyMemoryIndirectNV        = PFN_vkCmdCopyMemoryIndirectNV( vkGetInstanceProcAddr( instance, "vkCmdCopyMemoryIndirectNV" ) );
      vkCmdCopyMemoryToImageIndirectNV = PFN_vkCmdCopyMemoryToImageIndirectNV( vkGetInstanceProcAddr( instance, "vkCmdCopyMemoryToImageIndirectNV" ) );

      //=== VK_NV_memory_decompression ===
      vkCmdDecompressMemoryNV = PFN_vkCmdDecompressMemoryNV( vkGetInstanceProcAddr( instance, "vkCmdDecompressMemoryNV" ) );
      vkCmdDecompressMemoryIndirectCountNV =
        PFN_vkCmdDecompressMemoryIndirectCountNV( vkGetInstanceProcAddr( instance, "vkCmdDecompressMemoryIndirectCountNV" ) );

      //=== VK_EXT_extended_dynamic_state3 ===
      vkCmdSetTessellationDomainOriginEXT = PFN_vkCmdSetTessellationDomainOriginEXT( vkGetInstanceProcAddr( instance, "vkCmdSetTessellationDomainOriginEXT" ) );
      vkCmdSetDepthClampEnableEXT         = PFN_vkCmdSetDepthClampEnableEXT( vkGetInstanceProcAddr( instance, "vkCmdSetDepthClampEnableEXT" ) );
      vkCmdSetPolygonModeEXT              = PFN_vkCmdSetPolygonModeEXT( vkGetInstanceProcAddr( instance, "vkCmdSetPolygonModeEXT" ) );
      vkCmdSetRasterizationSamplesEXT     = PFN_vkCmdSetRasterizationSamplesEXT( vkGetInstanceProcAddr( instance, "vkCmdSetRasterizationSamplesEXT" ) );
      vkCmdSetSampleMaskEXT               = PFN_vkCmdSetSampleMaskEXT( vkGetInstanceProcAddr( instance, "vkCmdSetSampleMaskEXT" ) );
      vkCmdSetAlphaToCoverageEnableEXT    = PFN_vkCmdSetAlphaToCoverageEnableEXT( vkGetInstanceProcAddr( instance, "vkCmdSetAlphaToCoverageEnableEXT" ) );
      vkCmdSetAlphaToOneEnableEXT         = PFN_vkCmdSetAlphaToOneEnableEXT( vkGetInstanceProcAddr( instance, "vkCmdSetAlphaToOneEnableEXT" ) );
      vkCmdSetLogicOpEnableEXT            = PFN_vkCmdSetLogicOpEnableEXT( vkGetInstanceProcAddr( instance, "vkCmdSetLogicOpEnableEXT" ) );
      vkCmdSetColorBlendEnableEXT         = PFN_vkCmdSetColorBlendEnableEXT( vkGetInstanceProcAddr( instance, "vkCmdSetColorBlendEnableEXT" ) );
      vkCmdSetColorBlendEquationEXT       = PFN_vkCmdSetColorBlendEquationEXT( vkGetInstanceProcAddr( instance, "vkCmdSetColorBlendEquationEXT" ) );
      vkCmdSetColorWriteMaskEXT           = PFN_vkCmdSetColorWriteMaskEXT( vkGetInstanceProcAddr( instance, "vkCmdSetColorWriteMaskEXT" ) );
      vkCmdSetRasterizationStreamEXT      = PFN_vkCmdSetRasterizationStreamEXT( vkGetInstanceProcAddr( instance, "vkCmdSetRasterizationStreamEXT" ) );
      vkCmdSetConservativeRasterizationModeEXT =
        PFN_vkCmdSetConservativeRasterizationModeEXT( vkGetInstanceProcAddr( instance, "vkCmdSetConservativeRasterizationModeEXT" ) );
      vkCmdSetExtraPrimitiveOverestimationSizeEXT =
        PFN_vkCmdSetExtraPrimitiveOverestimationSizeEXT( vkGetInstanceProcAddr( instance, "vkCmdSetExtraPrimitiveOverestimationSizeEXT" ) );
      vkCmdSetDepthClipEnableEXT       = PFN_vkCmdSetDepthClipEnableEXT( vkGetInstanceProcAddr( instance, "vkCmdSetDepthClipEnableEXT" ) );
      vkCmdSetSampleLocationsEnableEXT = PFN_vkCmdSetSampleLocationsEnableEXT( vkGetInstanceProcAddr( instance, "vkCmdSetSampleLocationsEnableEXT" ) );
      vkCmdSetColorBlendAdvancedEXT    = PFN_vkCmdSetColorBlendAdvancedEXT( vkGetInstanceProcAddr( instance, "vkCmdSetColorBlendAdvancedEXT" ) );
      vkCmdSetProvokingVertexModeEXT   = PFN_vkCmdSetProvokingVertexModeEXT( vkGetInstanceProcAddr( instance, "vkCmdSetProvokingVertexModeEXT" ) );
      vkCmdSetLineRasterizationModeEXT = PFN_vkCmdSetLineRasterizationModeEXT( vkGetInstanceProcAddr( instance, "vkCmdSetLineRasterizationModeEXT" ) );
      vkCmdSetLineStippleEnableEXT     = PFN_vkCmdSetLineStippleEnableEXT( vkGetInstanceProcAddr( instance, "vkCmdSetLineStippleEnableEXT" ) );
      vkCmdSetDepthClipNegativeOneToOneEXT =
        PFN_vkCmdSetDepthClipNegativeOneToOneEXT( vkGetInstanceProcAddr( instance, "vkCmdSetDepthClipNegativeOneToOneEXT" ) );
      vkCmdSetViewportWScalingEnableNV  = PFN_vkCmdSetViewportWScalingEnableNV( vkGetInstanceProcAddr( instance, "vkCmdSetViewportWScalingEnableNV" ) );
      vkCmdSetViewportSwizzleNV         = PFN_vkCmdSetViewportSwizzleNV( vkGetInstanceProcAddr( instance, "vkCmdSetViewportSwizzleNV" ) );
      vkCmdSetCoverageToColorEnableNV   = PFN_vkCmdSetCoverageToColorEnableNV( vkGetInstanceProcAddr( instance, "vkCmdSetCoverageToColorEnableNV" ) );
      vkCmdSetCoverageToColorLocationNV = PFN_vkCmdSetCoverageToColorLocationNV( vkGetInstanceProcAddr( instance, "vkCmdSetCoverageToColorLocationNV" ) );
      vkCmdSetCoverageModulationModeNV  = PFN_vkCmdSetCoverageModulationModeNV( vkGetInstanceProcAddr( instance, "vkCmdSetCoverageModulationModeNV" ) );
      vkCmdSetCoverageModulationTableEnableNV =
        PFN_vkCmdSetCoverageModulationTableEnableNV( vkGetInstanceProcAddr( instance, "vkCmdSetCoverageModulationTableEnableNV" ) );
      vkCmdSetCoverageModulationTableNV = PFN_vkCmdSetCoverageModulationTableNV( vkGetInstanceProcAddr( instance, "vkCmdSetCoverageModulationTableNV" ) );
      vkCmdSetShadingRateImageEnableNV  = PFN_vkCmdSetShadingRateImageEnableNV( vkGetInstanceProcAddr( instance, "vkCmdSetShadingRateImageEnableNV" ) );
      vkCmdSetRepresentativeFragmentTestEnableNV =
        PFN_vkCmdSetRepresentativeFragmentTestEnableNV( vkGetInstanceProcAddr( instance, "vkCmdSetRepresentativeFragmentTestEnableNV" ) );
      vkCmdSetCoverageReductionModeNV = PFN_vkCmdSetCoverageReductionModeNV( vkGetInstanceProcAddr( instance, "vkCmdSetCoverageReductionModeNV" ) );

      //=== VK_EXT_shader_module_identifier ===
      vkGetShaderModuleIdentifierEXT = PFN_vkGetShaderModuleIdentifierEXT( vkGetInstanceProcAddr( instance, "vkGetShaderModuleIdentifierEXT" ) );
      vkGetShaderModuleCreateInfoIdentifierEXT =
        PFN_vkGetShaderModuleCreateInfoIdentifierEXT( vkGetInstanceProcAddr( instance, "vkGetShaderModuleCreateInfoIdentifierEXT" ) );

      //=== VK_NV_optical_flow ===
      vkGetPhysicalDeviceOpticalFlowImageFormatsNV =
        PFN_vkGetPhysicalDeviceOpticalFlowImageFormatsNV( vkGetInstanceProcAddr( instance, "vkGetPhysicalDeviceOpticalFlowImageFormatsNV" ) );
      vkCreateOpticalFlowSessionNV    = PFN_vkCreateOpticalFlowSessionNV( vkGetInstanceProcAddr( instance, "vkCreateOpticalFlowSessionNV" ) );
      vkDestroyOpticalFlowSessionNV   = PFN_vkDestroyOpticalFlowSessionNV( vkGetInstanceProcAddr( instance, "vkDestroyOpticalFlowSessionNV" ) );
      vkBindOpticalFlowSessionImageNV = PFN_vkBindOpticalFlowSessionImageNV( vkGetInstanceProcAddr( instance, "vkBindOpticalFlowSessionImageNV" ) );
      vkCmdOpticalFlowExecuteNV       = PFN_vkCmdOpticalFlowExecuteNV( vkGetInstanceProcAddr( instance, "vkCmdOpticalFlowExecuteNV" ) );

      //=== VK_QCOM_tile_properties ===
      vkGetFramebufferTilePropertiesQCOM = PFN_vkGetFramebufferTilePropertiesQCOM( vkGetInstanceProcAddr( instance, "vkGetFramebufferTilePropertiesQCOM" ) );
      vkGetDynamicRenderingTilePropertiesQCOM =
        PFN_vkGetDynamicRenderingTilePropertiesQCOM( vkGetInstanceProcAddr( instance, "vkGetDynamicRenderingTilePropertiesQCOM" ) );
    }

    void init( VkDevice device ) VULKAN_HPP_NOEXCEPT
    {
      //=== VK_VERSION_1_0 ===
      vkGetDeviceProcAddr                = PFN_vkGetDeviceProcAddr( vkGetDeviceProcAddr( device, "vkGetDeviceProcAddr" ) );
      vkDestroyDevice                    = PFN_vkDestroyDevice( vkGetDeviceProcAddr( device, "vkDestroyDevice" ) );
      vkGetDeviceQueue                   = PFN_vkGetDeviceQueue( vkGetDeviceProcAddr( device, "vkGetDeviceQueue" ) );
      vkQueueSubmit                      = PFN_vkQueueSubmit( vkGetDeviceProcAddr( device, "vkQueueSubmit" ) );
      vkQueueWaitIdle                    = PFN_vkQueueWaitIdle( vkGetDeviceProcAddr( device, "vkQueueWaitIdle" ) );
      vkDeviceWaitIdle                   = PFN_vkDeviceWaitIdle( vkGetDeviceProcAddr( device, "vkDeviceWaitIdle" ) );
      vkAllocateMemory                   = PFN_vkAllocateMemory( vkGetDeviceProcAddr( device, "vkAllocateMemory" ) );
      vkFreeMemory                       = PFN_vkFreeMemory( vkGetDeviceProcAddr( device, "vkFreeMemory" ) );
      vkMapMemory                        = PFN_vkMapMemory( vkGetDeviceProcAddr( device, "vkMapMemory" ) );
      vkUnmapMemory                      = PFN_vkUnmapMemory( vkGetDeviceProcAddr( device, "vkUnmapMemory" ) );
      vkFlushMappedMemoryRanges          = PFN_vkFlushMappedMemoryRanges( vkGetDeviceProcAddr( device, "vkFlushMappedMemoryRanges" ) );
      vkInvalidateMappedMemoryRanges     = PFN_vkInvalidateMappedMemoryRanges( vkGetDeviceProcAddr( device, "vkInvalidateMappedMemoryRanges" ) );
      vkGetDeviceMemoryCommitment        = PFN_vkGetDeviceMemoryCommitment( vkGetDeviceProcAddr( device, "vkGetDeviceMemoryCommitment" ) );
      vkBindBufferMemory                 = PFN_vkBindBufferMemory( vkGetDeviceProcAddr( device, "vkBindBufferMemory" ) );
      vkBindImageMemory                  = PFN_vkBindImageMemory( vkGetDeviceProcAddr( device, "vkBindImageMemory" ) );
      vkGetBufferMemoryRequirements      = PFN_vkGetBufferMemoryRequirements( vkGetDeviceProcAddr( device, "vkGetBufferMemoryRequirements" ) );
      vkGetImageMemoryRequirements       = PFN_vkGetImageMemoryRequirements( vkGetDeviceProcAddr( device, "vkGetImageMemoryRequirements" ) );
      vkGetImageSparseMemoryRequirements = PFN_vkGetImageSparseMemoryRequirements( vkGetDeviceProcAddr( device, "vkGetImageSparseMemoryRequirements" ) );
      vkQueueBindSparse                  = PFN_vkQueueBindSparse( vkGetDeviceProcAddr( device, "vkQueueBindSparse" ) );
      vkCreateFence                      = PFN_vkCreateFence( vkGetDeviceProcAddr( device, "vkCreateFence" ) );
      vkDestroyFence                     = PFN_vkDestroyFence( vkGetDeviceProcAddr( device, "vkDestroyFence" ) );
      vkResetFences                      = PFN_vkResetFences( vkGetDeviceProcAddr( device, "vkResetFences" ) );
      vkGetFenceStatus                   = PFN_vkGetFenceStatus( vkGetDeviceProcAddr( device, "vkGetFenceStatus" ) );
      vkWaitForFences                    = PFN_vkWaitForFences( vkGetDeviceProcAddr( device, "vkWaitForFences" ) );
      vkCreateSemaphore                  = PFN_vkCreateSemaphore( vkGetDeviceProcAddr( device, "vkCreateSemaphore" ) );
      vkDestroySemaphore                 = PFN_vkDestroySemaphore( vkGetDeviceProcAddr( device, "vkDestroySemaphore" ) );
      vkCreateEvent                      = PFN_vkCreateEvent( vkGetDeviceProcAddr( device, "vkCreateEvent" ) );
      vkDestroyEvent                     = PFN_vkDestroyEvent( vkGetDeviceProcAddr( device, "vkDestroyEvent" ) );
      vkGetEventStatus                   = PFN_vkGetEventStatus( vkGetDeviceProcAddr( device, "vkGetEventStatus" ) );
      vkSetEvent                         = PFN_vkSetEvent( vkGetDeviceProcAddr( device, "vkSetEvent" ) );
      vkResetEvent                       = PFN_vkResetEvent( vkGetDeviceProcAddr( device, "vkResetEvent" ) );
      vkCreateQueryPool                  = PFN_vkCreateQueryPool( vkGetDeviceProcAddr( device, "vkCreateQueryPool" ) );
      vkDestroyQueryPool                 = PFN_vkDestroyQueryPool( vkGetDeviceProcAddr( device, "vkDestroyQueryPool" ) );
      vkGetQueryPoolResults              = PFN_vkGetQueryPoolResults( vkGetDeviceProcAddr( device, "vkGetQueryPoolResults" ) );
      vkCreateBuffer                     = PFN_vkCreateBuffer( vkGetDeviceProcAddr( device, "vkCreateBuffer" ) );
      vkDestroyBuffer                    = PFN_vkDestroyBuffer( vkGetDeviceProcAddr( device, "vkDestroyBuffer" ) );
      vkCreateBufferView                 = PFN_vkCreateBufferView( vkGetDeviceProcAddr( device, "vkCreateBufferView" ) );
      vkDestroyBufferView                = PFN_vkDestroyBufferView( vkGetDeviceProcAddr( device, "vkDestroyBufferView" ) );
      vkCreateImage                      = PFN_vkCreateImage( vkGetDeviceProcAddr( device, "vkCreateImage" ) );
      vkDestroyImage                     = PFN_vkDestroyImage( vkGetDeviceProcAddr( device, "vkDestroyImage" ) );
      vkGetImageSubresourceLayout        = PFN_vkGetImageSubresourceLayout( vkGetDeviceProcAddr( device, "vkGetImageSubresourceLayout" ) );
      vkCreateImageView                  = PFN_vkCreateImageView( vkGetDeviceProcAddr( device, "vkCreateImageView" ) );
      vkDestroyImageView                 = PFN_vkDestroyImageView( vkGetDeviceProcAddr( device, "vkDestroyImageView" ) );
      vkCreateShaderModule               = PFN_vkCreateShaderModule( vkGetDeviceProcAddr( device, "vkCreateShaderModule" ) );
      vkDestroyShaderModule              = PFN_vkDestroyShaderModule( vkGetDeviceProcAddr( device, "vkDestroyShaderModule" ) );
      vkCreatePipelineCache              = PFN_vkCreatePipelineCache( vkGetDeviceProcAddr( device, "vkCreatePipelineCache" ) );
      vkDestroyPipelineCache             = PFN_vkDestroyPipelineCache( vkGetDeviceProcAddr( device, "vkDestroyPipelineCache" ) );
      vkGetPipelineCacheData             = PFN_vkGetPipelineCacheData( vkGetDeviceProcAddr( device, "vkGetPipelineCacheData" ) );
      vkMergePipelineCaches              = PFN_vkMergePipelineCaches( vkGetDeviceProcAddr( device, "vkMergePipelineCaches" ) );
      vkCreateGraphicsPipelines          = PFN_vkCreateGraphicsPipelines( vkGetDeviceProcAddr( device, "vkCreateGraphicsPipelines" ) );
      vkCreateComputePipelines           = PFN_vkCreateComputePipelines( vkGetDeviceProcAddr( device, "vkCreateComputePipelines" ) );
      vkDestroyPipeline                  = PFN_vkDestroyPipeline( vkGetDeviceProcAddr( device, "vkDestroyPipeline" ) );
      vkCreatePipelineLayout             = PFN_vkCreatePipelineLayout( vkGetDeviceProcAddr( device, "vkCreatePipelineLayout" ) );
      vkDestroyPipelineLayout            = PFN_vkDestroyPipelineLayout( vkGetDeviceProcAddr( device, "vkDestroyPipelineLayout" ) );
      vkCreateSampler                    = PFN_vkCreateSampler( vkGetDeviceProcAddr( device, "vkCreateSampler" ) );
      vkDestroySampler                   = PFN_vkDestroySampler( vkGetDeviceProcAddr( device, "vkDestroySampler" ) );
      vkCreateDescriptorSetLayout        = PFN_vkCreateDescriptorSetLayout( vkGetDeviceProcAddr( device, "vkCreateDescriptorSetLayout" ) );
      vkDestroyDescriptorSetLayout       = PFN_vkDestroyDescriptorSetLayout( vkGetDeviceProcAddr( device, "vkDestroyDescriptorSetLayout" ) );
      vkCreateDescriptorPool             = PFN_vkCreateDescriptorPool( vkGetDeviceProcAddr( device, "vkCreateDescriptorPool" ) );
      vkDestroyDescriptorPool            = PFN_vkDestroyDescriptorPool( vkGetDeviceProcAddr( device, "vkDestroyDescriptorPool" ) );
      vkResetDescriptorPool              = PFN_vkResetDescriptorPool( vkGetDeviceProcAddr( device, "vkResetDescriptorPool" ) );
      vkAllocateDescriptorSets           = PFN_vkAllocateDescriptorSets( vkGetDeviceProcAddr( device, "vkAllocateDescriptorSets" ) );
      vkFreeDescriptorSets               = PFN_vkFreeDescriptorSets( vkGetDeviceProcAddr( device, "vkFreeDescriptorSets" ) );
      vkUpdateDescriptorSets             = PFN_vkUpdateDescriptorSets( vkGetDeviceProcAddr( device, "vkUpdateDescriptorSets" ) );
      vkCreateFramebuffer                = PFN_vkCreateFramebuffer( vkGetDeviceProcAddr( device, "vkCreateFramebuffer" ) );
      vkDestroyFramebuffer               = PFN_vkDestroyFramebuffer( vkGetDeviceProcAddr( device, "vkDestroyFramebuffer" ) );
      vkCreateRenderPass                 = PFN_vkCreateRenderPass( vkGetDeviceProcAddr( device, "vkCreateRenderPass" ) );
      vkDestroyRenderPass                = PFN_vkDestroyRenderPass( vkGetDeviceProcAddr( device, "vkDestroyRenderPass" ) );
      vkGetRenderAreaGranularity         = PFN_vkGetRenderAreaGranularity( vkGetDeviceProcAddr( device, "vkGetRenderAreaGranularity" ) );
      vkCreateCommandPool                = PFN_vkCreateCommandPool( vkGetDeviceProcAddr( device, "vkCreateCommandPool" ) );
      vkDestroyCommandPool               = PFN_vkDestroyCommandPool( vkGetDeviceProcAddr( device, "vkDestroyCommandPool" ) );
      vkResetCommandPool                 = PFN_vkResetCommandPool( vkGetDeviceProcAddr( device, "vkResetCommandPool" ) );
      vkAllocateCommandBuffers           = PFN_vkAllocateCommandBuffers( vkGetDeviceProcAddr( device, "vkAllocateCommandBuffers" ) );
      vkFreeCommandBuffers               = PFN_vkFreeCommandBuffers( vkGetDeviceProcAddr( device, "vkFreeCommandBuffers" ) );
      vkBeginCommandBuffer               = PFN_vkBeginCommandBuffer( vkGetDeviceProcAddr( device, "vkBeginCommandBuffer" ) );
      vkEndCommandBuffer                 = PFN_vkEndCommandBuffer( vkGetDeviceProcAddr( device, "vkEndCommandBuffer" ) );
      vkResetCommandBuffer               = PFN_vkResetCommandBuffer( vkGetDeviceProcAddr( device, "vkResetCommandBuffer" ) );
      vkCmdBindPipeline                  = PFN_vkCmdBindPipeline( vkGetDeviceProcAddr( device, "vkCmdBindPipeline" ) );
      vkCmdSetViewport                   = PFN_vkCmdSetViewport( vkGetDeviceProcAddr( device, "vkCmdSetViewport" ) );
      vkCmdSetScissor                    = PFN_vkCmdSetScissor( vkGetDeviceProcAddr( device, "vkCmdSetScissor" ) );
      vkCmdSetLineWidth                  = PFN_vkCmdSetLineWidth( vkGetDeviceProcAddr( device, "vkCmdSetLineWidth" ) );
      vkCmdSetDepthBias                  = PFN_vkCmdSetDepthBias( vkGetDeviceProcAddr( device, "vkCmdSetDepthBias" ) );
      vkCmdSetBlendConstants             = PFN_vkCmdSetBlendConstants( vkGetDeviceProcAddr( device, "vkCmdSetBlendConstants" ) );
      vkCmdSetDepthBounds                = PFN_vkCmdSetDepthBounds( vkGetDeviceProcAddr( device, "vkCmdSetDepthBounds" ) );
      vkCmdSetStencilCompareMask         = PFN_vkCmdSetStencilCompareMask( vkGetDeviceProcAddr( device, "vkCmdSetStencilCompareMask" ) );
      vkCmdSetStencilWriteMask           = PFN_vkCmdSetStencilWriteMask( vkGetDeviceProcAddr( device, "vkCmdSetStencilWriteMask" ) );
      vkCmdSetStencilReference           = PFN_vkCmdSetStencilReference( vkGetDeviceProcAddr( device, "vkCmdSetStencilReference" ) );
      vkCmdBindDescriptorSets            = PFN_vkCmdBindDescriptorSets( vkGetDeviceProcAddr( device, "vkCmdBindDescriptorSets" ) );
      vkCmdBindIndexBuffer               = PFN_vkCmdBindIndexBuffer( vkGetDeviceProcAddr( device, "vkCmdBindIndexBuffer" ) );
      vkCmdBindVertexBuffers             = PFN_vkCmdBindVertexBuffers( vkGetDeviceProcAddr( device, "vkCmdBindVertexBuffers" ) );
      vkCmdDraw                          = PFN_vkCmdDraw( vkGetDeviceProcAddr( device, "vkCmdDraw" ) );
      vkCmdDrawIndexed                   = PFN_vkCmdDrawIndexed( vkGetDeviceProcAddr( device, "vkCmdDrawIndexed" ) );
      vkCmdDrawIndirect                  = PFN_vkCmdDrawIndirect( vkGetDeviceProcAddr( device, "vkCmdDrawIndirect" ) );
      vkCmdDrawIndexedIndirect           = PFN_vkCmdDrawIndexedIndirect( vkGetDeviceProcAddr( device, "vkCmdDrawIndexedIndirect" ) );
      vkCmdDispatch                      = PFN_vkCmdDispatch( vkGetDeviceProcAddr( device, "vkCmdDispatch" ) );
      vkCmdDispatchIndirect              = PFN_vkCmdDispatchIndirect( vkGetDeviceProcAddr( device, "vkCmdDispatchIndirect" ) );
      vkCmdCopyBuffer                    = PFN_vkCmdCopyBuffer( vkGetDeviceProcAddr( device, "vkCmdCopyBuffer" ) );
      vkCmdCopyImage                     = PFN_vkCmdCopyImage( vkGetDeviceProcAddr( device, "vkCmdCopyImage" ) );
      vkCmdBlitImage                     = PFN_vkCmdBlitImage( vkGetDeviceProcAddr( device, "vkCmdBlitImage" ) );
      vkCmdCopyBufferToImage             = PFN_vkCmdCopyBufferToImage( vkGetDeviceProcAddr( device, "vkCmdCopyBufferToImage" ) );
      vkCmdCopyImageToBuffer             = PFN_vkCmdCopyImageToBuffer( vkGetDeviceProcAddr( device, "vkCmdCopyImageToBuffer" ) );
      vkCmdUpdateBuffer                  = PFN_vkCmdUpdateBuffer( vkGetDeviceProcAddr( device, "vkCmdUpdateBuffer" ) );
      vkCmdFillBuffer                    = PFN_vkCmdFillBuffer( vkGetDeviceProcAddr( device, "vkCmdFillBuffer" ) );
      vkCmdClearColorImage               = PFN_vkCmdClearColorImage( vkGetDeviceProcAddr( device, "vkCmdClearColorImage" ) );
      vkCmdClearDepthStencilImage        = PFN_vkCmdClearDepthStencilImage( vkGetDeviceProcAddr( device, "vkCmdClearDepthStencilImage" ) );
      vkCmdClearAttachments              = PFN_vkCmdClearAttachments( vkGetDeviceProcAddr( device, "vkCmdClearAttachments" ) );
      vkCmdResolveImage                  = PFN_vkCmdResolveImage( vkGetDeviceProcAddr( device, "vkCmdResolveImage" ) );
      vkCmdSetEvent                      = PFN_vkCmdSetEvent( vkGetDeviceProcAddr( device, "vkCmdSetEvent" ) );
      vkCmdResetEvent                    = PFN_vkCmdResetEvent( vkGetDeviceProcAddr( device, "vkCmdResetEvent" ) );
      vkCmdWaitEvents                    = PFN_vkCmdWaitEvents( vkGetDeviceProcAddr( device, "vkCmdWaitEvents" ) );
      vkCmdPipelineBarrier               = PFN_vkCmdPipelineBarrier( vkGetDeviceProcAddr( device, "vkCmdPipelineBarrier" ) );
      vkCmdBeginQuery                    = PFN_vkCmdBeginQuery( vkGetDeviceProcAddr( device, "vkCmdBeginQuery" ) );
      vkCmdEndQuery                      = PFN_vkCmdEndQuery( vkGetDeviceProcAddr( device, "vkCmdEndQuery" ) );
      vkCmdResetQueryPool                = PFN_vkCmdResetQueryPool( vkGetDeviceProcAddr( device, "vkCmdResetQueryPool" ) );
      vkCmdWriteTimestamp                = PFN_vkCmdWriteTimestamp( vkGetDeviceProcAddr( device, "vkCmdWriteTimestamp" ) );
      vkCmdCopyQueryPoolResults          = PFN_vkCmdCopyQueryPoolResults( vkGetDeviceProcAddr( device, "vkCmdCopyQueryPoolResults" ) );
      vkCmdPushConstants                 = PFN_vkCmdPushConstants( vkGetDeviceProcAddr( device, "vkCmdPushConstants" ) );
      vkCmdBeginRenderPass               = PFN_vkCmdBeginRenderPass( vkGetDeviceProcAddr( device, "vkCmdBeginRenderPass" ) );
      vkCmdNextSubpass                   = PFN_vkCmdNextSubpass( vkGetDeviceProcAddr( device, "vkCmdNextSubpass" ) );
      vkCmdEndRenderPass                 = PFN_vkCmdEndRenderPass( vkGetDeviceProcAddr( device, "vkCmdEndRenderPass" ) );
      vkCmdExecuteCommands               = PFN_vkCmdExecuteCommands( vkGetDeviceProcAddr( device, "vkCmdExecuteCommands" ) );

      //=== VK_VERSION_1_1 ===
      vkBindBufferMemory2                 = PFN_vkBindBufferMemory2( vkGetDeviceProcAddr( device, "vkBindBufferMemory2" ) );
      vkBindImageMemory2                  = PFN_vkBindImageMemory2( vkGetDeviceProcAddr( device, "vkBindImageMemory2" ) );
      vkGetDeviceGroupPeerMemoryFeatures  = PFN_vkGetDeviceGroupPeerMemoryFeatures( vkGetDeviceProcAddr( device, "vkGetDeviceGroupPeerMemoryFeatures" ) );
      vkCmdSetDeviceMask                  = PFN_vkCmdSetDeviceMask( vkGetDeviceProcAddr( device, "vkCmdSetDeviceMask" ) );
      vkCmdDispatchBase                   = PFN_vkCmdDispatchBase( vkGetDeviceProcAddr( device, "vkCmdDispatchBase" ) );
      vkGetImageMemoryRequirements2       = PFN_vkGetImageMemoryRequirements2( vkGetDeviceProcAddr( device, "vkGetImageMemoryRequirements2" ) );
      vkGetBufferMemoryRequirements2      = PFN_vkGetBufferMemoryRequirements2( vkGetDeviceProcAddr( device, "vkGetBufferMemoryRequirements2" ) );
      vkGetImageSparseMemoryRequirements2 = PFN_vkGetImageSparseMemoryRequirements2( vkGetDeviceProcAddr( device, "vkGetImageSparseMemoryRequirements2" ) );
      vkTrimCommandPool                   = PFN_vkTrimCommandPool( vkGetDeviceProcAddr( device, "vkTrimCommandPool" ) );
      vkGetDeviceQueue2                   = PFN_vkGetDeviceQueue2( vkGetDeviceProcAddr( device, "vkGetDeviceQueue2" ) );
      vkCreateSamplerYcbcrConversion      = PFN_vkCreateSamplerYcbcrConversion( vkGetDeviceProcAddr( device, "vkCreateSamplerYcbcrConversion" ) );
      vkDestroySamplerYcbcrConversion     = PFN_vkDestroySamplerYcbcrConversion( vkGetDeviceProcAddr( device, "vkDestroySamplerYcbcrConversion" ) );
      vkCreateDescriptorUpdateTemplate    = PFN_vkCreateDescriptorUpdateTemplate( vkGetDeviceProcAddr( device, "vkCreateDescriptorUpdateTemplate" ) );
      vkDestroyDescriptorUpdateTemplate   = PFN_vkDestroyDescriptorUpdateTemplate( vkGetDeviceProcAddr( device, "vkDestroyDescriptorUpdateTemplate" ) );
      vkUpdateDescriptorSetWithTemplate   = PFN_vkUpdateDescriptorSetWithTemplate( vkGetDeviceProcAddr( device, "vkUpdateDescriptorSetWithTemplate" ) );
      vkGetDescriptorSetLayoutSupport     = PFN_vkGetDescriptorSetLayoutSupport( vkGetDeviceProcAddr( device, "vkGetDescriptorSetLayoutSupport" ) );

      //=== VK_VERSION_1_2 ===
      vkCmdDrawIndirectCount          = PFN_vkCmdDrawIndirectCount( vkGetDeviceProcAddr( device, "vkCmdDrawIndirectCount" ) );
      vkCmdDrawIndexedIndirectCount   = PFN_vkCmdDrawIndexedIndirectCount( vkGetDeviceProcAddr( device, "vkCmdDrawIndexedIndirectCount" ) );
      vkCreateRenderPass2             = PFN_vkCreateRenderPass2( vkGetDeviceProcAddr( device, "vkCreateRenderPass2" ) );
      vkCmdBeginRenderPass2           = PFN_vkCmdBeginRenderPass2( vkGetDeviceProcAddr( device, "vkCmdBeginRenderPass2" ) );
      vkCmdNextSubpass2               = PFN_vkCmdNextSubpass2( vkGetDeviceProcAddr( device, "vkCmdNextSubpass2" ) );
      vkCmdEndRenderPass2             = PFN_vkCmdEndRenderPass2( vkGetDeviceProcAddr( device, "vkCmdEndRenderPass2" ) );
      vkResetQueryPool                = PFN_vkResetQueryPool( vkGetDeviceProcAddr( device, "vkResetQueryPool" ) );
      vkGetSemaphoreCounterValue      = PFN_vkGetSemaphoreCounterValue( vkGetDeviceProcAddr( device, "vkGetSemaphoreCounterValue" ) );
      vkWaitSemaphores                = PFN_vkWaitSemaphores( vkGetDeviceProcAddr( device, "vkWaitSemaphores" ) );
      vkSignalSemaphore               = PFN_vkSignalSemaphore( vkGetDeviceProcAddr( device, "vkSignalSemaphore" ) );
      vkGetBufferDeviceAddress        = PFN_vkGetBufferDeviceAddress( vkGetDeviceProcAddr( device, "vkGetBufferDeviceAddress" ) );
      vkGetBufferOpaqueCaptureAddress = PFN_vkGetBufferOpaqueCaptureAddress( vkGetDeviceProcAddr( device, "vkGetBufferOpaqueCaptureAddress" ) );
      vkGetDeviceMemoryOpaqueCaptureAddress =
        PFN_vkGetDeviceMemoryOpaqueCaptureAddress( vkGetDeviceProcAddr( device, "vkGetDeviceMemoryOpaqueCaptureAddress" ) );

      //=== VK_VERSION_1_3 ===
      vkCreatePrivateDataSlot             = PFN_vkCreatePrivateDataSlot( vkGetDeviceProcAddr( device, "vkCreatePrivateDataSlot" ) );
      vkDestroyPrivateDataSlot            = PFN_vkDestroyPrivateDataSlot( vkGetDeviceProcAddr( device, "vkDestroyPrivateDataSlot" ) );
      vkSetPrivateData                    = PFN_vkSetPrivateData( vkGetDeviceProcAddr( device, "vkSetPrivateData" ) );
      vkGetPrivateData                    = PFN_vkGetPrivateData( vkGetDeviceProcAddr( device, "vkGetPrivateData" ) );
      vkCmdSetEvent2                      = PFN_vkCmdSetEvent2( vkGetDeviceProcAddr( device, "vkCmdSetEvent2" ) );
      vkCmdResetEvent2                    = PFN_vkCmdResetEvent2( vkGetDeviceProcAddr( device, "vkCmdResetEvent2" ) );
      vkCmdWaitEvents2                    = PFN_vkCmdWaitEvents2( vkGetDeviceProcAddr( device, "vkCmdWaitEvents2" ) );
      vkCmdPipelineBarrier2               = PFN_vkCmdPipelineBarrier2( vkGetDeviceProcAddr( device, "vkCmdPipelineBarrier2" ) );
      vkCmdWriteTimestamp2                = PFN_vkCmdWriteTimestamp2( vkGetDeviceProcAddr( device, "vkCmdWriteTimestamp2" ) );
      vkQueueSubmit2                      = PFN_vkQueueSubmit2( vkGetDeviceProcAddr( device, "vkQueueSubmit2" ) );
      vkCmdCopyBuffer2                    = PFN_vkCmdCopyBuffer2( vkGetDeviceProcAddr( device, "vkCmdCopyBuffer2" ) );
      vkCmdCopyImage2                     = PFN_vkCmdCopyImage2( vkGetDeviceProcAddr( device, "vkCmdCopyImage2" ) );
      vkCmdCopyBufferToImage2             = PFN_vkCmdCopyBufferToImage2( vkGetDeviceProcAddr( device, "vkCmdCopyBufferToImage2" ) );
      vkCmdCopyImageToBuffer2             = PFN_vkCmdCopyImageToBuffer2( vkGetDeviceProcAddr( device, "vkCmdCopyImageToBuffer2" ) );
      vkCmdBlitImage2                     = PFN_vkCmdBlitImage2( vkGetDeviceProcAddr( device, "vkCmdBlitImage2" ) );
      vkCmdResolveImage2                  = PFN_vkCmdResolveImage2( vkGetDeviceProcAddr( device, "vkCmdResolveImage2" ) );
      vkCmdBeginRendering                 = PFN_vkCmdBeginRendering( vkGetDeviceProcAddr( device, "vkCmdBeginRendering" ) );
      vkCmdEndRendering                   = PFN_vkCmdEndRendering( vkGetDeviceProcAddr( device, "vkCmdEndRendering" ) );
      vkCmdSetCullMode                    = PFN_vkCmdSetCullMode( vkGetDeviceProcAddr( device, "vkCmdSetCullMode" ) );
      vkCmdSetFrontFace                   = PFN_vkCmdSetFrontFace( vkGetDeviceProcAddr( device, "vkCmdSetFrontFace" ) );
      vkCmdSetPrimitiveTopology           = PFN_vkCmdSetPrimitiveTopology( vkGetDeviceProcAddr( device, "vkCmdSetPrimitiveTopology" ) );
      vkCmdSetViewportWithCount           = PFN_vkCmdSetViewportWithCount( vkGetDeviceProcAddr( device, "vkCmdSetViewportWithCount" ) );
      vkCmdSetScissorWithCount            = PFN_vkCmdSetScissorWithCount( vkGetDeviceProcAddr( device, "vkCmdSetScissorWithCount" ) );
      vkCmdBindVertexBuffers2             = PFN_vkCmdBindVertexBuffers2( vkGetDeviceProcAddr( device, "vkCmdBindVertexBuffers2" ) );
      vkCmdSetDepthTestEnable             = PFN_vkCmdSetDepthTestEnable( vkGetDeviceProcAddr( device, "vkCmdSetDepthTestEnable" ) );
      vkCmdSetDepthWriteEnable            = PFN_vkCmdSetDepthWriteEnable( vkGetDeviceProcAddr( device, "vkCmdSetDepthWriteEnable" ) );
      vkCmdSetDepthCompareOp              = PFN_vkCmdSetDepthCompareOp( vkGetDeviceProcAddr( device, "vkCmdSetDepthCompareOp" ) );
      vkCmdSetDepthBoundsTestEnable       = PFN_vkCmdSetDepthBoundsTestEnable( vkGetDeviceProcAddr( device, "vkCmdSetDepthBoundsTestEnable" ) );
      vkCmdSetStencilTestEnable           = PFN_vkCmdSetStencilTestEnable( vkGetDeviceProcAddr( device, "vkCmdSetStencilTestEnable" ) );
      vkCmdSetStencilOp                   = PFN_vkCmdSetStencilOp( vkGetDeviceProcAddr( device, "vkCmdSetStencilOp" ) );
      vkCmdSetRasterizerDiscardEnable     = PFN_vkCmdSetRasterizerDiscardEnable( vkGetDeviceProcAddr( device, "vkCmdSetRasterizerDiscardEnable" ) );
      vkCmdSetDepthBiasEnable             = PFN_vkCmdSetDepthBiasEnable( vkGetDeviceProcAddr( device, "vkCmdSetDepthBiasEnable" ) );
      vkCmdSetPrimitiveRestartEnable      = PFN_vkCmdSetPrimitiveRestartEnable( vkGetDeviceProcAddr( device, "vkCmdSetPrimitiveRestartEnable" ) );
      vkGetDeviceBufferMemoryRequirements = PFN_vkGetDeviceBufferMemoryRequirements( vkGetDeviceProcAddr( device, "vkGetDeviceBufferMemoryRequirements" ) );
      vkGetDeviceImageMemoryRequirements  = PFN_vkGetDeviceImageMemoryRequirements( vkGetDeviceProcAddr( device, "vkGetDeviceImageMemoryRequirements" ) );
      vkGetDeviceImageSparseMemoryRequirements =
        PFN_vkGetDeviceImageSparseMemoryRequirements( vkGetDeviceProcAddr( device, "vkGetDeviceImageSparseMemoryRequirements" ) );

      //=== VK_KHR_swapchain ===
      vkCreateSwapchainKHR    = PFN_vkCreateSwapchainKHR( vkGetDeviceProcAddr( device, "vkCreateSwapchainKHR" ) );
      vkDestroySwapchainKHR   = PFN_vkDestroySwapchainKHR( vkGetDeviceProcAddr( device, "vkDestroySwapchainKHR" ) );
      vkGetSwapchainImagesKHR = PFN_vkGetSwapchainImagesKHR( vkGetDeviceProcAddr( device, "vkGetSwapchainImagesKHR" ) );
      vkAcquireNextImageKHR   = PFN_vkAcquireNextImageKHR( vkGetDeviceProcAddr( device, "vkAcquireNextImageKHR" ) );
      vkQueuePresentKHR       = PFN_vkQueuePresentKHR( vkGetDeviceProcAddr( device, "vkQueuePresentKHR" ) );
      vkGetDeviceGroupPresentCapabilitiesKHR =
        PFN_vkGetDeviceGroupPresentCapabilitiesKHR( vkGetDeviceProcAddr( device, "vkGetDeviceGroupPresentCapabilitiesKHR" ) );
      vkGetDeviceGroupSurfacePresentModesKHR =
        PFN_vkGetDeviceGroupSurfacePresentModesKHR( vkGetDeviceProcAddr( device, "vkGetDeviceGroupSurfacePresentModesKHR" ) );
      vkAcquireNextImage2KHR = PFN_vkAcquireNextImage2KHR( vkGetDeviceProcAddr( device, "vkAcquireNextImage2KHR" ) );

      //=== VK_KHR_display_swapchain ===
      vkCreateSharedSwapchainsKHR = PFN_vkCreateSharedSwapchainsKHR( vkGetDeviceProcAddr( device, "vkCreateSharedSwapchainsKHR" ) );

      //=== VK_EXT_debug_marker ===
      vkDebugMarkerSetObjectTagEXT  = PFN_vkDebugMarkerSetObjectTagEXT( vkGetDeviceProcAddr( device, "vkDebugMarkerSetObjectTagEXT" ) );
      vkDebugMarkerSetObjectNameEXT = PFN_vkDebugMarkerSetObjectNameEXT( vkGetDeviceProcAddr( device, "vkDebugMarkerSetObjectNameEXT" ) );
      vkCmdDebugMarkerBeginEXT      = PFN_vkCmdDebugMarkerBeginEXT( vkGetDeviceProcAddr( device, "vkCmdDebugMarkerBeginEXT" ) );
      vkCmdDebugMarkerEndEXT        = PFN_vkCmdDebugMarkerEndEXT( vkGetDeviceProcAddr( device, "vkCmdDebugMarkerEndEXT" ) );
      vkCmdDebugMarkerInsertEXT     = PFN_vkCmdDebugMarkerInsertEXT( vkGetDeviceProcAddr( device, "vkCmdDebugMarkerInsertEXT" ) );

      //=== VK_KHR_video_queue ===
      vkCreateVideoSessionKHR  = PFN_vkCreateVideoSessionKHR( vkGetDeviceProcAddr( device, "vkCreateVideoSessionKHR" ) );
      vkDestroyVideoSessionKHR = PFN_vkDestroyVideoSessionKHR( vkGetDeviceProcAddr( device, "vkDestroyVideoSessionKHR" ) );
      vkGetVideoSessionMemoryRequirementsKHR =
        PFN_vkGetVideoSessionMemoryRequirementsKHR( vkGetDeviceProcAddr( device, "vkGetVideoSessionMemoryRequirementsKHR" ) );
      vkBindVideoSessionMemoryKHR        = PFN_vkBindVideoSessionMemoryKHR( vkGetDeviceProcAddr( device, "vkBindVideoSessionMemoryKHR" ) );
      vkCreateVideoSessionParametersKHR  = PFN_vkCreateVideoSessionParametersKHR( vkGetDeviceProcAddr( device, "vkCreateVideoSessionParametersKHR" ) );
      vkUpdateVideoSessionParametersKHR  = PFN_vkUpdateVideoSessionParametersKHR( vkGetDeviceProcAddr( device, "vkUpdateVideoSessionParametersKHR" ) );
      vkDestroyVideoSessionParametersKHR = PFN_vkDestroyVideoSessionParametersKHR( vkGetDeviceProcAddr( device, "vkDestroyVideoSessionParametersKHR" ) );
      vkCmdBeginVideoCodingKHR           = PFN_vkCmdBeginVideoCodingKHR( vkGetDeviceProcAddr( device, "vkCmdBeginVideoCodingKHR" ) );
      vkCmdEndVideoCodingKHR             = PFN_vkCmdEndVideoCodingKHR( vkGetDeviceProcAddr( device, "vkCmdEndVideoCodingKHR" ) );
      vkCmdControlVideoCodingKHR         = PFN_vkCmdControlVideoCodingKHR( vkGetDeviceProcAddr( device, "vkCmdControlVideoCodingKHR" ) );

      //=== VK_KHR_video_decode_queue ===
      vkCmdDecodeVideoKHR = PFN_vkCmdDecodeVideoKHR( vkGetDeviceProcAddr( device, "vkCmdDecodeVideoKHR" ) );

      //=== VK_EXT_transform_feedback ===
      vkCmdBindTransformFeedbackBuffersEXT = PFN_vkCmdBindTransformFeedbackBuffersEXT( vkGetDeviceProcAddr( device, "vkCmdBindTransformFeedbackBuffersEXT" ) );
      vkCmdBeginTransformFeedbackEXT       = PFN_vkCmdBeginTransformFeedbackEXT( vkGetDeviceProcAddr( device, "vkCmdBeginTransformFeedbackEXT" ) );
      vkCmdEndTransformFeedbackEXT         = PFN_vkCmdEndTransformFeedbackEXT( vkGetDeviceProcAddr( device, "vkCmdEndTransformFeedbackEXT" ) );
      vkCmdBeginQueryIndexedEXT            = PFN_vkCmdBeginQueryIndexedEXT( vkGetDeviceProcAddr( device, "vkCmdBeginQueryIndexedEXT" ) );
      vkCmdEndQueryIndexedEXT              = PFN_vkCmdEndQueryIndexedEXT( vkGetDeviceProcAddr( device, "vkCmdEndQueryIndexedEXT" ) );
      vkCmdDrawIndirectByteCountEXT        = PFN_vkCmdDrawIndirectByteCountEXT( vkGetDeviceProcAddr( device, "vkCmdDrawIndirectByteCountEXT" ) );

      //=== VK_NVX_binary_import ===
      vkCreateCuModuleNVX    = PFN_vkCreateCuModuleNVX( vkGetDeviceProcAddr( device, "vkCreateCuModuleNVX" ) );
      vkCreateCuFunctionNVX  = PFN_vkCreateCuFunctionNVX( vkGetDeviceProcAddr( device, "vkCreateCuFunctionNVX" ) );
      vkDestroyCuModuleNVX   = PFN_vkDestroyCuModuleNVX( vkGetDeviceProcAddr( device, "vkDestroyCuModuleNVX" ) );
      vkDestroyCuFunctionNVX = PFN_vkDestroyCuFunctionNVX( vkGetDeviceProcAddr( device, "vkDestroyCuFunctionNVX" ) );
      vkCmdCuLaunchKernelNVX = PFN_vkCmdCuLaunchKernelNVX( vkGetDeviceProcAddr( device, "vkCmdCuLaunchKernelNVX" ) );

      //=== VK_NVX_image_view_handle ===
      vkGetImageViewHandleNVX  = PFN_vkGetImageViewHandleNVX( vkGetDeviceProcAddr( device, "vkGetImageViewHandleNVX" ) );
      vkGetImageViewAddressNVX = PFN_vkGetImageViewAddressNVX( vkGetDeviceProcAddr( device, "vkGetImageViewAddressNVX" ) );

      //=== VK_AMD_draw_indirect_count ===
      vkCmdDrawIndirectCountAMD = PFN_vkCmdDrawIndirectCountAMD( vkGetDeviceProcAddr( device, "vkCmdDrawIndirectCountAMD" ) );
      if ( !vkCmdDrawIndirectCount )
        vkCmdDrawIndirectCount = vkCmdDrawIndirectCountAMD;
      vkCmdDrawIndexedIndirectCountAMD = PFN_vkCmdDrawIndexedIndirectCountAMD( vkGetDeviceProcAddr( device, "vkCmdDrawIndexedIndirectCountAMD" ) );
      if ( !vkCmdDrawIndexedIndirectCount )
        vkCmdDrawIndexedIndirectCount = vkCmdDrawIndexedIndirectCountAMD;

      //=== VK_AMD_shader_info ===
      vkGetShaderInfoAMD = PFN_vkGetShaderInfoAMD( vkGetDeviceProcAddr( device, "vkGetShaderInfoAMD" ) );

      //=== VK_KHR_dynamic_rendering ===
      vkCmdBeginRenderingKHR = PFN_vkCmdBeginRenderingKHR( vkGetDeviceProcAddr( device, "vkCmdBeginRenderingKHR" ) );
      if ( !vkCmdBeginRendering )
        vkCmdBeginRendering = vkCmdBeginRenderingKHR;
      vkCmdEndRenderingKHR = PFN_vkCmdEndRenderingKHR( vkGetDeviceProcAddr( device, "vkCmdEndRenderingKHR" ) );
      if ( !vkCmdEndRendering )
        vkCmdEndRendering = vkCmdEndRenderingKHR;

#if defined( VK_USE_PLATFORM_WIN32_KHR )
      //=== VK_NV_external_memory_win32 ===
      vkGetMemoryWin32HandleNV = PFN_vkGetMemoryWin32HandleNV( vkGetDeviceProcAddr( device, "vkGetMemoryWin32HandleNV" ) );
#endif /*VK_USE_PLATFORM_WIN32_KHR*/

       //=== VK_KHR_device_group ===
      vkGetDeviceGroupPeerMemoryFeaturesKHR =
        PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR( vkGetDeviceProcAddr( device, "vkGetDeviceGroupPeerMemoryFeaturesKHR" ) );
      if ( !vkGetDeviceGroupPeerMemoryFeatures )
        vkGetDeviceGroupPeerMemoryFeatures = vkGetDeviceGroupPeerMemoryFeaturesKHR;
      vkCmdSetDeviceMaskKHR = PFN_vkCmdSetDeviceMaskKHR( vkGetDeviceProcAddr( device, "vkCmdSetDeviceMaskKHR" ) );
      if ( !vkCmdSetDeviceMask )
        vkCmdSetDeviceMask = vkCmdSetDeviceMaskKHR;
      vkCmdDispatchBaseKHR = PFN_vkCmdDispatchBaseKHR( vkGetDeviceProcAddr( device, "vkCmdDispatchBaseKHR" ) );
      if ( !vkCmdDispatchBase )
        vkCmdDispatchBase = vkCmdDispatchBaseKHR;

      //=== VK_KHR_maintenance1 ===
      vkTrimCommandPoolKHR = PFN_vkTrimCommandPoolKHR( vkGetDeviceProcAddr( device, "vkTrimCommandPoolKHR" ) );
      if ( !vkTrimCommandPool )
        vkTrimCommandPool = vkTrimCommandPoolKHR;

#if defined( VK_USE_PLATFORM_WIN32_KHR )
      //=== VK_KHR_external_memory_win32 ===
      vkGetMemoryWin32HandleKHR           = PFN_vkGetMemoryWin32HandleKHR( vkGetDeviceProcAddr( device, "vkGetMemoryWin32HandleKHR" ) );
      vkGetMemoryWin32HandlePropertiesKHR = PFN_vkGetMemoryWin32HandlePropertiesKHR( vkGetDeviceProcAddr( device, "vkGetMemoryWin32HandlePropertiesKHR" ) );
#endif /*VK_USE_PLATFORM_WIN32_KHR*/

       //=== VK_KHR_external_memory_fd ===
      vkGetMemoryFdKHR           = PFN_vkGetMemoryFdKHR( vkGetDeviceProcAddr( device, "vkGetMemoryFdKHR" ) );
      vkGetMemoryFdPropertiesKHR = PFN_vkGetMemoryFdPropertiesKHR( vkGetDeviceProcAddr( device, "vkGetMemoryFdPropertiesKHR" ) );

#if defined( VK_USE_PLATFORM_WIN32_KHR )
      //=== VK_KHR_external_semaphore_win32 ===
      vkImportSemaphoreWin32HandleKHR = PFN_vkImportSemaphoreWin32HandleKHR( vkGetDeviceProcAddr( device, "vkImportSemaphoreWin32HandleKHR" ) );
      vkGetSemaphoreWin32HandleKHR    = PFN_vkGetSemaphoreWin32HandleKHR( vkGetDeviceProcAddr( device, "vkGetSemaphoreWin32HandleKHR" ) );
#endif /*VK_USE_PLATFORM_WIN32_KHR*/

       //=== VK_KHR_external_semaphore_fd ===
      vkImportSemaphoreFdKHR = PFN_vkImportSemaphoreFdKHR( vkGetDeviceProcAddr( device, "vkImportSemaphoreFdKHR" ) );
      vkGetSemaphoreFdKHR    = PFN_vkGetSemaphoreFdKHR( vkGetDeviceProcAddr( device, "vkGetSemaphoreFdKHR" ) );

      //=== VK_KHR_push_descriptor ===
      vkCmdPushDescriptorSetKHR = PFN_vkCmdPushDescriptorSetKHR( vkGetDeviceProcAddr( device, "vkCmdPushDescriptorSetKHR" ) );
      vkCmdPushDescriptorSetWithTemplateKHR =
        PFN_vkCmdPushDescriptorSetWithTemplateKHR( vkGetDeviceProcAddr( device, "vkCmdPushDescriptorSetWithTemplateKHR" ) );

      //=== VK_EXT_conditional_rendering ===
      vkCmdBeginConditionalRenderingEXT = PFN_vkCmdBeginConditionalRenderingEXT( vkGetDeviceProcAddr( device, "vkCmdBeginConditionalRenderingEXT" ) );
      vkCmdEndConditionalRenderingEXT   = PFN_vkCmdEndConditionalRenderingEXT( vkGetDeviceProcAddr( device, "vkCmdEndConditionalRenderingEXT" ) );

      //=== VK_KHR_descriptor_update_template ===
      vkCreateDescriptorUpdateTemplateKHR = PFN_vkCreateDescriptorUpdateTemplateKHR( vkGetDeviceProcAddr( device, "vkCreateDescriptorUpdateTemplateKHR" ) );
      if ( !vkCreateDescriptorUpdateTemplate )
        vkCreateDescriptorUpdateTemplate = vkCreateDescriptorUpdateTemplateKHR;
      vkDestroyDescriptorUpdateTemplateKHR = PFN_vkDestroyDescriptorUpdateTemplateKHR( vkGetDeviceProcAddr( device, "vkDestroyDescriptorUpdateTemplateKHR" ) );
      if ( !vkDestroyDescriptorUpdateTemplate )
        vkDestroyDescriptorUpdateTemplate = vkDestroyDescriptorUpdateTemplateKHR;
      vkUpdateDescriptorSetWithTemplateKHR = PFN_vkUpdateDescriptorSetWithTemplateKHR( vkGetDeviceProcAddr( device, "vkUpdateDescriptorSetWithTemplateKHR" ) );
      if ( !vkUpdateDescriptorSetWithTemplate )
        vkUpdateDescriptorSetWithTemplate = vkUpdateDescriptorSetWithTemplateKHR;

      //=== VK_NV_clip_space_w_scaling ===
      vkCmdSetViewportWScalingNV = PFN_vkCmdSetViewportWScalingNV( vkGetDeviceProcAddr( device, "vkCmdSetViewportWScalingNV" ) );

      //=== VK_EXT_display_control ===
      vkDisplayPowerControlEXT  = PFN_vkDisplayPowerControlEXT( vkGetDeviceProcAddr( device, "vkDisplayPowerControlEXT" ) );
      vkRegisterDeviceEventEXT  = PFN_vkRegisterDeviceEventEXT( vkGetDeviceProcAddr( device, "vkRegisterDeviceEventEXT" ) );
      vkRegisterDisplayEventEXT = PFN_vkRegisterDisplayEventEXT( vkGetDeviceProcAddr( device, "vkRegisterDisplayEventEXT" ) );
      vkGetSwapchainCounterEXT  = PFN_vkGetSwapchainCounterEXT( vkGetDeviceProcAddr( device, "vkGetSwapchainCounterEXT" ) );

      //=== VK_GOOGLE_display_timing ===
      vkGetRefreshCycleDurationGOOGLE   = PFN_vkGetRefreshCycleDurationGOOGLE( vkGetDeviceProcAddr( device, "vkGetRefreshCycleDurationGOOGLE" ) );
      vkGetPastPresentationTimingGOOGLE = PFN_vkGetPastPresentationTimingGOOGLE( vkGetDeviceProcAddr( device, "vkGetPastPresentationTimingGOOGLE" ) );

      //=== VK_EXT_discard_rectangles ===
      vkCmdSetDiscardRectangleEXT = PFN_vkCmdSetDiscardRectangleEXT( vkGetDeviceProcAddr( device, "vkCmdSetDiscardRectangleEXT" ) );

      //=== VK_EXT_hdr_metadata ===
      vkSetHdrMetadataEXT = PFN_vkSetHdrMetadataEXT( vkGetDeviceProcAddr( device, "vkSetHdrMetadataEXT" ) );

      //=== VK_KHR_create_renderpass2 ===
      vkCreateRenderPass2KHR = PFN_vkCreateRenderPass2KHR( vkGetDeviceProcAddr( device, "vkCreateRenderPass2KHR" ) );
      if ( !vkCreateRenderPass2 )
        vkCreateRenderPass2 = vkCreateRenderPass2KHR;
      vkCmdBeginRenderPass2KHR = PFN_vkCmdBeginRenderPass2KHR( vkGetDeviceProcAddr( device, "vkCmdBeginRenderPass2KHR" ) );
      if ( !vkCmdBeginRenderPass2 )
        vkCmdBeginRenderPass2 = vkCmdBeginRenderPass2KHR;
      vkCmdNextSubpass2KHR = PFN_vkCmdNextSubpass2KHR( vkGetDeviceProcAddr( device, "vkCmdNextSubpass2KHR" ) );
      if ( !vkCmdNextSubpass2 )
        vkCmdNextSubpass2 = vkCmdNextSubpass2KHR;
      vkCmdEndRenderPass2KHR = PFN_vkCmdEndRenderPass2KHR( vkGetDeviceProcAddr( device, "vkCmdEndRenderPass2KHR" ) );
      if ( !vkCmdEndRenderPass2 )
        vkCmdEndRenderPass2 = vkCmdEndRenderPass2KHR;

      //=== VK_KHR_shared_presentable_image ===
      vkGetSwapchainStatusKHR = PFN_vkGetSwapchainStatusKHR( vkGetDeviceProcAddr( device, "vkGetSwapchainStatusKHR" ) );

#if defined( VK_USE_PLATFORM_WIN32_KHR )
      //=== VK_KHR_external_fence_win32 ===
      vkImportFenceWin32HandleKHR = PFN_vkImportFenceWin32HandleKHR( vkGetDeviceProcAddr( device, "vkImportFenceWin32HandleKHR" ) );
      vkGetFenceWin32HandleKHR    = PFN_vkGetFenceWin32HandleKHR( vkGetDeviceProcAddr( device, "vkGetFenceWin32HandleKHR" ) );
#endif /*VK_USE_PLATFORM_WIN32_KHR*/

       //=== VK_KHR_external_fence_fd ===
      vkImportFenceFdKHR = PFN_vkImportFenceFdKHR( vkGetDeviceProcAddr( device, "vkImportFenceFdKHR" ) );
      vkGetFenceFdKHR    = PFN_vkGetFenceFdKHR( vkGetDeviceProcAddr( device, "vkGetFenceFdKHR" ) );

      //=== VK_KHR_performance_query ===
      vkAcquireProfilingLockKHR = PFN_vkAcquireProfilingLockKHR( vkGetDeviceProcAddr( device, "vkAcquireProfilingLockKHR" ) );
      vkReleaseProfilingLockKHR = PFN_vkReleaseProfilingLockKHR( vkGetDeviceProcAddr( device, "vkReleaseProfilingLockKHR" ) );

      //=== VK_EXT_debug_utils ===
      vkSetDebugUtilsObjectNameEXT    = PFN_vkSetDebugUtilsObjectNameEXT( vkGetDeviceProcAddr( device, "vkSetDebugUtilsObjectNameEXT" ) );
      vkSetDebugUtilsObjectTagEXT     = PFN_vkSetDebugUtilsObjectTagEXT( vkGetDeviceProcAddr( device, "vkSetDebugUtilsObjectTagEXT" ) );
      vkQueueBeginDebugUtilsLabelEXT  = PFN_vkQueueBeginDebugUtilsLabelEXT( vkGetDeviceProcAddr( device, "vkQueueBeginDebugUtilsLabelEXT" ) );
      vkQueueEndDebugUtilsLabelEXT    = PFN_vkQueueEndDebugUtilsLabelEXT( vkGetDeviceProcAddr( device, "vkQueueEndDebugUtilsLabelEXT" ) );
      vkQueueInsertDebugUtilsLabelEXT = PFN_vkQueueInsertDebugUtilsLabelEXT( vkGetDeviceProcAddr( device, "vkQueueInsertDebugUtilsLabelEXT" ) );
      vkCmdBeginDebugUtilsLabelEXT    = PFN_vkCmdBeginDebugUtilsLabelEXT( vkGetDeviceProcAddr( device, "vkCmdBeginDebugUtilsLabelEXT" ) );
      vkCmdEndDebugUtilsLabelEXT      = PFN_vkCmdEndDebugUtilsLabelEXT( vkGetDeviceProcAddr( device, "vkCmdEndDebugUtilsLabelEXT" ) );
      vkCmdInsertDebugUtilsLabelEXT   = PFN_vkCmdInsertDebugUtilsLabelEXT( vkGetDeviceProcAddr( device, "vkCmdInsertDebugUtilsLabelEXT" ) );

#if defined( VK_USE_PLATFORM_ANDROID_KHR )
      //=== VK_ANDROID_external_memory_android_hardware_buffer ===
      vkGetAndroidHardwareBufferPropertiesANDROID =
        PFN_vkGetAndroidHardwareBufferPropertiesANDROID( vkGetDeviceProcAddr( device, "vkGetAndroidHardwareBufferPropertiesANDROID" ) );
      vkGetMemoryAndroidHardwareBufferANDROID =
        PFN_vkGetMemoryAndroidHardwareBufferANDROID( vkGetDeviceProcAddr( device, "vkGetMemoryAndroidHardwareBufferANDROID" ) );
#endif /*VK_USE_PLATFORM_ANDROID_KHR*/

       //=== VK_EXT_sample_locations ===
      vkCmdSetSampleLocationsEXT = PFN_vkCmdSetSampleLocationsEXT( vkGetDeviceProcAddr( device, "vkCmdSetSampleLocationsEXT" ) );

      //=== VK_KHR_get_memory_requirements2 ===
      vkGetImageMemoryRequirements2KHR = PFN_vkGetImageMemoryRequirements2KHR( vkGetDeviceProcAddr( device, "vkGetImageMemoryRequirements2KHR" ) );
      if ( !vkGetImageMemoryRequirements2 )
        vkGetImageMemoryRequirements2 = vkGetImageMemoryRequirements2KHR;
      vkGetBufferMemoryRequirements2KHR = PFN_vkGetBufferMemoryRequirements2KHR( vkGetDeviceProcAddr( device, "vkGetBufferMemoryRequirements2KHR" ) );
      if ( !vkGetBufferMemoryRequirements2 )
        vkGetBufferMemoryRequirements2 = vkGetBufferMemoryRequirements2KHR;
      vkGetImageSparseMemoryRequirements2KHR =
        PFN_vkGetImageSparseMemoryRequirements2KHR( vkGetDeviceProcAddr( device, "vkGetImageSparseMemoryRequirements2KHR" ) );
      if ( !vkGetImageSparseMemoryRequirements2 )
        vkGetImageSparseMemoryRequirements2 = vkGetImageSparseMemoryRequirements2KHR;

      //=== VK_KHR_acceleration_structure ===
      vkCreateAccelerationStructureKHR    = PFN_vkCreateAccelerationStructureKHR( vkGetDeviceProcAddr( device, "vkCreateAccelerationStructureKHR" ) );
      vkDestroyAccelerationStructureKHR   = PFN_vkDestroyAccelerationStructureKHR( vkGetDeviceProcAddr( device, "vkDestroyAccelerationStructureKHR" ) );
      vkCmdBuildAccelerationStructuresKHR = PFN_vkCmdBuildAccelerationStructuresKHR( vkGetDeviceProcAddr( device, "vkCmdBuildAccelerationStructuresKHR" ) );
      vkCmdBuildAccelerationStructuresIndirectKHR =
        PFN_vkCmdBuildAccelerationStructuresIndirectKHR( vkGetDeviceProcAddr( device, "vkCmdBuildAccelerationStructuresIndirectKHR" ) );
      vkBuildAccelerationStructuresKHR = PFN_vkBuildAccelerationStructuresKHR( vkGetDeviceProcAddr( device, "vkBuildAccelerationStructuresKHR" ) );
      vkCopyAccelerationStructureKHR   = PFN_vkCopyAccelerationStructureKHR( vkGetDeviceProcAddr( device, "vkCopyAccelerationStructureKHR" ) );
      vkCopyAccelerationStructureToMemoryKHR =
        PFN_vkCopyAccelerationStructureToMemoryKHR( vkGetDeviceProcAddr( device, "vkCopyAccelerationStructureToMemoryKHR" ) );
      vkCopyMemoryToAccelerationStructureKHR =
        PFN_vkCopyMemoryToAccelerationStructureKHR( vkGetDeviceProcAddr( device, "vkCopyMemoryToAccelerationStructureKHR" ) );
      vkWriteAccelerationStructuresPropertiesKHR =
        PFN_vkWriteAccelerationStructuresPropertiesKHR( vkGetDeviceProcAddr( device, "vkWriteAccelerationStructuresPropertiesKHR" ) );
      vkCmdCopyAccelerationStructureKHR = PFN_vkCmdCopyAccelerationStructureKHR( vkGetDeviceProcAddr( device, "vkCmdCopyAccelerationStructureKHR" ) );
      vkCmdCopyAccelerationStructureToMemoryKHR =
        PFN_vkCmdCopyAccelerationStructureToMemoryKHR( vkGetDeviceProcAddr( device, "vkCmdCopyAccelerationStructureToMemoryKHR" ) );
      vkCmdCopyMemoryToAccelerationStructureKHR =
        PFN_vkCmdCopyMemoryToAccelerationStructureKHR( vkGetDeviceProcAddr( device, "vkCmdCopyMemoryToAccelerationStructureKHR" ) );
      vkGetAccelerationStructureDeviceAddressKHR =
        PFN_vkGetAccelerationStructureDeviceAddressKHR( vkGetDeviceProcAddr( device, "vkGetAccelerationStructureDeviceAddressKHR" ) );
      vkCmdWriteAccelerationStructuresPropertiesKHR =
        PFN_vkCmdWriteAccelerationStructuresPropertiesKHR( vkGetDeviceProcAddr( device, "vkCmdWriteAccelerationStructuresPropertiesKHR" ) );
      vkGetDeviceAccelerationStructureCompatibilityKHR =
        PFN_vkGetDeviceAccelerationStructureCompatibilityKHR( vkGetDeviceProcAddr( device, "vkGetDeviceAccelerationStructureCompatibilityKHR" ) );
      vkGetAccelerationStructureBuildSizesKHR =
        PFN_vkGetAccelerationStructureBuildSizesKHR( vkGetDeviceProcAddr( device, "vkGetAccelerationStructureBuildSizesKHR" ) );

      //=== VK_KHR_sampler_ycbcr_conversion ===
      vkCreateSamplerYcbcrConversionKHR = PFN_vkCreateSamplerYcbcrConversionKHR( vkGetDeviceProcAddr( device, "vkCreateSamplerYcbcrConversionKHR" ) );
      if ( !vkCreateSamplerYcbcrConversion )
        vkCreateSamplerYcbcrConversion = vkCreateSamplerYcbcrConversionKHR;
      vkDestroySamplerYcbcrConversionKHR = PFN_vkDestroySamplerYcbcrConversionKHR( vkGetDeviceProcAddr( device, "vkDestroySamplerYcbcrConversionKHR" ) );
      if ( !vkDestroySamplerYcbcrConversion )
        vkDestroySamplerYcbcrConversion = vkDestroySamplerYcbcrConversionKHR;

      //=== VK_KHR_bind_memory2 ===
      vkBindBufferMemory2KHR = PFN_vkBindBufferMemory2KHR( vkGetDeviceProcAddr( device, "vkBindBufferMemory2KHR" ) );
      if ( !vkBindBufferMemory2 )
        vkBindBufferMemory2 = vkBindBufferMemory2KHR;
      vkBindImageMemory2KHR = PFN_vkBindImageMemory2KHR( vkGetDeviceProcAddr( device, "vkBindImageMemory2KHR" ) );
      if ( !vkBindImageMemory2 )
        vkBindImageMemory2 = vkBindImageMemory2KHR;

      //=== VK_EXT_image_drm_format_modifier ===
      vkGetImageDrmFormatModifierPropertiesEXT =
        PFN_vkGetImageDrmFormatModifierPropertiesEXT( vkGetDeviceProcAddr( device, "vkGetImageDrmFormatModifierPropertiesEXT" ) );

      //=== VK_EXT_validation_cache ===
      vkCreateValidationCacheEXT  = PFN_vkCreateValidationCacheEXT( vkGetDeviceProcAddr( device, "vkCreateValidationCacheEXT" ) );
      vkDestroyValidationCacheEXT = PFN_vkDestroyValidationCacheEXT( vkGetDeviceProcAddr( device, "vkDestroyValidationCacheEXT" ) );
      vkMergeValidationCachesEXT  = PFN_vkMergeValidationCachesEXT( vkGetDeviceProcAddr( device, "vkMergeValidationCachesEXT" ) );
      vkGetValidationCacheDataEXT = PFN_vkGetValidationCacheDataEXT( vkGetDeviceProcAddr( device, "vkGetValidationCacheDataEXT" ) );

      //=== VK_NV_shading_rate_image ===
      vkCmdBindShadingRateImageNV          = PFN_vkCmdBindShadingRateImageNV( vkGetDeviceProcAddr( device, "vkCmdBindShadingRateImageNV" ) );
      vkCmdSetViewportShadingRatePaletteNV = PFN_vkCmdSetViewportShadingRatePaletteNV( vkGetDeviceProcAddr( device, "vkCmdSetViewportShadingRatePaletteNV" ) );
      vkCmdSetCoarseSampleOrderNV          = PFN_vkCmdSetCoarseSampleOrderNV( vkGetDeviceProcAddr( device, "vkCmdSetCoarseSampleOrderNV" ) );

      //=== VK_NV_ray_tracing ===
      vkCreateAccelerationStructureNV  = PFN_vkCreateAccelerationStructureNV( vkGetDeviceProcAddr( device, "vkCreateAccelerationStructureNV" ) );
      vkDestroyAccelerationStructureNV = PFN_vkDestroyAccelerationStructureNV( vkGetDeviceProcAddr( device, "vkDestroyAccelerationStructureNV" ) );
      vkGetAccelerationStructureMemoryRequirementsNV =
        PFN_vkGetAccelerationStructureMemoryRequirementsNV( vkGetDeviceProcAddr( device, "vkGetAccelerationStructureMemoryRequirementsNV" ) );
      vkBindAccelerationStructureMemoryNV = PFN_vkBindAccelerationStructureMemoryNV( vkGetDeviceProcAddr( device, "vkBindAccelerationStructureMemoryNV" ) );
      vkCmdBuildAccelerationStructureNV   = PFN_vkCmdBuildAccelerationStructureNV( vkGetDeviceProcAddr( device, "vkCmdBuildAccelerationStructureNV" ) );
      vkCmdCopyAccelerationStructureNV    = PFN_vkCmdCopyAccelerationStructureNV( vkGetDeviceProcAddr( device, "vkCmdCopyAccelerationStructureNV" ) );
      vkCmdTraceRaysNV                    = PFN_vkCmdTraceRaysNV( vkGetDeviceProcAddr( device, "vkCmdTraceRaysNV" ) );
      vkCreateRayTracingPipelinesNV       = PFN_vkCreateRayTracingPipelinesNV( vkGetDeviceProcAddr( device, "vkCreateRayTracingPipelinesNV" ) );
      vkGetRayTracingShaderGroupHandlesNV = PFN_vkGetRayTracingShaderGroupHandlesNV( vkGetDeviceProcAddr( device, "vkGetRayTracingShaderGroupHandlesNV" ) );
      if ( !vkGetRayTracingShaderGroupHandlesKHR )
        vkGetRayTracingShaderGroupHandlesKHR = vkGetRayTracingShaderGroupHandlesNV;
      vkGetAccelerationStructureHandleNV = PFN_vkGetAccelerationStructureHandleNV( vkGetDeviceProcAddr( device, "vkGetAccelerationStructureHandleNV" ) );
      vkCmdWriteAccelerationStructuresPropertiesNV =
        PFN_vkCmdWriteAccelerationStructuresPropertiesNV( vkGetDeviceProcAddr( device, "vkCmdWriteAccelerationStructuresPropertiesNV" ) );
      vkCompileDeferredNV = PFN_vkCompileDeferredNV( vkGetDeviceProcAddr( device, "vkCompileDeferredNV" ) );

      //=== VK_KHR_maintenance3 ===
      vkGetDescriptorSetLayoutSupportKHR = PFN_vkGetDescriptorSetLayoutSupportKHR( vkGetDeviceProcAddr( device, "vkGetDescriptorSetLayoutSupportKHR" ) );
      if ( !vkGetDescriptorSetLayoutSupport )
        vkGetDescriptorSetLayoutSupport = vkGetDescriptorSetLayoutSupportKHR;

      //=== VK_KHR_draw_indirect_count ===
      vkCmdDrawIndirectCountKHR = PFN_vkCmdDrawIndirectCountKHR( vkGetDeviceProcAddr( device, "vkCmdDrawIndirectCountKHR" ) );
      if ( !vkCmdDrawIndirectCount )
        vkCmdDrawIndirectCount = vkCmdDrawIndirectCountKHR;
      vkCmdDrawIndexedIndirectCountKHR = PFN_vkCmdDrawIndexedIndirectCountKHR( vkGetDeviceProcAddr( device, "vkCmdDrawIndexedIndirectCountKHR" ) );
      if ( !vkCmdDrawIndexedIndirectCount )
        vkCmdDrawIndexedIndirectCount = vkCmdDrawIndexedIndirectCountKHR;

      //=== VK_EXT_external_memory_host ===
      vkGetMemoryHostPointerPropertiesEXT = PFN_vkGetMemoryHostPointerPropertiesEXT( vkGetDeviceProcAddr( device, "vkGetMemoryHostPointerPropertiesEXT" ) );

      //=== VK_AMD_buffer_marker ===
      vkCmdWriteBufferMarkerAMD = PFN_vkCmdWriteBufferMarkerAMD( vkGetDeviceProcAddr( device, "vkCmdWriteBufferMarkerAMD" ) );

      //=== VK_EXT_calibrated_timestamps ===
      vkGetCalibratedTimestampsEXT = PFN_vkGetCalibratedTimestampsEXT( vkGetDeviceProcAddr( device, "vkGetCalibratedTimestampsEXT" ) );

      //=== VK_NV_mesh_shader ===
      vkCmdDrawMeshTasksNV              = PFN_vkCmdDrawMeshTasksNV( vkGetDeviceProcAddr( device, "vkCmdDrawMeshTasksNV" ) );
      vkCmdDrawMeshTasksIndirectNV      = PFN_vkCmdDrawMeshTasksIndirectNV( vkGetDeviceProcAddr( device, "vkCmdDrawMeshTasksIndirectNV" ) );
      vkCmdDrawMeshTasksIndirectCountNV = PFN_vkCmdDrawMeshTasksIndirectCountNV( vkGetDeviceProcAddr( device, "vkCmdDrawMeshTasksIndirectCountNV" ) );

      //=== VK_NV_scissor_exclusive ===
      vkCmdSetExclusiveScissorNV = PFN_vkCmdSetExclusiveScissorNV( vkGetDeviceProcAddr( device, "vkCmdSetExclusiveScissorNV" ) );

      //=== VK_NV_device_diagnostic_checkpoints ===
      vkCmdSetCheckpointNV       = PFN_vkCmdSetCheckpointNV( vkGetDeviceProcAddr( device, "vkCmdSetCheckpointNV" ) );
      vkGetQueueCheckpointDataNV = PFN_vkGetQueueCheckpointDataNV( vkGetDeviceProcAddr( device, "vkGetQueueCheckpointDataNV" ) );

      //=== VK_KHR_timeline_semaphore ===
      vkGetSemaphoreCounterValueKHR = PFN_vkGetSemaphoreCounterValueKHR( vkGetDeviceProcAddr( device, "vkGetSemaphoreCounterValueKHR" ) );
      if ( !vkGetSemaphoreCounterValue )
        vkGetSemaphoreCounterValue = vkGetSemaphoreCounterValueKHR;
      vkWaitSemaphoresKHR = PFN_vkWaitSemaphoresKHR( vkGetDeviceProcAddr( device, "vkWaitSemaphoresKHR" ) );
      if ( !vkWaitSemaphores )
        vkWaitSemaphores = vkWaitSemaphoresKHR;
      vkSignalSemaphoreKHR = PFN_vkSignalSemaphoreKHR( vkGetDeviceProcAddr( device, "vkSignalSemaphoreKHR" ) );
      if ( !vkSignalSemaphore )
        vkSignalSemaphore = vkSignalSemaphoreKHR;

      //=== VK_INTEL_performance_query ===
      vkInitializePerformanceApiINTEL      = PFN_vkInitializePerformanceApiINTEL( vkGetDeviceProcAddr( device, "vkInitializePerformanceApiINTEL" ) );
      vkUninitializePerformanceApiINTEL    = PFN_vkUninitializePerformanceApiINTEL( vkGetDeviceProcAddr( device, "vkUninitializePerformanceApiINTEL" ) );
      vkCmdSetPerformanceMarkerINTEL       = PFN_vkCmdSetPerformanceMarkerINTEL( vkGetDeviceProcAddr( device, "vkCmdSetPerformanceMarkerINTEL" ) );
      vkCmdSetPerformanceStreamMarkerINTEL = PFN_vkCmdSetPerformanceStreamMarkerINTEL( vkGetDeviceProcAddr( device, "vkCmdSetPerformanceStreamMarkerINTEL" ) );
      vkCmdSetPerformanceOverrideINTEL     = PFN_vkCmdSetPerformanceOverrideINTEL( vkGetDeviceProcAddr( device, "vkCmdSetPerformanceOverrideINTEL" ) );
      vkAcquirePerformanceConfigurationINTEL =
        PFN_vkAcquirePerformanceConfigurationINTEL( vkGetDeviceProcAddr( device, "vkAcquirePerformanceConfigurationINTEL" ) );
      vkReleasePerformanceConfigurationINTEL =
        PFN_vkReleasePerformanceConfigurationINTEL( vkGetDeviceProcAddr( device, "vkReleasePerformanceConfigurationINTEL" ) );
      vkQueueSetPerformanceConfigurationINTEL =
        PFN_vkQueueSetPerformanceConfigurationINTEL( vkGetDeviceProcAddr( device, "vkQueueSetPerformanceConfigurationINTEL" ) );
      vkGetPerformanceParameterINTEL = PFN_vkGetPerformanceParameterINTEL( vkGetDeviceProcAddr( device, "vkGetPerformanceParameterINTEL" ) );

      //=== VK_AMD_display_native_hdr ===
      vkSetLocalDimmingAMD = PFN_vkSetLocalDimmingAMD( vkGetDeviceProcAddr( device, "vkSetLocalDimmingAMD" ) );

      //=== VK_KHR_fragment_shading_rate ===
      vkCmdSetFragmentShadingRateKHR = PFN_vkCmdSetFragmentShadingRateKHR( vkGetDeviceProcAddr( device, "vkCmdSetFragmentShadingRateKHR" ) );

      //=== VK_EXT_buffer_device_address ===
      vkGetBufferDeviceAddressEXT = PFN_vkGetBufferDeviceAddressEXT( vkGetDeviceProcAddr( device, "vkGetBufferDeviceAddressEXT" ) );
      if ( !vkGetBufferDeviceAddress )
        vkGetBufferDeviceAddress = vkGetBufferDeviceAddressEXT;

      //=== VK_KHR_present_wait ===
      vkWaitForPresentKHR = PFN_vkWaitForPresentKHR( vkGetDeviceProcAddr( device, "vkWaitForPresentKHR" ) );

#if defined( VK_USE_PLATFORM_WIN32_KHR )
      //=== VK_EXT_full_screen_exclusive ===
      vkAcquireFullScreenExclusiveModeEXT = PFN_vkAcquireFullScreenExclusiveModeEXT( vkGetDeviceProcAddr( device, "vkAcquireFullScreenExclusiveModeEXT" ) );
      vkReleaseFullScreenExclusiveModeEXT = PFN_vkReleaseFullScreenExclusiveModeEXT( vkGetDeviceProcAddr( device, "vkReleaseFullScreenExclusiveModeEXT" ) );
      vkGetDeviceGroupSurfacePresentModes2EXT =
        PFN_vkGetDeviceGroupSurfacePresentModes2EXT( vkGetDeviceProcAddr( device, "vkGetDeviceGroupSurfacePresentModes2EXT" ) );
#endif /*VK_USE_PLATFORM_WIN32_KHR*/

       //=== VK_KHR_buffer_device_address ===
      vkGetBufferDeviceAddressKHR = PFN_vkGetBufferDeviceAddressKHR( vkGetDeviceProcAddr( device, "vkGetBufferDeviceAddressKHR" ) );
      if ( !vkGetBufferDeviceAddress )
        vkGetBufferDeviceAddress = vkGetBufferDeviceAddressKHR;
      vkGetBufferOpaqueCaptureAddressKHR = PFN_vkGetBufferOpaqueCaptureAddressKHR( vkGetDeviceProcAddr( device, "vkGetBufferOpaqueCaptureAddressKHR" ) );
      if ( !vkGetBufferOpaqueCaptureAddress )
        vkGetBufferOpaqueCaptureAddress = vkGetBufferOpaqueCaptureAddressKHR;
      vkGetDeviceMemoryOpaqueCaptureAddressKHR =
        PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR( vkGetDeviceProcAddr( device, "vkGetDeviceMemoryOpaqueCaptureAddressKHR" ) );
      if ( !vkGetDeviceMemoryOpaqueCaptureAddress )
        vkGetDeviceMemoryOpaqueCaptureAddress = vkGetDeviceMemoryOpaqueCaptureAddressKHR;

      //=== VK_EXT_line_rasterization ===
      vkCmdSetLineStippleEXT = PFN_vkCmdSetLineStippleEXT( vkGetDeviceProcAddr( device, "vkCmdSetLineStippleEXT" ) );

      //=== VK_EXT_host_query_reset ===
      vkResetQueryPoolEXT = PFN_vkResetQueryPoolEXT( vkGetDeviceProcAddr( device, "vkResetQueryPoolEXT" ) );
      if ( !vkResetQueryPool )
        vkResetQueryPool = vkResetQueryPoolEXT;

      //=== VK_EXT_extended_dynamic_state ===
      vkCmdSetCullModeEXT = PFN_vkCmdSetCullModeEXT( vkGetDeviceProcAddr( device, "vkCmdSetCullModeEXT" ) );
      if ( !vkCmdSetCullMode )
        vkCmdSetCullMode = vkCmdSetCullModeEXT;
      vkCmdSetFrontFaceEXT = PFN_vkCmdSetFrontFaceEXT( vkGetDeviceProcAddr( device, "vkCmdSetFrontFaceEXT" ) );
      if ( !vkCmdSetFrontFace )
        vkCmdSetFrontFace = vkCmdSetFrontFaceEXT;
      vkCmdSetPrimitiveTopologyEXT = PFN_vkCmdSetPrimitiveTopologyEXT( vkGetDeviceProcAddr( device, "vkCmdSetPrimitiveTopologyEXT" ) );
      if ( !vkCmdSetPrimitiveTopology )
        vkCmdSetPrimitiveTopology = vkCmdSetPrimitiveTopologyEXT;
      vkCmdSetViewportWithCountEXT = PFN_vkCmdSetViewportWithCountEXT( vkGetDeviceProcAddr( device, "vkCmdSetViewportWithCountEXT" ) );
      if ( !vkCmdSetViewportWithCount )
        vkCmdSetViewportWithCount = vkCmdSetViewportWithCountEXT;
      vkCmdSetScissorWithCountEXT = PFN_vkCmdSetScissorWithCountEXT( vkGetDeviceProcAddr( device, "vkCmdSetScissorWithCountEXT" ) );
      if ( !vkCmdSetScissorWithCount )
        vkCmdSetScissorWithCount = vkCmdSetScissorWithCountEXT;
      vkCmdBindVertexBuffers2EXT = PFN_vkCmdBindVertexBuffers2EXT( vkGetDeviceProcAddr( device, "vkCmdBindVertexBuffers2EXT" ) );
      if ( !vkCmdBindVertexBuffers2 )
        vkCmdBindVertexBuffers2 = vkCmdBindVertexBuffers2EXT;
      vkCmdSetDepthTestEnableEXT = PFN_vkCmdSetDepthTestEnableEXT( vkGetDeviceProcAddr( device, "vkCmdSetDepthTestEnableEXT" ) );
      if ( !vkCmdSetDepthTestEnable )
        vkCmdSetDepthTestEnable = vkCmdSetDepthTestEnableEXT;
      vkCmdSetDepthWriteEnableEXT = PFN_vkCmdSetDepthWriteEnableEXT( vkGetDeviceProcAddr( device, "vkCmdSetDepthWriteEnableEXT" ) );
      if ( !vkCmdSetDepthWriteEnable )
        vkCmdSetDepthWriteEnable = vkCmdSetDepthWriteEnableEXT;
      vkCmdSetDepthCompareOpEXT = PFN_vkCmdSetDepthCompareOpEXT( vkGetDeviceProcAddr( device, "vkCmdSetDepthCompareOpEXT" ) );
      if ( !vkCmdSetDepthCompareOp )
        vkCmdSetDepthCompareOp = vkCmdSetDepthCompareOpEXT;
      vkCmdSetDepthBoundsTestEnableEXT = PFN_vkCmdSetDepthBoundsTestEnableEXT( vkGetDeviceProcAddr( device, "vkCmdSetDepthBoundsTestEnableEXT" ) );
      if ( !vkCmdSetDepthBoundsTestEnable )
        vkCmdSetDepthBoundsTestEnable = vkCmdSetDepthBoundsTestEnableEXT;
      vkCmdSetStencilTestEnableEXT = PFN_vkCmdSetStencilTestEnableEXT( vkGetDeviceProcAddr( device, "vkCmdSetStencilTestEnableEXT" ) );
      if ( !vkCmdSetStencilTestEnable )
        vkCmdSetStencilTestEnable = vkCmdSetStencilTestEnableEXT;
      vkCmdSetStencilOpEXT = PFN_vkCmdSetStencilOpEXT( vkGetDeviceProcAddr( device, "vkCmdSetStencilOpEXT" ) );
      if ( !vkCmdSetStencilOp )
        vkCmdSetStencilOp = vkCmdSetStencilOpEXT;

      //=== VK_KHR_deferred_host_operations ===
      vkCreateDeferredOperationKHR  = PFN_vkCreateDeferredOperationKHR( vkGetDeviceProcAddr( device, "vkCreateDeferredOperationKHR" ) );
      vkDestroyDeferredOperationKHR = PFN_vkDestroyDeferredOperationKHR( vkGetDeviceProcAddr( device, "vkDestroyDeferredOperationKHR" ) );
      vkGetDeferredOperationMaxConcurrencyKHR =
        PFN_vkGetDeferredOperationMaxConcurrencyKHR( vkGetDeviceProcAddr( device, "vkGetDeferredOperationMaxConcurrencyKHR" ) );
      vkGetDeferredOperationResultKHR = PFN_vkGetDeferredOperationResultKHR( vkGetDeviceProcAddr( device, "vkGetDeferredOperationResultKHR" ) );
      vkDeferredOperationJoinKHR      = PFN_vkDeferredOperationJoinKHR( vkGetDeviceProcAddr( device, "vkDeferredOperationJoinKHR" ) );

      //=== VK_KHR_pipeline_executable_properties ===
      vkGetPipelineExecutablePropertiesKHR = PFN_vkGetPipelineExecutablePropertiesKHR( vkGetDeviceProcAddr( device, "vkGetPipelineExecutablePropertiesKHR" ) );
      vkGetPipelineExecutableStatisticsKHR = PFN_vkGetPipelineExecutableStatisticsKHR( vkGetDeviceProcAddr( device, "vkGetPipelineExecutableStatisticsKHR" ) );
      vkGetPipelineExecutableInternalRepresentationsKHR =
        PFN_vkGetPipelineExecutableInternalRepresentationsKHR( vkGetDeviceProcAddr( device, "vkGetPipelineExecutableInternalRepresentationsKHR" ) );

      //=== VK_EXT_swapchain_maintenance1 ===
      vkReleaseSwapchainImagesEXT = PFN_vkReleaseSwapchainImagesEXT( vkGetDeviceProcAddr( device, "vkReleaseSwapchainImagesEXT" ) );

      //=== VK_NV_device_generated_commands ===
      vkGetGeneratedCommandsMemoryRequirementsNV =
        PFN_vkGetGeneratedCommandsMemoryRequirementsNV( vkGetDeviceProcAddr( device, "vkGetGeneratedCommandsMemoryRequirementsNV" ) );
      vkCmdPreprocessGeneratedCommandsNV = PFN_vkCmdPreprocessGeneratedCommandsNV( vkGetDeviceProcAddr( device, "vkCmdPreprocessGeneratedCommandsNV" ) );
      vkCmdExecuteGeneratedCommandsNV    = PFN_vkCmdExecuteGeneratedCommandsNV( vkGetDeviceProcAddr( device, "vkCmdExecuteGeneratedCommandsNV" ) );
      vkCmdBindPipelineShaderGroupNV     = PFN_vkCmdBindPipelineShaderGroupNV( vkGetDeviceProcAddr( device, "vkCmdBindPipelineShaderGroupNV" ) );
      vkCreateIndirectCommandsLayoutNV   = PFN_vkCreateIndirectCommandsLayoutNV( vkGetDeviceProcAddr( device, "vkCreateIndirectCommandsLayoutNV" ) );
      vkDestroyIndirectCommandsLayoutNV  = PFN_vkDestroyIndirectCommandsLayoutNV( vkGetDeviceProcAddr( device, "vkDestroyIndirectCommandsLayoutNV" ) );

      //=== VK_EXT_private_data ===
      vkCreatePrivateDataSlotEXT = PFN_vkCreatePrivateDataSlotEXT( vkGetDeviceProcAddr( device, "vkCreatePrivateDataSlotEXT" ) );
      if ( !vkCreatePrivateDataSlot )
        vkCreatePrivateDataSlot = vkCreatePrivateDataSlotEXT;
      vkDestroyPrivateDataSlotEXT = PFN_vkDestroyPrivateDataSlotEXT( vkGetDeviceProcAddr( device, "vkDestroyPrivateDataSlotEXT" ) );
      if ( !vkDestroyPrivateDataSlot )
        vkDestroyPrivateDataSlot = vkDestroyPrivateDataSlotEXT;
      vkSetPrivateDataEXT = PFN_vkSetPrivateDataEXT( vkGetDeviceProcAddr( device, "vkSetPrivateDataEXT" ) );
      if ( !vkSetPrivateData )
        vkSetPrivateData = vkSetPrivateDataEXT;
      vkGetPrivateDataEXT = PFN_vkGetPrivateDataEXT( vkGetDeviceProcAddr( device, "vkGetPrivateDataEXT" ) );
      if ( !vkGetPrivateData )
        vkGetPrivateData = vkGetPrivateDataEXT;

#if defined( VK_ENABLE_BETA_EXTENSIONS )
      //=== VK_KHR_video_encode_queue ===
      vkCmdEncodeVideoKHR = PFN_vkCmdEncodeVideoKHR( vkGetDeviceProcAddr( device, "vkCmdEncodeVideoKHR" ) );
#endif /*VK_ENABLE_BETA_EXTENSIONS*/

#if defined( VK_USE_PLATFORM_METAL_EXT )
      //=== VK_EXT_metal_objects ===
      vkExportMetalObjectsEXT = PFN_vkExportMetalObjectsEXT( vkGetDeviceProcAddr( device, "vkExportMetalObjectsEXT" ) );
#endif /*VK_USE_PLATFORM_METAL_EXT*/

       //=== VK_KHR_synchronization2 ===
      vkCmdSetEvent2KHR = PFN_vkCmdSetEvent2KHR( vkGetDeviceProcAddr( device, "vkCmdSetEvent2KHR" ) );
      if ( !vkCmdSetEvent2 )
        vkCmdSetEvent2 = vkCmdSetEvent2KHR;
      vkCmdResetEvent2KHR = PFN_vkCmdResetEvent2KHR( vkGetDeviceProcAddr( device, "vkCmdResetEvent2KHR" ) );
      if ( !vkCmdResetEvent2 )
        vkCmdResetEvent2 = vkCmdResetEvent2KHR;
      vkCmdWaitEvents2KHR = PFN_vkCmdWaitEvents2KHR( vkGetDeviceProcAddr( device, "vkCmdWaitEvents2KHR" ) );
      if ( !vkCmdWaitEvents2 )
        vkCmdWaitEvents2 = vkCmdWaitEvents2KHR;
      vkCmdPipelineBarrier2KHR = PFN_vkCmdPipelineBarrier2KHR( vkGetDeviceProcAddr( device, "vkCmdPipelineBarrier2KHR" ) );
      if ( !vkCmdPipelineBarrier2 )
        vkCmdPipelineBarrier2 = vkCmdPipelineBarrier2KHR;
      vkCmdWriteTimestamp2KHR = PFN_vkCmdWriteTimestamp2KHR( vkGetDeviceProcAddr( device, "vkCmdWriteTimestamp2KHR" ) );
      if ( !vkCmdWriteTimestamp2 )
        vkCmdWriteTimestamp2 = vkCmdWriteTimestamp2KHR;
      vkQueueSubmit2KHR = PFN_vkQueueSubmit2KHR( vkGetDeviceProcAddr( device, "vkQueueSubmit2KHR" ) );
      if ( !vkQueueSubmit2 )
        vkQueueSubmit2 = vkQueueSubmit2KHR;
      vkCmdWriteBufferMarker2AMD  = PFN_vkCmdWriteBufferMarker2AMD( vkGetDeviceProcAddr( device, "vkCmdWriteBufferMarker2AMD" ) );
      vkGetQueueCheckpointData2NV = PFN_vkGetQueueCheckpointData2NV( vkGetDeviceProcAddr( device, "vkGetQueueCheckpointData2NV" ) );

      //=== VK_EXT_descriptor_buffer ===
      vkGetDescriptorSetLayoutSizeEXT = PFN_vkGetDescriptorSetLayoutSizeEXT( vkGetDeviceProcAddr( device, "vkGetDescriptorSetLayoutSizeEXT" ) );
      vkGetDescriptorSetLayoutBindingOffsetEXT =
        PFN_vkGetDescriptorSetLayoutBindingOffsetEXT( vkGetDeviceProcAddr( device, "vkGetDescriptorSetLayoutBindingOffsetEXT" ) );
      vkGetDescriptorEXT                 = PFN_vkGetDescriptorEXT( vkGetDeviceProcAddr( device, "vkGetDescriptorEXT" ) );
      vkCmdBindDescriptorBuffersEXT      = PFN_vkCmdBindDescriptorBuffersEXT( vkGetDeviceProcAddr( device, "vkCmdBindDescriptorBuffersEXT" ) );
      vkCmdSetDescriptorBufferOffsetsEXT = PFN_vkCmdSetDescriptorBufferOffsetsEXT( vkGetDeviceProcAddr( device, "vkCmdSetDescriptorBufferOffsetsEXT" ) );
      vkCmdBindDescriptorBufferEmbeddedSamplersEXT =
        PFN_vkCmdBindDescriptorBufferEmbeddedSamplersEXT( vkGetDeviceProcAddr( device, "vkCmdBindDescriptorBufferEmbeddedSamplersEXT" ) );
      vkGetBufferOpaqueCaptureDescriptorDataEXT =
        PFN_vkGetBufferOpaqueCaptureDescriptorDataEXT( vkGetDeviceProcAddr( device, "vkGetBufferOpaqueCaptureDescriptorDataEXT" ) );
      vkGetImageOpaqueCaptureDescriptorDataEXT =
        PFN_vkGetImageOpaqueCaptureDescriptorDataEXT( vkGetDeviceProcAddr( device, "vkGetImageOpaqueCaptureDescriptorDataEXT" ) );
      vkGetImageViewOpaqueCaptureDescriptorDataEXT =
        PFN_vkGetImageViewOpaqueCaptureDescriptorDataEXT( vkGetDeviceProcAddr( device, "vkGetImageViewOpaqueCaptureDescriptorDataEXT" ) );
      vkGetSamplerOpaqueCaptureDescriptorDataEXT =
        PFN_vkGetSamplerOpaqueCaptureDescriptorDataEXT( vkGetDeviceProcAddr( device, "vkGetSamplerOpaqueCaptureDescriptorDataEXT" ) );
      vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT = PFN_vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT(
        vkGetDeviceProcAddr( device, "vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT" ) );

      //=== VK_NV_fragment_shading_rate_enums ===
      vkCmdSetFragmentShadingRateEnumNV = PFN_vkCmdSetFragmentShadingRateEnumNV( vkGetDeviceProcAddr( device, "vkCmdSetFragmentShadingRateEnumNV" ) );

      //=== VK_EXT_mesh_shader ===
      vkCmdDrawMeshTasksEXT              = PFN_vkCmdDrawMeshTasksEXT( vkGetDeviceProcAddr( device, "vkCmdDrawMeshTasksEXT" ) );
      vkCmdDrawMeshTasksIndirectEXT      = PFN_vkCmdDrawMeshTasksIndirectEXT( vkGetDeviceProcAddr( device, "vkCmdDrawMeshTasksIndirectEXT" ) );
      vkCmdDrawMeshTasksIndirectCountEXT = PFN_vkCmdDrawMeshTasksIndirectCountEXT( vkGetDeviceProcAddr( device, "vkCmdDrawMeshTasksIndirectCountEXT" ) );

      //=== VK_KHR_copy_commands2 ===
      vkCmdCopyBuffer2KHR = PFN_vkCmdCopyBuffer2KHR( vkGetDeviceProcAddr( device, "vkCmdCopyBuffer2KHR" ) );
      if ( !vkCmdCopyBuffer2 )
        vkCmdCopyBuffer2 = vkCmdCopyBuffer2KHR;
      vkCmdCopyImage2KHR = PFN_vkCmdCopyImage2KHR( vkGetDeviceProcAddr( device, "vkCmdCopyImage2KHR" ) );
      if ( !vkCmdCopyImage2 )
        vkCmdCopyImage2 = vkCmdCopyImage2KHR;
      vkCmdCopyBufferToImage2KHR = PFN_vkCmdCopyBufferToImage2KHR( vkGetDeviceProcAddr( device, "vkCmdCopyBufferToImage2KHR" ) );
      if ( !vkCmdCopyBufferToImage2 )
        vkCmdCopyBufferToImage2 = vkCmdCopyBufferToImage2KHR;
      vkCmdCopyImageToBuffer2KHR = PFN_vkCmdCopyImageToBuffer2KHR( vkGetDeviceProcAddr( device, "vkCmdCopyImageToBuffer2KHR" ) );
      if ( !vkCmdCopyImageToBuffer2 )
        vkCmdCopyImageToBuffer2 = vkCmdCopyImageToBuffer2KHR;
      vkCmdBlitImage2KHR = PFN_vkCmdBlitImage2KHR( vkGetDeviceProcAddr( device, "vkCmdBlitImage2KHR" ) );
      if ( !vkCmdBlitImage2 )
        vkCmdBlitImage2 = vkCmdBlitImage2KHR;
      vkCmdResolveImage2KHR = PFN_vkCmdResolveImage2KHR( vkGetDeviceProcAddr( device, "vkCmdResolveImage2KHR" ) );
      if ( !vkCmdResolveImage2 )
        vkCmdResolveImage2 = vkCmdResolveImage2KHR;

      //=== VK_EXT_image_compression_control ===
      vkGetImageSubresourceLayout2EXT = PFN_vkGetImageSubresourceLayout2EXT( vkGetDeviceProcAddr( device, "vkGetImageSubresourceLayout2EXT" ) );

      //=== VK_EXT_device_fault ===
      vkGetDeviceFaultInfoEXT = PFN_vkGetDeviceFaultInfoEXT( vkGetDeviceProcAddr( device, "vkGetDeviceFaultInfoEXT" ) );

      //=== VK_KHR_ray_tracing_pipeline ===
      vkCmdTraceRaysKHR                    = PFN_vkCmdTraceRaysKHR( vkGetDeviceProcAddr( device, "vkCmdTraceRaysKHR" ) );
      vkCreateRayTracingPipelinesKHR       = PFN_vkCreateRayTracingPipelinesKHR( vkGetDeviceProcAddr( device, "vkCreateRayTracingPipelinesKHR" ) );
      vkGetRayTracingShaderGroupHandlesKHR = PFN_vkGetRayTracingShaderGroupHandlesKHR( vkGetDeviceProcAddr( device, "vkGetRayTracingShaderGroupHandlesKHR" ) );
      vkGetRayTracingCaptureReplayShaderGroupHandlesKHR =
        PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR( vkGetDeviceProcAddr( device, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR" ) );
      vkCmdTraceRaysIndirectKHR = PFN_vkCmdTraceRaysIndirectKHR( vkGetDeviceProcAddr( device, "vkCmdTraceRaysIndirectKHR" ) );
      vkGetRayTracingShaderGroupStackSizeKHR =
        PFN_vkGetRayTracingShaderGroupStackSizeKHR( vkGetDeviceProcAddr( device, "vkGetRayTracingShaderGroupStackSizeKHR" ) );
      vkCmdSetRayTracingPipelineStackSizeKHR =
        PFN_vkCmdSetRayTracingPipelineStackSizeKHR( vkGetDeviceProcAddr( device, "vkCmdSetRayTracingPipelineStackSizeKHR" ) );

      //=== VK_EXT_vertex_input_dynamic_state ===
      vkCmdSetVertexInputEXT = PFN_vkCmdSetVertexInputEXT( vkGetDeviceProcAddr( device, "vkCmdSetVertexInputEXT" ) );

#if defined( VK_USE_PLATFORM_FUCHSIA )
      //=== VK_FUCHSIA_external_memory ===
      vkGetMemoryZirconHandleFUCHSIA = PFN_vkGetMemoryZirconHandleFUCHSIA( vkGetDeviceProcAddr( device, "vkGetMemoryZirconHandleFUCHSIA" ) );
      vkGetMemoryZirconHandlePropertiesFUCHSIA =
        PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA( vkGetDeviceProcAddr( device, "vkGetMemoryZirconHandlePropertiesFUCHSIA" ) );
#endif /*VK_USE_PLATFORM_FUCHSIA*/

#if defined( VK_USE_PLATFORM_FUCHSIA )
      //=== VK_FUCHSIA_external_semaphore ===
      vkImportSemaphoreZirconHandleFUCHSIA = PFN_vkImportSemaphoreZirconHandleFUCHSIA( vkGetDeviceProcAddr( device, "vkImportSemaphoreZirconHandleFUCHSIA" ) );
      vkGetSemaphoreZirconHandleFUCHSIA    = PFN_vkGetSemaphoreZirconHandleFUCHSIA( vkGetDeviceProcAddr( device, "vkGetSemaphoreZirconHandleFUCHSIA" ) );
#endif /*VK_USE_PLATFORM_FUCHSIA*/

#if defined( VK_USE_PLATFORM_FUCHSIA )
      //=== VK_FUCHSIA_buffer_collection ===
      vkCreateBufferCollectionFUCHSIA = PFN_vkCreateBufferCollectionFUCHSIA( vkGetDeviceProcAddr( device, "vkCreateBufferCollectionFUCHSIA" ) );
      vkSetBufferCollectionImageConstraintsFUCHSIA =
        PFN_vkSetBufferCollectionImageConstraintsFUCHSIA( vkGetDeviceProcAddr( device, "vkSetBufferCollectionImageConstraintsFUCHSIA" ) );
      vkSetBufferCollectionBufferConstraintsFUCHSIA =
        PFN_vkSetBufferCollectionBufferConstraintsFUCHSIA( vkGetDeviceProcAddr( device, "vkSetBufferCollectionBufferConstraintsFUCHSIA" ) );
      vkDestroyBufferCollectionFUCHSIA = PFN_vkDestroyBufferCollectionFUCHSIA( vkGetDeviceProcAddr( device, "vkDestroyBufferCollectionFUCHSIA" ) );
      vkGetBufferCollectionPropertiesFUCHSIA =
        PFN_vkGetBufferCollectionPropertiesFUCHSIA( vkGetDeviceProcAddr( device, "vkGetBufferCollectionPropertiesFUCHSIA" ) );
#endif /*VK_USE_PLATFORM_FUCHSIA*/

       //=== VK_HUAWEI_subpass_shading ===
      vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI =
        PFN_vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI( vkGetDeviceProcAddr( device, "vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI" ) );
      vkCmdSubpassShadingHUAWEI = PFN_vkCmdSubpassShadingHUAWEI( vkGetDeviceProcAddr( device, "vkCmdSubpassShadingHUAWEI" ) );

      //=== VK_HUAWEI_invocation_mask ===
      vkCmdBindInvocationMaskHUAWEI = PFN_vkCmdBindInvocationMaskHUAWEI( vkGetDeviceProcAddr( device, "vkCmdBindInvocationMaskHUAWEI" ) );

      //=== VK_NV_external_memory_rdma ===
      vkGetMemoryRemoteAddressNV = PFN_vkGetMemoryRemoteAddressNV( vkGetDeviceProcAddr( device, "vkGetMemoryRemoteAddressNV" ) );

      //=== VK_EXT_pipeline_properties ===
      vkGetPipelinePropertiesEXT = PFN_vkGetPipelinePropertiesEXT( vkGetDeviceProcAddr( device, "vkGetPipelinePropertiesEXT" ) );

      //=== VK_EXT_extended_dynamic_state2 ===
      vkCmdSetPatchControlPointsEXT      = PFN_vkCmdSetPatchControlPointsEXT( vkGetDeviceProcAddr( device, "vkCmdSetPatchControlPointsEXT" ) );
      vkCmdSetRasterizerDiscardEnableEXT = PFN_vkCmdSetRasterizerDiscardEnableEXT( vkGetDeviceProcAddr( device, "vkCmdSetRasterizerDiscardEnableEXT" ) );
      if ( !vkCmdSetRasterizerDiscardEnable )
        vkCmdSetRasterizerDiscardEnable = vkCmdSetRasterizerDiscardEnableEXT;
      vkCmdSetDepthBiasEnableEXT = PFN_vkCmdSetDepthBiasEnableEXT( vkGetDeviceProcAddr( device, "vkCmdSetDepthBiasEnableEXT" ) );
      if ( !vkCmdSetDepthBiasEnable )
        vkCmdSetDepthBiasEnable = vkCmdSetDepthBiasEnableEXT;
      vkCmdSetLogicOpEXT                = PFN_vkCmdSetLogicOpEXT( vkGetDeviceProcAddr( device, "vkCmdSetLogicOpEXT" ) );
      vkCmdSetPrimitiveRestartEnableEXT = PFN_vkCmdSetPrimitiveRestartEnableEXT( vkGetDeviceProcAddr( device, "vkCmdSetPrimitiveRestartEnableEXT" ) );
      if ( !vkCmdSetPrimitiveRestartEnable )
        vkCmdSetPrimitiveRestartEnable = vkCmdSetPrimitiveRestartEnableEXT;

      //=== VK_EXT_color_write_enable ===
      vkCmdSetColorWriteEnableEXT = PFN_vkCmdSetColorWriteEnableEXT( vkGetDeviceProcAddr( device, "vkCmdSetColorWriteEnableEXT" ) );

      //=== VK_KHR_ray_tracing_maintenance1 ===
      vkCmdTraceRaysIndirect2KHR = PFN_vkCmdTraceRaysIndirect2KHR( vkGetDeviceProcAddr( device, "vkCmdTraceRaysIndirect2KHR" ) );

      //=== VK_EXT_multi_draw ===
      vkCmdDrawMultiEXT        = PFN_vkCmdDrawMultiEXT( vkGetDeviceProcAddr( device, "vkCmdDrawMultiEXT" ) );
      vkCmdDrawMultiIndexedEXT = PFN_vkCmdDrawMultiIndexedEXT( vkGetDeviceProcAddr( device, "vkCmdDrawMultiIndexedEXT" ) );

      //=== VK_EXT_opacity_micromap ===
      vkCreateMicromapEXT                 = PFN_vkCreateMicromapEXT( vkGetDeviceProcAddr( device, "vkCreateMicromapEXT" ) );
      vkDestroyMicromapEXT                = PFN_vkDestroyMicromapEXT( vkGetDeviceProcAddr( device, "vkDestroyMicromapEXT" ) );
      vkCmdBuildMicromapsEXT              = PFN_vkCmdBuildMicromapsEXT( vkGetDeviceProcAddr( device, "vkCmdBuildMicromapsEXT" ) );
      vkBuildMicromapsEXT                 = PFN_vkBuildMicromapsEXT( vkGetDeviceProcAddr( device, "vkBuildMicromapsEXT" ) );
      vkCopyMicromapEXT                   = PFN_vkCopyMicromapEXT( vkGetDeviceProcAddr( device, "vkCopyMicromapEXT" ) );
      vkCopyMicromapToMemoryEXT           = PFN_vkCopyMicromapToMemoryEXT( vkGetDeviceProcAddr( device, "vkCopyMicromapToMemoryEXT" ) );
      vkCopyMemoryToMicromapEXT           = PFN_vkCopyMemoryToMicromapEXT( vkGetDeviceProcAddr( device, "vkCopyMemoryToMicromapEXT" ) );
      vkWriteMicromapsPropertiesEXT       = PFN_vkWriteMicromapsPropertiesEXT( vkGetDeviceProcAddr( device, "vkWriteMicromapsPropertiesEXT" ) );
      vkCmdCopyMicromapEXT                = PFN_vkCmdCopyMicromapEXT( vkGetDeviceProcAddr( device, "vkCmdCopyMicromapEXT" ) );
      vkCmdCopyMicromapToMemoryEXT        = PFN_vkCmdCopyMicromapToMemoryEXT( vkGetDeviceProcAddr( device, "vkCmdCopyMicromapToMemoryEXT" ) );
      vkCmdCopyMemoryToMicromapEXT        = PFN_vkCmdCopyMemoryToMicromapEXT( vkGetDeviceProcAddr( device, "vkCmdCopyMemoryToMicromapEXT" ) );
      vkCmdWriteMicromapsPropertiesEXT    = PFN_vkCmdWriteMicromapsPropertiesEXT( vkGetDeviceProcAddr( device, "vkCmdWriteMicromapsPropertiesEXT" ) );
      vkGetDeviceMicromapCompatibilityEXT = PFN_vkGetDeviceMicromapCompatibilityEXT( vkGetDeviceProcAddr( device, "vkGetDeviceMicromapCompatibilityEXT" ) );
      vkGetMicromapBuildSizesEXT          = PFN_vkGetMicromapBuildSizesEXT( vkGetDeviceProcAddr( device, "vkGetMicromapBuildSizesEXT" ) );

      //=== VK_HUAWEI_cluster_culling_shader ===
      vkCmdDrawClusterHUAWEI         = PFN_vkCmdDrawClusterHUAWEI( vkGetDeviceProcAddr( device, "vkCmdDrawClusterHUAWEI" ) );
      vkCmdDrawClusterIndirectHUAWEI = PFN_vkCmdDrawClusterIndirectHUAWEI( vkGetDeviceProcAddr( device, "vkCmdDrawClusterIndirectHUAWEI" ) );

      //=== VK_EXT_pageable_device_local_memory ===
      vkSetDeviceMemoryPriorityEXT = PFN_vkSetDeviceMemoryPriorityEXT( vkGetDeviceProcAddr( device, "vkSetDeviceMemoryPriorityEXT" ) );

      //=== VK_KHR_maintenance4 ===
      vkGetDeviceBufferMemoryRequirementsKHR =
        PFN_vkGetDeviceBufferMemoryRequirementsKHR( vkGetDeviceProcAddr( device, "vkGetDeviceBufferMemoryRequirementsKHR" ) );
      if ( !vkGetDeviceBufferMemoryRequirements )
        vkGetDeviceBufferMemoryRequirements = vkGetDeviceBufferMemoryRequirementsKHR;
      vkGetDeviceImageMemoryRequirementsKHR =
        PFN_vkGetDeviceImageMemoryRequirementsKHR( vkGetDeviceProcAddr( device, "vkGetDeviceImageMemoryRequirementsKHR" ) );
      if ( !vkGetDeviceImageMemoryRequirements )
        vkGetDeviceImageMemoryRequirements = vkGetDeviceImageMemoryRequirementsKHR;
      vkGetDeviceImageSparseMemoryRequirementsKHR =
        PFN_vkGetDeviceImageSparseMemoryRequirementsKHR( vkGetDeviceProcAddr( device, "vkGetDeviceImageSparseMemoryRequirementsKHR" ) );
      if ( !vkGetDeviceImageSparseMemoryRequirements )
        vkGetDeviceImageSparseMemoryRequirements = vkGetDeviceImageSparseMemoryRequirementsKHR;

      //=== VK_VALVE_descriptor_set_host_mapping ===
      vkGetDescriptorSetLayoutHostMappingInfoVALVE =
        PFN_vkGetDescriptorSetLayoutHostMappingInfoVALVE( vkGetDeviceProcAddr( device, "vkGetDescriptorSetLayoutHostMappingInfoVALVE" ) );
      vkGetDescriptorSetHostMappingVALVE = PFN_vkGetDescriptorSetHostMappingVALVE( vkGetDeviceProcAddr( device, "vkGetDescriptorSetHostMappingVALVE" ) );

      //=== VK_NV_copy_memory_indirect ===
      vkCmdCopyMemoryIndirectNV        = PFN_vkCmdCopyMemoryIndirectNV( vkGetDeviceProcAddr( device, "vkCmdCopyMemoryIndirectNV" ) );
      vkCmdCopyMemoryToImageIndirectNV = PFN_vkCmdCopyMemoryToImageIndirectNV( vkGetDeviceProcAddr( device, "vkCmdCopyMemoryToImageIndirectNV" ) );

      //=== VK_NV_memory_decompression ===
      vkCmdDecompressMemoryNV              = PFN_vkCmdDecompressMemoryNV( vkGetDeviceProcAddr( device, "vkCmdDecompressMemoryNV" ) );
      vkCmdDecompressMemoryIndirectCountNV = PFN_vkCmdDecompressMemoryIndirectCountNV( vkGetDeviceProcAddr( device, "vkCmdDecompressMemoryIndirectCountNV" ) );

      //=== VK_EXT_extended_dynamic_state3 ===
      vkCmdSetTessellationDomainOriginEXT = PFN_vkCmdSetTessellationDomainOriginEXT( vkGetDeviceProcAddr( device, "vkCmdSetTessellationDomainOriginEXT" ) );
      vkCmdSetDepthClampEnableEXT         = PFN_vkCmdSetDepthClampEnableEXT( vkGetDeviceProcAddr( device, "vkCmdSetDepthClampEnableEXT" ) );
      vkCmdSetPolygonModeEXT              = PFN_vkCmdSetPolygonModeEXT( vkGetDeviceProcAddr( device, "vkCmdSetPolygonModeEXT" ) );
      vkCmdSetRasterizationSamplesEXT     = PFN_vkCmdSetRasterizationSamplesEXT( vkGetDeviceProcAddr( device, "vkCmdSetRasterizationSamplesEXT" ) );
      vkCmdSetSampleMaskEXT               = PFN_vkCmdSetSampleMaskEXT( vkGetDeviceProcAddr( device, "vkCmdSetSampleMaskEXT" ) );
      vkCmdSetAlphaToCoverageEnableEXT    = PFN_vkCmdSetAlphaToCoverageEnableEXT( vkGetDeviceProcAddr( device, "vkCmdSetAlphaToCoverageEnableEXT" ) );
      vkCmdSetAlphaToOneEnableEXT         = PFN_vkCmdSetAlphaToOneEnableEXT( vkGetDeviceProcAddr( device, "vkCmdSetAlphaToOneEnableEXT" ) );
      vkCmdSetLogicOpEnableEXT            = PFN_vkCmdSetLogicOpEnableEXT( vkGetDeviceProcAddr( device, "vkCmdSetLogicOpEnableEXT" ) );
      vkCmdSetColorBlendEnableEXT         = PFN_vkCmdSetColorBlendEnableEXT( vkGetDeviceProcAddr( device, "vkCmdSetColorBlendEnableEXT" ) );
      vkCmdSetColorBlendEquationEXT       = PFN_vkCmdSetColorBlendEquationEXT( vkGetDeviceProcAddr( device, "vkCmdSetColorBlendEquationEXT" ) );
      vkCmdSetColorWriteMaskEXT           = PFN_vkCmdSetColorWriteMaskEXT( vkGetDeviceProcAddr( device, "vkCmdSetColorWriteMaskEXT" ) );
      vkCmdSetRasterizationStreamEXT      = PFN_vkCmdSetRasterizationStreamEXT( vkGetDeviceProcAddr( device, "vkCmdSetRasterizationStreamEXT" ) );
      vkCmdSetConservativeRasterizationModeEXT =
        PFN_vkCmdSetConservativeRasterizationModeEXT( vkGetDeviceProcAddr( device, "vkCmdSetConservativeRasterizationModeEXT" ) );
      vkCmdSetExtraPrimitiveOverestimationSizeEXT =
        PFN_vkCmdSetExtraPrimitiveOverestimationSizeEXT( vkGetDeviceProcAddr( device, "vkCmdSetExtraPrimitiveOverestimationSizeEXT" ) );
      vkCmdSetDepthClipEnableEXT           = PFN_vkCmdSetDepthClipEnableEXT( vkGetDeviceProcAddr( device, "vkCmdSetDepthClipEnableEXT" ) );
      vkCmdSetSampleLocationsEnableEXT     = PFN_vkCmdSetSampleLocationsEnableEXT( vkGetDeviceProcAddr( device, "vkCmdSetSampleLocationsEnableEXT" ) );
      vkCmdSetColorBlendAdvancedEXT        = PFN_vkCmdSetColorBlendAdvancedEXT( vkGetDeviceProcAddr( device, "vkCmdSetColorBlendAdvancedEXT" ) );
      vkCmdSetProvokingVertexModeEXT       = PFN_vkCmdSetProvokingVertexModeEXT( vkGetDeviceProcAddr( device, "vkCmdSetProvokingVertexModeEXT" ) );
      vkCmdSetLineRasterizationModeEXT     = PFN_vkCmdSetLineRasterizationModeEXT( vkGetDeviceProcAddr( device, "vkCmdSetLineRasterizationModeEXT" ) );
      vkCmdSetLineStippleEnableEXT         = PFN_vkCmdSetLineStippleEnableEXT( vkGetDeviceProcAddr( device, "vkCmdSetLineStippleEnableEXT" ) );
      vkCmdSetDepthClipNegativeOneToOneEXT = PFN_vkCmdSetDepthClipNegativeOneToOneEXT( vkGetDeviceProcAddr( device, "vkCmdSetDepthClipNegativeOneToOneEXT" ) );
      vkCmdSetViewportWScalingEnableNV     = PFN_vkCmdSetViewportWScalingEnableNV( vkGetDeviceProcAddr( device, "vkCmdSetViewportWScalingEnableNV" ) );
      vkCmdSetViewportSwizzleNV            = PFN_vkCmdSetViewportSwizzleNV( vkGetDeviceProcAddr( device, "vkCmdSetViewportSwizzleNV" ) );
      vkCmdSetCoverageToColorEnableNV      = PFN_vkCmdSetCoverageToColorEnableNV( vkGetDeviceProcAddr( device, "vkCmdSetCoverageToColorEnableNV" ) );
      vkCmdSetCoverageToColorLocationNV    = PFN_vkCmdSetCoverageToColorLocationNV( vkGetDeviceProcAddr( device, "vkCmdSetCoverageToColorLocationNV" ) );
      vkCmdSetCoverageModulationModeNV     = PFN_vkCmdSetCoverageModulationModeNV( vkGetDeviceProcAddr( device, "vkCmdSetCoverageModulationModeNV" ) );
      vkCmdSetCoverageModulationTableEnableNV =
        PFN_vkCmdSetCoverageModulationTableEnableNV( vkGetDeviceProcAddr( device, "vkCmdSetCoverageModulationTableEnableNV" ) );
      vkCmdSetCoverageModulationTableNV = PFN_vkCmdSetCoverageModulationTableNV( vkGetDeviceProcAddr( device, "vkCmdSetCoverageModulationTableNV" ) );
      vkCmdSetShadingRateImageEnableNV  = PFN_vkCmdSetShadingRateImageEnableNV( vkGetDeviceProcAddr( device, "vkCmdSetShadingRateImageEnableNV" ) );
      vkCmdSetRepresentativeFragmentTestEnableNV =
        PFN_vkCmdSetRepresentativeFragmentTestEnableNV( vkGetDeviceProcAddr( device, "vkCmdSetRepresentativeFragmentTestEnableNV" ) );
      vkCmdSetCoverageReductionModeNV = PFN_vkCmdSetCoverageReductionModeNV( vkGetDeviceProcAddr( device, "vkCmdSetCoverageReductionModeNV" ) );

      //=== VK_EXT_shader_module_identifier ===
      vkGetShaderModuleIdentifierEXT = PFN_vkGetShaderModuleIdentifierEXT( vkGetDeviceProcAddr( device, "vkGetShaderModuleIdentifierEXT" ) );
      vkGetShaderModuleCreateInfoIdentifierEXT =
        PFN_vkGetShaderModuleCreateInfoIdentifierEXT( vkGetDeviceProcAddr( device, "vkGetShaderModuleCreateInfoIdentifierEXT" ) );

      //=== VK_NV_optical_flow ===
      vkCreateOpticalFlowSessionNV    = PFN_vkCreateOpticalFlowSessionNV( vkGetDeviceProcAddr( device, "vkCreateOpticalFlowSessionNV" ) );
      vkDestroyOpticalFlowSessionNV   = PFN_vkDestroyOpticalFlowSessionNV( vkGetDeviceProcAddr( device, "vkDestroyOpticalFlowSessionNV" ) );
      vkBindOpticalFlowSessionImageNV = PFN_vkBindOpticalFlowSessionImageNV( vkGetDeviceProcAddr( device, "vkBindOpticalFlowSessionImageNV" ) );
      vkCmdOpticalFlowExecuteNV       = PFN_vkCmdOpticalFlowExecuteNV( vkGetDeviceProcAddr( device, "vkCmdOpticalFlowExecuteNV" ) );

      //=== VK_QCOM_tile_properties ===
      vkGetFramebufferTilePropertiesQCOM = PFN_vkGetFramebufferTilePropertiesQCOM( vkGetDeviceProcAddr( device, "vkGetFramebufferTilePropertiesQCOM" ) );
      vkGetDynamicRenderingTilePropertiesQCOM =
        PFN_vkGetDynamicRenderingTilePropertiesQCOM( vkGetDeviceProcAddr( device, "vkGetDynamicRenderingTilePropertiesQCOM" ) );
    }

    template <typename DynamicLoader>
    void init( VkInstance const & instance, VkDevice const & device, DynamicLoader const & dl ) VULKAN_HPP_NOEXCEPT
    {
      PFN_vkGetInstanceProcAddr getInstanceProcAddr = dl.template getProcAddress<PFN_vkGetInstanceProcAddr>( "vkGetInstanceProcAddr" );
      PFN_vkGetDeviceProcAddr   getDeviceProcAddr   = dl.template getProcAddress<PFN_vkGetDeviceProcAddr>( "vkGetDeviceProcAddr" );
      init( static_cast<VkInstance>( instance ), getInstanceProcAddr, static_cast<VkDevice>( device ), device ? getDeviceProcAddr : nullptr );
    }

    template <typename DynamicLoader
#if VULKAN_HPP_ENABLE_DYNAMIC_LOADER_TOOL
              = VULKAN_HPP_NAMESPACE::DynamicLoader
#endif
              >
    void init( VkInstance const & instance, VkDevice const & device ) VULKAN_HPP_NOEXCEPT
    {
      static DynamicLoader dl;
      init( instance, device, dl );
    }
  };
}  // namespace VULKAN_HPP_NAMESPACE

#  if VULKAN_HPP_DISPATCH_LOADER_DYNAMIC == 1
export namespace VULKAN_HPP_NAMESPACE
{
    VULKAN_HPP_STORAGE_API DispatchLoaderDynamic defaultDispatchLoaderDynamic;
}
#  else
export namespace VULKAN_HPP_NAMESPACE {
inline DispatchLoaderStatic & getDispatchLoaderStatic()
{
static ::VULKAN_HPP_NAMESPACE::DispatchLoaderStatic dls;
return dls;
}
#  endif


export namespace VULKAN_HPP_NAMESPACE
{
  template <typename T, size_t N>
  class ArrayWrapper1D : public std::array<T, N>
  {
  public:
    VULKAN_HPP_CONSTEXPR ArrayWrapper1D() VULKAN_HPP_NOEXCEPT : std::array<T, N>() {}

    VULKAN_HPP_CONSTEXPR ArrayWrapper1D( std::array<T, N> const & data ) VULKAN_HPP_NOEXCEPT : std::array<T, N>( data ) {}

#if ( VK_USE_64_BIT_PTR_DEFINES == 0 )
    // on 32 bit compiles, needs overloads on index type int to resolve ambiguities
    VULKAN_HPP_CONSTEXPR T const & operator[]( int index ) const VULKAN_HPP_NOEXCEPT
    {
      return std::array<T, N>::operator[]( index );
    }

    T & operator[]( int index ) VULKAN_HPP_NOEXCEPT
    {
      return std::array<T, N>::operator[]( index );
    }
#endif

    operator T const *() const VULKAN_HPP_NOEXCEPT
    {
      return this->data();
    }

    operator T *() VULKAN_HPP_NOEXCEPT
    {
      return this->data();
    }

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    operator std::string() const
    {
      return std::string( this->data() );
    }

#if 17 <= VULKAN_HPP_CPP_VERSION
    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    operator std::string_view() const
    {
      return std::string_view( this->data() );
    }
#endif

#if defined( VULKAN_HPP_HAS_SPACESHIP_OPERATOR )
    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    std::strong_ordering operator<=>( ArrayWrapper1D<char, N> const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return *static_cast<std::array<char, N> const *>( this ) <=> *static_cast<std::array<char, N> const *>( &rhs );
    }
#else
    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    bool operator<( ArrayWrapper1D<char, N> const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return *static_cast<std::array<char, N> const *>( this ) < *static_cast<std::array<char, N> const *>( &rhs );
    }

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    bool operator<=( ArrayWrapper1D<char, N> const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return *static_cast<std::array<char, N> const *>( this ) <= *static_cast<std::array<char, N> const *>( &rhs );
    }

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    bool operator>( ArrayWrapper1D<char, N> const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return *static_cast<std::array<char, N> const *>( this ) > *static_cast<std::array<char, N> const *>( &rhs );
    }

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    bool operator>=( ArrayWrapper1D<char, N> const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return *static_cast<std::array<char, N> const *>( this ) >= *static_cast<std::array<char, N> const *>( &rhs );
    }
#endif

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    bool operator==( ArrayWrapper1D<char, N> const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return *static_cast<std::array<char, N> const *>( this ) == *static_cast<std::array<char, N> const *>( &rhs );
    }

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    bool operator!=( ArrayWrapper1D<char, N> const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return *static_cast<std::array<char, N> const *>( this ) != *static_cast<std::array<char, N> const *>( &rhs );
    }
  };

  // specialization of relational operators between std::string and arrays of chars
  template <size_t N>
  bool operator<( std::string const & lhs, ArrayWrapper1D<char, N> const & rhs ) VULKAN_HPP_NOEXCEPT
  {
    return lhs < rhs.data();
  }

  template <size_t N>
  bool operator<=( std::string const & lhs, ArrayWrapper1D<char, N> const & rhs ) VULKAN_HPP_NOEXCEPT
  {
    return lhs <= rhs.data();
  }

  template <size_t N>
  bool operator>( std::string const & lhs, ArrayWrapper1D<char, N> const & rhs ) VULKAN_HPP_NOEXCEPT
  {
    return lhs > rhs.data();
  }

  template <size_t N>
  bool operator>=( std::string const & lhs, ArrayWrapper1D<char, N> const & rhs ) VULKAN_HPP_NOEXCEPT
  {
    return lhs >= rhs.data();
  }

  template <size_t N>
  bool operator==( std::string const & lhs, ArrayWrapper1D<char, N> const & rhs ) VULKAN_HPP_NOEXCEPT
  {
    return lhs == rhs.data();
  }

  template <size_t N>
  bool operator!=( std::string const & lhs, ArrayWrapper1D<char, N> const & rhs ) VULKAN_HPP_NOEXCEPT
  {
    return lhs != rhs.data();
  }

  template <typename T, size_t N, size_t M>
  class ArrayWrapper2D : public std::array<ArrayWrapper1D<T, M>, N>
  {
  public:
    VULKAN_HPP_CONSTEXPR ArrayWrapper2D() VULKAN_HPP_NOEXCEPT : std::array<ArrayWrapper1D<T, M>, N>() {}

    VULKAN_HPP_CONSTEXPR ArrayWrapper2D( std::array<std::array<T, M>, N> const & data ) VULKAN_HPP_NOEXCEPT
      : std::array<ArrayWrapper1D<T, M>, N>( *reinterpret_cast<std::array<ArrayWrapper1D<T, M>, N> const *>( &data ) )
    {
    }
  };

  template <typename FlagBitsType>
  struct FlagTraits
  {
    static VULKAN_HPP_CONST_OR_CONSTEXPR bool isBitmask = false;
  };

  template <typename BitType>
  class Flags
  {
  public:
    using MaskType = typename std::underlying_type<BitType>::type;

    // constructors
    VULKAN_HPP_CONSTEXPR Flags() VULKAN_HPP_NOEXCEPT : m_mask( 0 ) {}

    VULKAN_HPP_CONSTEXPR Flags( BitType bit ) VULKAN_HPP_NOEXCEPT : m_mask( static_cast<MaskType>( bit ) ) {}

    VULKAN_HPP_CONSTEXPR Flags( Flags<BitType> const & rhs ) VULKAN_HPP_NOEXCEPT = default;

    VULKAN_HPP_CONSTEXPR explicit Flags( MaskType flags ) VULKAN_HPP_NOEXCEPT : m_mask( flags ) {}

    // relational operators
#if defined( VULKAN_HPP_HAS_SPACESHIP_OPERATOR )
    auto operator<=>( Flags<BitType> const & ) const = default;
#else
    VULKAN_HPP_CONSTEXPR bool operator<( Flags<BitType> const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return m_mask < rhs.m_mask;
    }

    VULKAN_HPP_CONSTEXPR bool operator<=( Flags<BitType> const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return m_mask <= rhs.m_mask;
    }

    VULKAN_HPP_CONSTEXPR bool operator>( Flags<BitType> const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return m_mask > rhs.m_mask;
    }

    VULKAN_HPP_CONSTEXPR bool operator>=( Flags<BitType> const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return m_mask >= rhs.m_mask;
    }

    VULKAN_HPP_CONSTEXPR bool operator==( Flags<BitType> const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return m_mask == rhs.m_mask;
    }

    VULKAN_HPP_CONSTEXPR bool operator!=( Flags<BitType> const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return m_mask != rhs.m_mask;
    }
#endif

    // logical operator
    VULKAN_HPP_CONSTEXPR bool operator!() const VULKAN_HPP_NOEXCEPT
    {
      return !m_mask;
    }

    // bitwise operators
    VULKAN_HPP_CONSTEXPR Flags<BitType> operator&( Flags<BitType> const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return Flags<BitType>( m_mask & rhs.m_mask );
    }

    VULKAN_HPP_CONSTEXPR Flags<BitType> operator|( Flags<BitType> const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return Flags<BitType>( m_mask | rhs.m_mask );
    }

    VULKAN_HPP_CONSTEXPR Flags<BitType> operator^( Flags<BitType> const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return Flags<BitType>( m_mask ^ rhs.m_mask );
    }

    VULKAN_HPP_CONSTEXPR Flags<BitType> operator~() const VULKAN_HPP_NOEXCEPT
    {
      return Flags<BitType>( m_mask ^ FlagTraits<BitType>::allFlags.m_mask );
    }

    // assignment operators
    VULKAN_HPP_CONSTEXPR_14 Flags<BitType> & operator=( Flags<BitType> const & rhs ) VULKAN_HPP_NOEXCEPT = default;

    VULKAN_HPP_CONSTEXPR_14 Flags<BitType> & operator|=( Flags<BitType> const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      m_mask |= rhs.m_mask;
      return *this;
    }

    VULKAN_HPP_CONSTEXPR_14 Flags<BitType> & operator&=( Flags<BitType> const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      m_mask &= rhs.m_mask;
      return *this;
    }

    VULKAN_HPP_CONSTEXPR_14 Flags<BitType> & operator^=( Flags<BitType> const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      m_mask ^= rhs.m_mask;
      return *this;
    }

    // cast operators
    explicit VULKAN_HPP_CONSTEXPR operator bool() const VULKAN_HPP_NOEXCEPT
    {
      return !!m_mask;
    }

    explicit VULKAN_HPP_CONSTEXPR operator MaskType() const VULKAN_HPP_NOEXCEPT
    {
      return m_mask;
    }

#if defined( VULKAN_HPP_FLAGS_MASK_TYPE_AS_PUBLIC )
  public:
#else
  private:
#endif
    MaskType m_mask;
  };

#if !defined( VULKAN_HPP_HAS_SPACESHIP_OPERATOR )
  // relational operators only needed for pre C++20
  template <typename BitType>
  VULKAN_HPP_CONSTEXPR bool operator<( BitType bit, Flags<BitType> const & flags ) VULKAN_HPP_NOEXCEPT
  {
    return flags.operator>( bit );
  }

  template <typename BitType>
  VULKAN_HPP_CONSTEXPR bool operator<=( BitType bit, Flags<BitType> const & flags ) VULKAN_HPP_NOEXCEPT
  {
    return flags.operator>=( bit );
  }

  template <typename BitType>
  VULKAN_HPP_CONSTEXPR bool operator>( BitType bit, Flags<BitType> const & flags ) VULKAN_HPP_NOEXCEPT
  {
    return flags.operator<( bit );
  }

  template <typename BitType>
  VULKAN_HPP_CONSTEXPR bool operator>=( BitType bit, Flags<BitType> const & flags ) VULKAN_HPP_NOEXCEPT
  {
    return flags.operator<=( bit );
  }

  template <typename BitType>
  VULKAN_HPP_CONSTEXPR bool operator==( BitType bit, Flags<BitType> const & flags ) VULKAN_HPP_NOEXCEPT
  {
    return flags.operator==( bit );
  }

  template <typename BitType>
  VULKAN_HPP_CONSTEXPR bool operator!=( BitType bit, Flags<BitType> const & flags ) VULKAN_HPP_NOEXCEPT
  {
    return flags.operator!=( bit );
  }
#endif

  // bitwise operators
  template <typename BitType>
  VULKAN_HPP_CONSTEXPR Flags<BitType> operator&( BitType bit, Flags<BitType> const & flags ) VULKAN_HPP_NOEXCEPT
  {
    return flags.operator&( bit );
  }

  template <typename BitType>
  VULKAN_HPP_CONSTEXPR Flags<BitType> operator|( BitType bit, Flags<BitType> const & flags ) VULKAN_HPP_NOEXCEPT
  {
    return flags.operator|( bit );
  }

  template <typename BitType>
  VULKAN_HPP_CONSTEXPR Flags<BitType> operator^( BitType bit, Flags<BitType> const & flags ) VULKAN_HPP_NOEXCEPT
  {
    return flags.operator^( bit );
  }

  // bitwise operators on BitType
  template <typename BitType, typename std::enable_if<FlagTraits<BitType>::isBitmask, bool>::type = true>
  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR Flags<BitType> operator&( BitType lhs, BitType rhs ) VULKAN_HPP_NOEXCEPT
  {
    return Flags<BitType>( lhs ) & rhs;
  }

  template <typename BitType, typename std::enable_if<FlagTraits<BitType>::isBitmask, bool>::type = true>
  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR Flags<BitType> operator|( BitType lhs, BitType rhs ) VULKAN_HPP_NOEXCEPT
  {
    return Flags<BitType>( lhs ) | rhs;
  }

  template <typename BitType, typename std::enable_if<FlagTraits<BitType>::isBitmask, bool>::type = true>
  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR Flags<BitType> operator^( BitType lhs, BitType rhs ) VULKAN_HPP_NOEXCEPT
  {
    return Flags<BitType>( lhs ) ^ rhs;
  }

  template <typename BitType, typename std::enable_if<FlagTraits<BitType>::isBitmask, bool>::type = true>
  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR Flags<BitType> operator~( BitType bit ) VULKAN_HPP_NOEXCEPT
  {
    return ~( Flags<BitType>( bit ) );
  }

#if !defined( VULKAN_HPP_DISABLE_ENHANCED_MODE )
  template <typename T>
  class ArrayProxy
  {
  public:
    VULKAN_HPP_CONSTEXPR ArrayProxy() VULKAN_HPP_NOEXCEPT
      : m_count( 0 )
      , m_ptr( nullptr )
    {
    }

    VULKAN_HPP_CONSTEXPR ArrayProxy( std::nullptr_t ) VULKAN_HPP_NOEXCEPT
      : m_count( 0 )
      , m_ptr( nullptr )
    {
    }

    ArrayProxy( T const & value ) VULKAN_HPP_NOEXCEPT
      : m_count( 1 )
      , m_ptr( &value )
    {
    }

    ArrayProxy( uint32_t count, T const * ptr ) VULKAN_HPP_NOEXCEPT
      : m_count( count )
      , m_ptr( ptr )
    {
    }

    template <std::size_t C>
    ArrayProxy( T const ( &ptr )[C] ) VULKAN_HPP_NOEXCEPT
      : m_count( C )
      , m_ptr( ptr )
    {
    }

#  if __GNUC__ >= 9
#    pragma GCC diagnostic push
#    pragma GCC diagnostic ignored "-Winit-list-lifetime"
#  endif

    ArrayProxy( std::initializer_list<T> const & list ) VULKAN_HPP_NOEXCEPT
      : m_count( static_cast<uint32_t>( list.size() ) )
      , m_ptr( list.begin() )
    {
    }

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxy( std::initializer_list<typename std::remove_const<T>::type> const & list ) VULKAN_HPP_NOEXCEPT
      : m_count( static_cast<uint32_t>( list.size() ) )
      , m_ptr( list.begin() )
    {
    }

#  if __GNUC__ >= 9
#    pragma GCC diagnostic pop
#  endif

    // Any type with a .data() return type implicitly convertible to T*, and a .size() return type implicitly
    // convertible to size_t. The const version can capture temporaries, with lifetime ending at end of statement.
    template <typename V,
              typename std::enable_if<std::is_convertible<decltype( std::declval<V>().data() ), T *>::value &&
                                      std::is_convertible<decltype( std::declval<V>().size() ), std::size_t>::value>::type * = nullptr>
    ArrayProxy( V const & v ) VULKAN_HPP_NOEXCEPT
      : m_count( static_cast<uint32_t>( v.size() ) )
      , m_ptr( v.data() )
    {
    }

    const T * begin() const VULKAN_HPP_NOEXCEPT
    {
      return m_ptr;
    }

    const T * end() const VULKAN_HPP_NOEXCEPT
    {
      return m_ptr + m_count;
    }

    const T & front() const VULKAN_HPP_NOEXCEPT
    {
      VULKAN_HPP_ASSERT( m_count && m_ptr );
      return *m_ptr;
    }

    const T & back() const VULKAN_HPP_NOEXCEPT
    {
      VULKAN_HPP_ASSERT( m_count && m_ptr );
      return *( m_ptr + m_count - 1 );
    }

    bool empty() const VULKAN_HPP_NOEXCEPT
    {
      return ( m_count == 0 );
    }

    uint32_t size() const VULKAN_HPP_NOEXCEPT
    {
      return m_count;
    }

    T const * data() const VULKAN_HPP_NOEXCEPT
    {
      return m_ptr;
    }

  private:
    uint32_t  m_count;
    T const * m_ptr;
  };

  template <typename T>
  class ArrayProxyNoTemporaries
  {
  public:
    VULKAN_HPP_CONSTEXPR ArrayProxyNoTemporaries() VULKAN_HPP_NOEXCEPT
      : m_count( 0 )
      , m_ptr( nullptr )
    {
    }

    VULKAN_HPP_CONSTEXPR ArrayProxyNoTemporaries( std::nullptr_t ) VULKAN_HPP_NOEXCEPT
      : m_count( 0 )
      , m_ptr( nullptr )
    {
    }

    ArrayProxyNoTemporaries( T & value ) VULKAN_HPP_NOEXCEPT
      : m_count( 1 )
      , m_ptr( &value )
    {
    }

    template <typename V>
    ArrayProxyNoTemporaries( V && value ) = delete;

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries( typename std::remove_const<T>::type & value ) VULKAN_HPP_NOEXCEPT
      : m_count( 1 )
      , m_ptr( &value )
    {
    }

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries( typename std::remove_const<T>::type && value ) = delete;

    ArrayProxyNoTemporaries( uint32_t count, T * ptr ) VULKAN_HPP_NOEXCEPT
      : m_count( count )
      , m_ptr( ptr )
    {
    }

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries( uint32_t count, typename std::remove_const<T>::type * ptr ) VULKAN_HPP_NOEXCEPT
      : m_count( count )
      , m_ptr( ptr )
    {
    }

    template <std::size_t C>
    ArrayProxyNoTemporaries( T ( &ptr )[C] ) VULKAN_HPP_NOEXCEPT
      : m_count( C )
      , m_ptr( ptr )
    {
    }

    template <std::size_t C>
    ArrayProxyNoTemporaries( T ( &&ptr )[C] ) = delete;

    template <std::size_t C, typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries( typename std::remove_const<T>::type ( &ptr )[C] ) VULKAN_HPP_NOEXCEPT
      : m_count( C )
      , m_ptr( ptr )
    {
    }

    template <std::size_t C, typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries( typename std::remove_const<T>::type ( &&ptr )[C] ) = delete;

    ArrayProxyNoTemporaries( std::initializer_list<T> const & list ) VULKAN_HPP_NOEXCEPT
      : m_count( static_cast<uint32_t>( list.size() ) )
      , m_ptr( list.begin() )
    {
    }

    ArrayProxyNoTemporaries( std::initializer_list<T> const && list ) = delete;

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries( std::initializer_list<typename std::remove_const<T>::type> const & list ) VULKAN_HPP_NOEXCEPT
      : m_count( static_cast<uint32_t>( list.size() ) )
      , m_ptr( list.begin() )
    {
    }

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries( std::initializer_list<typename std::remove_const<T>::type> const && list ) = delete;

    ArrayProxyNoTemporaries( std::initializer_list<T> & list ) VULKAN_HPP_NOEXCEPT
      : m_count( static_cast<uint32_t>( list.size() ) )
      , m_ptr( list.begin() )
    {
    }

    ArrayProxyNoTemporaries( std::initializer_list<T> && list ) = delete;

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries( std::initializer_list<typename std::remove_const<T>::type> & list ) VULKAN_HPP_NOEXCEPT
      : m_count( static_cast<uint32_t>( list.size() ) )
      , m_ptr( list.begin() )
    {
    }

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries( std::initializer_list<typename std::remove_const<T>::type> && list ) = delete;

    // Any type with a .data() return type implicitly convertible to T*, and a .size() return type implicitly convertible to size_t.
    template <typename V,
              typename std::enable_if<std::is_convertible<decltype( std::declval<V>().data() ), T *>::value &&
                                      std::is_convertible<decltype( std::declval<V>().size() ), std::size_t>::value>::type * = nullptr>
    ArrayProxyNoTemporaries( V & v ) VULKAN_HPP_NOEXCEPT
      : m_count( static_cast<uint32_t>( v.size() ) )
      , m_ptr( v.data() )
    {
    }

    const T * begin() const VULKAN_HPP_NOEXCEPT
    {
      return m_ptr;
    }

    const T * end() const VULKAN_HPP_NOEXCEPT
    {
      return m_ptr + m_count;
    }

    const T & front() const VULKAN_HPP_NOEXCEPT
    {
      VULKAN_HPP_ASSERT( m_count && m_ptr );
      return *m_ptr;
    }

    const T & back() const VULKAN_HPP_NOEXCEPT
    {
      VULKAN_HPP_ASSERT( m_count && m_ptr );
      return *( m_ptr + m_count - 1 );
    }

    bool empty() const VULKAN_HPP_NOEXCEPT
    {
      return ( m_count == 0 );
    }

    uint32_t size() const VULKAN_HPP_NOEXCEPT
    {
      return m_count;
    }

    T * data() const VULKAN_HPP_NOEXCEPT
    {
      return m_ptr;
    }

  private:
    uint32_t m_count;
    T *      m_ptr;
  };

  template <typename T>
  class StridedArrayProxy : protected ArrayProxy<T>
  {
  public:
    using ArrayProxy<T>::ArrayProxy;

    StridedArrayProxy( uint32_t count, T const * ptr, uint32_t stride ) VULKAN_HPP_NOEXCEPT
      : ArrayProxy<T>( count, ptr )
      , m_stride( stride )
    {
      VULKAN_HPP_ASSERT( sizeof( T ) <= stride );
    }

    using ArrayProxy<T>::begin;

    const T * end() const VULKAN_HPP_NOEXCEPT
    {
      return reinterpret_cast<T const *>( static_cast<uint8_t const *>( begin() ) + size() * m_stride );
    }

    using ArrayProxy<T>::front;

    const T & back() const VULKAN_HPP_NOEXCEPT
    {
      VULKAN_HPP_ASSERT( begin() && size() );
      return *reinterpret_cast<T const *>( static_cast<uint8_t const *>( begin() ) + ( size() - 1 ) * m_stride );
    }

    using ArrayProxy<T>::empty;
    using ArrayProxy<T>::size;
    using ArrayProxy<T>::data;

    uint32_t stride() const
    {
      return m_stride;
    }

  private:
    uint32_t m_stride = sizeof( T );
  };

  template <typename RefType>
  class Optional
  {
  public:
    Optional( RefType & reference ) VULKAN_HPP_NOEXCEPT
    {
      m_ptr = &reference;
    }

    Optional( RefType * ptr ) VULKAN_HPP_NOEXCEPT
    {
      m_ptr = ptr;
    }

    Optional( std::nullptr_t ) VULKAN_HPP_NOEXCEPT
    {
      m_ptr = nullptr;
    }

    operator RefType *() const VULKAN_HPP_NOEXCEPT
    {
      return m_ptr;
    }

    RefType const * operator->() const VULKAN_HPP_NOEXCEPT
    {
      return m_ptr;
    }

    explicit operator bool() const VULKAN_HPP_NOEXCEPT
    {
      return !!m_ptr;
    }

  private:
    RefType * m_ptr;
  };

  template <typename X, typename Y>
  struct StructExtends
  {
    enum
    {
      value = false
    };
  };

  template <typename Type, class...>
  struct IsPartOfStructureChain
  {
    static const bool valid = false;
  };

  template <typename Type, typename Head, typename... Tail>
  struct IsPartOfStructureChain<Type, Head, Tail...>
  {
    static const bool valid = std::is_same<Type, Head>::value || IsPartOfStructureChain<Type, Tail...>::valid;
  };

  template <size_t Index, typename T, typename... ChainElements>
  struct StructureChainContains
  {
    static const bool value = std::is_same<T, typename std::tuple_element<Index, std::tuple<ChainElements...>>::type>::value ||
                              StructureChainContains<Index - 1, T, ChainElements...>::value;
  };

  template <typename T, typename... ChainElements>
  struct StructureChainContains<0, T, ChainElements...>
  {
    static const bool value = std::is_same<T, typename std::tuple_element<0, std::tuple<ChainElements...>>::type>::value;
  };

  template <size_t Index, typename... ChainElements>
  struct StructureChainValidation
  {
    using TestType          = typename std::tuple_element<Index, std::tuple<ChainElements...>>::type;
    static const bool valid = StructExtends<TestType, typename std::tuple_element<0, std::tuple<ChainElements...>>::type>::value &&
                              ( TestType::allowDuplicate || !StructureChainContains<Index - 1, TestType, ChainElements...>::value ) &&
                              StructureChainValidation<Index - 1, ChainElements...>::valid;
  };

  template <typename... ChainElements>
  struct StructureChainValidation<0, ChainElements...>
  {
    static const bool valid = true;
  };

  template <typename... ChainElements>
  class StructureChain : public std::tuple<ChainElements...>
  {
  public:
    StructureChain() VULKAN_HPP_NOEXCEPT
    {
      static_assert( StructureChainValidation<sizeof...( ChainElements ) - 1, ChainElements...>::valid, "The structure chain is not valid!" );
      link<sizeof...( ChainElements ) - 1>();
    }

    StructureChain( StructureChain const & rhs ) VULKAN_HPP_NOEXCEPT : std::tuple<ChainElements...>( rhs )
    {
      static_assert( StructureChainValidation<sizeof...( ChainElements ) - 1, ChainElements...>::valid, "The structure chain is not valid!" );
      link( &std::get<0>( *this ),
            &std::get<0>( rhs ),
            reinterpret_cast<VkBaseOutStructure *>( &std::get<0>( *this ) ),
            reinterpret_cast<VkBaseInStructure const *>( &std::get<0>( rhs ) ) );
    }

    StructureChain( StructureChain && rhs ) VULKAN_HPP_NOEXCEPT : std::tuple<ChainElements...>( std::forward<std::tuple<ChainElements...>>( rhs ) )
    {
      static_assert( StructureChainValidation<sizeof...( ChainElements ) - 1, ChainElements...>::valid, "The structure chain is not valid!" );
      link( &std::get<0>( *this ),
            &std::get<0>( rhs ),
            reinterpret_cast<VkBaseOutStructure *>( &std::get<0>( *this ) ),
            reinterpret_cast<VkBaseInStructure const *>( &std::get<0>( rhs ) ) );
    }

    StructureChain( ChainElements const &... elems ) VULKAN_HPP_NOEXCEPT : std::tuple<ChainElements...>( elems... )
    {
      static_assert( StructureChainValidation<sizeof...( ChainElements ) - 1, ChainElements...>::valid, "The structure chain is not valid!" );
      link<sizeof...( ChainElements ) - 1>();
    }

    StructureChain & operator=( StructureChain const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      std::tuple<ChainElements...>::operator=( rhs );
      link( &std::get<0>( *this ),
            &std::get<0>( rhs ),
            reinterpret_cast<VkBaseOutStructure *>( &std::get<0>( *this ) ),
            reinterpret_cast<VkBaseInStructure const *>( &std::get<0>( rhs ) ) );
      return *this;
    }

    StructureChain & operator=( StructureChain && rhs ) = delete;

    template <typename T = typename std::tuple_element<0, std::tuple<ChainElements...>>::type, size_t Which = 0>
    T & get() VULKAN_HPP_NOEXCEPT
    {
      return std::get<ChainElementIndex<0, T, Which, void, ChainElements...>::value>( static_cast<std::tuple<ChainElements...> &>( *this ) );
    }

    template <typename T = typename std::tuple_element<0, std::tuple<ChainElements...>>::type, size_t Which = 0>
    T const & get() const VULKAN_HPP_NOEXCEPT
    {
      return std::get<ChainElementIndex<0, T, Which, void, ChainElements...>::value>( static_cast<std::tuple<ChainElements...> const &>( *this ) );
    }

    template <typename T0, typename T1, typename... Ts>
    std::tuple<T0 &, T1 &, Ts &...> get() VULKAN_HPP_NOEXCEPT
    {
      return std::tie( get<T0>(), get<T1>(), get<Ts>()... );
    }

    template <typename T0, typename T1, typename... Ts>
    std::tuple<T0 const &, T1 const &, Ts const &...> get() const VULKAN_HPP_NOEXCEPT
    {
      return std::tie( get<T0>(), get<T1>(), get<Ts>()... );
    }

    template <typename ClassType, size_t Which = 0>
    typename std::enable_if<std::is_same<ClassType, typename std::tuple_element<0, std::tuple<ChainElements...>>::type>::value && ( Which == 0 ), bool>::type
      isLinked() const VULKAN_HPP_NOEXCEPT
    {
      return true;
    }

    template <typename ClassType, size_t Which = 0>
    typename std::enable_if<!std::is_same<ClassType, typename std::tuple_element<0, std::tuple<ChainElements...>>::type>::value || ( Which != 0 ), bool>::type
      isLinked() const VULKAN_HPP_NOEXCEPT
    {
      static_assert( IsPartOfStructureChain<ClassType, ChainElements...>::valid, "Can't unlink Structure that's not part of this StructureChain!" );
      return isLinked( reinterpret_cast<VkBaseInStructure const *>( &get<ClassType, Which>() ) );
    }

    template <typename ClassType, size_t Which = 0>
    typename std::enable_if<!std::is_same<ClassType, typename std::tuple_element<0, std::tuple<ChainElements...>>::type>::value || ( Which != 0 ), void>::type
      relink() VULKAN_HPP_NOEXCEPT
    {
      static_assert( IsPartOfStructureChain<ClassType, ChainElements...>::valid, "Can't relink Structure that's not part of this StructureChain!" );
      auto pNext = reinterpret_cast<VkBaseInStructure *>( &get<ClassType, Which>() );
      VULKAN_HPP_ASSERT( !isLinked( pNext ) );
      auto & headElement = std::get<0>( static_cast<std::tuple<ChainElements...> &>( *this ) );
      pNext->pNext       = reinterpret_cast<VkBaseInStructure const *>( headElement.pNext );
      headElement.pNext  = pNext;
    }

    template <typename ClassType, size_t Which = 0>
    typename std::enable_if<!std::is_same<ClassType, typename std::tuple_element<0, std::tuple<ChainElements...>>::type>::value || ( Which != 0 ), void>::type
      unlink() VULKAN_HPP_NOEXCEPT
    {
      static_assert( IsPartOfStructureChain<ClassType, ChainElements...>::valid, "Can't unlink Structure that's not part of this StructureChain!" );
      unlink( reinterpret_cast<VkBaseOutStructure const *>( &get<ClassType, Which>() ) );
    }

  private:
    template <int Index, typename T, int Which, typename, class First, class... Types>
    struct ChainElementIndex : ChainElementIndex<Index + 1, T, Which, void, Types...>
    {
    };

    template <int Index, typename T, int Which, class First, class... Types>
    struct ChainElementIndex<Index, T, Which, typename std::enable_if<!std::is_same<T, First>::value, void>::type, First, Types...>
      : ChainElementIndex<Index + 1, T, Which, void, Types...>
    {
    };

    template <int Index, typename T, int Which, class First, class... Types>
    struct ChainElementIndex<Index, T, Which, typename std::enable_if<std::is_same<T, First>::value, void>::type, First, Types...>
      : ChainElementIndex<Index + 1, T, Which - 1, void, Types...>
    {
    };

    template <int Index, typename T, class First, class... Types>
    struct ChainElementIndex<Index, T, 0, typename std::enable_if<std::is_same<T, First>::value, void>::type, First, Types...>
      : std::integral_constant<int, Index>
    {
    };

    bool isLinked( VkBaseInStructure const * pNext ) const VULKAN_HPP_NOEXCEPT
    {
      VkBaseInStructure const * elementPtr =
        reinterpret_cast<VkBaseInStructure const *>( &std::get<0>( static_cast<std::tuple<ChainElements...> const &>( *this ) ) );
      while ( elementPtr )
      {
        if ( elementPtr->pNext == pNext )
        {
          return true;
        }
        elementPtr = elementPtr->pNext;
      }
      return false;
    }

    template <size_t Index>
    typename std::enable_if<Index != 0, void>::type link() VULKAN_HPP_NOEXCEPT
    {
      auto & x = std::get<Index - 1>( static_cast<std::tuple<ChainElements...> &>( *this ) );
      x.pNext  = &std::get<Index>( static_cast<std::tuple<ChainElements...> &>( *this ) );
      link<Index - 1>();
    }

    template <size_t Index>
    typename std::enable_if<Index == 0, void>::type link() VULKAN_HPP_NOEXCEPT
    {
    }

    void link( void * dstBase, void const * srcBase, VkBaseOutStructure * dst, VkBaseInStructure const * src )
    {
      while ( src->pNext )
      {
        std::ptrdiff_t offset = reinterpret_cast<char const *>( src->pNext ) - reinterpret_cast<char const *>( srcBase );
        dst->pNext            = reinterpret_cast<VkBaseOutStructure *>( reinterpret_cast<char *>( dstBase ) + offset );
        dst                   = dst->pNext;
        src                   = src->pNext;
      }
      dst->pNext = nullptr;
    }

    void unlink( VkBaseOutStructure const * pNext ) VULKAN_HPP_NOEXCEPT
    {
      VkBaseOutStructure * elementPtr = reinterpret_cast<VkBaseOutStructure *>( &std::get<0>( static_cast<std::tuple<ChainElements...> &>( *this ) ) );
      while ( elementPtr && ( elementPtr->pNext != pNext ) )
      {
        elementPtr = elementPtr->pNext;
      }
      if ( elementPtr )
      {
        elementPtr->pNext = pNext->pNext;
      }
      else
      {
        VULKAN_HPP_ASSERT( false );  // fires, if the ClassType member has already been unlinked !
      }
    }
  };

#  if !defined( VULKAN_HPP_NO_SMART_HANDLE )
  template <typename Type, typename Dispatch>
  class UniqueHandleTraits;

  template <typename Type, typename Dispatch>
  class UniqueHandle : public UniqueHandleTraits<Type, Dispatch>::deleter
  {
  private:
    using Deleter = typename UniqueHandleTraits<Type, Dispatch>::deleter;

  public:
    using element_type = Type;

    UniqueHandle() : Deleter(), m_value() {}

    explicit UniqueHandle( Type const & value, Deleter const & deleter = Deleter() ) VULKAN_HPP_NOEXCEPT
      : Deleter( deleter )
      , m_value( value )
    {
    }

    UniqueHandle( UniqueHandle const & ) = delete;

    UniqueHandle( UniqueHandle && other ) VULKAN_HPP_NOEXCEPT
      : Deleter( std::move( static_cast<Deleter &>( other ) ) )
      , m_value( other.release() )
    {
    }

    ~UniqueHandle() VULKAN_HPP_NOEXCEPT
    {
      if ( m_value )
      {
        this->destroy( m_value );
      }
    }

    UniqueHandle & operator=( UniqueHandle const & ) = delete;

    UniqueHandle & operator=( UniqueHandle && other ) VULKAN_HPP_NOEXCEPT
    {
      reset( other.release() );
      *static_cast<Deleter *>( this ) = std::move( static_cast<Deleter &>( other ) );
      return *this;
    }

    explicit operator bool() const VULKAN_HPP_NOEXCEPT
    {
      return m_value.operator bool();
    }

    Type const * operator->() const VULKAN_HPP_NOEXCEPT
    {
      return &m_value;
    }

    Type * operator->() VULKAN_HPP_NOEXCEPT
    {
      return &m_value;
    }

    Type const & operator*() const VULKAN_HPP_NOEXCEPT
    {
      return m_value;
    }

    Type & operator*() VULKAN_HPP_NOEXCEPT
    {
      return m_value;
    }

    const Type & get() const VULKAN_HPP_NOEXCEPT
    {
      return m_value;
    }

    Type & get() VULKAN_HPP_NOEXCEPT
    {
      return m_value;
    }

    void reset( Type const & value = Type() ) VULKAN_HPP_NOEXCEPT
    {
      if ( m_value != value )
      {
        if ( m_value )
        {
          this->destroy( m_value );
        }
        m_value = value;
      }
    }

    Type release() VULKAN_HPP_NOEXCEPT
    {
      Type value = m_value;
      m_value    = nullptr;
      return value;
    }

    void swap( UniqueHandle<Type, Dispatch> & rhs ) VULKAN_HPP_NOEXCEPT
    {
      std::swap( m_value, rhs.m_value );
      std::swap( static_cast<Deleter &>( *this ), static_cast<Deleter &>( rhs ) );
    }

  private:
    Type m_value;
  };

  template <typename UniqueType>
  VULKAN_HPP_INLINE std::vector<typename UniqueType::element_type> uniqueToRaw( std::vector<UniqueType> const & handles )
  {
    std::vector<typename UniqueType::element_type> newBuffer( handles.size() );
    std::transform( handles.begin(), handles.end(), newBuffer.begin(), []( UniqueType const & handle ) { return handle.get(); } );
    return newBuffer;
  }

  template <typename Type, typename Dispatch>
  VULKAN_HPP_INLINE void swap( UniqueHandle<Type, Dispatch> & lhs, UniqueHandle<Type, Dispatch> & rhs ) VULKAN_HPP_NOEXCEPT
  {
    lhs.swap( rhs );
  }
#  endif
#endif  // VULKAN_HPP_DISABLE_ENHANCED_MODE

#if !defined( VULKAN_HPP_NO_SMART_HANDLE )
  struct AllocationCallbacks;

  template <typename OwnerType, typename Dispatch>
  class ObjectDestroy
  {
  public:
    ObjectDestroy() = default;

    ObjectDestroy( OwnerType                                               owner,
                   Optional<const AllocationCallbacks> allocationCallbacks VULKAN_HPP_DEFAULT_ARGUMENT_NULLPTR_ASSIGNMENT,
                   Dispatch const & dispatch                               VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) VULKAN_HPP_NOEXCEPT
      : m_owner( owner )
      , m_allocationCallbacks( allocationCallbacks )
      , m_dispatch( &dispatch )
    {
    }

    OwnerType getOwner() const VULKAN_HPP_NOEXCEPT
    {
      return m_owner;
    }

    Optional<const AllocationCallbacks> getAllocator() const VULKAN_HPP_NOEXCEPT
    {
      return m_allocationCallbacks;
    }

  protected:
    template <typename T>
    void destroy( T t ) VULKAN_HPP_NOEXCEPT
    {
      VULKAN_HPP_ASSERT( m_owner && m_dispatch );
      m_owner.destroy( t, m_allocationCallbacks, *m_dispatch );
    }

  private:
    OwnerType                           m_owner               = {};
    Optional<const AllocationCallbacks> m_allocationCallbacks = nullptr;
    Dispatch const *                    m_dispatch            = nullptr;
  };

  class NoParent;

  template <typename Dispatch>
  class ObjectDestroy<NoParent, Dispatch>
  {
  public:
    ObjectDestroy() = default;

    ObjectDestroy( Optional<const AllocationCallbacks> allocationCallbacks,
                   Dispatch const & dispatch           VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) VULKAN_HPP_NOEXCEPT
      : m_allocationCallbacks( allocationCallbacks )
      , m_dispatch( &dispatch )
    {
    }

    Optional<const AllocationCallbacks> getAllocator() const VULKAN_HPP_NOEXCEPT
    {
      return m_allocationCallbacks;
    }

  protected:
    template <typename T>
    void destroy( T t ) VULKAN_HPP_NOEXCEPT
    {
      VULKAN_HPP_ASSERT( m_dispatch );
      t.destroy( m_allocationCallbacks, *m_dispatch );
    }

  private:
    Optional<const AllocationCallbacks> m_allocationCallbacks = nullptr;
    Dispatch const *                    m_dispatch            = nullptr;
  };

  template <typename OwnerType, typename Dispatch>
  class ObjectFree
  {
  public:
    ObjectFree() = default;

    ObjectFree( OwnerType                                               owner,
                Optional<const AllocationCallbacks> allocationCallbacks VULKAN_HPP_DEFAULT_ARGUMENT_NULLPTR_ASSIGNMENT,
                Dispatch const & dispatch                               VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) VULKAN_HPP_NOEXCEPT
      : m_owner( owner )
      , m_allocationCallbacks( allocationCallbacks )
      , m_dispatch( &dispatch )
    {
    }

    OwnerType getOwner() const VULKAN_HPP_NOEXCEPT
    {
      return m_owner;
    }

    Optional<const AllocationCallbacks> getAllocator() const VULKAN_HPP_NOEXCEPT
    {
      return m_allocationCallbacks;
    }

  protected:
    template <typename T>
    void destroy( T t ) VULKAN_HPP_NOEXCEPT
    {
      VULKAN_HPP_ASSERT( m_owner && m_dispatch );
      ( m_owner.free )( t, m_allocationCallbacks, *m_dispatch );
    }

  private:
    OwnerType                           m_owner               = {};
    Optional<const AllocationCallbacks> m_allocationCallbacks = nullptr;
    Dispatch const *                    m_dispatch            = nullptr;
  };

  template <typename OwnerType, typename Dispatch>
  class ObjectRelease
  {
  public:
    ObjectRelease() = default;

    ObjectRelease( OwnerType owner, Dispatch const & dispatch VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) VULKAN_HPP_NOEXCEPT
      : m_owner( owner )
      , m_dispatch( &dispatch )
    {
    }

    OwnerType getOwner() const VULKAN_HPP_NOEXCEPT
    {
      return m_owner;
    }

  protected:
    template <typename T>
    void destroy( T t ) VULKAN_HPP_NOEXCEPT
    {
      VULKAN_HPP_ASSERT( m_owner && m_dispatch );
      m_owner.release( t, *m_dispatch );
    }

  private:
    OwnerType        m_owner    = {};
    Dispatch const * m_dispatch = nullptr;
  };

  template <typename OwnerType, typename PoolType, typename Dispatch>
  class PoolFree
  {
  public:
    PoolFree() = default;

    PoolFree( OwnerType owner, PoolType pool, Dispatch const & dispatch VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) VULKAN_HPP_NOEXCEPT
      : m_owner( owner )
      , m_pool( pool )
      , m_dispatch( &dispatch )
    {
    }

    OwnerType getOwner() const VULKAN_HPP_NOEXCEPT
    {
      return m_owner;
    }

    PoolType getPool() const VULKAN_HPP_NOEXCEPT
    {
      return m_pool;
    }

  protected:
    template <typename T>
    void destroy( T t ) VULKAN_HPP_NOEXCEPT
    {
      ( m_owner.free )( m_pool, t, *m_dispatch );
    }

  private:
    OwnerType        m_owner    = OwnerType();
    PoolType         m_pool     = PoolType();
    Dispatch const * m_dispatch = nullptr;
  };

#endif  // !VULKAN_HPP_NO_SMART_HANDLE
}  // namespace VULKAN_HPP_NAMESPACE
