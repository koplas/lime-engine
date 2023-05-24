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

export module vulkan:result;

import :base;
import :enums;
import :string;

#ifndef VULKAN_HPP_NO_EXCEPTIONS
namespace std
{
  template <>
  struct is_error_code_enum<VULKAN_HPP_NAMESPACE::Result> : public true_type
  {
  };
}  // namespace std
#endif

#ifndef VULKAN_HPP_NO_EXCEPTIONS
export namespace VULKAN_HPP_NAMESPACE
{
  class ErrorCategoryImpl : public std::error_category
  {
  public:
    virtual const char * name() const VULKAN_HPP_NOEXCEPT override
    {
      return VULKAN_HPP_NAMESPACE_STRING "::Result";
    }

    virtual std::string message( int ev ) const override
    {
#  if defined( VULKAN_HPP_NO_TO_STRING )
      return std::to_string( ev );
#  else
      return VULKAN_HPP_NAMESPACE::to_string( static_cast<VULKAN_HPP_NAMESPACE::Result>( ev ) );
#  endif
    }
  };

  class Error
  {
  public:
    Error() VULKAN_HPP_NOEXCEPT                = default;
    Error( const Error & ) VULKAN_HPP_NOEXCEPT = default;
    virtual ~Error() VULKAN_HPP_NOEXCEPT       = default;

    virtual const char * what() const VULKAN_HPP_NOEXCEPT = 0;
  };

  class LogicError
    : public Error
    , public std::logic_error
  {
  public:
    explicit LogicError( const std::string & what ) : Error(), std::logic_error( what ) {}

    explicit LogicError( char const * what ) : Error(), std::logic_error( what ) {}

    virtual const char * what() const VULKAN_HPP_NOEXCEPT
    {
      return std::logic_error::what();
    }
  };

  class SystemError
    : public Error
    , public std::system_error
  {
  public:
    SystemError( std::error_code ec ) : Error(), std::system_error( ec ) {}

    SystemError( std::error_code ec, std::string const & what ) : Error(), std::system_error( ec, what ) {}

    SystemError( std::error_code ec, char const * what ) : Error(), std::system_error( ec, what ) {}

    SystemError( int ev, std::error_category const & ecat ) : Error(), std::system_error( ev, ecat ) {}

    SystemError( int ev, std::error_category const & ecat, std::string const & what ) : Error(), std::system_error( ev, ecat, what ) {}

    SystemError( int ev, std::error_category const & ecat, char const * what ) : Error(), std::system_error( ev, ecat, what ) {}

    virtual const char * what() const VULKAN_HPP_NOEXCEPT
    {
      return std::system_error::what();
    }
  };

  VULKAN_HPP_INLINE const std::error_category & errorCategory() VULKAN_HPP_NOEXCEPT
  {
    static ErrorCategoryImpl instance;
    return instance;
  }

  VULKAN_HPP_INLINE std::error_code make_error_code( Result e ) VULKAN_HPP_NOEXCEPT
  {
    return std::error_code( static_cast<int>( e ), errorCategory() );
  }

  VULKAN_HPP_INLINE std::error_condition make_error_condition( Result e ) VULKAN_HPP_NOEXCEPT
  {
    return std::error_condition( static_cast<int>( e ), errorCategory() );
  }

  class OutOfHostMemoryError : public SystemError
  {
  public:
    OutOfHostMemoryError( std::string const & message ) : SystemError( make_error_code( Result::eErrorOutOfHostMemory ), message ) {}

    OutOfHostMemoryError( char const * message ) : SystemError( make_error_code( Result::eErrorOutOfHostMemory ), message ) {}
  };

  class OutOfDeviceMemoryError : public SystemError
  {
  public:
    OutOfDeviceMemoryError( std::string const & message ) : SystemError( make_error_code( Result::eErrorOutOfDeviceMemory ), message ) {}

    OutOfDeviceMemoryError( char const * message ) : SystemError( make_error_code( Result::eErrorOutOfDeviceMemory ), message ) {}
  };

  class InitializationFailedError : public SystemError
  {
  public:
    InitializationFailedError( std::string const & message ) : SystemError( make_error_code( Result::eErrorInitializationFailed ), message ) {}

