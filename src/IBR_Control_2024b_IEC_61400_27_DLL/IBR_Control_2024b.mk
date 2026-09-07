# Copyright 1994-2014 The MathWorks, Inc.
#
# File    : IEC61400_27_DLL.tmf   $Revision: 1.71.4.31 $
#
# Abstract:
#       Template makefile for building a Windows-based stand-alone generic 
#       real-time version of Simulink model using generated C code and the
#								
#       Microsoft Visual C/C++ compiler versions: 6.0, 7.1, 8.0
#
#       Note that this template is automatically customized by the build 
#       procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#       build:
#
#         OPT_OPTS       - Optimization option. See DEFAULT_OPT_OPTS in
#                          vctools.mak for default.
#         OPTS           - User specific options.
#         CPP_OPTS       - C++ compiler options.
#         USER_SRCS      - Additional user sources, such as files needed by
#                          S-functions.
#         USER_INCLUDES  - Additional include paths
#                          (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#
#       To enable debugging:
#         set DEBUG_BUILD = 1, which will trigger OPTS=-Zi (may vary with
#                               compiler version, see compiler doc) 
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see grt.tlc

###############################################################################
#------------------------ Macros read by make_rtw ----------------------------#
###############################################################################
#  MAKECMD         - This is the command used to invoke the make utility
MAKECMD         = nmake

#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
HOST            = PC

#  BUILD           - Invoke make from the build procedure (yes/no)?
BUILD           = yes

#  SYS_TARGET_FILE - Name of system target file.
SYS_TARGET_FILE = IEC61400_27_DLL.tlc

###############################################################################
#---------------------- Tokens expanded by make_rtw --------------------------#
###############################################################################
#  MODEL_NAME          - Name of the Simulink block diagram
MODEL                = IBR_Control_2024b

#  MODEL_MODULES       - Any additional generated source modules
MODULES              = IBR_Control_2024b_data.c IEC61400_27_DLL.c rtGetInf.c rtGetNaN.c rt_nonfinite.c

#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
MAKEFILE             = IBR_Control_2024b.mk

#  MATLAB_ROOT         - Path to where MATLAB is installed.
MATLAB_ROOT          = C:\Program Files\MATLAB\R2024b
ALT_MATLAB_ROOT      = C:\PROGRA~1\MATLAB\R2024b

#  MATLAB_BIN          - Path to MATLAB executable.
MATLAB_BIN           = C:\Program Files\MATLAB\R2024b\bin
ALT_MATLAB_BIN       = C:\PROGRA~1\MATLAB\R2024b\bin

#  START_DIR           - Path to the current working directory
START_DIR            = C:\Users\if47izeq\Documents\_19_Simulink_DLL_Builder\Github\SIMULINK_DLL_Builder\src

#  S_FUNCTIONS_LIB     - List of S-functions libraries to link.
S_FUNCTIONS_LIB      = 

#  NUMST               - Number of sample times
NUMST                = 2

#  TID01EQ             - yes (1) or no (0): Are sampling rates of continuous task
#                        (tid=0) and 1st discrete task equal.
TID01EQ              = 1

#  NCSTATES            - Number of continuous states
NCSTATES             = 0

#  BUILDARGS           - Options passed in at the command line.
BUILDARGS            =  INCLUDE_MDL_TERMINATE_FCN=1 OPTS="-DTID01EQ=1"

#  MULTITASKING        - yes (1) or no (0): Is solver mode multitasking
MULTITASKING         = 0

#  MAT_FILE            - yes (1) or no (0): Should mat file logging be done
MAT_FILE             = 0

#  EXT_MODE            - yes (1) or no (0): Build for external mode
EXT_MODE             = 0

#  TMW_EXTMODE_TESTING - yes (1) or no (0): Build ext_test.c for external mode
#                        testing.
TMW_EXTMODE_TESTING  = 0

#  EXTMODE_TRANSPORT   - Index of transport mechanism (e.g. tcpip, serial) for extmode
EXTMODE_TRANSPORT    = 0

#  EXTMODE_STATIC      - yes (1) or no (0): Use static instead of dynamic mem alloc.
EXTMODE_STATIC       = 0

#  EXTMODE_STATIC_SIZE - Size of static memory allocation buffer.
EXTMODE_STATIC_SIZE  = 1000000

CODE_INTERFACE_PACKAGING = Nonreusable function

CLASSIC_INTERFACE    = 1
# Optional for GRT
ALLOCATIONFCN        = 0
ONESTEPFCN           = 0
TERMFCN              = 1
MULTI_INSTANCE_CODE  = 0

MODELREFS            = 

#  TARGET_LANG_EXT     - file extension of the code to be created 
TARGET_LANG_EXT      = c

#  MEX_OPT_FILE        - mex option file name
MEX_OPT_FILE         = 

