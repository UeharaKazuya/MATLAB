# Copyright 1994-2011 The MathWorks, Inc.
#
# File    : grt_lcc.tmf
#
# Abstract:
#	Template makefile for building a PC-based stand-alone generic real-time
#	version of Simulink model using generated C code and LCC compiler
#	Version 2.4
#
# 	This makefile attempts to conform to the guidelines specified in the
# 	IEEE Std 1003.2-1992 (POSIX) standard. It is designed to be used
#       with GNU Make (gmake) which is located in matlabroot/bin/win32.
#
# 	Note that this template is automatically customized by the build
#	procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#	build:
#	  OPT_OPTS       - Optimization options. Default is none. To enable
#                          debugging specify as OPT_OPTS=-g4.
#	  OPTS           - User specific compile options.
#	  USER_SRCS      - Additional user sources, such as files needed by
#			   S-functions.
#	  USER_INCLUDES  - Additional include paths
#			   (i.e. USER_INCLUDES="-I where-ever -I where-ever2")
#			   (For Lcc, have a '/'as file seperator before the
#			   file name instead of a '\' .
#			   i.e.,  d:\work\proj1/myfile.c - reqd for 'gmake')
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see grt.tlc

#------------------------ Macros read by make_rtw ------------------------------
#
# The following macros are read by the build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the build procedure (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.

MAKECMD         = "%MATLAB%\bin\%MATLAB_ARCH%\gmake"
SHELL           = cmd
HOST            = PC
BUILD           = yes
SYS_TARGET_FILE = sbox2.tlc
BUILD_SUCCESS	= ***(D) Created
COMPILER_TOOL_CHAIN = cl6x


MAKEFILE_FILESEP = /

#---------------------- Tokens expanded by make_rtw ----------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# build procedure.
#
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to where MATLAB is installed.
#  MATLAB_BIN          - Path to MATLAB executable.
#  S_FUNCTIONS         - List of S-functions.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link.
#  SOLVER              - Solver source file name
#  NUMST               - Number of sample times
#  TID01EQ             - yes (1) or no (0): Are sampling rates of continuous task
#                        (tid=0) and 1st discrete task equal.
#  NCSTATES            - Number of continuous states
#  BUILDARGS           - Options passed in at the command line.
#  MULTITASKING        - yes (1) or no (0): Is solver mode multitasking
#  EXT_MODE            - yes (1) or no (0): Build for external mode
#  TMW_EXTMODE_TESTING - yes (1) or no (0): Build ext_test.c for external mode
#                        testing.
#  EXTMODE_TRANSPORT   - Index of transport mechanism (e.g. tcpip, serial) for extmode
#  EXTMODE_STATIC      - yes (1) or no (0): Use static instead of dynamic mem alloc.
#  EXTMODE_STATIC_SIZE - Size of static memory allocation buffer.


MODEL                = liner_control
MODULES              = rt_matrx.c rt_printf.c liner_control_capi.c liner_control_data.c rtGetInf.c rtGetNaN.c rt_nonfinite.c dam148ctrl.c to_host_rt.c to_memory_rt.c udcm6_sep.c
MAKEFILE             = liner_control.mk
MATLAB_ROOT          = C:/Program Files/MATLAB/R2019b
ALT_MATLAB_ROOT      = C:/PROGRA~1/MATLAB/R2019b
MATLAB_BIN           = C:/Program Files/MATLAB/R2019b/bin
ALT_MATLAB_BIN       = C:/PROGRA~1/MATLAB/R2019b/bin
MASTER_ANCHOR_DIR    = 
START_DIR            = C:/WinPass/sBOX2/Uehara
S_FUNCTIONS          = 
S_FUNCTIONS_LIB      = 
SOLVER               = 
NUMST                = 2
TID01EQ              = 0
NCSTATES             = 0
BUILDARGS            =  MAT_FILE=0 COMBINE_OUTPUT_UPDATE_FCNS=1 INCLUDE_MDL_TERMINATE_FCN=1 MULTI_INSTANCE_CODE=0 ISPROTECTINGMODEL=NOTPROTECTING
MULTITASKING         = 0
EXT_MODE             = 0
TMW_EXTMODE_TESTING  = 0
EXTMODE_TRANSPORT    = 0
EXTMODE_STATIC       = 0
EXTMODE_STATIC_SIZE  = 1000000

MODELREFS            = 
SHARED_SRC           = 
SHARED_SRC_DIR       = 
SHARED_BIN_DIR       = 
SHARED_LIB           = 
OPTIMIZATION_FLAGS   = 
ADDITIONAL_LDFLAGS   = 
CLASSIC_INTERFACE    = 0

