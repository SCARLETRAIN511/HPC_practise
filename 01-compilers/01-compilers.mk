##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=01-compilers
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/jt2418/Desktop/hpc/Exercise1/Exercise1
ProjectPath            :=/home/jt2418/Desktop/hpc/Exercise1/Exercise1/01-compilers
IntermediateDirectory  :=../build-$(ConfigurationName)/01-compilers
OutDir                 :=../build-$(ConfigurationName)/01-compilers
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Jiaxuan Tang
Date                   :=24/01/22
CodeLitePath           :=/home/jt2418/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)blas 
ArLibs                 :=  "blas" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall -Wshadow $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall -Wshadow $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/01-compilers/compiler-main.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/01-compilers/compiler-norm.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/01-compilers/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/01-compilers"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/01-compilers"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/01-compilers/.d:
	@mkdir -p "../build-$(ConfigurationName)/01-compilers"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/01-compilers/compiler-main.cpp$(ObjectSuffix): compiler-main.cpp ../build-$(ConfigurationName)/01-compilers/compiler-main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jt2418/Desktop/hpc/Exercise1/Exercise1/01-compilers/compiler-main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/compiler-main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/01-compilers/compiler-main.cpp$(DependSuffix): compiler-main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/01-compilers/compiler-main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/01-compilers/compiler-main.cpp$(DependSuffix) -MM compiler-main.cpp

../build-$(ConfigurationName)/01-compilers/compiler-main.cpp$(PreprocessSuffix): compiler-main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/01-compilers/compiler-main.cpp$(PreprocessSuffix) compiler-main.cpp

../build-$(ConfigurationName)/01-compilers/compiler-norm.cpp$(ObjectSuffix): compiler-norm.cpp ../build-$(ConfigurationName)/01-compilers/compiler-norm.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jt2418/Desktop/hpc/Exercise1/Exercise1/01-compilers/compiler-norm.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/compiler-norm.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/01-compilers/compiler-norm.cpp$(DependSuffix): compiler-norm.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/01-compilers/compiler-norm.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/01-compilers/compiler-norm.cpp$(DependSuffix) -MM compiler-norm.cpp

../build-$(ConfigurationName)/01-compilers/compiler-norm.cpp$(PreprocessSuffix): compiler-norm.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/01-compilers/compiler-norm.cpp$(PreprocessSuffix) compiler-norm.cpp


-include ../build-$(ConfigurationName)/01-compilers//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