    InitializationFailedError( char const * message ) : SystemError( make_error_code( Result::eErrorInitializationFailed ), message ) {}
  };

  class DeviceLostError : public SystemError
  {
  public:
    DeviceLostError( std::string const & message ) : SystemError( make_error_code( Result::eErrorDeviceLost ), message ) {}

    DeviceLostError( char const * message ) : SystemError( make_error_code( Result::eErrorDeviceLost ), message ) {}
  };

  class MemoryMapFailedError : public SystemError
  {
  public:
    MemoryMapFailedError( std::string const & message ) : SystemError( make_error_code( Result::eErrorMemoryMapFailed ), message ) {}

    MemoryMapFailedError( char const * message ) : SystemError( make_error_code( Result::eErrorMemoryMapFailed ), message ) {}
  };

  class LayerNotPresentError : public SystemError
  {
  public:
    LayerNotPresentError( std::string const & message ) : SystemError( make_error_code( Result::eErrorLayerNotPresent ), message ) {}

    LayerNotPresentError( char const * message ) : SystemError( make_error_code( Result::eErrorLayerNotPresent ), message ) {}
  };

  class ExtensionNotPresentError : public SystemError
  {
  public:
    ExtensionNotPresentError( std::string const & message ) : SystemError( make_error_code( Result::eErrorExtensionNotPresent ), message ) {}

    ExtensionNotPresentError( char const * message ) : SystemError( make_error_code( Result::eErrorExtensionNotPresent ), message ) {}
  };

  class FeatureNotPresentError : public SystemError
  {
  public:
    FeatureNotPresentError( std::string const & message ) : SystemError( make_error_code( Result::eErrorFeatureNotPresent ), message ) {}

    FeatureNotPresentError( char const * message ) : SystemError( make_error_code( Result::eErrorFeatureNotPresent ), message ) {}
  };

  class IncompatibleDriverError : public SystemError
  {
  public:
    IncompatibleDriverError( std::string const & message ) : SystemError( make_error_code( Result::eErrorIncompatibleDriver ), message ) {}

    IncompatibleDriverError( char const * message ) : SystemError( make_error_code( Result::eErrorIncompatibleDriver ), message ) {}
  };

  class TooManyObjectsError : public SystemError
  {
  public:
    TooManyObjectsError( std::string const & message ) : SystemError( make_error_code( Result::eErrorTooManyObjects ), message ) {}

    TooManyObjectsError( char const * message ) : SystemError( make_error_code( Result::eErrorTooManyObjects ), message ) {}
  };

  class FormatNotSupportedError : public SystemError
  {
  public:
    FormatNotSupportedError( std::string const & message ) : SystemError( make_error_code( Result::eErrorFormatNotSupported ), message ) {}

    FormatNotSupportedError( char const * message ) : SystemError( make_error_code( Result::eErrorFormatNotSupported ), message ) {}
  };

  class FragmentedPoolError : public SystemError
  {
  public:
    FragmentedPoolError( std::string const & message ) : SystemError( make_error_code( Result::eErrorFragmentedPool ), message ) {}

    FragmentedPoolError( char const * message ) : SystemError( make_error_code( Result::eErrorFragmentedPool ), message ) {}
  };

  class UnknownError : public SystemError
  {
  public:
    UnknownError( std::string const & message ) : SystemError( make_error_code( Result::eErrorUnknown ), message ) {}

    UnknownError( char const * message ) : SystemError( make_error_code( Result::eErrorUnknown ), message ) {}
  };

  class OutOfPoolMemoryError : public SystemError
  {
  public:
    OutOfPoolMemoryError( std::string const & message ) : SystemError( make_error_code( Result::eErrorOutOfPoolMemory ), message ) {}

    OutOfPoolMemoryError( char const * message ) : SystemError( make_error_code( Result::eErrorOutOfPoolMemory ), message ) {}
  };

  class InvalidExternalHandleError : public SystemError
  {
  public:
    InvalidExternalHandleError( std::string const & message ) : SystemError( make_error_code( Result::eErrorInvalidExternalHandle ), message ) {}

    InvalidExternalHandleError( char const * message ) : SystemError( make_error_code( Result::eErrorInvalidExternalHandle ), message ) {}
  };

