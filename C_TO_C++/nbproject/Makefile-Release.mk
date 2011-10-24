#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++-4.4
CXX=g++-4.4
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/program22.o \
	${OBJECTDIR}/program18.o \
	${OBJECTDIR}/program19bis.o \
	${OBJECTDIR}/program30.o \
	${OBJECTDIR}/program15bis.o \
	${OBJECTDIR}/program11.o \
	${OBJECTDIR}/program28.o \
	${OBJECTDIR}/program02.o \
	${OBJECTDIR}/program13.o \
	${OBJECTDIR}/program29bis.o \
	${OBJECTDIR}/program17bis.o \
	${OBJECTDIR}/program08.o \
	${OBJECTDIR}/program25.o \
	${OBJECTDIR}/program07.o \
	${OBJECTDIR}/program12.o \
	${OBJECTDIR}/program03.o \
	${OBJECTDIR}/program18ter.o \
	${OBJECTDIR}/program09.o \
	${OBJECTDIR}/program15.o \
	${OBJECTDIR}/program16.o \
	${OBJECTDIR}/program26.o \
	${OBJECTDIR}/program20.o \
	${OBJECTDIR}/program10.o \
	${OBJECTDIR}/program29.o \
	${OBJECTDIR}/program01.o \
	${OBJECTDIR}/program19.o \
	${OBJECTDIR}/program17.o \
	${OBJECTDIR}/program04.o \
	${OBJECTDIR}/program14.o \
	${OBJECTDIR}/program31.o \
	${OBJECTDIR}/program21.o \
	${OBJECTDIR}/program24.o \
	${OBJECTDIR}/program19_chaine.o \
	${OBJECTDIR}/program05.o \
	${OBJECTDIR}/program18bis.o \
	${OBJECTDIR}/program23.o \
	${OBJECTDIR}/program06.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/c_to_c__

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/c_to_c__: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/c_to_c__ ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/program22.o: program22.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program22.o program22.cpp

${OBJECTDIR}/program18.o: program18.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program18.o program18.cpp

${OBJECTDIR}/program19bis.o: program19bis.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program19bis.o program19bis.cpp

${OBJECTDIR}/program30.o: program30.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program30.o program30.cpp

${OBJECTDIR}/program15bis.o: program15bis.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program15bis.o program15bis.cpp

${OBJECTDIR}/program11.o: program11.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program11.o program11.cpp

${OBJECTDIR}/program28.o: program28.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program28.o program28.cpp

${OBJECTDIR}/program02.o: program02.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program02.o program02.cpp

${OBJECTDIR}/program13.o: program13.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program13.o program13.cpp

${OBJECTDIR}/program29bis.o: program29bis.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program29bis.o program29bis.cpp

${OBJECTDIR}/program17bis.o: program17bis.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program17bis.o program17bis.cpp

${OBJECTDIR}/program08.o: program08.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program08.o program08.cpp

${OBJECTDIR}/program25.o: program25.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program25.o program25.cpp

${OBJECTDIR}/program07.o: program07.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program07.o program07.cpp

${OBJECTDIR}/program12.o: program12.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program12.o program12.cpp

${OBJECTDIR}/program03.o: program03.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program03.o program03.cpp

${OBJECTDIR}/program18ter.o: program18ter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program18ter.o program18ter.cpp

${OBJECTDIR}/program09.o: program09.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program09.o program09.cpp

${OBJECTDIR}/program15.o: program15.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program15.o program15.cpp

${OBJECTDIR}/program16.o: program16.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program16.o program16.cpp

${OBJECTDIR}/program26.o: program26.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program26.o program26.cpp

${OBJECTDIR}/program20.o: program20.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program20.o program20.cpp

${OBJECTDIR}/program10.o: program10.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program10.o program10.cpp

${OBJECTDIR}/program29.o: program29.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program29.o program29.cpp

${OBJECTDIR}/program01.o: program01.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program01.o program01.cpp

${OBJECTDIR}/program19.o: program19.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program19.o program19.cpp

${OBJECTDIR}/program17.o: program17.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program17.o program17.cpp

${OBJECTDIR}/program04.o: program04.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program04.o program04.cpp

${OBJECTDIR}/program14.o: program14.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program14.o program14.cpp

${OBJECTDIR}/program31.o: program31.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program31.o program31.cpp

${OBJECTDIR}/program21.o: program21.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program21.o program21.cpp

${OBJECTDIR}/program24.o: program24.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program24.o program24.cpp

${OBJECTDIR}/program19_chaine.o: program19_chaine.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program19_chaine.o program19_chaine.cpp

${OBJECTDIR}/program05.o: program05.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program05.o program05.cpp

${OBJECTDIR}/program18bis.o: program18bis.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program18bis.o program18bis.cpp

${OBJECTDIR}/program23.o: program23.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program23.o program23.cpp

${OBJECTDIR}/program06.o: program06.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/program06.o program06.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/c_to_c__

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
