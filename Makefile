SDIR := src
ODIR := obj
IDIR := include
TDIR := test

CXXFLAGS = -O1 -fPIC -std=c++11 -MMD -MP
CXXFLAGS += -I. -I$(IDIR)
CXXFLAGS += -Wall -Wextra -Wno-unused-parameter
DFLAGS = -g

LIBS = -lm

STATIC_LIB_TARGET = libdynaacore.a

SRCS_CORE = \
	$(SDIR)/caja.cpp\
	$(SDIR)/carga_personalizada.cpp\
	$(SDIR)/elemento.cpp\
	$(SDIR)/main.cpp\

SRCS_TEST = \
	$(TDIR)/unittestmain.cpp\
	$(TDIR)/cargas_test.cpp\
	$(TDIR)/cajas_test.cpp\

OBJS_CORE = $(SRCS_CORE:$(SDIR)/%.cpp=$(ODIR)/%.o)
OBJS_TEST = $(SRCS_TEST:$(TDIR)/%.cpp=$(ODIR)/%.o)

$(ODIR)/%.o: $(TDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< 

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: all staticlib tests runtests clean

all: staticlib runtests

staticlib: $(OBJS_CORE)
	@echo -e "\n*** Building static library ($(STATIC_LIB_TARGET))"
	ar -cr $(STATIC_LIB_TARGET) $(OBJS_CORE)

tests: $(OBJS_TEST)
	@echo -e "\n*** Building unit tests for ($(STATIC_LIB_TARGET))"
	$(CXX) $(CXXFLAGS) $(DFLAGS) -o run_tests $^ $(LIBS) -L. $(STATIC_LIB_TARGET)

runtests: tests
	@echo -e "\n*** Running all unit tests"
	-./run_tests

clean:
	/bin/rm -f $(OBJS_CORE) $(OBJS_TEST) $(OBJS_CORE:%.o=%.d) $(OBJS_TEST:%.o=%.d)
	/bin/rm -f ./$(STATIC_LIB_TARGET)
	/bin/rm -f ./run_tests


-include $(OBJS_CORE:%.o=%.d) $(OBJS_TEST:%.o=%.d)