#--------------------------- Model and reference models -----------------------
MODELLIB                  = 
MODELREF_LINK_LIBS        = 
MODELREF_LINK_RSPFILE     = liner_control_ref.rsp
MODELREF_INC_PATH         = 
RELATIVE_PATH_TO_ANCHOR   = ..
# NONE: standalone, SIM: modelref sim, RTW: modelref coder target
MODELREF_TARGET_TYPE       = NONE

#-- In the case when directory name contains space ---
ifneq ($(MATLAB_ROOT),$(ALT_MATLAB_ROOT))
MATLAB_ROOT := $(ALT_MATLAB_ROOT)
endif
ifneq ($(MATLAB_BIN),$(ALT_MATLAB_BIN))
MATLAB_BIN := $(ALT_MATLAB_BIN)
endif

#--------------------------- Tool Specifications ------------------------------

CC = cl6x
AR = ar6x
LD = cl6x
LIBCMD = ar6x

#----------------------------- External mode -----------------------------------

# Uncomment -DVERBOSE to have information printed to stdout
# To add a new transport layer, see the comments in
#   <matlabroot>/toolbox/simulink/simulink/extmode_transports.m
ifeq ($(EXT_MODE),1)
  EXT_CC_OPTS = -DEXT_MODE -DWIN32 # -DVERBOSE
  ifeq ($(EXTMODE_TRANSPORT),0) #tcpip
    EXT_SRC = ext_svr.c updown.c ext_work.c rtiostream_interface.c rtiostream_tcpip.c
    EXT_LIB = $(MATLAB_ROOT)\sys\lcc\lib\wsock32.lib
  endif
  ifeq ($(EXTMODE_TRANSPORT),1) #serial_win32
    EXT_SRC  = ext_svr.c updown.c ext_work.c ext_svr_serial_transport.c
    EXT_SRC += ext_serial_pkt.c rtiostream_serial_interface.c rtiostream_serial.c
  endif
  ifeq ($(TMW_EXTMODE_TESTING),1)
    EXT_SRC     += ext_test.c
    EXT_CC_OPTS += -DTMW_EXTMODE_TESTING
  endif
  ifeq ($(EXTMODE_STATIC),1)
    EXT_SRC     += mem_mgr.c
    EXT_CC_OPTS += -DEXTMODE_STATIC -DEXTMODE_STATIC_SIZE=$(EXTMODE_STATIC_SIZE)
  endif
endif

#------------------------------ Include Path ----------------------------------

# see MATLAB_INCLUDES and COMPILER_INCLUDES from lcctools.mak

MATLAB_INCLUDES = \
 -i. \
	-i"$(MATLAB_ROOT)"\simulink\include \
	-i"$(MATLAB_ROOT)"\extern\include \
	-i"$(MATLAB_ROOT)"\rtw\c\src \
	-i"$(MATLAB_ROOT)"\rtw\c\libsrc \

COMPILER_INCLUDES = \

ADD_INCLUDES = \
	-i$(START_DIR) \
	-i$(START_DIR)/liner_control_sbox2_rtw \
	-i$(MATLAB_ROOT)/extern/include \
	-i$(MATLAB_ROOT)/simulink/include \
	-i$(MATLAB_ROOT)/rtw/c/src \
	-i$(MATLAB_ROOT)/rtw/c/src/ext_mode/common \


SHARED_INCLUDES =
ifneq ($(SHARED_SRC_DIR),)
SHARED_INCLUDES = -i$(SHARED_SRC_DIR)
endif

USER_INCLUDES	= -i$(PASS_SBOX2)\sboxSrc

INCLUDES = -i. -i$(RELATIVE_PATH_TO_ANCHOR) $(MATLAB_INCLUDES) $(ADD_INCLUDES) \
           $(COMPILER_INCLUDES) $(USER_INCLUDES) $(MODELREF_INC_PATH) $(SHARED_INCLUDES)

#------------------------ rtModel ----------------------------------------------
RTM_CC_OPTS = -DUSE_RTMODEL

#-------------------------------- C Flags --------------------------------------

# Optimization Options
OPT_OPTS = "to set this is to make dsp_rt.lib, if necessary"

# General User Options
OPTS    = -DREAL_T=REAL32_T
CPP_REQ_DEFINES = 	-DUSE_RTMODEL -DMODEL=$(MODEL) -DRT -DNUMST=$(NUMST) \
					-DNCSTATES=$(NCSTATES) -DMULTITASKING=$(MULTITASKING)


CC_OPTS	= $(OPTS) $(EXT_CC_OPTS)

CFLAGS	= -mv6740 -O2 --obj_extension=.o67 --define=omapl137  --abi=eabi \
$(CPP_REQ_DEFINES) $(CC_OPTS) $(INCLUDES) \