  class FragmentationError : public SystemError
  {
  public:
    FragmentationError( std::string const & message ) : SystemError( make_error_code( Result::eErrorFragmentation ), message ) {}

    FragmentationError( char const * message ) : SystemError( make_error_code( Result::eErrorFragmentation ), message ) {}
  };

  class InvalidOpaqueCaptureAddressError : public SystemError
  {
  public:
    InvalidOpaqueCaptureAddressError( std::string const & message ) : SystemError( make_error_code( Result::eErrorInvalidOpaqueCaptureAddress ), message ) {}

    InvalidOpaqueCaptureAddressError( char const * message ) : SystemError( make_error_code( Result::eErrorInvalidOpaqueCaptureAddress ), message ) {}
  };

  class SurfaceLostKHRError : public SystemError
  {
  public:
    SurfaceLostKHRError( std::string const & message ) : SystemError( make_error_code( Result::eErrorSurfaceLostKHR ), message ) {}

    SurfaceLostKHRError( char const * message ) : SystemError( make_error_code( Result::eErrorSurfaceLostKHR ), message ) {}
  };

  class NativeWindowInUseKHRError : public SystemError
  {
  public:
    NativeWindowInUseKHRError( std::string const & message ) : SystemError( make_error_code( Result::eErrorNativeWindowInUseKHR ), message ) {}

    NativeWindowInUseKHRError( char const * message ) : SystemError( make_error_code( Result::eErrorNativeWindowInUseKHR ), message ) {}
  };

  class OutOfDateKHRError : public SystemError
  {
  public:
    OutOfDateKHRError( std::string const & message ) : SystemError( make_error_code( Result::eErrorOutOfDateKHR ), message ) {}

    OutOfDateKHRError( char const * message ) : SystemError( make_error_code( Result::eErrorOutOfDateKHR ), message ) {}
  };

  class IncompatibleDisplayKHRError : public SystemError
  {
  public:
    IncompatibleDisplayKHRError( std::string const & message ) : SystemError( make_error_code( Result::eErrorIncompatibleDisplayKHR ), message ) {}

    IncompatibleDisplayKHRError( char const * message ) : SystemError( make_error_code( Result::eErrorIncompatibleDisplayKHR ), message ) {}
  };

  class ValidationFailedEXTError : public SystemError
  {
  public:
    ValidationFailedEXTError( std::string const & message ) : SystemError( make_error_code( Result::eErrorValidationFailedEXT ), message ) {}

    ValidationFailedEXTError( char const * message ) : SystemError( make_error_code( Result::eErrorValidationFailedEXT ), message ) {}
  };

  class InvalidShaderNVError : public SystemError
  {
  public:
    InvalidShaderNVError( std::string const & message ) : SystemError( make_error_code( Result::eErrorInvalidShaderNV ), message ) {}

    InvalidShaderNVError( char const * message ) : SystemError( make_error_code( Result::eErrorInvalidShaderNV ), message ) {}
  };

  class ImageUsageNotSupportedKHRError : public SystemError
  {
  public:
    ImageUsageNotSupportedKHRError( std::string const & message ) : SystemError( make_error_code( Result::eErrorImageUsageNotSupportedKHR ), message ) {}

    ImageUsageNotSupportedKHRError( char const * message ) : SystemError( make_error_code( Result::eErrorImageUsageNotSupportedKHR ), message ) {}
  };

  class VideoPictureLayoutNotSupportedKHRError : public SystemError
  {
  public:
    VideoPictureLayoutNotSupportedKHRError( std::string const & message )
      : SystemError( make_error_code( Result::eErrorVideoPictureLayoutNotSupportedKHR ), message )
    {
    }

    VideoPictureLayoutNotSupportedKHRError( char const * message ) : SystemError( make_error_code( Result::eErrorVideoPictureLayoutNotSupportedKHR ), message )
    {
    }
  };

  class VideoProfileOperationNotSupportedKHRError : public SystemError
  {
  public:
    VideoProfileOperationNotSupportedKHRError( std::string const & message )
      : SystemError( make_error_code( Result::eErrorVideoProfileOperationNotSupportedKHR ), message )
    {
    }

