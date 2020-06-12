CXXFLAGS = -march=native
CCFLAGS = $(CXXFLAGS)

SOURCEDIR=FlightTicketSystem
BUILDDIR=build
SRC = $(wildcard $(SOURCEDIR)/*.cc)
OBJ = $(patsubst $(SOURCEDIR)/%.cc,$(BUILDDIR)/%.o,$(SRC))
DS = $(patsubst $(SOURCEDIR)/%.cc,$(BUILDDIR)/%.d,$(SRC))

all : CXXFLAGS += -DUNICODE -Wall -Wextra -O3
all : dir $(DS) $(BUILDDIR)/main

debug : CXXFLAGS += -DDEBUG -DUNICODE -Wall -Wextra -g -O0
debug: CCFLAGS += -DDEBUG -DUNICODE  -Wall -g -O0
debug: dir $(DS) $(BUILDDIR)/main

dir: 
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@.out $^

$(DS) : $(BUILDDIR)/%.d: $(SOURCEDIR)/%.cc
	$(CXX) -MM -MP -MF  $@ $<
	sed -i '1s/^/$(BUILDDIR)\//' $@

-include $(DS)

$(OBJ):$(BUILDDIR)/%.o: $(SOURCEDIR)/%.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY : clean
clean :
	-rm $(BUILDDIR)/main.out $(BUILDDIR)/*.o $(BUILDDIR)/*.d