LDFLAGS	= -w\
-l$(PASS_SBOX2)\passLib\sBOXv2dev.LIB \
-m$(MODEL).MAP


#------------------------- Additional Libraries -------------------------------

LIBS =


LIBS += $(EXT_LIB) $(S_FUNCTIONS_LIB)
LIBS += $(PASS_SBOX2)\sboxSrc\iramboot.cmd

#----------------------------- Source Files ------------------------------------

ifeq ($(MODELREF_TARGET_TYPE), NONE)
    PRODUCT            = $(MODEL).out
    BUILD_PRODUCT_TYPE = executable

MAIN_SRC = rt_main.c
REQ_SRCS           = $(MODEL).c $(MODULES) $(EXT_SRC) $(SOLVER) \
				$(MAIN_SRC) rt_sim.c
else
    # Model reference coder target
    PRODUCT  = $(MODELLIB)
    REQ_SRCS = $(MODULES)
endif

USER_SRCS =

USER_OBJS       = $(USER_SRCS:.c=.o67)
LOCAL_USER_OBJS = $(notdir $(USER_OBJS))

SRCS      = $(REQ_SRCS) $(S_FUNCTIONS)
OBJS      = $(SRCS:.c=.o67)  $(USER_OBJS)
LINK_OBJS = $(SRCS:.c=.o67) $(LOCAL_USER_OBJS)

SHARED_OBJS := $(addsuffix .o67, $(basename $(wildcard $(SHARED_SRC))))
FMT_SHARED_OBJS = $(subst /,\,$(SHARED_OBJS))

#----------------------------- Compiler Command --------------------------
#
TICLCMD         = $(CC) $(CFLAGS) -c $<
TILINKCMD       = $(LD) -q -x $(MODEL).o67 $(MODEL).plt MAT.PLT $(LDFLAGS) -o$@

#--------------------------------- Rules ---------------------------------------

ifeq ($(MODELREF_TARGET_TYPE),NONE)
$(PRODUCT) : $(OBJS) $(SHARED_LIB) $(LIBS) $(MODELREF_LINK_LIBS)
	$(LD) -mv6740 -O2 --define=omapl137 --abi=eabi --obj_extension=.o67 -z --define=DSP_CORE=1 --warn_sections --reread_libs --rom_model -o$(MODEL).out $(LINK_OBJS) $(SHARED_LIB) $(LIBS) $(LDFLAGS) 
	@cmd /C "echo $(BUILD_SUCCESS) executable: $(MODEL).out"
else

$(PRODUCT) : $(OBJS) $(SHARED_LIB)
	$(LIBCMD) rv $(MODELLIB) $(LINK_OBJS)
	@cmd /C "echo $(BUILD_SUCCESS) static library $(MODELLIB)"
endif

%.o67 : %.c
	$(TICLCMD)
%.o67 : $(PASS_SBOX2)/sboxSrc/%.c
	$(TICLCMD)
%.o67 : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) -c -i$(RELATIVE_PATH_TO_ANCHOR)/$(<F:.c=cn_rtw) $(CFLAGS)  $<

%.o67 : $(MATLAB_ROOT)/rtw/c/grt/%.c
	$(TICLCMD)

%.o67 : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(TICLCMD)

%.o67 : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.c
	$(TICLCMD)

%.o67 : $(MATLAB_ROOT)/rtw/c/src/rtiostream/rtiostreamtcpip/%.c
	$(TICLCMD)

%.o67 : $(MATLAB_ROOT)/simulink/src/%.c
	$(TICLCMD)

# Libraries:





#----------------------------- Dependencies ------------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw

$(SHARED_OBJS) : $(SHARED_BIN_DIR)/%.o67 : $(SHARED_SRC_DIR)/%.c
	$(TICLCMD)

$(SHARED_LIB) : $(SHARED_OBJS)
	@cmd /C "echo ###(C) Creating $@"
	$(LIBCMD) /out:$@ $(FMT_SHARED_OBJS)
	@cmd /C "echo ###(C) $@ Created"

#--------- Miscellaneous rules to purge, clean and lint (sol2 only) ------------

purge : clean
	@cmd /C "echo ### Deleting the generated source code for $(MODEL)"
	@del $(MODEL).c $(MODEL).h $(MODEL)_types.h $(MODEL)_data.c \
	        $(MODEL)_private.h $(MODEL).rtw $(MODULES) rtw_proj.tmw $(MAKEFILE)

clean :
	@cmd /C "echo ### Deleting the objects and $(PROGRAM)"
	@del $(LINK_OBJS) ..\$(MODEL).exe



# EOF: grt_lcc.tmf