    VideoProfileOperationNotSupportedKHRError( char const * message )
      : SystemError( make_error_code( Result::eErrorVideoProfileOperationNotSupportedKHR ), message )
    {
    }
  };

  class VideoProfileFormatNotSupportedKHRError : public SystemError
  {
  public:
    VideoProfileFormatNotSupportedKHRError( std::string const & message )
      : SystemError( make_error_code( Result::eErrorVideoProfileFormatNotSupportedKHR ), message )
    {
    }

    VideoProfileFormatNotSupportedKHRError( char const * message ) : SystemError( make_error_code( Result::eErrorVideoProfileFormatNotSupportedKHR ), message )
    {
    }
  };

  class VideoProfileCodecNotSupportedKHRError : public SystemError
  {
  public:
    VideoProfileCodecNotSupportedKHRError( std::string const & message )
      : SystemError( make_error_code( Result::eErrorVideoProfileCodecNotSupportedKHR ), message )
    {
    }

    VideoProfileCodecNotSupportedKHRError( char const * message ) : SystemError( make_error_code( Result::eErrorVideoProfileCodecNotSupportedKHR ), message ) {}
  };

  class VideoStdVersionNotSupportedKHRError : public SystemError
  {
  public:
    VideoStdVersionNotSupportedKHRError( std::string const & message ) : SystemError( make_error_code( Result::eErrorVideoStdVersionNotSupportedKHR ), message )
    {
    }

    VideoStdVersionNotSupportedKHRError( char const * message ) : SystemError( make_error_code( Result::eErrorVideoStdVersionNotSupportedKHR ), message ) {}
  };

  class InvalidDrmFormatModifierPlaneLayoutEXTError : public SystemError
  {
  public:
    InvalidDrmFormatModifierPlaneLayoutEXTError( std::string const & message )
      : SystemError( make_error_code( Result::eErrorInvalidDrmFormatModifierPlaneLayoutEXT ), message )
    {
    }

    InvalidDrmFormatModifierPlaneLayoutEXTError( char const * message )
      : SystemError( make_error_code( Result::eErrorInvalidDrmFormatModifierPlaneLayoutEXT ), message )
    {
    }
  };

  class NotPermittedKHRError : public SystemError
  {
  public:
    NotPermittedKHRError( std::string const & message ) : SystemError( make_error_code( Result::eErrorNotPermittedKHR ), message ) {}

    NotPermittedKHRError( char const * message ) : SystemError( make_error_code( Result::eErrorNotPermittedKHR ), message ) {}
  };

#  if defined( VK_USE_PLATFORM_WIN32_KHR )
  class FullScreenExclusiveModeLostEXTError : public SystemError
  {
  public:
    FullScreenExclusiveModeLostEXTError( std::string const & message ) : SystemError( make_error_code( Result::eErrorFullScreenExclusiveModeLostEXT ), message )
    {
    }

    FullScreenExclusiveModeLostEXTError( char const * message ) : SystemError( make_error_code( Result::eErrorFullScreenExclusiveModeLostEXT ), message ) {}
  };
#  endif /*VK_USE_PLATFORM_WIN32_KHR*/

  class CompressionExhaustedEXTError : public SystemError
  {
  public:
    CompressionExhaustedEXTError( std::string const & message ) : SystemError( make_error_code( Result::eErrorCompressionExhaustedEXT ), message ) {}

    CompressionExhaustedEXTError( char const * message ) : SystemError( make_error_code( Result::eErrorCompressionExhaustedEXT ), message ) {}
  };

}  // namespace VULKAN_HPP_NAMESPACE