#  VISUAL_VER          - Visual C++ version information
VISUAL_VER           = 16.0


OPTIMIZATION_FLAGS   = 
ADDITIONAL_LDFLAGS   = 

# To enable debugging: set DEBUG_BUILD = 1
DEBUG_BUILD          = 0

###############################################################################
#--------------------------- Model and reference models ----------------------#
###############################################################################
MODELLIB                  = 
MODELREF_LINK_LIBS        = 
MODELREF_LINK_RSPFILE     = IBR_Control_2024b_ref.rsp
RELATIVE_PATH_TO_ANCHOR   = ..
MODELREF_TARGET_TYPE      = NONE

!if "$(MATLAB_ROOT)" != "$(ALT_MATLAB_ROOT)"
MATLAB_ROOT = $(ALT_MATLAB_ROOT)
!endif
!if "$(MATLAB_BIN)" != "$(ALT_MATLAB_BIN)"
MATLAB_BIN = $(ALT_MATLAB_BIN)
!endif

###############################################################################
#--------------------------- Tool Specifications -----------------------------#
###############################################################################
!include $(MATLAB_ROOT)\rtw\c\tools\vctools.mak

PERL = $(MATLAB_ROOT)\sys\perl\win32\bin\perl

###############################################################################
#------------------------------ Include/Lib Path -----------------------------#
###############################################################################
MATLAB_INCLUDES =                    $(MATLAB_ROOT)\simulink\include
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\extern\include
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src\ext_mode\common

# Additional file include paths

MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(START_DIR)
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(START_DIR)\IBR_Control_2024b_IEC_61400_27_DLL
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\extern\include
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\simulink\include
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src\ext_mode\common

INCLUDE = .;$(RELATIVE_PATH_TO_ANCHOR);$(MATLAB_INCLUDES);$(INCLUDE)

###############################################################################
#------------------------ External mode --------------------------------------#
###############################################################################
# To add a new transport layer, see the comments in
#   <matlabroot>/toolbox/simulink/simulink/extmode_transports.m
#
#!if $(EXT_MODE) == 1
#
# Uncomment -DVERBOSE to have information printed to stdout
#EXT_CC_OPTS = -DEXT_MODE # -DVERBOSE
#
#!if $(EXTMODE_TRANSPORT) == 0 #tcpip
#EXT_SRC = ext_svr.c updown.c ext_work.c rtiostream_interface.c rtiostream_tcpip.c
#EXT_LIB = wsock32.lib
#!endif
#
#!if $(EXTMODE_TRANSPORT) == 1 #serial_win32
#EXT_SRC = ext_svr.c updown.c ext_work.c ext_svr_serial_transport.c
#EXT_SRC = $(EXT_SRC) ext_serial_pkt.c rtiostream_serial_interface.c rtiostream_serial.c
#EXT_LIB =
#!endif
#
#!if $(TMW_EXTMODE_TESTING) == 1
#EXT_SRC     = $(EXT_SRC) ext_test.c
#EXT_CC_OPTS = $(EXT_CC_OPTS) -DTMW_EXTMODE_TESTING
#!endif
#
#!if $(EXTMODE_STATIC) == 1
#EXT_SRC     = $(EXT_SRC) mem_mgr.c
#EXT_CC_OPTS = $(EXT_CC_OPTS) -DEXTMODE_STATIC -DEXTMODE_STATIC_SIZE=$(EXTMODE_STATIC_SIZE)
#!endif
#
#!else
EXT_SRC     =
EXT_CC_OPTS =
EXT_LIB     =
#!endif
#
###############################################################################
#------------------------ rtModel --------------------------------------------#
###############################################################################

RTM_CC_OPTS = -DUSE_RTMODEL

###############################################################################
#----------------- Compiler and Linker Options -------------------------------#
###############################################################################
# Optimization Options
OPT_OPTS = $(DEFAULT_OPT_OPTS)

# General User Options
!if "$(DEBUG_BUILD)" == "0"
DBG_FLAG =
!else
#   Set OPT_OPTS=-Zi and any additional flags for debugging
DBG_FLAG = -Zi
!endif


!if "$(OPTIMIZATION_FLAGS)" != ""
CC_OPTS = $(OPTS) $(EXT_CC_OPTS) $(RTM_CC_OPTS) $(OPTIMIZATION_FLAGS)
!else
CC_OPTS = $(OPT_OPTS) $(OPTS) $(EXT_CC_OPTS) $(RTM_CC_OPTS)
!endif

CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DRT -DNUMST=$(NUMST) \
		          -DTID01EQ=$(TID01EQ) -DNCSTATES=$(NCSTATES) \
		          -DMT=$(MULTITASKING) -DHAVESTDIO -DMAT_FILE=$(MAT_FILE) \
		          -DONESTEPFCN=$(ONESTEPFCN) -DTERMFCN=$(TERMFCN) \
		          -DMULTI_INSTANCE_CODE=$(MULTI_INSTANCE_CODE) \
		          -DCLASSIC_INTERFACE=$(CLASSIC_INTERFACE) \
		          -DALLOCATIONFCN=$(ALLOCATIONFCN)

