<?xml version="1.0" encoding="utf-8"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.1">

<xsl:import href="global-variables.xsl"/>

<xsl:output method="xml" indent="yes"/>
<xsl:template match="xcconfig-plugin-file">
<xsl:if test="not(string(/code/@mac-specific-xcconfig-file))">Generating Plugin.xcconfig from template...
	<xsl:document href="{/code/@mac-project-dir}{$filesep}{/code/@long-name}Plugin.xcconfig" method="text" indent="yes">
		<xsl:call-template name="xcconfig-plugin"/>
	</xsl:document>
</xsl:if>
</xsl:template>



<xsl:template match="xcconfig-plugin" name="xcconfig-plugin"><xsl:variable name="sdkdir" select="/code/@mac-sdk-dir"/>
ID_BUILD_CONFIG_PLUGIN_SDK = YES

// InDesign sdk project build settings (based on common build settings)
#include "<xsl:value-of select="$sdkdir"/>/build/mac/prj/_shared_build_settings/common.xcconfig"

// InDesign sdk project specific build settings

// InDesign Build variables
BUILT_APPLICATION_DIR = ../$(TARGET_NAME)/packagefolder/contents/macos/
TARGET_BUILD_DIR = $(BUILT_PRODUCTS_DIR)
WRAPPER_EXTENSION = InDesignPlugin

// Include search paths
HEADER_SEARCH_PATHS = $(OS_HEADER_SEARCH_PATHS) $(ID_PUBLIC_HEADER_SEARCH_PATHS) $(ID_OPEN_HEADER_SEARCH_PATHS) $(ASL_HEADER_SEARCH_PATHS) $(ID_SDK_ROOT)/external/afl/includes

REZ_SEARCH_PATHS = $(ID_COMMON_REZ_SEARCH_PATHS) $(ID_SDK_ROOT)/external/palettes $(ID_SDK_ROOT)/external/workflow icons

// GCC flags
GCC_ENABLE_SYMBOL_SEPARATION = YES
GCC_PREFIX_HEADER = $(ID_SDK_ROOT)/source/precomp/gcc/PluginPrefix.pch
GCC_PREPROCESSOR_DEFINITIONS = $(GCC_PREPROCESSOR_DEFINITIONS) MACINTOSH MACOSX_SDKVERSION=$(MACOSX_SDKVERSION) $(BIB_THROW)
GCC_WARN_UNUSED_VARIABLE = NO
GCC_WARN_CHECK_SWITCH_STATEMENTS = NO
//WARNING_CFLAGS = -Wchar-subscripts -Wimplicit -Wsequence-point -Winit-self -Wmissing-field-initializers -Wpointer-arith -Wcast-align -Wpacked

// Linker Flags
DEAD_CODE_STRIPPING = YES
INSTALL_PATH = ./
ONLY_LINK_ESSENTIAL_SYMBOLS = YES
OTHER_LDFLAGS = -Wl,-executable_path -Wl,$(BUILT_APPLICATION_DIR)

// plist compiler flags
PLC_GENERATE_PKGINFO_FILE = YES
PLC_OUTPUT_CREATOR = InDn
PLC_OUTPUT_TYPE = ????

// Misc flags
ALWAYS_REZ = YES

//HEADER_SEARCH_PATHS = /Developer/Headers/FlatCarbon $(ID_SDK_ROOT)/external/asl/boost_libraries/ $(ID_SDK_ROOT)/external/asl/intel_tbb_libraries/include/ $(ID_SDK_ROOT)/external/afl/includes $(ID_SDK_ROOT)/source/precomp/common $(ID_SDK_ROOT)/source/precomp/msvc $(ID_SDK_ROOT)/source/public/includes $(ID_SDK_ROOT)/source/public/interfaces/architecture $(ID_SDK_ROOT)/source/public/includes/utils $(ID_SDK_ROOT)/source/public/interfaces/utils $(ID_SDK_ROOT)/source/public/interfaces/xmedia $(ID_SDK_ROOT)/source/public/libs/widgetbin/includes

ID_SDK_ROOT = <xsl:value-of select="$sdkdir"/>
BUILT_APPLICATION_DIR = $(ID_SDK_ROOT)/build/mac/$(TARGET_NAME)/packagefolder/contents/macos/
</xsl:template>
</xsl:stylesheet>