/*[[noreturn]]*/ export void throwResultException( ::VULKAN_HPP_NAMESPACE::Result result, char const * message )
{
  using namespace VULKAN_HPP_NAMESPACE;
  switch ( result )
  {
    case Result::eErrorOutOfHostMemory: throw OutOfHostMemoryError( message );
    case Result::eErrorOutOfDeviceMemory: throw OutOfDeviceMemoryError( message );
    case Result::eErrorInitializationFailed: throw InitializationFailedError( message );
    case Result::eErrorDeviceLost: throw DeviceLostError( message );
    case Result::eErrorMemoryMapFailed: throw MemoryMapFailedError( message );
    case Result::eErrorLayerNotPresent: throw LayerNotPresentError( message );
    case Result::eErrorExtensionNotPresent: throw ExtensionNotPresentError( message );
    case Result::eErrorFeatureNotPresent: throw FeatureNotPresentError( message );
    case Result::eErrorIncompatibleDriver: throw IncompatibleDriverError( message );
    case Result::eErrorTooManyObjects: throw TooManyObjectsError( message );
    case Result::eErrorFormatNotSupported: throw FormatNotSupportedError( message );
    case Result::eErrorFragmentedPool: throw FragmentedPoolError( message );
    case Result::eErrorUnknown: throw UnknownError( message );
    case Result::eErrorOutOfPoolMemory: throw OutOfPoolMemoryError( message );
    case Result::eErrorInvalidExternalHandle: throw InvalidExternalHandleError( message );
    case Result::eErrorFragmentation: throw FragmentationError( message );
    case Result::eErrorInvalidOpaqueCaptureAddress: throw InvalidOpaqueCaptureAddressError( message );
    case Result::eErrorSurfaceLostKHR: throw SurfaceLostKHRError( message );
    case Result::eErrorNativeWindowInUseKHR: throw NativeWindowInUseKHRError( message );
    case Result::eErrorOutOfDateKHR: throw OutOfDateKHRError( message );
    case Result::eErrorIncompatibleDisplayKHR: throw IncompatibleDisplayKHRError( message );
    case Result::eErrorValidationFailedEXT: throw ValidationFailedEXTError( message );
    case Result::eErrorInvalidShaderNV: throw InvalidShaderNVError( message );
    case Result::eErrorImageUsageNotSupportedKHR: throw ImageUsageNotSupportedKHRError( message );
    case Result::eErrorVideoPictureLayoutNotSupportedKHR: throw VideoPictureLayoutNotSupportedKHRError( message );
    case Result::eErrorVideoProfileOperationNotSupportedKHR: throw VideoProfileOperationNotSupportedKHRError( message );
    case Result::eErrorVideoProfileFormatNotSupportedKHR: throw VideoProfileFormatNotSupportedKHRError( message );
    case Result::eErrorVideoProfileCodecNotSupportedKHR: throw VideoProfileCodecNotSupportedKHRError( message );
    case Result::eErrorVideoStdVersionNotSupportedKHR: throw VideoStdVersionNotSupportedKHRError( message );
    case Result::eErrorInvalidDrmFormatModifierPlaneLayoutEXT: throw InvalidDrmFormatModifierPlaneLayoutEXTError( message );
    case Result::eErrorNotPermittedKHR: throw NotPermittedKHRError( message );
#  if defined( VK_USE_PLATFORM_WIN32_KHR )
    case Result::eErrorFullScreenExclusiveModeLostEXT: throw FullScreenExclusiveModeLostEXTError( message );
#  endif /*VK_USE_PLATFORM_WIN32_KHR*/
    case Result::eErrorCompressionExhaustedEXT: throw CompressionExhaustedEXTError( message );
    default: throw SystemError( make_error_code( result ) );
  }
}

#endif

export namespace VULKAN_HPP_NAMESPACE
{
  template <typename T>
  void ignore( T const & ) VULKAN_HPP_NOEXCEPT
  {
  }

  template <typename T>
  struct ResultValue
  {
#ifdef VULKAN_HPP_HAS_NOEXCEPT
    ResultValue( Result r, T & v ) VULKAN_HPP_NOEXCEPT( VULKAN_HPP_NOEXCEPT( T( v ) ) )
#else
    ResultValue( Result r, T & v )
#endif
      : result( r ), value( v )
    {
    }

#ifdef VULKAN_HPP_HAS_NOEXCEPT
    ResultValue( Result r, T && v ) VULKAN_HPP_NOEXCEPT( VULKAN_HPP_NOEXCEPT( T( std::move( v ) ) ) )
#else
    ResultValue( Result r, T && v )
#endif
      : result( r ), value( std::move( v ) )
    {
    }

    Result result;
    T      value;