CFLAGS   = $(cflags) $(cvarsmt) $(CFLAGS_VERSPECIFIC) $(DBG_FLAG) $(CC_OPTS) $(CPP_REQ_DEFINES) $(USER_INCLUDES)
CPPFLAGS = $(cflags) $(cvarsmt) $(CPPFLAGS_VERSPECIFIC) $(DBG_FLAG) $(CPP_OPTS) $(CC_OPTS) $(CPP_REQ_DEFINES) $(USER_INCLUDES)
LDFLAGS  = $(ldebug) $(conflags) $(EXT_LIB) $(conlibsmt) libcpmt.lib $(ADDITIONAL_LDFLAGS)

# libcpmt.lib is the multi-threaded, static lib version of the C++ standard lib

###############################################################################
#----------------------------- Source Files ----------------------------------#
###############################################################################

# Dynamic library
!if "$(MODELREF_TARGET_TYPE)" == "NONE"
PRODUCT   = $(RELATIVE_PATH_TO_ANCHOR)\$(MODEL).dll

REQ_SRCS  = $(MODEL).$(TARGET_LANG_EXT) $(MODULES) IEC61400_27_DLL.c rt_sim.c $(EXT_SRC)
    
# Model Reference Target
!else
PRODUCT   = $(MODELLIB)
REQ_SRCS  = $(MODULES)
!endif

USER_SRCS =

SRCS = $(REQ_SRCS) $(USER_SRCS) 
OBJS_CPP_UPPER = $(SRCS:.CPP=.obj)
OBJS_CPP_LOWER = $(OBJS_CPP_UPPER:.cpp=.obj)
OBJS_C_UPPER = $(OBJS_CPP_LOWER:.C=.obj)
OBJS = $(OBJS_C_UPPER:.c=.obj)

###############################################################################
# ------------------------- Additional Libraries -----------------------------#
###############################################################################

LIBS = 


LIBS = $(LIBS)

###############################################################################
# ---------------------------- Linker Script ---------------------------------#
###############################################################################

CMD_FILE = $(MODEL).lnk
GEN_LNK_SCRIPT = $(MATLAB_ROOT)\rtw\c\tools\mkvc_lnk.pl

###############################################################################
#--------------------------------- Rules -------------------------------------#
###############################################################################
all: set_environment_variables $(PRODUCT)

!if "$(MODELREF_TARGET_TYPE)" == "NONE"
#--- Stand-alone model ---
$(PRODUCT) : $(OBJS) $(LIBS) $(MODELREF_LINK_LIBS)
	@cmd /C "echo ### Linking ..."
	$(PERL) $(GEN_LNK_SCRIPT) $(CMD_FILE) $(OBJS)
	$(LD) /DLL $(LDFLAGS) $(S_FUNCTIONS_LIB) $(LIBS) $(MAT_LIBS) @$(CMD_FILE) @$(MODELREF_LINK_RSPFILE) -out:$@
	@del $(CMD_FILE)
	@cmd /C "echo ### Created dynamic library $(MODEL).dll"
!else
#--- Model reference Coder Target ---
$(PRODUCT) : $(OBJS) 
	@cmd /C "echo ### Linking ..."
	$(PERL) $(GEN_LNK_SCRIPT) $(CMD_FILE) $(OBJS)
	$(LD) -lib /OUT:$(MODELLIB) @$(CMD_FILE) $(S_FUNCTIONS_LIB)
	@cmd /C "echo ^#^#^# Created static library $(MODELLIB)"
!endif

!if "$(TARGET_LANG_EXT)" ==  "cpp"
{$(MATLAB_ROOT)\rtw\c\grt}.c.obj :
    @cmd /C "echo ### Compiling $<"
    $(CC) /TP $(CPPFLAGS) $<
!else
{$(MATLAB_ROOT)\rtw\c\grt}.c.obj :
    @cmd /C "echo ### Compiling $<"
    $(CC) $(CFLAGS) $<
!endif

{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\common}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\rtiostream\rtiostreamtcpip}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\serial}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\custom}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

# Additional sources

{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\simulink\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\toolbox\simulink\blocks\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<



{$(MATLAB_ROOT)\rtw\c\src}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\simulink\src}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\simulink\blocks\src}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<



# Look in simulink/src helper files

{$(MATLAB_ROOT)\simulink\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\simulink\src}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

# Put these rule last, otherwise nmake will check toolboxes first

{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<


set_environment_variables:
	@set INCLUDE=$(INCLUDE)
	@set LIB=$(LIB)

# Libraries:





#----------------------------- Dependencies -----------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw
