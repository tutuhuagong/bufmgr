################################################################ 
## variable definitions 
CC 			= g++
AR 			= ar rc
RM 			= rm -f
MKDIR			= mkdir -p

################################################################ 
## compile flags 
ifeq ($(BUILD),release)
# "Release" build - optimization, and no debug symbols
CXXFLAGS += -O2 -s -DNDEBUG
else
# "Debug" build - no optimization, and debugging symbols
CXXFLAGS += -O0 -g -Wall
endif

################################################################ 
## linker flags 
LINKERFLAGS 		=

################################################################ 
## src, includes, objs, dependence files
TOP_DIR 		= $(shell pwd)
SRC_DIR			= $(TOP_DIR)/src
BIN_DIR			= $(TOP_DIR)/bin

# INCLUDES	= -I$(SRC_DIR)/btree \
                  -I$(SRC_DIR)/bufmgr \
		-I$(SRC_DIR)/globaldefs \
		-I$(SRC_DIR)/spacemgr \
		-I$(SRC_DIR)/tests \
		-I$(SRC_DIR)/buffer_vector \
		-I$(SRC_DIR)/main
# INCLUDES = $(shell find $(SRC_DIR) -type d | sed 's\^\-I\' | sed '$ ! s/$/ \\/') 
HEADERS 		= $(shell find $(TOP_DIR) -name *.h -print)
INCLUDES                = $(shell find $(SRC_DIR) -type d | sed 's\^\-I\' ) 
SRCS			= $(shell find $(TOP_DIR) -name *.cc -print) 
OBJS			= $(patsubst %.cc, %.o, $(SRCS))
DFILES			= $(patsubst %.cc, %.d, $(SRCS))

################################################################ 
## targets and rules
MAIN_TRAGET = bufmgr

$(MAIN_TRAGET): $(OBJS)
	-@$(MKDIR) $(BIN_DIR)
	$(CC) $(CXXFLAGS) -o $(BIN_DIR)/$(MAIN_TRAGET) $(OBJS) $(INCLUDES) $(LINKERFLAGS)
 	
%.o: %.cc
	$(CC) $(CXXFLAGS) -c -o $@ $< $(INCLUDES)

## dependece files which includes the header dependences of a source file. Generated automatically by the "gcc -MM" cmd
-include $(DFILES)

%.d: %.cc
	@set -e; \
	$(RM)  $@; \
	$(CC) -MM $(CXXFLAGS) $(INCLUDES) $< > $@.1234; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.1234 > $@.123; \
	sed '1 s\^\$(dir $@)\' < $@.123 > $@; \
	$(RM) $@.1234; \
	$(RM) $@.123;

clean:
	-$(RM) $(MAIN_TARGET)
	-$(RM) $(shell find $(TOP_DIR) -name *~ )
.PHONY: clean

clear: clean
	-$(RM) -R $(BIN_DIR)
	-$(RM) $(DFILES) $(OBJS)
.PHONY: clear

	
