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

export module vulkan.format_traits;

import vulkan;

export namespace VULKAN_HPP_NAMESPACE
{

  //=====================
  //=== Format Traits ===
  //=====================

  // The three-dimensional extent of a texel block.
  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR_14 std::array<uint8_t, 3> blockExtent( VULKAN_HPP_NAMESPACE::Format format )
  {
    switch ( format )
    {
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbUnormBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbSrgbBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbaUnormBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbaSrgbBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eBc2UnormBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eBc2SrgbBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eBc3UnormBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eBc3SrgbBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eBc4UnormBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eBc4SnormBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eBc5UnormBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eBc5SnormBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eBc6HUfloatBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eBc6HSfloatBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eBc7UnormBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eBc7SrgbBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8UnormBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8SrgbBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A1UnormBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A1SrgbBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A8UnormBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A8SrgbBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eEacR11UnormBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eEacR11SnormBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eEacR11G11UnormBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eEacR11G11SnormBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4UnormBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4SrgbBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4UnormBlock: return { { 5, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4SrgbBlock: return { { 5, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5UnormBlock: return { { 5, 5, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5SrgbBlock: return { { 5, 5, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5UnormBlock: return { { 6, 5, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5SrgbBlock: return { { 6, 5, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6UnormBlock: return { { 6, 6, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6SrgbBlock: return { { 6, 6, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5UnormBlock: return { { 8, 5, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5SrgbBlock: return { { 8, 5, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6UnormBlock: return { { 8, 6, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6SrgbBlock: return { { 8, 6, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8UnormBlock: return { { 8, 8, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8SrgbBlock: return { { 8, 8, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5UnormBlock: return { { 10, 5, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5SrgbBlock: return { { 10, 5, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6UnormBlock: return { { 10, 6, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6SrgbBlock: return { { 10, 6, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8UnormBlock: return { { 10, 8, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8SrgbBlock: return { { 10, 8, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10UnormBlock: return { { 10, 10, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10SrgbBlock: return { { 10, 10, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10UnormBlock: return { { 12, 10, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10SrgbBlock: return { { 12, 10, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12UnormBlock: return { { 12, 12, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12SrgbBlock: return { { 12, 12, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eG8B8G8R8422Unorm: return { { 2, 1, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8G8422Unorm: return { { 2, 1, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6G10X6R10X6422Unorm4Pack16: return { { 2, 1, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eB10X6G10X6R10X6G10X6422Unorm4Pack16: return { { 2, 1, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4G12X4R12X4422Unorm4Pack16: return { { 2, 1, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eB12X4G12X4R12X4G12X4422Unorm4Pack16: return { { 2, 1, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eG16B16G16R16422Unorm: return { { 2, 1, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eB16G16R16G16422Unorm: return { { 2, 1, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4SfloatBlock: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4SfloatBlock: return { { 5, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5SfloatBlock: return { { 5, 5, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5SfloatBlock: return { { 6, 5, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6SfloatBlock: return { { 6, 6, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5SfloatBlock: return { { 8, 5, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6SfloatBlock: return { { 8, 6, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8SfloatBlock: return { { 8, 8, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5SfloatBlock: return { { 10, 5, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6SfloatBlock: return { { 10, 6, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8SfloatBlock: return { { 10, 8, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10SfloatBlock: return { { 10, 10, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10SfloatBlock: return { { 12, 10, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12SfloatBlock: return { { 12, 12, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc12BppUnormBlockIMG: return { { 8, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc14BppUnormBlockIMG: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc22BppUnormBlockIMG: return { { 8, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc24BppUnormBlockIMG: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc12BppSrgbBlockIMG: return { { 8, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc14BppSrgbBlockIMG: return { { 4, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc22BppSrgbBlockIMG: return { { 8, 4, 1 } };
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc24BppSrgbBlockIMG: return { { 4, 4, 1 } };

      default: return { { 1, 1, 1 } };
    }
  }

  // The texel block size in bytes.
  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR_14 uint8_t blockSize( VULKAN_HPP_NAMESPACE::Format format )
  {
    switch ( format )
    {
      case VULKAN_HPP_NAMESPACE::Format::eR4G4UnormPack8: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR4G4B4A4UnormPack16: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eB4G4R4A4UnormPack16: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR5G6B5UnormPack16: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eB5G6R5UnormPack16: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR5G5B5A1UnormPack16: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eB5G5R5A1UnormPack16: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eA1R5G5B5UnormPack16: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR8Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8Snorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8Uscaled: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8Sscaled: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8Sint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8Srgb: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Unorm: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Snorm: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Uscaled: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Sscaled: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Uint: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Sint: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Srgb: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Snorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Uscaled: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Sscaled: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Uint: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Sint: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Srgb: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Snorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Uscaled: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Sscaled: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Uint: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Sint: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Srgb: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Unorm: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Snorm: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Uscaled: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Sscaled: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Uint: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Sint: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Srgb: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Unorm: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Snorm: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Uscaled: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Sscaled: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Uint: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Sint: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Srgb: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8UnormPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SnormPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8UscaledPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SscaledPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8UintPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SintPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SrgbPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10UnormPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10SnormPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10UscaledPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10SscaledPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10UintPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10SintPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10UnormPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10SnormPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10UscaledPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10SscaledPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10UintPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10SintPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR16Unorm: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR16Snorm: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR16Uscaled: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR16Sscaled: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR16Uint: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR16Sint: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR16Sfloat: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Unorm: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Snorm: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Uscaled: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Sscaled: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Uint: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Sint: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Sfloat: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Unorm: return 6;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Snorm: return 6;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Uscaled: return 6;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Sscaled: return 6;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Uint: return 6;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Sint: return 6;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Sfloat: return 6;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Unorm: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Snorm: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Uscaled: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Sscaled: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Uint: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Sint: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Sfloat: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eR32Uint: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR32Sint: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR32Sfloat: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32Uint: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32Sint: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32Sfloat: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32Uint: return 12;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32Sint: return 12;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32Sfloat: return 12;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32A32Uint: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32A32Sint: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32A32Sfloat: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eR64Uint: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eR64Sint: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eR64Sfloat: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64Uint: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64Sint: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64Sfloat: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64Uint: return 24;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64Sint: return 24;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64Sfloat: return 24;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64A64Uint: return 32;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64A64Sint: return 32;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64A64Sfloat: return 32;
      case VULKAN_HPP_NAMESPACE::Format::eB10G11R11UfloatPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eE5B9G9R9UfloatPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eD16Unorm: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eX8D24UnormPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eD32Sfloat: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eS8Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eD16UnormS8Uint: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eD24UnormS8Uint: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eD32SfloatS8Uint: return 5;
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbUnormBlock: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbSrgbBlock: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbaUnormBlock: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbaSrgbBlock: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eBc2UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eBc2SrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eBc3UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eBc3SrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eBc4UnormBlock: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eBc4SnormBlock: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eBc5UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eBc5SnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eBc6HUfloatBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eBc6HSfloatBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eBc7UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eBc7SrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8UnormBlock: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8SrgbBlock: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A1UnormBlock: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A1SrgbBlock: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A8UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A8SrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eEacR11UnormBlock: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eEacR11SnormBlock: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eEacR11G11UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eEacR11G11SnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4SrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4SrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5SrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5SrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6SrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5SrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6SrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8SrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5SrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6SrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8SrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10SrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10SrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12SrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eG8B8G8R8422Unorm: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8G8422Unorm: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane420Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane420Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane422Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane422Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane444Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR10X6UnormPack16: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR10X6G10X6Unorm2Pack16: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR10X6G10X6B10X6A10X6Unorm4Pack16: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6G10X6R10X6422Unorm4Pack16: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eB10X6G10X6R10X6G10X6422Unorm4Pack16: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane420Unorm3Pack16: return 6;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane420Unorm3Pack16: return 6;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane422Unorm3Pack16: return 6;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane422Unorm3Pack16: return 6;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane444Unorm3Pack16: return 6;
      case VULKAN_HPP_NAMESPACE::Format::eR12X4UnormPack16: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR12X4G12X4Unorm2Pack16: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR12X4G12X4B12X4A12X4Unorm4Pack16: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4G12X4R12X4422Unorm4Pack16: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eB12X4G12X4R12X4G12X4422Unorm4Pack16: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane420Unorm3Pack16: return 6;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane420Unorm3Pack16: return 6;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane422Unorm3Pack16: return 6;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane422Unorm3Pack16: return 6;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane444Unorm3Pack16: return 6;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16G16R16422Unorm: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eB16G16R16G16422Unorm: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane420Unorm: return 6;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane420Unorm: return 6;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane422Unorm: return 6;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane422Unorm: return 6;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane444Unorm: return 6;
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane444Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane444Unorm3Pack16: return 6;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane444Unorm3Pack16: return 6;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane444Unorm: return 6;
      case VULKAN_HPP_NAMESPACE::Format::eA4R4G4B4UnormPack16: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eA4B4G4R4UnormPack16: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4SfloatBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4SfloatBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5SfloatBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5SfloatBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6SfloatBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5SfloatBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6SfloatBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8SfloatBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5SfloatBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6SfloatBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8SfloatBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10SfloatBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10SfloatBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12SfloatBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc12BppUnormBlockIMG: return 8;
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc14BppUnormBlockIMG: return 8;
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc22BppUnormBlockIMG: return 8;
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc24BppUnormBlockIMG: return 8;
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc12BppSrgbBlockIMG: return 8;
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc14BppSrgbBlockIMG: return 8;
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc22BppSrgbBlockIMG: return 8;
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc24BppSrgbBlockIMG: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16S105NV: return 4;

      default: VULKAN_HPP_ASSERT( false ); return 0;
    }
  }

  // The class of the format (can't be just named "class"!)
  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR_14 char const * compatibilityClass( VULKAN_HPP_NAMESPACE::Format format )
  {
    switch ( format )
    {
      case VULKAN_HPP_NAMESPACE::Format::eR4G4UnormPack8: return "8-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR4G4B4A4UnormPack16: return "16-bit";
      case VULKAN_HPP_NAMESPACE::Format::eB4G4R4A4UnormPack16: return "16-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR5G6B5UnormPack16: return "16-bit";
      case VULKAN_HPP_NAMESPACE::Format::eB5G6R5UnormPack16: return "16-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR5G5B5A1UnormPack16: return "16-bit";
      case VULKAN_HPP_NAMESPACE::Format::eB5G5R5A1UnormPack16: return "16-bit";
      case VULKAN_HPP_NAMESPACE::Format::eA1R5G5B5UnormPack16: return "16-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8Unorm: return "8-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8Snorm: return "8-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8Uscaled: return "8-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8Sscaled: return "8-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8Uint: return "8-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8Sint: return "8-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8Srgb: return "8-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Unorm: return "16-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Snorm: return "16-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Uscaled: return "16-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Sscaled: return "16-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Uint: return "16-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Sint: return "16-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Srgb: return "16-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Unorm: return "24-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Snorm: return "24-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Uscaled: return "24-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Sscaled: return "24-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Uint: return "24-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Sint: return "24-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Srgb: return "24-bit";
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Unorm: return "24-bit";
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Snorm: return "24-bit";
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Uscaled: return "24-bit";
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Sscaled: return "24-bit";
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Uint: return "24-bit";
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Sint: return "24-bit";
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Srgb: return "24-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Unorm: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Snorm: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Uscaled: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Sscaled: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Uint: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Sint: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Srgb: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Unorm: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Snorm: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Uscaled: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Sscaled: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Uint: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Sint: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Srgb: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8UnormPack32: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SnormPack32: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8UscaledPack32: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SscaledPack32: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8UintPack32: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SintPack32: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SrgbPack32: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10UnormPack32: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10SnormPack32: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10UscaledPack32: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10SscaledPack32: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10UintPack32: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10SintPack32: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10UnormPack32: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10SnormPack32: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10UscaledPack32: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10SscaledPack32: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10UintPack32: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10SintPack32: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16Unorm: return "16-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16Snorm: return "16-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16Uscaled: return "16-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16Sscaled: return "16-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16Uint: return "16-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16Sint: return "16-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16Sfloat: return "16-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Unorm: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Snorm: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Uscaled: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Sscaled: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Uint: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Sint: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Sfloat: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Unorm: return "48-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Snorm: return "48-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Uscaled: return "48-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Sscaled: return "48-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Uint: return "48-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Sint: return "48-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Sfloat: return "48-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Unorm: return "64-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Snorm: return "64-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Uscaled: return "64-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Sscaled: return "64-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Uint: return "64-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Sint: return "64-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Sfloat: return "64-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR32Uint: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR32Sint: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR32Sfloat: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR32G32Uint: return "64-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR32G32Sint: return "64-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR32G32Sfloat: return "64-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32Uint: return "96-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32Sint: return "96-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32Sfloat: return "96-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32A32Uint: return "128-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32A32Sint: return "128-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32A32Sfloat: return "128-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR64Uint: return "64-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR64Sint: return "64-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR64Sfloat: return "64-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR64G64Uint: return "128-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR64G64Sint: return "128-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR64G64Sfloat: return "128-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64Uint: return "192-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64Sint: return "192-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64Sfloat: return "192-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64A64Uint: return "256-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64A64Sint: return "256-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64A64Sfloat: return "256-bit";
      case VULKAN_HPP_NAMESPACE::Format::eB10G11R11UfloatPack32: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eE5B9G9R9UfloatPack32: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eD16Unorm: return "D16";
      case VULKAN_HPP_NAMESPACE::Format::eX8D24UnormPack32: return "D24";
      case VULKAN_HPP_NAMESPACE::Format::eD32Sfloat: return "D32";
      case VULKAN_HPP_NAMESPACE::Format::eS8Uint: return "S8";
      case VULKAN_HPP_NAMESPACE::Format::eD16UnormS8Uint: return "D16S8";
      case VULKAN_HPP_NAMESPACE::Format::eD24UnormS8Uint: return "D24S8";
      case VULKAN_HPP_NAMESPACE::Format::eD32SfloatS8Uint: return "D32S8";
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbUnormBlock: return "BC1_RGB";
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbSrgbBlock: return "BC1_RGB";
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbaUnormBlock: return "BC1_RGBA";
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbaSrgbBlock: return "BC1_RGBA";
      case VULKAN_HPP_NAMESPACE::Format::eBc2UnormBlock: return "BC2";
      case VULKAN_HPP_NAMESPACE::Format::eBc2SrgbBlock: return "BC2";
      case VULKAN_HPP_NAMESPACE::Format::eBc3UnormBlock: return "BC3";
      case VULKAN_HPP_NAMESPACE::Format::eBc3SrgbBlock: return "BC3";
      case VULKAN_HPP_NAMESPACE::Format::eBc4UnormBlock: return "BC4";
      case VULKAN_HPP_NAMESPACE::Format::eBc4SnormBlock: return "BC4";
      case VULKAN_HPP_NAMESPACE::Format::eBc5UnormBlock: return "BC5";
      case VULKAN_HPP_NAMESPACE::Format::eBc5SnormBlock: return "BC5";
      case VULKAN_HPP_NAMESPACE::Format::eBc6HUfloatBlock: return "BC6H";
      case VULKAN_HPP_NAMESPACE::Format::eBc6HSfloatBlock: return "BC6H";
      case VULKAN_HPP_NAMESPACE::Format::eBc7UnormBlock: return "BC7";
      case VULKAN_HPP_NAMESPACE::Format::eBc7SrgbBlock: return "BC7";
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8UnormBlock: return "ETC2_RGB";
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8SrgbBlock: return "ETC2_RGB";
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A1UnormBlock: return "ETC2_RGBA";
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A1SrgbBlock: return "ETC2_RGBA";
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A8UnormBlock: return "ETC2_EAC_RGBA";
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A8SrgbBlock: return "ETC2_EAC_RGBA";
      case VULKAN_HPP_NAMESPACE::Format::eEacR11UnormBlock: return "EAC_R";
      case VULKAN_HPP_NAMESPACE::Format::eEacR11SnormBlock: return "EAC_R";
      case VULKAN_HPP_NAMESPACE::Format::eEacR11G11UnormBlock: return "EAC_RG";
      case VULKAN_HPP_NAMESPACE::Format::eEacR11G11SnormBlock: return "EAC_RG";
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4UnormBlock: return "ASTC_4x4";
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4SrgbBlock: return "ASTC_4x4";
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4UnormBlock: return "ASTC_5x4";
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4SrgbBlock: return "ASTC_5x4";
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5UnormBlock: return "ASTC_5x5";
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5SrgbBlock: return "ASTC_5x5";
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5UnormBlock: return "ASTC_6x5";
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5SrgbBlock: return "ASTC_6x5";
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6UnormBlock: return "ASTC_6x6";
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6SrgbBlock: return "ASTC_6x6";
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5UnormBlock: return "ASTC_8x5";
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5SrgbBlock: return "ASTC_8x5";
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6UnormBlock: return "ASTC_8x6";
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6SrgbBlock: return "ASTC_8x6";
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8UnormBlock: return "ASTC_8x8";
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8SrgbBlock: return "ASTC_8x8";
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5UnormBlock: return "ASTC_10x5";
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5SrgbBlock: return "ASTC_10x5";
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6UnormBlock: return "ASTC_10x6";
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6SrgbBlock: return "ASTC_10x6";
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8UnormBlock: return "ASTC_10x8";
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8SrgbBlock: return "ASTC_10x8";
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10UnormBlock: return "ASTC_10x10";
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10SrgbBlock: return "ASTC_10x10";
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10UnormBlock: return "ASTC_12x10";
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10SrgbBlock: return "ASTC_12x10";
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12UnormBlock: return "ASTC_12x12";
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12SrgbBlock: return "ASTC_12x12";
      case VULKAN_HPP_NAMESPACE::Format::eG8B8G8R8422Unorm: return "32-bit G8B8G8R8";
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8G8422Unorm: return "32-bit B8G8R8G8";
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane420Unorm: return "8-bit 3-plane 420";
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane420Unorm: return "8-bit 2-plane 420";
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane422Unorm: return "8-bit 3-plane 422";
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane422Unorm: return "8-bit 2-plane 422";
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane444Unorm: return "8-bit 3-plane 444";
      case VULKAN_HPP_NAMESPACE::Format::eR10X6UnormPack16: return "16-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR10X6G10X6Unorm2Pack16: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR10X6G10X6B10X6A10X6Unorm4Pack16: return "64-bit R10G10B10A10";
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6G10X6R10X6422Unorm4Pack16: return "64-bit G10B10G10R10";
      case VULKAN_HPP_NAMESPACE::Format::eB10X6G10X6R10X6G10X6422Unorm4Pack16: return "64-bit B10G10R10G10";
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane420Unorm3Pack16: return "10-bit 3-plane 420";
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane420Unorm3Pack16: return "10-bit 2-plane 420";
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane422Unorm3Pack16: return "10-bit 3-plane 422";
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane422Unorm3Pack16: return "10-bit 2-plane 422";
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane444Unorm3Pack16: return "10-bit 3-plane 444";
      case VULKAN_HPP_NAMESPACE::Format::eR12X4UnormPack16: return "16-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR12X4G12X4Unorm2Pack16: return "32-bit";
      case VULKAN_HPP_NAMESPACE::Format::eR12X4G12X4B12X4A12X4Unorm4Pack16: return "64-bit R12G12B12A12";
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4G12X4R12X4422Unorm4Pack16: return "64-bit G12B12G12R12";
      case VULKAN_HPP_NAMESPACE::Format::eB12X4G12X4R12X4G12X4422Unorm4Pack16: return "64-bit B12G12R12G12";
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane420Unorm3Pack16: return "12-bit 3-plane 420";
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane420Unorm3Pack16: return "12-bit 2-plane 420";
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane422Unorm3Pack16: return "12-bit 3-plane 422";
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane422Unorm3Pack16: return "12-bit 2-plane 422";
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane444Unorm3Pack16: return "12-bit 3-plane 444";
      case VULKAN_HPP_NAMESPACE::Format::eG16B16G16R16422Unorm: return "64-bit G16B16G16R16";
      case VULKAN_HPP_NAMESPACE::Format::eB16G16R16G16422Unorm: return "64-bit B16G16R16G16";
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane420Unorm: return "16-bit 3-plane 420";
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane420Unorm: return "16-bit 2-plane 420";
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane422Unorm: return "16-bit 3-plane 422";
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane422Unorm: return "16-bit 2-plane 422";
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane444Unorm: return "16-bit 3-plane 444";
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane444Unorm: return "8-bit 2-plane 444";
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane444Unorm3Pack16: return "10-bit 2-plane 444";
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane444Unorm3Pack16: return "12-bit 2-plane 444";
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane444Unorm: return "16-bit 2-plane 444";
      case VULKAN_HPP_NAMESPACE::Format::eA4R4G4B4UnormPack16: return "16-bit";
      case VULKAN_HPP_NAMESPACE::Format::eA4B4G4R4UnormPack16: return "16-bit";
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4SfloatBlock: return "ASTC_4x4";
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4SfloatBlock: return "ASTC_5x4";
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5SfloatBlock: return "ASTC_5x5";
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5SfloatBlock: return "ASTC_6x5";
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6SfloatBlock: return "ASTC_6x6";
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5SfloatBlock: return "ASTC_8x5";
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6SfloatBlock: return "ASTC_8x6";
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8SfloatBlock: return "ASTC_8x8";
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5SfloatBlock: return "ASTC_10x5";
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6SfloatBlock: return "ASTC_10x6";
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8SfloatBlock: return "ASTC_10x8";
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10SfloatBlock: return "ASTC_10x10";
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10SfloatBlock: return "ASTC_12x10";
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12SfloatBlock: return "ASTC_12x12";
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc12BppUnormBlockIMG: return "PVRTC1_2BPP";
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc14BppUnormBlockIMG: return "PVRTC1_4BPP";
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc22BppUnormBlockIMG: return "PVRTC2_2BPP";
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc24BppUnormBlockIMG: return "PVRTC2_4BPP";
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc12BppSrgbBlockIMG: return "PVRTC1_2BPP";
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc14BppSrgbBlockIMG: return "PVRTC1_4BPP";
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc22BppSrgbBlockIMG: return "PVRTC2_2BPP";
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc24BppSrgbBlockIMG: return "PVRTC2_4BPP";
      case VULKAN_HPP_NAMESPACE::Format::eR16G16S105NV: return "32-bit";

      default: VULKAN_HPP_ASSERT( false ); return "";
    }
  }

  // The number of bits in this component, if not compressed, otherwise 0.
  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR_14 uint8_t componentBits( VULKAN_HPP_NAMESPACE::Format format, uint8_t component )
  {
    switch ( format )
    {
      case VULKAN_HPP_NAMESPACE::Format::eR4G4UnormPack8:
        switch ( component )
        {
          case 0: return 4;
          case 1: return 4;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR4G4B4A4UnormPack16:
        switch ( component )
        {
          case 0: return 4;
          case 1: return 4;
          case 2: return 4;
          case 3: return 4;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eB4G4R4A4UnormPack16:
        switch ( component )
        {
          case 0: return 4;
          case 1: return 4;
          case 2: return 4;
          case 3: return 4;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR5G6B5UnormPack16:
        switch ( component )
        {
          case 0: return 5;
          case 1: return 6;
          case 2: return 5;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eB5G6R5UnormPack16:
        switch ( component )
        {
          case 0: return 5;
          case 1: return 6;
          case 2: return 5;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR5G5B5A1UnormPack16:
        switch ( component )
        {
          case 0: return 5;
          case 1: return 5;
          case 2: return 5;
          case 3: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eB5G5R5A1UnormPack16:
        switch ( component )
        {
          case 0: return 5;
          case 1: return 5;
          case 2: return 5;
          case 3: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eA1R5G5B5UnormPack16:
        switch ( component )
        {
          case 0: return 1;
          case 1: return 5;
          case 2: return 5;
          case 3: return 5;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8Unorm:
        switch ( component )
        {
          case 0: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8Snorm:
        switch ( component )
        {
          case 0: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8Uscaled:
        switch ( component )
        {
          case 0: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8Sscaled:
        switch ( component )
        {
          case 0: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8Uint:
        switch ( component )
        {
          case 0: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8Sint:
        switch ( component )
        {
          case 0: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8Srgb:
        switch ( component )
        {
          case 0: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Unorm:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Snorm:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Uscaled:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Sscaled:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Uint:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Sint:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Srgb:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Unorm:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Snorm:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Uscaled:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Sscaled:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Uint:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Sint:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Srgb:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Unorm:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Snorm:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Uscaled:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Sscaled:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Uint:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Sint:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Srgb:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Unorm:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          case 3: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Snorm:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          case 3: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Uscaled:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          case 3: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Sscaled:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          case 3: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Uint:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          case 3: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Sint:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          case 3: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Srgb:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          case 3: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Unorm:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          case 3: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Snorm:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          case 3: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Uscaled:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          case 3: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Sscaled:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          case 3: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Uint:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          case 3: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Sint:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          case 3: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Srgb:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          case 3: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8UnormPack32:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          case 3: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SnormPack32:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          case 3: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8UscaledPack32:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          case 3: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SscaledPack32:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          case 3: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8UintPack32:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          case 3: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SintPack32:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          case 3: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SrgbPack32:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          case 3: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10UnormPack32:
        switch ( component )
        {
          case 0: return 2;
          case 1: return 10;
          case 2: return 10;
          case 3: return 10;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10SnormPack32:
        switch ( component )
        {
          case 0: return 2;
          case 1: return 10;
          case 2: return 10;
          case 3: return 10;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10UscaledPack32:
        switch ( component )
        {
          case 0: return 2;
          case 1: return 10;
          case 2: return 10;
          case 3: return 10;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10SscaledPack32:
        switch ( component )
        {
          case 0: return 2;
          case 1: return 10;
          case 2: return 10;
          case 3: return 10;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10UintPack32:
        switch ( component )
        {
          case 0: return 2;
          case 1: return 10;
          case 2: return 10;
          case 3: return 10;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10SintPack32:
        switch ( component )
        {
          case 0: return 2;
          case 1: return 10;
          case 2: return 10;
          case 3: return 10;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10UnormPack32:
        switch ( component )
        {
          case 0: return 2;
          case 1: return 10;
          case 2: return 10;
          case 3: return 10;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10SnormPack32:
        switch ( component )
        {
          case 0: return 2;
          case 1: return 10;
          case 2: return 10;
          case 3: return 10;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10UscaledPack32:
        switch ( component )
        {
          case 0: return 2;
          case 1: return 10;
          case 2: return 10;
          case 3: return 10;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10SscaledPack32:
        switch ( component )
        {
          case 0: return 2;
          case 1: return 10;
          case 2: return 10;
          case 3: return 10;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10UintPack32:
        switch ( component )
        {
          case 0: return 2;
          case 1: return 10;
          case 2: return 10;
          case 3: return 10;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10SintPack32:
        switch ( component )
        {
          case 0: return 2;
          case 1: return 10;
          case 2: return 10;
          case 3: return 10;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16Unorm:
        switch ( component )
        {
          case 0: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16Snorm:
        switch ( component )
        {
          case 0: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16Uscaled:
        switch ( component )
        {
          case 0: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16Sscaled:
        switch ( component )
        {
          case 0: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16Uint:
        switch ( component )
        {
          case 0: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16Sint:
        switch ( component )
        {
          case 0: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16Sfloat:
        switch ( component )
        {
          case 0: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Unorm:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Snorm:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Uscaled:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Sscaled:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Uint:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Sint:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Sfloat:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Unorm:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          case 2: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Snorm:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          case 2: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Uscaled:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          case 2: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Sscaled:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          case 2: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Uint:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          case 2: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Sint:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          case 2: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Sfloat:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          case 2: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Unorm:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          case 2: return 16;
          case 3: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Snorm:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          case 2: return 16;
          case 3: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Uscaled:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          case 2: return 16;
          case 3: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Sscaled:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          case 2: return 16;
          case 3: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Uint:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          case 2: return 16;
          case 3: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Sint:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          case 2: return 16;
          case 3: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Sfloat:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          case 2: return 16;
          case 3: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32Uint:
        switch ( component )
        {
          case 0: return 32;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32Sint:
        switch ( component )
        {
          case 0: return 32;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32Sfloat:
        switch ( component )
        {
          case 0: return 32;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32Uint:
        switch ( component )
        {
          case 0: return 32;
          case 1: return 32;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32Sint:
        switch ( component )
        {
          case 0: return 32;
          case 1: return 32;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32Sfloat:
        switch ( component )
        {
          case 0: return 32;
          case 1: return 32;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32Uint:
        switch ( component )
        {
          case 0: return 32;
          case 1: return 32;
          case 2: return 32;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32Sint:
        switch ( component )
        {
          case 0: return 32;
          case 1: return 32;
          case 2: return 32;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32Sfloat:
        switch ( component )
        {
          case 0: return 32;
          case 1: return 32;
          case 2: return 32;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32A32Uint:
        switch ( component )
        {
          case 0: return 32;
          case 1: return 32;
          case 2: return 32;
          case 3: return 32;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32A32Sint:
        switch ( component )
        {
          case 0: return 32;
          case 1: return 32;
          case 2: return 32;
          case 3: return 32;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32A32Sfloat:
        switch ( component )
        {
          case 0: return 32;
          case 1: return 32;
          case 2: return 32;
          case 3: return 32;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64Uint:
        switch ( component )
        {
          case 0: return 64;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64Sint:
        switch ( component )
        {
          case 0: return 64;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64Sfloat:
        switch ( component )
        {
          case 0: return 64;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64Uint:
        switch ( component )
        {
          case 0: return 64;
          case 1: return 64;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64Sint:
        switch ( component )
        {
          case 0: return 64;
          case 1: return 64;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64Sfloat:
        switch ( component )
        {
          case 0: return 64;
          case 1: return 64;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64Uint:
        switch ( component )
        {
          case 0: return 64;
          case 1: return 64;
          case 2: return 64;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64Sint:
        switch ( component )
        {
          case 0: return 64;
          case 1: return 64;
          case 2: return 64;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64Sfloat:
        switch ( component )
        {
          case 0: return 64;
          case 1: return 64;
          case 2: return 64;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64A64Uint:
        switch ( component )
        {
          case 0: return 64;
          case 1: return 64;
          case 2: return 64;
          case 3: return 64;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64A64Sint:
        switch ( component )
        {
          case 0: return 64;
          case 1: return 64;
          case 2: return 64;
          case 3: return 64;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64A64Sfloat:
        switch ( component )
        {
          case 0: return 64;
          case 1: return 64;
          case 2: return 64;
          case 3: return 64;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eB10G11R11UfloatPack32:
        switch ( component )
        {
          case 0: return 10;
          case 1: return 11;
          case 2: return 10;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eE5B9G9R9UfloatPack32:
        switch ( component )
        {
          case 0: return 9;
          case 1: return 9;
          case 2: return 9;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eD16Unorm:
        switch ( component )
        {
          case 0: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eX8D24UnormPack32:
        switch ( component )
        {
          case 0: return 24;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eD32Sfloat:
        switch ( component )
        {
          case 0: return 32;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eS8Uint:
        switch ( component )
        {
          case 0: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eD16UnormS8Uint:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eD24UnormS8Uint:
        switch ( component )
        {
          case 0: return 24;
          case 1: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eD32SfloatS8Uint:
        switch ( component )
        {
          case 0: return 32;
          case 1: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eEacR11UnormBlock:
        switch ( component )
        {
          case 0: return 11;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eEacR11SnormBlock:
        switch ( component )
        {
          case 0: return 11;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eEacR11G11UnormBlock:
        switch ( component )
        {
          case 0: return 11;
          case 1: return 11;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eEacR11G11SnormBlock:
        switch ( component )
        {
          case 0: return 11;
          case 1: return 11;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8G8R8422Unorm:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          case 3: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8G8422Unorm:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          case 3: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane420Unorm:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane420Unorm:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane422Unorm:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane422Unorm:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane444Unorm:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR10X6UnormPack16:
        switch ( component )
        {
          case 0: return 10;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR10X6G10X6Unorm2Pack16:
        switch ( component )
        {
          case 0: return 10;
          case 1: return 10;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR10X6G10X6B10X6A10X6Unorm4Pack16:
        switch ( component )
        {
          case 0: return 10;
          case 1: return 10;
          case 2: return 10;
          case 3: return 10;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6G10X6R10X6422Unorm4Pack16:
        switch ( component )
        {
          case 0: return 10;
          case 1: return 10;
          case 2: return 10;
          case 3: return 10;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eB10X6G10X6R10X6G10X6422Unorm4Pack16:
        switch ( component )
        {
          case 0: return 10;
          case 1: return 10;
          case 2: return 10;
          case 3: return 10;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane420Unorm3Pack16:
        switch ( component )
        {
          case 0: return 10;
          case 1: return 10;
          case 2: return 10;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane420Unorm3Pack16:
        switch ( component )
        {
          case 0: return 10;
          case 1: return 10;
          case 2: return 10;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane422Unorm3Pack16:
        switch ( component )
        {
          case 0: return 10;
          case 1: return 10;
          case 2: return 10;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane422Unorm3Pack16:
        switch ( component )
        {
          case 0: return 10;
          case 1: return 10;
          case 2: return 10;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane444Unorm3Pack16:
        switch ( component )
        {
          case 0: return 10;
          case 1: return 10;
          case 2: return 10;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR12X4UnormPack16:
        switch ( component )
        {
          case 0: return 12;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR12X4G12X4Unorm2Pack16:
        switch ( component )
        {
          case 0: return 12;
          case 1: return 12;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR12X4G12X4B12X4A12X4Unorm4Pack16:
        switch ( component )
        {
          case 0: return 12;
          case 1: return 12;
          case 2: return 12;
          case 3: return 12;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4G12X4R12X4422Unorm4Pack16:
        switch ( component )
        {
          case 0: return 12;
          case 1: return 12;
          case 2: return 12;
          case 3: return 12;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eB12X4G12X4R12X4G12X4422Unorm4Pack16:
        switch ( component )
        {
          case 0: return 12;
          case 1: return 12;
          case 2: return 12;
          case 3: return 12;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane420Unorm3Pack16:
        switch ( component )
        {
          case 0: return 12;
          case 1: return 12;
          case 2: return 12;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane420Unorm3Pack16:
        switch ( component )
        {
          case 0: return 12;
          case 1: return 12;
          case 2: return 12;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane422Unorm3Pack16:
        switch ( component )
        {
          case 0: return 12;
          case 1: return 12;
          case 2: return 12;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane422Unorm3Pack16:
        switch ( component )
        {
          case 0: return 12;
          case 1: return 12;
          case 2: return 12;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane444Unorm3Pack16:
        switch ( component )
        {
          case 0: return 12;
          case 1: return 12;
          case 2: return 12;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16G16R16422Unorm:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          case 2: return 16;
          case 3: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eB16G16R16G16422Unorm:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          case 2: return 16;
          case 3: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane420Unorm:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          case 2: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane420Unorm:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          case 2: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane422Unorm:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          case 2: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane422Unorm:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          case 2: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane444Unorm:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          case 2: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane444Unorm:
        switch ( component )
        {
          case 0: return 8;
          case 1: return 8;
          case 2: return 8;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane444Unorm3Pack16:
        switch ( component )
        {
          case 0: return 10;
          case 1: return 10;
          case 2: return 10;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane444Unorm3Pack16:
        switch ( component )
        {
          case 0: return 12;
          case 1: return 12;
          case 2: return 12;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane444Unorm:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          case 2: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eA4R4G4B4UnormPack16:
        switch ( component )
        {
          case 0: return 4;
          case 1: return 4;
          case 2: return 4;
          case 3: return 4;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eA4B4G4R4UnormPack16:
        switch ( component )
        {
          case 0: return 4;
          case 1: return 4;
          case 2: return 4;
          case 3: return 4;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16S105NV:
        switch ( component )
        {
          case 0: return 16;
          case 1: return 16;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }

      default: return 0;
    }
  }

  // The number of components of this format.
  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR_14 uint8_t componentCount( VULKAN_HPP_NAMESPACE::Format format )
  {
    switch ( format )
    {
      case VULKAN_HPP_NAMESPACE::Format::eR4G4UnormPack8: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR4G4B4A4UnormPack16: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eB4G4R4A4UnormPack16: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR5G6B5UnormPack16: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eB5G6R5UnormPack16: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR5G5B5A1UnormPack16: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eB5G5R5A1UnormPack16: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA1R5G5B5UnormPack16: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR8Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8Snorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8Uscaled: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8Sscaled: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8Sint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8Srgb: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Unorm: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Snorm: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Uscaled: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Sscaled: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Uint: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Sint: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Srgb: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Snorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Uscaled: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Sscaled: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Uint: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Sint: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Srgb: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Snorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Uscaled: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Sscaled: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Uint: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Sint: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Srgb: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Unorm: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Snorm: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Uscaled: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Sscaled: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Uint: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Sint: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Srgb: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Unorm: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Snorm: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Uscaled: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Sscaled: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Uint: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Sint: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Srgb: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8UnormPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SnormPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8UscaledPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SscaledPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8UintPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SintPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SrgbPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10UnormPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10SnormPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10UscaledPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10SscaledPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10UintPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10SintPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10UnormPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10SnormPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10UscaledPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10SscaledPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10UintPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10SintPack32: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR16Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16Snorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16Uscaled: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16Sscaled: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16Sint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16Sfloat: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Unorm: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Snorm: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Uscaled: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Sscaled: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Uint: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Sint: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Sfloat: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Snorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Uscaled: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Sscaled: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Uint: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Sint: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Sfloat: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Unorm: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Snorm: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Uscaled: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Sscaled: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Uint: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Sint: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Sfloat: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR32Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR32Sint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR32Sfloat: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32Uint: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32Sint: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32Sfloat: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32Uint: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32Sint: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32Sfloat: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32A32Uint: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32A32Sint: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32A32Sfloat: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR64Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR64Sint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR64Sfloat: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64Uint: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64Sint: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64Sfloat: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64Uint: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64Sint: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64Sfloat: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64A64Uint: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64A64Sint: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64A64Sfloat: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eB10G11R11UfloatPack32: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eE5B9G9R9UfloatPack32: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eD16Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eX8D24UnormPack32: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eD32Sfloat: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eS8Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eD16UnormS8Uint: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eD24UnormS8Uint: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eD32SfloatS8Uint: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbUnormBlock: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbSrgbBlock: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbaUnormBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbaSrgbBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eBc2UnormBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eBc2SrgbBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eBc3UnormBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eBc3SrgbBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eBc4UnormBlock: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eBc4SnormBlock: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eBc5UnormBlock: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eBc5SnormBlock: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eBc6HUfloatBlock: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eBc6HSfloatBlock: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eBc7UnormBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eBc7SrgbBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8UnormBlock: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8SrgbBlock: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A1UnormBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A1SrgbBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A8UnormBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A8SrgbBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eEacR11UnormBlock: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eEacR11SnormBlock: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eEacR11G11UnormBlock: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eEacR11G11SnormBlock: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4UnormBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4SrgbBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4UnormBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4SrgbBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5UnormBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5SrgbBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5UnormBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5SrgbBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6UnormBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6SrgbBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5UnormBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5SrgbBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6UnormBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6SrgbBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8UnormBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8SrgbBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5UnormBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5SrgbBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6UnormBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6SrgbBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8UnormBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8SrgbBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10UnormBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10SrgbBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10UnormBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10SrgbBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12UnormBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12SrgbBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eG8B8G8R8422Unorm: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8G8422Unorm: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane420Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane420Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane422Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane422Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane444Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR10X6UnormPack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR10X6G10X6Unorm2Pack16: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR10X6G10X6B10X6A10X6Unorm4Pack16: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6G10X6R10X6422Unorm4Pack16: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eB10X6G10X6R10X6G10X6422Unorm4Pack16: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane420Unorm3Pack16: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane420Unorm3Pack16: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane422Unorm3Pack16: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane422Unorm3Pack16: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane444Unorm3Pack16: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eR12X4UnormPack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR12X4G12X4Unorm2Pack16: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eR12X4G12X4B12X4A12X4Unorm4Pack16: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4G12X4R12X4422Unorm4Pack16: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eB12X4G12X4R12X4G12X4422Unorm4Pack16: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane420Unorm3Pack16: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane420Unorm3Pack16: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane422Unorm3Pack16: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane422Unorm3Pack16: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane444Unorm3Pack16: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16G16R16422Unorm: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eB16G16R16G16422Unorm: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane420Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane420Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane422Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane422Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane444Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane444Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane444Unorm3Pack16: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane444Unorm3Pack16: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane444Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eA4R4G4B4UnormPack16: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eA4B4G4R4UnormPack16: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4SfloatBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4SfloatBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5SfloatBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5SfloatBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6SfloatBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5SfloatBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6SfloatBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8SfloatBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5SfloatBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6SfloatBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8SfloatBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10SfloatBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10SfloatBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12SfloatBlock: return 4;
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc12BppUnormBlockIMG: return 4;
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc14BppUnormBlockIMG: return 4;
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc22BppUnormBlockIMG: return 4;
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc24BppUnormBlockIMG: return 4;
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc12BppSrgbBlockIMG: return 4;
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc14BppSrgbBlockIMG: return 4;
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc22BppSrgbBlockIMG: return 4;
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc24BppSrgbBlockIMG: return 4;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16S105NV: return 2;

      default: return 0;
    }
  }

  // The name of the component
  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR_14 char const * componentName( VULKAN_HPP_NAMESPACE::Format format, uint8_t component )
  {
    switch ( format )
    {
      case VULKAN_HPP_NAMESPACE::Format::eR4G4UnormPack8:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR4G4B4A4UnormPack16:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB4G4R4A4UnormPack16:
        switch ( component )
        {
          case 0: return "B";
          case 1: return "G";
          case 2: return "R";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR5G6B5UnormPack16:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB5G6R5UnormPack16:
        switch ( component )
        {
          case 0: return "B";
          case 1: return "G";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR5G5B5A1UnormPack16:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB5G5R5A1UnormPack16:
        switch ( component )
        {
          case 0: return "B";
          case 1: return "R";
          case 2: return "G";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA1R5G5B5UnormPack16:
        switch ( component )
        {
          case 0: return "A";
          case 1: return "R";
          case 2: return "G";
          case 3: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8Unorm:
        switch ( component )
        {
          case 0: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8Snorm:
        switch ( component )
        {
          case 0: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8Uscaled:
        switch ( component )
        {
          case 0: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8Sscaled:
        switch ( component )
        {
          case 0: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8Uint:
        switch ( component )
        {
          case 0: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8Sint:
        switch ( component )
        {
          case 0: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8Srgb:
        switch ( component )
        {
          case 0: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Unorm:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Snorm:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Uscaled:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Sscaled:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Uint:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Sint:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Srgb:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Unorm:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Snorm:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Uscaled:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Sscaled:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Uint:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Sint:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Srgb:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Unorm:
        switch ( component )
        {
          case 0: return "B";
          case 1: return "G";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Snorm:
        switch ( component )
        {
          case 0: return "B";
          case 1: return "G";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Uscaled:
        switch ( component )
        {
          case 0: return "B";
          case 1: return "G";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Sscaled:
        switch ( component )
        {
          case 0: return "B";
          case 1: return "G";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Uint:
        switch ( component )
        {
          case 0: return "B";
          case 1: return "G";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Sint:
        switch ( component )
        {
          case 0: return "B";
          case 1: return "G";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Srgb:
        switch ( component )
        {
          case 0: return "B";
          case 1: return "G";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Unorm:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Snorm:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Uscaled:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Sscaled:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Uint:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Sint:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Srgb:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Unorm:
        switch ( component )
        {
          case 0: return "B";
          case 1: return "G";
          case 2: return "R";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Snorm:
        switch ( component )
        {
          case 0: return "B";
          case 1: return "G";
          case 2: return "R";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Uscaled:
        switch ( component )
        {
          case 0: return "B";
          case 1: return "G";
          case 2: return "R";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Sscaled:
        switch ( component )
        {
          case 0: return "B";
          case 1: return "G";
          case 2: return "R";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Uint:
        switch ( component )
        {
          case 0: return "B";
          case 1: return "G";
          case 2: return "R";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Sint:
        switch ( component )
        {
          case 0: return "B";
          case 1: return "G";
          case 2: return "R";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Srgb:
        switch ( component )
        {
          case 0: return "B";
          case 1: return "G";
          case 2: return "R";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8UnormPack32:
        switch ( component )
        {
          case 0: return "A";
          case 1: return "B";
          case 2: return "G";
          case 3: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SnormPack32:
        switch ( component )
        {
          case 0: return "A";
          case 1: return "B";
          case 2: return "G";
          case 3: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8UscaledPack32:
        switch ( component )
        {
          case 0: return "A";
          case 1: return "B";
          case 2: return "G";
          case 3: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SscaledPack32:
        switch ( component )
        {
          case 0: return "A";
          case 1: return "B";
          case 2: return "G";
          case 3: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8UintPack32:
        switch ( component )
        {
          case 0: return "A";
          case 1: return "B";
          case 2: return "G";
          case 3: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SintPack32:
        switch ( component )
        {
          case 0: return "A";
          case 1: return "B";
          case 2: return "G";
          case 3: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SrgbPack32:
        switch ( component )
        {
          case 0: return "A";
          case 1: return "B";
          case 2: return "G";
          case 3: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10UnormPack32:
        switch ( component )
        {
          case 0: return "A";
          case 1: return "R";
          case 2: return "G";
          case 3: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10SnormPack32:
        switch ( component )
        {
          case 0: return "A";
          case 1: return "R";
          case 2: return "G";
          case 3: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10UscaledPack32:
        switch ( component )
        {
          case 0: return "A";
          case 1: return "R";
          case 2: return "G";
          case 3: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10SscaledPack32:
        switch ( component )
        {
          case 0: return "A";
          case 1: return "R";
          case 2: return "G";
          case 3: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10UintPack32:
        switch ( component )
        {
          case 0: return "A";
          case 1: return "R";
          case 2: return "G";
          case 3: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10SintPack32:
        switch ( component )
        {
          case 0: return "A";
          case 1: return "R";
          case 2: return "G";
          case 3: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10UnormPack32:
        switch ( component )
        {
          case 0: return "A";
          case 1: return "B";
          case 2: return "G";
          case 3: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10SnormPack32:
        switch ( component )
        {
          case 0: return "A";
          case 1: return "B";
          case 2: return "G";
          case 3: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10UscaledPack32:
        switch ( component )
        {
          case 0: return "A";
          case 1: return "B";
          case 2: return "G";
          case 3: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10SscaledPack32:
        switch ( component )
        {
          case 0: return "A";
          case 1: return "B";
          case 2: return "G";
          case 3: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10UintPack32:
        switch ( component )
        {
          case 0: return "A";
          case 1: return "B";
          case 2: return "G";
          case 3: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10SintPack32:
        switch ( component )
        {
          case 0: return "A";
          case 1: return "B";
          case 2: return "G";
          case 3: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16Unorm:
        switch ( component )
        {
          case 0: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16Snorm:
        switch ( component )
        {
          case 0: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16Uscaled:
        switch ( component )
        {
          case 0: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16Sscaled:
        switch ( component )
        {
          case 0: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16Uint:
        switch ( component )
        {
          case 0: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16Sint:
        switch ( component )
        {
          case 0: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16Sfloat:
        switch ( component )
        {
          case 0: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Unorm:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Snorm:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Uscaled:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Sscaled:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Uint:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Sint:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Sfloat:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Unorm:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Snorm:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Uscaled:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Sscaled:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Uint:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Sint:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Sfloat:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Unorm:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Snorm:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Uscaled:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Sscaled:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Uint:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Sint:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Sfloat:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32Uint:
        switch ( component )
        {
          case 0: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32Sint:
        switch ( component )
        {
          case 0: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32Sfloat:
        switch ( component )
        {
          case 0: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32Uint:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32Sint:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32Sfloat:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32Uint:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32Sint:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32Sfloat:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32A32Uint:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32A32Sint:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32A32Sfloat:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64Uint:
        switch ( component )
        {
          case 0: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64Sint:
        switch ( component )
        {
          case 0: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64Sfloat:
        switch ( component )
        {
          case 0: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64Uint:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64Sint:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64Sfloat:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64Uint:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64Sint:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64Sfloat:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64A64Uint:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64A64Sint:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64A64Sfloat:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB10G11R11UfloatPack32:
        switch ( component )
        {
          case 0: return "B";
          case 1: return "G";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eE5B9G9R9UfloatPack32:
        switch ( component )
        {
          case 0: return "B";
          case 1: return "G";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eD16Unorm:
        switch ( component )
        {
          case 0: return "D";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eX8D24UnormPack32:
        switch ( component )
        {
          case 0: return "D";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eD32Sfloat:
        switch ( component )
        {
          case 0: return "D";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eS8Uint:
        switch ( component )
        {
          case 0: return "S";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eD16UnormS8Uint:
        switch ( component )
        {
          case 0: return "D";
          case 1: return "S";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eD24UnormS8Uint:
        switch ( component )
        {
          case 0: return "D";
          case 1: return "S";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eD32SfloatS8Uint:
        switch ( component )
        {
          case 0: return "D";
          case 1: return "S";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbUnormBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbSrgbBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbaUnormBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbaSrgbBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc2UnormBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc2SrgbBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc3UnormBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc3SrgbBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc4UnormBlock:
        switch ( component )
        {
          case 0: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc4SnormBlock:
        switch ( component )
        {
          case 0: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc5UnormBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc5SnormBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc6HUfloatBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc6HSfloatBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc7UnormBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc7SrgbBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8UnormBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8SrgbBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A1UnormBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A1SrgbBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A8UnormBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A8SrgbBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eEacR11UnormBlock:
        switch ( component )
        {
          case 0: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eEacR11SnormBlock:
        switch ( component )
        {
          case 0: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eEacR11G11UnormBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eEacR11G11SnormBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4UnormBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4SrgbBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4UnormBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4SrgbBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5UnormBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5SrgbBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5UnormBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5SrgbBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6UnormBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6SrgbBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5UnormBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5SrgbBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6UnormBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6SrgbBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8UnormBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8SrgbBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5UnormBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5SrgbBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6UnormBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6SrgbBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8UnormBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8SrgbBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10UnormBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10SrgbBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10UnormBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10SrgbBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12UnormBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12SrgbBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8G8R8422Unorm:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "G";
          case 3: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8G8422Unorm:
        switch ( component )
        {
          case 0: return "B";
          case 1: return "G";
          case 2: return "R";
          case 3: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane420Unorm:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane420Unorm:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane422Unorm:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane422Unorm:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane444Unorm:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR10X6UnormPack16:
        switch ( component )
        {
          case 0: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR10X6G10X6Unorm2Pack16:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR10X6G10X6B10X6A10X6Unorm4Pack16:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6G10X6R10X6422Unorm4Pack16:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "G";
          case 3: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB10X6G10X6R10X6G10X6422Unorm4Pack16:
        switch ( component )
        {
          case 0: return "B";
          case 1: return "G";
          case 2: return "R";
          case 3: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane420Unorm3Pack16:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane420Unorm3Pack16:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane422Unorm3Pack16:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane422Unorm3Pack16:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane444Unorm3Pack16:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR12X4UnormPack16:
        switch ( component )
        {
          case 0: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR12X4G12X4Unorm2Pack16:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR12X4G12X4B12X4A12X4Unorm4Pack16:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4G12X4R12X4422Unorm4Pack16:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "G";
          case 3: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB12X4G12X4R12X4G12X4422Unorm4Pack16:
        switch ( component )
        {
          case 0: return "B";
          case 1: return "G";
          case 2: return "R";
          case 3: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane420Unorm3Pack16:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane420Unorm3Pack16:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane422Unorm3Pack16:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane422Unorm3Pack16:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane444Unorm3Pack16:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16G16R16422Unorm:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "G";
          case 3: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB16G16R16G16422Unorm:
        switch ( component )
        {
          case 0: return "B";
          case 1: return "G";
          case 2: return "R";
          case 3: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane420Unorm:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane420Unorm:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane422Unorm:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane422Unorm:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane444Unorm:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane444Unorm:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane444Unorm3Pack16:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane444Unorm3Pack16:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane444Unorm:
        switch ( component )
        {
          case 0: return "G";
          case 1: return "B";
          case 2: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA4R4G4B4UnormPack16:
        switch ( component )
        {
          case 0: return "A";
          case 1: return "R";
          case 2: return "G";
          case 3: return "B";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA4B4G4R4UnormPack16:
        switch ( component )
        {
          case 0: return "A";
          case 1: return "B";
          case 2: return "G";
          case 3: return "R";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4SfloatBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4SfloatBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5SfloatBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5SfloatBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6SfloatBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5SfloatBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6SfloatBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8SfloatBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5SfloatBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6SfloatBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8SfloatBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10SfloatBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10SfloatBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12SfloatBlock:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc12BppUnormBlockIMG:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc14BppUnormBlockIMG:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc22BppUnormBlockIMG:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc24BppUnormBlockIMG:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc12BppSrgbBlockIMG:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc14BppSrgbBlockIMG:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc22BppSrgbBlockIMG:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc24BppSrgbBlockIMG:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          case 2: return "B";
          case 3: return "A";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16S105NV:
        switch ( component )
        {
          case 0: return "R";
          case 1: return "G";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }

      default: return "";
    }
  }

  // The numeric format of the component
  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR_14 char const * componentNumericFormat( VULKAN_HPP_NAMESPACE::Format format, uint8_t component )
  {
    switch ( format )
    {
      case VULKAN_HPP_NAMESPACE::Format::eR4G4UnormPack8:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR4G4B4A4UnormPack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB4G4R4A4UnormPack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR5G6B5UnormPack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB5G6R5UnormPack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR5G5B5A1UnormPack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB5G5R5A1UnormPack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA1R5G5B5UnormPack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8Snorm:
        switch ( component )
        {
          case 0: return "SNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8Uscaled:
        switch ( component )
        {
          case 0: return "USCALED";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8Sscaled:
        switch ( component )
        {
          case 0: return "SSCALED";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8Uint:
        switch ( component )
        {
          case 0: return "UINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8Sint:
        switch ( component )
        {
          case 0: return "SINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8Srgb:
        switch ( component )
        {
          case 0: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Snorm:
        switch ( component )
        {
          case 0: return "SNORM";
          case 1: return "SNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Uscaled:
        switch ( component )
        {
          case 0: return "USCALED";
          case 1: return "USCALED";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Sscaled:
        switch ( component )
        {
          case 0: return "SSCALED";
          case 1: return "SSCALED";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Uint:
        switch ( component )
        {
          case 0: return "UINT";
          case 1: return "UINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Sint:
        switch ( component )
        {
          case 0: return "SINT";
          case 1: return "SINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Srgb:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Snorm:
        switch ( component )
        {
          case 0: return "SNORM";
          case 1: return "SNORM";
          case 2: return "SNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Uscaled:
        switch ( component )
        {
          case 0: return "USCALED";
          case 1: return "USCALED";
          case 2: return "USCALED";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Sscaled:
        switch ( component )
        {
          case 0: return "SSCALED";
          case 1: return "SSCALED";
          case 2: return "SSCALED";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Uint:
        switch ( component )
        {
          case 0: return "UINT";
          case 1: return "UINT";
          case 2: return "UINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Sint:
        switch ( component )
        {
          case 0: return "SINT";
          case 1: return "SINT";
          case 2: return "SINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Srgb:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Snorm:
        switch ( component )
        {
          case 0: return "SNORM";
          case 1: return "SNORM";
          case 2: return "SNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Uscaled:
        switch ( component )
        {
          case 0: return "USCALED";
          case 1: return "USCALED";
          case 2: return "USCALED";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Sscaled:
        switch ( component )
        {
          case 0: return "SSCALED";
          case 1: return "SSCALED";
          case 2: return "SSCALED";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Uint:
        switch ( component )
        {
          case 0: return "UINT";
          case 1: return "UINT";
          case 2: return "UINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Sint:
        switch ( component )
        {
          case 0: return "SINT";
          case 1: return "SINT";
          case 2: return "SINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Srgb:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Snorm:
        switch ( component )
        {
          case 0: return "SNORM";
          case 1: return "SNORM";
          case 2: return "SNORM";
          case 3: return "SNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Uscaled:
        switch ( component )
        {
          case 0: return "USCALED";
          case 1: return "USCALED";
          case 2: return "USCALED";
          case 3: return "USCALED";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Sscaled:
        switch ( component )
        {
          case 0: return "SSCALED";
          case 1: return "SSCALED";
          case 2: return "SSCALED";
          case 3: return "SSCALED";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Uint:
        switch ( component )
        {
          case 0: return "UINT";
          case 1: return "UINT";
          case 2: return "UINT";
          case 3: return "UINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Sint:
        switch ( component )
        {
          case 0: return "SINT";
          case 1: return "SINT";
          case 2: return "SINT";
          case 3: return "SINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Srgb:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Snorm:
        switch ( component )
        {
          case 0: return "SNORM";
          case 1: return "SNORM";
          case 2: return "SNORM";
          case 3: return "SNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Uscaled:
        switch ( component )
        {
          case 0: return "USCALED";
          case 1: return "USCALED";
          case 2: return "USCALED";
          case 3: return "USCALED";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Sscaled:
        switch ( component )
        {
          case 0: return "SSCALED";
          case 1: return "SSCALED";
          case 2: return "SSCALED";
          case 3: return "SSCALED";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Uint:
        switch ( component )
        {
          case 0: return "UINT";
          case 1: return "UINT";
          case 2: return "UINT";
          case 3: return "UINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Sint:
        switch ( component )
        {
          case 0: return "SINT";
          case 1: return "SINT";
          case 2: return "SINT";
          case 3: return "SINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Srgb:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8UnormPack32:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SnormPack32:
        switch ( component )
        {
          case 0: return "SNORM";
          case 1: return "SNORM";
          case 2: return "SNORM";
          case 3: return "SNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8UscaledPack32:
        switch ( component )
        {
          case 0: return "USCALED";
          case 1: return "USCALED";
          case 2: return "USCALED";
          case 3: return "USCALED";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SscaledPack32:
        switch ( component )
        {
          case 0: return "SSCALED";
          case 1: return "SSCALED";
          case 2: return "SSCALED";
          case 3: return "SSCALED";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8UintPack32:
        switch ( component )
        {
          case 0: return "UINT";
          case 1: return "UINT";
          case 2: return "UINT";
          case 3: return "UINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SintPack32:
        switch ( component )
        {
          case 0: return "SINT";
          case 1: return "SINT";
          case 2: return "SINT";
          case 3: return "SINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SrgbPack32:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10UnormPack32:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10SnormPack32:
        switch ( component )
        {
          case 0: return "SNORM";
          case 1: return "SNORM";
          case 2: return "SNORM";
          case 3: return "SNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10UscaledPack32:
        switch ( component )
        {
          case 0: return "USCALED";
          case 1: return "USCALED";
          case 2: return "USCALED";
          case 3: return "USCALED";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10SscaledPack32:
        switch ( component )
        {
          case 0: return "SSCALED";
          case 1: return "SSCALED";
          case 2: return "SSCALED";
          case 3: return "SSCALED";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10UintPack32:
        switch ( component )
        {
          case 0: return "UINT";
          case 1: return "UINT";
          case 2: return "UINT";
          case 3: return "UINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10SintPack32:
        switch ( component )
        {
          case 0: return "SINT";
          case 1: return "SINT";
          case 2: return "SINT";
          case 3: return "SINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10UnormPack32:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10SnormPack32:
        switch ( component )
        {
          case 0: return "SNORM";
          case 1: return "SNORM";
          case 2: return "SNORM";
          case 3: return "SNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10UscaledPack32:
        switch ( component )
        {
          case 0: return "USCALED";
          case 1: return "USCALED";
          case 2: return "USCALED";
          case 3: return "USCALED";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10SscaledPack32:
        switch ( component )
        {
          case 0: return "SSCALED";
          case 1: return "SSCALED";
          case 2: return "SSCALED";
          case 3: return "SSCALED";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10UintPack32:
        switch ( component )
        {
          case 0: return "UINT";
          case 1: return "UINT";
          case 2: return "UINT";
          case 3: return "UINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10SintPack32:
        switch ( component )
        {
          case 0: return "SINT";
          case 1: return "SINT";
          case 2: return "SINT";
          case 3: return "SINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16Snorm:
        switch ( component )
        {
          case 0: return "SNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16Uscaled:
        switch ( component )
        {
          case 0: return "USCALED";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16Sscaled:
        switch ( component )
        {
          case 0: return "SSCALED";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16Uint:
        switch ( component )
        {
          case 0: return "UINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16Sint:
        switch ( component )
        {
          case 0: return "SINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16Sfloat:
        switch ( component )
        {
          case 0: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Snorm:
        switch ( component )
        {
          case 0: return "SNORM";
          case 1: return "SNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Uscaled:
        switch ( component )
        {
          case 0: return "USCALED";
          case 1: return "USCALED";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Sscaled:
        switch ( component )
        {
          case 0: return "SSCALED";
          case 1: return "SSCALED";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Uint:
        switch ( component )
        {
          case 0: return "UINT";
          case 1: return "UINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Sint:
        switch ( component )
        {
          case 0: return "SINT";
          case 1: return "SINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Sfloat:
        switch ( component )
        {
          case 0: return "SFLOAT";
          case 1: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Snorm:
        switch ( component )
        {
          case 0: return "SNORM";
          case 1: return "SNORM";
          case 2: return "SNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Uscaled:
        switch ( component )
        {
          case 0: return "USCALED";
          case 1: return "USCALED";
          case 2: return "USCALED";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Sscaled:
        switch ( component )
        {
          case 0: return "SSCALED";
          case 1: return "SSCALED";
          case 2: return "SSCALED";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Uint:
        switch ( component )
        {
          case 0: return "UINT";
          case 1: return "UINT";
          case 2: return "UINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Sint:
        switch ( component )
        {
          case 0: return "SINT";
          case 1: return "SINT";
          case 2: return "SINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Sfloat:
        switch ( component )
        {
          case 0: return "SFLOAT";
          case 1: return "SFLOAT";
          case 2: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Snorm:
        switch ( component )
        {
          case 0: return "SNORM";
          case 1: return "SNORM";
          case 2: return "SNORM";
          case 3: return "SNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Uscaled:
        switch ( component )
        {
          case 0: return "USCALED";
          case 1: return "USCALED";
          case 2: return "USCALED";
          case 3: return "USCALED";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Sscaled:
        switch ( component )
        {
          case 0: return "SSCALED";
          case 1: return "SSCALED";
          case 2: return "SSCALED";
          case 3: return "SSCALED";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Uint:
        switch ( component )
        {
          case 0: return "UINT";
          case 1: return "UINT";
          case 2: return "UINT";
          case 3: return "UINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Sint:
        switch ( component )
        {
          case 0: return "SINT";
          case 1: return "SINT";
          case 2: return "SINT";
          case 3: return "SINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Sfloat:
        switch ( component )
        {
          case 0: return "SFLOAT";
          case 1: return "SFLOAT";
          case 2: return "SFLOAT";
          case 3: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32Uint:
        switch ( component )
        {
          case 0: return "UINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32Sint:
        switch ( component )
        {
          case 0: return "SINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32Sfloat:
        switch ( component )
        {
          case 0: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32Uint:
        switch ( component )
        {
          case 0: return "UINT";
          case 1: return "UINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32Sint:
        switch ( component )
        {
          case 0: return "SINT";
          case 1: return "SINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32Sfloat:
        switch ( component )
        {
          case 0: return "SFLOAT";
          case 1: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32Uint:
        switch ( component )
        {
          case 0: return "UINT";
          case 1: return "UINT";
          case 2: return "UINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32Sint:
        switch ( component )
        {
          case 0: return "SINT";
          case 1: return "SINT";
          case 2: return "SINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32Sfloat:
        switch ( component )
        {
          case 0: return "SFLOAT";
          case 1: return "SFLOAT";
          case 2: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32A32Uint:
        switch ( component )
        {
          case 0: return "UINT";
          case 1: return "UINT";
          case 2: return "UINT";
          case 3: return "UINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32A32Sint:
        switch ( component )
        {
          case 0: return "SINT";
          case 1: return "SINT";
          case 2: return "SINT";
          case 3: return "SINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32A32Sfloat:
        switch ( component )
        {
          case 0: return "SFLOAT";
          case 1: return "SFLOAT";
          case 2: return "SFLOAT";
          case 3: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64Uint:
        switch ( component )
        {
          case 0: return "UINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64Sint:
        switch ( component )
        {
          case 0: return "SINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64Sfloat:
        switch ( component )
        {
          case 0: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64Uint:
        switch ( component )
        {
          case 0: return "UINT";
          case 1: return "UINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64Sint:
        switch ( component )
        {
          case 0: return "SINT";
          case 1: return "SINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64Sfloat:
        switch ( component )
        {
          case 0: return "SFLOAT";
          case 1: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64Uint:
        switch ( component )
        {
          case 0: return "UINT";
          case 1: return "UINT";
          case 2: return "UINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64Sint:
        switch ( component )
        {
          case 0: return "SINT";
          case 1: return "SINT";
          case 2: return "SINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64Sfloat:
        switch ( component )
        {
          case 0: return "SFLOAT";
          case 1: return "SFLOAT";
          case 2: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64A64Uint:
        switch ( component )
        {
          case 0: return "UINT";
          case 1: return "UINT";
          case 2: return "UINT";
          case 3: return "UINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64A64Sint:
        switch ( component )
        {
          case 0: return "SINT";
          case 1: return "SINT";
          case 2: return "SINT";
          case 3: return "SINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64A64Sfloat:
        switch ( component )
        {
          case 0: return "SFLOAT";
          case 1: return "SFLOAT";
          case 2: return "SFLOAT";
          case 3: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB10G11R11UfloatPack32:
        switch ( component )
        {
          case 0: return "UFLOAT";
          case 1: return "UFLOAT";
          case 2: return "UFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eE5B9G9R9UfloatPack32:
        switch ( component )
        {
          case 0: return "UFLOAT";
          case 1: return "UFLOAT";
          case 2: return "UFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eD16Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eX8D24UnormPack32:
        switch ( component )
        {
          case 0: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eD32Sfloat:
        switch ( component )
        {
          case 0: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eS8Uint:
        switch ( component )
        {
          case 0: return "UINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eD16UnormS8Uint:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eD24UnormS8Uint:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eD32SfloatS8Uint:
        switch ( component )
        {
          case 0: return "SFLOAT";
          case 1: return "UINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbUnormBlock:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbSrgbBlock:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbaUnormBlock:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbaSrgbBlock:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc2UnormBlock:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc2SrgbBlock:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc3UnormBlock:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc3SrgbBlock:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc4UnormBlock:
        switch ( component )
        {
          case 0: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc4SnormBlock:
        switch ( component )
        {
          case 0: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc5UnormBlock:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc5SnormBlock:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc6HUfloatBlock:
        switch ( component )
        {
          case 0: return "UFLOAT";
          case 1: return "UFLOAT";
          case 2: return "UFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc6HSfloatBlock:
        switch ( component )
        {
          case 0: return "SFLOAT";
          case 1: return "SFLOAT";
          case 2: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc7UnormBlock:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eBc7SrgbBlock:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8UnormBlock:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8SrgbBlock:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A1UnormBlock:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A1SrgbBlock:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A8UnormBlock:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A8SrgbBlock:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eEacR11UnormBlock:
        switch ( component )
        {
          case 0: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eEacR11SnormBlock:
        switch ( component )
        {
          case 0: return "SNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eEacR11G11UnormBlock:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eEacR11G11SnormBlock:
        switch ( component )
        {
          case 0: return "SNORM";
          case 1: return "SNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4UnormBlock:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4SrgbBlock:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4UnormBlock:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4SrgbBlock:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5UnormBlock:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5SrgbBlock:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5UnormBlock:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5SrgbBlock:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6UnormBlock:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6SrgbBlock:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5UnormBlock:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5SrgbBlock:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6UnormBlock:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6SrgbBlock:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8UnormBlock:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8SrgbBlock:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5UnormBlock:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5SrgbBlock:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6UnormBlock:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6SrgbBlock:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8UnormBlock:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8SrgbBlock:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10UnormBlock:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10SrgbBlock:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10UnormBlock:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10SrgbBlock:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12UnormBlock:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12SrgbBlock:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8G8R8422Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8G8422Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane420Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane420Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane422Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane422Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane444Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR10X6UnormPack16:
        switch ( component )
        {
          case 0: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR10X6G10X6Unorm2Pack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR10X6G10X6B10X6A10X6Unorm4Pack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6G10X6R10X6422Unorm4Pack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB10X6G10X6R10X6G10X6422Unorm4Pack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane420Unorm3Pack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane420Unorm3Pack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane422Unorm3Pack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane422Unorm3Pack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane444Unorm3Pack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR12X4UnormPack16:
        switch ( component )
        {
          case 0: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR12X4G12X4Unorm2Pack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR12X4G12X4B12X4A12X4Unorm4Pack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4G12X4R12X4422Unorm4Pack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB12X4G12X4R12X4G12X4422Unorm4Pack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane420Unorm3Pack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane420Unorm3Pack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane422Unorm3Pack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane422Unorm3Pack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane444Unorm3Pack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16G16R16422Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eB16G16R16G16422Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane420Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane420Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane422Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane422Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane444Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane444Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane444Unorm3Pack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane444Unorm3Pack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane444Unorm:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA4R4G4B4UnormPack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eA4B4G4R4UnormPack16:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4SfloatBlock:
        switch ( component )
        {
          case 0: return "SFLOAT";
          case 1: return "SFLOAT";
          case 2: return "SFLOAT";
          case 3: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4SfloatBlock:
        switch ( component )
        {
          case 0: return "SFLOAT";
          case 1: return "SFLOAT";
          case 2: return "SFLOAT";
          case 3: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5SfloatBlock:
        switch ( component )
        {
          case 0: return "SFLOAT";
          case 1: return "SFLOAT";
          case 2: return "SFLOAT";
          case 3: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5SfloatBlock:
        switch ( component )
        {
          case 0: return "SFLOAT";
          case 1: return "SFLOAT";
          case 2: return "SFLOAT";
          case 3: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6SfloatBlock:
        switch ( component )
        {
          case 0: return "SFLOAT";
          case 1: return "SFLOAT";
          case 2: return "SFLOAT";
          case 3: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5SfloatBlock:
        switch ( component )
        {
          case 0: return "SFLOAT";
          case 1: return "SFLOAT";
          case 2: return "SFLOAT";
          case 3: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6SfloatBlock:
        switch ( component )
        {
          case 0: return "SFLOAT";
          case 1: return "SFLOAT";
          case 2: return "SFLOAT";
          case 3: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8SfloatBlock:
        switch ( component )
        {
          case 0: return "SFLOAT";
          case 1: return "SFLOAT";
          case 2: return "SFLOAT";
          case 3: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5SfloatBlock:
        switch ( component )
        {
          case 0: return "SFLOAT";
          case 1: return "SFLOAT";
          case 2: return "SFLOAT";
          case 3: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6SfloatBlock:
        switch ( component )
        {
          case 0: return "SFLOAT";
          case 1: return "SFLOAT";
          case 2: return "SFLOAT";
          case 3: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8SfloatBlock:
        switch ( component )
        {
          case 0: return "SFLOAT";
          case 1: return "SFLOAT";
          case 2: return "SFLOAT";
          case 3: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10SfloatBlock:
        switch ( component )
        {
          case 0: return "SFLOAT";
          case 1: return "SFLOAT";
          case 2: return "SFLOAT";
          case 3: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10SfloatBlock:
        switch ( component )
        {
          case 0: return "SFLOAT";
          case 1: return "SFLOAT";
          case 2: return "SFLOAT";
          case 3: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12SfloatBlock:
        switch ( component )
        {
          case 0: return "SFLOAT";
          case 1: return "SFLOAT";
          case 2: return "SFLOAT";
          case 3: return "SFLOAT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc12BppUnormBlockIMG:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc14BppUnormBlockIMG:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc22BppUnormBlockIMG:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc24BppUnormBlockIMG:
        switch ( component )
        {
          case 0: return "UNORM";
          case 1: return "UNORM";
          case 2: return "UNORM";
          case 3: return "UNORM";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc12BppSrgbBlockIMG:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc14BppSrgbBlockIMG:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc22BppSrgbBlockIMG:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc24BppSrgbBlockIMG:
        switch ( component )
        {
          case 0: return "SRGB";
          case 1: return "SRGB";
          case 2: return "SRGB";
          case 3: return "SRGB";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }
      case VULKAN_HPP_NAMESPACE::Format::eR16G16S105NV:
        switch ( component )
        {
          case 0: return "SINT";
          case 1: return "SINT";
          default: VULKAN_HPP_ASSERT( false ); return "";
        }

      default: return "";
    }
  }

  // The plane this component lies in.
  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR_14 uint8_t componentPlaneIndex( VULKAN_HPP_NAMESPACE::Format format, uint8_t component )
  {
    switch ( format )
    {
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane420Unorm:
        switch ( component )
        {
          case 0: return 0;
          case 1: return 1;
          case 2: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane420Unorm:
        switch ( component )
        {
          case 0: return 0;
          case 1: return 1;
          case 2: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane422Unorm:
        switch ( component )
        {
          case 0: return 0;
          case 1: return 1;
          case 2: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane422Unorm:
        switch ( component )
        {
          case 0: return 0;
          case 1: return 1;
          case 2: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane444Unorm:
        switch ( component )
        {
          case 0: return 0;
          case 1: return 1;
          case 2: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane420Unorm3Pack16:
        switch ( component )
        {
          case 0: return 0;
          case 1: return 1;
          case 2: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane420Unorm3Pack16:
        switch ( component )
        {
          case 0: return 0;
          case 1: return 1;
          case 2: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane422Unorm3Pack16:
        switch ( component )
        {
          case 0: return 0;
          case 1: return 1;
          case 2: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane422Unorm3Pack16:
        switch ( component )
        {
          case 0: return 0;
          case 1: return 1;
          case 2: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane444Unorm3Pack16:
        switch ( component )
        {
          case 0: return 0;
          case 1: return 1;
          case 2: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane420Unorm3Pack16:
        switch ( component )
        {
          case 0: return 0;
          case 1: return 1;
          case 2: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane420Unorm3Pack16:
        switch ( component )
        {
          case 0: return 0;
          case 1: return 1;
          case 2: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane422Unorm3Pack16:
        switch ( component )
        {
          case 0: return 0;
          case 1: return 1;
          case 2: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane422Unorm3Pack16:
        switch ( component )
        {
          case 0: return 0;
          case 1: return 1;
          case 2: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane444Unorm3Pack16:
        switch ( component )
        {
          case 0: return 0;
          case 1: return 1;
          case 2: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane420Unorm:
        switch ( component )
        {
          case 0: return 0;
          case 1: return 1;
          case 2: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane420Unorm:
        switch ( component )
        {
          case 0: return 0;
          case 1: return 1;
          case 2: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane422Unorm:
        switch ( component )
        {
          case 0: return 0;
          case 1: return 1;
          case 2: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane422Unorm:
        switch ( component )
        {
          case 0: return 0;
          case 1: return 1;
          case 2: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane444Unorm:
        switch ( component )
        {
          case 0: return 0;
          case 1: return 1;
          case 2: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane444Unorm:
        switch ( component )
        {
          case 0: return 0;
          case 1: return 1;
          case 2: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane444Unorm3Pack16:
        switch ( component )
        {
          case 0: return 0;
          case 1: return 1;
          case 2: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane444Unorm3Pack16:
        switch ( component )
        {
          case 0: return 0;
          case 1: return 1;
          case 2: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane444Unorm:
        switch ( component )
        {
          case 0: return 0;
          case 1: return 1;
          case 2: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 0;
        }

      default: return 0;
    }
  }

  // True, if the components of this format are compressed, otherwise false.
  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR_14 bool componentsAreCompressed( VULKAN_HPP_NAMESPACE::Format format )
  {
    switch ( format )
    {
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbUnormBlock:
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbSrgbBlock:
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbaUnormBlock:
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbaSrgbBlock:
      case VULKAN_HPP_NAMESPACE::Format::eBc2UnormBlock:
      case VULKAN_HPP_NAMESPACE::Format::eBc2SrgbBlock:
      case VULKAN_HPP_NAMESPACE::Format::eBc3UnormBlock:
      case VULKAN_HPP_NAMESPACE::Format::eBc3SrgbBlock:
      case VULKAN_HPP_NAMESPACE::Format::eBc4UnormBlock:
      case VULKAN_HPP_NAMESPACE::Format::eBc4SnormBlock:
      case VULKAN_HPP_NAMESPACE::Format::eBc5UnormBlock:
      case VULKAN_HPP_NAMESPACE::Format::eBc5SnormBlock:
      case VULKAN_HPP_NAMESPACE::Format::eBc6HUfloatBlock:
      case VULKAN_HPP_NAMESPACE::Format::eBc6HSfloatBlock:
      case VULKAN_HPP_NAMESPACE::Format::eBc7UnormBlock:
      case VULKAN_HPP_NAMESPACE::Format::eBc7SrgbBlock:
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8UnormBlock:
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8SrgbBlock:
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A1UnormBlock:
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A1SrgbBlock:
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A8UnormBlock:
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A8SrgbBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4UnormBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4SrgbBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4UnormBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4SrgbBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5UnormBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5SrgbBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5UnormBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5SrgbBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6UnormBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6SrgbBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5UnormBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5SrgbBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6UnormBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6SrgbBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8UnormBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8SrgbBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5UnormBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5SrgbBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6UnormBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6SrgbBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8UnormBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8SrgbBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10UnormBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10SrgbBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10UnormBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10SrgbBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12UnormBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12SrgbBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4SfloatBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4SfloatBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5SfloatBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5SfloatBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6SfloatBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5SfloatBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6SfloatBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8SfloatBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5SfloatBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6SfloatBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8SfloatBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10SfloatBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10SfloatBlock:
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12SfloatBlock:
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc12BppUnormBlockIMG:
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc14BppUnormBlockIMG:
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc22BppUnormBlockIMG:
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc24BppUnormBlockIMG:
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc12BppSrgbBlockIMG:
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc14BppSrgbBlockIMG:
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc22BppSrgbBlockIMG:
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc24BppSrgbBlockIMG: return true;
      default: return false;
    }
  }

  // A textual description of the compression scheme, or an empty string if it is not compressed
  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR_14 char const * compressionScheme( VULKAN_HPP_NAMESPACE::Format format )
  {
    switch ( format )
    {
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbUnormBlock: return "BC";
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbSrgbBlock: return "BC";
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbaUnormBlock: return "BC";
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbaSrgbBlock: return "BC";
      case VULKAN_HPP_NAMESPACE::Format::eBc2UnormBlock: return "BC";
      case VULKAN_HPP_NAMESPACE::Format::eBc2SrgbBlock: return "BC";
      case VULKAN_HPP_NAMESPACE::Format::eBc3UnormBlock: return "BC";
      case VULKAN_HPP_NAMESPACE::Format::eBc3SrgbBlock: return "BC";
      case VULKAN_HPP_NAMESPACE::Format::eBc4UnormBlock: return "BC";
      case VULKAN_HPP_NAMESPACE::Format::eBc4SnormBlock: return "BC";
      case VULKAN_HPP_NAMESPACE::Format::eBc5UnormBlock: return "BC";
      case VULKAN_HPP_NAMESPACE::Format::eBc5SnormBlock: return "BC";
      case VULKAN_HPP_NAMESPACE::Format::eBc6HUfloatBlock: return "BC";
      case VULKAN_HPP_NAMESPACE::Format::eBc6HSfloatBlock: return "BC";
      case VULKAN_HPP_NAMESPACE::Format::eBc7UnormBlock: return "BC";
      case VULKAN_HPP_NAMESPACE::Format::eBc7SrgbBlock: return "BC";
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8UnormBlock: return "ETC2";
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8SrgbBlock: return "ETC2";
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A1UnormBlock: return "ETC2";
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A1SrgbBlock: return "ETC2";
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A8UnormBlock: return "ETC2";
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A8SrgbBlock: return "ETC2";
      case VULKAN_HPP_NAMESPACE::Format::eEacR11UnormBlock: return "EAC";
      case VULKAN_HPP_NAMESPACE::Format::eEacR11SnormBlock: return "EAC";
      case VULKAN_HPP_NAMESPACE::Format::eEacR11G11UnormBlock: return "EAC";
      case VULKAN_HPP_NAMESPACE::Format::eEacR11G11SnormBlock: return "EAC";
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4UnormBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4SrgbBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4UnormBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4SrgbBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5UnormBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5SrgbBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5UnormBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5SrgbBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6UnormBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6SrgbBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5UnormBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5SrgbBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6UnormBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6SrgbBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8UnormBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8SrgbBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5UnormBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5SrgbBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6UnormBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6SrgbBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8UnormBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8SrgbBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10UnormBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10SrgbBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10UnormBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10SrgbBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12UnormBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12SrgbBlock: return "ASTC LDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4SfloatBlock: return "ASTC HDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4SfloatBlock: return "ASTC HDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5SfloatBlock: return "ASTC HDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5SfloatBlock: return "ASTC HDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6SfloatBlock: return "ASTC HDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5SfloatBlock: return "ASTC HDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6SfloatBlock: return "ASTC HDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8SfloatBlock: return "ASTC HDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5SfloatBlock: return "ASTC HDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6SfloatBlock: return "ASTC HDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8SfloatBlock: return "ASTC HDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10SfloatBlock: return "ASTC HDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10SfloatBlock: return "ASTC HDR";
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12SfloatBlock: return "ASTC HDR";
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc12BppUnormBlockIMG: return "PVRTC";
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc14BppUnormBlockIMG: return "PVRTC";
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc22BppUnormBlockIMG: return "PVRTC";
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc24BppUnormBlockIMG: return "PVRTC";
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc12BppSrgbBlockIMG: return "PVRTC";
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc14BppSrgbBlockIMG: return "PVRTC";
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc22BppSrgbBlockIMG: return "PVRTC";
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc24BppSrgbBlockIMG: return "PVRTC";

      default: return "";
    }
  }

  // True, if this format is a compressed one.
  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR_14 bool isCompressed( VULKAN_HPP_NAMESPACE::Format format )
  {
    return ( *VULKAN_HPP_NAMESPACE::compressionScheme( format ) != 0 );
  }

  // The number of bits into which the format is packed. A single image element in this format
  // can be stored in the same space as a scalar type of this bit width.
  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR_14 uint8_t packed( VULKAN_HPP_NAMESPACE::Format format )
  {
    switch ( format )
    {
      case VULKAN_HPP_NAMESPACE::Format::eR4G4UnormPack8: return 8;
      case VULKAN_HPP_NAMESPACE::Format::eR4G4B4A4UnormPack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eB4G4R4A4UnormPack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eR5G6B5UnormPack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eB5G6R5UnormPack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eR5G5B5A1UnormPack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eB5G5R5A1UnormPack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eA1R5G5B5UnormPack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8UnormPack32: return 32;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SnormPack32: return 32;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8UscaledPack32: return 32;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SscaledPack32: return 32;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8UintPack32: return 32;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SintPack32: return 32;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SrgbPack32: return 32;
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10UnormPack32: return 32;
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10SnormPack32: return 32;
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10UscaledPack32: return 32;
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10SscaledPack32: return 32;
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10UintPack32: return 32;
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10SintPack32: return 32;
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10UnormPack32: return 32;
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10SnormPack32: return 32;
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10UscaledPack32: return 32;
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10SscaledPack32: return 32;
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10UintPack32: return 32;
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10SintPack32: return 32;
      case VULKAN_HPP_NAMESPACE::Format::eB10G11R11UfloatPack32: return 32;
      case VULKAN_HPP_NAMESPACE::Format::eE5B9G9R9UfloatPack32: return 32;
      case VULKAN_HPP_NAMESPACE::Format::eX8D24UnormPack32: return 32;
      case VULKAN_HPP_NAMESPACE::Format::eR10X6UnormPack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eR10X6G10X6Unorm2Pack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eR10X6G10X6B10X6A10X6Unorm4Pack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6G10X6R10X6422Unorm4Pack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eB10X6G10X6R10X6G10X6422Unorm4Pack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane420Unorm3Pack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane420Unorm3Pack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane422Unorm3Pack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane422Unorm3Pack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane444Unorm3Pack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eR12X4UnormPack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eR12X4G12X4Unorm2Pack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eR12X4G12X4B12X4A12X4Unorm4Pack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4G12X4R12X4422Unorm4Pack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eB12X4G12X4R12X4G12X4422Unorm4Pack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane420Unorm3Pack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane420Unorm3Pack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane422Unorm3Pack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane422Unorm3Pack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane444Unorm3Pack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane444Unorm3Pack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane444Unorm3Pack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eA4R4G4B4UnormPack16: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eA4B4G4R4UnormPack16: return 16;

      default: return 0;
    }
  }

  // The single-plane format that this plane is compatible with.
  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR_14 VULKAN_HPP_NAMESPACE::Format planeCompatibleFormat( VULKAN_HPP_NAMESPACE::Format format, uint8_t plane )
  {
    switch ( format )
    {
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane420Unorm:
        switch ( plane )
        {
          case 0: return VULKAN_HPP_NAMESPACE::Format::eR8Unorm;
          case 1: return VULKAN_HPP_NAMESPACE::Format::eR8Unorm;
          case 2: return VULKAN_HPP_NAMESPACE::Format::eR8Unorm;
          default: VULKAN_HPP_ASSERT( false ); return VULKAN_HPP_NAMESPACE::Format::eUndefined;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane420Unorm:
        switch ( plane )
        {
          case 0: return VULKAN_HPP_NAMESPACE::Format::eR8Unorm;
          case 1: return VULKAN_HPP_NAMESPACE::Format::eR8G8Unorm;
          default: VULKAN_HPP_ASSERT( false ); return VULKAN_HPP_NAMESPACE::Format::eUndefined;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane422Unorm:
        switch ( plane )
        {
          case 0: return VULKAN_HPP_NAMESPACE::Format::eR8Unorm;
          case 1: return VULKAN_HPP_NAMESPACE::Format::eR8Unorm;
          case 2: return VULKAN_HPP_NAMESPACE::Format::eR8Unorm;
          default: VULKAN_HPP_ASSERT( false ); return VULKAN_HPP_NAMESPACE::Format::eUndefined;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane422Unorm:
        switch ( plane )
        {
          case 0: return VULKAN_HPP_NAMESPACE::Format::eR8Unorm;
          case 1: return VULKAN_HPP_NAMESPACE::Format::eR8G8Unorm;
          default: VULKAN_HPP_ASSERT( false ); return VULKAN_HPP_NAMESPACE::Format::eUndefined;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane444Unorm:
        switch ( plane )
        {
          case 0: return VULKAN_HPP_NAMESPACE::Format::eR8Unorm;
          case 1: return VULKAN_HPP_NAMESPACE::Format::eR8Unorm;
          case 2: return VULKAN_HPP_NAMESPACE::Format::eR8Unorm;
          default: VULKAN_HPP_ASSERT( false ); return VULKAN_HPP_NAMESPACE::Format::eUndefined;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane420Unorm3Pack16:
        switch ( plane )
        {
          case 0: return VULKAN_HPP_NAMESPACE::Format::eR10X6UnormPack16;
          case 1: return VULKAN_HPP_NAMESPACE::Format::eR10X6UnormPack16;
          case 2: return VULKAN_HPP_NAMESPACE::Format::eR10X6UnormPack16;
          default: VULKAN_HPP_ASSERT( false ); return VULKAN_HPP_NAMESPACE::Format::eUndefined;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane420Unorm3Pack16:
        switch ( plane )
        {
          case 0: return VULKAN_HPP_NAMESPACE::Format::eR10X6UnormPack16;
          case 1: return VULKAN_HPP_NAMESPACE::Format::eR10X6G10X6Unorm2Pack16;
          default: VULKAN_HPP_ASSERT( false ); return VULKAN_HPP_NAMESPACE::Format::eUndefined;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane422Unorm3Pack16:
        switch ( plane )
        {
          case 0: return VULKAN_HPP_NAMESPACE::Format::eR10X6UnormPack16;
          case 1: return VULKAN_HPP_NAMESPACE::Format::eR10X6UnormPack16;
          case 2: return VULKAN_HPP_NAMESPACE::Format::eR10X6UnormPack16;
          default: VULKAN_HPP_ASSERT( false ); return VULKAN_HPP_NAMESPACE::Format::eUndefined;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane422Unorm3Pack16:
        switch ( plane )
        {
          case 0: return VULKAN_HPP_NAMESPACE::Format::eR10X6UnormPack16;
          case 1: return VULKAN_HPP_NAMESPACE::Format::eR10X6G10X6Unorm2Pack16;
          default: VULKAN_HPP_ASSERT( false ); return VULKAN_HPP_NAMESPACE::Format::eUndefined;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane444Unorm3Pack16:
        switch ( plane )
        {
          case 0: return VULKAN_HPP_NAMESPACE::Format::eR10X6UnormPack16;
          case 1: return VULKAN_HPP_NAMESPACE::Format::eR10X6UnormPack16;
          case 2: return VULKAN_HPP_NAMESPACE::Format::eR10X6UnormPack16;
          default: VULKAN_HPP_ASSERT( false ); return VULKAN_HPP_NAMESPACE::Format::eUndefined;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane420Unorm3Pack16:
        switch ( plane )
        {
          case 0: return VULKAN_HPP_NAMESPACE::Format::eR12X4UnormPack16;
          case 1: return VULKAN_HPP_NAMESPACE::Format::eR12X4UnormPack16;
          case 2: return VULKAN_HPP_NAMESPACE::Format::eR12X4UnormPack16;
          default: VULKAN_HPP_ASSERT( false ); return VULKAN_HPP_NAMESPACE::Format::eUndefined;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane420Unorm3Pack16:
        switch ( plane )
        {
          case 0: return VULKAN_HPP_NAMESPACE::Format::eR12X4UnormPack16;
          case 1: return VULKAN_HPP_NAMESPACE::Format::eR12X4G12X4Unorm2Pack16;
          default: VULKAN_HPP_ASSERT( false ); return VULKAN_HPP_NAMESPACE::Format::eUndefined;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane422Unorm3Pack16:
        switch ( plane )
        {
          case 0: return VULKAN_HPP_NAMESPACE::Format::eR12X4UnormPack16;
          case 1: return VULKAN_HPP_NAMESPACE::Format::eR12X4UnormPack16;
          case 2: return VULKAN_HPP_NAMESPACE::Format::eR12X4UnormPack16;
          default: VULKAN_HPP_ASSERT( false ); return VULKAN_HPP_NAMESPACE::Format::eUndefined;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane422Unorm3Pack16:
        switch ( plane )
        {
          case 0: return VULKAN_HPP_NAMESPACE::Format::eR12X4UnormPack16;
          case 1: return VULKAN_HPP_NAMESPACE::Format::eR12X4G12X4Unorm2Pack16;
          default: VULKAN_HPP_ASSERT( false ); return VULKAN_HPP_NAMESPACE::Format::eUndefined;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane444Unorm3Pack16:
        switch ( plane )
        {
          case 0: return VULKAN_HPP_NAMESPACE::Format::eR12X4UnormPack16;
          case 1: return VULKAN_HPP_NAMESPACE::Format::eR12X4UnormPack16;
          case 2: return VULKAN_HPP_NAMESPACE::Format::eR12X4UnormPack16;
          default: VULKAN_HPP_ASSERT( false ); return VULKAN_HPP_NAMESPACE::Format::eUndefined;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane420Unorm:
        switch ( plane )
        {
          case 0: return VULKAN_HPP_NAMESPACE::Format::eR16Unorm;
          case 1: return VULKAN_HPP_NAMESPACE::Format::eR16Unorm;
          case 2: return VULKAN_HPP_NAMESPACE::Format::eR16Unorm;
          default: VULKAN_HPP_ASSERT( false ); return VULKAN_HPP_NAMESPACE::Format::eUndefined;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane420Unorm:
        switch ( plane )
        {
          case 0: return VULKAN_HPP_NAMESPACE::Format::eR16Unorm;
          case 1: return VULKAN_HPP_NAMESPACE::Format::eR16G16Unorm;
          default: VULKAN_HPP_ASSERT( false ); return VULKAN_HPP_NAMESPACE::Format::eUndefined;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane422Unorm:
        switch ( plane )
        {
          case 0: return VULKAN_HPP_NAMESPACE::Format::eR16Unorm;
          case 1: return VULKAN_HPP_NAMESPACE::Format::eR16Unorm;
          case 2: return VULKAN_HPP_NAMESPACE::Format::eR16Unorm;
          default: VULKAN_HPP_ASSERT( false ); return VULKAN_HPP_NAMESPACE::Format::eUndefined;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane422Unorm:
        switch ( plane )
        {
          case 0: return VULKAN_HPP_NAMESPACE::Format::eR16Unorm;
          case 1: return VULKAN_HPP_NAMESPACE::Format::eR16G16Unorm;
          default: VULKAN_HPP_ASSERT( false ); return VULKAN_HPP_NAMESPACE::Format::eUndefined;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane444Unorm:
        switch ( plane )
        {
          case 0: return VULKAN_HPP_NAMESPACE::Format::eR16Unorm;
          case 1: return VULKAN_HPP_NAMESPACE::Format::eR16Unorm;
          case 2: return VULKAN_HPP_NAMESPACE::Format::eR16Unorm;
          default: VULKAN_HPP_ASSERT( false ); return VULKAN_HPP_NAMESPACE::Format::eUndefined;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane444Unorm:
        switch ( plane )
        {
          case 0: return VULKAN_HPP_NAMESPACE::Format::eR8Unorm;
          case 1: return VULKAN_HPP_NAMESPACE::Format::eR8G8Unorm;
          default: VULKAN_HPP_ASSERT( false ); return VULKAN_HPP_NAMESPACE::Format::eUndefined;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane444Unorm3Pack16:
        switch ( plane )
        {
          case 0: return VULKAN_HPP_NAMESPACE::Format::eR10X6UnormPack16;
          case 1: return VULKAN_HPP_NAMESPACE::Format::eR10X6G10X6Unorm2Pack16;
          default: VULKAN_HPP_ASSERT( false ); return VULKAN_HPP_NAMESPACE::Format::eUndefined;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane444Unorm3Pack16:
        switch ( plane )
        {
          case 0: return VULKAN_HPP_NAMESPACE::Format::eR12X4UnormPack16;
          case 1: return VULKAN_HPP_NAMESPACE::Format::eR12X4G12X4Unorm2Pack16;
          default: VULKAN_HPP_ASSERT( false ); return VULKAN_HPP_NAMESPACE::Format::eUndefined;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane444Unorm:
        switch ( plane )
        {
          case 0: return VULKAN_HPP_NAMESPACE::Format::eR16Unorm;
          case 1: return VULKAN_HPP_NAMESPACE::Format::eR16G16Unorm;
          default: VULKAN_HPP_ASSERT( false ); return VULKAN_HPP_NAMESPACE::Format::eUndefined;
        }

      default: VULKAN_HPP_ASSERT( plane == 0 ); return format;
    }
  }

  // The number of image planes of this format.
  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR_14 uint8_t planeCount( VULKAN_HPP_NAMESPACE::Format format )
  {
    switch ( format )
    {
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane420Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane420Unorm: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane422Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane422Unorm: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane444Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane420Unorm3Pack16: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane420Unorm3Pack16: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane422Unorm3Pack16: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane422Unorm3Pack16: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane444Unorm3Pack16: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane420Unorm3Pack16: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane420Unorm3Pack16: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane422Unorm3Pack16: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane422Unorm3Pack16: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane444Unorm3Pack16: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane420Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane420Unorm: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane422Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane422Unorm: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane444Unorm: return 3;
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane444Unorm: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane444Unorm3Pack16: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane444Unorm3Pack16: return 2;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane444Unorm: return 2;

      default: return 1;
    }
  }

  // The relative height of this plane. A value of k means that this plane is 1/k the height of the overall format.
  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR_14 uint8_t planeHeightDivisor( VULKAN_HPP_NAMESPACE::Format format, uint8_t plane )
  {
    switch ( format )
    {
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane420Unorm:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 2;
          case 2: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane420Unorm:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane422Unorm:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 1;
          case 2: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane422Unorm:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane444Unorm:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 1;
          case 2: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane420Unorm3Pack16:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 2;
          case 2: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane420Unorm3Pack16:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane422Unorm3Pack16:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 1;
          case 2: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane422Unorm3Pack16:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane444Unorm3Pack16:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 1;
          case 2: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane420Unorm3Pack16:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 2;
          case 2: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane420Unorm3Pack16:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane422Unorm3Pack16:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 1;
          case 2: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane422Unorm3Pack16:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane444Unorm3Pack16:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 1;
          case 2: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane420Unorm:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 2;
          case 2: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane420Unorm:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane422Unorm:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 1;
          case 2: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane422Unorm:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane444Unorm:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 1;
          case 2: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane444Unorm:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane444Unorm3Pack16:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane444Unorm3Pack16:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane444Unorm:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }

      default: VULKAN_HPP_ASSERT( plane == 0 ); return 1;
    }
  }

  // The relative width of this plane. A value of k means that this plane is 1/k the width of the overall format.
  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR_14 uint8_t planeWidthDivisor( VULKAN_HPP_NAMESPACE::Format format, uint8_t plane )
  {
    switch ( format )
    {
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane420Unorm:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 2;
          case 2: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane420Unorm:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane422Unorm:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 2;
          case 2: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane422Unorm:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane444Unorm:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 1;
          case 2: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane420Unorm3Pack16:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 2;
          case 2: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane420Unorm3Pack16:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane422Unorm3Pack16:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 2;
          case 2: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane422Unorm3Pack16:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane444Unorm3Pack16:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 1;
          case 2: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane420Unorm3Pack16:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 2;
          case 2: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane420Unorm3Pack16:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane422Unorm3Pack16:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 2;
          case 2: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane422Unorm3Pack16:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane444Unorm3Pack16:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 1;
          case 2: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane420Unorm:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 2;
          case 2: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane420Unorm:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane422Unorm:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 2;
          case 2: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane422Unorm:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 2;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane444Unorm:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 1;
          case 2: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane444Unorm:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane444Unorm3Pack16:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane444Unorm3Pack16:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane444Unorm:
        switch ( plane )
        {
          case 0: return 1;
          case 1: return 1;
          default: VULKAN_HPP_ASSERT( false ); return 1;
        }

      default: VULKAN_HPP_ASSERT( plane == 0 ); return 1;
    }
  }

  // The number of texels in a texel block.
  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR_14 uint8_t texelsPerBlock( VULKAN_HPP_NAMESPACE::Format format )
  {
    switch ( format )
    {
      case VULKAN_HPP_NAMESPACE::Format::eR4G4UnormPack8: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR4G4B4A4UnormPack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eB4G4R4A4UnormPack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR5G6B5UnormPack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eB5G6R5UnormPack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR5G5B5A1UnormPack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eB5G5R5A1UnormPack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eA1R5G5B5UnormPack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8Snorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8Uscaled: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8Sscaled: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8Sint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8Srgb: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Snorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Uscaled: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Sscaled: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Sint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8Srgb: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Snorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Uscaled: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Sscaled: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Sint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8Srgb: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Snorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Uscaled: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Sscaled: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Sint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8Srgb: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Snorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Uscaled: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Sscaled: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Sint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR8G8B8A8Srgb: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Snorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Uscaled: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Sscaled: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Sint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8A8Srgb: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8UnormPack32: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SnormPack32: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8UscaledPack32: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SscaledPack32: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8UintPack32: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SintPack32: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eA8B8G8R8SrgbPack32: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10UnormPack32: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10SnormPack32: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10UscaledPack32: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10SscaledPack32: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10UintPack32: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eA2R10G10B10SintPack32: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10UnormPack32: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10SnormPack32: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10UscaledPack32: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10SscaledPack32: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10UintPack32: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eA2B10G10R10SintPack32: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16Snorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16Uscaled: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16Sscaled: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16Sint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16Sfloat: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Snorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Uscaled: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Sscaled: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Sint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16Sfloat: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Snorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Uscaled: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Sscaled: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Sint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16Sfloat: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Snorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Uscaled: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Sscaled: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Sint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16B16A16Sfloat: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR32Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR32Sint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR32Sfloat: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32Sint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32Sfloat: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32Sint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32Sfloat: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32A32Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32A32Sint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR32G32B32A32Sfloat: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR64Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR64Sint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR64Sfloat: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64Sint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64Sfloat: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64Sint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64Sfloat: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64A64Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64A64Sint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR64G64B64A64Sfloat: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eB10G11R11UfloatPack32: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eE5B9G9R9UfloatPack32: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eD16Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eX8D24UnormPack32: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eD32Sfloat: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eS8Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eD16UnormS8Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eD24UnormS8Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eD32SfloatS8Uint: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbUnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbSrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbaUnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eBc1RgbaSrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eBc2UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eBc2SrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eBc3UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eBc3SrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eBc4UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eBc4SnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eBc5UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eBc5SnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eBc6HUfloatBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eBc6HSfloatBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eBc7UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eBc7SrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8SrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A1UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A1SrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A8UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eEtc2R8G8B8A8SrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eEacR11UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eEacR11SnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eEacR11G11UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eEacR11G11SnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4UnormBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4SrgbBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4UnormBlock: return 20;
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4SrgbBlock: return 20;
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5UnormBlock: return 25;
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5SrgbBlock: return 25;
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5UnormBlock: return 30;
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5SrgbBlock: return 30;
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6UnormBlock: return 36;
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6SrgbBlock: return 36;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5UnormBlock: return 40;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5SrgbBlock: return 40;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6UnormBlock: return 48;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6SrgbBlock: return 48;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8UnormBlock: return 64;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8SrgbBlock: return 64;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5UnormBlock: return 50;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5SrgbBlock: return 50;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6UnormBlock: return 60;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6SrgbBlock: return 60;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8UnormBlock: return 80;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8SrgbBlock: return 80;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10UnormBlock: return 100;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10SrgbBlock: return 100;
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10UnormBlock: return 120;
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10SrgbBlock: return 120;
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12UnormBlock: return 144;
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12SrgbBlock: return 144;
      case VULKAN_HPP_NAMESPACE::Format::eG8B8G8R8422Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eB8G8R8G8422Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane420Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane420Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane422Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane422Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R83Plane444Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR10X6UnormPack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR10X6G10X6Unorm2Pack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR10X6G10X6B10X6A10X6Unorm4Pack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6G10X6R10X6422Unorm4Pack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eB10X6G10X6R10X6G10X6422Unorm4Pack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane420Unorm3Pack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane420Unorm3Pack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane422Unorm3Pack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane422Unorm3Pack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X63Plane444Unorm3Pack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR12X4UnormPack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR12X4G12X4Unorm2Pack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR12X4G12X4B12X4A12X4Unorm4Pack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4G12X4R12X4422Unorm4Pack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eB12X4G12X4R12X4G12X4422Unorm4Pack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane420Unorm3Pack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane420Unorm3Pack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane422Unorm3Pack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane422Unorm3Pack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X43Plane444Unorm3Pack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16G16R16422Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eB16G16R16G16422Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane420Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane420Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane422Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane422Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R163Plane444Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG8B8R82Plane444Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG10X6B10X6R10X62Plane444Unorm3Pack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG12X4B12X4R12X42Plane444Unorm3Pack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eG16B16R162Plane444Unorm: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eA4R4G4B4UnormPack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eA4B4G4R4UnormPack16: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eAstc4x4SfloatBlock: return 16;
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x4SfloatBlock: return 20;
      case VULKAN_HPP_NAMESPACE::Format::eAstc5x5SfloatBlock: return 25;
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x5SfloatBlock: return 30;
      case VULKAN_HPP_NAMESPACE::Format::eAstc6x6SfloatBlock: return 36;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x5SfloatBlock: return 40;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x6SfloatBlock: return 48;
      case VULKAN_HPP_NAMESPACE::Format::eAstc8x8SfloatBlock: return 64;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x5SfloatBlock: return 50;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x6SfloatBlock: return 60;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x8SfloatBlock: return 80;
      case VULKAN_HPP_NAMESPACE::Format::eAstc10x10SfloatBlock: return 100;
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x10SfloatBlock: return 120;
      case VULKAN_HPP_NAMESPACE::Format::eAstc12x12SfloatBlock: return 144;
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc12BppUnormBlockIMG: return 1;
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc14BppUnormBlockIMG: return 1;
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc22BppUnormBlockIMG: return 1;
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc24BppUnormBlockIMG: return 1;
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc12BppSrgbBlockIMG: return 1;
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc14BppSrgbBlockIMG: return 1;
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc22BppSrgbBlockIMG: return 1;
      case VULKAN_HPP_NAMESPACE::Format::ePvrtc24BppSrgbBlockIMG: return 1;
      case VULKAN_HPP_NAMESPACE::Format::eR16G16S105NV: return 1;

      default: VULKAN_HPP_ASSERT( false ); return 0;
    }
  }

}  // namespace VULKAN_HPP_NAMESPACE