    operator std::tuple<Result &, T &>() VULKAN_HPP_NOEXCEPT
    {
      return std::tuple<Result &, T &>( result, value );
    }
  };

#if !defined( VULKAN_HPP_NO_SMART_HANDLE )
  template <typename Type, typename Dispatch>
  struct ResultValue<UniqueHandle<Type, Dispatch>>
  {
#  ifdef VULKAN_HPP_HAS_NOEXCEPT
    ResultValue( Result r, UniqueHandle<Type, Dispatch> && v ) VULKAN_HPP_NOEXCEPT
#  else
    ResultValue( Result r, UniqueHandle<Type, Dispatch> && v )
#  endif
      : result( r )
      , value( std::move( v ) )
    {
    }

    std::tuple<Result, UniqueHandle<Type, Dispatch>> asTuple()
    {
      return std::make_tuple( result, std::move( value ) );
    }

    Result                       result;
    UniqueHandle<Type, Dispatch> value;
  };

  template <typename Type, typename Dispatch>
  struct ResultValue<std::vector<UniqueHandle<Type, Dispatch>>>
  {
#  ifdef VULKAN_HPP_HAS_NOEXCEPT
    ResultValue( Result r, std::vector<UniqueHandle<Type, Dispatch>> && v ) VULKAN_HPP_NOEXCEPT
#  else
    ResultValue( Result r, std::vector<UniqueHandle<Type, Dispatch>> && v )
#  endif
      : result( r )
      , value( std::move( v ) )
    {
    }

    std::tuple<Result, std::vector<UniqueHandle<Type, Dispatch>>> asTuple()
    {
      return std::make_tuple( result, std::move( value ) );
    }

    Result                                    result;
    std::vector<UniqueHandle<Type, Dispatch>> value;
  };
#endif

  template <typename T>
  struct ResultValueType
  {
#ifdef VULKAN_HPP_NO_EXCEPTIONS
    typedef ResultValue<T> type;
#else
    typedef T    type;
#endif
  };

  template <>
  struct ResultValueType<void>
  {
#ifdef VULKAN_HPP_NO_EXCEPTIONS
    typedef Result type;
#else
    typedef void type;
#endif
  };

  VULKAN_HPP_INLINE typename ResultValueType<void>::type createResultValueType( Result result )
  {
#ifdef VULKAN_HPP_NO_EXCEPTIONS
    return result;
#else
    ignore( result );
#endif
  }

  template <typename T>
  VULKAN_HPP_INLINE typename ResultValueType<T>::type createResultValueType( Result result, T & data )
  {
#ifdef VULKAN_HPP_NO_EXCEPTIONS
    return ResultValue<T>( result, data );
#else
    ignore( result );
    return data;
#endif
  }

  template <typename T>
  VULKAN_HPP_INLINE typename ResultValueType<T>::type createResultValueType( Result result, T && data )
  {
#ifdef VULKAN_HPP_NO_EXCEPTIONS
    return ResultValue<T>( result, std::move( data ) );
#else
    ignore( result );
    return std::move( data );
#endif
  }

  VULKAN_HPP_INLINE void resultCheck( Result result, char const * message )
  {
#ifdef VULKAN_HPP_NO_EXCEPTIONS
    ignore( result );  // just in case VULKAN_HPP_ASSERT_ON_RESULT is empty
    ignore( message );
    VULKAN_HPP_ASSERT_ON_RESULT( result == Result::eSuccess );
#else
    if ( result != Result::eSuccess )
    {
      throwResultException( result, message );
    }
#endif
  }

  VULKAN_HPP_INLINE void resultCheck( Result result, char const * message, std::initializer_list<Result> successCodes )
  {
#ifdef VULKAN_HPP_NO_EXCEPTIONS
    ignore( result );        // just in case VULKAN_HPP_ASSERT_ON_RESULT is empty
    ignore( message );
    ignore( successCodes );  // just in case VULKAN_HPP_ASSERT_ON_RESULT is empty
    VULKAN_HPP_ASSERT_ON_RESULT( std::find( successCodes.begin(), successCodes.end(), result ) != successCodes.end() );
#else
    if ( std::find( successCodes.begin(), successCodes.end(), result ) == successCodes.end() )
    {
      throwResultException( result, message );
    }
#endif
  }
}  // namespace VULKAN_HPP_NAMESPACE
